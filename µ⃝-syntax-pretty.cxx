/*  µ⃝-syntax-pretty.cxx | prints abstract syntax tree from left to right. */

void stmt₋print(struct tabcontext * tabs, struct dynamic₋bag * statement)
{
   switch (statement->T)
   {
   case callsym: print("call '⬚'\n",﹟ident(statement->X.store.regular)); break;
   case branch₋goto₋optsym: print("branch to '⬚'\n",﹟ident(statement->X.store.regular)); break;
   case ifsym: print("compare\n"); infix₋print(); stmt₋print(); stmt₋print(); break;
   case afterward: print("assign\n"); break;
   default: print("<unrecognized statement>\n");
   }
}

void unary₋print(struct tabcontext * tabs, char * op, struct dynamic₋bag * expression)
{
   switch (expression->T)
   {
   case ident: print("⬚ident '⬚' @⬚\n",﹟indent(0,tabs), 
    ﹟ident(item->X.store.regular),﹟short(item->memory)); break;
   case number: print("⬚number '⬚' @⬚\n",﹟indent(0,tabs), 
    ﹟d(item->X.store.integer),﹟short(item->memory)); break;
   }
}

void infix₋print(struct tabcontext * tabs, char * op, struct dynamic₋bag * expression)
{
   print₋tree(tabs,expression->form.l);
   switch (expression->T)
   {
   case times: infix₋print(tabs,"times"); break;
   case divide: infix₋print(tabs,"÷"); break;
   case plus: infix₋print(tabs,"+"); break;
   case minus: infix₋print(tabs,"-"); break;
   case eql: infix₋print(tabs,"="); break;
   case neq: infix₋print(tabs,"≠"); break;
   case lss: infix₋print(tabs,"<"); break;
   case leq: infix₋print(tabs,"≤"); break;
   case gtr: infix₋print(tabs,">"); break;
   case geq: infix₋print(tabs,"≥"); break;
   }
   print("⬚⬚ @⬚\n",﹟indent(0,tabs),﹟s7(op),﹟short(expression->memory));
   print₋tree(tabs,expression->form.r);
}

void list₋print(struct dynamic₋bag₋cons * list₋first, void (^elem)(struct dynamic₋bag * item))
{ struct dynamic₋bag₋cons * memory = list₋first;
   print("[");
again:
   if (memory == 0) goto unagain;
   elem(memory->item);
   memory = memory->nxt.next; goto again;
unagain:
   print("]");
}

void print₋ast(struct tabcontext * tabs, struct dynamic₋bag₋cons * machine₋recollect)
{
   switch (item->T)
   {
   case callsym: print("⬚call '⬚'\n", ﹟indent(0,tabs), ﹟ident(item->X.store.regular)); break;
   case branch₋goto₋optsym: print("⬚branch ", ﹟indent(0,tabs), ﹟ident(item->X.store.regular)); break;
   case label: break;
   case afterward: break;
   case comparesym: break;
   case additionssym: stmt₋print(tabs,item); break;
   case constsym: print("constant '⬚'\n", ﹟ident(item->X.store.regular)); print₋tree(tabs,item->element); break;
   case varsym: print("variable '⬚'\n", ﹟ident(item->X.store.regular)); print₋tree(tabs,item->element); break;
   case procsym: print("transcript '⬚'\n", ﹟ident(item->X.store.regular)); 
    list₋print(tabs,item->formalºª,item->formal₋last); stmt₋print(tabs,item->sequence); break;
   default: print("unknown item and symbol-type '⬚'\n",﹟d(item->T));
   }
}

