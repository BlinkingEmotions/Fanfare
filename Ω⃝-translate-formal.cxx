/*  Ω⃝-translate-formal.cxx | interpreters and compilers. */

struct source₋location {
  __builtin_int_t lineno₋first,lineno₋last,column₋first,column₋last;
};

void location₋init(struct source₋location * location)
{
   struct source₋location initial = { 1, 1, 1, 1 };
   *location = initial;
}

void location₋nextcolumn(struct source₋location * location)
{
   location->column₋first = 1 + location->column₋last;
   location->column₋last = location->column₋first;
}

void location₋symbol(struct source₋location * location, int width, 
 struct source₋location * out)
{
   location->column₋last = width + location->column₋first - 1;
   *out = *location;
   location->column₋last += 1;
   location->column₋first = location->column₋last;
}

void location₋nextline(struct source₋location * location)
{
   location->lineno₋first += 1;
   location->lineno₋last = location->lineno₋first;
   location->column₋first = location->column₋last = 1;
}

Argᴾ ﹟regularpool(struct collection * 🅗, Nonabsolute relative)
{
   Symbolfragment job = ^(symbol₋present ucout, void * ctxt) {
     if (regularpool₋at(🅗,relative, 
       ^(short symbols₋total, short fragments, short symbols[], char32̄_t * segment[]) {
         for (int i=0; i<fragments; i+=1) {
         /*  print("(segment-length is ⬚ of ⬚ fragments)",﹟d(symbols[i]), ﹟d(fragments)); */
           ucout(symbols[i],segment[i]);
         }
       })) { ucout(7,U"<empty>"); }
   };
   return ﹟λ₂(job,0);
}

struct tabcontext { short indentation; };

Argᴾ ﹟indent(int times, struct tabcontext * ctxt)
{
   Serialfragment job = copy₋block(^(serial₋present u8out, void * cxt) {
     int i=0;
again:
     if (i >= times + ctxt->indentation) goto unagain;
     u8out(U8(" "),1);
     i+=1; goto again;
unagain:
     ;
   });
   return ﹟λ₁(job,0);
}

