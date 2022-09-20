#!/usr/bin/env /bin/zsh

builtin typeset INITIAL="-g -std=c2x"
builtin typeset MACINTOSH='-mmacosx-version-min=11.3.1 -isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk'
builtin typeset GIT="-DSHA1GIT=`git log -1 '--pretty=format:%h'`"
builtin typeset MISCELLANEOUS='-fblocks -fno-rtti -fno-coroutines-ts -fno-exceptions'
builtin typeset CCARG_MAC="$INITIAL $MACINTOSH $GIT $MISCELLANEOUS"

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
)

output=(
  'retros-compi' 'run-link'
  'c-maskin' 'helixsh'
  'turbin' 'turbin'
  'parent-kabinett' 'patent'
  'intel-hex' 'intelhex'
  'uql-gen' "question"
  'linguistics-epi' 'x86_epitom-7'
  'enforce-beskow' 'beskow'
  'nut-f1-schweiz' 'non-bell' # for inspector and intendent and not higher-ranked police.
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
     builtin command clang $text -fmodule-map-file=🚦.modules "$components[$sku_key]"
     if [[ -n "$debugger" ]]; then
       builtin command xcrun lldb $output[$sku_key]
     fi
   }
}

compile_and_run

