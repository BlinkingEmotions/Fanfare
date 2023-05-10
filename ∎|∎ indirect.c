/*  ∎|∎ indirect.c | dynamic pointer. */

#include "twinbeam.h"

typedef struct { __builtin_uint_t address,bytes; } refers;

void load(int * value, refers * ref) ⓣ { ref->address = (__builtin_uint_t)value; ref->bytes=sizeof(int); }
void dereference(refers ref, int * value) ⓣ { *value = *(int *)(ref.address); }

void foo(refers input, void (^completion)(refers output))
{
   completion(input);
}

int main(int argc, char * argv[])
{
   int value1=17; refers indirect1;
   load(&value1,&indirect1);
   foo(indirect1, ^(refers output) { /* const */ int value2;
     dereference(output,&value2);
     print("value2 is ⬚. size is ⬚\n", ﹟x((__builtin_uint_t)value2), ﹟x((__builtin_uint_t)output.bytes));
   }); 
}

/*   clang -g -I../Apps/ '∎|∎ indirect.c' ../Apps/Source/Releases/libTwinbeam-x86_64.a */

