#!/usr/bin/env /bin/zsh

builtin typeset INITIAL='-g -std=c2x -mmacosx-version-min=11.3.1'
builtin typeset MODULES='-fmodules-ts -fimplicit-modules -fmodule-map-file=🚦.modules'
builtin typeset MACINTOSH='-isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk'
builtin typeset GIT="-DSHA1GIT=`git log -1 '--pretty=format:%h'`"
builtin typeset CCARG_MAC="$MODULES $MACINTOSH $GIT"

builtin typeset progname=$0
# builtin typeset -a sku_keys         # array
builtin typeset -a sku_sequence
builtin typeset debugger
builtin typeset -A components       # associative a․𝘬․a 'sources'.
builtin typeset -A output

# sku_keys are retros-compi, c-maskin, turbin, parent-kabinett, intel-hex, uql and friends.

components=(
  'retros-compi' '􀐒 retros-compi.c'
  'c-maskin' '􀖆 ⒞-maskin.c'
  'turbin' '􀖆 turbin.cpp'
  'parent-kabinett' '􀖆 parent-kabinett.c'
  'intel-hex' '🥽 Intelhex.cpp'
  'uql-gen' '🥽⋆UQL.cpp 🥽⋆UQL₂.cpp'
  'linguistics-epi' '􀥳 lingustics-epi.c'
  'enforce-beskow' '􁕊 enforce-beskow.c'
  'nut-f1-schweiz' '􀐒 slow-pid.c'
)

output=(
  'retros-compi' 'run-link'
  'c-maskin' 'helixsh'
  'turbin' 'turbin'
  'parent-kabinett' 'patent'
  'intel-hex' 'intelhex'
  'uql-gen' "question"
  'linguistics-epi' 'linguistics-epi'
  'enforce-beskow' 'beskow'
  'nut-f1-schweiz' 'non-bell'
)

function usage
{
   command cat << HEREDOC
   
   Usage $progname [-d] SKU-key
   
   optional arguments:
     -h, --help          show this help message and exit.
     -d, --debug         start debugger after compilation.
   
   Sku-keys:
   
HEREDOC
   
   for key value in ${(kv)components}; do
     builtin echo "$key: $value"
   done
   
   builtin printf "\n"
}

if [[ $# -eq 0 ]]; then
  usage
  builtin bye 1
fi

while [[ $# -gt 0 ]]; do
  case $1 in 
   -d | --debugger)
     builtin shift
     debugger="yes"
     ;;
   -help | --help | -h | --h | -\? )
     usage
     builtin bye 1
     ;;
   * )
     sku_sequence+="$1"
     builtin shift
     ;;
  esac
done

function compile_and_run()
{
   for sku_key ($sku_sequence) {
     builtin typeset text="-o $output[$sku_key] ${CCARG_MAC}"
     builtin command xcrun "clang $INITIAL $text '$components[$sku_key]'"
     if [[ -n "$debugger" ]]; then
       command xcrun lldb $output[$sku_key]
     fi
   }
}

compile_and_run
