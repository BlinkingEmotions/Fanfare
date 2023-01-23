/*  􁋹 µ-parse.c | infix computation, location, inclusion, presentation-
 prominent, sequent, schema, folding and retrieval-correctness harvesting 
 essentials. */

import Twinbeam;

enum symbol₋class { ident, number, times, divide, plus, minus, lparen, 
 rparen, eql, neq/*=10*/, lss, leq, gtr, geq, semicolon, callsym, beginsym, 
 endsym, /* whilesym, dosym, forsym */ branch₋goto₋optsym/*=20 inner and 
 outer iteration */, elsesym, thensym, ifsym, afterward, constsym, varsym, 
 procsym, period, comma, oddsym/*=30*/, voidsym, sectionsym, textsym, 
 lformalrefpressym, rformalpresentsym, rformalreferencesym, additionssym, 
 colon, label, symbol₋for₋enquery/*=40*/, end₋of₋transmission₋and₋file, 
 uninit₋symbol, logical₋alternate, logical₋and, logical₋or, logical₋not, 
 diffusesym, referencessym, dowsingsym, ellipsissym, leftrightread, insym, schemasym
}; /* .IF. .ELSE. .ELIF. .END. .INCLUDE. .DEFINE. DEFINED */

/* clang -g -fmodules-ts -fimplicit-modules -fmodule-map-file=🚦.modules      \
 '􁋹 µ-parse.c' ../Apps/Source/Releases/libTwinbeam-x86_64.a                  \
  ../Apps/Additions/monolith-sequent.c */

enum language₋mode { mode₋initial, mode₋integer, mode₋regular, 
 mode₋fixpoint, mode₋collection };

struct source₋location {
  __builtin_int_t lineno₋first,lineno₋last,column₋first,column₋last;
};

void location₋init(struct source₋location * l) {
 struct source₋location initial₋interval = { 1, 1, 1, 1 };
 *l=initial₋interval; }
void location₋nextcolumn(struct source₋location * l) { l->column₋first = 1 + 
 l->column₋last; l->column₋last=l->column₋first; }
void location₋symbol(struct source₋location * l, int width, 
 struct source₋location * out) { l->column₋last = width + l->column₋first - 1; 
 *out=*l; l->column₋last+=1; l->column₋first = l->column₋last; }
void location₋nextline(struct source₋location * l) {
 l->lineno₋first+=1,l->lineno₋last=l->lineno₋first,
 l->column₋first=l->column₋last=1;
}

struct language₋context {
  __builtin_int_t tip₋unicode;
  int carrier₁,carrier₂; /* 'retrospect did purge newline' and 'retrospect₋detail and 
   retrospect₋summar differs' and 'summar is always ahead'. */
  /* retrospect is identifier,'call','begin','if','while' and while reading 
   into 'symbol' we passed a (in case of multiple, thelast) 'carriage return' 
   then from lexer insert semicolon. */
  enum language₋mode state;
  char32̄_t regular[2048];
  short syms₋in₋regular;
  __builtin_int_t ongoing;
  short syms₋in₋number;
  struct source₋location interval;
  /* short zero₋to₋nines[100]; short syms₋in₋fraction; */
  Trie keys;
};

typedef struct Symbolinterval { short symbols; char32̄_t * start; } Symbolinterval;

typedef Nonabsolute Nonabsolut;

struct token₋detail {
  union {
    Nonabsolut regularOrIdent;
    Sequenta number;
    __builtin_int_t integer;
  } store;
  int kind;
  struct source₋location interval;
};

typedef struct Symbol { enum symbol₋class class; struct token₋detail gritty; } Symbol;

struct Unicodes text; struct language₋context Ctxt; /* executable and parser. */

Symbol symbol₋passed; /*  a․𝘬․a 'memory after reading passed' and 'ground₋fold'. */
Symbol symbol,retrospect; /* the global variable `symbol` are among scholars known as `lookahead`. */

#define STATE(s) (s == ctxt->state)
#define TRACE₋TOKENS
#define TRACE₋SYNTAX
#define TRACE₋SYMBOL

typedef void (^Utf8)(char8₋t *,__builtin_int_t);

void error(int type, char text[], ...)
{ va_prologue(text)
   int write(int,const char *,...);
   int print﹟(Utf8,const char *,__builtin_va_list);
   Utf8 out = ^(char8₋t * u8s, __builtin_int_t bytes) { write(1,(const void *)u8s,bytes); };
   print﹟(out,text,__various);
   print(out,".\n");
   va_epilogue
}

