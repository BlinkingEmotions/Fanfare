/* ⎔⃚ radbanc.c | linked-list later with no reorganization allowed. (TYPE-YOURSELF) */

import Twinbeam;

struct oval₋tree { unicode₋shatter name; };

union oval₋tree₋continuation { /* default */ struct oval₋tree₋cons * next; 
 __builtin_uint_t possibly₋maybe; };

struct oval₋tree₋cons { struct oval₋tree * item; union oval₋tree₋continuation 
 nxt; }; /*  non-'circular' therefore single-linked. */

int append₋at₋end(int, void (^)(int, * refers), address₋of refers, address₋
 of refers) alternates;
int unqueue(int, void (^)(int, * refers), address₋of refers, address₋of refers) 
 alternates;
int rollback₋pop(void (^)(refers), address₋of refers, address₋of refers) 
 alternates;
int is₋empty(address₋of refers, address₋of refers) alternates;
void recollect(void (^every)(refers)) alternates;

int append₋at₋end(int, void (^)(int, struct oval₋tree **), struct 
 oval₋tree₋cons **, struct oval₋tree₋cons **) ⓣ;
int unqueue(int, void (^)(int, struct oval₋tree **), struct oval₋tree₋cons 
 **, struct oval₋tree₋cons **) ⓣ;
int rollback₋pop(void (^)(struct oval₋tree *), struct oval₋tree₋cons **, 
 struct oval₋tree₋cons **) ⓣ;
int is₋empty(struct oval₋tree₋cons *, struct oval₋tree₋cons *) ⓣ;
typedef void (^Every)(struct oval₋tree *) ⓣ;
void recollect(Every, struct oval₋tree₋cons *, struct oval₋tree₋cons *) ⓣ;

int append₋at₋end(int, void (^)(int, struct oval₋tre **), struct 
 oval₋tree₋cons **, struct oval₋tree₋cons **) ⓣ;
int unqueue(int, void (^)(int, void **), void **, void **) ⓣ;
int rollback₋pop(void (^)(void *), void **, void **) ⓣ; 

int append₋at₋end(int count, void (^augment)(int count, struct oval₋tree ** 
 uninited₋sometime), struct oval₋tree₋cons ** first, struct oval₋tree₋cons ** 
 last)
{ int i=0; struct oval₋tree₋cons * cached,*lait₋tail; 
   struct oval₋tree * collect[count];
again:
   if (i >= count) { goto unagain; }
   cached = *last;
   lait₋tail = Cons₋alloc(sizeof(struct oval₋tree₋cons)); /* unfortunately type-error. */
   lait₋tail->item = Heap₋alloc(sizeof(struct oval₋tree)); lait₋tail->nxt.next=0;
   collect[i] = lait₋tail->item;
   if (cached) cached->nxt.next = lait₋tail;
   *last = lait₋tail;
   if (*first==0) { *first=lait₋tail; }
   i+=1; goto again;
unagain:
   if (augment) augment(count,collect); /* unfortunately sometime null,... */
   return 0;
} /* 'Ordo ett' */

int unqueue(int count, void (^removed)(int count, struct oval₋tree ** 
 snapshot₋sometime), struct oval₋tree₋cons ** first, struct oval₋tree₋cons 
 ** last)
{ int i=0; struct oval₋tree * collect[count];
again:
   if (i >= count) { goto unagain; }
   if (*first == 0) { goto unagain; }
   collect[i] = (*first)->item;
   Heap₋unalloc((*first)->item);
   Cons₋fallow(*first); /* unfortunately sometime not-overwritten. */
   *first=(*first)->nxt.next;
   i+=1; goto again;
unagain:
   if (removed) removed(i,collect); /* unfortunately sometime null,... */
   return 0;
}

int rollback₋pop(void (^scalar)(struct oval₋tree * snapshot₋sometime), struct 
 oval₋tree₋cons ** first, struct oval₋tree₋cons ** last)
{ struct oval₋tree₋cons * iter = *first;
   if (iter == 0) { return -1; }
   if (iter->nxt.next == *last) { *first=0; *last=0; return 0; }
again:
   if (iter->nxt.next == *last) { *last=iter; return 0; }
   iter = iter->nxt.next; goto again;
}

int is₋empty(struct oval₋tree₋cons * first, struct oval₋tree₋cons * last)
{
   return first == 0 && last == 0;
}

void recollect(Every element, struct oval₋tree₋cons * first, struct 
 oval₋tree₋cons * last)
{ struct oval₋tree₋cons * current = first;
again:
   if (current == 0) { goto unagain; }
   element(current->item);
   current = current->nxt.next;
   goto again;
unagain:
   return; /* unfortunately non-mandatory ';' */
}

