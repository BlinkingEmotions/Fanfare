/*  intelhex.cpp | parsing binary content in classic engineering style (not base-64). */

import Terminalfun;

/* #include <Twinbeam.h>
#include <Additions/Additions.h> */

/* clang++ -o intelhex -std=c++2a -g -I ../../                               \
 -fmodules-ts -fimplicit-modules -fmodule-map-file=🚦.modules                \
                                                          '🥽 Intelhex.cpp' */

/* xcrun clang @ccargs_mac -o intelhex '🥽 Intelhex.cpp' ../Apps/Additions/Fossilate.cpp */

inexorable
int
ParseIntelHex(
  const char * 𝑙𝑒𝑎𝑑𝑖𝑛𝑔 utf8text, 
  void (^material)(uint8_t byte, bool& stop)
) /* Returns `0` or the line number to first faulty line. */
{  int line=0;
    auto non7bitchar = ^(char unsigned leadOr8Bit) { return leadOr8Bit >= 128; };
    auto lowercase⁷ᵇⁱᵗ = ^(char c) { return 'a' <= c && c <= 'z'; };
    auto digit⁷ᵇⁱᵗ = ^(char c) { return '0' <= c && c <= '9'; };
    auto letter⁷ᵇⁱᵗ = ^(char c) { return lowercase⁷ᵇⁱᵗ(c) || ('A' <= c && c <= 'Z'); };
    auto upper⁷ᵇⁱᵗ = ^(char c) { return lowercase⁷ᵇⁱᵗ(c) ? c - 0x20 : c; };
    auto hex﹖ = ^(char c) { return (uint8_t)(c < ':' ? c - '0' : c - 'A' + 10); };
    auto delta = ^(char c, int pos0To3) { return hex﹖(upper⁷ᵇⁱᵗ(c))<<(4*pos0To3); };
    uint8_t acc=0; __builtin_uint_t i=0; bool hi=true;
again:
    unsigned char c = *(utf8text + i); ++i;
    if (non7bitchar(c)) { return line; }
    if (c == 0) { return hi ? i != 0 : line; }
    if (c == '\x0a') { line++; goto again; }
    if (c == '\x0d') { goto again; }
    if (c == '\x20') { goto again; } /* ⬷ space-up your Intel-Hex files! */
    if (c == ':') { /* Starting new text line here, yet no code... */ goto again; }
    if (c == '#') { do { i++; c = *(utf8text + i); } while (c != '\x0a' && c != '\x0d' 
      && c != '\x00'); if (c == '\x0a') line++; } /* Comments not actually in spec. */
    if (!(digit⁷ᵇⁱᵗ(c) || letter⁷ᵇⁱᵗ(c))) { return line; }
    if (hi) { acc = delta(c, 1); hi=false; }
    else { acc += delta(c, 0); bool stop=false; material(acc, stop); 
      if (stop) return line; hi=true; }
    goto again;
} /* ⬷ a․𝘬․a 'instantiatedInBoot_ParseIntelHex'. */

inexorable
int
ParseIntelHex(
  const char * 𝑙𝑒𝑎𝑑𝑖𝑛𝑔 utf8text,
  void (^aim)(uint16_t upper), /* When an extended linear address is found. */
  void (^row)(int bytes, uint8_t * material, uint16_t lower),
  void (^endoffile)()
)
{  int __block idx=-4, bytes, addrhi, addrlo, type;
    uint8_t buf₁[256]; 𝑓𝑙𝑢𝑐𝑡𝑢𝑎𝑛𝑡 uint8_t accCRC=0; uint8_t *buf₂=buf₁;
    auto crcneq = ^(uint8_t crc) { uint8_t acc=((-accCRC)&0xff); return acc != crc; };
    int err = ParseIntelHex(utf8text, ^(uint8_t byte, bool& stop) {
      switch (idx) {
      case -4: bytes=byte; break;
      case -3: addrhi=byte; break;
      case -2: addrlo=byte; break;
      case -1: type=byte; break;
      default: *(buf₂+idx)=byte;
      }
      if (idx == bytes) { if (crcneq(byte)) { /* stop=true; */ } idx=-5; accCRC=0; }
      else if (idx == bytes - 1) switch (type) {
      case 0: row(bytes, buf₂, addrhi<<8 | addrlo<<0); break;
      case 4: aim(buf₂[0]<<8 | buf₂[1]); break; /* ⬷ Stored in big endian. */
      case 1: endoffile(); break;
      }
    idx++; accCRC += byte; });
    
    return err;
} /* ⬷ a․𝘬․a 'instantiatedInBoot_ParseIntelHex'. */

