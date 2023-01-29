/* ⎔⃚ radbanc.c | linked-list and no reorganization allowed. */

import Twinbeam;

struct oval₋tree { unicode₋shatter name; };

union oval₋tree₋continuation { struct oval₋tree * next; __builtin_uint_t possibly₋maybe; };

struct oval₋tree₋cons { struct oval₋tree item; union oval₋tree₋continuation nxt; };
/*  non-'circular' therefore single-linked. */

struct necklace { struct oval₋tree₋cons * materialºª,last; } left₋hand;

int necklace₋init(int count, void (^init)(int count, struct oval₋tree ** 
 uninited₋sometime), struct oval₋tree₋cons * first, struct oval₋tree₋cons * last)
{ int i=0; struct oval₋tree₋cons * current;
   first = last = 0;
again:
   if (i >= count) { return 0; }
   current = Cons₋alloc(sizeof(struct oval₋tree));
   current->nxt = first;
   first = current;
   i +=1; goto again;
}

int necklace₋uninit(void (^uninit)(int count, struct oval₋tree ** 
 snapshot₋sometime), struct oval₋tree₋cons * first, struct oval₋tree₋cons * 
 last)
{ 
 
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
 snapshot₋sometime), struct oval₋tree₋cons * first, struct 
 oval₋tree₋cons * last)
{
   
}

int rollback₋pop(void (^scalar)(struct oval₋tree * snapshot₋sometime), struct 
 oval₋tree₋cons * first, struct oval₋tree₋cons * last) { }

int main()
{
   if (necklace₋init(0,0,left₋hand.materialºª,left₋hand.last)) { return 1; }
   if (append₋at₋end(1,0,left₋hand.materialºª,left₋hand.last)) { return 2; }
   if (append₋at₋end(1,0,left₋hand.materialºª,left₋hand.last)) { return 3; }
   if (unqueue(1,0,left₋hand.materialºª,left₋hand.last)) { return 4; }
   if (rollback₋pop(0,left₋hand.materialºª,left₋hand.last)) { return 5; }
   if (necklace₋uninit(0,left₋hand.materialºª,left₋hand.last)) { return 7; }
   return 0;
}

/* \also 'sys/queue.h'. */

