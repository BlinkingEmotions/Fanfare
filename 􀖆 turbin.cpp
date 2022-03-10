*  turbin a․𝘬․a Plan-9 | accountants' traveller companion. (CORP. EDITION.) */

import Twinbeam; /* ⬷ he is sitting in a box 𝘦․𝘨 T-FOR-D and De-la-v-all. */

/* xcrun clang @ccargs_mac -o turbin -DSHA1GIT=`git log -1 '--pretty=format:%h'` 
 '􀖆 turbin.cpp' */

typedef int64_t     Integer;
typedef Sequenta    Real; /* ⬷ here we toggle - base two and ten - native 
 Ieee754 and software arithmetics (base two and ten). */
typedef struct Unicodes transient₋Unicode;
typedef unicode₋shatter unicode₋memory;
typedef struct structa Regularpool;

/* ╳╳ scandinavian 'således' tran-sact-ions and veri-fi-c-at-es (lexer and parser) ╳╳ */

struct Ɀ₋AST { /* seder-custom and recollect */ 
 enum { INSTANT, REGULAR, INSTANT, FUNCTION_KEYWORD, L₋BRACKET, R₋BRACKET, 
  END₋OF₋TRANSMISSION };
};

/* ╳╳ computation two tables: 'annual return' and 'profit and loss' (lexer and parser) ╳╳ */

struct ᵀAST {
  
  enum { /* terminals ⤐ */ POP_KEYWORD, SWAP_KEYWORD, DUP_KEYWORD, 
   PLUS_KEYWORD, MINUS_KEYWORD, MULT_KEYWORD, DIV_KEYWORD, REPORT_KEYWORD, 
   BOLD_KEYWORD, IDENTIFIER, SQSTRING, /* non-terminals ⤐ */ // DEBET/CREDIT
   report, opt₋bold, END₋OF₋TRANSMISSION };
  
}; /* ⬷ a․𝘬․a 'table₋parser'․ */

struct language₋context { enum 𝑓𝑙𝑢𝑐𝑡𝑢𝑎𝑛𝑡 mode { initial, c₋comment, qstring } mode=initial; 
  
  __builtin_int_t linenumber₋first=1,linenumber₋last=1;
  
  fifo order₋and₋memory; Structa symbol₋stack;
  
}; /* ⬷ a․𝘬․a 'verificate₋parser' and token-i-sa-tio-n. */

Regularpool languageᵀ,languageⱿ;

struct { __builtin_int_t kiddle₋error; } error₋panel;

inexorable int init₋context(__builtin_int_t program₋bytes, struct Businessrule₋scanner₋ctxt * const ctx)
{
   ctx->lineno₋first=1, ctx->lineno₋last=1; ctx->idx₋u8c=0; ctx->negative=0; 
   ctx->mode = initial;
   return 0;
}