struct collection * identifiers;

void assign₋symbol(enum symbol₋class s, Symbol * sym, short count₋impression)
{ sym->class=s;
   location₋symbol(&Ctxt.interval,count₋impression,&sym->gritty.interval);
}

int symbol₋equal(enum symbol₋class s) { return symbol.class==s; }

int copy₋identifier(struct language₋context * ctxt, Symbol * out)
{ Nonabsolut reference = collection₋count(identifiers)/4;
   char32̄_t * ucs=ctxt->regular; __builtin_int_t tetras=ctxt->syms₋in₋regular;
   if (copy₋append₋onto₋regular(identifiers,tetras,ucs,Alloc,&reference)) { return -1; }
   if (regularpool₋datum₋text(identifiers,tetras,reference)) { return -1; }
   assign₋symbol(ident,out,tetras);
   return 0;
}

int copy₋number(struct language₋context * ctxt, Symbol * out, int type)
{ assign₋symbol(number,out,ctxt->syms₋in₋number);
   switch (type)
   {
   case 1:
     out->gritty.store.integer = ctxt->ongoing;
     out->gritty.kind = 3;
     break;
   /* case 2:
     int₋to₋sequent((int64_t)(ctxt->ongoing),&out->gritty.store.number);
     fraction₋to₋sequent(4,ctxt->zeroToNines,&out->gritty.store.number);
     out->gritty.kind = 2;
     break; */
   }
   return 0;
}

