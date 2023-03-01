/*  cabinet-detail.c | multiple-name text filing and the coroutine. (INITIALLY₋NON-EXPIRING) */

import Twinbeam;

#include <unistd.h> /* declaration of 'readlink'. */
#include <fcntl.h>
#define _POSIX_C_SOURCE /* selects high-precision stat and a modern inode. */
#include <sys/stat.h>
#include <dirent.h>

enum expiration { read₋once, after₋seven₋days, after₋seven₋years };

enum textfile₋aloha { doodle, file, initially₋committed, unstaged, staged, balanced };

typedef void (^Response)(char32̄_t * ucs, __builtin_int_t bytes);

EXT₋C int Order(Response out, char32̄_t * command, ...);

struct Unicodes void₋path() { struct Unicodes epsilon = { 36, U"9E4A34A9-D501-41F6-9C1C-238F96A00CC2" }; return epsilon; }

union guid₋shim { struct guid composite; __uint128_t machine; };

typedef struct guid openfile₋guid;
typedef openfile₋guid openfile₋id;

thesaurus₋ref guid₋and₋secondary=ΨΛΩ,guid₋and₋primary=ΨΛΩ; /* persisted index on ssd and two inodes. */
regular₋ref opened₋files=ΨΛΩ; /* not persisted on ssd, only recorded in virtual memory. */

char8₋t * repo = U8("/tmp/cabinet-petite");

#pragma recto mentatives to create application-textfile, project₋textfile and 'additional₋textfile'

int create₋application₋detail(Response out, openfile₋id * regular)
{
   return 0;
} /* revision handled text file in primary memory that may be upgraded to a non-doodle file and multiple names. */

int create₋collocation(Response out, struct Unicodes path, openfile₋id * regular)
{
   return 0;
} /* a text file shared by multiple applications and unrevisioned. */

int augment₋application₋with₋detail(Response out, openfile₋id * regular)
{
   return 0;
} /* augments revision-handled text file with additional file. */

int open₋persisted₋detail(Response out, union guid₋shim anchor, openfile₋id * regular) ⓣ
{
   return 0;
}

int open₋persisted₋detail(Response out, struct Unicodes primaryOrSecondary, openfile₋id * regular) ⓣ
{
   return 0;
}

int promote₋doodle₋to₋file(Response out, openfile₋id regular, 
 struct Unicodes primary, struct Unicodes secondary) ⓣ
{
   return 0;
}

int promote₋doodle₋to₋file(Response out, openfile₋id regular, 
 struct Unicodes either, int secondary) ⓣ
{
   return 0;
}

int discard₋if₋doodle(openfile₋id regular)
{
   return 0;
} /* conditionally removes file if not been upgraded to non-doodle. */

inexorable int initial₋commit(openfile₋id regular)
{
   return 0;
}

inexorable int stage₋nondoodle(openfile₋id regular)
{
   return 0;
}

inexorable int commit₋nondoodle(openfile₋id regular)
{
   return 0;
}

inexorable int openfile₋status(openfile₋id regular, enum textfile₋aloha * state)
{
   return 0;
}

int process₋file(openfile₋id regular)
{ enum textfile₋aloha state;
   if (openfile₋status(regular,&state)) { return -1; }
   switch (state)
   {

   }
   return 0;
}

int main()
{ openfile₋id textfile;
   Response out = ^(char32̄_t * ucs, __builtin_int_t bytes) { 
    print("response: '⬚'.\n", ﹟S(bytes,ucs)); };
   if (create₋application₋detail(out,&textfile)) { return -1;}
   return 0;
}

#pragma recto not yet brilliant wording

int create₋textfile(struct Unicodes primary, struct Unicodes secondary, int expiration, openfile₋id * regular)
{
   /*( cancellation int cancel-and-singlelinked and file-expiration. */ /* and chronologic expiration. */
   /* primaries: |idx|->|idx|->/ secondaries: |idx|->\ */
    char8₋t stored₋secondary[secondary.tetras*4],stored₋primary[primary.tetras*4]; __builtin_int_t u8bytes;
   if (UnicodeToUtf8(secondary.tetras,secondary.unicodes,stored₋secondary,&u8bytes)) { return -1; }
   if (UnicodeToUtf8(primary.tetras,primary.unicodes,stored₋primary,&u8bytes)) { return -1; }
   char8₋t * primary₋path=U8(""),*secondary₋path=U8("");
   int fd₋primary = open((const char *)primary₋path, O_EXCL | O_CREAT);
   if (fd₋primary == -1) { return -1; }
   if (link((const char *)primary₋path,(const char *)secondary₋path)) { return -1; }
   int fd₋secondary = open((const char *)secondary₋path, O_SYMLINK);
   if (fd₋secondary == -1) { return -1; }
   union guid₋shim fineprint = { .composite=Guid() };
   int * material = (int *)Alloc(sizeof(int)+sizeof(int));
   material[0]=fd₋primary; material[1]=fd₋secondary;
   opened₋files = impression₋store(opened₋files,fineprint.machine,material,Alloc);
   Copy8Memory((ByteAlignedRef)regular,(ByteAlignedRef)&(fineprint.composite),sizeof(openfile₋id));
   return 0;
} 

