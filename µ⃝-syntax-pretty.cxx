/*  µ⃝-syntax-pretty.cxx | prints abstract syntax tree from left to right. */

Argᴾ ﹟fier(bagref item)
{
   return ﹟ident(item->X.store.regular);
}

#define ﹟ent ﹟indent

void print₋expr(struct tabcontext * tabs, bagref expr)
{ char * op;
   switch (expr->T)
   {
   case ident: print("⬚ident '⬚' @⬚\n",﹟ent(0,tabs), 
    ﹟fier(expr),﹟short(expr->memory)); return;
   case number: print("⬚number '⬚' @⬚\n",﹟ent(0,tabs), 
    ﹟d(expr->X.store.integer),﹟short(expr->memory)); return;
   case unarbitrated₋symbol:
    print("⬚unarbitrated\n",﹟ent(0,tabs));
    return;
   case times: op="*"; goto tail;
   case divide: op="÷"; goto tail;
   case plus: op="+"; goto tail;
   case minus: op="-"; goto tail;
   case eqltwo: op="=="; goto tail;
   case eqlone: op="="; goto tail;
   case neq: op="≠"; goto tail;
   case lss: op="<"; goto tail;
   case leq: op="≤"; goto tail;
   case gtr: op=">"; goto tail;
   case geq: op="≥"; goto tail;
   default: print("unknown expression and symbol-type '⬚'\n", ﹟d(expr->T)); return;
   }
tail:
   ++tabs->indentation;
   print₋expr(tabs,expr->form.l);
   print₋expr(tabs,expr->form.r);
   --tabs->indentation;
   print("⬚⬚ @⬚\n",﹟ent(0,tabs),﹟s7(op),﹟short(expr->memory));
   ++tabs->indentation;
   --tabs->indentation;
}

void print₋list(struct tabcontext * tabs, consref list)
{ consref cell=list; bagref memory; int i=0;
again:
   if (cell == 0) return;
   i+=1; if (i >= 100) return;
   memory=cell->item;
   switch (memory->T)
   {
   case callsym:
     print("⬚call '⬚' (@ 0x⬚)\n",﹟ent(0,tabs),﹟fier(memory),﹟ref(memory));
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
     if (memory->form.element) {
       print("⬚inited with\n",﹟ent(0,tabs));
       print₋expr(tabs,memory->form.element);
     }
     else print("⬚uninited\n",﹟ent(0,tabs));
     break;
   case procsym:
     print("transcript '⬚' (@ 0x⬚)\n",﹟fier(memory),﹟ref(memory));
     ++tabs->indentation;
     print₋list(tabs,memory->form.formalºª);
     print₋list(tabs,memory->form.detailsºª);
     --tabs->indentation;
     break;
   case formalparamsym:
     print("⬚formal param (@ 0x⬚)\n",﹟ent(0,tabs),﹟ref(memory));
     print("⬚type '⬚'\n",﹟ent(1,tabs),﹟fier(memory->form.element));
     print("⬚left '⬚'\n",﹟ent(1,tabs),﹟fier(memory->form.l));
     // print("⬚right '⬚'\n",﹟ent(1,tabs));
     break;
   default:
     print("unknown tree item '⬚' with symbol-type '⬚'\n",﹟d(i),﹟d(memory->T));
     return;
   }
   cell=cell->nxt.next;
   goto again;
}

void print₋ast(bagref tree)
{  struct tabcontext tabs; 
   print("*** constants ***\n");
   tabs.indentation=0; print₋list(&tabs,tree->form.const₋machineºª);
   print("*** start-of function list ***\n");
   tabs.indentation=0; print₋list(&tabs,tree->form.machineºª);
   print("*** function list ends with found memory recollects ***\n");
   tabs.indentation=0; print₋list(&tabs,tree->form.recollectºª);
}

