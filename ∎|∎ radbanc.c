/* ⎔⃚ radbanc.c | linked-list later with no reorganization allowed. */

import Twinbeam;

struct oval₋tree { unicode₋shatter name; };

union oval₋tree₋continuation { /* prominent */ struct oval₋tree₋cons * next; __builtin_uint_t possibly₋maybe; };

struct oval₋tree₋cons { struct oval₋tree item; union oval₋tree₋continuation nxt; };
/*  non-'circular' therefore single-linked. */

int rollback₋pop(void (^)(struct oval₋tree *), struct oval₋tree₋cons **, struct oval₋tree₋cons **);
int unqueue(int, void (^)(int, struct oval₋tree **), struct oval₋tree₋cons **, struct oval₋tree₋cons **);
int append₋at₋end(int, void (^)(int, struct oval₋tree **), struct oval₋tree₋cons **, struct oval₋tree₋cons **);
int is₋empty(struct oval₋tree₋cons *, struct oval₋tree₋cons *);
typedef void (^Every)(struct oval₋tree *);
void recollect(Every, struct oval₋tree₋cons **, struct oval₋tree₋cons **);

struct necklace { struct oval₋tree₋cons * materialºª,*last; } left₋hand;

int necklace₋init(int count, void (^init)(int count, struct oval₋tree ** 
 uninited₋sometime), struct oval₋tree₋cons ** first, struct oval₋tree₋cons ** last)
{ int i=0; struct oval₋tree₋cons * current; /* curl, div and rot. */
   *first = *last = 0; struct oval₋tree * collecta[count];
again:
   if (i >= count) { goto unagain; }
   current = Cons₋alloc(sizeof(struct oval₋tree));
   current->nxt.next = *first;
   *first = current;
   collecta[i] = &current->item;
   i+=1; goto again;
unagain:
   init(count,collecta);
   return 0;
}

int necklace₋uninit(void (^before)(int count, struct oval₋tree ** 
 snapshot₋sometime), struct oval₋tree₋cons ** first, struct oval₋tree₋cons ** last)
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
   before(count,first₋element);
   return 0;
}

int is₋empty(struct oval₋tree₋cons * first, struct oval₋tree₋cons * last)
{
   return first == 0 && last == 0;
}

void recollect(Every element, struct oval₋tree₋cons ** first, struct oval₋tree₋cons ** last)
{ struct oval₋tree₋cons * current = *first;
again:
   if (current == 0) { return; }
   element(&current->item);
   current = current->nxt.next; goto again;
}

int append₋at₋end(int count, void (^augment)(int count, struct oval₋tree ** 
 uninited₋sometime), struct oval₋tree₋cons ** first, struct oval₋tree₋cons ** last)
{ int i=0; struct oval₋tree₋cons * cached,*lait₋tail; 
   struct oval₋tree * collecta[count];
again:
   if (i >= count) { goto unagain; }
   cached = *last;
   lait₋tail = Cons₋alloc(sizeof(struct oval₋tree));
   collecta[i] = &lait₋tail->item;
   cached->nxt.next = lait₋tail;
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
{ int i=0; struct oval₋tree * collecta[count];
again:
   if (i >= count) { goto unagain; }
   if (*first == 0) { goto unagain; }
   collecta[i] = &(*first)->item;
   Cons₋fallow(*first);
   *first=(*first)->nxt.next;
   i+=1; goto again;
unagain:
   removed(i,collecta);
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