int include₋history₋on₋file()
{
   return 0;
}

int create₋pathlist()
{
   return 0;
}

int include₋filepath₋in₋pathlist()
{
   return 0;
}

int synchronize₋collocation()
{
   return 0;
}

int synchronize₋application()
{
   return 0;
}

int Occurrence(const char c, struct Unicodes text)
{ int acc=0; char32̄_t uc;
   for (__builtin_int_t i=0; i<text.tetras; i+=1) {
     uc = *(i + text.unicodes);
     acc += (uc == c ? 1 : 0);
   }
   return acc;
}

int list₋files(struct Unicodes expression, void (^list)(int count, struct 
 Unicodes * secondary, struct Unicodes * primary, openfile₋id * regular))
{ int one₋nameext₋separator=0,multiple₋nameext₋separators=0, 
    primary₋secondary₋separator=0;
   return 0;
}

int solve(struct Unicodes expression, struct Unicodes * secondary, struct 
 Unicodes * primary, openfile₋id * regular)
{ int one₋nameext₋separator=0,multiple₋nameext₋separators=0, 
    primary₋secondary₋separator=0;
   int nameext₋count = Occurrence('.',expression);
   if (nameext₋count==1) { one₋nameext₋separator=1; }
   if (nameext₋count!=0 && nameext₋count!=1) { multiple₋nameext₋separators=1; }
   int separator₋count = Occurrence('-',expression);
   if (separator₋count!=0 || separator₋count!=1) { return -1; }
   if (separator₋count==1) { primary₋secondary₋separator=1; }
   *primary=Run(U"the primary name.txt");
   *secondary=Run(U"the secondary name.txt");
   __uint128_t fineprint = 1;
   struct w₋node * node = impression₋seek(opened₋files,fineprint);
   if (node == ΨΛΩ) { return -1; }
   int fd = *(int *)(node->note);
   struct stat sb; if (fstat(fd,&sb)==-1) { return -1; }
   __builtin_int_t device₋id=sb.st_dev, inode₋number=sb.st_ino, 
    hard₋links=sb.st_nlink, byte₋size=sb.st_size, userdef=sb.st_flags, 
    file₋generation=sb.st_gen;
   uint64_t last₋access=sb.st_atimensec, last₋change₋material=sb.st_mtimensec, 
    last₋change₋meta=sb.st_ctimensec, first₋created=sb.st_birthtimensec;
   print(
"device-id ⬚, inode-number ⬚, hard﹟ ⬚, bytes ⬚, last-access ⬚, last-change-meta ⬚, "
"last-change-material ⬚, userdef ⬚, file-generation ⬚, creation-point ⬚\n", 
    ﹟d(device₋id), ﹟d(inode₋number), ﹟d(hard₋links), ﹟d(byte₋size), ﹟d(last₋access), 
    ﹟d(last₋change₋meta), ﹟d(last₋change₋material), ﹟d(userdef), ﹟d(file₋generation), 
    ﹟d(first₋created));
   struct guid uuid = Guid();
   Copy8Memory((ByteAlignedRef)regular,(ByteAlignedRef)&uuid,sizeof(struct guid));
   return 0;
}

int open₋file(struct Unicodes expression, openfile₋id * regular)
{ struct Unicodes secondary,primary;
   if (solve(expression,&secondary,&primary,regular)) { vfprint("unable to solve expression into primary and secondary file names.\n"); return -1; }
   union guid₋shim fineprint = { .composite=Guid() };
   note₋ref material = Alloc(sizeof(int));
   opened₋files = impression₋store(opened₋files,fineprint.machine,material,Alloc);
   Copy8Memory((ByteAlignedRef)regular,(ByteAlignedRef)&(fineprint.composite),sizeof(struct guid));
   return 0;
}