int next₋token₋inner(struct language₋context * ctxt, Symbol * out)
{ __builtin_int_t i,symbols=text.tetras; char32̄_t uc,uc₊₁,uc₊2; int lift₋count=0,sym;
   typedef int (^type)(char32̄_t); ctxt->carrier₁=0;
   type digit = ^(char32̄_t uc) { return U'0' <= uc && uc <= U'9'; };
   type letter = ^(char32̄_t uc) { return U'a' <= uc && uc <= U'z'; };
   🧵(identifier,integer₋constant,keyword,trouble,completion) {
   case identifier: copy₋identifier(ctxt,out); ctxt->syms₋in₋regular=0; ctxt->state=mode₋initial; return 0;
   case integer₋constant: copy₋number(ctxt,out,1); ctxt->ongoing=0; ctxt->syms₋in₋number=0; ctxt->state=mode₋initial; return 0;
   case keyword: assign₋symbol(sym,out,ctxt->syms₋in₋regular); ctxt->syms₋in₋regular=0; ctxt->state=mode₋initial; return 0;
   case completion: assign₋symbol(end₋of₋transmission₋and₋file,out,0); return 0;
   case trouble: return -1;
   }
again:
   i=ctxt->tip₋unicode,ctxt->tip₋unicode+=1;
   if (i >= symbols) { confess(completion); }
   if (i == symbols - 1) { lift₋count=2; }
   if (i == symbols - 2) { lift₋count=1; }
   uc = *(text.unicodes + i), 
   uc₊₁ = lift₋count >= 2 ? U' ' : *(text.unicodes + i + 1);
   uc₊2 = lift₋count >= 1 ? U' ' : *(text.unicodes + i + 2);
   if (STATE(mode₋initial) && uc == U'\xa') {
     /* lexer indicates 'semicolon on carriage return' (after reading retrospect) */
     ctxt->carrier₁=1; /* assign₋symbol(semicolon,out,1); */
     location₋nextline(&ctxt->interval);
   }
   else if (STATE(mode₋initial) && uc == U'\xd') { }
   else if (STATE(mode₋initial) && uc == U' ') { location₋nextcolumn(&ctxt->interval); }
   else if (STATE(mode₋initial) && uc == U'\t') { location₋nextcolumn(&ctxt->interval); }
   else if (STATE(mode₋initial) && uc == U'(') { assign₋symbol(lparen,out,1); return 0; }
   else if (STATE(mode₋initial) && uc == U')') { assign₋symbol(rparen,out,1); return 0; }
   else if (STATE(mode₋initial) && uc == U'*') { assign₋symbol(times,out,1); return 0; }
   else if (STATE(mode₋initial) && uc == U'÷') { assign₋symbol(divide,out,1); return 0; } /* ⌥ + '/'. */
   else if (STATE(mode₋initial) && uc == U'/') { assign₋symbol(divide,out,1); return 0; }
   else if (STATE(mode₋initial) && uc == U'+') { assign₋symbol(plus,out,1); return 0; }
   else if (STATE(mode₋initial) && uc == U'-') { assign₋symbol(minus,out,1); return 0; }
   else if (STATE(mode₋initial) && uc == U'=') { assign₋symbol(eql,out,1); return 0; }
   else if (STATE(mode₋initial) && uc == U'<' && uc₊₁ == U'>') { ctxt->tip₋unicode+=1; assign₋symbol(neq,out,2); return 0; }
   else if (STATE(mode₋initial) && uc == U'≠') { assign₋symbol(neq,out,1); return 0; } /* ⌥ + '='. */
   else if (STATE(mode₋initial) && uc == U'<' && uc₊₁ == U'=') { ctxt->tip₋unicode+=1; assign₋symbol(leq,out,2); return 0; }
   else if (STATE(mode₋initial) && uc == U'≤') { assign₋symbol(leq,out,1); return 0; } /* ⌥ + '<'. */
   else if (STATE(mode₋initial) && uc == U'<') { assign₋symbol(lss,out,1); return 0; }
   else if (STATE(mode₋initial) && uc == U'>' && uc₊₁ == U'=') { ctxt->tip₋unicode+=1; assign₋symbol(geq,out,2); return 0; }
   else if (STATE(mode₋initial) && uc == U'≥') { assign₋symbol(geq,out,1); return 0; } /* ⌥ + '>'. */
   else if (STATE(mode₋initial) && uc == U'>') { assign₋symbol(gtr,out,1); return 0; }
   else if (STATE(mode₋initial) && uc == U';') { assign₋symbol(semicolon,out,1); return 0; } /* @<semicolon₋processed@> twice. */
   else if (STATE(mode₋initial) && uc == U':' && uc₊₁ == U'=') { ctxt->tip₋unicode+=1; assign₋symbol(afterward,out,2); return 0; }
   else if (STATE(mode₋initial) && uc == U':') { assign₋symbol(colon,out,1); return 0; }
   else if (STATE(mode₋initial) && uc == U',') { assign₋symbol(comma,out,1); return 0; }
   else if (STATE(mode₋initial) && uc == U'.') { assign₋symbol(period,out,1); print("754 period\n"); return 0; }
   else if (STATE(mode₋initial) && uc == U'@' && uc₊₁ == U'*') { assign₋symbol(sectionsym,out,2); return 0; } /* paragraph, subsection and article. */
   else if (STATE(mode₋initial) && uc == U'@') { assign₋symbol(textsym,out,1); return 0; } /* section, claim, report and changes and subclause and indenture. */
   else if (STATE(mode₋initial) && uc == U'@' && uc₊₁ == U'<') { assign₋symbol(lformalrefpressym,out,2); return 0; } /* exhibit, annex and addendum. */
   else if (STATE(mode₋initial) && uc == U'@' && uc₊₁ == U'>' && uc₊2 == U'=') { assign₋symbol(rformalpresentsym,out,3); return 0; } /* schedule, expenditures, jurisdiction. */
   else if (STATE(mode₋initial) && uc == U'@' && uc₊₁ == U'>') { assign₋symbol(rformalreferencesym,out,2); return 0; }
   else if (STATE(mode₋initial) && uc == U'\x2405') { assign₋symbol(symbol₋for₋enquery,out,1); return 0; } /* first and final 'render' alternatively 'do-not-render' section in editor. */
   else if (STATE(mode₋initial) && uc == U'-' && uc₊₁ == U'-' && uc₊2 == U'<') { assign₋symbol(dowsingsym,out,3); return 0; }
   else if (STATE(mode₋initial) && uc == U'.' && uc₊₁ == U'.' && uc₊2 == U'.') { assign₋symbol(ellipsissym,out,3); return 0; }
   else if (STATE(mode₋initial) && uc == U'…') { assign₋symbol(ellipsissym,out,1); return 0; } /* ⌥ + ';'. */
   else if (STATE(mode₋initial) && uc == U'¬') { assign₋symbol(logical₋not,out,1); return 0; } /* ⌥ + 'l'. ∧∨. */
   else if (STATE(mode₋initial) && uc == U'@' && uc₊₁ == U'@') { assign₋symbol(leftrightread,out,2); return 0; }
   else if ((STATE(mode₋initial) && letter(uc)) || (STATE(mode₋regular) && (letter(uc) || digit(uc)))) {
     if (ctxt->syms₋in₋regular == 2048) { error(1,"identifier and keyword too long"); confess(trouble); }
     ctxt->regular[ctxt->syms₋in₋regular]=uc;
     ctxt->syms₋in₋regular+=1;
     ctxt->state = mode₋regular;
     if (!(U'a' <= uc₊₁ && uc₊₁ <= U'z') && !(U'0' <= uc₊₁ && uc₊₁ <= U'9')) {
       if (!trie₋keyword(ctxt->syms₋in₋regular,ctxt->regular,&sym,&(Ctxt.keys))) { confess(keyword); }
       confess(identifier); }
   }
   else if ((STATE(mode₋initial) || STATE(mode₋integer)) && digit(uc)) {
     ctxt->ongoing *= 10; ctxt->ongoing += uc - U'0';
     ctxt->syms₋in₋number+=1;
     ctxt->state = mode₋integer;
     if (!(U'0' <= uc₊₁ && uc₊₁ <= U'9')) { confess(integer₋constant); }
   } /* else if mode₋fixpoint \also in --<􀥳 lingustics-epi.c>{array buffer the}. */
     /* @= #include "u-arithmetic.cxx" */ /* if (x==0) @<array buffer the@> */
   else {
    confess(trouble);
   }
   goto again;
}

