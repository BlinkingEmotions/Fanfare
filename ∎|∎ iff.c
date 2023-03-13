/*  iff.c | exhaustive on dates and caledric matters. */

import Twinbeam;
#include <time.h>
#include <stdio.h>

void correct()
{ int incl₋frac = 0; chronology₋UQ32 frac=0;chronology₋instant v;
   /* Julandatno day = Tellus(1,31,2021); */
   int32_t material[] = { 2021, 1, 31, 11, 30, 10 };
   /* create₋ */ instant(material,frac,&v);
   present₋instant(v,incl₋frac,^(char digitHyphenColonPeriodOrSpace) {
    print("⬚", ﹟c7(digitHyphenColonPeriodOrSpace));
   });
   Juliandayno d; int32_t h,m,s; chronology₋UQ32 frac2;
   reveille(v,&d,&h,&m,&s,&frac2);
   char32̄_t * material2 = U"2022-01-31 11:30:15"; 
   if (Timestamp(encoding₋unicode,19*4,(uint8_t *)material2,&v)) 
    ENSURE(false,"error read and write.");
}

int main()
{ int y,M,d,incr=0; struct tm date, *gm;
   print("exhaustive date printout.\n");
   //  { 2400000+incr, 2400001+incr }; /* increments-increase at noon. */
   date.tm_year=1858; date.tm_mon=11; date.tm_mday=17;
   date.tm_hour=11;   date.tm_min=30; date.tm_sec=10;
again:
   if (incr >= 300) goto unagain;
   time_t nt = mktime(&date) + incr; /* seconds from epoch is nt. */
   nt += (incr*24*60*60) - incr;
   gm = gmtime(&nt);
   char * stored; struct tm gm2; time_t t2;
   asprintf(&stored,"%d-%.2d-%.2d %.2d:%.2d:%.2d", gm->tm_year, gm->tm_mon,
     gm->tm_mday, gm->tm_hour, gm->tm_min, gm->tm_sec);
   fprintf(stderr,"%s.\n", stored);
   int r = sscanf(
      stored, "%d-%d-%d %d:%d:%d",
      &gm2.tm_year, &gm2.tm_mon, &gm2.tm_mday,
      &gm2.tm_hour, &gm2.tm_min, &gm2.tm_sec);
   if (r != 6) fprintf(stderr, "error sscanf\n");
   t2 = timegm(&gm2);
   if (t2 != nt) fprintf(stderr,"error t2 is %jd and nt is %jd and stored is %s.\n", 
   	(intmax_t)t2,(intmax_t)nt,stored);
   free(stored);
   incr+=1; goto again;

/*
   Juliandayno day = 2400000; / * 17 nov, 1858 

   Juliandate(day,&M,&d,&y);

    union Tp₋stomp ptn; ptn.bits=v;
  
   ENSURE(day=12347643, "error in Juliandate");
   ENSURE(d=1,"error in day");
   
   Juliandayno dayno = 2400000 + nt/(24*60*60);

   chronology₋instant v; 
   uint8_t * material = (uint8_t *)U"2023-03-09 13:29:12 ";
   */
unagain:
   print("*** finished printout ***\n");

   return 0;
}

/* clang -g -fmodules-ts -fimplicit-modules -fmodule-map-file=🚦.modules      \
 '∎|∎ iff.c' ../Apps/Source/Releases/libTwinbeam-x86_64.a */
