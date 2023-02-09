/* ⎔⃚ radbanc.c | linked-list later with no reorganization allowed. (TYPE-YOURSELF) */

import Twinbeam;

/* int append₋at₋end(int, void (^)(int, * refers), address₋of refers, address₋
 of refers) alternates;
int unqueue(int, void (^)(int, * refers), address₋of refers, address₋of 
 refers) alternates;
int rollback₋pop(void (^)(refers), address₋of refers, address₋of refers) 
 alternates;
int is₋empty(address₋of refers, address₋of refers) alternates;
void recollect(void (^every)(refers)) alternates; */

int append₋at₋end(int, void (^)(int, void **), void **, void **, int) ⓣ;
int unqueue(int, void (^)(int, void **), void **, void **) ⓣ;
int rollback₋pop(void (^)(void *), void **, void **) ⓣ; 
int is₋empty(void *, void *) ⓣ;
void recollect(void (^every)(void *),void *,void *) ⓣ;
int uninit₋list(void (^removed)(void *),void *,void *) ⓣ;

typedef void Material; typedef void Conscell;

union cell₋continuation { /* default */ Conscell * next; __builtin_uint_t 
 possibly₋maybe; };

struct cons₋cell { Material * item; union cell₋continuation nxt; };

typedef struct cons₋cell Cons₋cell;

int append₋at₋end(int count, void (^augment)(int count, Material ** 
 uninited₋sometime), Conscell ** first, Conscell ** last, 
 int sizeof₋material) ⓣ
{ int i=0; struct cons₋cell * cached,*lait₋tail; 
   Material * collect[count];
again:
   if (i >= count) { goto unagain; }
   cached = (Cons₋cell *)*last;
   lait₋tail = Cons₋alloc(sizeof(Material *) + sizeof(Conscell *)); /* unfortunately type-error. */
   lait₋tail->item = Heap₋alloc(sizeof₋material); lait₋tail->nxt.next=0;
   collect[i] = lait₋tail->item;
   if (cached) cached->nxt.next = lait₋tail;
   *last = lait₋tail;
   if (*first==0) { *first=lait₋tail; }
   i+=1; goto again;
unagain:
   if (augment) augment(count,collect); /* unfortunately sometime null,... */
   return 0;
} /* 'Ordo ett' */

int unqueue(int count, void (^removed)(int count, Material ** 
 snapshot₋sometime), Conscell ** first, Conscell ** last) ⓣ
{ int i=0; Material * collect[count]; Cons₋cell ** First=(Cons₋cell **)first;
again:
   if (i >= count) { goto unagain; }
   if (*first == 0) { goto unagain; }
   collect[i] = (*First)->item;
   Heap₋unalloc((*First)->item);
   Cons₋fallow(*first); /* unfortunately sometime not-overwritten. */
   *first=(*First)->nxt.next;
   i+=1; goto again;
unagain:
   if (removed) removed(i,collect); /* unfortunately sometime null,... */
   return 0;
}

int rollback₋pop(void (^scalar)(Material * snapshot₋sometime), Conscell ** 
 first, Conscell ** last) ⓣ
{ Cons₋cell * iter = *(Cons₋cell **)first;
   if (iter == 0) { return -1; }
   if (iter->nxt.next == *last) { *first=0; *last=0; return 0; }
again:
   if (iter->nxt.next == *last) { *last=iter; return 0; }
   iter = iter->nxt.next; goto again;
}

int is₋empty(Conscell * first, Conscell * last) ⓣ
{
   return first == 0 && last == 0;
}

void recollect(void (^element)(Material *), Conscell * first, Conscell * last) ⓣ
{ Cons₋cell * current = (Cons₋cell *)first;
again:
   if (current == 0) { goto unagain; }
   element(current->item);
   current = current->nxt.next;
   goto again;
unagain:
   return; /* unfortunately non-mandatory ';' */
}

int uninit₋list(void (^removed)(Material *), Conscell * first, Conscell * last) ⓣ
{ Cons₋cell * current = (Cons₋cell *)first;
again:
   if (current == 0) goto unagain;
   removed(current->item);
   Heap₋unalloc(current);
   current = current->nxt.next;
unagain:
   return 0;
}

#pragma recto with 'refers' keyword, detailed 'generalization' is not required

struct oval₋tree { unicode₋shatter name; };

union oval₋tree₋continuation { /* default */ struct oval₋tree₋cons * next; 
 __builtin_uint_t possibly₋maybe; };

struct oval₋tree₋cons { struct oval₋tree * item; union oval₋tree₋continuation 
 nxt; }; /*  non-'circular' therefore single-linked. */

typedef void ** (^paramet₋to₋automat)(struct oval₋tree₋cons **);
typedef struct oval₋tree ** (^variant₋fromto₋array)(void **);
typedef struct oval₋tree * (^variant₋fromto₋indirect₋toread)(void *);