int close₋file(openfile₋id regular)
{
   union guid₋shim fineprint = { .composite=regular };
   struct w₋node * node = impression₋seek(opened₋files,fineprint.machine);
   int * fds = (int *)(node->note);
   int fd₋primary=fds[0],fd₋secondary=fds[1];
   if (fsync(fd₋secondary) == -1) return -1;
   if (fsync(fd₋primary) == -1) return -1; 
   if (close(fd₋secondary) == -1) return -1;
   if (close(fd₋primary) == -1) return -1;
   return 0;
}

int primary₋filename₋add(struct Unicodes primary, struct Unicodes additional₋primary)
{ char8₋t primary₋existing[primary.tetras*4],prealloc₋additional[additional₋primary.tetras*4]; 
    __builtin_int_t u8bytes;
   if (UnicodeToUtf8(primary.tetras,primary.unicodes,primary₋existing,&u8bytes)) { return -1; }
   if (UnicodeToUtf8(additional₋primary.tetras,additional₋primary.unicodes,prealloc₋additional,&u8bytes)) { return -1; }
   if (symlink((const char *)primary₋existing,(const char *)prealloc₋additional)) { return -1; }
   return 0;
}

int secondary₋filename₋add(struct Unicodes secondary, struct Unicodes additional₋secondary)
{ char8₋t secondary₋existing[secondary.tetras*4],prealloc₋additional[additional₋secondary.tetras*4]; 
    __builtin_int_t u8bytes;
   if (UnicodeToUtf8(secondary.tetras,secondary.unicodes,secondary₋existing,&u8bytes)) { return -1; }
    if (UnicodeToUtf8(additional₋secondary.tetras,additional₋secondary.unicodes,prealloc₋additional,&u8bytes)) { return -1; }
   if (symlink((const char *)secondary₋existing,(const char *)prealloc₋additional)) { return -1; }
   return 0;
}

int doodle₋textfile(openfile₋id * regular)
{
   
}

int derived₋spawnfile(openfile₋id * regular)
{
   
} /* not links-file but 'tree threaded'. */

int persist₋textfile(openfile₋id regular, struct Unicodes primary, struct Unicodes secondary)
{
   
}

typedef int (*search₋text)(struct Unicodes primary, struct Unicodes secondary, 
 openfile₋id regular, __builtin_int_t lineno₋first, __builtin_int_t lineno₋last, 
 __builtin_int_t column₋first, __builtin_int_t column₋last, 
 __builtin_int_t u8₋offset);

struct outcome₋search {
   union {
     search₋text reference;
   } material;
   int kind;
};

int search₋and₋find(struct Unicodes filename, struct Unicodes filetype, int total₋rows, int row₋outside₋bound, int rows₋in₋sight, 
 int row₋expected₋soon, struct Unicodes anchor₁, struct Unicodes anchor₂, struct outcome₋search find)
{
   return 0;
} /*  replace with 'search₋location' and 'search₋interval' and search₋vironment and 'prominent'. */

typedef void (^Generated)(int count, struct Unicodes * derived₋primary, struct Unicodes * derived₋secondary);
int Generated₋files(struct Unicodes filename₋source, Generated list); /* not file-links but 'threaded tree'. */

struct text₋presentation₋forfork {
  __builtin_int_t the₋symbols; char32̄_t * the₋text; __builtin_int_t total₋rows;
  __builtin_int_t * rendering₋newlines, rendering₋newlines₋count;
  __builtin_int_t row₋inside₋bound, row₋outside₋bound, rows₋constituting₋bound;
  __builtin_int_t first₋row₋speculative, last₋row₋speculative;
}; /* a․𝘬․a 'file attributes' (such-as 'file completed') and 'computed file attributes' (such as 'list-of-functions') and 'forks'. */

struct outcome₋plausable { };

int Plausible₋display(struct text₋form input1, struct Unicodes input2, struct outcome₋plausable options);

int Plausible₋text(struct Unicodes anchor1, struct Unicodes anchor2, 
 __builtin_int_t symbols, char32̄_t * uc, struct outcome₋plausable options);

int Introduce₋program(struct Unicodes function, struct Unicodes anchor1, 
 struct Unicodes anchor2, __builtin_int_t symbols, char32̄_t * uc, 
 struct Unicode augment, struct outcome₋plausable options);
/* language is described in --<retros-compi.c> and '.detail'. */

/* struct iovec { char *iov_base; size_t iov_len; }; */

