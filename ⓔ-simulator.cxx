/*  ⓔ-simulator.cxx | movement Brownian and advance like Monte-Carlo. */

int Conversion(Instant instant, Real value, Nonabsolute src, Nonabsolute dst, Real * also)
{
   return 0;
}

int IsReversed(Nonabsolute left, Nonabsolute right, struct collection * ident)
{
   __builtin_int_t ﹟₋left = *(uint32_t *)collection₋relative(left,ident);
   __builtin_int_t ﹟₋right = *(uint32_t *)collection₋relative(right,ident);
   char32̄_t ucl,ucr; int ldx=1,rdx=1;
agai:
   if (ldx >= ﹟₋left || rdx >= ﹟₋right) goto note;
   ucl = *(char32̄_t *)collection₋relative(ldx+left,ident);
   ucr = *(char32̄_t *)collection₋relative(rdx+right,ident);
   if (ucr != ucl) goto note;
   ldx+=1,rdx+=1;
   goto agai;
note:
   return ldx == ﹟₋left && rdx == ﹟₋right;
}

#define EXIT_INTERACTIVE 1
#define EXIT_APPLICATION 2
#define CONTINUE_INTERACT 3

int list(char * concept)
{
   if (strcmp(concept,"schedule") == 0) { }
   else if (strcmp(concept,"entity") == 0) { }
   else if (strcmp(concept,"currency") == 0) { }
   else if (strcmp(concept,"exchange") == 0) { }
   return CONTINUE_INTERACT;
}

int general(char * entity)
{
   return CONTINUE_INTERACT;
}

int inspect(char * entity)
{
   return CONTINUE_INTERACT;
}

int step(char * granularity)
{
   return CONTINUE_INTERACT;
}

int table(char * tablepath)
{
   return CONTINUE_INTERACT;
}

int Execute(int count, char * seqce[])
{
   if (strcmp(seqce[0], "quit") == 0) { return EXIT_APPLICATION; }
   else if (strcmp(seqce[0], "help") == 0) { 
     print(
     "The turbin shell responds to a selection of keywords with zero "
     "alternatively one argument:\n\n · list schedule|entity|"
     "currency|exchange,\n · general <entity>,\n · inspect <entity>,\n · "
     "continue,\n · step statement|iteration,\n · table <filepath>,\n · "
     "quit,\n · help.\n\n"); }
   else if (strcmp(seqce[0], "continue") == 0) { return EXIT_INTERACTIVE; }
   else if (strcmp(seqce[0], "list") && count == 2) { return list(seqce[1]); }
   else if (strcmp(seqce[0], "general") && count == 2) { return general(seqce[1]); }
   else if (strcmp(seqce[0], "inspect") && count == 2) { return inspect(seqce[1]); }
   else if (strcmp(seqce[0], "step") && count == 2) { return step(seqce[1]); }
   else if (strcmp(seqce[0], "table") && count == 2) { return table(seqce[1]); }
   else print("Unknown turbine command '⬚' (⬚ parameters).\n\n",﹟s7(seqce[0]),﹟d(count-1)); /* for later before and after and intervallic subreport. */
   return CONTINUE_INTERACT;
}

int EvaluateCommand(char8₋t * entered)
{
   /* print("Entered '⬚'.\n", ﹟s8(entered)); */
   const char * delim = " \t"; char * state;
   char * first = strtok_r((char *)entered,delim,&state);
   if (first == NULL) return CONTINUE_INTERACT;
   char * second = strtok_r(NULL,delim,&state);
   char * one[] = { first }, *two[] = { first, second };
   if (second == NULL) return Execute(1,one);
   else return Execute(2,two);
   return CONTINUE_INTERACT;
} /* recognize keyword and zero alternatively one arguments: 
  quit, help, list schedule|entity|currency|exchange, 
  general <entity>, inspect <entity>, continue, step 
  statement|iteration, table <filepath>. */

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

