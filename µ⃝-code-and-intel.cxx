/*  µ⃝-code-and-intel.cxx | (fine-)print assembly for Intel x86-64. */

#define MACHINE₋TYPE    1 /* Binary32 alternatively binary64 a․𝘬․a 'Machine'. */
#define REAL₋TYPE       2 /* Float32 alternatively float64 a․𝘬․a 'Real'. */
#define UNICODE₋TYPE    3 /* Binary32 a․𝘬․a 'Unicode' and char32̄_t. */
#define UTF8₋TYPE       4 /* Binary8 a․𝘬․a 'Utf₋8' and char8₋t. */
#define REFERS₋TYPE     5 /* 'pointer' a․𝘬․a 'Indirect reference'. */
#define SIMDRx2₋TYPE    7 /* four float64 a․𝘬․a simd_tᵦ. */
#define BINARY128₋UTYPE 8 /* signed long long integer. */
#define BINARY128₋STYPE 9 /* unsigned long long integer. */

void typename₋to₋type(Nonabsolute typename, short * fundamen)
{
   *fundamen = MACHINE₋TYPE; /* union-find and makeset(binary128), find(binary128), and union(binary128, binary128) */
   binary128 root = SHA256(U"MACHINE-TYPE");
   binary128 query = SHA256(typename);
   binary128 base = find(query);
   switch (base) {
   case 0x123456789ABCDEFull: break;
   default: vfprint("unknown fundamental type.\n"); break;
   }
}

int signature(bagref transcript, int * count, short ** signature)
{  
   if (transcript->T != procsym) return -1;
   int cnt=elem₋count(transcript->form.formalºª);
   *count = cnt;
   *signature = Alloc(cnt*sizeof(short));
   recollect(^(bagref formal,int index) { 
     short fundamen;
     Nonabsolute name = formal->X.store.regular;
     typename₋to₋type(name,&fundamen);
     *(*signature + index) = fundamen;
   },transcript->form.formalºª);

   return 0;
}

Argᴾ ﹟intel₋passed(int count, short signature[], short left₋to₋right)
{ char * regset1[] = { "rdi","rsi","rdx","rcx","r8","r9" }, * regset2[] = { 
    "xmm0","xmm1","xmm2","xmm3","xmm4","xmm5","xmm6","xmm7" };
   short idx₋integer=0,idx₋real=0,type; __builtin_int_t i=0;
   Serialfragment element = ^(serial₋present u8out, void * ctxt) {
    char8₋t * text = (char8₋t *)ctxt; __builtin_int_t count = 
    Utf8BytesUntilZero(text,BUILTIN₋INT₋MAX); u8out(text,count); };
   Serialfragment indexed = ^(serial₋present u8out, void * ctxt) {
    char8₋t * prefix=U8("[rbp+8*"), *suffix=U8("+16]");
    u8out(prefix,7); Base𝕟((__builtin_uint_t)ctxt,10,0, ^(char c) { 
     u8out((char8₋t *)&c,1); }); u8out(suffix,4);
   };
again:
   type = signature[i];
   if (i == left₋to₋right-1) {
     if (type == MACHINE₋TYPE && idx₋integer <= 5) return ﹟λ₁(element,regset1[idx₋integer]);
     if (type == REAL₋TYPE && idx₋real <= 7) return ﹟λ₁(element,regset2[idx₋real]);
     else { return ﹟λ₁(indexed,(void *)i); }
   }
   if (type == MACHINE₋TYPE) { idx₋integer+=1; }
   if (type == REAL₋TYPE) { idx₋real+=1; }
   i+=1; goto again;
}

Argᴾ ﹟intel₋automatic₋mask(int count, short signature[])
{ char8₋t * prefix=U8("subl rsp, "), *suffix=U8(" /* move stack pointer to include new automatic. */");
   Serialfragment three = ^(serial₋present u8out, void * ctxt) { u8out(prefix,9); 
   Base𝕟((__builtin_uint_t)ctxt,10,0, ^(char c) { u8out((char8₋t *)&c,1); });
    u8out(suffix,51); };
   short type; __builtin_int_t acc,i=0;
   void * ctxt = (void *)0;
again:
   type = signature[i];
   if (i == count) { ctxt=(void *)acc; return ﹟λ₁(three,ctxt); }
   if (type == MACHINE₋TYPE) { acc+=4; }
   if (type == REAL₋TYPE) { acc+=4; }
   i+=1; goto again;
}

Argᴾ ﹟intel₋automatic₋reference(int count, short signature[], short 
 top₋to₋bottom)
{ char8₋t * prefix=U8("[rbp-8-"), *suffix=U8("]");
   Serialfragment three = ^(serial₋present u8out, void * ctxt) { u8out(prefix,7); 
    Base𝕟((__builtin_uint_t)ctxt,10,0,^(char c) { u8out((char8₋t *)&c,1); });
    u8out(suffix,1); };
   short type; __builtin_int_t offset=0,i=0;
again:
   type = signature[i];
   if (i == top₋to₋bottom - 1) { return ﹟λ₁(three,(void *)offset); }
   i+=1; goto again;
} /* in at&t: '-4(ebp)' and referenced as negative offset relative rbp. */