typedef struct ship₋relation { paramet₋to₋automat special1; variant₋fromto₋array 
 special2; int sizeof₋material; variant₋fromto₋indirect₋toread special3; } refers;
struct ship₋relation areel = {
 .special1 = ^(struct oval₋tree₋cons ** input) { return (void **)input; }, 
 .special2 = ^(void ** input) { return (struct oval₋tree **)input; }, 
 .sizeof₋material = sizeof(struct oval₋tree), 
 .special3 = ^(void * input) { return (struct oval₋tree *)input; }
};

int append₋at₋end(int count, void (^augment)(int, struct oval₋tree **), struct 
 oval₋tree₋cons ** first, struct oval₋tree₋cons ** last, struct ship₋relation reel) ⓣ
{
   return append₋at₋end(count,^(int count, void ** uninited₋sometime) { 
    augment(count,reel.special2(uninited₋sometime)); },reel.special1(first), 
     reel.special1(last),reel.sizeof₋material);
}

int unqueue(int count, void (^removed)(int, struct oval₋tree **), struct 
 oval₋tree₋cons ** first, struct oval₋tree₋cons ** last, struct ship₋relation reel) ⓣ
{
   return unqueue(count, ^(int count, void ** snapshot₋sometime) { 
    removed(count,reel.special2(snapshot₋sometime)); },reel.special1(first),
     reel.special1(last));
}

int rollback₋pop(void (^scalar)(struct oval₋tree *), struct oval₋tree₋cons ** 
 first, struct oval₋tree₋cons ** last, struct ship₋relation reel) ⓣ
{
   return rollback₋pop(^(void * snapshot₋sometime) { 
    scalar(reel.special3(snapshot₋sometime)); },reel.special1(first),
     reel.special1(last));
}

int is₋empty(struct oval₋tree₋cons * first, struct oval₋tree₋cons * last, 
 struct ship₋relation reel) ⓣ
{
   return is₋empty(first,last);
}

void recollect(void (^every)(struct oval₋tree * item), struct oval₋tree₋cons 
 * first, struct oval₋tree₋cons * last, struct ship₋relation reel) ⓣ
{
   recollect(^(void * item) { every(reel.special3(item)); },first,last);
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
  struct oval₋tree₋cons ** first, struct oval₋tree₋cons ** last, struct 
  ship₋relation reel)
{ __builtin_int_t 𝑓𝑙𝑢𝑐𝑡𝑢𝑎𝑛𝑡 count=0;
   Material /* *next₋element=0, */*first₋element = alloca(sizeof(void *));
   if (uninit₋list(^(Material * item) { /* next₋element= */alloca(sizeof(void *)); count+=1; },*first,*last)) { return -1; }
   if (before) before(count,(struct oval₋tree **)reel.special3(first₋element)); /* unfortunately sometime null,... */
   *first = *last = 0;
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
   },&left₋hand.materialºª,&left₋hand.last,areel)) { return 2; }
   if (append₋at₋end(1,^(int count, struct oval₋tree ** snapshot₋sometime) {
     *&(snapshot₋sometime[0]->name) = persist₋as₋shatter(Run(UC("second-append")));
   },&left₋hand.materialºª,&left₋hand.last,areel)) { return 3; }
   if (unqueue(1,^(int count, struct oval₋tree ** snapshot₋sometime) {
     print("unqueued ⬚\n",﹟S(Heap₋object₋size(snapshot₋sometime[0]->name), 
      snapshot₋sometime[0]->name));
   },&left₋hand.materialºª,&left₋hand.last,areel)) { return 4; }
   if (rollback₋pop(^(struct oval₋tree * snapshot₋sometime) {
     print("rollback ⬚",﹟S(Heap₋object₋size(snapshot₋sometime->name), 
      snapshot₋sometime->name));
   },&left₋hand.materialºª,&left₋hand.last,areel)) { return 5; }
   typedef void (^Every)(struct oval₋tree *);
   Every every = ^(struct oval₋tree * car) { vfprint("car is '⬚'\n", 
    ﹟S(Heap₋object₋size(car->name)/4,car->name)); };
   recollect(every,left₋hand.materialºª,left₋hand.last,areel);
   if (necklace₋uninit(^(int count, struct oval₋tree ** snapshot₋sometime) {
     print("uninit list ⬚\n",﹟S(Heap₋object₋size(snapshot₋sometime[0]->name), 
      snapshot₋sometime[0]->name));
   },&left₋hand.materialºª,&left₋hand.last,areel)) { return 7; } /* arc occurred. */
   return 0;
}

/* compile with 
 
  clang -g -fmodules-ts -fimplicit-modules -fmodule-map-file=🚦.modules      \
   '∎|∎ radbanc.c' ../Apps/Source/Releases/libTwinbeam-x86_64.a
 
 \also 'sys/queue.h' and 'struct.h'. */

