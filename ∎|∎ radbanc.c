/*  radbanc.c | linked-list and no reorganization allowed. */

import Twinbeam;

struct oval₋tree { unicode₋shatter name; };

union oval₋tree₋continuation { struct oval₋tree * next; __builtin_uint_t possibly₋maybe; };

struct necklace { struct oval₋tree₋continuation * materialºª,last; } left₋hand;


struct oval₋tree₋cons { struct oval₋tree item; union oval₋tree₋continuation nxt; };
/*  non-'circular' therefore single-linked. */

int necklace₋init() { }

int necklace₋uninit() { }

int append₋at₋end() { }

int unqueue() { }

int rollback() { }

int main()
{
   left₋hand.materialºª = Cons₋alloc(sizeof(struct oval₋tree));
   if (append₋at₋end()) { return 1; }
   if (append₋at₋end()) { return 2; }
   if (unqueue()) { return 3; }
   if (rollback()) { return 4; }
   return 0;
}

/* \also 'sys/queue.h'. */

