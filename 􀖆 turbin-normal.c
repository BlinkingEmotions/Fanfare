/*  turbin-normal.c | modellers' traveller companion. (CORP. EDITION.) */

import Twinbeam; /*  he is sitting in a box 𝘦․𝘨 T-FOR-D and De-la-v-all. */

enum symbol₋class { ident=1, machine, monetary, times, divide, plus, minus, 
 lparen, rparen, eqlone, transcriptsym, instant, bookkeepsym, debetsym, 
 creditsym, commentsym, varsym, printsym, breaksym, setsym, returnsym, dosym, 
 endsym, beforesym, entitysym, accountsym, tablesym, createsym, namedsym, 
 tradingsym, residentsym, withsym, schedulesym, startssym, occurssym, 
 exchangesym, currencysym, popsym, swapsym, dupsym, reportsym, boldsym, 
 quotesym, eot₋and₋file, unarbitrated₋symbol 
};

/* compile with ./retro-mac.sh essence-turbin */

enum language₋mode {
  mode₋initial, mode₋integer, mode₋regular, mode₋fraction, 
  mode₋single₋ekunem, mode₋multi₋ekunem, mode₋quotes₋text 
};

typedef int64_t Integer;
typedef Sequenta Real; /*  base two and ten hardware Ieee754 and software arithmetics. */
typedef chronology₋instant Instant;

#include "Ω⃝-translate-formal.cxx"

struct language₋context
{
  __builtin_int_t tip₋unicode;
  enum language₋mode state; 
  char32̄_t regular[2048];
  double ongoing₋number;
  short zero₋to₋nines[100];
  Nonabsolute reference₋quoted;
  short syms₋in₋regular;
  short syms₋in₋number;
  short syms₋in₋fraction;
  short syms₋in₋quotes;
  struct source₋location interval;
  struct Unicodes program₋text;
  char8₋t * source₋path;
  Trie keys;
  int negative;
}; /*  a․𝘬․a 'verificate₋parser and token-i-sa-tio-n. language and code 
 library is exercised in a separate language for auctions and the agreement. */

typedef struct token₋detail
{
  union { 
    Nonabsolute regular;
    double number;
    __builtin_int_t integer;
  } store;
  int kind;
  struct language₋context * predecessor;
  struct source₋location interval;
} Td;

typedef struct Symbol { enum symbol₋class class; Td gritty; } Symbol;

struct dynamic₋bag { };

typedef struct translation {
  struct language₋context ctxt;
  Symbol symbol₋passed,symbol,retrospect;
  struct collection *ident,*text;
  struct dynamic₋bag * bu₋fragment,*td₋tree;
} Translation;

int Init₋translation₋unit(char8₋t * src₋path, Translation * t, int language)
{
   t->ctxt.tip₋unicode=0;
   t->ctxt.state=mode₋initial;
   t->ctxt.syms₋in₋regular = 0;
   t->ctxt.syms₋in₋number = 0;
   t->ctxt.syms₋in₋fraction = 0;
   t->ctxt.ongoing₋number = 0;
   t->ctxt.source₋path = src₋path;
   location₋init(&t->ctxt.interval);
   t->symbol₋passed.class = unarbitrated₋symbol;
   t->ident = Alloc(sizeof(struct collection));
   if (init₋regularpool(t->ident)) return -1;
   t->text = Alloc(sizeof(struct collection));
   if (init₋regularpool(t->text)) return -1;
   /* td₋tree = new₋Unit(), bu-fragment */
   t->ctxt.program₋text = Run(U"2023-01-01 12:00:00 PRINT 'Starting simulation.'\n");
   switch (language)
   {
   case 1: {
    char32̄_t * keywords[] = { U"TRANSCRIPT", U"BOOKKEEP", U"DEBET", 
     U"CREDIT", U"COMMENT", U"VAR", U"PRINT", U"BREAK", U"SET", U"RETURN", 
     U"DO", U"END", U"BEFORE", U"ENTITY", U"ACCOUNT", U"TABLE", U"CREATE", 
     U"NAMED", U"TRADING", U"RESIDENT", U"WITH", U"SCHEDULE", U"STARTS", 
     U"OCCURS", U"EXCHANGE", U"CURRENCY" };
    int symbols[] = { transcriptsym, bookkeepsym, debetsym, creditsym, 
     commentsym, varsym, printsym, breaksym, setsym, returnsym, dosym, 
     endsym, beforesym, entitysym, accountsym, tablesym, createsym, 
     namedsym, tradingsym, residentsym, withsym, schedulesym, startssym, 
     occurssym, exchangesym, currencysym };
    merge₋to₋trie(29,keywords,symbols,&t->ctxt.keys);
    break; }
   case 2: {
    char32̄_t * keywords[] = { U"DUP", U"POP", U"SWAP", U"REPORT", U"BOLD" };
    int symbols[] = { dupsym, popsym, swapsym, reportsym, boldsym };
    merge₋to₋trie(5,keywords,symbols,&t->ctxt.keys);
    break; }
   }
   return 0;
}

