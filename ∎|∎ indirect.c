/*  ∎|∎ indirect.c | dynamic pointer. */

#include "twinbeam.h"

typedef struct { __builtin_uint_t address,bytes; } refers;

void load(int * value, refers ref) ⓣ { ref.address = (__builtin_uint_t)value; ref.bytes=sizeof(int); }
void dereference(refers ref, int * value) ⓣ { *value = *(int *)(ref.address); }

int foo(refers input)
{
   int value;
   dereference(input,&value);
   return value;
}

int main(int argc, char * argv[])
{
   int value1=17; refers indirect1;
   load(&value1,indirect1);
   int value2 = foo(indirect1); 
}

/*   clang -g -I../Apps/ '∎|∎ indirect.c' ../Apps/Source/Releases/libTwinbeam-x86_64.a */

