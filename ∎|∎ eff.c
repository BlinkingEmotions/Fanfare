/*  eff.c plan och konstant friktion \see centrifug, magnet och molyb tillvara. */

import Twinbeam;

#include <sys/queue.h>

/*
#define TAILQ_HEAD(name,type)                                               \
 struct name {                                                              \
   struct type *stqh_first;                                                 \
   struct type **stqh_last;                                                 \
 }
*/

struct perform {
  int a,b,c;
  STAILQ_ENTRY(perform) entries; /* instead of 'next'. */
};

struct assemblage {
  STAILQ_HEAD(distinctive1,perform) steps; /* actual single-linked list. */
}; 

struct instruction {
  int a,b,c;
  TAILQ_ENTRY(instruction) entries;
};

struct disjunct₋ops { 
  TAILQ_HEAD(distinctive2,instruction) multiple; /* actual double-linked list. */
};

int Order(void (^out)(char32̄_t *, __builtin_int_t), char32̄_t * command, ...);

int
main(
  int argc, 
  char * argv[]
)
{
   struct assemblage wrench = STAILQ_HEAD_INITIALIZER(wrench.steps);
   
   STAILQ_INIT(&wrench.steps);
   
   struct perform * step₋one = malloc(sizeof(struct perform));
   STAILQ_INSERT_HEAD(&wrench.steps,step₋one,entries);
   
   struct perform * step₋two = malloc(sizeof(struct perform));
   STAILQ_INSERT_AFTER(&wrench.steps,step₋one,step₋two,entries);
   
   struct perform * np;
   STAILQ_FOREACH(np,&wrench.steps,entries) {
     print("element");
   }

  /* if (Order(^(char32̄_t * ucs, __builtin_int_t bytes) { 
    print("response '⬚'.\n",﹟S(bytes,ucs)); }, U"ls -la '⬚' ", ﹟S(U"/"))) { return 1; } */
   
   return 0;
}

/* clang -g -fmodules-ts -fimplicit-modules -fmodule-map-file=🚦.modules      \
 '∎|∎ eff.c' ../Apps/Source/Releases/libTwinbeam-x86_64.a */


