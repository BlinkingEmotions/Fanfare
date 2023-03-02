/*  􁋹 µ-parse.c | captures infix computation, location, inclusion, 
 presentation-prominent, sequent, schema, indirect-refers, text-folding, 
 references and correctness log. (GET-ON) */

import Twinbeam;

enum symbol₋class { ident=1, number, times, divide, plus, minus, lparen, 
 rparen, eqltwo, neq, lss, leq, gtr, geq, eqlone, callsym, beginsym, endsym, 
 branch₋goto₋optsym, colon, label, afterward, constsym, varsym, procsym, 
 period, comma, semicolon, elsesym, thensym, comparesym, oddsym, 
 additionssym, voidsym, referssym, unicode₋textsym, utf8₋textsym, 
 paragraphsym, start₋indenturesym, referenceindenture₋startsym, 
 end₋referenceindenturesym, subsectionsym, symbol₋for₋enquery, 
 logical₋alternate, logical₋and, logical₋or, logical₋not, 
 schemasym, reelsym, environmentsym, exceptionsym, 
 dowsingsym, ellipsissym, leftrightread, insym, presentsym, 
 serpentsummarysym, settingsym, referencessym, correctionssym, 
 flagsandnotessym, diffusesym, dotifsym, definedsym, dotdefinesym, 
 dotendsym, dotincludesym, systemsym, unicodesym, utf8sym, conceptsym, 
 invariantsym, eot₋and₋file, intrinsicsym, unarbitrated₋symbol, 
 formalparamsym };

enum language₋mode { mode₋initial, mode₋integer, mode₋regular, 
 mode₋fixpoint, mode₋quotes₋text, mode₋collection };

#include "Ω⃝-translate-formal.cxx" /* defines 'source₋location'. */

struct language₋context {
  __builtin_int_t tip₋unicode;
  int carrier₁,carrier₂; /* 'retrospect did purge newline' and 'retrospect₋
   detail and retrospect₋summar differs' and 'summar is always ahead'. */
  /* retrospect is identifier,'call','begin','if','while' and while reading 
   into 'symbol' we passed a (in case of multiple, thelast) 'carriage return' 
   then from lexer insert semicolon. */
  enum language₋mode state;
  char32̄_t regular[2048];
  __builtin_int_t ongoing₋number;
  short zero₋to₋nines[100]; /* a․𝘬․a 'fraction₋and₋digits'. */
  Nonabsolute reference₋quoted;
  short syms₋in₋regular,syms₋in₋number, 
   syms₋in₋fraction,syms₋in₋quotes;
  struct source₋location interval;
  Trie keys;
};

struct token₋detail {
  union {
    Nonabsolute regular;
    Sequenta number;
    __builtin_int_t integer;
  } store;
  int kind;
  struct source₋location interval;
};

struct Unicodes text₋program; struct language₋context Ctxt;

typedef struct Symbol { enum symbol₋class class; struct token₋detail gritty; } Symbol;

Symbol symbol₋passed,symbol,retrospect;
/*  a․𝘬․a 'memory after reading passed'/'ground₋fold', 'current' and 'next'. */

#define STATE(s) (s == ctxt->state)
#define TRACE₋TOKENS
#define TRACE₋SYNTAX
#define TRACE₋SYMBOL

typedef void (^Utf8)(char8₋t *,__builtin_int_t);

void error(int type, char text[], ...)
{ va_prologue(text)
   int write(int,const char *,...);
   int print﹟(Utf8,const char *,__builtin_va_list);
   Utf8 out = ^(char8₋t * u8s, __builtin_int_t bytes) {
    write(1,(const void *)u8s,bytes); };
   print﹟(out,text,__various);
   print(out,".\n");
   va_epilogue
}

struct collection *identifiers,*text₋unicode,*text₋utf8;

void assign₋symbol(enum symbol₋class s, Symbol * sym, short count₋impression)
{ sym->class=s;
   if (count₋impression >= 2) Ctxt.tip₋unicode+=count₋impression-1;
   location₋symbol(&Ctxt.interval,count₋impression,&sym->gritty.interval);
}

void assign₋symbol₋noforward(enum symbol₋class s, Symbol * sym, short count₋impression)
{ sym->class=s;
   location₋symbol(&Ctxt.interval,count₋impression,&sym->gritty.interval);
}

int symbol₋equal(enum symbol₋class s) { return symbol.class==s; }

int copy₋identifier(struct language₋context * ctxt, Symbol * out)
{ __builtin_int_t tetras=ctxt->syms₋in₋regular;
   out->class=ident; location₋symbol(&ctxt->interval,tetras,&out->gritty.interval);
   char32̄_t * ucs=ctxt->regular; Nonabsolute reference;
   if (copy₋append₋onto₋regular(identifiers,tetras,ucs,Alloc,&reference)) return -1;
   if (regularpool₋datum₋text(identifiers,tetras,reference)) return -1;
   /* print("storing datum at tetra no ⬚ (⬚ symbols)\n",﹟d(reference),﹟d(tetras)); */
   out->gritty.kind=1; out->gritty.store.regular=reference;
   return 0;
}

