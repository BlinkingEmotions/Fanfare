/*  ⓔ-Frontend.cxx | with interval and the zebra distribution. */

int next₋token₁(struct language₋context * ctxt, 
 struct token₋detail * detail₋out)
{
   return 0;
}

int BsimParse(struct language₋context * ctxt, 
 struct Unicodes events₋program, struct parsed₋context₁ * ctxt₋out)
{
   return 0;
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
   case ACCOUNT_KEYOWORD: return "account";
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
   case OCCURRING_KEYWORD: return "occurring";
   case ENDING_KEYWORD: return "ending"
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
