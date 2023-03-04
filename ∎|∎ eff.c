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
  LIST_ENTRY(perform) entries; /* instead of 'next'. */
};

struct assemblage {
   LIST_HEAD(distinctives,perform) steps; /* actual double-linked list. */
}; 


struct disjucinct₋ops { };

int Order(void (^out)(char32̄_t *, __builtin_int_t), char32̄_t * command, ...);

int
main(
  int argc, 
  char * argv[]
)
{
   struct assemblage wrench = LIST_HEAD_INITIALIZER(steps);
   
   LIST_INIT(&wrench.steps);
   
   struct perform * step₋head = malloc(sizeof(struct perform));
   LIST_INSERT_HEAD(&wrench.steps,step₋head,entries);
   
   struct perform * step₋item = malloc(sizeof(struct perform));
   LIST_INSERT_AFTER(step₋head,step₋item,entries);
   
   struct perform * np;
   LIST_FOREACH(np,&wrench.steps,entries) {
     print("element");
   }

  /* if (Order(^(char32̄_t * ucs, __builtin_int_t bytes) { 
    print("response '⬚'.\n",﹟S(bytes,ucs)); }, U"ls -la '⬚' ", ﹟S(U"/"))) { return 1; } */
   
   return 0;
} /* STAILQ_INSERT_TAIL(step_head,step_head,entries) and TAILQ prefix. */

/* clang -g -fmodules-ts -fimplicit-modules -fmodule-map-file=🚦.modules      \
 '∎|∎ eff.c' ../Apps/Source/Releases/libTwinbeam-x86_64.a */


