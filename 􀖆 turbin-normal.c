/*  turbin-normal a․𝘬․a Plan-9 | modellers' traveller companion. (CORP. EDITION.) */

import Twinbeam; /*  he is sitting in a box 𝘦․𝘨 T-FOR-D and De-la-v-all. */

/* ./retro-mac.sh turbin-āttika to compile. */

typedef int64_t     Integer;
typedef Sequenta    Real; /* ⬷ here we attempt base two and ten hardware 
 Ieee754 and software arithmetics. */
typedef struct structa Regularset;

/* ╳╳ northern 'således' tran-sact-ions and veri-fi-c-at-es ╳╳ */

typedef struct {
 enum { REGULAR, MONETARY, FUNCTION_KEYWORD, INSTANT, 
  BOOKKEEP_KEYWORD, DEBET_KEYWORD, CREDIT_KEYWORD, COMMENT_KEYWORD, WITH_KEYWORD, 
  PRINT_KEYWORD, BREAK_KEYWORD, SET_KEYWORD, VAR_KEYWORD, RETURN_KEYWORD, 
  DO_KEYWORD, IF_KEYWORD, THEN_KEYWORD, ELSE_KEYWORD, END_KEYWORD, BEFORE_KEYWORD, 
  PLUS_SYMBOL, MINUS_SYMBOL, MULT_SYMBOL, DIV_SYMBOL, AND_SYMBOLS, OR_SYMBOLS, 
  NOT_SYMBOL, XOR_SYMBOL, ENTITY_KEYWORD, ACCOUNT_KEYWORD, 
  TABLE_KEYWORD, DISPLAY_KEYWORD, FROM_KEYWORD, 
  CREATE_KEYWORD, NAMED_KEYWORD, TRADING_KEYWORD, IN_KEYWORD, RESIDENT_KEYWORD, 
  WITH_KEYWORD, IS_KEYWORD, TO_KEYWORD, SCHEDULE_KEYWORD, STARTING_KEYWORD, 
  OCCURING_KEYWORD, ENDING_KEYWORD, DROP₋SCHEDULE_KEYWORD, EXCHANGE_KEYWORD, 
  RATE_KEYWORD, CURRENCY_KEYWORD, 
  L₋BRACKET, R₋BRACKET, QUOTED₋TEXT, END₋OF₋TRANSMISSION };
 typedef enum { initial, singline₋comment, multiline₋comment, 
  quoted₋text } mode=initial;
} Ɀ₋AST; /* ⬷ a․𝘬․a bokföringssed, custom and recollect. */

/* ╳╳ computation two tables: 'annual return' and 'profit and loss' ╳╳ */

typedef struct {
  enum { POP_KEYWORD, SWAP_KEYWORD, DUP_KEYWORD, 
   PLUS_KEYWORD, MINUS_KEYWORD, MULT_KEYWORD, DIV_KEYWORD, 
   REPORT_KEYWORD, BOLD_KEYWORD, REGULAR, QUOTED₋TEXT, 
   END₋OF₋TRANSMISSION, report, opt₋bold };
  typedef enum { initial, singleline₋comment, multiline₋comment, 
   quoted₋text } mode=initial;
} ᵀAST; /*  a․𝘬․a 'table₋parser' and terminals-and-nonterminals․ */

typedef struct {
  __builtin_int_t linenumber₋first=1,linenumber₋last=1, 
   column₋first=1,column₋last=1,tip₋unicode;
  
  fifo order₋and₋memory; Structa symbol₋stack;
  
} language₋context; /*  a․𝘬․a 'verificate₋parser' and token-i-sa-tio-n. */

Regularset languageᵀ,languageⱿ;

struct { __builtin_uint_t diagnosis₋count; } error₋panel;

inexorable 
int context₋init(
  __builtin_int_t program₋bytes, 
  struct language₋context * const ctxt
)
{
   ctx->linenumber₋first=1, ctx->linenumber₋last=1, ctx->idx₋u8c=0, 
     ctx->negative=0;
   __builtin_int_t maxu8bytes=BUILTIN₋INT₋MAX;
   ctx->sourcepath = Retranscript(u8txtpath,maxu8bytes);
   ctx->mode = initial;
   return 0;
}

