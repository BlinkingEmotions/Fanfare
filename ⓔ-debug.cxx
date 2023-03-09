/*  ⓔ-debug.cxx | routines for when finding errors in compiler. */

void print₋decoded₋text(struct Unicodes ucs)
{ char32̄_t uc;
   __builtin_int_t ext₋count=0,i=0;
again:
   if (i >= ucs.tetras) { goto unagain; }
   uc = *(i + ucs.unicodes);
   print("U+");
   Base𝕟((__builtin_uint_t)uc,16,4,^(char zero₋to₋nine) { 
     print("⬚", ﹟c7(zero₋to₋nine));
   });
   if (uc & 0xffff0000) { ext₋count += 1; print("⌜"); } else { print(" "); }
unagain:
   print("(ext₋count=⬚)\n", ﹟d(ext₋count));
}


inexorable void fier(struct collection * identifiers, Symbol symbol)
{ struct source₋location interval = symbol.gritty.interval;
   print("token 'ident' and regular=⬚ is retrieved as '⬚'. (col. ⬚-⬚, line ⬚-⬚)\n", 
    ﹟d(symbol.gritty.store.regular), ﹟ident(identifiers,symbol.gritty.store.regular), 
    ﹟d(interval.column₋first), ﹟d(interval.column₋last), 
    ﹟d(interval.lineno₋first), ﹟d(interval.lineno₋last));
}

inexorable void mger(Symbol symbol)
{struct source₋location interval = symbol.gritty.interval;
   print("token 'integer-constant' and ⬚. (col. ⬚-⬚, line ⬚-⬚)\n", 
    ﹟d(symbol.gritty.store.integer), ﹟d(interval.column₋first), ﹟d(interval.column₋last), 
    ﹟d(interval.lineno₋first), ﹟d(interval.lineno₋last));
}

inexorable void fger(Symbol symbol)
{ struct source₋location interval = symbol.gritty.interval;
   print("token 'fixpoint-constant' and ⬚. (col. ⬚-⬚, line ⬚-⬚)\n", 
    ﹟d(symbol.gritty.store.integer), ﹟d(interval.column₋first), ﹟d(interval.column₋last), 
    ﹟d(interval.lineno₋first), ﹟d(interval.lineno₋last));
}

void trace₋token(Symbol symbol, struct collection * identifiers)
{ struct source₋location interval = symbol.gritty.interval;
   typedef void (^Print)(char *);
   Print token = ^(char * rendition)
   { 
    print("token ⬚. (col. ⬚-⬚, line ⬚-⬚)\n", 
    ﹟s7(rendition), ﹟d(interval.column₋first), ﹟d(interval.column₋last), 
    ﹟d(interval.lineno₋first), ﹟d(interval.lineno₋last)); };
   switch(symbol.class)
   {
   case ident: fier(identifiers,symbol); break;
   case machine: mger(symbol); break;
   case monetary: fger(symbol); break;
   case times: token("'*'"); break;
   case divide: token("'/'"); break;
   case plus: token("'+'"); break;
   case minus: token("'-'"); break;
   case lparen: token("'('"); break;
   case rparen: token("')'"); break;
   /*  case eqltwo: token("'==' (two letters)"); break;     
   case neg: token("'<>'"); break;     
   case lss: token("'<'"); break;      
   case leq: token("'<='"); break;     
   case gtr: token("'>'"); break;      
   case geq: token("'>='"); break; */
   case eqlone: token("'=' (one symbol)"); break;
   case transcriptsym: token("TRANSCRIPT"); break;
   case instant: token("<instant>"); break;
   case bookkeepsym: token("'BOOKKEEP"); break;
   case debetsym: token("'DEBET'"); break;
   case creditsym: token("'CREDIT'"); break;
   case commentsym: token("'COMMENT'"); break;
   case varsym: token("'VAR'"); break;
   case printsym: token("'PRINT'"); break;
   case breaksym: token("'BREAK'"); break;
   case setsym: token("'SET'"); break;
   case returnsym: token("'RETURN'"); break;
   case dosym: token("'DO'"); break;
   /* case ifsym: token("'IF'"); break;
   case thensym: token("'THEN'"); break;
   case elsesym: token("'ELSE'"); break; */
   case endsym: token("'END'"); break;
   case beforesym: token("'BEFORE'"); break;
   /* case andsym: token("'AND'"); break;
   case orsym: token("'OR'"); break;
   case notsym: token("'NOT'"); break;
   case xorsym: token("'XOR'"); break; */
   case entitysym: token("'ENTITY'"); break;
   case accountsym: token("'ACCOUNT'"); break;
   case tablesym: token("'TABLE'"); break;
   case createsym: token("'CREATE'"); break;
   case namedsym: token("'NAMED'"); break;
   case tradingsym: token("'TRADING'"); break;
   case residentsym: token("'RESIDENT'"); break;
   case withsym: token("'WITH'"); break;
   case schedulesym: token("'SCHEDULE'"); break;
   case startssym: token("'STARTS'"); break;
   case occurssym: token("'OCCURS'"); break;
   case exchangesym: token("'EXCHANGE'"); break;
   case currencysym: token("'CURRENCY'"); break;
   /* case lbracksym: token("'['"); break;      
   case rbracksym: token("']'"); break; */
   case popsym: token("'POP'"); break;
   case swapsym: token("'SWAP'"); break;
   case dupsym: token("'DUP'"); break;
   case reportsym: token("'REPORT'"); break;
   case boldsym: token("'BOLD'"); break;
   case eot₋and₋file: return token("eot"); break;
   case unarbitrated₋symbol: token("unarbitrated"); break;
   default: vfprint("token '⬚' not recognized.\n",﹟d(symbol.class));
   }
}
