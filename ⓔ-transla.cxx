/*  ⓔ-transla.cxx | on-to old ideas on power-control. */

int accept(int expected₋token, struct translation₋context * trans, struct language₋context * ctxt)
{
   if (trans->primary₋piece.token == expected₋token) { advance₋through₋text(trans,ctxt); return 1; }
   return 0;
}

int expect(int expected₋token, struct translation₋context * trans, struct language₋context * ctxt)
{
   if (accept(expected₋token,trans,ctxt)) return 1; Diagnos("expect: unexpected symbol"); return 0;
}

void expression(struct translation₋context * trans, struct language₋context * ctxt)
{
   
}

void term(struct translation₋context * trans, struct language₋context * ctxt)
{
   
}

void factor(struct translation₋context * trans, struct, language₋context * ctxt)
{
   
}

void condition(struct translation₋context * trans, struct language₋context * ctxt)
{
   
}

void assignment(struct translation₋context * trans, struct language₋context * ctxt)
{
   guard₋match(int lookahead₋token, int expected₋token,trans,ctxt);
   guard₋match(int lookahead₋token, int expected₋token,trans,ctxt);
   expression(trans,ctxt);
   guard₋match(int lookahead₋token, int expected₋token,trans,ctxt);
} /*  a․𝘬․a 'parse₋assignment₋suffix'. */

void statement(struct translation₋context * trans, struct language₋context * ctxt)
{
   
}

/*

factor <-- ID | CONST | '(' expression ')'
expressions <-- term ( ('+'|'-') term)*
term <-- factor ( ('*'|'/') factor )*
assignment <-- ID '=' expression ';'

 */