Argᴾ ﹟intel₋call₋coalesc(short passing, int is₋128₋bits, char * src₋opt, 
 char * src₋mandatory)
{ char8₋t * integer₋lsb=U8("movq rax, "), *real₋lsb=U8("movq xmm0, "), 
    *integer₋msb=U8("movq rdx, "), *real₋msb=U8("movq xmm1, ");
   Serialfragment two = ^(serial₋present u8out, void * ctxt) {
    if (passing == MACHINE₋TYPE) { u8out(integer₋lsb,3); }
    if (passing == REAL₋TYPE) { u8out(real₋lsb,3); }
    if (is₋128₋bits && passing == MACHINE₋TYPE) { u8out(integer₋msb,3); }
    if (is₋128₋bits && passing == REAL₋TYPE) { u8out(real₋msb,3); }
   };
   void * ctxt = (void *)0;
   return ﹟λ₁(two,ctxt);
} /* the 'rdx' is used on 128-bit integer returns. (and for 'real' xmm0 and secondarily xmm1) */

char * registers[] = { "rax", "r15", "r14", "r13", "r12", "rbx", "rbp", "r9", 
 "r8", "rcx", "rdx", "rsi", "rdi" };

char ** requisi₋automat(int count)
{ 
   return &registers[13-count];
}

char * requisi₋signature(short item) { return registers[item]; }

int requisi₋redundant(struct dynamic₋bag * item, char **item1, char **item2)
{
   switch (item->T)
   {
   case times:
   case divide:
   case plus:
   case minus:
     *item1=requisi₋signature(item->form.l->memory);
     *item2=requisi₋signature(item->form.r->memory);
     return 0;
   default: error(4,"unknown operation found while allocating registers");
   }
   return -1;
}

void generate₋arithmetic(struct dynamic₋bag * item)
{
   print(
"    "
   );
   switch (item->T)
   {
   case times: print("imul"); break;
   case divide: print("idiv"); break;
   case plus: print("add"); break;
   case minus: print("sub"); break;
   default: error(4,"unknown arithmetic operation"); break;
   }
   char *r1,*r2;
   if (requisi₋redundant(item,&r1,&r2)) { error(4,"unknown arithmetic rendition in assembly"); }
   print(" ⬚,⬚\n",﹟s7(r1),﹟s7(r2));
   if (item->memory != item->form.r->memory) {
     char * dst = requisi₋signature(item->memory);
     print("mov ⬚,⬚\n",﹟s7(r2),﹟s7(dst));
  }
}

void generate₋logic(struct dynamic₋bag * item, enum symbol₋class type)
{
   print(
"    "
   );
   switch (type)
   {
   case logical₋alternate: print("xor"); break;
   case logical₋and: print("and"); break;
   case logical₋or: print("or"); break;
   default: error(4,"unknown logical operation"); break;
   } char *r1,*r2;
   if (requisi₋redundant(item,&r1,&r2)) { error(4,"unknown logic rendition in assembly"); }
   print(" ⬚,⬚\n",﹟s7(r1),﹟s7(r2));
   if (item->memory != item->form.r->memory) {
      char * dst = requisi₋signature(item->memory);
      print("mov ⬚,⬚\n",﹟s7(r2),﹟s7(dst));
   }
}

void generate₋cast(struct dynamic₋bag * widen)
{
   print(
"     cwb,cwde,cwd,cdq\n"
   );
}

void generate₋assign(struct dynamic₋bag * becomes)
{
   print(
"    mov rdi, rax\n" /* rdi becomes rax. */
   );
}

void generate₋condition(struct dynamic₋bag * select)
{ struct guid ident=Guid(); 
   print(
"    testq rax,rax\n"
"    jz sometime₋⬚\n"
"sometime₋⬚:\n",
   ﹟leap(ident),﹟leap(ident));
   print(
"either₋⬚:\n",
   ﹟leap(ident));
}

void generate₋loop(struct dynamic₋bag * etery)
{ struct guid ident=Guid(); 
   print(
"⬚:\n"
"    jmp ⬚\n",﹟leap(ident),﹟leap(ident));
}

void preserve(int restore, int count, ...)
{ char * register₋name,*registers[count]; int i=0;
   va_prologue(count)
again:
   if (i >= count) goto unagain;
   register₋name = va_unqueue(char *);
   if (restore) {
     registers[count-i-1]=register₋name;
    }
   else { print(
"      push   ⬚\n",﹟s7(register₋name)
   ); }
   i+=1; goto again;
unagain:
   if (restore) { for (i=0; i<count; i+=1) {
     print(
"      pop    ⬚\n",﹟s7(registers[i])
   );
   } }
   va_epilogue
}