inexorable int
Lookahead₋scan₋Businessrules(
  __builtin_int_t bytes, char8_t text[], 
  enum Business₋token₋symbol * kind, 
  union Business₋symbol₋token₋detail * detail, 
  struct Businessrule₋scanner₋ctxt * b₋ctxt, 
  void (*identifier)(int symbols, char32_t * start)
)
{
   uchar c,f,e,d; char32_t unicode; __builtin_int_t i=s₋ctxt->idx₋u8c;
   
   🧵(utf8₋error,pool₋error,scanner₋error,conversion₋error,
   unterminated₋quote,unknown₋keyword,wrong₋number₋of₋argument,token,
   truncated₋token₋utf8) {
    case utf8₋error: return -1;
    case pool₋error: return -2;
    case unterminated₋quote: return -3;
    case unknown₋keyword: return -4;
    case wrong₋number₋of₋argument: return -5;
    case token: identifier(b₋ctxt->symbols₋in₋regular, b₋ctxt->regular); return 0;
    case truncated₋token₋utf8: return 0;
   }
   
   typedef int (^type)(char32_t c);
   typedef void (^action)(void);
   
   type digit = ^(char32_t c) { return U'0' <= c && c <= U'9'; };
   type derender₋newline = ^(char32_t c) { return c == U'\xa'; }; /* de- = completely = fullgångna. */
   type newline = ^(char32_t c) { return derender₋newline(c) || c == U'\xd'; };
   type whitespace = ^(char32_t c) { return c == U' ' || U'\t' == c || newline(c); };
   type regular = ^(char32_t c) { return (U'a' <= c && c <= U'z') || (U'A' <= c && c <= U'Z') || digit(c); };
   type period = ^(char32_t c) { return c == U'.'; };
   
   typedef int (^Assistant₁)();
   typedef int (^Assistant₂)(Stringpool, char32_t);
   typedef int (*Assistant₂₋params)(char32_t unicode);
   typedef Assistant₂₋params Stringpool;
   
   Assistant₂ assistant₂ = ^(Stringpool follow₋current, char32_t unicode) { return follow₋current(unicode); };
   Assistant₁ assistant₁ = ^(void (*close₋current)(void)) { close₋current(); return 0; };
   
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
     } else { unicode = (char32_t)c; s₋ctxt->idx₋u8c+=1; }
   }
   
   /* ⤐ Unicode decoded and available ⤐ */
   
   if (derender₋newline(unicode)) { s₋ctxt->lineno₋first+=1, s₋ctxt->lineno₋last+=1; token₋sep(); }
   else if (newline(unicode)) { token₋sep(); }
   else if (whitespace(unicode)) { token₋sep(); }
   else if (s₋ctxt->mode == initial && unicode == U'-') { s₋ctxt->negative = !s₋ctxt->negative; }
   else if (s₋ctxt->mode == initial && digit(unicode)) {
     Feeder feeder = ^(unsigned short * l₋to₋r₋digit) {
       return complete; };
     if (CastTˣᵗToSequent(feeder,&s₋ctxt->ongoing)) { confess(conversion₋error); }
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
   
   auto digit = ^(char32_t c) { return U'0' <= c && c <= U'9'; };
   auto counting₋newline = ^(char32_t c) { return c == U'\xa'; };
   auto newline = ^(char32_t c) { return counting₋newline(c) || c == U'\xd'; };
   auto whitespace = ^(char32_t c) { return c == U' ' || U'\t' == c || newline(c); };
   auto misc₋symbols = ^(char32_t c) { return U'😐' == c || c == U'_'; }; /* ⬷ see clang c++ scanner for one definition. */
   auto first₋ident₋char = ^(char32_t c) { return (U'a' <= c && c <= U'z') || (U'A' <= c && c <= U'Z') || misc₋symbols(c); };
   auto rest₋ident₋char = ^(char32_t c) { return first₋ident₋char(c) || digit(c); };
   
   /* connect to kiddle qstring alt. identifier a․𝘬․a 'regular token' ⤐ */
   
   auto append₋qstring₋alt₋ident₋unicode = ^(char32_t c) { if (ctx.puddle.copy₋append₋text(1, { c })) { PULT💡(panel.kiddle₋error); } } };
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
   
   auto lexer₋peek₋one₋symbol = ^(__builtin_int_t &optbeam) { char32_t c; 
again:
     if (beam >= program.tetras) { goto unagain; }
     c = *(beam + program.unicodes);
     if (c == 0x0000) { goto unagain; } /* ⬷ c𝘧․ END₋OF₋TRANSMISSION. */
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
   }; /* ⬷ a․𝘬․a 'crypto₋lex' (req. 256-bit leafs to symbol tree). Reads 'program' 
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
} /* ⬷ a․𝘬․a 'Parse-and-render-tabular'. */

#pragma mark - event parser front-end

struct AstNode { };
struct Expression : public AstNode { };
struct Statement : public AstNode { };
struct Statementsequence { }; /* ⬷ a․𝘬․a 'timestamped₋Statement₋sequence'. */
struct Sequences { }; /* ⬷ a․𝘬․a 'timestamped₋statement₋Sequncences'. */
/* ⬷ 𝘤𝘧․ anglo-saxian 'modelling', scandinavian 'nogsamhet' and 'likely-surely'. */

struct ParserContext₁ { Sequences * root; };

inexorable int BsimParse(ParserContext₁& ctx, Unicodes events) { return 0; }
/* ⬷ a․𝘬․a scandinavian 'torr-sim'. */

#include "ⓔ-Frontend.cxx" /* ⬷ either interval, possibly distribution function. */

#pragma mark - Simulator

struct Simulator { History history; Version version=101L; 
  Simulator() : history(version) { }
  void enterInteractiveMode() { }
  int simulate(Sequences * s) { return 0; }
};

#include "ⓔ-Simulator.cxx" /* ⬷ variance and sums of normally distributed variables. */

#pragma mark - Commando line



#pragma mark - Startup and reporting

#include <stddef.h> /* For `size_t`… */
#include <stdio.h> /* ...and `fprintf`, `FILE`, `fopen`, `fread`, 
 `fseek`, `fclose`, `SEEK_SET`, `stdout` and `stderr`… */
#include <stdlib.h> /* …together with `malloc` and `exit`. */
#include <wordexp.h> /* and of course: bootloader path ~ expansion. */
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>

int FileSystemItemExists(const char * path, off_t * bytes) { struct stat st; int y = 
 stat(path,&st); if (y == 0) { *bytes = st.st_size; return 1; } else { return 0; } 
}

