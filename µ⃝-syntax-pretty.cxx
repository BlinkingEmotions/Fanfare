/*  µ⃝-syntax-pretty.cxx | prints abstract syntax tree from left to right. */

Argᴾ ﹟fier(struct dynamic₋bag * item)
{
   return ﹟ident(item->X.store.regular);
}

#define ﹟ent ﹟indent

void print₋expr(struct tabcontext * tabs, struct dynamic₋bag * expr)
{ char * op;
   switch (expr->T)
   {
   case ident: print("⬚ident '⬚' @⬚\n",﹟ent(0,tabs), 
    ﹟fier(expr),﹟short(expr->memory)); return;
   case number: print("⬚number '⬚' @⬚\n",﹟ent(0,tabs), 
    ﹟d(expr->X.store.integer),﹟short(expr->memory)); return;
   case times: op="*"; goto tail;
   case divide: op="÷"; goto tail;
   case plus: op="+"; goto tail;
   case minus: op="-"; goto tail;
   case eql: op="="; goto tail;
   case neq: op="≠"; goto tail;
   case lss: op="<"; goto tail;
   case leq: op="≤"; goto tail;
   case gtr: op=">"; goto tail;
   case geq: op="≥"; goto tail;
   default: print("unknown expression and symbol-type '⬚'\n", ﹟d(expr->T)); return;
   }
tail:
   print₋expr(tabs,expr->form.l);
   print("⬚⬚ @⬚\n",﹟ent(0,tabs),﹟s7(op),﹟short(expr->memory));
   print₋expr(tabs,expr->form.r);
}

void list₋print(struct dynamic₋bag₋cons * list₋first, 
 void (^element)(struct dynamic₋bag * item))
{ struct dynamic₋bag₋cons * memory = list₋first;
   print("[");
again:
   if (memory == 0) goto unagain;
   element(memory->item);
   memory = memory->nxt.next; goto again;
unagain:
   print("]");
}

void print₋list(struct tabcontext * tabs, struct dynamic₋bag₋cons * list)
{  struct dynamic₋bag₋cons * cell = list; struct dynamic₋bag * memory;
again:
   if (cell == 0) return;
   memory=cell->item;
   switch (memory->T)
   {
   case callsym:
     print("⬚call '⬚'\n",﹟ent(0,tabs),﹟fier(memory));
     break;
   case branch₋goto₋optsym:
     print("⬚branch to '⬚'\n",﹟ent(0,tabs),﹟fier(memory));
     break;
   case comparesym:
     print("⬚compare\n",﹟ent(0,tabs));
     ++tabs->indentation;
     print₋expr(tabs,memory->form.element);
     print₋list(tabs,memory->form.compare₋thenºª);
     print₋list(tabs,memory->form.compare₋elseºª);
     --tabs->indentation;
     break;
   case afterward:
     print("⬚assign\n",﹟ent(0,tabs));
     ++tabs->indentation;
     print₋expr(tabs,memory->form.l);
     print₋expr(tabs,memory->form.r);
     --tabs->indentation;
     break;
   case label:
     print("label '⬚':",﹟fier(memory));
     break;
   case additionssym:
     print("⬚additions '⬚'",﹟ent(0,tabs),﹟fier(memory));
     print₋expr(tabs,memory);
     break;
   case constsym:
     print("constant '⬚'\n",﹟fier(memory));
     print₋expr(tabs,memory->form.element);
     break;
   case varsym:
     print("⬚variable '⬚'\n",﹟ent(0,tabs),﹟fier(memory));
     if (memory->form.element) { print("⬚inited with\n",﹟ent(0,tabs)); print₋expr(tabs,memory->form.element); }
     else print("⬚uninited\n",﹟ent(0,tabs));
     break;
   case procsym:
     print("transcript '⬚'\n",﹟fier(memory));
     print₋list(tabs,memory->form.formalºª);
     print₋list(tabs,memory->form.sequenceºª);
     break;
   default:
     print("⬚unknown tree item and symbol-type '⬚'\n",﹟ent(0,tabs),﹟d(memory->T));
   }
   cell=cell->nxt.next;
   goto again;
}

void print₋ast(struct dynamic₋bag * tree)
{  struct tabcontext tabs; tabs.indentation=0;
   print₋list(&tabs,tree->form.recollectºª);
   tabs.indentation=0;
   print₋list(&tabs,tree->form.machineºª);
}

