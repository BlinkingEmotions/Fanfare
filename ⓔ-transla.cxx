/*  ⓔ-transla.cxx | on-to old ideas on power-control. */

int match(int expected₋token, struct translation₋context * trans, struct language₋context * ctxt)
{
   if (trans->primary₋piece.token == expected₋token) { advance₋through₋text(trans,ctxt); return 1; }
   return 0;
} /* a.k.a 'accept'. */

int expect(int expected₋token, struct translation₋context * trans, struct language₋context * ctxt)
{
   if (match(expected₋token,trans,ctxt)) return 1; Diagnos("expect: unexpected symbol"); return 0;
}

/*

factor <-- ID | CONST | '(' expression ')'
term <-- factor ( ('*'|'/') factor )*
expressions <-- term ( ('+'|'-') term)*
assignment <-- ID '=' expression ';'

 */

void statement(struct translation₋context * trans, struct language₋context * ctxt)
{
   
}

void assignment(struct translation₋context * trans, struct language₋context * ctxt)
{
   /* guard₋match */ match(REGULAR,trans,ctxt);
   /* guard₋match */ match(EQUALS,trans,ctxt);
   expression(trans,ctxt);
   /* guard₋match */ match(SEMICOLON,trans,ctxt);
} /*  a․𝘬․a 'parse₋assignment₋suffix'. */

void condition(struct translation₋context * trans, struct language₋context * ctxt)
{
   
}

void expression(struct translation₋context * trans, struct language₋context * ctxt)
{
   term(trans,ctxt);
again:
   if (trans->primary₋piece.token != PLUS_SYMBOL && trans->primary₋piece.token != MINUS_SYMBOL) { return; }
   match(trans->primary₋piece.token,trans,ctxt);
   term(trans,ctxt);
   goto again;
}

void term(struct translation₋context * trans, struct language₋context * ctxt)
{
   factor(trans,ctxt);
again:
   if (trans->primary₋piece.token != MULT_SUMBOL && trans->primary₋piece.token != DIV_SYMBOL) { return; }
   match(trans->primary₋piece.token,trans,ctxt);
   factor(trans,ctxt);
   goto again;
}

void factor(struct translation₋context * trans, struct language₋context * ctxt)
{
   switch (trans->primary₋piece.token) {
   case REGULAR: match(REGULAR,trans,ctxt); break;
   case MONETARY; match(MONETARY,trans,ctxt); break;
   case LEFT₋PAREN: match(LEFT₋PAREN,trans,ctxt); expression(trans,ctxt); match(RIGHT₋PAREN,trans,ctxt); break;
   default: Diagnos(1,ctxt,1,"expecting id,const,leftparen got _\n");
   }
}

