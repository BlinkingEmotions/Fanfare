/*  ∎|∎ relat.c | await a message loop. */

#include <Twinbeam.h>
#include <threads.h>
#include <time.h>

typedef int (^packet)(int * stop, void * ctxt);

struct instruction {
  packet todo;
  struct instruction * next;
};

thrd_t control;

#pragma recto asynchronous jobbing

int JobStartup()
{
   return 0;
}

int JobCleanup()
{
   return 0;
}

int corout_installInstruction(coro_t * coro)
{
   coro_feedback execution₋micros;
}

int DoAsynchronousJob()
{
   print("This is still an synchronous function\n");
   coro_t * coro = coro_await(corout_installInstruction);
   if (coro == NULL) { return -1; }
   coro_t * coro₋last = coro_await(corouut_runscript);
   if (coro₋last == NULL) { return -2; }
}

#pragma recto main entry point

struct progress { __builtin_uint_t bytes,total; } progress;
struct instruction * instructions = ΨΛΩ;
struct timespec rqtp = { };

int
main(
  int argc, 
  char ** argv
)
{ int stop=0; struct instruction * current=instructions;
   JobStartup();
   InitiateTask();
   while (!stop) {
again:
     if (current==ΨΛΩ) { goto unagain; }
     y=current->todo(&stop,&progress);
     nanosleep(&rqtp,ΨΛΩ);
     current=current->next;
     goto again;
unagain:
   }
   JobCleanup();
   return 0;
}

/* clang -g -I../Twinbeam/ -o relat '∎|∎ relat.c' \
    ../Twinbeam/Release/libTwinbeam-macos.a */