Argᴾ ﹟ident(struct collection * ident, Nonabsolute relative)
{
   return ﹟regularpool(ident,relative);
}

struct { __builtin_uint_t diagnosis₋count,bitmap; } error₋panel;

#define STATE(s) (s == t->ctxt.state)
#define TRACE₋TOKENS  /* while reading .streck and .table files, print-out tokens on stdout. */
#define TRACE₋SYNTAX /* after parsing .streck files, print the indented syntax tree on stdout. */
#define TRACE₋SYMBOLS /* emit all symbols in string pool. */
#define TRACE₋ENCODING /* after decoding utf-8 output the decoded Unicodes to stdout. */

void Diagnos(int type, char8₋t * src₋path, struct source₋location * l, 
 int bye, const char * sevenbit₋utf8, ...)
{  va_prologue(sevenbit₋utf8); ;
   __builtin_int_t lineno₋first=l->lineno₋first, 
    linecount=(l->lineno₋last-l->lineno₋first+1), 
    column₋first=l->column₋first, 
    column₋last=l->column₋last;
   vfprint("⬚ (⬚) ⫶ ⬚—⬚ ⬚.", ﹟s8(src₋path), ﹟d(lineno₋first), 
    ﹟d(column₋last), ﹟d(column₋last));
   vfprint(" (⬚ line", ﹟d(linecount));
   if (linecount != 1) { vfprint("s"); }
   typedef void (^Output)(char8₋t * u8s, __builtin_int_t bytes);
   extern int print﹟(Output,const char *,__builtin_va_list);
   extern int write(int,const void *,int);
   Output output = ^(char8₋t * u8s, __builtin_int_t bytes) { 
    write(2,(const void *)u8s,bytes); };
   print﹟(output,sevenbit₋utf8,__various);
   vfprint(")\n");
   va_epilogue;
   if (bye) { exit(29); } else { error₋panel.diagnosis₋count += 1; }
} /* type determines void, sevenbit text starts with 'info', 'warning', 
 'error', 'intern'. */

int special(char32̄_t uc)
{ int i=0;
   static char32̄_t sorted₋cases[] = {
     U'ٖ', U'ᵢ',U'ᵣ',U'ᵤ',U'ᵥ',U'ᵦ',U'ᵧ',U'ᵨ',U'ᵩ',U'ᵪ', 
     U'₊',U'₋',U'₌',U'₍',U'₎',U'⨧',U'ₐ',U'ₑ',U'ₒ',U'ₓ', 
     U'ₔ',U'ⱼ',U'ₕ',U'ₖ',U'ₗ',U'ₘ',U'ₙ',U'ₚ',U'ₛ',U'ₜ' };
again:
    if (i>=30) goto unagain;
    if (uc == sorted₋cases[i]) return true;
    i+=1; goto again;
unagain:
    return false;
};

int digit(char32̄_t uc) { return U'0' <= uc && uc <= U'9'; }
int arabic(char32̄_t uc) { return (U'a' <= uc && uc <= U'z') || 
 (U'A' <= uc && uc <= U'Z') || uc == U'₋'; }
int subscript(char32̄_t uc) { return U'₀' <= uc && uc <= U'₉'; }
int supscript(char32̄_t uc) { return U'⁰' <= uc && uc <= U'⁹'; }
int letter(char32̄_t uc) { return arabic(uc) || subscript(uc) || 
 supscript(uc) || special(uc); };

void assign₋symbol(enum symbol₋class s, short advance, 
 struct language₋context * ctxt, Symbol * sym)
{ sym->class=s;
   if (advance >= 2) ctxt->tip₋unicode+=advance-1;
   location₋symbol(&ctxt->interval,advance,&sym->gritty.interval);
}

