/*  cabinet-detail.c | multiple-name filing. */

import Twinbeam;

#include <unistd.h>
#include <fcntl.h>

struct Unicodes empty₋secondary() { struct Unicodes epsilon = { 0, U"" }; return epsilon; }

int create₋file(struct Unicodes primary, struct Unicodes secondary)
{ char8₋t prealloc₋path[primary.tetras*4]; __builtin_int_t u8bytes;
   if (UnicodeToUtf8(primary.tetras,primary.unicodes,prealloc₋path,&u8bytes)) { return 0; }
   int fd = open((const char *)prealloc₋path, O_CREAT | O_EXCL);
   if (fd) { return -1; }
   char8₋t prealloc₋secondary[secondary.tetras*4];
   if (UnicodeToUtf8(secondary.tetras,secondary.unicodes,prealloc₋secondary,&u8bytes)) { return 0; }
   if (link((const char *)prealloc₋path,(const char *)prealloc₋secondary)) { return -1; }
   return 0;
}

int primary₋filename₋add(struct Unicodes primary, struct Unicodes additional₋primary)
{ char8₋t prealloc₋primary[primary.tetras*4], prealloc₋secondary[secondary.tetras*4]; 
    __builtin_int_t u8bytes;
    if (UnicodeToUtf8(primary.tetras,primary.unicodes,prealloc₋primary,&u8bytes)) { return 0; }
    if (UnicodeToUtf8(secondary.tetras,secondary.unicodes,prealloc₋secondary,&u8bytes)) { return 0; }
   if (symlink((const char *)exisisting,(const char *)additional)) { return -1; }
   return 0;
}

int secondary₋filename₋add(struct Unicodes secondary, struct Unicodes additional₋secondary)
{ char8₋t prealloc₋primary[primary.tetras*4], prealloc₋secondary[secondary.tetras*4]; 
    __builtin_int_t u8bytes;
    if (UnicodeToUtf8(primary.tetras,primary.unicodes,prealloc₋primary,&u8bytes)) { return 0; }
    if (UnicodeToUtf8(secondary.tetras,secondary.unicodes,prealloc₋secondary,&u8bytes)) { return 0; }
   if (symlink((const char *)existing,(const char *)additional)) { return -1; }
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