#define ⁺⁼ProcessCommandline(ARGV)                                              \
auto process_commandline = ^(const char * argv[]) {                             \
  auto scan_option = ^(const char * arg) {                                      \
    switch (*arg) {                                                             \
    case 'h': fprintf(stderr, "Usage: %s [-f <figures.table file>] [-g] "       \
      "<event file>\n", argv[0]); exit(1);                                      \
    case 'f': ++ca; if (ca) { open_figures_file(*ca); } else { exit(2); } return; \
    case 'g': interactive = true; return;                                       \
    case 'v': fprintf(stderr, "%s version: %s\n", argv[0], "0x" STRINGIFY(SHA1GIT)); \
      exit(3);                                                                  \
    default: fprintf(stderr, "Unknown command-line argument\n"); exit(4); }     \
  }; /* argv[argc] == NULL, so: */                                              \
  for (ca = argv + 1; *ca && (*ca)[0] == '-'; ++ca) scan_option(1 + *ca);       \
  if (!*ca) scan_option("h"); /* 'No args' ∧ 'ends with argument'. */           \
}; process_commandline(ARGV) /* Implicits in lambda expression: `ca`, `interactive` and `SHA1GIT`. */

int
main(
  int argc, 
  const char * argv[]
)
{  bool 𝑓𝑙𝑢𝑐𝑡𝑢𝑎𝑛𝑡 interactive=false; 𝑓𝑙𝑢𝑐𝑡𝑢𝑎𝑛𝑡 char8_t * figures=NULL; 𝑓𝑙𝑢𝑐𝑡𝑢𝑎𝑛𝑡 char8_t * events;
    𝑓𝑙𝑢𝑐𝑡𝑢𝑎𝑛𝑡 const char **ca; 𝑓𝑙𝑢𝑐𝑡𝑢𝑎𝑛𝑡 off_t figures₋utf8bytes;
#define event_filenameOrNULL *ca
    auto open₋figures₋file = ^(const char *utf8path𝘖r𝙽𝚄𝙻𝙻) {
      /* expand ~ in e․𝘨 `~/myshoebox/myfigures.table`. */
      wordexp_t expansion₁; wordexp(utf8path𝘖r𝙽𝚄𝙻𝙻,&expansion₁,0); /* ⬷ enter 'prompt% man wordexp' for details. */
      const char * filename = expansion₁.we_wordv[0];
      off_t utf8bytes; if (!FileSystemItemExists(filename,&utf8bytes)) { exit(5); }
      int fd = open(filename,O_RDONLY);
      if (fd == -1) { mfprint("Unable to open figures file\n"); exit(6); }
      void * p = mmap(0, 1 + utf8bytes,PROT_READ,MAP_SHARED,fd,0);
      if (close(fd) == -1) { exit(7); }
      if (p == MAP_FAILED) { exit(8); }
      figures = (char8_t *)p; *(figures + utf8bytes) = 0x04; figures₋utf8bytes=utf8bytes;
    }; /* ⬷ optional. */
    auto open₋rule₋file = ^(const char *utf8path𝘖r𝖭𝖴𝖫𝖫) { }; /* ⬷ optional as well. */
    ⁺⁼ProcessCommandline(argv);
    if (!event_filenameOrNULL) { mfprint("No event file given at your command line\n"); exit(9); }
    off_t utf8bytes; if (!FileSystemItemExists(event_filenameOrNULL,&utf8bytes)) { exit(10); }
    int fd = open(event_filenameOrNULL,O_RDONLY);
    if (fd == -1) { mprintf("Unable to open event file '%s'\n", event_filenameOrNULL); exit(11); }
    void * p = mmap(0, 1 + utf8bytes, PROT_READ, MAP_SHARED, fd, 0);
    if (close(fd) == -1) { exit(12); }
    if (p == MAP_FAILED) { exit(13); }
    events = (char8_t *)p; *(events + utf8bytes) = 0x04;
    𝑓𝑙𝑢𝑐𝑡𝑢𝑎𝑛𝑡 Simulator sim; /* …else profit&loss and balance sheets non-𝑎𝑐𝑐𝑖𝑑𝑒𝑛𝑡𝑙𝑦 ends up optional. */
    /* Parse open file */ 
    if (Utf8ToUnicode(events, 1 + __builtin_int_t(utf8bytes),
      ^(__builtin_int_t tetras, char32_t * ucs, __builtin_int_t utf8bytes) { ParserContext₁ ctx; 
        Unicodes events { tetras, ucs };
        if (BsimParse(ctx,events)) { exit(15); }
        if (interactive) { sim.enterInteractiveMode(); }
        if (sim.simulate(ctx.root)) { exit(16); }
      }
    )) { exit(14); }
    
    if (figures) {
      if (Utf8ToUnicode(figures, 1 + __builtin_int_t(figures₋utf8bytes), 
        ^(__builtin_int_t tetras, char32_t * ucs, __builtin_int_t utf8bytes) {
          Unicodes program { tetras, ucs };
          Chronology::Instant bye₋ts;
          if (Rendertable(bye₋ts, sim.history, program)) { exit(18); }
        })) { exit(17); }
    }
    
    return 0;
} /* ⬷ i․𝘦 simulate events and often output figures at a given point in time. */

/* https://9fans.github.io/plan9port/man/man1/intro.html

Reread sam, eqn, pic, fossil and the implementation in C++ turbine, Table.ypp, business.rul and --<UIQ.cpp>. */



