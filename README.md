To compile and debug one of the mac programs, write

```
./retro-mac.sh -d intel-hex
```

alternatively

to compile and debug one of the mac programs, write

```
xcrun clang @ccargs_mac -o Contours '🥽⋆Rävvägen.cpp'
lldb 
file ./Contours
b main
r
s
````
to load the mac-debugger with your program and set a breakpoint when its `main` function is called.

### Prototyping and embedded systems

To compile, debug and run on prototype board or the Pic32 simulator, write something similar to

```
./retro-mips.sh @ccargs_mm 七
./retro-deb.sh @scripts/polis_flash 七
```

(do not enter the full source file name but the project suffix i.e no goggles and without the file extension.)

