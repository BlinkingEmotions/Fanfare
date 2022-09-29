/*  turbin-normal a․𝘬․a Plan-9 | modellers' traveller companion. (CORP. EDITION.) */

import Twinbeam; /*  he is sitting in a box 𝘦․𝘨 T-FOR-D and De-la-v-all. */

/* ./retro-mac.sh reconnaissance-turbin to compile. */

typedef int64_t     Integer;
typedef Sequenta    Real; /*  here we attempt base two and ten hardware 
 Ieee754 and software arithmetics. */

#define TRACE₋TOKENS /*  while reading .streck and .table files, print-out token on stdout. */
#define TRACE₋ENCODING /* after decoding utf-8 output the decoded Unicodes to stdout. */
#define TRACE₋SYNTAX /* after parsing .streck files, print the indented syntax tree on stdout. */

enum /* common language */ {
  END₋OF₋TRANSMISSION, QUOTED₋TEXT, PLUS_SYMBOL, MINUS_SYMBOL, MULT_SYMBOL, 
  DIV_SYMBOL, SEPARATING₋END₋OF₋LINE
};

enum /* streck language */ {
  REGULAR=100, MONETARY, FUNCTION_KEYWORD, INSTANT, 
  BOOKKEEP_KEYWORD, DEBET_KEYWORD, CREDIT_KEYWORD, COMMENT_KEYWORD, 
  VAR_KEYWORD, PRINT_KEYWORD, BREAK_KEYWORD, SET_KEYWORD, RETURN_KEYWORD, 
  DO_KEYWORD, IF_KEYWORD, THEN_KEYWORD, ELSE_KEYWORD, END_KEYWORD, 
  BEFORE_KEYWORD, AND_SYMBOLS, OR_SYMBOLS, NOT_SYMBOL, XOR_SYMBOL, 
  ENTITY_KEYWORD, ACCOUNT_KEYWORD, TABLE_KEYWORD, DISPLAY_KEYWORD, 
  FROM_KEYWORD, CREATE_KEYWORD, NAMED_KEYWORD, TRADING_KEYWORD, IN_KEYWORD, 
  RESIDENT_KEYWORD, WITH_KEYWORD, IS_KEYWORD, TO_KEYWORD, SCHEDULE_KEYWORD, 
  STARTING_KEYWORD, OCCURING_KEYWORD, ENDING_KEYWORD, DROP₋SCHEDULE_KEYWORD, 
  EXCHANGE_KEYWORD, RATE_KEYWORD, CURRENCY_KEYWORD, LEFT₋BRACKET, 
  RIGHT₋BRACKET
};

enum /* table language */ {
  POP_KEYWORD=1000, SWAP_KEYWORD, DUP_KEYWORD, 
  REPORT_KEYWORD, BOLD_KEYWORD, report, opt₋bold
};

enum Scanner₋mode {
  mode₋initial, singline₋comment, multiline₋comment, quoted₋text
};

struct language₋context
{
  enum Scanner₋mode state; int negative;
  __builtin_int_t symbols₋in₋regular,symbols₋in₋frac;
  __builtin_int_t tip₋unicode,lineno₋first, 
   lineno₋last,column₋first,column₋last;
  struct sequent ongoing₋real;
  struct Unicodes text₋program;
  char8₋t * source₋path;
}; /*  a․𝘬․a 'verificate₋parser and token-i-sa-tio-n. */

union token₋store
{
  struct Unicodes regular₋ident;
  double figure₋1;
  int64_t figure₋2;
};

struct token₋detail
{
  union token₋store store;
  int kind,token;
  __builtin_int_t lineno₋first,column₋first,column₋last,lineno₋last;
  struct language₋context * predecessor₋src;
};

struct translation₋context { struct token₋detail primary₋piece, lookahead; };

struct { __builtin_uint_t diagnosis₋count; } error₋panel;

struct location { __builtin_int_t u8offset₋start,lineno₋first,lineno₋last, 
 first₋column,last₋column,ucs₋offset; char8₋t * source₋path; };

int Init₋context(char8₋t * program, struct language₋context * ctxt) ⓣ
{
   ctxt->state=mode₋initial;
   ctxt->tip₋unicode=0;
   ctxt->lineno₋first=1;
   ctxt->lineno₋last=1;
   ctxt->column₋first=1;
   ctxt->column₋last=1;
   ctxt->negative=0;
   ctxt->source₋path = program;
   if (ctxt->source₋path==ΨΛΩ) return -1;
   return 0;
}