void next₋token(struct language₋context * ctxt)
{ int y;
  if (ctxt->tip₋unicode==0) {
    y = next₋token₋inner(ctxt,&symbol);
    if (y != 0) { error(1,"scanner error: initial trouble"); exit(2); }
  } else {
    symbol₋passed = symbol;
    symbol = retrospect;
  }
  y = next₋token₋inner(ctxt,&retrospect);
  int retrospect₋class = retrospect.class;
  if (retrospect₋class == ident || retrospect₋class == callsym ||
    retrospect₋class == beginsym || retrospect₋class == ifsym) 
  { ctxt->carrier₂=1; } else { ctxt->carrier₂=0; }
  if (y != 0) { error(1,"scanner error: advanced failure"); exit(2); }

#if defined TRACE₋TOKENS
  typedef void (^Print)(char *);
  struct source₋location interval = symbol.gritty.interval;
  Print token = ^(char * rendition) { print("⬚ (⬚-⬚, line ⬚-⬚)\n", 
   ﹟s7(rendition), ﹟d(interval.column₋first), ﹟d(interval.column₋last), 
   ﹟d(interval.lineno₋first), ﹟d(interval.lineno₋last)); };
  switch (symbol.class) {
  case ident: token("identifier"); break;
  case number: token("integer-constant"); break; /* for later 'fixpoint-constant'. */
  case lparen: token("'('"); break;
  case rparen: token("')'"); break;
  case times: token("'*'"); break;
  case divide: token("'/'"); break;
  case plus: token("'+'"); break;
  case minus: token("'-'"); break;
  case neq: token("'<>'"); break;
  case lss: token("'<'"); break;
  case leq: token("'<='"); break;
  case gtr: token("'>'"); break;
  case geq: token("'>='"); break;
  case callsym: token("'call'"); break;
  case ifsym: token("'if'"); break;
  case thensym: token("'then'"); break;
  case elsesym: token("'else'"); break;
  /* case whilesym: print("'while'\n"); break;
  case dosym: print("'do'\n"); break; */
  case branch₋goto₋optsym: token("'branch-goto-opt'"); break;
  case constsym: token("'constant'"); break;
  case comma: token("','"); break;
  case varsym: token("'var'"); break;
  case procsym: token("'transcript'"); break;
  case oddsym: token("'odd'"); break;
  case beginsym: token("'begin'"); break;
  case endsym: token("'end'"); break;
  case eql: token("'='"); break;
  case colon: token("':'"); break;
  case afterward: token("':='"); break;
  case semicolon: token("';'"); break;
  case end₋of₋transmission₋and₋file: token("completion"); break;
  case sectionsym: token("'@*'"); break;
  case textsym: token("'@'"); break;
  case lformalrefpressym: token("'@<'"); break;
  case rformalpresentsym: token("'@>='"); break;
  case rformalreferencesym: token("'@>'"); break;
  case additionssym: token("'additions'"); break;
  case label: token("label"); break;
  case diffusesym: token("diffuse"); break;
  case referencessym: token("references"); break;
  case dowsingsym: token("--<"); break;
  case ellipsissym: token("…"); break;
  case leftrightread: token("@@"); break;
  case insym: token("in"); break;
  default: vfprint("period and non-sorted generalization.\n");
  }
#endif
}