int copy₋identifier(struct language₋context * ctxt, struct collection * 
 identifiers, Symbol * out) 
{ char32̄_t * ucs=ctxt->regular;
   __builtin_int_t tetras=ctxt->syms₋in₋regular;
   Nonabsolute reference = collection₋count(identifiers);
   if (copy₋prepare₋datum(identifiers,Alloc)) return -1;
   if (copy₋append₋onto₋regular(identifiers,tetras,ucs,Alloc)) return -1;
   if (regularpool₋datum₋text(identifiers,tetras,reference)) return -1;
   location₋symbol(&ctxt->interval,tetras,&out->gritty.interval);
   out->class=ident; out->gritty.kind=1;
   out->gritty.store.regular=reference;
   return 0;
}

int copy₋number(struct language₋context * ctxt, Symbol * out, int type)
{
   location₋symbol(&ctxt->interval,ctxt->syms₋in₋number,&out->gritty.interval);
   switch (type)
   {
   case 1:
     out->class=machine; 
     out->gritty.store.integer = ctxt->ongoing₋number;
     out->gritty.kind=3;
     break;
   case 2:
     out->class=monetary;
     out->gritty.store.number = (double)ctxt->ongoing₋number;
     out->gritty.store.number += 0.0; /* ! \see --<Additions>--<monolith-sequent.c>{fraction₋to₋sequent}. */
     out->gritty.kind=2;
     break;
   }
   return 0;
}

void assign₋symbol₋noforward(enum symbol₋class s, short count₋impression, 
 struct language₋context * ctxt, Symbol * sym)
{ sym->class=s;
   location₋symbol(&ctxt->interval,count₋impression,&sym->gritty.interval);
}

#define ELIF₋INIT₋WITH₋ONE(sym) else if (STATE(mode₋initial) && uc == sym)
#define ELIF₋INIT₋WITH₋TWO(sym1,sym2) else if (STATE(mode₋initial) &&        \
 uc == sym1 && uc₊₁ == sym2) 
#define ELIF₋INIT₋WITH₋TEE(sym1,sym2,sym3) else if (STATE(mode₋initial) &&   \
 uc == sym1 && uc₊₁ == sym2 && uc₊₂ == sym3)
#define RET return 0;
#define EL₋CONFESS else confess(trouble);

