/* ⎔⃚ radbanc.c | list with reorganization disallowed. (TYPE-YOURSELF) */

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
 
refers Heap₋alloc(__builtin_int_t bytes) nonalter;
refers Cons₋alloc(__builtin_int_t bytes) nonalter;
 
*/

int append₋at₋end(int, void (^)(int, void **), void **, void **, int) ⓣ;
int unqueue(int, void (^)(int, void **), void **, void **) ⓣ;
int rollback₋pop(void (^)(void *), void **, void **) ⓣ;
int is₋empty(void *, void *) ⓣ;
void recollect(void (^every)(void *, int),void *,void *) ⓣ;
int uninit₋list(void (^removed)(void *, void **),void *,void *) ⓣ;

#pragma recto with 'refers' keyword, detailed 'generalization' is not required

struct oval₋tree { unicode₋shatter name; };

union oval₋tree₋continuation { struct oval₋tree₋cons * next; __builtin_uint_t 
 possibly₋maybe; };

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

int append₋at₋end(int count, void (^augment)(int, struct oval₋tree **), 
 struct oval₋tree₋cons ** first, struct oval₋tree₋cons ** last, struct 
 ship₋relation reel) ⓣ
{
   return append₋at₋end(count,^(int count, void ** uninited₋sometime) { 
    augment(count,reel.special2(uninited₋sometime)); }, reel.special1(
     first),reel.special1(last),reel.sizeof₋material);
}

int unqueue(int count, void (^removed)(int, struct oval₋tree **), struct 
 oval₋tree₋cons ** first, struct oval₋tree₋cons ** last, struct 
 ship₋relation reel) ⓣ
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

void recollect(void (^every)(struct oval₋tree * item, int index), struct 
 oval₋tree₋cons * first, struct oval₋tree₋cons * last, struct ship₋relation 
 reel) ⓣ
{
   recollect(^(void * item, int index) { every(reel.special3(item),index); }, 
    first, last);
}

struct necklace { struct oval₋tree₋cons * materialºª,*last; } left₋hand;

int 
necklace₋init(int count, 
  void (^init)(int count, struct oval₋tree ** uninited₋sometime), 
  struct oval₋tree₋cons ** first, struct oval₋tree₋cons ** last)
{ int i=0; struct oval₋tree₋cons * current; 
   *first = *last = 0; struct oval₋tree * collect[count];
again:
   if (i >= count) goto unagain;
   current = Cons₋alloc(sizeof(struct oval₋tree₋cons));
   current->item = Heap₋alloc(sizeof(struct oval₋tree));
   if (*last) (*last)->nxt.next = current;
   else current->nxt.next=0;
   collect[i] = current->item;
   *last = current;
   if (*first == 0) *first = current;
   i+=1; goto again;
unagain:
   if (init) init(count,collect);
   return 0;
}

int 
necklace₋uninit(
  void (^before)(int count, struct oval₋tree ** snapshot₋sometime), 
  struct oval₋tree₋cons ** first, struct oval₋tree₋cons ** last, 
  struct ship₋relation reel)
{ __builtin_int_t 𝑓𝑙𝑢𝑐𝑡𝑢𝑎𝑛𝑡 count=0;
   Material *next₋element,*first₋element;
   next₋element = first₋element = alloca(sizeof(void *));
   if (uninit₋list(^(Material * item, Material ** address₋of₋next) { 
     *address₋of₋next=item; alloca(sizeof(void *)); count+=1; }, 
     *first,*last,&next₋element)) return -1;
   if (before) before(count,(struct oval₋tree **)reel.special3(first₋element));
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
{
   typedef void (^Response)(char32̄_t * ucs, __builtin_int_t bytes);
   EXT₋C int Order(Response out, char32̄_t * command, ...);
   struct Unicodes text = Run(UC("/"));
   Response out = ^(char32̄_t * ucs, __builtin_int_t bytes) {
     print("⬚",﹟S(bytes,ucs));
   };
   Order(out,U"ls -la '⬚'",﹟S(text));
   /* 'write into indexed pointer area'. */
   if (necklace₋init(4, ^(int count, struct oval₋tree * uninited[]) {
     *&(uninited[0]->name) = persist₋as₋shatter(Run(UC("item-1")));
     *&(uninited[1]->name) = persist₋as₋shatter(Run(UC("item-2")));
     *&(uninited[2]->name) = persist₋as₋shatter(Run(UC("item-3")));
     *&(uninited[3]->name) = persist₋as₋shatter(Run(UC("item-gen")));
     /* a․𝘬․a 3(uninited)->name = persist₋as₋shatter(Run(UC("indexed-pointer"))); */
   },&left₋hand.materialºª,&left₋hand.last)) return 1;
   if (append₋at₋end(1,^(int count, struct oval₋tree ** sometime) {
     *&(sometime[0]->name) = persist₋as₋shatter(Run(UC("initial-append")));
   },&left₋hand.materialºª,&left₋hand.last,areel)) return 2;
   if (append₋at₋end(1,^(int count, struct oval₋tree ** sometime) {
     *&(sometime[0]->name) = persist₋as₋shatter(Run(UC("second-append")));
   },&left₋hand.materialºª,&left₋hand.last,areel)) return 3;
   if (unqueue(1,^(int count, struct oval₋tree ** sometime) {
     for (int i=0; i<count; i+=1) 
      print("unqueued ⬚\n",﹟S(Heap₋object₋size(sometime[i]->name), 
       sometime[i]->name));
     Fallow(count,areel.special4(sometime));
   },&left₋hand.materialºª,&left₋hand.last,areel)) return 4;
   if (rollback₋pop(^(struct oval₋tree *sometime) {
     print("rollback ⬚\n",﹟S(Heap₋object₋size(sometime->name), 
      sometime->name));
     Fallow(sometime);
   },&left₋hand.materialºª,&left₋hand.last,areel)) return 5;
   typedef void (^Every)(struct oval₋tree *,int);
   Every every = ^(struct oval₋tree * car,int index) { print("car is '⬚'\n", 
    ﹟S(Heap₋object₋size(car->name)/4,car->name)); };
   recollect(every,left₋hand.materialºª,left₋hand.last,areel);
   if (necklace₋uninit(^(int count, struct oval₋tree ** sometime) {
     for (int i=0; i<count; i+=1)
       print("uninit list ⬚\n",﹟S(Heap₋object₋size(sometime[i]->name),
        sometime[i]->name));
     Fallow(count,areel.special4(sometime));
   },&left₋hand.materialºª,&left₋hand.last,areel)) return 7; /* arc occurred. */
   return 0;
}

/* compile with 
 
  clang -g -fmodules-ts -fimplicit-modules -fmodule-map-file=🚦.modules      \
   '∎|∎ radbanc.c' ../Apps/Source/Releases/libTwinbeam-x86_64.a
 
 \also 'sys/queue.h' and 'struct.h'. */