int copy₋number(struct language₋context * ctxt, Symbol * out, int type)
{ out->class=number;
   location₋symbol(&ctxt->interval,ctxt->syms₋in₋number,&out->gritty.interval);
   switch (type)
   {
   case 1:
     out->gritty.store.integer = ctxt->ongoing₋number;
     out->gritty.kind=3;
     break;
   case 2:
     int₋to₋sequent((int64_t)(ctxt->ongoing₋number),&out->gritty.store.number);
     fraction₋to₋sequent(ctxt->syms₋in₋fraction,ctxt->zero₋to₋nines, 
      &out->gritty.store.number);
     out->gritty.kind=2;
     break;
   }
   return 0;
}

Argᴾ ﹟ident(Nonabsolute regular)
{
   return ﹟regularpool(identifiers,regular);
}

int next₋token₋inner(struct language₋context * ctxt, Symbol * out)
{ __builtin_int_t i,symbols=text₋program.tetras; char32̄_t uc,uc₊₁,uc₊2; 
    int lift₋count=0,sym;
   typedef int (^type)(char32̄_t); ctxt->carrier₁=0;
   type digit = ^(char32̄_t uc) { return U'0' <= uc && uc <= U'9'; };
   type letter = ^(char32̄_t uc) { return (U'a' <= uc && uc <= U'z') || 
    (U'A' <= uc && uc <= U'Z') || uc == U'₋' || (U'\x1f600' /*􀈂*/ <= uc && uc <= U'\x1008fa' /*􀣺*/); };
   🧵(identifier,machine₋constant,keyword,trouble,completion,unicode_text) {
   case identifier: copy₋identifier(ctxt,out); ctxt->syms₋in₋regular=0; 
    ctxt->state=mode₋initial; return 0;
   case machine₋constant: copy₋number(ctxt,out,1); ctxt->ongoing₋number=0; 
    ctxt->syms₋in₋number=ctxt->syms₋in₋fraction=0; ctxt->state=mode₋initial;
    return 0;
   case keyword: assign₋symbol₋noforward(sym,out,ctxt->syms₋in₋regular); 
    ctxt->syms₋in₋regular=0; ctxt->state=mode₋initial; return 0;
   case completion: assign₋symbol(eot₋and₋file,out,0); return 0;
   case trouble: print("trouble occurred at ⬚\n",﹟d(ctxt->tip₋unicode)); return -1;
   }
again:
   i=ctxt->tip₋unicode,ctxt->tip₋unicode+=1;
   if (i >= symbols) confess(completion);
   if (i == symbols - 1) lift₋count=2;
   if (i == symbols - 2) lift₋count=1;
   uc = *(text₋program.unicodes + i), 
   uc₊₁ = lift₋count >= 2 ? U' ' : *(text₋program.unicodes + i + 1);
   uc₊2 = lift₋count >= 1 ? U' ' : *(text₋program.unicodes + i + 2);
   if (STATE(mode₋initial) && uc == U'\xa') {
     /* lexer indicates 'semicolon on carriage return' (after reading retrospect) */
     ctxt->carrier₁=1; /* assign₋symbol2(semicolon,out,1); */
     location₋nextline(&ctxt->interval);
   }
#define ELIF₋INIT₋WITH₋ONE(sym) else if (STATE(mode₋initial) && uc == sym)
#define ELIF₋INIT₋WITH₋TWO(sym1,sym2) else if (STATE(mode₋initial) &&        \
 uc == sym1 && uc₊₁ == sym2)
#define ELIF₋INIT₋WITH₋TEE(sym1,sym2,sym3) else if (STATE(mode₋initial) &&   \
 uc == sym1 && uc₊₁ == sym2 && uc₊2 == sym3)
