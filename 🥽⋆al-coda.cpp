/*  al-coda.cpp | Details on char32_t, char8_t and utf-8. */

import Terminalfun;

/* xcrun clang @ccargs_mac -o alcoda '🥽⋆al-coda.cpp' */

int 
main(
  int argc, 
  const char * argv[]
)
{
   const char8_t * text1 = u8"sample text"; /* utf-8. */
   const char32_t * text2 = U"sample text"; /* Unicode. */
   const char * format = "Utf8: '⬚' and Unicode: '⬚'\n"; /* ⬷ utf-8. */
   print("Utf8: '⬚' and Unicode: '⬚'\n", ﹟s(text1), ﹟S(11, (char32_t *)text2));
   return 0;
}

