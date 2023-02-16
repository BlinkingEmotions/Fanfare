/*  µ⃝-code-and-tree.cxx | abstract syntax tree construction. */

struct dynamic₋bag * new₋Identifier(Nonabsolute token)
{
   struct dynamic₋bag * nonode = Alloc(sizeof(struct dynamic₋bag));
   struct dynamic₋bag init = {.T=ident,.X.kind=1,.X.store.regular=token};
   *nonode = init;
   return nonode;
}

struct dynamic₋bag * new₋Numeric(struct token₋detail item, int type)
{
   struct dynamic₋bag * nonode = Alloc(sizeof(struct dynamic₋bag));
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

struct dynamic₋bag * new₋Expression(struct dynamic₋bag * left, struct 
 dynamic₋bag * right, enum symbol₋class op)
{
   struct dynamic₋bag *node = Alloc(sizeof(struct dynamic₋bag));
   struct dynamic₋bag init = {.T=op,.form.l=left,.form.r=right};
   *node = init;
   return node;
}

struct dynamic₋bag * new₋Unary(struct dynamic₋bag * item, enum 
 symbol₋class op)
{
   struct dynamic₋bag *node = Alloc(sizeof(struct dynamic₋bag));
   struct dynamic₋bag init = {.T=op,.form.element=item};
   *node=init;
   return node;
}

struct dynamic₋bag * new₋Statement(enum symbol₋class type)
{
   struct dynamic₋bag *node = Alloc(sizeof(struct dynamic₋bag));
   struct dynamic₋bag init = {.T=type,.form.sequence₋last=ΨΛΩ,.form.sequenceºª=ΨΛΩ};
   *node=init;
   return node;
}

struct dynamic₋bag * new₋User(Nonabsolute symbol, struct dynamic₋bag * 
 actual₋and₋detail)
{
   struct dynamic₋bag *node = Alloc(sizeof(struct dynamic₋bag));
   struct dynamic₋bag init = { .T=procsym, .X.kind=1, .X.store.regular=symbol };
   *node=init;
   return node;
}

struct dynamic₋bag * new₋Intrinsic(Nonabsolute symbol, struct dynamic₋bag * 
 actual₋and₋detail)
{
   struct dynamic₋bag *node = Alloc(sizeof(struct dynamic₋bag));
   struct dynamic₋bag init = { .T=procsym, .X.kind=1., .X.store.regular=symbol };
   *node=init;
   return node;
}

/* registers 'sems' = '/' possibly-maybe '⁄' and 'allterna' = 'µ' */

void print₋datatree(int brk, struct dynamic₋bag * item)
{ int i=0;
again:
   if (i>=brk) { goto unagain; }
   print("⬚ at 0x⬚: { l:⬚ r:⬚ elem:⬚ seq:⬚ { ⬚ else ⬚ } { ⬚ with (⬚) } procs:⬚ var:⬚ } and '⬚'\n", 
    ﹟d(item->T),﹟ref(item), 
    ﹟ref(item->form.l),﹟ref(item->form.r), 
    ﹟ref(item->form.element),﹟ref(item->form.sequenceºª), 
    ﹟ref(item->form.compare₋thenºª),﹟ref(item->form.compare₋elseºª), 
    ﹟ref(item->form.detailsºª),﹟ref(item->form.formalºª), 
    ﹟ref(item->form.machineºª),﹟ref(item->form.recollectºª), 
    ﹟identifier(item->X.store.regular));
   i+=1; goto again;
unagain:
   return;
}

void print₋tree(struct dynamic₋bag * item)
{
   typedef void (^Print)(char *);
   typedef void (^Detail)(struct dynamic₋bag * item);
   typedef void (^Every)(struct dynamic₋bag *, Detail);

   Print infix = ^(char * operation) { for (int i=0; i<indentation; i+=1) { print(" "); } 
    indentation+=1; print₋tree(item->l); indentation+=-1; 
    print("⬚ @⬚\n",﹟s7(operation),﹟d((__builtin_int_t)item->memory)); indentation+=2; 
    print₋tree(item->r); indentation+=-1; };
   Every each = ^(struct dynamic₋bag * item₋first, Detail detail) { 
    struct dynamic₋bag * i=item₋first; for (;i;i=i->nextºª) { detail(i); } };
   Detail detail = ^(struct dynamic₋bag * item) { print₋tree(item); };
   switch (item->T)
   {
   case ident: print("ident '⬚' @⬚\n", ﹟ident(item->X.store.regular),﹟d((__builtin_int_t)item->memory)); break;
   case number: print("number '⬚' @⬚\n", ﹟d(item->X.store.integer), ﹟d((__builtin_int_t)item->memory)); break;
   case times: infix("times"); break;
   case divide: infix("divide"); break;
   case plus: infix("plus"); break;
   case minus: infix("minus"); break;
   case eql: infix("eql"); break;
   case neq: infix("neq"); break;
   case lss: infix("lss"); break;
   case leq: infix("leq"); break;
   case gtr: infix("gtr"); break;
   case geq: infix("geq"); break;
   case callsym: print("call '⬚'\n", ﹟ident(item->X.store.regular)); break;
   case branch₋goto₋optsym: print("branch ⬚\n", ﹟ident(item->X.store.regular)); break;
   case ifsym: print("compare\n"); indentation+=1; print₋tree(item->compare₋then); 
    print₋tree(item->compare₋else); indentation+=-1; break;
   case afterward: print("afterward @⬚\n", ﹟d((__builtin_int_t)item->memory)); indentation+=1; 
    print₋tree(item->l); if (item->r) print₋tree(item->r); else print("<unassigned>\n"); break;
   case constsym: print("constsym\n"); each(item->sequence,detail); break;
   case varsym: print("varsym\n"); each(item->sequence,detail); break;
   case procsym: print("procsym '⬚'\n", ﹟ident(item->X.store.regular)); 
    indentation+=1; each(item->formal,detail); print("\n"); 
    each(item->detail,detail); indentation+=-1; break;
   default: { print("unknown item with symbol-type '⬚'\n", ﹟d((__builtin_int_t)item->T)); }
   }
}

void House(int type, int count, ...)
{ va_prologue(count) typedef struct dynamic₋bag * refers; /* refer-en-ce = auto *. A․𝘬․a 'biblio' and 'redux'. */
   switch (type)
   {
   case 🅐: { Nonabsolute token = va_unqueue(Nonabsolute);
    form = new₋Identifier(token); break; }
   case 🅑: { struct token₋detail item = va_unqueue(struct token₋detail);
    int type = va_unqueue(int);
    form = new₋Numeric((struct token₋detail)item,1); break; }
   case 🅒: { void * left = va_unqueue(struct dynamic₋bag *);
    void * right = va_unqueue(struct dynamic₋bag *);
    enum symbol₋class op = va_unqueue(enum symbol₋class);
    form = new₋Expression((struct dynamic₋bag *)left,(struct dynamic₋bag *)right,op);
    break; }
   case 🅔: { Nonabsolute left = va_unqueue(Nonabsolute);
    void * right = va_unqueue(struct dynamic₋bag *);
    form = new₋Statement(additionssym);
    form->l = new₋Identifier(left);
    form->r = (struct dynamic₋bag *)right;
    break; }
   case 🅕: { Nonabsolute identity = va_unqueue(Nonabsolute);
    void * right = va_unqueue(struct dynamic₋bag *);
    form = new₋Statement(afterward);
    form->l = new₋Identifier(identity);
    form->r = right;
    break; }
   case 🅖: { Nonabsolute callee = va_unqueue(Nonabsolute);
    form = new₋Identifier(callee);
    form->T = callsym;
    break; }
   case 🅗: { void * unit = va_unqueue(struct dynamic₋bag *);
    form = (struct dynamic₋bag *)unit;
    break; }/* statement list */
   case 🅙: { void * condition = va_unqueue(struct dynamic₋bag *);
    void * compare₋then = va_unqueue(struct dynamic₋bag *);
    void * compare₋else = va_unqueue(struct dynamic₋bag *);
    form = new₋Statement(ifsym);
    form->compare₋then = compare₋then;
    form->compare₋else = compare₋else;
    break; } /* condition */
   case 🅛: { Nonabsolute uni₋vers = va_unqueue(Nonabsolute);
    void * serpent = va_unqueue(struct dynamic₋bag *);
    form = new₋Statement(afterward);
    form->l = new₋Identifier(uni₋vers);
    form->r = serpent;
    break; }
   case 🅝: { Nonabsolute identifier = va_unqueue(Nonabsolute);
    void * arg₋u₋men = va_unqueue(struct dynamic₋bag *);
    form = new₋Statement(afterward);
    form->l = new₋Identifier(identifier);
    form->r = arg₋u₋men;
    break; }
   case 🅟: { Nonabsolute sy = va_unqueue(Nonabsolute);
    void * parameters = va_unqueue(struct dynamic₋bag *);
    void * detail = va_unqueue(struct dynamic₋bag *);
    form = new₋Userfunction(sy,(struct dynamic₋bag *)parameters,(struct dynamic₋bag *)detail);
    break; } /* details found in tree and compilation unit. */
   case 🅠: { refers tree = va_unqueue(struct dynamic₋bag *);
    refers reads = va_unqueue(struct dynamic₋bag *);
    if (tree->const₋machineºª==ΨΛΩ) { tree->const₋machineºª=reads; }
    else { reads->prev=tree->art->last; if (tree->art->last) tree->art->last->next=reads; tree->art->last=reads; }
    break; } /* computed and expressed constants. */
   case 🅡: { refers tree = va_unqueue(struct dynamic₋bag *);
    refers reads = va_unqueue(struct dynamic₋bag *);
    if (tree->recollectºª==ΨΛΩ) { tree->recollectºª=reads; }
    else { reads->prev=tree->var->last; if (tree->var->last) tree->var->last->next=reads; tree->var->last=reads; }
    break; } /* variables. */
   case 🅢: { Nonabsolute name = va_unqueue(Nonabsolute);
    refers tree = va_unqueue(struct dynamic₋bag *);
    refers table = va_unqueue(struct dynamic₋bag *);
    form = new₋Intrinsicfunction(name,(struct dynamic₋bag *)tree, (struct dynamic₋bag *)table);
    break; } /* uses runtime with no explicit details. */
   case 🅣: { /* new_Usercall */
    break; }
   case 🅩: { refers tree = va_unqueue(struct dynamic₋bag *);
    refers reads = va_unqueue(struct dynamic₋bag *);
    if (tree->machineºª == ΨΛΩ) { tree->machineºª=reads; }
    else { reads->prev=tree->last₋machine; if (tree->last₋machine) tree->pct->last->next=reads; tree->pct->last=reads; }
    break; } /* procedures and functions. */
   }
   va_epilogue
}