#define RET return 0;
#define EL₋CONFESS else confess(trouble);
   ELIF₋INIT₋WITH₋ONE(U'\xd') { /* do nothing */ }
   ELIF₋INIT₋WITH₋ONE(U' ') location₋nextcolumn(&ctxt->interval);
   ELIF₋INIT₋WITH₋ONE(U'\t') location₋nextcolumn(&ctxt->interval);
   ELIF₋INIT₋WITH₋ONE(U'(') { assign₋symbol(lparen,out,1); RET }
   ELIF₋INIT₋WITH₋ONE(U')') { assign₋symbol(rparen,out,1); RET }
   ELIF₋INIT₋WITH₋ONE(U'*') { assign₋symbol(times,out,1); RET }
   ELIF₋INIT₋WITH₋ONE(U'÷') { assign₋symbol(divide,out,1); RET } /* ⌥ + '/'. */
   ELIF₋INIT₋WITH₋ONE(U'/') { assign₋symbol(divide,out,1); RET }
   ELIF₋INIT₋WITH₋ONE(U'+') { assign₋symbol(plus,out,1); RET }
   ELIF₋INIT₋WITH₋ONE(U'-') { assign₋symbol(minus,out,1); RET }
   ELIF₋INIT₋WITH₋ONE(U'=') { assign₋symbol(eqlone,out,1); RET }
   ELIF₋INIT₋WITH₋TWO(U'=',U'=') { assign₋symbol(eqltwo,out,2); RET }
   ELIF₋INIT₋WITH₋TWO(U'<',U'>') { assign₋symbol(neq,out,2); RET }
   ELIF₋INIT₋WITH₋ONE(U'≠') { assign₋symbol(neq,out,1); RET } /* ⌥ + '='. */
   ELIF₋INIT₋WITH₋TWO(U'<',U'=') { assign₋symbol(leq,out,2); RET }
   ELIF₋INIT₋WITH₋ONE(U'≤') { assign₋symbol(leq,out,1); RET } /* ⌥ + '<'. */
   ELIF₋INIT₋WITH₋ONE(U'<') { assign₋symbol(lss,out,1); RET }
   ELIF₋INIT₋WITH₋TWO(U'>',U'=') { assign₋symbol(geq,out,2); RET }
   ELIF₋INIT₋WITH₋ONE(U'≥') { assign₋symbol(geq,out,1); RET } /* ⌥ + '>'. */
   ELIF₋INIT₋WITH₋ONE(U'>') { assign₋symbol(gtr,out,1); RET }
   ELIF₋INIT₋WITH₋ONE(U'¬') { assign₋symbol(logical₋not,out,1); RET } /* ⌥ + 'l'. ∧∨. */
   ELIF₋INIT₋WITH₋ONE(U';') { assign₋symbol(semicolon,out,1); RET } /* @<semicolon₋processed@> twice. */
   ELIF₋INIT₋WITH₋TWO(U':',U'=') { assign₋symbol(afterward,out,2); RET }
   ELIF₋INIT₋WITH₋ONE(U':') { assign₋symbol(colon,out,1); RET }
   ELIF₋INIT₋WITH₋ONE(U',') { assign₋symbol(comma,out,1); RET }
   ELIF₋INIT₋WITH₋TWO(U'@',U'*') { assign₋symbol(paragraphsym,out,2); RET } /* paragraph, subsection and article. */
   ELIF₋INIT₋WITH₋ONE(U'@') { assign₋symbol(subsectionsym,out,1); RET } /* section, claim, report and changes and subclause. */
   ELIF₋INIT₋WITH₋TEE(U'@',U'>',U'=') { assign₋symbol(start₋indenturesym,out,3); RET } /* schedule, expenditures, jurisdiction. */
   ELIF₋INIT₋WITH₋TWO(U'@',U'<') { assign₋symbol(referenceindenture₋startsym,out,2); RET } /* exhibit, annex and addendum. */
   ELIF₋INIT₋WITH₋TWO(U'@',U'>') { assign₋symbol(end₋referenceindenturesym,out,2); RET }
   ELIF₋INIT₋WITH₋TEE(U'.',U'.',U'.') { assign₋symbol(ellipsissym,out,3); RET }
   ELIF₋INIT₋WITH₋ONE(U'…') { assign₋symbol(ellipsissym,out,1); RET } /* ⌥ + ';'. */
   ELIF₋INIT₋WITH₋TEE(U'-',U'-',U'<') { assign₋symbol(dowsingsym,out,3); RET }
   ELIF₋INIT₋WITH₋TWO(U'@',U'@') { assign₋symbol(leftrightread,out,2); RET }
   /* first and final 'render' alternatively 'do-not-render' and 'requires modification' in text editor. */
   /* else if (STATE(mode₋initial) && uc == U'\x----') { assign₋symbol(symbol₋for₋clipbook₋exclusion₋toggle,out,1) } ⁄* will not include material in clipbook. */
   /* else if (STATE(mode₋initial) && uc == U'\x----') { assign₋symbol(symbol₋for₋prominent₋toggle); } ⁄* display text in bold-face. */
   /* else if (STATE(mode₋initial) && uc == U'\x----') { assign₋symbol(symbol₋for₋guttertext); } ⁄* line-oriented material rendered left to editor (gutter) at hoover. */
   /* else if (STATE(mode₋initial) && UC == U'\x----') { assign₋SYMBOL(symbol₋for₋popovertext); } ⁄* multiple-line material rendered as popover inside editor at hoover. */
   ELIF₋INIT₋WITH₋ONE(U'\x2405') { assign₋symbol(symbol₋for₋enquery,out,1); RET } /* toggle fold/unfold at double-click. */
   /* \later 'text-block rendition-interpretation and painters-knife' (\see 77995 Sat, 18 Feb 2023 05:25). ⌥ + '-' is '–' and ⌥ + shift + '-' is '—'. */
   ELIF₋INIT₋WITH₋ONE(U'.') { assign₋symbol(period,out,1); print("754 period\n"); RET }
   ELIF₋INIT₋WITH₋ONE(U'"') {
     ctxt->reference₋quoted = collection₋count(text₋unicode);
     ctxt->syms₋in₋quotes=0;
     ctxt->state = mode₋quotes₋text;
     location₋nextcolumn(&ctxt->interval);
     /* RET */
   }
   else if (STATE(mode₋quotes₋text)) {
     if (uc == U'"') {
       if (regularpool₋datum₋text(text₋unicode,ctxt->syms₋in₋quotes,ctxt->reference₋quoted)) confess(trouble);
       assign₋symbol₋noforward(unicode₋textsym,out,ctxt->syms₋in₋quotes); ctxt->state = mode₋initial; return 0; }
     else { if (uc == U'\\' && uc₊₁ == U'"') { ctxt->tip₋unicode+=1; uc=U'"'; }
       if (copy₋append₋onto₋regular(text₋unicode,1,&uc,Alloc,&ctxt->reference₋quoted)) confess(trouble);
     }
   }
   else if ((STATE(mode₋initial) && letter(uc)) || (STATE(mode₋regular) && (letter(uc) || digit(uc)))) {
     if (ctxt->syms₋in₋regular == 2048) { error(1,"identifier and keyword too long"); confess(trouble); }
     ctxt->regular[ctxt->syms₋in₋regular]=uc;
     ctxt->syms₋in₋regular+=1;
     ctxt->state = mode₋regular;
     if (!letter(uc₊₁) && !digit(uc₊₁)) {
       if (!trie₋keyword(ctxt->syms₋in₋regular,ctxt->regular,&sym,&(Ctxt.keys))) { confess(keyword); }
       confess(identifier);
     }
   }
   else if ((STATE(mode₋initial) || STATE(mode₋integer)) && digit(uc)) {
     ctxt->ongoing₋number*=10;
     ctxt->ongoing₋number+=(uc - U'0');
     ctxt->syms₋in₋number+=1;
     ctxt->state = mode₋integer;
     if (!digit(uc₊₁)) confess(machine₋constant);
   } /* else if mode₋fixpoint \also in --<􀥳 lingustics-epi.c>{array buffer the}. */
     /* @= #include "u-arithmetic.cxx" */ /* if (x==0) @<array buffer the@> */
   EL₋CONFESS
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
   retrospect₋class == beginsym || retrospect₋class == comparesym) 
  { ctxt->carrier₂=1; } else { ctxt->carrier₂=0; }
  if (y != 0) { error(1,"scanner error: advanced failure"); exit(2); }

