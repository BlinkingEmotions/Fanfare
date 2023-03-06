/*  eff.c plan och konstant friktion \see centrifug, magnet och molyb tillvara. */

import Twinbeam;

#include <sys/queue.h>
#include <sys/rbtree.h>
#include <unicode/ustring.h>
#include <string.h>

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

typedef struct { rb_node_t node; const char * name; int payload; } material;

signed int compare_nodes(void * context, const  void *node1, const void *node2)
{ return strcmp(((material *)node1)->name,((material *)node2)->name); }
signed int compare_key(void * context, const void *node, 
 const void * key) { return strcmp(((material *)node)->name,(const char *)key); }

UChar * to_unicode1(char * cstr)
{
   size_t srclen = strlen(cstr);
   int32_t capacity = srclen*4;
   UChar * eight=malloc(capacity);
   eight = u_uastrcpy(eight,cstr); /* UErrorCode error; dst = u_strFromUTF8(dst,capacity,&actual,cstr,srclen,&error); */
   return eight;
}

char * to_cstring(UChar * str)
{
   int32_t len = u_strlen(str);
   char * thirtytwo = malloc(len*4);
   thirtytwo = u_austrcpy(thirtytwo,str);
   return thirtytwo;
}

int tokenize(UChar * str, const UChar * delim, void (^token)(UChar * word))
{
   UChar *state,*first; int initial=1;
again:
   first = u_strtok_r(initial ? str : NULL,delim,&state);
   if (first != NULL) { token(first); initial=0; goto again; }
   return 0;
}

int IsFileSuffix(const char * suffix, char8₋t * one₋filepath)
{
   UChar * filepath = to_unicode1((char *)one₋filepath);
   static const UChar dot[]={ 0x46, 0x00 };
   UChar * lastdot = u_strrstr(filepath,dot); 
   UChar * u_suffix = to_unicode1((char *)suffix);
   return u_strcmp(lastdot,u_suffix) == 0;
}

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
   
   material * m1=Alloc(sizeof(material)),*m2=Alloc(sizeof(material));
   m1->name="hello",m1->payload=5,m2->name="world",m2->payload=7;
   rb_tree_t rbt; rb_tree_ops_t ops = {compare_nodes,compare_key,0,0};
   rb_tree_init(&rbt,&ops);
   void * insertedOrExisting1 = rb_tree_insert_node(&rbt,m1);
   if (insertedOrExisting1 != m1) { print("Unable to insert node1.\n"); }
   void * insertedOrExisting2 = rb_tree_insert_node(&rbt,m2);
   if (insertedOrExisting2 != m2) { print("Unable to insert node2.\n"); }   
   size_t count = rb_tree_count(&rbt);
   print("count is ⬚.\n",﹟d(count));
   material * found = rb_tree_find_node(&rbt,"world");
   if (found == 0) print("Unable to find selected node\n.");
   else print("payload is ⬚\n",﹟d(found->payload));
   
   static const UChar left[]={ 0x41, 0x42, 0x43, 0 };    /* "ABC" */
   static const UChar right[]={ 0x61, 0x62, 0x63, 0 };    /* "abc" */
   if (u_strcmp(left,right) == 0) print("equal");
   else print("non-equal\n");
   
   UChar * str = to_unicode1("hello world");
   static const UChar delim[]={ 0x20, 0x00 };

   if (tokenize(str,delim, ^(UChar * word) {
     char * cstr = to_cstring(word);
     print("token is '⬚'.\n",﹟s7(cstr));
     free(cstr);
   })) { return 1; }
   free(str);
   return 0;
   }

/* clang -g -fmodules-ts -fimplicit-modules -fmodule-map-file=🚦.modules      \
 '∎|∎ eff.c' ../Apps/Source/Releases/libTwinbeam-x86_64.a */


