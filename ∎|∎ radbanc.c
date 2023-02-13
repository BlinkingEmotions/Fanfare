/* ⎔⃚ radbanc.c | linked-list later with no reorganization allowed. (TYPE-YOURSELF) */

import Twinbeam;

/* int append₋at₋end(int, void (^)(int, * refers), address₋of refers, address₋
 of refers, int) nonalter;
int unqueue(int, void (^)(int, * refers), address₋of refers, address₋of 
 refers) nonalter;
int rollback₋pop(void (^)(refers), address₋of refers, address₋of refers) 
 nonalter;
int is₋empty(address₋of refers, address₋of refers) nonalter;
void recollect(void (^every)(refers,int), address₋of refers, 
 address₋of refers) nonalter;
int uninit₋list(void (^)(refers, address₋of refers), address₋of refers, 
 address₋of refers, address₋of refers) nonalter;
*/

int append₋at₋end(int, void (^)(int, void **), void **, void **, int) ⓣ;
int unqueue(int, void (^)(int, void **), void **, void **) ⓣ;
int rollback₋pop(void (^)(void *), void **, void **) ⓣ;
int is₋empty(void *, void *) ⓣ;
void recollect(void (^every)(void *, int),void *,void *) ⓣ;
int uninit₋list(void (^removed)(void *, void **),void *,void *) ⓣ;

typedef void Material; typedef void Conscell;

union cell₋continuation { /* default */ Conscell * next; __builtin_uint_t 
 possibly₋maybe; };

struct cons₋cell { Material * item; union cell₋continuation nxt; };

typedef struct cons₋cell Cons₋cell;

int append₋at₋end(int count, void (^augment)(int count, Material ** 
 uninited₋sometime), Conscell ** first, Conscell ** last, 
 int sizeof₋material) ⓣ
{ int i=0; struct cons₋cell * memory,*element₋last; 
   Material * collect[count];
again:
   if (i >= count) goto unagain;
   memory = (Cons₋cell *)*last;
   element₋last = Cons₋alloc(sizeof(Conscell *) + sizeof(Material *)); /* unfortunately type-error. */
   element₋last->item = Heap₋alloc(sizeof₋material); element₋last->nxt.next=0;
   collect[i] = element₋last->item;
   if (memory) memory->nxt.next = element₋last;
   *last = element₋last;
   if (*first==0) { *first=memory; }
   i+=1; goto again;
unagain:
   if (augment) augment(count,collect);
   return 0;
} /* 'Ordo ett' */

int unqueue(int count, void (^removed)(int count, Material ** 
 snapshot₋sometime), Conscell ** first, Conscell ** last) ⓣ
{ int i=0; Material * collect[count];
   Cons₋cell ** First=(Cons₋cell **)first;
again:
   if (i >= count) goto unagain;
   if (*first == 0) goto unagain;
   collect[i] = (*First)->item;
   Cons₋fallow(*First); /* unfortunately sometime not-overwritten. */
   *first=(*First)->nxt.next;
   i+=1; goto again;
unagain:
   if (removed) removed(i,collect);
   return 0;
}

int rollback₋pop(void (^scalar)(Material * snapshot₋sometime), Conscell ** 
 first, Conscell ** last) ⓣ
{ Cons₋cell * select = *(Cons₋cell **)first, *deleted;
   if (select == 0) return -1;
   if (*last == *first) { deleted=select,*first=0,*last=0; goto unagain; }
again:
   if (select->nxt.next == *last) { *last=select; goto unagain; }
   select = select->nxt.next; goto again;
unagain:
   scalar(deleted);
   return 0;
}

int is₋empty(Conscell * first, Conscell * last) ⓣ
{
   return first == 0 && last == 0;
}

void recollect(void (^item)(Material *,int), Conscell * first, 
 Conscell * last) ⓣ
{ Cons₋cell * select = (Cons₋cell *)first; int index=0;
again:
   if (select == 0) goto unagain;
   item(select->item,index);
   select = select->nxt.next;
   index+=1; goto again;
unagain:
   return; /* unfortunately non-mandatory ';' */
}

