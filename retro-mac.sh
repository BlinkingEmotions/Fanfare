#!/usr/bin/env /bin/zsh

builtin typeset INITIAL='-g -std=c2x'
builtin typeset MODULES='-fmodules-ts -fimplicit-modules -fmodule-map-file=🚦.modules'
builtin typeset MACINTOSH='-isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk'
builtin typeset GIT='-DSHA1GIT=`git log -1 '--pretty=format:%h'`'
builtin typeset CCARG_MAC='$MODULES $MACINTOSH $GIT'

builtin typeset progname=$0
# builtin typeset -a sku_keys         # array
builtin typeset sku_key=$1
builtin typeset debugger
builtin typeset -A components       # associative a․𝘬․a 'sources'.
builtin typeset -A output

# sku_keys are retros-compi, c-maskin, turbin, parent-kabinett, intel-hex, uql and friends.

components["retros-compi"]='􀐒 retros-compi.c'
components["c-maskin"]='􀖆 ⒞-maskin.c'
components["turbin"]='􀖆 turbin.cpp'
components["parent-kabinett"]='􀖆 parent-kabinett.c'
components["intel-hex"]='🥽 Intelhex.cpp'
components["uql"]='🥽⋆UQL.cpp 🥽⋆UQL₂.cpp'
components["linguistics-epi"]='􀥳 lingustics-epi.c'
components["enforce-beskow"]='􁕊 enforce-beskow.c'

output["retros-compi"]="run-link"
output["c-maskin"]="helixsh" 
output["turbin"]="turbin"
output["parent-kabinett"]="patent"
output["intel-hex"]="intelhex"
output["uql"]="question"
output["linguistics-epi"]='linguistics-epi'
output["enforce-beskow"]='beskow'

function usage
{
   cat << HEREDOC
   
   Usage $progname [-d] SKU-key
   
   optional arguments:
     -h, --help          show this help message and exit.
     -d, --debug         start debugger after compilation.
   
   Sku-keys:

HEREDOC
   
   for key value in ${(kv)components}; do
     echo "$key: $value"
   done
   
   echo " "
}

if [[ $# -eq 0 ]]; then
  usage
  exit 2
fi

while [[ $# -gt 0 ]]; do
  case $1 in 
   -d | --debugger)
     shift
     debugger="yes"
     ;;
   -help | --help | -h | --h | -\? )
     usage
     exit 1
     ;;
   * )
     skus+="$1"
     shift
     ;;
  esac
done

function compile_and_run()
{
   xcrun clang $INITIAL -o $output[$sku_key] $CCARG_MAC $components[$sku_key]
   if [[ -n "$debugger" ]]; then
   	 xcrun lldb $output[$sku_key]
   fi
}

compile_and_run