void expression(void);

int match(enum symbol₋class s) { if (symbol₋equal(s)) { next₋token(&Ctxt); return 1; } return 0; }

int expect(enum symbol₋class s) { if (match(s)) return 1; error(2,"expect: unexpected symbol (⬚)", ﹟d((__builtin_int_t)(symbol.class))); return 0; }

int enrich(enum symbol₋class s, enum symbol₋class not₋passed) { if (symbol₋equal(s) && retrospect.class == not₋passed) { next₋token(&Ctxt); return 1; } return 0; }
/*  consumes one symbols when two symbols matches. */

int at₋opt(enum symbol₋class s, void (*action)()) { if (symbol₋equal(s)) { next₋token(&Ctxt); action(); } return 0; }

void valid(int type, enum symbol₋class s, char msg[]) { if (!symbol₋equal(s)) { error(type,msg); } }

int newline₋match(enum symbol₋class s) { if (symbol₋equal(s) || (Ctxt.carrier₁ && Ctxt.carrier₂)) { next₋token(&Ctxt); return 1; } return 0; }

int eltgat(enum symbol₋class s, void (*action)()) { return 0; }

struct dynamic₋bag {
  struct token₋detail X;
  enum symbol₋class T;
  struct dynamic₋bag *l,*r,*compare₋then,*compare₋else,*sequence,*element;
  struct dynamic₋bag *next,*prev;
  struct dynamic₋bag *formal, *detail;
  __uint128_t fineprint; Nonabsolut episod;
  struct dynamic₋bag *art,*var,*pct,*last;
  short memory,count; int leg;
  __builtin_int_t memory₋count;
};

struct dynamic₋bag * summary₋groundfold;

enum { 🅐=1, 🅑, 🅒, 🅔, 🅕, 🅖, 🅗, 🅙, 🅛, 🅝, 🅟, 🅠, 🅡, 🅩, 🅣 };

void process₋compute(struct dynamic₋bag *);
void print₋tree(struct dynamic₋bag * item);
void House(int type, int count, ...);
void assign(struct dynamic₋bag *);
void codegenerate();

struct dynamic₋bag *form,*tree;

#include "µ⃝-code-and-tree.cxx"
/* #include "µ⃝-verse-const.cxx" */
#include "µ⃝-general-register.cxx"
/* #include "µ⃝-semantic-register.cxx"
#include "µ⃝-code-and-arm.cxx" */
#include "µ⃝-code-and-intel.cxx"

void factor(void)
{
   if (match(ident)) { House(🅐,1,symbol₋passed.gritty.store.regularOrIdent); }
   else if (match(number)) { House(🅑,2,symbol₋passed.gritty,1); }
   else if (match(lparen)) { expression(); expect(rparen); }
   else { error(2,"factor: syntax error"); next₋token(&Ctxt); }
} /*  here we start to recognize 'primary' and 'secondary' and not 'ternary'. */

void term(void)
{
   factor(); struct dynamic₋bag * left=form; enum symbol₋class passed; 
   while (symbol₋equal(times) || symbol₋equal(divide)) { 
    passed=symbol.class; next₋token(&Ctxt); factor(); 
    House(🅒,3,left,form,passed); }
} /*  'multiplication' has higher precedence than 'addition'. */

void expression(void)
{ enum symbol₋class passed=plus; struct dynamic₋bag * left;
   if (symbol₋equal(plus) || symbol₋equal(minus)) { 
    passed=symbol.class; next₋token(&Ctxt); } term(); left=form; 
   if (passed==minus) { left=new₋Unary(left,minus); }
   while (symbol₋equal(plus) || symbol₋equal(minus)) { 
    passed=symbol.class; next₋token(&Ctxt); term(); 
    House(🅒,3,left,form,passed); }
} /*  'addition' has not as high precedence as 'multiplication'. */

void condition(void)
{ struct dynamic₋bag * left;
   if (match(oddsym)) { expression(); form=new₋Unary(form,oddsym); }
   else {
     expression(); left=form; 
     if (symbol₋equal(eql) || symbol₋equal(neq) || symbol₋equal(lss) || 
      symbol₋equal(leq) || symbol₋equal(gtr) || symbol₋equal(geq)) 
     { enum symbol₋class passed=symbol.class; 
       next₋token(&Ctxt); expression(); House(🅒,3,left,form,passed);
     } /* else {
       error(2,"condition: invalid operator");
       next₋token(&Ctxt,0);
     } */
   }
}