int next₋token₋inner(Translation * t, Symbol * out)
{ __builtin_int_t i,symbols=t->ctxt.program₋text.tetras; char32̄_t uc,uc₊₁,uc₊2;
    int lift₋count=0,sym;
    struct language₋context * ctxt = &t->ctxt;

   🧵(identifier,machine₋constant,fixpoint₋constant,quoted,keyword,trouble, \
    completion)
   {
   case identifier: copy₋identifier(ctxt,t->ident,out); 
    t->ctxt.syms₋in₋regular=0; t->ctxt.state=mode₋initial; return 0;
   case machine₋constant: return 0;
   case fixpoint₋constant: return 0;
   case quoted: t->ctxt.state=mode₋initial; return 0;
   case keyword: assign₋symbol₋noforward(sym,t->ctxt.syms₋in₋regular,ctxt,out); 
    t->ctxt.syms₋in₋regular=0; t->ctxt.state=mode₋initial; return 0;
   case completion: assign₋symbol(eot₋and₋file,0,ctxt,out); return 0;
   case trouble: vfprint("trouble occurred at ⬚.\n", ﹟d(t->ctxt.tip₋unicode)); 
    return -1;
   }
again:
   i=t->ctxt.tip₋unicode; t->ctxt.tip₋unicode+=1;
   if (i >= symbols) confess(completion);
   if (i == symbols - 1) lift₋count=2;
   if (i == symbols - 2) lift₋count=1;
   char32̄_t * unicodes = t->ctxt.program₋text.unicodes;
   uc = *(unicodes + i);
   uc₊₁ = lift₋count >= 2 ? U' ' : *(unicodes + i + 1);
   uc₊2 = lift₋count >= 1 ? U' ' : *(unicodes + i + 2);
   struct source₋location * intervalref = &t->ctxt.interval;
   if (STATE(mode₋initial) && uc == U'\xa') {
     location₋nextline(intervalref);
   }
   else if (STATE(mode₋initial) && uc == U'\xd') { /* do nothing. */}
   else if (STATE(mode₋initial) && uc == U'/' && uc₊₁ == U'*') {
     t->ctxt.tip₋unicode+=1,t->ctxt.state=mode₋multi₋ekunem; }
   else if (STATE(mode₋multi₋ekunem) && uc == U'\xa') { 
     location₋nextline(intervalref); }
   else if (STATE(mode₋multi₋ekunem) && uc == U'*' && uc₊₁ == U'/') { 
     t->ctxt.tip₋unicode+=1,t->ctxt.state=mode₋initial; }
   else if (STATE(mode₋multi₋ekunem)) { /* do nothing. */ }
   else if (STATE(mode₋initial) && uc == U'/' && uc₊₁ == U'/')
   { t->ctxt.tip₋unicode+=1,t->ctxt.state=mode₋single₋ekunem; }
   else if (STATE(mode₋single₋ekunem) && uc == '\xa') {
     t->ctxt.state=mode₋initial; location₋nextline(intervalref); }
   else if (STATE(mode₋single₋ekunem)) { /* do nothimg. */ }
   ELIF₋INIT₋WITH₋ONE(U' ') { location₋legion(intervalref); }
   ELIF₋INIT₋WITH₋ONE(U'\t') { location₋legion(intervalref); }
   ELIF₋INIT₋WITH₋ONE(U'(') { assign₋symbol(lparen,1,ctxt,out); RET }
   ELIF₋INIT₋WITH₋ONE(U')') { assign₋symbol(rparen,1,ctxt,out); RET }
   ELIF₋INIT₋WITH₋ONE(U'*') { assign₋symbol(times,1,ctxt,out); RET }
   ELIF₋INIT₋WITH₋ONE(U'/') { assign₋symbol(divide,1,ctxt,out); RET }
   ELIF₋INIT₋WITH₋ONE(U'+') { assign₋symbol(plus,1,ctxt,out); RET }
   ELIF₋INIT₋WITH₋ONE(U'-') { assign₋symbol(minus,1,ctxt,out); RET }
   ELIF₋INIT₋WITH₋ONE(U'=') { assign₋symbol(eqlone,1,ctxt,out); RET }
   else if (STATE(mode₋initial) && uc == U'\'') {
     ctxt->reference₋quoted = collection₋count(t->text);
     if (copy₋prepare₋datum(t->text,Alloc)) confess(trouble);
     ctxt->syms₋in₋quotes=0;
     ctxt->state = mode₋quotes₋text;
     location₋legion(&ctxt->interval);
   }
   else if (STATE(mode₋quotes₋text) && uc != U'\'') {
     if (uc == U'\\' && uc₊₁ == U'"') { ctxt->tip₋unicode+=1; uc=U'"'; }
     if (copy₋append₋onto₋regular(t->text,1,&uc,Alloc)) confess(trouble);
   }
   else if (STATE(mode₋quotes₋text) && uc == U'\'') {
     if (regularpool₋datum₋text(t->text,ctxt->syms₋in₋quotes, 
      ctxt->reference₋quoted)) return -1;
     assign₋symbol₋noforward(quotesym,ctxt->syms₋in₋quotes,ctxt,out);
     confess(quoted);
   }
   else if ((STATE(mode₋initial) && letter(uc)) || (STATE(mode₋regular) && (letter(uc) || digit(uc)))) {
    if (ctxt->syms₋in₋regular == 2048) {
      Diagnos(1,ctxt->source₋path,&t->symbol.gritty.interval,1,
        "identifier and keyword too long");
      confess(trouble); }
     ctxt->regular[ctxt->syms₋in₋regular]=uc;
     ctxt->syms₋in₋regular+=1;
     ctxt->state=mode₋regular;
     if(!letter(uc₊₁) && !digit(uc₊₁)) {
      if (!trie₋keyword(ctxt->syms₋in₋regular,ctxt->regular,&sym,&ctxt->keys))
        confess(keyword);
      confess(identifier);
     } 
   }
   else if (STATE(mode₋fraction) && digit(uc)) {
     ctxt->zero₋to₋nines[ctxt->syms₋in₋fraction] = uc;
     ctxt->syms₋in₋fraction+=1;
     if (!digit(uc₊₁)) confess(fixpoint₋constant);
   }
   else if ((STATE(mode₋initial) && digit(uc))) {
     ctxt->ongoing₋number*=10;
     ctxt->ongoing₋number+=(uc - U'0');
     ctxt->syms₋in₋number+=1;
     if (uc₊₁ == U'.') { ctxt->state = mode₋fraction; ctxt->tip₋unicode+=1; }
     if (ctxt->syms₋in₋number == 4 && uc₊₁ == U'-') {
       /* attempt Timestamp... from tip₋unicode - 4 and X onward. */
       chronology₋instant stamp; 
       int bytes=min(symbols - ctxt->tip₋unicode, 19);
       uint8_t * material=(uint8_t *)(ctxt->tip₋unicode - 3);
       if (bytes != 19) goto atlast;
       int y =Timestamp(encoding₋unicode,bytes,material,&stamp);
       if (y != 0) goto atlast;
     }
atlast:
     if (!digit(uc₊₁)) confess(machine₋constant);
   }
   EL₋CONFESS
   goto again;
}