#if defined TRACE₋TOKENS
  typedef void (^Print)(char *);
  struct source₋location interval = symbol.gritty.interval;
  Print token = ^(char * rendition) { print("token ⬚. (col. ⬚-⬚, line ⬚-⬚)\n", 
   ﹟s7(rendition), ﹟d(interval.column₋first), ﹟d(interval.column₋last), 
   ﹟d(interval.lineno₋first), ﹟d(interval.lineno₋last)); };
  Print fier = ^(char * rendition) { 
   print("token 'ident' and regular=⬚ is retrieved as '⬚'. (col. ⬚-⬚, line ⬚-⬚)\n", 
   ﹟d(symbol.gritty.store.regular), ﹟ident(symbol.gritty.store.regular), 
   ﹟d(interval.column₋first), ﹟d(interval.column₋last), 
   ﹟d(interval.lineno₋first), ﹟d(interval.lineno₋last)); };
  Print mber = ^(char * rendition) { print("token 'integer-constant' and ⬚. (col. ⬚-⬚, line ⬚-⬚)\n", 
   ﹟d(symbol.gritty.store.integer), ﹟d(interval.column₋first), ﹟d(interval.column₋last), 
   ﹟d(interval.lineno₋first), ﹟d(interval.lineno₋last)); };
  switch (symbol.class) {
  case ident: fier("identifier"); break;
  case number: mber("integer-constant"); break; /* for later 'fixpoint-constant'. */
  case lparen: token("'('"); break;
  case rparen: token("')'"); break;
  case times: token("'*'"); break;
  case divide: token("'/'"); break;
  case plus: token("'+'"); break;
  case minus: token("'-'"); break;
  case eqltwo: token("'==' (two symbols)"); break;
  case eqlone: token("'=' (one symbol)"); break;
  case neq: token("'<>'"); break;
  case lss: token("'<'"); break;
  case leq: token("'<='"); break;
  case gtr: token("'>'"); break;
  case geq: token("'>='"); break;
  case callsym: token("'call'"); break;
  case beginsym: token("'begin'"); break;
  case endsym: token("'end'"); break;
  case branch₋goto₋optsym: token("'branch-goto-opt'"); break;
  case colon: token("':'"); break;
  case label: token("label"); break;
  case afterward: token("':='"); break;
  case constsym: token("'constant'"); break;
  case varsym: token("'var'"); break;
  case procsym: token("'transcript'"); break;
  case period: token("'period'"); break;
  case comma: token("','"); break;
  case semicolon: token("';'"); break;
  case elsesym: token("'else'"); break;
  case comparesym: token("'if'"); break;
  case thensym: token("'then'"); break;
  case oddsym: token("'odd'"); break;
  case additionssym: token("'additions'"); break;
  case voidsym: token("'void'"); break;
  case referssym: token("'refers'"); break;
  case unicode₋textsym: token("\"<process-text>\"");
  case utf8₋textsym: token("\"<storage-text>\""); break;
  case paragraphsym: token("'@*'"); break;
  case start₋indenturesym: token("'@>='"); break;
  case referenceindenture₋startsym: token("'@<'"); break;
  case end₋referenceindenturesym: token("'@>'"); break;
  case subsectionsym: token("'@'"); break;
  case symbol₋for₋enquery: token("'␅'"); break;
  case logical₋alternate: token("'^'"); break;
  case logical₋and: token("'&&'"); break;
  case logical₋or: token("'||'"); break;
  case logical₋not: token("'!'"); break;
  case dowsingsym: token("'--<'"); break;
  case ellipsissym: token("'…'"); break;
  case leftrightread: token("'@@'"); break;
  case insym: token("'in'"); break;
  case schemasym: token("'schema'"); break;
  case reelsym: token("'reel'"); break;
  case environmentsym: token("'environment'"); break;
  case exceptionsym: token("'exception'"); break;
  case serpentsummarysym: token("'serpent₋summary'"); break;
  case settingsym: token("'settings'"); break;
  case referencessym: token("'references'"); break;
  case correctionssym: token("'corrections'"); break;
  case flagsandnotessym: token("'flags₋and₋notes"); break;
  case diffusesym: token("'diffuse'"); break;
  case dotifsym: token("'.IF.'"); break;
  case definedsym: token("'DEFINED'"); break;
  case dotdefinesym: token("'.DEFINE.'"); break;
  case dotendsym: token("'.END.'"); break;
  case dotincludesym: token("'.INCLUDE.'"); break;
  case systemsym: token("'system'"); break;
  case eot₋and₋file: token("completion"); break;
  case unarbitrated₋symbol: token("'𝘶𝘯𝘢𝘳𝘣𝘪𝘵𝘳𝘢𝘵𝘦𝘥'"); break;
  default: vfprint("token '⬚' not recognized.\n", ﹟d(symbol.class));
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

int one₋alternatively₋two(enum symbol₋class s, void (*action)()) { return 0; } /* a․𝘬․a 'eltgat'. */

struct dynamic₋bag₋form {
  struct dynamic₋bag *l,*r,*element;                         /* expression */
  struct dynamic₋bag₋cons *compare₋thenºª, 
   *compare₋elseºª,*sequenceºª,*sequence₋last, 
   *else₋last,*then₋last;                                     /* statement */
  struct dynamic₋bag₋cons *formalºª,*detailsºª, 
   *formal₋last,*details₋last;                               /* definition */
  struct dynamic₋bag₋cons *machineºª,*recollectºª, 
   *machine₋last,*recollect₋last;                     /* code and variable */
  struct dynamic₋bag₋cons *adaptionºª,*surroundºª, 
   *associationºª,*exceptionºª,*adaption₋last, 
   *surround₋last,*association₋last,*exception₋last;            /* serpent */
  struct dynamic₋bag₋cons *persistºª,*persist₋last;             /* setting */
  struct dynamic₋bag₋cons *augmentºª,*differenceºª, 
   *possibly₋twoºª,*possibly₋two₋last, 
   *difference₋last,*augment₋last;                   /* instr.,errata,flag */
  struct dynamic₋bag₋cons *const₋machineºª, 
   *constmachine₋last;                                         /* constant */
};

struct dynamic₋bag {
  struct token₋detail X;
  struct dynamic₋bag₋form form;
  enum symbol₋class T;
  short memory,count; short leg;
  struct dynamic₋bag * preexercise;
  __uint128_t guid₋fineprint;
  __builtin_int_t memory₋count; /* counts 'reads' from virtual memory */
  Nonabsolute episod₋read; /* non-physical register name holding virtual memory reads. */
};

union dynamic₋bag₋continuation { struct dynamic₋bag₋cons * next; 
 __builtin_uint_t possibly₋maybe; };

struct dynamic₋bag₋cons { struct dynamic₋bag *item; union 
 dynamic₋bag₋continuation nxt; };

typedef struct dynamic₋bag₋cons * consref;
typedef struct dynamic₋bag * bagref;

/* int retail(void (^)(refers), address₋of refers first, address₋of 
 refers last) */

int retail(void (^ ᐧ)(struct dynamic₋bag * ᐧ ), struct dynamic₋bag₋cons * ᐧ 
 * ᐧ /* ᐝ */, struct dynamic₋bag₋cons * ᐧ * ᐧ /* ᐝ */);

int retail(void (^section)(struct dynamic₋bag * material), struct 
 dynamic₋bag₋cons ** first, struct dynamic₋bag₋cons ** last)
{ int bag₋size = sizeof(struct dynamic₋bag), 
    cons₋size = sizeof(struct dynamic₋bag₋cons);
   consref cell = (consref)Heap₋alloc(cons₋size);
   bagref item = (bagref)Heap₋alloc(bag₋size);
   struct dynamic₋bag₋cons * memory=0;
   if (cell == 0 || item == 0) return -1;
   section(item);
   if (last) memory = *last;
   cell->item = item;
   if (memory) memory->nxt.next = cell;
   cell->nxt.next = 0;
   *last = cell;
   if (*first == 0) *first=cell;
   return 0;
} /*  a․𝘬․a 'append₋at₋end'. */

struct dynamic₋bag * summary₋groundfold;

typedef void ** (^sequence₋to₋general)(struct dynamic₋bag **);
typedef struct dynamic₋bag ** (^general₋to₋sequence)(void **);
typedef struct dynamic₋bag * (^bag₋to₋general)(void *);
typedef struct ship₋relation { sequence₋to₋general special1; 
  general₋to₋sequence special2; bag₋to₋general special3; 
  int retail₋failure; int sizeof₋bag; } refers;
struct ship₋relation areel = {
 .special1 = ^(struct dynamic₋bag ** input) { return (void **)input; }, 
 .special2 = ^(void ** input) { return (struct dynamic₋bag **)input; }, 
 .special3 = ^(void * input) { return (struct dynamic₋bag *)input; }, 
 .retail₋failure = 0, /* setting accumulated₋retail₋failure */
 .sizeof₋bag = sizeof(struct dynamic₋bag)
};

enum { 🅐=1, 🅑, 🅒, 🅓 };
enum { 🅔🅔, 🅕🅣, 🅖🅕, 🅗🅖, 🅘🅦, 🅙🅗, 🅚🅙};
enum { 🅚, 🅛1, 🅛2, 🅝, 🅡0, 🅡1 };

void Expression(int type, int count, ...);
void Statement(int type, int count, ...);
int constant₋compute(struct dynamic₋bag *);
void general₋register(struct dynamic₋bag *);
void print₋ast(struct dynamic₋bag * tree);
void generate₋code();


Argᴾ ﹟ref(struct dynamic₋bag₋cons * list) ⓣ
{
   return ﹟d((__builtin_uint_t)list);
}

Argᴾ ﹟ref(struct dynamic₋bag * item) ⓣ
{
   return ﹟d((__builtin_uint_t)item);
}

Argᴾ ﹟short(short num)
{
   return ﹟d((__builtin_int_t)num);
}

void print₋datatree(int brk, struct dynamic₋bag * item)
{ int i=0;
again:
   if (i>=brk) goto again;
   print("⬚ at 0x⬚: { l:⬚ r:⬚ elem:⬚ seq:⬚ { ⬚ else ⬚ } { ⬚ with (⬚) } procs:⬚ var:⬚ } and '⬚'\n", 
    ﹟d(item->T),﹟ref(item), 
    ﹟ref(item->form.l),﹟ref(item->form.r), 
    ﹟ref(item->form.element),﹟ref(item->form.sequenceºª), 
    ﹟ref(item->form.compare₋thenºª),﹟ref(item->form.compare₋elseºª), 
    ﹟ref(item->form.detailsºª),﹟ref(item->form.formalºª), 
    ﹟ref(item->form.machineºª),﹟ref(item->form.recollectºª), 
    ﹟ident(item->X.store.regular));
   i+=1; goto again;
unagain:
   return;
}

struct dynamic₋bag *bu₋fragment,*td₋tree;

#include "µ⃝-code-and-tree.cxx"
#include "µ⃝-verse-const.cxx"
#include "µ⃝-general-register.cxx"
/* #include "µ⃝-semantic-register.cxx"
#include "µ⃝-code-and-arm.cxx" */
#include "µ⃝-code-and-intel.cxx"
#include "µ⃝-syntax-pretty.cxx"

void factor(void)
{
   if (match(ident)) { Expression(🅐,1,symbol₋passed.gritty.store.regular); }
   else if (match(number)) { Expression(🅑,2,symbol₋passed.gritty,1); }
   else if (match(lparen)) { expression(); expect(rparen); }
   else { error(2,"factor: syntax error"); next₋token(&Ctxt); }
} /*  here we start to recognize 'primary' and 'secondary' and not 'ternary'. */

void term(void)
{
   factor(); bagref left=bu₋fragment; enum symbol₋class op; 
   while (symbol₋equal(times) || symbol₋equal(divide)) { 
    op=symbol.class; next₋token(&Ctxt); factor(); 
    Expression(🅒,3,left,bu₋fragment,op); }
} /*  'multiplication' has higher precedence than 'addition'. */

void expression(void)
{ enum symbol₋class op=plus; bagref left;
   if (symbol₋equal(plus) || symbol₋equal(minus)) { 
    op=symbol.class; next₋token(&Ctxt); } term(); left=bu₋fragment; 
   if (op==minus) { left=new₋Unary(left,minus); }
   while (symbol₋equal(plus) || symbol₋equal(minus)) { 
    op=symbol.class; next₋token(&Ctxt); term(); 
    Expression(🅒,3,left,bu₋fragment,op); }
} /*  'addition' has not as high precedence as 'multiplication'. */

void condition(void)
{
   if (match(oddsym)) { expression(); bu₋fragment=new₋Unary(bu₋fragment,oddsym); }
   else {
     expression(); bagref left=bu₋fragment; 
     if (symbol₋equal(eqltwo) || symbol₋equal(neq) || symbol₋equal(lss) || 
      symbol₋equal(leq) || symbol₋equal(gtr) || symbol₋equal(geq)) 
     { enum symbol₋class op=symbol.class; 
       next₋token(&Ctxt); expression(); Expression(🅒,3,left,bu₋fragment,op);
     } /* else {
       error(2,"condition: invalid operator");
       next₋token(&Ctxt,0);
     } */
   }
}

void function₋actual₋list(void)
{ consref params=0,params₋last=0;
   do { condition();
     if (retail(^(struct dynamic₋bag * material) {
       *material = *bu₋fragment;
     },&params,&params₋last)) { Pult(areel.retail₋failure); return; }
   } while(match(comma));
   Expression(🅓,2,params,params₋last);
} /* car->next=fragment when not₋first else ΨΛΩ; */

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
   if (match(additionssym)) { Nonabsolute left; /* a․𝘬․a 'l-value'. */ 
    do { expect(ident); left=symbol₋passed.gritty.store.regular; 
     if (match(eqlone)) { expect(eqlone); condition(); Statement(🅔🅔,2,left,bu₋fragment); }
    } while (match(comma)); }
   else if (match(ident)) {
    Nonabsolute token=symbol₋passed.gritty.store.regular;
    if (match(lparen)) {
     if (!symbol₋equal(rparen)) { function₋actual₋list(); } expect(rparen); 
     Statement(🅕🅣,2,token,bu₋fragment); }
    else if (match(afterward)) { condition(); Statement(🅖🅕,2,token,bu₋fragment); }
    else { error(2,"neither assignment, call nor variable introduction"); }
   }
   else if (enrich(callsym,ident)) { expect(ident); 
    Statement(🅗🅖,1,symbol₋passed.gritty.store.regular); }
   else if (match(beginsym)) { do { statement(); Statement(🅘🅦,1,bu₋fragment); } 
    while (newline₋match(semicolon)); expect(endsym); Statement(🅙🅗,1,bu₋fragment); }
   else if (match(comparesym)) { bagref select1,select2=0,cond=0;
     condition(); cond=bu₋fragment; expect(thensym); statement(); 
     select1=bu₋fragment; at₋opt(elsesym,opt₋etter); select2=bu₋fragment; 
     Statement(🅚🅙,3,cond,select1,select2); }
   /* else if (match(whilesym)) { condition(); expect(dosym); statement(); } */
   else { error(2,"statement: syntax error"); next₋token(&Ctxt); }
}

