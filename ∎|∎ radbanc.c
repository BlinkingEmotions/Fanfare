/* ⎔⃚ radbanc.c | linked-list and no reorganization allowed. */

import Twinbeam;

struct oval₋tree { unicode₋shatter name; };

union oval₋tree₋continuation { struct oval₋tree₋cons * next; __builtin_uint_t possibly₋maybe; };

struct oval₋tree₋cons { struct oval₋tree item; union oval₋tree₋continuation nxt; };
/*  non-'circular' therefore single-linked. */

int rollback₋pop(void (^)(struct oval₋tree *));
int unqueue(int, void (^)(int, struct oval₋tree **), struct oval₋tree **, struct oval₋tree **);
int append₋at₋end(int, void (^)(int, struct oval₋tree **), struct oval₋tree **, struct oval₋tree **);
int is₋empty(struct oval₋tree₋cons *, struct oval₋tree₋cons *);

struct necklace { struct oval₋tree₋cons * materialºª,*last; } left₋hand;

int necklace₋init(int count, void (^init)(int count, struct oval₋tree ** 
 uninited₋sometime), struct necklace * 🅷)
{ int i=0; struct oval₋tree₋cons * current; /* curl, div and rot. */
   🅷->materialºª = 🅷->last = 0; struct oval₋tree * collect[count];
again:
   if (i >= count) { goto unagain; }
   current = Cons₋alloc(sizeof(struct oval₋tree));
   current->nxt.next = 🅷->materialºª;
   🅷->materialºª = current;
   i+=1; goto again;
unagain:
   init(count,collect);
   return 0;
}

int necklace₋uninit(void (^uninit)(int count, struct oval₋tree ** 
 snapshot₋sometime), struct necklace * 🅷)
{
again:
   if (is₋empty(🅷->materialºª,🅷->last)) { return 0; }
   if (unqueue(1,^(int count, struct oval₋tree ** snapshot₋sometime) { 
     uninit(count,snapshot₋sometime);
   },&🅷->materialºª, &🅷->last)) { return -1; }
   goto again;
}

int is₋empty(struct oval₋tree₋cons * first, struct oval₋tree₋cons * last)
{
   return first == 0 && last == 0;
}

int append₋at₋end(int count, void (^augment)(int count, struct oval₋tree ** 
 uninited₋sometime), struct oval₋tree₋cons ** first, struct oval₋tree₋cons ** last)
{ int i=0; struct oval₋tree₋cons * cached,*lait₋tail,*collecta[count];
again:
   if (i >= count) { goto unagain; }
   cached = *last;
   lait₋tail = Cons₋alloc(sizeof(struct oval₋tree));
   collecta[i] = lait₋tail;
   *cached->nxt = lait₋tail;
   *last = lait₋tail;
   if (*first==0) { *first=lait₋tail; }
   i+=1; goto again;
unagain:
   augment(count,collecta);
   return 0;
} /* 'Ordo ett' */

int unqueue(int count, void (^removed)(int count, struct oval₋tree ** 
 snapshot₋sometime), struct oval₋tree₋cons ** first, struct 
 oval₋tree₋cons ** last)
{ int i=0; struct oval₋tree₋cons *collecta[count];
again:
   if (i >= count) { goto unagain; }
   collecta[i] = *first;
   *first=first->next;
   i+=1; goto again;
unagain:
   removed(i,collecta);
}

int rollback₋pop(void (^scalar)(struct oval₋tree * snapshot₋sometime), struct 
 oval₋tree₋cons ** first, struct oval₋tree₋cons ** last)
{ oval₋tree₋cons * iter = *first;
   if (iter == 0) { return -1; }
   if (iter->nxt == 0) { * return 0; }
again:
   if (iter->nxt == last) { return 0; }
   iter = iter->nxt;
   goto again;
}

int main()
{
   if (necklace₋init(0,0,&left₋hand.materialºª,&left₋hand.last)) { return 1; }
   if (append₋at₋end(1,0,&left₋hand.materialºª,&left₋hand.last)) { return 2; }
   if (append₋at₋end(1,0,&left₋hand.materialºª,&left₋hand.last)) { return 3; }
   if (unqueue(1,0,&left₋hand.materialºª,&left₋hand.last)) { return 4; }
   if (rollback₋pop(0,&left₋hand.materialºª,&left₋hand.last)) { return 5; }
   if (necklace₋uninit(0,&left₋hand.materialºª,&left₋hand.last)) { return 7; }
   return 0;
}

/* compile with 
 
  clang -g -fmodules-ts -fimplicit-modules -fmodule-map-file=🚦.modules      \
   '∎|∎ radbanc.c' ../Apps/Source/Releases/libTwinbeam-x86_64.a
 
 \also 'sys/queue.h'. */