int next₋token₋streck(Translation * t)
{ int y;
   if (t->ctxt.tip₋unicode == 0) {
     y = next₋token₋inner(t,&t->symbol);
     if (y != 0) { Diagnos(1,t->ctxt.source₋path,&t->symbol.gritty.interval,1, 
      "streck scanner error, initial trouble"); exit(2); }
   } else {
     t->symbol₋passed = t->symbol;
     t->symbol = t->retrospect;
   }
   y = next₋token₋inner(t,&t->retrospect);
   if (y != 0) { Diagnos(1,t->ctxt.source₋path,&t->retrospect.gritty.interval, 
    1,"streck scanner error, advance failure"); exit(3); }
#if defined TRACE₋TOKENS
   void trace₋token(Symbol, struct collection *);
   trace₋token(t->symbol,t->ident);
#endif
   return 0;
}

#pragma recto outcometh and abstract

typedef struct dynamic₋bag expression;
typedef struct dynamic₋bag statement;
typedef struct dynamic₋bag statements;

struct sequence { chronology₋instant stamp; statements stmts; };

typedef struct dynamic₋bag sequences;

/*  🅩₋literal, 🅡₋literal, string₋to₋🅽, 🅩₋to₋🅡 */

#pragma recto parsing northern 'således' tran-sact-ions and veri-fi-c-at-es

/* a․𝘬․a bokföringssed, custom and recollect. 𝘤𝘧․ anglo-saxian 'modelling', 
 scandinavian 'nogsamhet' and 'likely-surely'. And a․𝘬․a 'table₋parser' and 
 terminals-and-nonterminals․ */

typedef struct virtu₋context
{
  sequences program;
  chronology₋instant last;
} simul₋context;


int Prepared(char8₋t * streck₋source₋path, Translation * t)
{
   return 0;
}

int BsimParse(Translation * t, simul₋context * ctxt₋out)
{
   return 0;
}

#pragma recto stochastic and deterministic simulation

#include <sys/queue.h>
#include <sys/rbtree.h>
#include <unicode/ustring.h>
#include <readline/readline.h>
#undef true
#include <string.h>

typedef struct Itwiż₋Cuideam {
   Instant effect;
   Real weight₋lo, weight₋hi;
   Nonabsolute unit₋lo, unit₋hi;
 } Exchange; /* the two units are sorted on sha-256. */

typedef struct Currency { 
  rb_node_t node;
  UChar * name;
} Munita;

typedef struct Entity {
  rb_node_t node;
  UChar * name;
  struct timeserie history; /* a․𝘬․a 'book'. */
  version₋ts revision;
} Entity;

typedef struct Schedule {
  rb_node_t node;
  UChar * name;
  chronology₋instant starts;
  struct chronology₋relative period;
} Schedule;

typedef struct Simulator {
  rb_tree_t entities; rb_tree_ops_t entity₋ops;
  __builtin_int_t prompt_number;
} Simulator;

int IsReversed(Nonabsolute left, Nonabsolute right, struct collection * ident);
int Append(Real vleft, Nonabsolute uleft, Real vright, Nonabsolute uright, 
 int reversed, Exchange * exch) ⓣ;
int Append(UChar name, Entity * entity) ⓣ;
int Append(UChar name, Munita * currency) ⓣ;
int Conversion(Instant instant, Real value, Nonabsolute src, Nonabsolute dst, Real * also);

/* #include "ⓔ-helper.h" */