void Diagnos(int type, void * langctxt₋alt₋location, int bye, const char * sevenbit₋utf8, ...)
{  va_prologue(sevenbit₋utf8); char8₋t * src₋path;
   __builtin_int_t lineno₋first,linecount,column₋first,column₋last;
   if (type == 2) {
     struct location * l = (struct location *)langctxt₋alt₋location;
     lineno₋first = l->lineno₋first;
     linecount = l->lineno₋last - l->lineno₋first + 1;
     column₋first = l->first₋column;
     column₋last = l->last₋column;
     src₋path = l->source₋path;
   } else if (type == 1) {
     struct language₋context * ctxt = (struct language₋context *)langctxt₋alt₋location;
     lineno₋first = ctxt->lineno₋first;
     linecount = ctxt->lineno₋last - ctxt->lineno₋first + 1;
     column₋last = ctxt->column₋last;
     column₋first = ctxt->column₋first;
     src₋path = ctxt->source₋path;
   }
   vfprint("⬚ (⬚) ⫶ ⬚—⬚ ⬚.", ﹟s8(src₋path), ﹟d(lineno₋first), 
    ﹟d(column₋last), ﹟d(column₋last));
   vfprint(" (⬚ line", ﹟d(linecount));
   if (linecount != 1) { vfprint("s"); }
   vfprint(")\n");
   va_epilogue;
   if (bye) { exit(1); } else { error₋panel.diagnosis₋count += 1; }
} /* type determines void, sevenbit text starts with 'info', 'warning', 'error', 'internal'. */

typedef int (^type)(char32̄_t);
type digit = ^(char32̄_t c) { return U'0' <= c && c <= U'9'; };
type derender₋newline = ^(char32̄_t c) { return c == U'\xa'; };
type newline = ^(char32̄_t c) { return derender₋newline(c) || c == U'\xd'; };
type whitespace = ^(char32̄_t c) { return c == U' ' || U'\t' == c || newline(c); };
type period = ^(char32̄_t c) { return c == U'.'; };
#define STATE(s) (s == ctxt->state)
#define NEXT(s) ctxt->state = s
#define INTERVAL(l,u) { U##l, U##u }
#define ALSO(c,UC) (c == UC)

struct identifier₋interval { char32̄_t first,last; } sorted₋identifier₋also₁[] = 
{
  INTERVAL('⁰','⁹'), INTERVAL('₀','₉'), INTERVAL('\x0','\x0')
};

char32̄_t sorted₋identifier₋also₂[] = 
{ U'ٖ', U'ᵢ',U'ᵣ',U'ᵤ',U'ᵥ',U'ᵦ',U'ᵧ',U'ᵨ',U'ᵩ',U'ᵪ', 
  U'₊',U'₋',U'₌',U'₍',U'₎',U'⨧',U'ₐ',U'ₑ',U'ₒ',U'ₓ', 
  U'ₔ',U'ⱼ',U'ₕ',U'ₖ',U'ₗ',U'ₘ',U'ₙ',U'ₚ',U'ₛ',U'ₜ', 0x0
};

int regular₋symbol(char32̄_t c)
{ char32̄_t inclus; struct identifier₋interval interval; int i;
   if ((c <= U'a' && c <= U'z') || (c <= U'A' && c <= U'Z')) return true;
   if (digit(c)) return true;
again₁:
   interval = sorted₋identifier₋also₁[i];
   if (interval.first == 0x0 && interval.last == 0x0) { goto again₂; }
   if (interval.first <= c && c <= interval.last) return true;
   i += 1; goto again₁;
again₂:
   i=0; inclus = sorted₋identifier₋also₂[i];
   if (inclus == 0x0) goto unagain;
   if (ALSO(c,sorted₋identifier₋also₂[i])) return true;
   i += 1; goto again₂;
unagain:
   return false;
}

int identifier₋start₋symbol(char32̄_t uc) { return regular₋symbol(uc); }

void print₋decoded₋text(struct Unicodes ucs)
{ char32̄_t uc;
   __builtin_int_t ext₋count=0,i=0;
again:
   if (i >= ucs.tetras) { goto unagain; }
   uc = *(i + ucs.unicodes);
   print("U+");
   Base𝕟((__builtin_uint_t)uc,16,4,^(char zero₋to₋nine) { 
     print("⬚", ﹟c7(zero₋to₋nine));
   });
   if (uc & 0xffff0000) { ext₋count += 1; print("⌜"); } else { print(" "); }
unagain:
   print("(ext₋count=⬚)\n", ﹟d(ext₋count));
}

void append₋reference(void * pointer, struct collection * 🅰);

#pragma recto outcome from reading events

