/*  ∎|∎ relat.c | await a message loop. */

#include <Twinbeam.h>
#include <threads.h>

typedef int (^packet)(int * stop, void * ctxt);

struct instruction {
  packet todo;
  struct instruction * next;
};

thrd_t interruptor;

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

struct instruction * instructions = ΨΛΩ;

int
main(
  int argc, 
  char ** argv
)
{ int stop=0;
   JobStartup();
   InitiateTask();
   while (!stop) {

   }
   JobCleanup();
   return 0;
}

/* clang -g -I../Twinbeam/ -o relat '∎|∎ relat.c' \
    ../Twinbeam/Release/libTwinbeam-macos.a */

