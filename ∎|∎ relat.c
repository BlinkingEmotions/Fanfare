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

extern struct instructions * instructions;

void InitiateTask()
{
   return 0;
}

#pragma recto asynchronous jobbing

int CopyStartup()
{
   return 0;
}

int CopyCleanup()
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
   print("Task expected to consume ⬚ µs\n", coro->yield);
   int y = coro_resume(coro);
   if (y) { return -2; }
   coro_t * coro₋last = coro_await(corout_runscript);
   if (coro₋last == NULL) { return -3; }
}

#pragma recto main entry point

struct progress { __builtin_uint_t bytes,total; } progress;
struct instruction * instructions = ΨΛΩ;
struct timespec buffer = { };

typedef struct __coro_t {
  coro_function_t function;
  ucontext_t original;
  __builtin_int_t buffer1[50];
  ucontext_t overlay;
  __builtin_int_t buffer2[50];
  __builtin_int_t yield;
  int finished;
};

int
main(
  int argc, 
  char ** argv
)
{ int stop=0; struct instruction * current=instructions;
   CopyStartup();
   InitiateTask();
   while (!stop) {
again:
     if (current==ΨΛΩ) { goto unagain; }
     y=current->todo(&stop,&progress);
     nanosleep(&buffer,ΨΛΩ);
     current=current->next;
     goto again;
unagain:
   }
   CopyCleanup();
   return 0;
}

/* clang -g -I../Twinbeam/ -o relat '∎|∎ relat.c' \
    ../Twinbeam/Release/libTwinbeam-macos.a */

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

extern struct instructions * instructions;

void InitiateTask()
{
   return 0;
}

#pragma recto asynchronous jobbing

int CopyStartup()
{
   return 0;
}

int CopyCleanup()
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
   print("Task expected to consume ⬚ µs\n", coro->yield);
   int y = coro_resume(coro);
   if (y) { return -2; }
   coro_t * coro₋last = coro_await(corout_runscript);
   if (coro₋last == NULL) { return -3; }
}

#pragma recto main entry point

struct progress { __builtin_uint_t bytes,total; } progress;
struct instruction * instructions = ΨΛΩ;
struct timespec buffer = { };

typedef struct __coro_t {
  coro_function_t function;
  ucontext_t original;
  __builtin_int_t buffer1[50];
  ucontext_t overlay;
  __builtin_int_t buffer2[50];
  __builtin_int_t yield;
  int finished;
};

int
main(
  int argc, 
  char ** argv
)
{ int stop=0; struct instruction * current=instructions;
   CopyStartup();
   InitiateTask();
   while (!stop) {
again:
     if (current==ΨΛΩ) { goto unagain; }
     y=current->todo(&stop,&progress);
     nanosleep(&buffer,ΨΛΩ);
     current=current->next;
     goto again;
unagain:
   }
   CopyCleanup();
   return 0;
}

/* clang -g -I../Twinbeam/ -o relat '∎|∎ relat.c' \
    ../Twinbeam/Release/libTwinbeam-macos.a */