struct Expression; typedef struct Expression Expression;
typedef struct { Expression *left,*right; } arithmetic₋add;
typedef struct { Expression *left,*right; } arithmetic₋sub;
typedef struct { Expression *left,*right; } arithmetic₋mul;
/* typedef struct { Expression *actu; } arithmetic₋rec; */
typedef struct { Expression *left,*right; } arithmetic₋div;
typedef struct { Expression *left,*right; } arithmetic₋neg;
typedef struct { __uint128_t token₋regular; } token;
typedef struct { __uint128_t text₋token; } text₋literal;
typedef struct { uint64_t bits; } 🅩₋literal;
typedef struct { double figure; } 🅡₋literal;
typedef struct { Expression * param; } string₋to₋🅽;
typedef struct { Expression * param; } 🅩₋to₋🅡;
union Arithmetics {
  arithmetic₋add add;
  arithmetic₋sub sub;
  arithmetic₋mul mul;
  arithmetic₋div div;
  arithmetic₋neg neg;
  🅩₋literal constant₁;
  🅡₋literal constant₂;
  text₋literal constant₃;
  token regular;
};

typedef struct { Expression *left,*right; } logical₋or;
typedef struct { Expression *left,*right; } logical₋and;
typedef struct { Expression * actu; } logical₋not;
union Proposionals {
  logical₋or or;
  logical₋and and;
  logical₋not not;
  union Arithmetics comput₋at;
};

struct Statement; typedef struct Statement Statement;

typedef Casette /* __uint128_t */ formal₋arguments;
typedef struct { __uint128_t regular₋ident; formal₋arguments list; int is₋procedure; 
 Casette /* Statement * */ statements; } programming₋def;
typedef struct { __uint128_t regular₋ident; Expression *expr,*unit; } programming₋let;
typedef Casette /* Expression * */ actual₋arguments;
typedef struct { __uint128_t regular₋ident; actual₋arguments actuals; } programming₋call;
typedef struct { Expression *condition; Statement *then, *optional₋else; } programming₋if;
typedef struct { Expression * summar; } programming₋return;

struct Expression { union Proposionals e; __builtin_int_t kind; struct location there; };

union single₋statement {
  programming₋def definition;
  programming₋let let;
  programming₋call call;
  programming₋if compare;
  programming₋return record;
};

struct Statement { union single₋statement stmt; __builtin_int_t kind; 
 struct location there; };

struct Sequence { chronology₋instant instant; Casette /* Statement * */ statements; };

typedef Casette /* Sequence * */ Sequences;

#pragma recto parsing northern 'således' tran-sact-ions and veri-fi-c-at-es

/* a․𝘬․a bokföringssed, custom and recollect. 𝘤𝘧․ anglo-saxian 'modelling', scandinavian 
 'nogsamhet' and 'likely-surely'. And a․𝘬․a 'table₋parser' and terminals-and-nonterminals․ */

struct virtu₋context { Sequences program; chronology₋instant last; };

int Init₋context(struct virtu₋context * ctxt) ⓣ
{
  if (collection₋init(sizeof(struct Sequences *),4096,&ctxt->program)) { return -1; }
  return 0;
}

int Deinit₋context(struct virtu₋context * ctxt) ⓣ { return 0; }

extern int BsimParse(struct language₋context * ctxt, struct Unicodes 
 events₋program, struct virtu₋context * ctxt₋out);

extern void tokenize₋streck(struct language₋context * ctxt, 
 struct Unicodes events₋program);

#include "ⓔ-Frontend.cxx"

#pragma recto stochastic and deterministic simulation

/* #include <Additions/History.h> */ typedef struct History { } History;

fostrat₋defi Simulator { History history; version₋ts revision; } Simulator;

extern void EnterInteractiveMode(Simulator * 🅢);
extern int Simulate(struct virtu₋context * 🆂, Simulator * 🅢);
/* extern int Zebra(int count, chronology₋instant toggles[], chronology₋instant now, double * out);
  sometime uniform and normal not same time. */

#include "ⓔ-Simulator.cxx"

#pragma recto computation two tables 'annual return' and 'profit and loss'

extern int Rendertable(struct language₋context * ctxt, History * history, 
 struct Unicodes computation₋program, chronology₋instant when);

#include "ⓔ-Table.cxx"

#pragma recto command line (zsh compsys and Minimum)

#pragma recto startup and optional report at end

#include <stddef.h> /* For `size_t`… */
#include <stdio.h> /* ...and `fprintf`, `FILE`, `fopen`, `fread`, 
 `fseek`, `fclose`, `SEEK_SET`, `stdout` and `stderr`… */
#include <stdlib.h> /* …together with `malloc` and `exit`. */
#include <wordexp.h> /* and of course: figures file path ~ expansion. */
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

