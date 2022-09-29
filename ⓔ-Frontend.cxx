/*  ⓔ-Frontend.cxx | interval and the zebra distribution. */

inexorable int append₋to₋fraction(char32̄_t uc, struct language₋context * ctxt)
{
   return 0;
}

inexorable int append₋to₋regular(char32̄_t uc, struct language₋context * ctxt)
{
   return 0;
}

inexorable void resize₋window(struct language₋context * ctxt, 
 struct token₋detail * detail₋out)
{
   detail₋out->lineno₋first = ctxt->lineno₋first;
}

inexorable void reset(struct language₋context * ctxt)
{
   ctxt->state=mode₋initial;
   ctxt->symbols₋in₋regular=0;
   ctxt->ongoing₋real = accumulative₋zero();
   ctxt->symbols₋in₋frac=0;
}

int next₋token₁(struct language₋context * ctxt, struct token₋detail * detail₋out)
{ __builtin_int_t i,symbols=ctxt->text₋program.tetras;
   struct Unicodes program=ctxt->text₋program;
   
   🧵(regular,monetary,error,completion)
   {
   case regular: return 0;
   case monetary: return 0;
   case completion: return -1;
   case error: return -2;
   }
   
again:
   
   i=ctxt->tip₋unicode; ctxt->tip₋unicode+=1;
   if (i >= symbols && STATE(mode₋initial)) { confess(completion); }
   else confess(error);
   goto again;
}

inexorable int advance₋through₋text(struct translation₋context * trans, 
 struct language₋context * ctxt)
{
   trans->primary₋piece = trans->lookahead;
   return next₋token₁(ctxt,&trans->lookahead);
}

inexorable void guard₋match(int lookahead₋token, int expected₋token, 
 struct translation₋context * trans, struct language₋context * ctxt)
{
   if (lookahead₋token == expected₋token) {
     int y = advance₋through₋text(trans,ctxt);
   } else {
    char * tokenname(int);
    char * expected₋name = tokenname(expected₋token);
    char * actual₋name = tokenname(lookahead₋token);
    Diagnos(1,trans,0,"error: syntax expected ⬚ token and read a ⬚ token", 
     ﹟s7(expected₋name), ﹟s7(actual₋name));
    error₋panel.bitmap != recovery;
   }
}

inexorable int query₋match(int expected₋token, int conditional₋token, 
 struct translation₋context * trans, struct language₋context * ctxt)
{
   int old = trans->primary₋piece.token == expected₋token;
   int young = trans->lookahead.token == conditional₋token;
   int proceed = old && young;
   int early = old && !young;
   if (proceed) { guard₋match(_,_,trans,ctxt); }
   if (early) { Exhausted₋grammar(trans); }
}

inexorable void Exhausted₋grammar(struct translation₋context * trans)
{
   Argᴾ token = s7(tokenname(trans->lookahead.token));
   Diagnos(1,trans,1,"error: exhausted syntactic envelop in token ⬚", token);
   /* "error: symbol ⬚ unwelcomed syntactically" */
   /* "error: token ⬚ is off topic" */
}

inexorable void parse₋statement(struct translation₋context * trans, struct language₋context * ctxt)
{
   if (query₋match()) { }
   else if (query₋match()) { }
   else { }
}

int recur₋descent₋streck(struct translation₋context * trans, struct language₋context * ctxt)
{
   parse₋statement(primary₋piece,lookahead);
   return 0;
}

int BsimParse(struct language₋context * ctxt, struct virtu₋context * ctxt₋out)
{
   struct translation₋context read₋ctxt;
   if (next₋token₁(ctxt,events₋program,&read₋ctxt->primary₋piece)) { vfprint("zero token conversionalist error\n"); return -1; }
   if (next₋token₁(ctxt,events₋program,&read₋ctxt->lookahead)) { vfprint("one token conversionalist error\n"); return -2; }
   int i = recur₋descent₋streck(&trans₋ctxt,ctxt);
   switch (i)
   {
   case -1: vfprint("parsed ok.\n"); return 0; break;
   case -2: vfprint("parse error.\n"); return -2; break;
   }
   return -1;
}

