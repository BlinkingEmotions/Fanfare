/*  ⓔ-simulator.cxx |  movement Brownian and advance like Monte-Carlo. */

#define EXIT_INTERACTIVE 1
#define EXIT_APPLICATION 2
#define CONTINUE_INTERACT 3

int EvaluateCommand(char8₋t * entered)
{
   print("Entered '⬚'.\n", ﹟s8(entered));
   return CONTINUE_INTERACT;
} /* recognize keyword and one alternatively two arguments: 
  quit, help, list schedule|entity|currency|exchange, 
  general <entity>, inspect <entity>, 
  continue, step statement|iteration. */

void EnterInteractiveMode(int * quit, Simulator * 🅢)
{ int y=0; 🅢->prompt_number=1;
   while (y != EXIT_INTERACTIVE && y != EXIT_APPLICATION)
   {
#if defined STDIO_READLINE
     print("In[⬚]:= ",﹟d(🅢->prompt_number));
     size_t cap; char * line=0; getline(&line,&cap,stdin);
#else
     char prompt[100];
     sprintf(prompt,"In[%lld]:= ",🅢->prompt_number);
     char * line = readline(prompt);
     if (line && *line) add_history(line);
#endif
     print("\nOut[⬚]=\n\n",﹟d(🅢->prompt_number));
     y = EvaluateCommand((char8₋t *)line);
     🅢->prompt_number+=1;
   }
   *quit = (y == EXIT_APPLICATION);
}

int Simulate(simul₋context * 🆂, Simulator * 🅢)
{
   return 0;
}