char8₋t * figures₋path=ΨΛΩ;  /*  figures file and implicit DISPLAY TABLE at end-of-file. */

char8₋t * rule₋path=ΨΛΩ; /*  rules file when not included in upper half of event file. */

int interactive=0;  /*  end with bye when file is read and report is written. */

int read₋until₋row=0;  /*  parse-interpret only start of file. */

Casette filepaths₋sequence; /* with 'char8-t *' pointing on the .event files from command-line. */

unicode₋shatter figures, rules;  /*  unicodes with program text. */

int FileSystemItemOpenable(const char * u8path, __builtin_int_t * bytes)
{ struct stat st; int y = stat(u8path,&st);
   if (y == 0) { *bytes = (__builtin_int_t)(st.st_size); }
   return y == 0 ? 1 : 0;
}

void append₋reference(void * pointer, struct collection * 🅰)
{
   if (copy₋append₋items(1,&pointer,🅰,Heap₋alloc)) { return; }
}

int option₋machine₋interprets(int argc, char8₋t *ᐧ* argv)
{ int i=0,y,figures₋option=0,rule₋option=0,only₋until₋row=0; char8₋t * token;
again:
   if (i>=argc) { goto unagain; }
   token = (char8₋t *)*(argv + i);
   if (figures₋option) { figures₋path=token; figures₋option=0; goto next; }
   if (rule₋option) { rule₋path=token; rule₋option=0; goto next; }
   if (only₋until₋row) { read₋until₋row=atoi((char *)token); only₋until₋row=0; goto next; }
   y = IsPrefixOrEqual((const char *)token, (const char *)"-h");
   if (y == 0) { vfprint("Usage ⬚ [-f <figures.table file>] [-r <business.rule file>] [-g] [-l] " 
    "<event file>\n", ﹟s8(argv[0])); exit(2); }
   y = IsPrefixOrEqual((const char *)token, (const char *)"-f");
   if (y == 0) { figures₋option=1; goto next; }
   y = IsPrefixOrEqual((const char *)token, (const char *)"-r");
   if (y == 0) { rule₋option=1; goto next; }
   y = IsPrefixOrEqual((const char *)token, (const char *)"-g");
   if (y == 0) { interactive=1; goto next; }
   y = IsPrefixOrEqual((const char *)token, (const char *)"-v");
   if (y == 0) { vfprint("⬚ version ⬚\n", argv[0], "0x" QUOTE(SHA1GIT)); goto next; }
   y = IsPrefixOrEqual((const char *)token, (const char *)"-l"); /* rows to process. */
   if (y == 0) { only₋until₋row=1; goto next; }
   y = IsPrefixOrEqual((const char *)token, (const char *)"-");
   if (y > 0) { vfprint("Unknown command-line argument\n"); exit(3); }
   append₋reference(token,&filepaths₋sequence);
next:
   i+=1; goto again;
unagain:
   return 0;
}

unicode₋shatter ᐝ open₋and₋decode(char8₋t * textfile, int expand₋tilde, int * err)
{
   const char * u8path𝘖r𝙽𝚄𝙻𝙻 = (const char *)textfile;
   if (expand₋tilde) { wordexp_t expansion₂; 
     if (wordexp(u8path𝘖r𝙽𝚄𝙻𝙻,&expansion₂,0)) { *err=1; return ΨΛΩ; } /*  enter 
      'prompt% man wordexp' for details. */
     u8path𝘖r𝙽𝚄𝙻𝙻 = expansion₂.we_wordv[0];
   }
   __builtin_int_t u8bytes,symbols;
   if (!FileSystemItemOpenable(u8path𝘖r𝙽𝚄𝙻𝙻,&u8bytes)) { *err=2; return ΨΛΩ; }
   int fd = open(u8path𝘖r𝙽𝚄𝙻𝙻,O_RDONLY);
   if (fd == -1) { *err=3; return ΨΛΩ; }
   /* void * p = mmap(0, 1 + u8bytes,PROT_READ,MAP_SHARED,fd,0);
    the abstraction 'mmap' is too descriptive. */
   char8₋t * material = (char8₋t *)Heap₋alloc(u8bytes + 1);
   ssize_t bytesread = read(fd,material,u8bytes);
   if (bytesread != u8bytes) { *err=5; return ΨΛΩ; }
   if (close(fd) == -1) { *err=7; return ΨΛΩ; } /* det kan ju /vara-lõst/ pā olika sātt 
    och 'det har vi aldrig sagt'. */
   /* if (p == MAP_FAILED) { exit(8); } */
   *(material + u8bytes) = 0x04;
   unicode₋shatter text = (unicode₋shatter)Heap₋alloc(4*(u8bytes + 1));
   if (Utf8ToUnicode(1+u8bytes,material,text,&symbols)) { *err=8; return ΨΛΩ; }
#if defined TRACE₋ENCODING
   struct Unicodes debug₋text = { symbols, text };
   print₋decoded₋text(debug₋text);
#endif
   return text;
}