void tokenize₋streck(struct language₋context * ctxt, 
 struct Unicodes events₋program)
{ struct token₋detail isolation; char * name; int i;
again:
   i = next₋token₁(ctxt,events₋program,&isolation);
   if (i == -1 || i == -2) { goto unagain; }
   extern char * tokenname(int);
   name = tokenname(isolation.token);
   print("⬚ (⬚ ⬚ ⬚ ⬚ ⬚)\n", ﹟s7(name), ﹟d(isolation.column₋first), 
    ﹟d(isolation.column₋last), ﹟d(isolation.lineno₋first), 
    ﹟d(isolation.lineno₋last), 
    ﹟s8(isolation.predecessor₋src->source₋path));
   if (isolation.token == END₋OF₋TRANSMISSION) { goto unagain; }
   goto again;
unagain:
   print("\n");
   ctxt->tip₋unicode=0;
}

char * tokenname(int token)
{
   switch (token) {
   case END₋OF₋TRANSMISSION: return "eot";
   case QUOTED₋TEXT: return "quoted-text";
   case PLUS_SYMBOL: return "+";
   case MINUS_SYMBOL: return "-";
   case MULT_SYMBOL: return "*";
   case DIV_SYMBOL: return "/";
   case REGULAR: return "regular";
   case MONETARY: return "monetary";
   case FUNCTION_KEYWORD: return "function";
   case INSTANT: return "instant";
   case BOOKKEEP_KEYWORD: return "bookkeep";
   case DEBET_KEYWORD: return "debet";
   case CREDIT_KEYWORD: return "credit";
   case COMMENT_KEYWORD: return "comment";
   case VAR_KEYWORD: return "var";
   case PRINT_KEYWORD: return "print";
   case BREAK_KEYWORD: return "break";
   case SET_KEYWORD: return "set";
   case RETURN_KEYWORD: return "return";
   case DO_KEYWORD: return "do";
   case IF_KEYWORD: return "if";
   case THEN_KEYWORD: return "then";
   case ELSE_KEYWORD: return "else";
   case END_KEYWORD: return "end";
   case BEFORE_KEYWORD: return "before";
   case AND_SYMBOLS: return "and";
   case OR_SYMBOLS: return "or";
   case NOT_SYMBOL: return "not";
   case XOR_SYMBOL: return "xor";
   case ENTITY_KEYWORD: return "entity";
   case ACCOUNT_KEYWORD: return "account";
   case TABLE_KEYWORD: return "table";
   case DISPLAY_KEYWORD: return "display";
   case FROM_KEYWORD: return "from";
   case CREATE_KEYWORD: return "create";
   case NAMED_KEYWORD: return "named";
   case TRADING_KEYWORD: return "trading";
   case IN_KEYWORD: return "in";
   case RESIDENT_KEYWORD: return "resident";
   case WITH_KEYWORD: return "with";
   case IS_KEYWORD: return "is";
   case TO_KEYWORD: return "to";
   case SCHEDULE_KEYWORD: return "schedule";
   case STARTING_KEYWORD: return "starting";
   case OCCURING_KEYWORD: return "occurring";
   case ENDING_KEYWORD: return "ending";
   case DROP₋SCHEDULE_KEYWORD: return "drop₋schedule";
   case EXCHANGE_KEYWORD: return "exchange";
   case RATE_KEYWORD: return "rate";
   case CURRENCY_KEYWORD: return "currency";
   case LEFT₋BRACKET: return "[";
   case RIGHT₋BRACKET: return "]";
   case POP_KEYWORD: return "pop";
   case SWAP_KEYWORD: return "swap";
   case DUP_KEYWORD: return "dup";
   case REPORT_KEYWORD: return "report";
   case BOLD_KEYWORD: return "bold";
   }
   return "<unknown>";
}
