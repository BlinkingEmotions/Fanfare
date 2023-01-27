/*  radbanc.c | linked-list and no reorganization allowed. */

import Twinbeam;

struct oval₋tree { unicode₋shatter name; };

union oval₋tree₋continuation { struct oval₋tree * next; __builtin_uint_t possibly₋maybe; };

struct oval₋tree₋cons { struct oval₋tree item; union oval₋tree₋continuation nxt; };
/*  non-'circular' therefore single-linked. */

struct necklace { struct oval₋tree₋cons * materialºª,last; } left₋hand;

int necklace₋init(int count, void (^init)(int count, struct oval₋tree ** sometime)) { }

int necklace₋uninit(void (^uninit)(int count, struct oval₋tree ** sometime)) { }

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