inexorable int scan₋sequence₋of₋evidence₋and₋absorb( /* it. verificare. */
  __builtin_int_t symbols, char32̄_t text[])
{
   
}

inexorable int scan₋sequence₋of₋evidence₋and₋absorb(
  __builtin_int_t bytes, char8₋t * setyb)
{
   
}

inexorable int deinit₋context(struct language₋context * ctxt) { Fallow(ctxt); }

inexorable int
scan₋sequence₋of₋evidence₋and₋absorb(
  __builtin_int_t bytes, char8₋t text[], 
  enum Business₋token₋symbol * kind, 
  union Business₋symbol₋token₋detail * detail, 
  struct Businessrule₋scanner₋ctxt * b₋ctxt, 
  void (*identifier)(int symbols, char32̄_t * start)
)
{
   uchar c,f,e,d; char32̄_t unicode; __builtin_int_t i=s₋ctxt->idx₋u8c;
   
   🧵(utf8₋error,pool₋error,scanner₋error,conversion₋error,
  unterminated₋quote,unknown₋keyword,wrong₋number₋of₋argument,
  token,truncated₋token₋utf8) {
    case utf8₋error: return -1;
    case pool₋error: return -2;
    case unterminated₋quote: return -3;
    case unknown₋keyword: return -4;
    case wrong₋number₋of₋argument: return -5;
    case token: identifier(b₋ctxt->symbols₋in₋regular, b₋ctxt->regular); return 0;
    case truncated₋token₋utf8: return 0;
   }
   
   typedef int (^type)(char32̄_t c);
   typedef void (^action)(void);
   
   type digit = ^(char32̄_t c) { return U'0' <= c && c <= U'9'; };
   type derender₋newline = ^(char32̄_t c) { return c == U'\xa'; }; /* de- = completely = fullgångna. */
   type newline = ^(char32̄_t c) { return derender₋newline(c) || c == U'\xd'; };
   type whitespace = ^(char32̄_t c) { return c == U' ' || U'\t' == c || newline(c); };
   type regular = ^(char32̄_t c) { return (U'a' <= c && c <= U'z') || (U'A' <= c && c <= U'Z') || digit(c); };
   type period = ^(char32̄_t c) { return c == U'.'; };
   
   typedef int (^History)();
   typedef int (^Nondeterminist)(Stringpool, char32̄_t);
   typedef int (*History₋params)(char32̄_t unicode);
   typedef History₋params Stringpool;
   
   History extrapolat = ^(Stringpool follow₋current, char32̄_t unicode) { return follow₋current(unicode); };
   Nondeterminist retrospect = ^(void (*close₋current)(void)) { close₋current(); return 0; };
   
   action token₋sep = ^{ s₋ctxt->mode = initial; };
   
   action found₋beziercurve₋start = ^{
    *kind = start₋line;
    detail->ref=(void *)NULL;
    confess(token); };
   action found₋beziercurve₋add = ^{
    *kind = add₋line;
    detail->ref=(void *)NULL;
    confess(token); };
   action found₋beziercurve₋end = ^{
    *kind = end₋line;
    detail->ref=(void *)NULL;
    confess(token); };
   action found₋text = ^{ };
   
again:
   
   while (i<symbols) {
     c = text[i];
     if (248 <= c || (128 <= c && c < 192)) { confess(utf8₋error); }
     else if (c >= 128) {
       __builtin_int_t onesUntilZero = __builtin_clzll(~((uint64_t)c<<56));
       __builtin_int_t followers = onesUntilZero - 1;
       switch (followers) {
       case 3: if (i+3 >= bytes) { confess(truncated₋token₋utf8); }
         f = program₋u8s[i+3]; s₋ctxt->idx₋u8c+=4;
       case 2: if (i+2 >= bytes) { confess(truncated₋token₋utf8); }
         e = program₋u8s[i+2]; s₋ctxt->idx₋u8c+=3;
       case 1: if (i+1 >= bytes) { confess(truncated₋token₋utf8); }
         d = program₋u8s[i+1]; s₋ctxt->idx₋u8c+=2;
       default: confess(utf8₋error);
       }
       if (followers == 1) { unicode = ((0b11111 & c) << 6) | (0x3F & d); }
       if (followers == 2) { unicode = ((0b1111 & c) << 12) | ((0x3F & d) << 6) | 
        (0x3F & e); }
       if (followers == 3) { unicode = ((0b111 & c) << 18) | ((0x3F & d) << 12) | 
        ((0x3F & e) << 6) | (0x3F & f); }
     } else { unicode = (char32̄_t)c; s₋ctxt->idx₋u8c+=1; }
   }
   
   /* ⤐ Unicode decoded and available ⤐ */
   
   if (derender₋newline(unicode)) { s₋ctxt->lineno₋first+=1, s₋ctxt->lineno₋last+=1; token₋sep(); }
   else if (newline(unicode)) { token₋sep(); }
   else if (whitespace(unicode)) { token₋sep(); }
   else if (s₋ctxt->mode == initial && unicode == U'-') { s₋ctxt->negative = !s₋ctxt->negative; }
   else if (s₋ctxt->mode == initial && digit(unicode)) {
     Feeder feeder = ^(unsigned short * l₋to₋r₋digit) {
       return complete; };
     if (CastTextToNumeric(feeder,&s₋ctxt->ongoing)) { confess(conversion₋error); }
   }
   else if (s₋ctxt->mode == initial && period(unicode)) {
     switch (s₋ctxt->mode) {
     case digits: s₋ctxt->mode = digitAltsignAltPeriod; break;
     case digitsperiod: break;
     default: ;
     }
   }
   else if (s₋ctxt->mode == initial && unicode == U',') {
     *kind = comma₋0x2c;
     detail->ref=(void *)NULL;
     confess(token); token₋sep(); }
   else if (s₋ctxt->mode == initial && unicode == U'␜') { s₋ctxt->mode = unicodes; } /* ⬷ a․𝘬․a 'e2 90 9c' and U+241c. */
   else if (s₋ctxt->mode == unicodes && unicode != U'␜') {
     if (assistant₂(record,unicode)) { confess(pool₋error); }
   }
   else if (s₋ctxt->mode == unicodes && unicode == U'␜') { assistant₁(); token₋sep(); }
   else { confess(scanner₋error); }
   
   goto again;
}

