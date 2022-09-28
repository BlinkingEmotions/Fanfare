To compile and debug one of the mac programs, write

```
./retro-mac.sh -d intel-hex
b main
r
s
```

(The debugger will stop the program before `main` is processed.)

### Prototyping and embedded systems

To compile, debug and run on prototype board or the Pic32 simulator, write something similar to

```
./retro-mips.sh @ccargs_mm 七
./retro-deb.sh @scripts/polis_flash 七
```

(do not enter the full source file name but the project suffix i.e no goggles and without the file extension.)