void branch₋rule₋file()
{ int err;
   rules = open₋and₋decode(rule₋path,false,&err);
   Argᴾ one = ﹟s8(rule₋path);
   switch (err) {
   case 1: vfprint("Expansion rejected on '⬚'\n", one); break;
   case 2: vfprint("No rule file named '⬚'\n", one); break;
   case 3: vfprint("Unable to open rule file named '⬚'\n", one); break;
   case 5: vfprint("Partially read rule file '⬚'.\n", one); break;
   case 7: vfprint("Lingering relat from '⬚'.\n", one); break;
   case 8: vfprint("Incomprehensible encoding in '⬚'.\n", one); break;
   }
   if (rules == ΨΛΩ) { exit(5); }
}

void branch₋figures₋file()
{ int err;
   /* expand ~ in e․𝘨 `~/myshoebox/myfigures.table`. */
   figures = open₋and₋decode(figures₋path,true,&err);
   Argᴾ one = ﹟s8(figures₋path);
   switch (err) {
   case 1: vfprint("Expansion rejected on '⬚'\n", one); break;
   case 2: vfprint("No figure file named '⬚'\n", one); break;
   case 3: vfprint("Unable to open figures file named '⬚'\n", one); break;
   case 5: vfprint("Partially read figures file '⬚'.\n", one); break;
   case 7: vfprint("Lingering relat from '⬚'.\n", one); break;
   case 8: vfprint("Incomprehensible encoding in '⬚'.\n", one); break;
   }
   if (figures == ΨΛΩ) { exit(7); }
}

int
main(
  int argc, 
  const char * argv[]
)
{ Simulator sim; unicode₋shatter events;
   struct language₋context streck₋ctxt;
    struct virtu₋context machine₋ctxt;
    error₋panel.diagnosis₋count = 0;
    Init₋context(&machine₋ctxt);
    if (collection₋init(sizeof(char8₋t *),4096,&filepaths₋sequence)) { exit(1); }
    option₋machine₋interprets(argc,(char8₋t *ᐧ*)argv);
    if (figures₋path) { branch₋figures₋file(); } /*  optional. */
    if (rule₋path) { branch₋rule₋file(); }/*  optional and upper half of event file. */
    if (collection₋count(&filepaths₋sequence) == 0)
    {
      vfprint("No event file given at command line.\n"); exit(2);
    } __builtin_int_t idx=0,fd,symbols; char8₋t * file₋ref; int err;
    
    if (rule₋path) {
      if (Init₋context(rule₋path,&streck₋ctxt)) { exit(10); }
      symbols = Heap₋object₋size(rules);
      struct Unicodes program = { symbols, rules };
      if (BsimParse(&streck₋ctxt,program,&machine₋ctxt)) { exit(12); }
    }
    
again:
    
    if (idx >= argc) { goto unagain; }
    file₋ref = (char8₋t *)collection₋relative(idx,&filepaths₋sequence);
    events = open₋and₋decode(file₋ref,true,&err);
    symbols = Heap₋object₋size(events);
    streck₋ctxt->text₋program = { symbols, events };
    if (Init₋context(file₋ref,&streck₋ctxt)) { exit(10); }
#if defined TRACE₋TOKENS
    tokenize₋streck(&streck₋ctxt,program);
#endif
    if (BsimParse(&streck₋ctxt,program,&machine₋ctxt)) { exit(12); }
    Fallow(events); idx+=1; goto again;
    
unagain:
    
    if (interactive) { EnterInteractiveMode(&sim); }
    if (Simulate(&machine₋ctxt,&sim)) { exit(13); }
    
    if (figures₋path)
    { chronology₋instant bye₋ts; /* 𝘦․𝘨 'material ending 2019-12-24 23:59:59 rendered 2022-09-23 17:05'. */
      symbols = Heap₋object₋size(figures)/4;
      struct Unicodes program = { symbols, figures };
      struct language₋context table₋ctxt;
      if (Init₋context(figures₋path,&table₋ctxt)) { exit(15); }
      if (Rendertable(&table₋ctxt,&sim.history,program,bye₋ts)) { exit(17); }
    }
    
    Deinit₋context(&machine₋ctxt);
    
    return 0;
} /*  simulate events and output figures often at end-of-simulation. */