#include <sys/types.h>
#include <sys/uio.h>

ssize_t pwritev₋c(int fd, const struct iovec *iov, int iovcnt, 
 off_t byteoffsetfile, coro_t * coro, struct Act * feedback)
{ __builtin_int_t acc=0;
   for (__builtin_int_t i=0; i<iovcnt; i+=1) {
     char * dst=iov[i].iov_base; size_t nbyte=iov[i].iov_len;
     ssize_t byteswrite=pwrite(fd,dst,nbyte,byteoffsetfile+acc);
     if (byteswrite<0) { return byteswrite; }
     acc+=byteswrite;
     if (feedback) { coro_feedback(coro,(int)monoton₋ordinal(ΨΛΩ,feedback)); }
     /* if (byteswrite==0) { i=iovcnt; } */
   }
   return acc;
}

ssize_t preadv₋c(int fd, const struct iovec *iov, int iovcnt, 
 off_t byteoffsetfile, coro_t * coro, struct Act * feedback)
{ __builtin_int_t acc=0;
   for (__builtin_int_t i=0; i<iovcnt; i+=1) {
     char * dst=iov[i].iov_base; size_t nbyte=iov[i].iov_len;
     ssize_t bytesread=pread(fd,dst,nbyte,byteoffsetfile+acc);
     if (bytesread<0) { return bytesread; }
     acc+=bytesread;
     if (feedback) { coro_feedback(coro,(int)monoton₋ordinal(ΨΛΩ,feedback)); }
     if (bytesread==0) { i=iovcnt; }
   }
   return acc;
}

int reconcile₋file(openfile₋id regular, int count, uint8_t ** offset, 
 __builtin_int_t * bytes, __builtin_int_t * bytesactual, coro_t * coro, 
 struct Act * feedback)
{
   struct iovec stripes[count];
   union guid₋shim fineprint = { .composite=regular };
   struct w₋node * node = impression₋seek(opened₋files,fineprint.machine);
   if (node == ΨΛΩ) { return -1; }
   int * fds = (int *)(node->note);
   if (fds[0] == -1) { return -1; } struct stat sb;
   if (feedback) { coro_feedback(coro,(int)monoton₋ordinal(ΨΛΩ,feedback)); }
   if (fstat(fds[0],&sb) == -1) { goto err; }
   if (S_ISDIR(sb.st_mode)) { goto err; }
   if (S_ISLNK(sb.st_mode)) { goto err; } /* neither hard nor soft link. */
   if (feedback) { coro_feedback(coro,(int)monoton₋ordinal(ΨΛΩ,feedback)); }
   for (int i=0; i<count; i+=1) { stripes[i].iov_len=bytes[i]; stripes[i].iov_base=offset[i]; }
   *bytesactual = pwritev₋c(fds[0],stripes,count,0,coro,feedback);
   if (feedback) { coro_feedback(coro,(int)monoton₋ordinal(ΨΛΩ,feedback)); }
   return 0;
err:
  if (close(fds[0]) == -1) { return -2; }
  return -1;
}

int branch₋file(openfile₋id regular, int count, uint8_t ** offset, 
 __builtin_int_t * bytes, __builtin_int_t * bytesactual, coro_t * coro, 
 struct Act * feedback)
{
   struct iovec stripes[count];
   union guid₋shim fineprint = { .composite=regular };
   struct w₋node * node = impression₋seek(opened₋files,fineprint.machine);
   if (node == ΨΛΩ) { return -1; }
   int * fds = (int *)(node->note);
   if (fds[0] == -1) { return -1; } struct stat sb;
   if (feedback) { coro_feedback(coro,(int)monoton₋ordinal(ΨΛΩ,feedback)); }
   if (fstat(fds[0],&sb) == -1) { goto err; }
   if (S_ISDIR(sb.st_mode)) { goto err; }
   if (S_ISLNK(sb.st_mode)) { goto err; }
   if (feedback) { coro_feedback(coro,(int)monoton₋ordinal(ΨΛΩ,feedback)); }
   for (int i=0; i<count; i+=1) { stripes[i].iov_len=bytes[i]; stripes[i].iov_base=offset[i]; }
   *bytesactual = preadv₋c(fds[0],stripes,count,0,coro,feedback);
   if (feedback) { coro_feedback(coro,(int)monoton₋ordinal(ΨΛΩ,feedback)); }
   return 0;
err:
   if (close(fds[0]) == -1) { return -2; }
   return -1;
}

#pragma recto material and entry

