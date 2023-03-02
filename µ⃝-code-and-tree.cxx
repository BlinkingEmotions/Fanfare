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
   struct dynamic₋bag init = {.T=procsym,.X.kind=1,.X.store.regular=symbol};
   *node=init;
   return node;
}

bagref new₋Unit()
{
   bagref node = Alloc(sizeof(struct dynamic₋bag));
   return node;
}

bagref new₋AbelianZero()
{
   bagref node = Alloc(sizeof(struct dynamic₋bag));
   struct dynamic₋bag init = {.T=unarbitrated₋symbol,.X.kind=2};
   *node=init;
   return node;
}

void Expression(int type, int count, ...)
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
   case 🅓: {
    consref params = va_unqueue(consref);
    consref params₋last = va_unqueue(consref);
    bu₋fragment->form.sequenceºª = params;
    bu₋fragment->form.sequence₋last = params₋last;
    break; }
   }
   va_epilogue
}

void Statement(int type, int count, ...)
{ va_prologue(count)
   switch (type)
   {
   case 🅔🅔: { Nonabsolute left = va_unqueue(Nonabsolute);
    bagref right = va_unqueue(bagref);
    bu₋fragment = new₋Statement(additionssym);
    bu₋fragment->form.l = new₋Identifier(left);
    bu₋fragment->form.r = right;
    break; }
   case 🅕🅣: {
    Nonabsolute called = va_unqueue(Nonabsolute);
    bagref params = va_unqueue(bagref);
    bu₋fragment = new₋Identifier(called);
    bu₋fragment->form.sequenceºª = params->form.sequenceºª;
    bu₋fragment->form.sequence₋last = params->form.sequence₋last;
    break; } /* function defined in 'compilation-unit'. */
   case 🅖🅕: { Nonabsolute identity = va_unqueue(Nonabsolute);
    bagref right = va_unqueue(bagref);
    bu₋fragment = new₋Statement(afterward);
    bu₋fragment->form.l = new₋Identifier(identity);
    bu₋fragment->form.r = right;
    break; }
   case 🅗🅖: { Nonabsolute called = va_unqueue(Nonabsolute);
    bu₋fragment = new₋Identifier(called);
    bu₋fragment->form.sequenceºª=0;
    bu₋fragment->form.sequence₋last=0;
    break; }
   case 🅘🅦: {
    bagref statement₋to₋append = va_unqueue(bagref);
    consref ftail = td₋tree->form.machine₋last;
    if (retail(^(struct dynamic₋bag * material) {
      *material = *statement₋to₋append;
    },&ftail->item->form.sequenceºª,&ftail->item->form.sequence₋last)) {
      Pult(areel.retail₋failure); return; }
    break; }
    case 🅙🅗: { bagref fragment₋statementºª = va_unqueue(bagref);
     td₋tree->form.machine₋last->item->form.sequence₋last = fragment₋statementºª->form.sequenceºª;
     break; } /* statement list */
   case 🅚🅙: { void * condition = va_unqueue(bagref);
    void * compare₋then = va_unqueue(consref);
    void * compare₋else = va_unqueue(consref);
    bu₋fragment = new₋Statement(comparesym);
    bu₋fragment->form.compare₋thenºª = compare₋then;
    bu₋fragment->form.compare₋elseºª = compare₋else;
    break; } /* condition */
   }
   va_epilogue
}

void Section(int type, int count, ...)
{ va_prologue(count)
   switch (type)
   {
   case 🅛1: { Nonabsolute uni₋vers = va_unqueue(Nonabsolute);
    void * argument₋serpent = va_unqueue(bagref);
    bu₋fragment = new₋Statement(afterward);                              /* 'global' key. */
    bu₋fragment->form.l = new₋Identifier(uni₋vers);
    bu₋fragment->form.r = argument₋serpent;
    break; } /* computed alternatively variable. */
   case 🅛2: { bagref circul = va_unqueue(bagref);
    consref * firstref = va_unqueue(consref *);
    consref * lastref = va_unqueue(consref *);
    if (retail(^(struct dynamic₋bag * material) {
      *material = *circul;                     /* a․𝘬․a 'Copy8Memory'. 'shadow-hallow' */
    },firstref,lastref)) {
      Pult(areel.retail₋failure); return; }                    /* not to be 'overlay'. */
    break; } /* computed alternatively variable. */
   case 🅝: { Nonabsolute uninit₋univers = va_unqueue(Nonabsolute); 
    bu₋fragment = new₋Statement(afterward);
    bu₋fragment->form.l = new₋Identifier(uninit₋univers);
    bu₋fragment->form.r = new₋AbelianZero();
    break; } /* uninited variable. */
   case 🅡0: { Nonabsolute symbol = va_unqueue(Nonabsolute);
    /* print("retailing function named '⬚'\n",﹟ident(symbol)); */
    if (retail(^(struct dynamic₋bag * material) {
      struct dynamic₋bag init = {.T=procsym,.X.kind=1,.X.store.regular=symbol};
      *material = init;
    },&td₋tree->form.machineºª,&td₋tree->form.machine₋last)) {
      Pult(areel.retail₋failure); return; }
    break; } /* ensures a 'User'-ast at 'td₋tree->machine₋last'. */
   case 🅡1: {
    bagref formal = va_unqueue(bagref);
    bagref detail = va_unqueue(bagref);
    td₋tree->form.machine₋last->item->form.detailsºª = detail->form.detailsºª;
    td₋tree->form.machine₋last->item->form.details₋last = detail->form.details₋last;
    td₋tree->form.machine₋last->item->form.formalºª = formal->form.formalºª;
    td₋tree->form.machine₋last->item->form.formal₋last = formal->form.formal₋last;
    break; } /* connect formal and detail to last added 'User'-function. */
   case 🅡2: { void * reads_function_and_paramlist = va_unqueue(bagref);
    break; } /* attach 'procedures' and 'functions' to tree. */
   }
   va_epilogue
}

void Serpent₋schema(Nonabsolute name, struct dynamic₋bag * matrix, int columns)
{
   vfprint("attempt to create association\n");
/*   bu₋fragment = new₋Identifier(name);
   bu₋fragment->form.sequenceºª=params->form.sequenceºª;
   bu₋fragment->form.sequence₋last=params->form.sequence₋last; */
}

void House(int type, int count, ...)
{ va_prologue(count)
   switch (type)
   {
   case 🅚: { void * formalºª = va_unqueue(consref);
     void * formal₋last = va_unqueue(consref);
     bu₋fragment->form.formalºª=formalºª;
     bu₋fragment->form.formal₋last=formal₋last;
     break; }; /* binds formal parameter list first and last to fragment. */
   }
   va_epilogue
} /*  A․𝘬․a 'biblio' and 'redux'. */

