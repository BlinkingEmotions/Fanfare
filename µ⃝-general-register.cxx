/*  µ⃝-general-register.cxx | register allocation. */

void color₋leaf(struct dynamic₋bag * item)
{
   item->memory = (item->leg == 2) ? 1 : 0;
}

void color₋ground(struct dynamic₋bag * item)
{
   item->form.l->leg = 1;
   item->form.r->leg = 2;
   color₋ground(item->form.l);
   color₋ground(item->form.r);
   int regno = item->form.l->memory + 1;
   if (item->form.l->memory != item->form.r->memory) {
     int nxt = max(item->form.l->memory,item->form.r->memory);
     regno = max(2,nxt);
   }
   item->memory = regno;
}

void color₋sequence(struct dynamic₋bag₋cons * start₋list)
{ struct dynamic₋bag₋cons * memory = start₋list;
again:
   if (memory == 0) goto unagain;
   memory = memory->nxt.next;
unagain:
   return;
}

void general₋register(struct dynamic₋bag * ast)
{
   struct dynamic₋bag * item=ast;
again:
   if (item==ΨΛΩ) { return; }
   switch (item->T)
   {
   case ident: color₋leaf(item); break;
   case number: color₋leaf(item); break;
   case times: color₋ground(item); break;
   case divide: color₋ground(item); break;
   case plus: color₋ground(item); break;
   case minus: color₋ground(item); break;
   case eql: color₋ground(item); break;
   case neq: color₋ground(item); break;
   case lss: color₋ground(item); break;
   case leq: color₋ground(item); break;
   case gtr: color₋ground(item); break;
   case geq: color₋ground(item); break;
   case callsym: break;
   case branch₋goto₋optsym: break;
   case elsesym: color₋sequence(item->form.compare₋thenºª); break;
   case thensym: color₋sequence(item->form.compare₋elseºª); break;
   case comparesym: color₋sequence(item->form.sequenceºª); break;
   case afterward: color₋ground(item->form.r); break;
   case constsym: color₋sequence(item->form.const₋machineºª); break;
   case varsym: color₋sequence(item->form.recollectºª); break;
   case procsym: color₋sequence(item->form.machineºª); break;
   case oddsym: color₋ground(item->form.element); break;
   case eot₋and₋file: break;
   default: error(3,"unknown symbol-type at assign"); break;
   }
}