struct necklace { struct oval₋tree₋cons * materialºª,*last; } left₋hand;

int 
necklace₋init(int count, 
  void (^init)(int count, struct oval₋tree ** uninited₋sometime), 
  struct oval₋tree₋cons ** first, struct oval₋tree₋cons ** last)
{ int i=0; struct oval₋tree₋cons * current; 
   *first = *last = 0; struct oval₋tree * collect[count];
again:
   if (i >= count) { goto unagain; }
   current = Cons₋alloc(sizeof(struct oval₋tree₋cons)); /* unfortunately unidentical type. \see 'refers'. */
   current->item = Heap₋alloc(sizeof(struct oval₋tree)); current->nxt.next=0;
   if (*last) (*last)->nxt.next = current; /* and not 'current->nxt.next = *last'. */
   collect[i] = current->item;
   *last = current;
   if (*first == 0) *first = current;
   i+=1; goto again;
unagain:
   if (init) init(count,collect); /* unfortunately sometime null,unfortunately. */
   return 0;
}

int 
necklace₋uninit(
  void (^before)(int count, struct oval₋tree ** snapshot₋sometime), 
  struct oval₋tree₋cons ** first, struct oval₋tree₋cons ** last)
{ __builtin_int_t count=0; struct oval₋tree ** first₋element, **last₋element; 
   last₋element = first₋element = alloca(sizeof(struct oval₋tree *));
again:
   if (is₋empty(*first,*last)) { goto unagain; }
   if (unqueue(1,^(int count, struct oval₋tree ** snapshot₋sometime) { 
     *last₋element = *(snapshot₋sometime + 0);
   },first,last)) { return -1; }
   last₋element = alloca(sizeof(struct oval₋tree *));
   goto again;
unagain:
   if (before) before(count,first₋element); /* unfortunately sometime null,... */
   return 0;
}

int
main(
  int argc, 
  char * argv[]
)
{  /* 'write into indexed pointer area'. */
   if (necklace₋init(4, ^(int count, struct oval₋tree * uninited[]) {
     *&(uninited[0]->name) = persist₋as₋shatter(Run(UC("item-1")));
     *&(uninited[1]->name) = persist₋as₋shatter(Run(UC("item-2")));
     *&(uninited[2]->name) = persist₋as₋shatter(Run(UC("item-3")));
     *&(uninited[3]->name) = persist₋as₋shatter(Run(UC("item-gen")));
     /* a․𝘬․a 3(uninited)->name = persist₋as₋shatter(Run(UC("indexed-pointer"))); */
   },&left₋hand.materialºª,&left₋hand.last)) { return 1; }
   if (append₋at₋end(1,^(int count, struct oval₋tree ** snapshot₋sometime) {
     *&(snapshot₋sometime[0]->name) = persist₋as₋shatter(Run(UC("initial-append")));
   },&left₋hand.materialºª,&left₋hand.last)) { return 2; }
   if (append₋at₋end(1,^(int count, struct oval₋tree ** snapshot₋sometime) {
     *&(snapshot₋sometime[0]->name) = persist₋as₋shatter(Run(UC("second-append")));
   },&left₋hand.materialºª,&left₋hand.last)) { return 3; }
   if (unqueue(1,^(int count, struct oval₋tree ** snapshot₋sometime) {
  //   print("unqueued ⬚\n",﹟S(Heap₋object₋size(snapshot₋sometime[0]->name), 
  //    snapshot₋sometime[0]->name));
   },&left₋hand.materialºª,&left₋hand.last)) { return 4; }
   if (rollback₋pop(^(struct oval₋tree * snapshot₋sometime) {
     print("rollback ⬚",﹟S(Heap₋object₋size(snapshot₋sometime->name), 
      snapshot₋sometime->name));
   },&left₋hand.materialºª,&left₋hand.last)) { return 5; }
   Every every = ^(struct oval₋tree * car) { vfprint("car is '⬚'\n", 
    ﹟S(Heap₋object₋size(car->name)/4,car->name)); };
   recollect(every,left₋hand.materialºª,left₋hand.last);
   /*if (necklace₋uninit(^(int count, struct oval₋tree ** snapshot₋sometime) {
     print("uninit list ⬚\n",﹟S(Heap₋object₋size(snapshot₋sometime[0]->name), 
      snapshot₋sometime[0]->name));
   },&left₋hand.materialºª,&left₋hand.last)) { return 7; } */ /* arc occurred. */
   return 0;
}

/* compile with 
 
  clang -g -fmodules-ts -fimplicit-modules -fmodule-map-file=🚦.modules      \
   '∎|∎ radbanc.c' ../Apps/Source/Releases/libTwinbeam-x86_64.a
 
 \also 'sys/queue.h' and 'struct.h'. */