inexorable int Rendertable(Chronology::Instant when, History& history, Unicodes program)
{
   Context₂ 𝑓𝑙𝑢𝑐𝑡𝑢𝑎𝑛𝑡 ctx; __builtin_int_t 𝑓𝑙𝑢𝑐𝑡𝑢𝑎𝑛𝑡 beam=0;
   
   if (Setup₋filelength₋enough(ctx.puddle, 4*program.tetras)) { return -1; }
   
   🧵(unterminated₋quote, non₋recognized₋escape, general₋error, 
  requires₋two₋argument, requires₋an₋argument, abstract₋machine₋failed, 
  parse₋error, parser₋exhausted) {
   case nonterminated₋quote: return -1;
   case non₋recognized₋escape: return -2;
   case general₋error: return -3;
   /* ⬷ regular; established context ⤐ */
   case requires₋two₋argument: return -4;
   case requires₋an₋argument: return -5;
   case abstract₋machine₋failed: return -7;
   case parse₋error: return -8;
   case parser₋exhausted: return -9;
   } /* ⬷ exits from inside a block using 'confess'. */
   
   /* character classes ⤐ */
   
   auto digit = ^(char32̄_t c) { return U'0' <= c && c <= U'9'; };
   auto counting₋newline = ^(char32̄_t c) { return c == U'\xa'; };
   auto newline = ^(char32̄_t c) { return counting₋newline(c) || c == U'\xd'; };
   auto whitespace = ^(char32̄_t c) { return c == U' ' || U'\t' == c || newline(c); };
   auto misc₋symbols = ^(char32̄_t c) { return U'😐' == c || c == U'_'; }; /* ⬷ see clang c++ scanner for one definition. */
   auto first₋ident₋char = ^(char32̄_t c) { return (U'a' <= c && c <= U'z') || (U'A' <= c && c <= U'Z') || misc₋symbols(c); };
   auto rest₋ident₋char = ^(char32̄_t c) { return first₋ident₋char(c) || digit(c); };
   
   /* connect to kiddle qstring alt. identifier a․𝘬․a 'regular token' ⤐ */
   
   auto append₋qstring₋alt₋ident₋unicode = ^(char32̄_t c) { if (ctx.puddle.copy₋append₋text(1, { c })) { PULT💡(panel.kiddle₋error); } } };
   auto regular-token-ended = ^{ /* ✃✃✃ */ if (ctx.puddle.datum₋text(regulartetras)) { PULT💡(panel.kiddle₋error); } /* ✁✁✁ */ };
   auto regular₋token-started = ^{ /* ✁✁✁ */ regulartetras=0; /* ✃✃✃ */ };
   
   /* comments, quoted strings and escape characters ⤐ */
   
   auto found₋start₋c₋comment = ^{ ctx.mode = ParserContext₂::mode::c₋comment; };
   auto found₋end₋c₋comment = ^{ ctx.mode = ParserContext₂::mode::initial; }; /* ⬷ when in 'ctx.mode = c₋comment'. */
   auto found₋newline = ^{ ++(ctx.lineno); };
   auto found₋cpp₋comment = ^{ ++(ctx.lineno); }; /* ⬷ until 'newline'. */
   auto found₋single₋quote = ^{ ctx.inside₋quotes=1; ctx.mode = ParserContext₂::mode::qstring; regular₋started(); };
   auto found₋single₋quote￨qstring = ^{ ctx.mode = ParserContext₂::mode::initial; ctx.inside₋quotes=0; regular₋ended(); };
   auto found₋sq₋escape￨qstring = ^{ confess(non₋recognized₋escape); };
   auto found₋symbol￨qstring = ^(char32_t uc) { append₋qstring₋unicode(uc); };
   auto found₋newline￨qstring = ^{ confess(nonterminated₋quote); };
   
   /* quotes, identifiers and keywords ⤐ */
   
   auto found₋pop = ^{ return ᵀAST::POP_KEYWORD; };
   auto found₋swap = ^{ return ᵀAST::SWAP_KEYWORD; };
   auto found₋dup = ^{ return ᵀAST::DUP_KEYWORD; };
   auto found₋operator₋plus = ^{ return ᵀAST::PLUS_KEYWORD; };
   auto found₋operator₋minus = ^{ return ᵀAST::MINUS_KEYWORD; };
   auto found₋operator₋mult = ^{ return ᵀAST::MULT_KEYWORD; };
   auto found₋operator₋div = ^{ return ᵀAST::DIV_KEYWORD; };
   auto found₋report = ^{ return ᵀAST::REPORT_KEYWORD; };
   auto found₋bold = ^{ return ᵀAST::BOLD_KEYWORD; };
   auto found₋ident = ^{ };
   auto found₋string = ^{ };
   
   /* regular language recollection and state ⤐ */
   
   𝑓𝑙𝑢𝑐𝑡𝑢𝑎𝑛𝑡 enum class found /* ⬷ a․𝘬․a 'state'. */ { ed₋start, ₍div₎, 
    ₍divmul₎, found::₍esc￨c₋comment₎, ₍mul￨c₋comment₎, 
    ₍divdiv₎, ₍sq₎, ₍sq￨qstr₎, ₍esc￨qstr₎, ₍esc₋sq￨qstr₎, 
    initialregular, suffixregular, error 
   } state = found::ed₋start; 
   
   /* match and retrieve longest possible token until token 
     ended alternatively a keyword is found ⤐ \*/
   
   auto lexer₋peek₋one₋symbol = ^(__builtin_int_t &optbeam) { char32̄_t c; 
again:
     if (beam >= program.tetras) { goto unagain; }
     c = *(beam + program.unicodes);
     if (c == 0x0000) { goto unagain; } /*  c𝘧․ END₋OF₋TRANSMISSION. */
     switch (state) {
     case found::ed₋start: if (counting₋newline(c)) { found₋newline(); }
       else if (whitespace(c)) { /* do nothing */ }
       else if (c == U'+') { return found₋operator₋plus(); }
       else if (c == U'-') { return found₋operator₋minus(); }
       else if (c == U'*') { return found₋operator₋mult(); }
       else if (c == U'/') { state = found::₍div₎; }
       else if (c == U'\'') { state = found::₍sq₎; }
       else if (first₋ident₋char(c)) { /* state = found::ed₋start; */ }
       break;
     case found::₍div₎:
       if (c == U'*') { found₋start₋c₋comment(); state = found::₍divmul₎; }
       else if (c == U'/') { found₋cpp₋comment(); }
       else { state = found::ed₋start; return found₋operator₋div(); }
       break;
     case found::₍divmul₎:
       if (c == U'*') { state = found::₍mul￨c₋comment₎; }
       else if (counting₋newline(c)) { found₋newline(); }
       /* else if (c == U'@') { state = found::₍esc￨c₋comment₎; } */
       else { /* do nothing */ }
       break;
     /* case found::₍esc￨c₋comment₎: break; */
     case found::₍mul￨c₋comment₎:
       if (c == U'/') { found₋end₋c₋comment(); state = found::ed₋start; }
       break;
     case found::₍divdiv₎:
       if (counting₋newline(c)) { found₋newline(); state = found::ed₋start; }
       else if (whitespace(c)) { /* do nothing */ }
       break;
     case found::initialregular: break;
     case found::suffixregular: break;
     case found::error: default: confess(general₋error);
     }
unagain:
     return ᵀAST::END₋OF₋TRANSMISSION;
   }; /*  a․𝘬․a 'crypto₋lex' (req. 256-bit leafs to symbol tree). Reads 'program' 
 and refreshes 'beam'. Requires 'still-token(char32_t)' and 'ws ends token'. Often 
 expressed as ''. */
   
   union Entity { __builtin_uint_t bits; float ℝ; } topAndLeft, rightAndsecond;
   
   auto recognize₋DUP = ^{ if (ctx.order₋and₋value.count() >= 1) { 
     __builtin_uint_t * top = 𝟷₋tile₋Bank(0, ctx.order₋and₋value);
     topAndLeft.bits = *top;
     if (ctx.order₋and₋value.𝟷₋tile₋copy₋include(1, { topAndLeft.bits })) 
     { confess(abstract₋machine₋failed); }
    } else { confess(requires₋an₋argument); } };
   
   auto recognize₋POP = ^{ if (ctx.order₋and₋value.count() >= 1) { 
     ctx.order₋and₋value.pop();
    } else { confess(requires₋an₋argument); } };
   
   auto recognize₋SWAP = ^{ if (ctx.order₋and₋value.count() >= 2) { 
      __builtin_uint_t * top = 𝟷₋tile₋Bank(0, ctx.order₋and₋value);
      __builtin_uint_t * second = 𝟷₋tile₋Bank(1, ctx.order₋and₋value);
      rightAndsecond.bits = *second; topAndLeft.bits = *top;
      ctx.order₋and₋value.pop(); ctx.order₋and₋value.pop();
      if (ctx.order₋and₋value.𝟷₋tile₋copy₋include(2, { topAndLeft.bits, rightAndsecond.bits })) 
      { confess(abstract₋machine₋failed); }
    } else { confess(requires₋two₋argument); } };
   
   auto recognize₋arith₋op = ^(int op) { if (ctx.order₋and₋value.count() >= 2) {
      __builtin_uint_t * top = 𝟷₋tile₋Bank(0, ctx.order₋and₋value);
      __builtin_uint_t * second = 𝟷₋tile₋Bank(1, ctx.order₋and₋value);
      rightAndsecond.bits = *second; topAndLeft.bits = *top;
      ctx.order₋and₋value.pop(); ctx.order₋and₋value.pop();
      switch (op) {
      case PLUS_KEYWORD: topAndLeft.ℝ += rightAndsecond.ℝ; break;
      case MINUS_KEYWORD: topAndLeft.ℝ -= rightAndsecond.ℝ; break;
      case MULT_KEYWORD: topAndLeft.ℝ *= rightAndsecond.ℝ; break;
      case DIV_KEYWORD: topAndLeft.ℝ /= rightAndsecond.ℝ; break;
      }
      if (ctx.order₋and₋value.𝟷₋tile₋copy₋include(1, { topAndLeft.bits })) 
      { confess(abstract₋machine₋failed); }
    } else { confess(requires₋two₋argument); } };
   
   auto recognize₋REPORT = ^(Unicodes quoted, int bold) {
    if (ctx.order₋and₋value.count() >= 1) { 
      __builtin_uint_t * top = 𝟷₋tile₋Bank(0, ctx.order₋and₋value);
      topAndLeft.bits = *top; ctx.order₋and₋value.pop();
      if (bold) { /* to_upper */ _myOutput << quote; } else { _myOutput << quote; }
      _myOutput << "  " << ::Present(_myOutput, topAndLeft.ℝ) << eol;
    } else { confess(requires₋an₋argument); } };
   
   auto recognize₋identifier = ^(Unicodes ident) { 
/*     Expression::Result result = 
       ctx->getSimulator()->evaluateIdentifier(
         ts, monteCarloState, iteration,
         identifier, sourceLocation
       ); */
      if (ctx.order₋and₋value.𝟷₋tile₋copy₋include(1, { 1.0 })) 
      { confess(abstract₋machine₋failed); }
   };
   
   auto recognize₋opt₋BOLD = ^(int enabled) { };
   
   /* context free language parser - LL(1) - ahead ⤐ */
   
   auto init₋symbol₋stack = ^{
   }();
   
   auto define₋language = ^{
   }();
   
   while (!Empty(ctx.symbol₋stack)) {
     int top = *(__builtin_int_t *)𝟷₋tile₋Youngest(ctx.symbol₋stack);
     __builtin_int_t optbeam; int symbol = lexer₋peek₋one₋symbol(optbeam);
     if (top == symbol) {
       print("Matched symbol ⬚\n", ﹟d((__builtin_int_t)symbol));
       /* ... and discard both 'read symbol' and 'top of stack': */
       beam = optbeam; /* ⬷ actually 'lexer₋advance₋one₋symbol' */
       if (ctx.symbol₋stack.𝟷₋tile₋fifo₋pop()) { confess(parser₋exhausted); }
     }
     else { /* int rule = language₁, language₂ [top][symbol]; */
       Treeint leafkey { .keyvalue = { top, -1 } };
       Treeint * first = Lookup(ctx.language₁, leafkey);
       Treeint * second = Lookup(ctx.language₂, *first);
       uint64_t rule = second->keyvalue.val;
       
       print("Rule ⬚\n", ﹟d((__builtin_int_t)rule));
       
       switch (rule) {
       case 1: /* → */
         break;
       case 2: /* → */
         break;
       case 3: /* → */
         break;
       default: confess(parse₋error);
       }
     }
   }
   /* parser finished */
   return 0;
} /*  a․𝘬․a 'Parse-and-render-tabular'. */