int
Reprogram(
  const char * 𝑙𝑒𝑎𝑑𝑖𝑛𝑔 utf8text,
  uint8_t * 𝟼𝟺kRam
)/* 8*8 = The size of 'four erasable blocks' on a Pic32 and the max */
{ /* number of bytes after a `04` type defined in the IntelHex format. */
    /* First one pass to validate all CRCs in `utf8text`. */
    /* For each 64k block, copy whole block to Ram. */
    /* Then the second pass muxing the old and the new followed by a flash. */
    /* We may want to rollback/abort in the midst of programming since a faulty 
        flash cell may be detected at any time. */
    /* Toggle PFSWAP in case of no errors. */
    return 0;
} /* ⬷ a․𝘬․a `'nstantiatedInBoot_Reprogram'. */

#ifdef __x86_64__
#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#endif

void *
mapfileʳᵚ(
  const char * canonicalRegularOrLinkpathᵘᵗf⁸,
  __builtin_int_t pagesOffset,
  __builtin_int_t pagesCountOrZero,
  __builtin_int_t * bytesActual,
  bool append𝙴𝙾𝚃at𝙴𝙾𝙵
)
{ void *p;
    __builtin_int_t bytesOffset = pagesOffset*Syspagesize();
#if defined __x86_64__
    int fd = open(canonicalRegularOrLinkpathᵘᵗf⁸, O_RDONLY);
    if (fd == -1) { return NULL; } struct stat sb;
    if (fstat(fd, &sb) == -1) { goto err; }
    if (!S_ISREG(sb.st_mode)) { goto err; } /* Not regular file. */
    *bytesActual = pagesCountOrZero == 0 ? sb.st_size - bytesOffset : 
      pagesCountOrZero*Syspagesize();
    p = mmap(0, *bytesActual, PROT_READ, MAP_SHARED, fd, bytesOffset);
    if (p == MAP_FAILED) { goto err; }
#elif defined __mips__
    /* ⬷ see --<🥽 Memclone.cpp>{Copy} */
#endif
    return p;
err:
#if defined __x86_64__
    if (close(fd) == -1) { return NULL; } /* todo: Close when not error. */
#endif
    return NULL;
}

#pragma mark - ...and the entry point:

int
main(
  int argc,
  const char *argv[]
)
{  __builtin_int_t bytesActual;
    const char * filepath = "Minimum.hex";
    const char * text = (const char *)mapfileʳᵚ(filepath, 0, 0, &bytesActual, true);
    if (text == NULL) { return 1; } int __block count=1, bytes, addrhi, addrlo, type;
    /* if (ParseIntelHex(text, ^(uint8_t d) { printf("%x\n", d); })) { return 1; } */
    if (ParseIntelHex(text,
      ^(uint16_t upper) { printf("32-bit linear addr (upper 16-bits): %x\n", upper); },
      ^(int bytes, uint8_t * material, uint16_t lower) { 
         printf("%d bytes on %x: ", (int)bytes, (int)lower); for (int i=0; i < bytes; 
         i++) { printf("%.2x ", (int)*(material + i)); } printf("\n"); },
      ^{ printf("End-of-file\n"); }
    )) { return 1; }
    
    /* ...and now the full program: */
    
    uint8_t 𝟼𝟺kRam[64*1024];
    if (Reprogram(text, 𝟼𝟺kRam)) { return 1; }
    // boot_TogglePFSWAP(PIC32MZDA_KEY1, PIC32MZDA_KEY2);
    // Reset(PIC32MZDA_KEY1, PIC32MZDA_KEY2);
    return 0;
}

