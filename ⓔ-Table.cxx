/*  ⓔ-Table.cxx | render table with scalars and intervals. */

int next₋token₂(struct language₋context * ctxt, 
 struct token₋detail * detail₋out)
{
   return 0;
}

int recur₋descent₋table(struct token₋detail * primary, struct token₋detail * lookahead)
{
   return 0;
}

int Rendertable(struct language₋context * ctxt, History * history, 
 struct Unicodes computation₋program, chronology₋instant when)
{ struct token₋detail primary₋piece,lookahead; char * name;
   if (next₋token₂(ctxt,&primary₋piece)) { print("zero-to-one-token program\n"); goto unagain; }
again:
   if (next₋token₂(ctxt,&primary₋piece)) goto unagain;
   if (recur₋descent₋table(&primary₋piece,&lookahead)) goto unagain;
#if defined TRACE₋TOKENS
   char * tokenname(int);
   name = tokenname(primary₋piece.token);
   print("⬚ (⬚ ⬚ ⬚ ⬚ ⬚)\n", ﹟s7(name), ﹟d(primary₋piece.column₋first), 
    ﹟d(primary₋piece.column₋last), ﹟d(primary₋piece.lineno₋first), 
    ﹟d(primary₋piece.lineno₋last), 
    ﹟s8(primary₋piece.predecessor₋src->source₋path));
#endif
   goto again;
unagain:
#if defined TRACE₋TOKENS
   print("\n");
#endif
   return 0;
}