#pragma recto event parser front-end

struct AstNode { };
struct Expression : public AstNode { };
struct Statement : public AstNode { };
struct Statementsequence { }; /*  a․𝘬․a 'timestamped₋Statement₋sequence'. */
struct Sequences { }; /*  a․𝘬․a 'timestamped₋statement₋Sequncences'. */
/*  𝘤𝘧․ anglo-saxian 'modelling', scandinavian 'nogsamhet' and 'likely-surely'. */

struct ParserContext₁ { Sequences * root; };

inexorable int BsimParse(ParserContext₁& ctx, Unicodes events) { return 0; }
/*  a․𝘬․a scandinavian 'torr-sim'. */

#include "ⓔ-Frontend.cxx" /*  either interval, possibly distribution function. */

#pragma recto simulator

fostrat₋defi Simulator { History history; Version version=101L; } Simulator;

int Zebra(int count, chronology₋instant * toggles, double * out)
{

} /*  sometime uniform and normal not same time. */

void EnterInteractiveMode(Simulator * S) { }

int Simulate(Sequences * s, Simulator * S) { return 0; }

#include "ⓔ-Simulator.cxx" /*  variance and sums of normally distributed variables. */

#pragma recto command line

#pragma recto startup and reporting

#include <stddef.h> /* For `size_t`… */
#include <stdio.h> /* ...and `fprintf`, `FILE`, `fopen`, `fread`, 
 `fseek`, `fclose`, `SEEK_SET`, `stdout` and `stderr`… */
