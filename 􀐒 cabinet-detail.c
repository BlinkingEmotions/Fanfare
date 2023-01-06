/*  cabinet-detail.c | multiple-name filing. */

import Twinbeam;

#include <unistd.h>
#include <fcntl.h>
#define _POSIX_C_SOURCE /* high-precision stat and the modern inode. */
#include <sys/stat.h>

struct Unicodes void₋path() { struct Unicodes epsilon = { 36, U"9E4A34A9-D501-41F6-9C1C-238F96A00CC2" }; return epsilon; }

thesaurus₋ref guid₋and₋secondary=ΨΛΩ,guid₋and₋primary=ΨΛΩ; /* persisted index on ssd and two inodes. */
regular₋ref opened₋files=ΨΛΩ; /* not persisted on ssd, only recorded in virtual memory. */

typedef struct guid openfile₋guid;
typedef openfile₋guid openfile₋id;

union guid₋shim { struct guid composite; __uint128_t machine; };

int create₋file(struct Unicodes primary, struct Unicodes secondary, openfile₋id * regular)
{ char8₋t prealloc₋path[primary.tetras*4]; __builtin_int_t u8bytes;
   if (UnicodeToUtf8(primary.tetras,primary.unicodes,prealloc₋path,&u8bytes)) { return -1; }

   int fd = open((const char *)prealloc₋path, O_CREAT | O_EXCL);
   if (fd == -1) { return -1; }
   char8₋t prealloc₋secondary[secondary.tetras*4];
   if (UnicodeToUtf8(secondary.tetras,secondary.unicodes,prealloc₋secondary,&u8bytes)) { return -1; }
   if (link((const char *)prealloc₋path,(const char *)prealloc₋secondary)) { return -1; }
   union guid₋shim fineprint = { .composite=Guid() };
   int * material = (int *)Alloc(sizeof(int)); *material=fd;
   struct w₋node * node = impression₋store(opened₋files,fineprint.machine,material,Alloc);
   Copy8Memory((ByteAlignedRef)regular,(ByteAlignedRef)&fineprint,sizeof(struct guid));
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
   int fd1=secondary₋node->, fd2=primary₋node->;
   if (close(fd1) == -1) { return -1; }
   if (close(fd2) == -1) { return -1; }
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

typedef int (*search₋text)(struct Unicodes primary, struct Unicodes secondary, 
 openfile₋id regular, __builtin_int_t lineno₋first, __builtin_int_t lineno₋last, 
 __builtin_int_t column₋first, __builtin_int_t column₋last);

struct outcome₋search {
   union {
     search₋text reference;
   } material;
   int kind;
};

int search₋and₋find(struct Unicodes filename, struct Unicodes filetype, 
 struct Unicodes anchor₁, struct Unicodes anchor₂, struct outcome₋search find)
{
   return 0;
}

/* struct iovec { char *iov_base; size_t iov_len; }; */

#include <sys/types.h>
#include <sys/uio.h>

ssize_t pwrt₋c(int fd, const void *buf, size_t nbyte, off_t offset, struct Act * as₋coroutine)
{
   vfprint("bytes written.\n");
}

ssize_t prd₋c(int fd, void *buf, size_t nbyte, off_t offset, struct Act * as₋coroutine)
{
   vfprint("bytes read.\n");
}

ssize_t pwritev₋c(int fd, const struct iovec *iov, int iovcnt, 
 off_t byteoffset, struct Act * as₋coroutine)
{ __builtin_int_t acc=0;
   for (__builtin_int_t i=0; i<iovcnt; i+=1) {
     char * dst=iov[i].iov_base; size_t nbyte=iov[i].iov_len;
     ssize_t byteswrite=pwrite(fd,dst,nbyte,byteoffset+acc);
     if (byteswrite<0) { return byteswrite; }
     acc+=byteswrite;
     if (as₋coroutine) { coro_feedback(coro,(int)monoton₋ordinal(ΨΛΩ,as₋coroutine)); }
     /* if (byteswrite==0) { i=iovcnt; } */
   }
   return acc;
}

ssize_t preadv₋c(int fd, const struct iovec *iov, int iovcnt, 
 off_t byteoffset, struct Act * as₋coroutine)
{ __builtin_int_t acc=0;
   for (__builtin_int_t i=0; i<iovcnt; i+=1) {
     char * dst=iov[i].iov_base; size_t nbyte=iov[i].iov_len;
     ssize_t bytesread=pread(fd,dst,nbyte,byteoffset+acc,as₋coroutine);
     if (bytesread<0) { return bytesread; }
     acc+=bytesread;
     if (as₋coroutine) { coro_feedback(coro,(int)monoton₋ordinal(ΨΛΩ,as₋coroutine)); }
     if (bytesread==0) { i=iovcnt; }
   }
   return acc;
}

int reconcile₋file(openfile₋id regular, int count, uint8_t ** offset, 
 __builtin_int_t * bytes, __builtin_int_t * bytesactual, int as₋coroutine)
{ char8₋t prealloc₋path[identifier.tetras*4]; __builtin_int_t u8bytes;
   struct iovec stripes[count]; struct Act act₋wr; init₋monoton(&act₋wr,1);
   if (UnicodeToUtf8(identifier.tetras,identifier.unicodes,prealloc₋path,&u8bytes)) { return -1; }
   int fd = open((const char *)prealloc₋path, O_WRONLY);
   if (fd == -1) { return -1; } struct stat sb;
   if (as₋coroutine) { coro_feedback(coro,(int)monoton₋ordinal(ΨΛΩ,act₋wr)); }
   if (fstat(fd,&sb) == -1) { goto err; }
   if (S_ISDIR(sb.st_mode)) { goto err; }
   if (S_ISLNK(sb.st_mode)) { goto err; } /* neither hard nor soft link. */
   if (as₋coroutine) { coro_feedback(coro,(int)monoton₋ordinal(ΨΛΩ,act₋wr)); }
   for (int i=0; i<count; i+=1) { stripes[i].iov_len=bytes[i]; stripes[i].iov_base=offset[i]; }
   *bytesactual = pwritev₋c(fd,stripes,count,0,&act₋wr);
   if (as₋coroutine) { coro_feedback(coro,(int)monoton₋ordinal(ΨΛΩ,act₋wr)); }
   return 0;
err:
  if (close(fd) == -1) { return -2; }
  return -1;
}

int branch₋file(openfile₋id regular, int count, uint8_t ** offset, 
 __builtin_int_t * bytes, __builtin_int_t * bytesactual, int as₋coroutine)
{ char8₋t prealloc₋path[expression.tetras*4]; __builtin_int_t u8bytes;
   struct iovec stripes[count]; struct Act act₋rd; init₋monoton(&act₋rd,1);
   if (UnicodeToUtf8(expression.tetras,expression.unicodes,prealloc₋path,&u8bytes)) { return -1; }
   int fd = open((const char *)prealloc₋path, O_RDONLY | O_EXCL);
   if (fd == -1) { return -1; } struct stat sb;
   if (as₋coroutine) { coro_feedback(coro,(int)monoton₋ordinal(ΨΛΩ,act₋rd)); }
   if (fstat(fd,&sb) == -1) { goto err; }
   if (S_ISDIR(sb.st_mode)) { goto err; }
   if (S_ISLNK(sb.st_mode)) { goto err; }
   if (as₋coroutine) { coro_feedback(coro,(int)monoton₋ordinal(ΨΛΩ,act₋rd)); }
   for (int i=0; i<count; i+=1) { stripes[i].iov_len=bytes[i]; stripes[i].iov_base=offset[i]; }
   *bytesactual = preadv₋c(fd,stripes,count,&act₋rd);
   if (as₋coroutine) { coro_feedback(coro,(int)monoton₋ordinal(ΨΛΩ,act₋rd)); }
   return 0;
err:
   if (close(fd) == -1) { return -2; }
   return -1;
}

#pragma recto material and entry

struct Unicodes filename₋expression;

uint8_t material1[5] = { 1, 2, 3, 4, 5 };
uint8_t material2[7] = { 17, 16, 15, 14, 13, 13, 13 };

int corout₋filing(coro_t * coro)
{ struct Act act₋wr; init₋monton(&act₋wr,1);
   coro_feedback(coro,1); openfile₋id regular;
   if (open₋file(filename₋expression,&regular)) { coro_feedback(coro,-1); }
   uint8_t * offset[] = { material1, material2 };
   __builtin_int_t bytes[] = { 5, 7 },actual;
   int count = sizeof(offset)/sizeof(uint8_t *);
   if (reconcile₋file(regular,count,offset,bytes,&actual,1)) { coro_feedback(coro,-2); }
   coro_feedback(coro,2);
   return 0;
}

#include <removefile.h>

int callback(removefile_state_t s, const char * path, void * ctx)
{
   vfprint("file deleted '⬚'\n",﹟s7((char *)path));
   return REMOVEFILE_PROCEED;
}

void cleanup()
{ removefile_state_t s=removefile_state_alloc();
   removefile_state_set(s,REMOVEFILE_STATE_CONFIRM_CALLBACK,callback);
   removefile_state_set(s,REMOVEFILE_STATE_CONFIRM_CONTEXT,callback);
   removefile("/tmp/zz.txt",s,ΨΛΩ);
   removefile_state_free(s);
}

int main()
{
   filename₋expression = Run(U"hello world.txt");
   /* cleanup(); */
   /* initial episode filing attempt with given file name. */
   openfile₋id regular;
   if (create₋file(filename₋expression,void₋path(),&regular)) { vfprint("error when create₋file.\n"); }
   uint8_t * offset[] = { material1,material2 }; __builtin_int_t bytes[] = { 5,7 },actual;
   int count = sizeof(offset)/sizeof(uint8_t *);
   if (reconcile₋file(regular,count,offset,bytes,&actual,0)) { vfprint("error during reconcillation.\n"); }
   if (close₋file(regular)) { vfprint("error at close.\n"); }
   if (open₋file(filename₋expression,&regular)) { vfprint("unable to open file.\n"); }
   if (branch₋file(regular,count,offset,bytes,&actual,0)) { vfprint("error unable to branch.\n"); }
   if (close₋file(regular)) { vfprint("error when close.\n"); }
   /* filing episodes and coroutine attempt. */
   coro_t * coro = coro_await(corout₋filing); int yield;
again:
   yield = coro_resume(coro);
   if (yield == 0) { goto unagain; }
   if (yield <= -1) { goto err; }
   vfprint("filing coroutine reported ⬚.\n", ﹟d((__builtin_int_t)yield));
   goto again;
err:
   vfprint("error while running coroutine ⬚.\n", ﹟d((__builtin_int_t)yield));
unagain:
   coro_free(coro);
   return 0;
}

/* compile with ./retro-mac.sh cabinet-detail 
 
 xcrun clang -g -fmodule-ts -fimplicit-modules -fmodule-map-file=🚦.modules  \
  -o cabinet-detail -DSHA1GIR="`git log -1 '--pretty=format:%h'`"\"          \
  '􀐒 cabinet-detail.c' ../Apps/Source/Releases/libTwinbeam-x86_64.a        \
  ../Apps/Additions/monolith-sequence.c */

/* see 'man list' and 'man rbtree' and 'man dirent'. */


