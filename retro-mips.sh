#!/usr/bin/env /bin/zsh

# trap 'print "You hitted ctrl-c"'                    INT
# trap 'print "You tried to kill me!"'               TERM
# trap 'print "...and changed the window size"      WINCH # Width:text
# trap 'print "I am not universally accepted"' 𝟺kbWritten
# trap 'call usage()'                             COMPOSE
# ...another language:
# untrap                                        INT, TERM
# trap -                                         INT TERM
# ...so:
# untrap                                         INT TERM
# de/retrap                                      INT TERM

builtin typeset llvm=/Users/<Path to --<llvm>/12.0.0
builtin typeset fossilat=/Users/<Path to --<Twinbeam.h>/Additions/Fossilate.cpp
builtin typeset runtime='/Users/<Path to --<℮ ia64+pic32rt>/llvm-rt3.cpp'
builtin typeset twinbeam=/Users/<Path to --<Twinbeam.h>/Source/Releases/libTwinbeam_pic32mz.a
builtin typeset additions=/Users/<Path to --<Twinbeam.h>/Additions/Releases/libAdditions_pic32mz.a
builtin typeset script='/Users/<Path to --<℮ ia64+pic32rt>/Pic32-two.ld'
builtin typeset boot=/Users/<Path to --<Twinbeam.h>/Bootloader/Releases/bootloader_mz_39e78938.hex
builtin typeset hexintel=/Users/<Path to --<Twinbeam.h>/Sprinkle/llvm2pic32
builtin typeset MDBPATH=/Applications/microchip/mplabx/v5.25/mplab_platform/bin
builtin typeset PIC32DEVICE=PIC32MZ2064DAB288
builtin typeset pdb=/Users/<Path to --<Twinbeam.h>/Sprinkle/pdb/pdb
# ⬷ avoid 'source retro-files' instead 'builtin typeset boot --<bootloader_mz_39e78938.hex>'.

#  This script is 'read' by 'a shell' and a binary is 'loaded' followed 
#  by 'executed'. Following Unix, for details on execution, enter 'man zsh', 
#  'man zshmisc' and 'man dyld' at prompt.

builtin typeset utan_vatten
builtin typeset talrik_utskrift
builtin typeset simulator
builtin typeset run
builtin typeset -a filenames
builtin typeset -a response_files
builtin typeset infix

function usage
{
   cat << HEREDOC
   
   Usage: $progname [-s] project-infix
   
   optional arguments:
     -h, --help           show this help message and exit
     -s, --simulator      succumb to inexact sw simulation
     -v, --verbose        increase the verbosity of script
     --dry-run            restrain to find; not execute
     -d, --debug          start debugger after compilation.
   
HEREDOC
}

if [[ $# -eq 0 ]]; then
  usage
  exit 2
fi

while [ $# -gt 0 ]; do
  case $1 in
    -s | --simulator)
      shift
      simulator="yes"
      ;;
    -v | --verbose)
      shift
      talrik_utskrift="yes"
      ;;
    -dry-run)
      shift
      utan_vatten="yes"
      ;;
    -d | --debug)
      shift
      run="yes"
      ;;
    -help | --help | -h | --h | -\? )
      usage
      exit 1
      ;;
    * )
      if [[ $1 =~ ^@ ]]; then
        response_files+="$1"
      else
        filenames+="$1"
        infix="$1" # ⬷ binary gets last source-arguments' name.
      fi
      shift
      ;;
  esac
done

if ((#filenames < 1)); then
  builtin echo 'No source file given to retro-mips.'
  exit 1
fi

filenames[-1]="🥽 $filenames[-1].cpp"

if [[ -n "$talrik_utskrift" ]]; then
  builtin echo "Compiling $filenames"
fi

for sourcefile ($filenames) {
  if [[ ! -e "$sourcefile" ]]; then
    builtin echo "The source file '${sourcefile}' does not exist."
    exit 2
  fi
}

function compile()
{
  
  builtin typeset -a objectfiles
  
  for sourcefile ($filenames) {
    builtin typeset objfile=${sourcefile/.cpp/.o}
    command $llvm/clang-12 $response_files -o ${objfile}                    \
    -DSHA1GIT=`git log -1 '--pretty=format:%h'` -c $sourcefile
    if [ ! $? -eq 0 ]; then
      echo "\nUnable to compile '${sourcefile}'.\n"
      exit 3
    fi
    objectfiles+=$objfile
  }
  command $llvm/clang-12 $response_files -o llvm-rt3.o -c $runtime
  if [ ! $? -eq 0 ]; then
    echo "\nUnable to compile '${runtime}'.\n"
    exit 4
  fi
  command $llvm/clang-12 $response_files -o Fossilate.o -c $fossilat
  if [ ! $? -eq 0 ]; then
    echo "\nUnable to compile '${fossilat}'.\n"
    exit 5
  fi
  command $llvm/ld.lld -T $script -o $infix $twinbeam $additions            \
   $objectfiles Fossilate.o llvm-rt3.o
  if [ ! $? -eq 0 ]; then
    echo "\nUnable to link producing '${infix}'.\n"
    exit 6
  fi
  command $hexintel -b $boot $infix > "${infix}.hex"
  if [ $? -eq 0 ]; then
    echo "Binary created."
  else
    echo "Unable to create binary.\n"
  fi
  command rm llvm-rt3.o Fossilate.o
}

# Starts the simulator/debugger with %prompt> pdb myprogram.hex
function debug()
{
  if [[ -n "$simulator" ]]; then
    command -p $pdb -s "${infix}.hex"
# ~/Projects/Monitor/Apps/bin/mdb setup_mzda_simulator 2>/dev/null
  else
    command -p $pdb "${infix}.hex"
# ~/Projects/Monitor/Apps/bin/mdb setup_mzda_target 2>/dev/null
  fi
}

if [[ -n "$utan_vatten" ]]; then
  command echo "Dry-run. No installable created."
  command exit 0
else
  compile
fi

if [[ -n "$run" ]]; then
  debug
fi