#include <stdlib.h> /* …together with `malloc` and `exit`. */
#include <wordexp.h> /* and of course: figures file path ~ expansion. */
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>

char8₋t * figures₋material₋and₋path=ΨΛΩ;  /*  figures file and implicit DISPLAY TABLE at end-of-file. */

char8₋t * rules₋material₋and₋path=ΨΛΩ; /*  rules file when not included in upper half of event file. */

int interactive=0;  /*  end with bye when file is read and report is written. */

int read₋until₋row=0;  /*  parse-interpret only start of file. */

struct collection filepaths₋sequence; /* with 'char8-t *'. */

unicode₋shatter figures, rules, events;  /*  unicodes with program text. */

Simulator sim; /* other-case profit & loss and balance sheets non-𝑎𝑐𝑐𝑖𝑑𝑒𝑛𝑡𝑙𝑦 ends up optional. */

int FileSystemItemOpenable(const char * u8path, __builtin_int_t * bytes)
{ struct stat st; int y = stat(u8path,&st);
   if (y == 0) { *bytes = (__builtin_int_t)(st.st_size); }
   return y == 0 ? 1 : 0;
}

void append₋reference(void * pointer)
{
   if (copy₋append₋items(1,&pointer,&filepaths₋sequence,Heap₋alloc)) { return; }
}

