/*  µ⃝-code-and-tree.cxx | abstract syntax tree construction. */

bagref new₋Identifier(Nonabsolute token)
{
   bagref nonode = Alloc(sizeof(struct dynamic₋bag));
   struct dynamic₋bag init = {.T=ident,.X.kind=1,.X.store.regular=token};
   *nonode = init;
   return nonode;
}

bagref new₋Numeric(struct token₋detail item, int type)
{
   bagref nonode = Alloc(sizeof(struct dynamic₋bag));
   nonode->T=number;
   switch (type)
   {
   case 1:
    nonode->X.store.number=item.store.number;
    nonode->X.kind=2;
    break;
   case 2:
    nonode->X.store.integer=item.store.integer;
    nonode->X.kind=3;
    break;
   }
   return nonode;
}

bagref new₋Expression(bagref left, bagref right, enum symbol₋class op)
{
   bagref node = Alloc(sizeof(struct dynamic₋bag));
   struct dynamic₋bag init = {.T=op,.form.l=left,.form.r=right};
   *node = init;
   return node;
}

bagref new₋Unary(bagref item, enum symbol₋class op)
{
   bagref node = Alloc(sizeof(struct dynamic₋bag));
   struct dynamic₋bag init = {.T=op,.form.element=item};
   *node=init;
   return node;
}

bagref new₋Statement(enum symbol₋class type)
{
   bagref node = Alloc(sizeof(struct dynamic₋bag));
   struct dynamic₋bag init = {.T=type,.form.sequence₋last=ΨΛΩ,.form.sequenceºª=ΨΛΩ};
   *node=init;
   return node;
}

bagref new₋User(Nonabsolute symbol)
{
   bagref node = Alloc(sizeof(struct dynamic₋bag));
   struct dynamic₋bag init = {.T=procsym,.X.kind=1,.X.store.regular=symbol};
   *node=init;
   return node;
}

bagref new₋Intrinsic(Nonabsolute symbol)
{
   bagref node = Alloc(sizeof(struct dynamic₋bag));
   struct dynamic₋bag init = {.T=procsym,.X.kind=1.,.X.store.regular=symbol};
   *node=init;
   return node;
}

bagref new₋Unit()
{
   bagref node = Alloc(sizeof(struct dynamic₋bag));
   return node;
}

