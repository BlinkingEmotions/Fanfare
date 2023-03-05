/*  eff.c plan och konstant friktion \see centrifug, magnet och molyb tillvara. */

import Twinbeam;

#include <sys/queue.h>
#include <sys/rbtree.h>
#include <string.h>

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

struct material { rb_node_t node; const char * name; int payload; };

signed int compare_nodes(void * context, const  void *node1, 
 const void *node2) { return strcmp(((struct material *)node1)->name,((struct material *)node2)->name); }
signed int compare_key(void * context, const void *node, 
 const void * key) { return strcmp(((struct material *)node)->name,(const char *)key); }

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
     print("element\n");
   }

  /* if (Order(^(char32̄_t * ucs, __builtin_int_t bytes) { 
    print("response '⬚'.\n",﹟S(bytes,ucs)); }, U"ls -la '⬚' ", ﹟S(U"/"))) { return 1; } */
   
   struct material * m1=Alloc(sizeof(struct material)),*m2=Alloc(sizeof(struct material));
   m1->name="hello",m1->payload=5,m2->name="world",m2->payload=7;
   rb_tree_t rbt; rb_tree_ops_t ops = {compare_nodes,compare_key,0,0};
   rb_tree_init(&rbt,&ops);
   void * insertedOrExisting1 = rb_tree_insert_node(&rbt,m1);
   if (insertedOrExisting1 != m1) { print("Unable to insert node1.\n"); }
   void * insertedOrExisting2 = rb_tree_insert_node(&rbt,m2);
   if (insertedOrExisting2 != m2) { print("Unable to insert node2.\n"); }   
   size_t count = rb_tree_count(&rbt);
   print("count is ⬚.\n",﹟d(count));
   struct material * found = rb_tree_find_node(&rbt,"world");
   if (found == 0) print("Unable to find selected node\n.");
   else print("payload is ⬚\n",﹟d(found->payload));
   return 0;
}

/* clang -g -fmodules-ts -fimplicit-modules -fmodule-map-file=🚦.modules      \
 '∎|∎ eff.c' ../Apps/Source/Releases/libTwinbeam-x86_64.a */