void EnterInteractiveMode(int * quit, Simulator * 🅢);
int Simulate(simul₋context * 🆂, Simulator * 🅢);
/* extern int Zebra(int count, chronology₋instant toggles[], chronology₋
 instant now, double * out); sometime uniform and normal not same time. */

#include "ⓔ-simulator.cxx"

#pragma recto computation two tables 'annual return' and 'profit and loss'

int Rendertable(Translation * t, Simulator * sim, 
 chronology₋instant when);
int Tableparse(struct Unicodes program, char8₋t * path, 
 Translation * t);

#include "ⓔ-table.cxx"

void Deinit₋context(simul₋context * ctxt)
{

}

#pragma recto command line (zsh compsys and Minimum completion)

/* file-open (⌘O), file-save (⌘S), find (⌘F), emoji and symbols (⌘E) completion . */

/* show completions ^ Space, record macro ^ Q, playback macro ^ ⇧ Q. */

/* zsh is not popover. */ /* P(E|F)=P(E∩F)/P(F) */

#pragma recto startup and optional report at end

#include <stdio.h> /* ...and `fprintf`, `FILE`, `fopen`, `fread`, 
 `fseek`, `fclose`, `SEEK_SET`, `stdout` and `stderr`… */
#include <stddef.h> /* For `size_t`… */
#include <stdlib.h> /* …together with `malloc` and `exit`. */
#include <wordexp.h> /* and of course: figures file path ~ expansion. */
#include <sys/stat.h> /* for 'FileSystemItemOpenable'. */
#include <unistd.h>
#include <fcntl.h>

char8₋t * figures₋path=ΨΛΩ;  /*  figures file and implicit DISPLAY TABLE at 
 end-of-file. */

char8₋t * rule₋path=ΨΛΩ; /*  rules file when not included in upper half of 
 event file. */

int interactive=0;  /*  end with bye when file is read and report is
  written. */

int read₋until₋row=0;  /*  parse-interpret only start of file. */

struct collection filepaths₋sequence; /* with 'char8-t *' pointing on the 
 .event files from command-line. */

unicode₋shatter figures, rules;  /*  unicodes with program text. */

int FileSystemItemOpenable(const char * u8path, __builtin_int_t * bytes)
{ struct stat st; int y = stat(u8path,&st);
   if (y == 0) { *bytes = (__builtin_int_t)(st.st_size); }
   return y == 0 ? 1 : 0;
}

void append₋reference(void * path, struct collection * 🅰)
{
   if (copy₋append₋items(1,&path,🅰,Heap₋alloc)) { return; }
}

int option₋machine₋interprets(int argc, char8₋t *ᐧ* argv)
{ int i=1,y,figures₋option=0,rule₋option=0,only₋until₋row=0; 
   char8₋t * token, *msg=U8("");
again:
   if (i>=argc) { goto unagain; }
   token = *(argv + i);
   if (figures₋option) { figures₋path=token; figures₋option=0; goto next; }
   if (rule₋option) { rule₋path=token; rule₋option=0; goto next; }
   if (only₋until₋row) { read₋until₋row=atoi((char *)token); 
    only₋until₋row=0; goto next; }
   y = IsPrefixOrEqual((const char *)token,"-h");
   if (y == -1) { vfprint("Usage ⬚ [-f <figures.table file>] [-r "
    "<business.streck file>] [-g] [-l <lineno>] " 
    "<.streck files>\n", ﹟s8(argv[0])); exit(27); }
   y = IsPrefixOrEqual((const char *)token,"-f");
   if (y == -1) { figures₋option=1; goto next; }
   y = IsPrefixOrEqual((const char *)token,"-r");
   if (y == -1) { rule₋option=1; goto next; }
   y = IsPrefixOrEqual((const char *)token,"-g");
   if (y == -1) { interactive=1; goto next; }
   y = IsPrefixOrEqual((const char *)token,"-v");
   if (y == -1) { char * tb; Identity₋Tb(&tb); 
    vfprint("⬚ version ⬚ and tb-⬚.\n",﹟s8(argv[0]),﹟s7(SHA1GIT),﹟s7(tb));
    goto next; }
   y = IsPrefixOrEqual((const char *)token,"-l"); /* rows to process. */
   if (y == -1) { only₋until₋row=1; goto next; }
   y = IsPrefixOrEqual((const char *)token,"-");
   if (y > 0 || y == 0) { vfprint("Unknown turbin parameter '⬚'.\n", 
    ﹟s8(token)); exit(21); }
   append₋reference(token,&filepaths₋sequence);
next:
   i+=1; goto again;
descriptive:
   vfprint("turbin command-line error '⬚'\n",﹟s8(msg));
   return -1;
unagain:
   if (figures₋option) { msg=U8("no figures file given"); goto descriptive; }
   if (rule₋option) { msg=U8("no rule file given"); goto descriptive; }
   return 0;
}

