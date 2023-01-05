/*  cabinet-detail.c | multiple-name filing. */

import Twinbeam;

#include <unistd.h>
#include <fcntl.h>

struct Unicodes empty₋secondary() { struct Unicodes epsilon = { 0, U"" }; return epsilon; }

int create₋file(struct Unicodes primary, struct Unicodes secondary, struct guid * identity)
{ char8₋t prealloc₋path[primary.tetras*4]; __builtin_int_t u8bytes;
   if (UnicodeToUtf8(primary.tetras,primary.unicodes,prealloc₋path,&u8bytes)) { return -1; }
   int fd = open((const char *)prealloc₋path, O_CREAT | O_EXCL);
   if (fd == -1) { return -1; }
   char8₋t prealloc₋secondary[secondary.tetras*4];
   if (UnicodeToUtf8(secondary.tetras,secondary.unicodes,prealloc₋secondary,&u8bytes)) { return -1; }
   if (link((const char *)prealloc₋path,(const char *)prealloc₋secondary)) { return -1; }
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

typedef int (*search₋text)(struct Unicodes filename, __builtin_int_t row);

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
#include <sys/stat.h>

ssize_t pwritev(int fd, const struct iovec *iov, int iovcnt, 
 off_t byteoffset)
{ __builtin_int_t acc=0;
   for (__builtin_int_t i=0; i<iovcnt; i+=1) {
     char * dst=iov[i].iov_base; size_t nbyte=iov[i].iov_len;
     ssize_t byteswrite=pwrite(fd,dst,nbyte,byteoffset+acc);
     if (byteswrite<0) { return byteswrite; }
     acc+=byteswrite;
     /* if (byteswrite==0) { i=iovcnt; } */
   }
   return acc;
}

ssize_t preadv(int fd, const struct iovec *iov, int iovcnt, 
 off_t byteoffset)
{ __builtin_int_t acc=0;
   for (__builtin_int_t i=0; i<iovcnt; i+=1) {
     char * dst=iov[i].iov_base; size_t nbyte=iov[i].iov_len;
     ssize_t bytesread=pread(fd,dst,nbyte,byteoffset+acc);
     if (bytesread<0) { return bytesread; }
     acc+=bytesread;
     if (bytesread==0) { i=iovcnt; }
   }
   return acc;
}

int reconcile₋file(struct Unicodes identifier, int count, uint8_t ** offset, __builtin_int_t * bytes, __builtin_int_t * bytesactual)
{ char8₋t prealloc₋path[identifier.tetras*4]; __builtin_int_t u8bytes;
   struct iovec stripes[count];
   if (UnicodeToUtf8(identifier.tetras,identifier.unicodes,prealloc₋path,&u8bytes)) { return -1; }
   int fd = open((const char *)prealloc₋path, O_WRONLY);
   if (fd == -1) { return -1; } struct stat sb;
   if (fstat(fd,&sb) == -1) { goto err; }
   if (S_ISDIR(sb.st_mode)) { goto err; }
   if (S_ISLNK(sb.st_mode)) { goto err; }
   for (int i=0; i<count; i+=1) { stripes[i].iov_len=bytes[i]; stripes[i].iov_base=offset[i]; }
   *bytesactual = pwritev(fd,stripes,count,0);
   /* coro_feedback, coro_await, coro_resume and coro_free. */
   return 0;
err:
  if (close(fd) == -1) { return -2; }
  return -1;
}

int branch₋file(struct Unicodes expression, int count, uint8_t ** offset, __builtin_int_t * bytes, __builtin_int_t * bytesactual)
{ char8₋t prealloc₋path[expression.tetras*4]; __builtin_int_t u8bytes;
   struct iovec stripes[count];
   if (UnicodeToUtf8(expression.tetras,expression.unicodes,prealloc₋path,&u8bytes)) { return -1; }
   int fd = open((const char *)prealloc₋path, O_RDONLY | O_EXCL);
   if (fd == -1) { return -1; } struct stat sb;
   if (fstat(fd,&sb) == -1) { goto err; }
   if (S_ISDIR(sb.st_mode)) { goto err; }
   if (S_ISLNK(sb.st_mode)) { goto err; }
   for (int i=0; i<count; i+=1) { stripes[i].iov_len=bytes[i]; stripes[i].iov_base=offset[i]; }
   /* coro_feedback, coro_await, coro_resume and coro_f. */
   *bytesactual = preadv(fd,stripes,count,0);
   return 0;
err:
   if (close(fd) == -1) { return -2; }
   return -1;
}

thesaurus₋ref filename₋and₋guid;

int main()
{
   struct Unicodes primary = Run(U"hello world.txt");
   struct guid identity;
   if (create₋file(primary, empty₋secondary(),&identity)) { }
   uint8_t * offset[] = {}; __builtin_int_t bytes[] = {}; __builtin_int_t actual;
   int count = sizeof(offset)/sizeof(uint8_t *);
   struct Unicodes identifier = Run(U"no-identifier");
   if (reconcile₋file(identifier,count,offset,bytes,&actual)) { }
   struct Unicodes noexpression = Run(U"no-expression");
   if (branch₋file(noexpression,count,offset,bytes,&actual)) { }
   return 0;
}

/* see 'man list' and 'man rbtree' and 'man dirent'. */