void opt₋second(void)
{
   print("secondary-non-negotiated identifier\n");
}

void function₋formal₋list(void)
{ consref params=0,params₋last=0; Nonabsolute type,name1,name2=-1;
   do { match(ident); type=symbol₋passed.gritty.store.regular;
      expect(/*left₋*/ ident); name1=symbol₋passed.gritty.store.regular;
     if (symbol₋equal(ident)) { match(ident); name2=symbol₋passed.gritty.store.regular; }
     if (retail(^(struct dynamic₋bag * item) {
       item->T = formalparamsym;
       item->form.element = new₋Identifier(type);
       item->form.l = new₋Identifier(name1);
       item->form.r = new₋Identifier(name2);
     },&params,&params₋last)) { Pult(areel.retail₋failure); return; }
   } while(match(comma));
   /* type element, l and r is optional argument-label and inner identifiers. */
   td₋tree->form.machine₋last->item->form.formalºª = params;
   td₋tree->form.machine₋last->item->form.formal₋last = params₋last;
}

void opt₋void(void) { }

void block(void)
{
   while (symbol₋equal(constsym) || symbol₋equal(varsym) || 
    symbol₋equal(procsym))
   {
      switch (symbol.class)
      {
      case constsym: {
        match(constsym); Nonabsolute name;
        do { expect(ident); name=symbol₋passed.gritty.store.regular; 
          expect(eqlone); condition(); Section(🅛1,2,name,bu₋fragment); 
          Section(🅛2,3,bu₋fragment,&td₋tree->form.const₋machineºª,&td₋tree->form.constmachine₋last);
        } while (match(comma)); at₋opt(semicolon,opt₋void); break; }
      case varsym: {
        match(varsym); { Nonabsolute name;
        do { expect(ident); name=symbol₋passed.gritty.store.regular; 
         if (match(eqlone)) { expect(eqlone); condition(); 
         Section(🅛1,2,name,bu₋fragment); } else { Section(🅝,1,name); }
         Section(🅛2,3,bu₋fragment,&td₋tree->form.recollectºª,&td₋tree->form.recollect₋last);
        } while (match(comma)); at₋opt(semicolon,opt₋void); } break; }
      case procsym: {
        match(procsym); { Nonabsolute name; 
        expect(ident); name=symbol₋passed.gritty.store.regular; 
        Section(🅡0,1,name); expect(lparen); 
        if (!symbol₋equal(rparen)) { function₋formal₋list(); } expect(rparen); 
        statement(); Section(🅡1,1,bu₋fragment); }
        break; }
      default: break;
      }
   }
   if (symbol₋equal(serpentsummarysym))
   {
     switch (symbol.class)
     {
     case schemasym: { Nonabsolute name; int cols=-1,ccnt=0;
       match(schemasym); expect(ident); 
       name = symbol₋passed.gritty.store.regular;
       expect(eqlone); expect(lparen);
       while (symbol₋equal(unicode₋textsym)) {
         expect(unicode₋textsym); expect(minus); 
         do { expect(unicode₋textsym); ccnt+=1; } 
         while(!(symbol₋equal(rparen) || retrospect.class == unicode₋textsym));
         ccnt=0;
       }
       expect(rparen); 
       Serpent₋schema(name,bu₋fragment,cols); break; }
     case reelsym: { match(reelsym); expect(eqlone); break; }
     case environmentsym: {
       Nonabsolute coroutine,interrupt;
       match(environmentsym); expect(ident); 
       interrupt = symbol₋passed.gritty.store.regular;
       expect(eqlone); expect(ident);
       coroutine = symbol₋passed.gritty.store.regular;
       break; }
     case exceptionsym: match(exceptionsym); expect(eqlone); expect(lparen); 
       expect(rparen); break;
     default: error(2,"unsupported initial serpent-summary keyword"); break;
     }
   }
   if (symbol₋equal(settingsym))
   {
     match(settingsym);
   }
   while (symbol₋equal(correctionssym) || symbol₋equal(referencessym)) {
     switch (symbol.class)
     {
     case correctionssym: match(correctionssym); break;
     case referencessym: match(referencessym); expect(dowsingsym); break;
     default: break;
     }
   }
   if (symbol₋equal(flagsandnotessym))
   {
     match(flagsandnotessym);
   }
}