struct Unicodes filename₋expression;

uint8_t material1[5] = { 1, 2, 3, 4, 5 };
uint8_t material2[7] = { 17, 16, 15, 14, 13, 13, 13 };

struct errors₋and₋diagnostics
{
   __builtin_int_t filing₋error;
} panel = { 0 };

int corout₋filing(coro_t * coro)
{
   uint8_t * offset[] = { material1, material2 };
   __builtin_int_t bytes[] = { 5, 7 },actual;
   int count = sizeof(offset)/sizeof(uint8_t *);
   struct Act act₋wr; init₋monoton(&act₋wr,1);
   coro_feedback(coro,1); openfile₋id regular;
   if (open₋file(filename₋expression,&regular)) { coro_feedback(coro,-1); }
   if (reconcile₋file(regular,count,offset,bytes,&actual,coro,&act₋wr)) { coro_feedback(coro,-2); }
   coro_feedback(coro,2);
   if (close₋file(regular)) { coro_feedback(coro,-3); }
   return 0; /* see equivalence with 'didReadWriteOrSync'. */
}

#include <removefile.h>

int demonstration₋delegate(removefile_state_t s, const char * path, void * ctx)
{
   vfprint("file deleted '⬚'\n",﹟s7((char *)path));
   return REMOVEFILE_PROCEED;
}

void cleanup()
{ removefile_state_t s=removefile_state_alloc();
   removefile_state_set(s,REMOVEFILE_STATE_CONFIRM_CALLBACK,demonstration₋delegate);
   removefile_state_set(s,REMOVEFILE_STATE_CONFIRM_CONTEXT,demonstration₋delegate);
   removefile("/tmp/zz.txt",s,ΨΛΩ);
   removefile_state_free(s);
}

int main()
{
   
   if (Play(^(struct Unicodes serial) { 
      print(" ⬚ ", ﹟S(serial));
   }, U"hello world  ⬚ ", ﹟S(U"again"))) { return 1; }
   struct Unicodes text = Run(UC("/"));
 
 //  Response out = ^(char32̄_t * ucs, __builtin_int_t bytes) { print("⬚",﹟S(bytes,ucs)); };
 //  Order(out, U"ls -la '⬚'", ﹟S(text));

#ifdef x
   filename₋expression = Run(U"hello world.txt");
   /* cleanup(); */
   /* initial episode filing attempt with given file name. */
   openfile₋id regular;
   uint8_t * offset[] = { material1,material2 }; __builtin_int_t bytes[] = { 5,7 },actual;
   int count = sizeof(offset)/sizeof(uint8_t *);
   if (create₋textfile(filename₋expression,void₋path(),0,&regular)) { vfprint("error when create₋file.\n"); }
   if (reconcile₋file(regular,count,offset,bytes,&actual,0,0)) { vfprint("error during reconcillation.\n"); }
   if (close₋file(regular)) { vfprint("error at close.\n"); }
   if (open₋file(filename₋expression,&regular)) { vfprint("unable to open file.\n"); }
   if (branch₋file(regular,count,offset,bytes,&actual,0,0)) { vfprint("error unable to branch.\n"); }
   if (close₋file(regular)) { vfprint("error when close.\n"); }
   /* filing episodes and coroutine attempt. */
   coro_t * coro = coro_await(corout₋filing); int yield;
again:
   yield = coro_resume(coro);
   if (yield == 0) { goto unagain; }
   if (yield <= -1) { Pult(panel.filing₋error); goto err; }
   vfprint("filing coroutine reported ⬚.\n", ﹟d((__builtin_int_t)yield));
   goto again;
err:
   vfprint("error while running coroutine ⬚.\n", ﹟d((__builtin_int_t)yield));
unagain:
   coro_free(coro);
#endif
   return 0;
}

/* compile with ./retro-mac.sh cabinet-detail 
 
 xcrun clang -g -fmodules-ts -fimplicit-modules -fmodule-map-file=🚦.modules \
  -o cabinet-detail -DSHA1GIR=\"`git log -1 '--pretty=format:%h'`\"          \
  '􀐒 cabinet-detail.c' ../Apps/Source/Releases/libTwinbeam-x86_64.a        \
  ../Apps/Additions/monolith-sequent.c                                       \
  ../../Cox-route/context-1.S                                                \
  ../../Cox-route/context-2.c                                                \
  ../../Cox-route/coro-main.c */

/* see 'man queue' and 'man rbtree' and 'man dirent'. */