int option₋machine₋interprets(int argc, const char8₋t ** argv)
{ int i=0,y,figures₋filepath=0,rules₋filepath=0,only₋until₋row=0; char8₋t * token;
again:
   if (i>=argc) { goto unagain; }
   token = *(argv + i);
   if (figures₋filepath) { figures₋material₋and₋path=token; figures₋filepath=0; goto next; }
   if (rules₋filepath) { rules₋material₋and₋path=token; rules₋filepath=0; goto next; }
   if (only₋until₋row) { read₋until₋row=atoi(token); only₋until₋row=0; goto next; }
   y = IsPrefixOrEqual((const char *)token, (const char *)"-h");
   if (y == 0) { vfprint("Usage ⬚ [-f <figures.table file>] [-g] " 
    "<event file>\n", argv[0]); exit(2); }
   y = IsPrefixOrEqual((const char *)token, (const char *)"-f");
   if (y == 0) { figures₋filepath=1; goto next; }
   y = IsPrefixOrEqual((const char *)token, (const char *)"-g");
   if (y == 0) { interactive=1; goto next; }
   y = IsPrefixOrEqual((const char *)token, (const char *)"-v");
   if (y == 0) { vfprint("⬚ version ⬚\n", argv[0], "0x" QUOTE(SHA1GIT)); goto next; }
   y = IsPrefixOrEqual((const char *)token, (const char *)"-r"); /* rows to process. */
   if (y == 0) { only₋until₋row=1; goto next; }
   y = IsPrefixOrEqual((const char *)token, (const char *)"-");
   if (y > 0) { vfprint("Unknown command-line argument\n"); exit(5); }
   append₋reference(token);
next:
   i+=1; goto again;
ungain:
   return 0;
}