int uninit₋list(void (^removed)(Material *, Material **), Conscell * first, 
 Conscell * last, Material ** address₋of₋next) ⓣ
{ Cons₋cell * select = (Cons₋cell *)first;
again:
   if (select == 0) goto unagain;
   Heap₋unalloc(select);
   if (removed) removed(select->item,address₋of₋next);
   select = select->nxt.next;
   goto again;
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
typedef void ** (^special₋to₋general)(struct oval₋tree **);
typedef struct ship₋relation { paramet₋to₋automat special1; 
 variant₋fromto₋array special2; int sizeof₋material; 
 variant₋fromto₋indirect₋toread special3; special₋to₋general 
 special4; } refers;
struct ship₋relation areel = {
 .special1 = ^(struct oval₋tree₋cons ** input) { return (void **)input; }, 
 .special2 = ^(void ** input) { return (struct oval₋tree **)input; }, 
 .sizeof₋material = sizeof(struct oval₋tree), 
 .special3 = ^(void * input) { return (struct oval₋tree *)input; }, 
 .special4 = ^(struct oval₋tree ** input) { return (void **)input; }
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

void recollect(void (^every)(struct oval₋tree * item, int index), struct oval₋tree₋cons 
 * first, struct oval₋tree₋cons * last, struct ship₋relation reel) ⓣ
{
   recollect(^(void * item, int index) { every(reel.special3(item),index); },first,last);
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
   Material *next₋element,*first₋element; next₋element = first₋element = alloca(sizeof(void *));
   if (uninit₋list(^(Material * item, Material ** address₋of₋next) { 
     *address₋of₋next=item; alloca(sizeof(void *)); count+=1; },*first,*last,&next₋element)) { return -1; }
   if (before) before(count,(struct oval₋tree **)reel.special3(first₋element)); /* unfortunately sometime null,... */
   *first = *last = 0;
   return 0;
}

void Fallow(int count, void ** reference) ⓣ
{
   for (int i=0; i<count; i+=1) Fallow(i,reference[i]);
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
     for (int i=0; i<count; i+=1) 
      print("unqueued ⬚\n",﹟S(Heap₋object₋size(snapshot₋sometime[i]->name), 
       snapshot₋sometime[i]->name));
     Fallow(count,areel.special4(snapshot₋sometime));
   },&left₋hand.materialºª,&left₋hand.last,areel)) { return 4; }
   if (rollback₋pop(^(struct oval₋tree * snapshot₋sometime) {
     print("rollback ⬚\n",﹟S(Heap₋object₋size(snapshot₋sometime->name), 
      snapshot₋sometime->name));
     Fallow(snapshot₋sometime);
   },&left₋hand.materialºª,&left₋hand.last,areel)) { return 5; }
   typedef void (^Every)(struct oval₋tree *,int);
   Every every = ^(struct oval₋tree * car,int index) { print("car is '⬚'\n", 
    ﹟S(Heap₋object₋size(car->name)/4,car->name)); };
   recollect(every,left₋hand.materialºª,left₋hand.last,areel);
   if (necklace₋uninit(^(int count, struct oval₋tree ** snapshot₋sometime) {
     for (int i=0; i<count; i+=1)
       print("uninit list ⬚\n",﹟S(Heap₋object₋size(snapshot₋sometime[i]->name), 
        snapshot₋sometime[i]->name));
     Fallow(count,areel.special4(snapshot₋sometime));
   },&left₋hand.materialºª,&left₋hand.last,areel)) { return 7; } /* arc occurred. */
   return 0;
}

/* compile with 
 
  clang -g -fmodules-ts -fimplicit-modules -fmodule-map-file=🚦.modules      \
   '∎|∎ radbanc.c' ../Apps/Source/Releases/libTwinbeam-x86_64.a
 
 \also 'sys/queue.h' and 'struct.h'. */

