/*  ∎|∎ relat.c | await a message loop. */

#include <Twinbeam.h>
#include <time.h>
#define _XOPEN_SOURCE
#include <ucontext.h>

int InitiateTask()
{
   return 0;
}

int ShutdownTask()
{
   return 0;
}

#pragma recto asynchronous jobbing

typedef struct __coro_t {
  coro_function_t function;
  ucontext_t original;
  __builtin_int_t buffer1[50];
  ucontext_t overlay;
  __builtin_int_t buffer2[50];
  __builtin_int_t yield;
  int finished;
} coro_t; /* a․𝘬․a Task_builtinint. */

int CopyCleanup()
{
   return 0;
}

int corout₋installInstruction(coro_t * coro)
{
   const int execution₋micros = 100*1000;
   coro_feedback(coro,execution₋micros);
   print("Install start\n");
   return coro->filecount; /* zero files copied. */
}

int corout₋runscript(coro_t * coro)
{
   print("Modify runtime\n");
   return 0;
}

int CopyStartup() /* a․𝘬․a DoAsynchronousJob() */
{
   print("This is still an synchronous function\n");
   int bytes = sizeof(struct __coro_t);
   coro_t * coro = (coro_t *)malloc(bytes);
   coro->files = { 2, { "/tmp/abc", "/tmp/bac" } };
   coro = coro_await(coro,corout₋installInstruction);
   if (coro == NULL) { return -1; }
   print("Task 'install' expected to consume ⬚ µs\n", ﹟d(coro->yield));
   if (coro_resume(coro)) { return -2; }
   print("Task 'install' copied ⬚ files\n", ﹟d(coro->yield));
   coro_t * coro₋last = coro_await(corout₋runscript);
   if (coro₋last == NULL) { return -3; }
   return 0;
}

#pragma recto main entry point

struct progress { __builtin_uint_t bytes,total; } progress;

int
main(
  int argc, 
  char ** argv
)
{
   if (InitiateTask()) { exit(1); }
   if (CopyStartup()) { exit(2); }
   CopyCleanup();
   ShutdownTask();
   return 0;
}

/* clang -g -I../Twinbeam/ -o relat '∎|∎ relat.c' \
    ../Twinbeam/Release/libTwinbeam-macos.a */

