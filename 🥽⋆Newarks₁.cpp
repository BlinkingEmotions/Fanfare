/*  Newarks₁.cpp ║ Flight-controller, but surface-aware. */

import Pic32mzda;

/*
 
 export prefix=~/Projects/mips-tools/11.0.0;
 $prefix/clang-11 @ccargs_mz -o Newarks₁ '🥽⋆Newarks₁.cpp';
 $prefix/llvm2pic32 -b bootloader_mz_7084bfcf Newarks₁ > Newarks₁.hex
 
 */

int MeasureBattery() { return 0; }

int main() { wait; }

