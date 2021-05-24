#!/usr/bin/env /bin/zsh

builtin typeset pdb=/Users/<Path to sprinkle>/Sprinkle/pdb/pdb
builtin typeset MDBPATH=/Applications/microchip/mplabx/v5.50/mplab_platform/bin/mdb.sh
builtin typeset PIC32DEVICE=PIC32MM0064GPL036
# builtin typeset PIC32DEVICE=PIC32MZ2064DAB288

builtin typeset talrik_utskrift
builtin typeset simulator
builtin typeset -a mdb_scripts
builtin typeset -a infixes

function usage
{
   cat << HEREDOC
   
   Usage: $progname [-s] [mdb-script] project-infix
   
   optional arguments:
     -h, --help           show this help message and exit
     -s, --simulator      succumb to inexact sw simulation
     -v, --verbose        increase the verbosity of script
   
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
    -help | --help | -h | --h | -\? )
      usage
      exit 1
      ;;
    * )
      if [[ $1 =~ ^@ ]]; then
        mdb_scripts+="$1"
      else
        infixes+="$1"
      fi
      shift
      ;;
  esac
done

if ((#infixes != 1)); then
  builtin echo 'One .hex file infix not given to retro-debugger.'
  exit 1
fi

infixes[-1]="$infixes[-1].hex"

for hexfile ($infixes) {
  if [[ ! -e "$hexfile" ]]; then
    builtin echo "The binary image file '${hexfile}' does not exist."
    exit 2
  fi
}

if ((#mdb_scripts == 1)); then
  builtin echo 'One debugger script given to retro-debugger.'
fi

if [[ -n "$talrik_utskrift" ]]; then
  builtin echo "Debugging $infixes using the script $mdb_scripts"
fi

if [[ -n "$simulator" ]]; then
  command -p $pdb -s "${infix}.hex"
else
  command -p $pdb "${infix}.hex"
fi

# ./retro-mips.sh @ccargs_Curio-mm polis
# ../Apps/Sprinkle/pdb/pdb ./debscripts/polis_flash 2>/dev/null
# ~/Projects/Monitor/Apps/bin/mdb.sh setup_mzda_simulator 2>/dev/null
# ~/Projects/Monitor/Apps/bin/mdb.sh setup_mzda_target 2>/dev/null