void program(void)
{
   next₋token(&Ctxt); block(); valid(2,eot₋and₋file,"incorrect signature");
}

/* -mindful call|couroutine|branch|overflow|store|load|gate */
/* -skip call multiply */

int main(int argc, char * argv[])
{
   char32̄_t * keywords[] = { U"constant", U"variable", U"call", U"begin", 
    U"end", U"if", U"then", U"odd", U"transcript", U"else", U"void", 
    U"branch", U"in", U"present", U"refers", U"additions", U"U8", U"UC", 
    U"schema", U"reel", U"environment", U"exception", 
    U"serpent₋summary", U"settings", U"references", U"corrections", 
    U"flags₋and₋notes", U"diffuse", U".IF.", U"DEFINED", U".DEFINE.", 
    U".END.", U".INCLUDE.", U"system", U"unicode", U"utf₋8", U"concept",
    U"invariant" };
   int symbols[] = { constsym,varsym,callsym,beginsym,endsym,comparesym, 
    thensym,oddsym,procsym,elsesym,voidsym,branch₋goto₋optsym,insym, 
    presentsym,referssym,additionssym,utf8₋textsym,unicode₋textsym, 
    schemasym,reelsym,environmentsym,exceptionsym, 
    serpentsummarysym,settingsym,referencessym,correctionssym, 
    flagsandnotessym,diffusesym,dotifsym,definedsym,dotdefinesym, 
    dotendsym,dotincludesym,systemsym,unicodesym,utf8sym,conceptsym,
    invariantsym };
   merge₋to₋trie(36,keywords,symbols,&Ctxt.keys);
   Ctxt.state=mode₋initial;
   Ctxt.tip₋unicode=0;
   Ctxt.syms₋in₋regular=0;
   Ctxt.syms₋in₋number=0;
   Ctxt.syms₋in₋fraction=0;
   /* the integer 'syms₋in₋quotes' set when '"' is recognized. */
   Ctxt.ongoing₋number=0;
   location₋init(&Ctxt.interval);
   symbol₋passed.class = unarbitrated₋symbol;
   identifiers = Alloc(sizeof(struct collection));
   if (init₋regularpool(identifiers)) return 1;
   text₋unicode = Alloc(sizeof(struct collection));
   if (init₋regularpool(text₋unicode)) return 1;
   text₋utf8 = Alloc(sizeof(struct collection));
   if (init₋regularpool(text₋utf8)) return 1;
   td₋tree = new₋Unit();
   text₋program = Run(
    U"transcript hello(binary16 arg1, binary32 arg2) begin call control end\n\n");
/*
U"constant abcd=321+1,dcba=123;\n"
 "variable cdeg,gec,cgb\n"
 "transcript foo() begin\n"
 "  call window1; call window2;\n"
 "  if cdeg <> gec then begin cgb:=1+1; abcd() end "
 "  else begin cgb:=1-1 end end\n"
 "transcript fie( int )\nbegin\n call view\nend\n"
 "transcript fue()\nbegin\n call control\nend\n\n");*/
   program();
#if defined TRACE₋SYNTAX
   print₋ast(td₋tree);
#endif
   if (constant₋compute(td₋tree)) return 3;
   general₋register(td₋tree);
#if defined TRACE₋SYMBOL
   __builtin_int_t symbol₋count=collection₋count(identifiers);
   Nonabsolute 𝑓𝑙𝑢𝑐𝑡𝑢𝑎𝑛𝑡 relative=0,previous₋relative=0;
   print("*** symbols-begin ***\n");
again:
   if (relative >= symbol₋count) goto unagain;
   if (regularpool₋at(identifiers, relative, 
     ^(short symbols₋total, short count₋segments, short symbols₋segment[], char32̄_t * segment[]) {
       print("⬚: ", ﹟d((__builtin_int_t)relative));
       for (int i=0; i<count₋segments; i+=1) print("⬚",﹟S(symbols₋segment[i],segment[i]));
       print(" (⬚ symbols)\n", ﹟d((__builtin_int_t)(symbols₋total)));
       previous₋relative=relative;
       relative+=(symbols₋total + 1);
     }
   )) { print("unable to locate symbol '⬚' in pool.\n", ﹟d(relative)); return 4; }
   goto again;
unagain:
   print("*** symbols-end ***\n");
#endif
   codegenerate();
   print("*** pult is ***\n");
   print("⬚ retail₋failure\n", ﹟d(areel.retail₋failure));
   print("*** end-pult ***\n");
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
  text-and-symbol = U8"" and U8'' and UC"" and UC''
 condition = 'odd' statment | expression ('=='|'#'|'<'|'<='|'>'|'>=') expression
  \also U'0' <= uc <= U'9'.
 expression = ['+'|'-'] term {'+'|'-' term}
 term = factor {'*'|'/' factor}
 factor = ident | number | '(' expression ')'
 
 fashion₋se₋p = semicolon₋alternatively₋termirender₋and₋not(ident,'call','begin','if')
 block₋p₋se = termirender₋and₋not('transcript','var','const')
 
 clang -g -fmodules-ts -fimplicit-modules -fmodule-map-file=🚦.modules      \
 '􁋹 µ-parse.c' ../Apps/Source/Releases/libTwinbeam-x86_64.a                  \
  ../Apps/Additions/monolith-sequent.c 
 
 */