void generate₋call(struct dynamic₋bag * called₋to₋recieve)
{ Nonabsolute ref = called₋to₋recieve->X.store.regular;
   preserve(0,7,"rbx","rsp","rbp","r12","r13","r14","r15"); /* preserve caller-save registers before call. */
   int parameter₋count=8,is₋vararg=1;
   if (parameter₋count > 6) {
     print(
"    pushq eight             /* more than six registers in prototype. */\n"
"    pushq seventh\n"
     );
   }
   print("mov al,13"); /* variable number of arguments. */
   print(
"    call  ⬚                /* push the address of the next instruction onto the stack and transfer control. */n",
   ﹟ident(ref));
   /* caller cleans up the stack. ...and */
   preserve(1,7,"rbx","rsp","rbp","r12","r13","r14","r15"); /* restore caller-save registers after call. */
}

void generate₋store()
{
   print(
"\n      .section __DATA,__data\n" /* initialized and placed in object file. */
"\n      .comm _abc4,8\n"
"\n      .bss\n" /* uninitialized and placed in ram. */
"\nabc3: .fill 1,8,0\n" /* three parameters repeat, size, value. */
"\n      .section __TEXT,__rodata\n" /* initialization for global and static. */
"\nabc1: .asciz \"\41\42\43 \"\n"
"\nabc2: .long 0x41,0x44,0\n"
   );
}

void generate₋unit()
{
   print(
"/*  assembly.S | compiled material. */\n"
"#define END(symbol)\n"
"#define START(symbol)\n"
   );
   generate₋store();
   print(
"\n      .section __TEXT,__text\n\n"
   );
   struct dynamic₋bag * material; Nonabsolute symbol;
   struct dynamic₋bag₋cons *cell₋machine=td₋tree->form.machineºª,*statement₋cell;
function₋again:
   if (cell₋machine == 0) goto function₋unagain;
   material = cell₋machine->item;
   if (material==0) error(99,"unable to form abstract syntax");
   symbol = material->X.store.regular;
   print(
"\n      .globl _⬚\n"
"      .intel_syntax\n"
"      START(_⬚)\n"
"_⬚:\n",﹟ident(symbol),﹟ident(symbol),﹟ident(symbol),﹟ident(symbol));
   print(
"      push   rbp               /* store frame pointer in stack. */\n"
"      mov    rsp,rbp           /* assign 'rbp' to 'rsp'. */\n"
"      sub    rsp,24            /* stack pointer points to top of frame. */\n"
   );
   /* preserve and restore the listed registers exercised in this 'material' function. */
   preserve(0,7,"rbx","rsp","rbp","r12","r13","r14","r15"); /* preserve calle-save registers. */
   /* scratch registers are rax,rdi,rsi,rdx,rcx,r8,r9,r10,r11. */
   /* rdi, rsi, rdx, rcx, r8, r9 and for floating points xmm0 - xmm7 then right to left pushed. */
   /* the registers must be preserved before calling is made. */
   short signature[] = { MACHINE₋TYPE, MACHINE₋TYPE, MACHINE₋TYPE };
   print(
"      mov    [rbp-8], ⬚      /* frame pointer finds address to material 'automatic' in frame. */\n", 
   ﹟intel₋passed(3, signature, 1));
   /* use up to 128 bytes below 'rsp' (on macos coined 'the red-area'). */
   statement₋cell = material->form.sequenceºª;
statement₋again:
   if (statement₋cell == 0) goto statement₋unagain;
   print(
"      mov    rax, 17           /* real statement. */\n"
   );
   statement₋cell = statement₋cell->nxt.next; goto statement₋again;
statement₋unagain:
   print(
"      mov    rax, 13           /* return integer in 'rax'. */\n"
   );
   preserve(1,7,"rbx","rsp","rbp","r12","r13","r14","r15"); /* restore callee-save registers. */
   print(
"      mov    rbp, rsp          /* dealloc automatic variables. */\n"
"      pop    rbp               /* restore frame pointer from stack. */\n"
"      ret\n" /*  if 'lexical nesting on intel x86-64' see 'enter', 'leave' and 'ret'. */
"      END(_⬚)\n", 
   ﹟ident(symbol));
   /* item = item->form.next₋machineºª; */
   cell₋machine = cell₋machine->nxt.next; goto function₋again;
function₋unagain:
   print("/* (end compiled material.) */\n");
} /* rbp points to the base of the current stack frame and contains the saved 
 'rbp' 
 |
 |
 |---------| 16-byte aligned address.
 |         |
 |         | $rbp+8n+16 argument 'n'.
 |   ...   | ...
 |         | $rbp+16    argument 7.
 |         | $rbp+8     return address.
 |  stack  | $rbp±0     previous $rbp value.
 |   ...   | $rbp-8     first automatic if all parameters passed in registers.
 |         | $rbp-16
 |         | $rsp       top of the stack.
 |         | 128-bytes red-zone $rsp-128 to $rsp-8.
 |---------|
 |   heap  |
 |---------|
 |         |
 |  .text  | code and global- and static initial values.
 |         |
 |---------|
 |  .bss   | globals not having initial value.
 |---------|
 |  .data  | inited globals and static variables (also inited).
 |---------|
 |
 |
 */

/* clang -S util.c for util.s */

/* ./a.out | clang -c -x assembler - -o - */
/* ▚ ld -arch x86_64 /dev/stdin */ /* not-possible random-access required. */