unicode₋shatter ᐝ open₋and₋decode(char8₋t * textfile, int expand₋tilde, 
 int * err)
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
   char8₋t * material = (char8₋t *)Heap₋alloc(u8bytes + 1);
   ssize_t bytesread = read(fd,material,u8bytes);
   if (bytesread != u8bytes) { *err=5; return ΨΛΩ; }
   if (close(fd) == -1) { *err=7; return ΨΛΩ; }
   *(material + u8bytes) = 0x04;
   unicode₋shatter text = (unicode₋shatter)Heap₋alloc(4*(u8bytes + 1));
   if (Utf8ToUnicode(1+u8bytes,material,text,&symbols)) { *err=8; return ΨΛΩ; }
   Heap₋unalloc(material);
#if defined TRACE₋ENCODING
   struct Unicodes debug₋text = { symbols, text };
   EXT₋C void print₋decoded₋text(struct Unicodes);
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
   if (rules == ΨΛΩ) { exit(17); }
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
   if (figures == ΨΛΩ) { exit(13); }
}

int
main(
  int argc, 
  const char * argv[]
)
{ Simulator simulator; unicode₋shatter events;
   Translation trans;
    simul₋context machine₋ctxt;
    error₋panel.diagnosis₋count = 0;
    if (collection₋init(sizeof(char8₋t *),4096,&filepaths₋sequence)) { 
     exit(1); }
    if (option₋machine₋interprets(argc,(char8₋t *ᐧ*)argv)) { exit(2); }
    if (figures₋path) { branch₋figures₋file(); } /*  optional .table file rendered at end. */
    if (rule₋path) { branch₋rule₋file(); }/*  optional and upper half of event file. */
    if (!interactive && collection₋count(&filepaths₋sequence) == 0)
    {
      vfprint("No event file given at command line.\n"); exit(3);
    } __builtin_int_t idx=0,fd,symbols; char8₋t * file₋ref; int err;
    
    if (rule₋path) {
      symbols = Heap₋object₋size(rules)/4;
      struct Unicodes initial₋program = { symbols, rules };
      trans.ctxt.program₋text = initial₋program;
      if (Init₋translation₋unit(rule₋path,&trans,1)) { exit(31); }
      if (Prepared(rule₋path,&trans)) { exit(4); }
      if (BsimParse(&trans,&machine₋ctxt)) { exit(5); }
    }
again:
    if (idx >= collection₋count(&filepaths₋sequence)) { goto unagain; }
    file₋ref = (char8₋t *)collection₋relative(idx,&filepaths₋sequence);
    events = open₋and₋decode(file₋ref,true,&err);
    symbols = Heap₋object₋size(events)/4;
    struct Unicodes main₋program = { symbols, events };
    trans.ctxt.program₋text = main₋program;
    if (Init₋translation₋unit(file₋ref,&trans,1)) { exit(33); }
    if (Prepared(file₋ref,&trans)) { exit(7); }
    if (BsimParse(&trans,&machine₋ctxt)) { exit(8); }
    Fallow(events); idx+=1; goto again;
unagain:
    if (interactive) { int quit; EnterInteractiveMode(&quit,&simulator); }
    if (Simulate(&machine₋ctxt,&simulator)) { exit(9); }
    
    if (figures₋path) /* ta-bell. */
    { chronology₋instant bye₋ts; /* 𝘦․𝘨 'material ending 2019-12-24 23:59:59 rendered 2022-09-23 17:05'. */
      symbols = Heap₋object₋size(figures)/4;
      struct Unicodes program = { symbols, figures };
      if (Init₋translation₋unit(rule₋path,&trans,2)) { exit(37); }
      if (Tableparse(program,figures₋path,&trans)) { exit(10); }
      if (Rendertable(&trans,&simulator,bye₋ts)) { exit(11); }
    }
    
    Deinit₋context(&machine₋ctxt);
    
    return 0;
} /*  simulate events and output figures often at end-of-simulation. */

#include "ⓔ-debug.cxx"