void actual₋list(void)
{ struct dynamic₋bag * car; short size=0;
   do { car=Alloc(sizeof(struct dynamic₋bag)); if (size!=0) car->next=form; 
    condition(); car->element=form; size+=1; } while(match(comma));
   form=car; form->count=size;
} /* car->next=form when not₋first else ΨΛΩ; */

void opt₋etter(void)
{
   void statement(void);
   statement();
}

/* int faschion₋se₋p()
{
   return !(retrospect.class==ident || retrospect.class==callsym || 
    retrospect.class==beginsym || retrospect.class==ifsym);
} */

void statement(void)
{
   if (match(additionssym)) { Nonabsolut l₋value /* a․𝘬․a 'left'. */; 
    do { expect(ident); l₋value=symbol.gritty.store.regularOrIdent; 
     if (match(eql)) { expect(eql); condition(); House(🅔,2,l₋value,form); }
    } while (match(comma)); /* House() */ }
   else if (match(ident)) { struct dynamic₋bag * meat=ΨΛΩ; 
    Nonabsolut callee₋and₋identifier=symbol.gritty.store.regularOrIdent;
    if (match(lparen)) { if (!symbol₋equal(rparen)) { actual₋list(); meat=form; } expect(rparen); 
     House(🅣,2,meat,callee₋and₋identifier); }
    else if (match(afterward)) { condition(); House(🅕,2,callee₋and₋identifier,form); }
    else { error(2,"neither assignment, call nor introduction"); }
   }
   else if (enrich(callsym,ident)) { expect(ident); House(🅖,1,symbol₋passed.gritty.store.regularOrIdent); }
   else if (match(beginsym)) { do { statement(); } while (newline₋match(semicolon)); expect(endsym); House(🅗,1,form); }
   else if (match(ifsym)) { condition(); expect(thensym); statement(); at₋opt(elsesym,opt₋etter); House(🅙,1,form); }
   /* else if (match(whilesym)) { condition(); expect(dosym); statement(); } */ /* notera att 'undvikande utav vānster' ska vara tre abstraktion. */
   else { error(2,"statement: syntax error"); next₋token(&Ctxt); }
}

void opt₋second(void)
{
   print("secondary-non-negotiated identifier\n");
}

void formal₋list(void)
{ struct dynamic₋bag * car; short size=0;
   do { car=Alloc(sizeof(struct dynamic₋bag)); if (size!=0) car->next=form; expect(ident); 
    expect(/*left₋*/ ident); eltgat(/*right₋*/ident,opt₋second); 
    car->element=form; size+=1;
   } while(match(comma));
 form=car; form->count=size;
}

void opt₋void(void) { }

void block(void)
{ tree=Alloc(sizeof(struct dynamic₋bag)); tree->art=tree->var=tree->pct=ΨΛΩ;
   while (symbol₋equal(constsym) || symbol₋equal(varsym) || symbol₋equal(procsym) || 
    symbol₋equal(schemasym) || symbol₋equal(referencessym))
   {
      switch (symbol.class)
      {
      case constsym: { /* symbol₋equal(constsym) */
        match(constsym); Nonabsolut serpent; /* struct dynamic₋bag * list=ΨΛΩ; */
        do { expect(ident); serpent=symbol₋passed.gritty.store.regularOrIdent; 
          expect(eql); condition(); House(🅛,2,serpent,form); House(🅠,2,tree,form);
        } while (match(comma)); at₋opt(semicolon,opt₋void); break; }
      case varsym: {
        match(varsym); { Nonabsolut argument; /* struct dynamic₋bag * list=ΨΛΩ; */
        do { expect(ident); argument=symbol₋passed.gritty.store.regularOrIdent; 
         if (match(eql)) { expect(eql); condition(); House(🅝,2,argument,form); } 
         else { House(🅝,2,argument,ΨΛΩ); } House(🅡,2,tree,form);
        } while (match(comma)); at₋opt(semicolon,opt₋void); } break; }
      case procsym: {
        match(procsym); { Nonabsolut cipher; struct dynamic₋bag *list=ΨΛΩ,*detail; 
        expect(ident); cipher=symbol₋passed.gritty.store.regularOrIdent; expect(lparen); 
        if (!symbol₋equal(rparen)) { formal₋list(); list=form; } expect(rparen); 
        statement(); detail=form; House(🅟,3,cipher,list,detail); House(🅩,2,tree,form); }
        break; }
      case schemasym: { expect(ident); expect(eql); expect(lparen); break; }
      case referencessym: { expect(referencessym); expect(dowsingsym); break; }
      default: error(2,"unsupported initial keyword"); break;
      }
   }
}