unicode₋shatter open₋and₋decode(char8₋t * textfile, int expand₋tilde, int * err)
{
   const char * u8path𝘖r𝙽𝚄𝙻𝙻 = (const char *)textfile;
   if (expand₋tilde) { wordexp_t expansion₂; 
      wordexp(u8path𝘖r𝙽𝚄𝙻𝙻,&expansion₂,0); /*  enter 'prompt% man wordexp' for details. */
      u8path𝘖r𝙽𝚄𝙻𝙻 = expansion₂.we_wordv[0];
   }
   __builtin_int_t u8bytes,symbols;
   if (!FileSystemItemOpenable(u8path𝘖r𝙽𝚄𝙻𝙻,&u8bytes)) { *err=2; return ΨΛΩ; }
   int fd = open(u8path𝘖r𝙽𝚄𝙻𝙻,O_RDONLY);
   if (fd == -1) { vfprint("Unable to open figures file\n"); *err=3; return ΨΛΩ; }
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
   if (Utf8ToUnicode(1+rules₋u8bytes,rules,text,&symbols)) { *err=8; return ΨΛΩ; }
   return text;
}

void open₋rule₋file()
{ int err;
   rules = open₋and₋decode(rules₋material₋and₋path,false,&err);
   switch (err) {
   case 1: break;
   case 2: vfprint("No rule file named '⬚'\n", ﹟s8(rules₋material₋and₋path)); break;
   case 3: vfprint("Unable to open rule file named '⬚'\n", ﹟s8(rules₋material₋and₋path)); break;
   case 4: break;
   }
   if (rules == ΨΛΩ) { exit(5); }
} /*  optional and upper half of event file. */