void House(int type, int count, ...)
{ va_prologue(count)
   switch (type)
   {
   case 🅐: { Nonabsolute token = va_unqueue(Nonabsolute);
    bu₋fragment = new₋Identifier(token); break; }
   case 🅑: { struct token₋detail item = va_unqueue(struct token₋detail);
    int type = va_unqueue(int);
    bu₋fragment = new₋Numeric((struct token₋detail)item,1); break; }
   case 🅒: { bagref left = va_unqueue(bagref);
    bagref right = va_unqueue(bagref);
    enum symbol₋class op = va_unqueue(enum symbol₋class);
    bu₋fragment = new₋Expression(left,right,op);
    break; }
   case 🅔: { Nonabsolute left = va_unqueue(Nonabsolute);
    bagref right = va_unqueue(bagref);
    bu₋fragment = new₋Statement(additionssym);
    bu₋fragment->form.l = new₋Identifier(left);
    bu₋fragment->form.r = right;
    break; }
   case 🅒2: {
    consref params = va_unqueue(consref);
    consref params₋last = va_unqueue(consref);
    bu₋fragment->form.sequenceºª = params;
    bu₋fragment->form.sequence₋last = params₋last;
    break; }
   case 🅣: {
    Nonabsolute called = va_unqueue(Nonabsolute);
    bagref params = va_unqueue(bagref);
    bu₋fragment = new₋Identifier(called);
    bu₋fragment->form.sequenceºª = params->form.sequenceºª;
    bu₋fragment->form.sequence₋last = params->form.sequence₋last;
    break; } /* function defined in 'compilation-unit'. */
   case 🅕: { Nonabsolute identity = va_unqueue(Nonabsolute);
    bagref right = va_unqueue(bagref);
    bu₋fragment = new₋Statement(afterward);
    bu₋fragment->form.l = new₋Identifier(identity);
    bu₋fragment->form.r = right;
    break; }
   case 🅖: { Nonabsolute called = va_unqueue(Nonabsolute);
    bu₋fragment = new₋Identifier(called);
    bu₋fragment->form.sequenceºª=0;
    bu₋fragment->form.sequence₋last=0;
    break; }
   case 🅦: { bagref base = va_unqueue(bagref);
            /*
    bagref circul = va_unqueue(bagref);
    if (retail(^(struct dynamic₋bag * material) {
      *material = *circul;
    },&unit->form.sequenceºª,&unit->form.sequence₋last)) {
      Pult(areel.retail₋failure); return; }
    fragment = unit; */
    break; }
 //  case 🅗: { bagref fragment₋statementºª = va_unqueue(bagref);
 //   tree->form.machine₋last->item->form.sequence₋last = fragment₋statementºª->form.sequenceºª;
 //   break; } /* statement list */
/*   case 🅙: { void * condition = va_unqueue(bagref);
    void * compare₋then = va_unqueue(consref);
    void * compare₋else = va_unqueue(consref);
    fragment = new₋Statement(comparesym);
    fragment->form.compare₋thenºª = compare₋then;
    fragment->form.compare₋elseºª = compare₋else;
    break; } / * condition * /
   case 🅚: { void * formalºª = va_unqueue(consref);
     void * formal₋last = va_unqueue(consref);
     fragment->form.formalºª=formalºª;
     fragment->form.formal₋last=formal₋last;
     break; }; / * binds formal parameter list first and last to fragment. * /
   case 🅛1: { Nonabsolute uni₋vers = va_unqueue(Nonabsolute);
    void * serpent = va_unqueue(bagref);
    fragment = new₋Statement(afterward);                              / * 'global' key. * 
    fragment->form.l = new₋Identifier(uni₋vers);
    fragment->form.r = serpent;
    break; } / * constant second time. * /
   case 🅛2: { bagref circul = va_unqueue(bagref);
    bagref unit = va_unqueue(bagref);
    if (retail(^(struct dynamic₋bag * material) {
      *material = *circul;                     / * a․𝘬․a 'Copy8Memory'. 'shadow-hallow' * /
    },&unit->form.const₋machineºª,&unit->form.constmachine₋last)) {
      Pult(areel.retail₋failure); return; }                    / * not to be 'overlay'. * /
    break; } / * computed and expressed constants. * /
   case 🅝: { Nonabsolute identifier = va_unqueue(Nonabsolute);
    void * arg₋u₋men = va_unqueue(bagref);
    fragment = new₋Statement(afterward);
    fragment->form.l = new₋Identifier(identifier);
    fragment->form.r = arg₋u₋men;
    break; }
   case 🅟: { void * tree = va_unqueue(bagref);
    void * reads = va_unqueue(bagref);
    break; } / * variables. * / */
   case 🅡1: { Nonabsolute symbol = va_unqueue(Nonabsolute);
    bagref formal = va_unqueue(bagref);
    bagref detail = va_unqueue(bagref);
    bu₋fragment = new₋User(symbol);
    bu₋fragment->form.detailsºª = detail->form.detailsºª;
    bu₋fragment->form.details₋last = detail->form.details₋last;
    bu₋fragment->form.formalºª = formal->form.formalºª;
    bu₋fragment->form.formal₋last = formal->form.formal₋last;
    break; } /* definition located in one compilation unit. */
   case 🅡2: { void * reads_function_and_paramlist = va_unqueue(bagref);
    if (retail(^(struct dynamic₋bag * material) {
      
    },&td₋tree->form.sequenceºª,&td₋tree->form.sequence₋last)) {
      Pult(areel.retail₋failure); return;
    }
    break; } /*attach 'procedures' and 'functions' to tree. */
   case 🅢: { Nonabsolute name₋table = va_unqueue(Nonabsolute);
    bagref params = va_unqueue(bagref);
    bu₋fragment = new₋Identifier(name₋table);
    bu₋fragment->form.sequenceºª=params->form.sequenceºª;
    bu₋fragment->form.sequence₋last=params->form.sequence₋last;
    break; } /* uses runtime with no details. */
   }
   va_epilogue
} /*  A․𝘬․a 'biblio' and 'redux'. */

