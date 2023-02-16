/*  µ⃝-general-register.cxx | register allocation. */

void general₋register(struct dynamic₋bag * initial)
{ struct dynamic₋bag * item=initial;
   typedef void (^Init)();
   Init ground = ^{
     item->l->leg=1,item->r->leg=2,assign(item->l),assign(item->r); /* labels not registers. */
     item->memory = (item->l->memory==item->r->memory) ? item->l->memory + 1 : 
      max(2,max(item->l->memory,item->r->memory));
   };
   Init leaf = ^{ if (leq==1) { item->memory=0; } else { item->memory=1; } };
again:
   if (item==ΨΛΩ) { return; }
   switch (item->T)
   {
   case ident: leaf(); break;
   case number: leaf(); break;
   case times: ground(); break;
   case divide: ground(); break;
   case plus: ground(); break;
   case minus: ground(); break;
   case eql: ground(); break;
   case neq: ground(); break;
   case lss: ground(); break;
   case leq: ground(); break;
   case gtr: ground(); break;
   case geq: ground(); break;
   case callsym: break;
   case branch₋goto₋optsym: break;
   case elsesym: assign(item->sequence); break;
   case thensym: assign(item->sequence); break;
   case ifsym: assign(item->sequence); break;
   case afterward: assign(item->r); break;
   case constsym: assign(item->const₋machineºª); break;
   case varsym: assign(item->recollectºª); break;
   case procsym: assign(item->machineºª); break;
   case oddsym: assign(item->sequence); break;
   case end₋of₋transmission₋and₋file: break;
   default: error(3,"unknown symbol-type at assign"); break;
   }
   item=item->nextºª; goto again;
}