void open₋figures₋file()
{ int err;
   /* expand ~ in e․𝘨 `~/myshoebox/myfigures.table`. */
   figures = open₋and₋decode(figures₋material₋and₋path,true,&err);
   switch (err) {
   case 1: break;
   case 2: break;
   case 3: break;
   case 4: break;
   }
   if (figures == ΨΛΩ) { exit(7); }
} /*  optional. */

int
main(
  int argc, 
  const char * argv[]
)
{   char8₋t * figures=ΨΛΩ; __builtin_int_t figures₋u8bytes;
    char8₋t * rules=ΨΛΩ; __builtin_int_t rules₋u8bytes;
    char8₋t * events=ΨΛΩ; __builtin_int_t events₋u8bytes;
    if (collection₋init(sizeof(char8₋t *),4096,&filepaths₋sequence)) { exit(1); }
    option₋machine₋interprets(argv,(const char8₋t *)argv);
    if (figures₋material₋and₋path) { open_figures_file(); }
    if (rules₋material₋and₋path) { open_rules_file(); }
    if (collection₋count(&filepaths₋sequence) == 0) {
      vfprint("No event file given at your command line.\n"); exit(9);
    }
    if (rules₋material₋and₋path) {
      rules = (unicode₋shatter)Heap₋alloc(rules₋u8bytes);
      char32̄_t ucs[rules₋u8bytes]; __builtin_int_t tetras;
      if (Utf8ToUnicode(1+rules₋u8bytes,rules,ucs,&tetras)) { exit(); }
    } __builtin_int_t idx=0; void * p; int fd;
    
again:
    
    events = (char8₋t *)collection₋relative(idx,&filepaths₋sequence);
    if (!FileSystemItemExists(events,&events₋u8bytes)) { exit(10); }
    fd = open((const char *)events,O_RDONLY);
    if (fd == -1) { vfprint("Unable to open event file '⬚'.\n", events); exit(11); }
    p = mmap(0, 1 + events₋u8bytes, PROT_READ, MAP_SHARED, fd, 0);
    if (close(fd) == -1) { exit(12); }
    if (p == MAP_FAILED) { exit(13); }
    events = (char8₋t *)p; *(events + events₋u8bytes) = 0x04;
    char32̄_t ucs[events₋u8bytes]; __builtin_int_t tetras;
    if (Utf8ToUnicode(1+events₋u8bytes,events,ucs,&tetras)) { exit(14); }
    ParserContext₁ ctx; Unicodes events { tetras, ucs };
    if (BsimParse(ctx,events)) { exit(15); }
    if (interactive) { EnterInteractiveMode(&sim); }
    if (Simulate(ctx.root,&sim)) { exit(16); }
    idx+=1; goto again;
    
unagain:
    
    if (figures₋material₋and₋path) {
      char32̄_t ucs[figures₋u8bytes]; __builtin_int_t tetras;
      figures = (unicode₋shatter)Heap₋alloc(figures₋u8bytes);
      tetras = figures₋u8bytes;
      if (Utf8ToUnicode(1+figures₋u8bytes,figures₋material₋and₋path,figures,&tetras)) { exit(17); }
      Unicodes program { tetras, ucs }; chronology₋instant bye₋ts;
      if (Rendertable(bye₋ts, sim.history, program)) { exit(18); }
    }
    
    return 0;
} /*  simulate events and often output figures at a given point in time. */