void program(void) { next₋token(&Ctxt); block(); valid(2,end₋of₋transmission₋and₋file,"incorrect signature"); }

int main()
{
   char32̄_t * kvlist[] = { U"constant", U"variable", U"call", U"begin", U"end", 
    U"if", U"then", U"odd", U"transcript", U"else", U"void", U"diffuse", 
    U"references", U"in", U"schema" };
   int symlist[] = { constsym,varsym,callsym,beginsym,endsym,ifsym,thensym,
    oddsym,procsym,elsesym,voidsym,diffusesym,referencessym, insym, schemasym };
   merge₋to₋trie(15,kvlist,symlist,&(Ctxt.keys));
   Ctxt.state=mode₋initial;
   Ctxt.tip₋unicode=0;
   Ctxt.syms₋in₋regular=0;
   Ctxt.ongoing=0; /* Ctxt.syms₋in₋fraction=0; */
   location₋init(&Ctxt.interval);
   symbol₋passed.class = uninit₋symbol;
   identifiers = Alloc(sizeof(struct collection));
   if (init₋regularpool(identifiers)) { return 1; }
   text = Run(U"constant abcd=321+1,dcba=123;\nvariable cdeg,gec,cgb\ntranscript foo() begin\n call window1; call window2;\nif cdeg <> gec then begin cgb:=1+1; abcd() end else begin cgb:=1-1 end end\n transcript fie()\nbegin\n call view\nend\n transcript fue()\nbegin\ncall control end");
   program();
   assign(form);
#if defined TRACE₋SYNTAX
   print₋tree(tree->art);
   print₋tree(tree->var);
   print₋tree(tree->pct);
#endif
   codegenerate(); /* a.k.a 'ferry' and 'tooth'. (code and documentation.) */
#if defined TRACE₋SYMBOL
   __builtin_int_t symbol₋count=collection₋count(identifiers);
   Nonabsolute 𝑓𝑙𝑢𝑐𝑡𝑢𝑎𝑛𝑡 relative=0,previous₋relative=0;
   print("symbols-begin\n");
again:
   if (relative >= symbol₋count) { goto unagain; }
   if (regularpool₋at(identifiers, relative, 
     ^(short symbols₋total, short count₋segments, short symbols₋segment[], char32̄_t * segment[]) {
       print("⬚: ", ﹟d((__builtin_int_t)relative));
       for (int i=0; i<count₋segments; i+=1) print("⬚",﹟S(symbols₋segment[i],segment[i]));
       print(" (⬚ symbols)\n", ﹟d((__builtin_int_t)(symbols₋total)));
       previous₋relative=relative;
       relative+=symbols₋total + 1;
     }
   )) { print("unable to locate symbol '⬚' in pool.\n", ﹟d(relative)); return 1; }
   goto again;
unagain:
   print("symbols-end\n");
#endif
   return 0;
}

/*
 
 program = block end₋of₋transmission₋and₋file
 block = 'const' ident '=' number { ',' ident '=' number } block₋p₋se
   'var' ident { ',' ident } block₋p₋se
   'transcript' ident '(' { formal-list } ')' statement block₋p₋se
   'schema' ident '=' '(' '"' text '"' '-' ... ')'
   'references' '--<' etta '@@' tvāa '>' { 'in' ident } \cr <indent augment>
 statement = ident ':=' expression
   { 'call' } ident
   'begin' statement stmt₋se₋p { statment stmt₋se₋p } 'end'
   'if' condition 'then' statement
   / * 'while' condition 'do' statement * /
 condition = 'odd' statment | expression ('='|'#'|'<'|'<='|'>'|'>=') expression
 expression = ['+'|'-'] term {'+'|'-' term}
 term = factor {'*'|'/' factor}
 factor = ident | number | '(' expression ')'
 
 fashion₋se₋p = semicolon₋alternatively₋termirender₋and₋not(ident,'call','begin','if')
 block₋p₋se = termirender₋and₋not('transcript','var','const')
 
  */
