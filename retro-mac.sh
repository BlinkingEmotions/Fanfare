#!/usr/bin/env /bin/zsh

builtin typeset progname=$0
builtin typeset -a sku_sequence # declares an array.
builtin typeset flag_and_debugger
builtin typeset -A components # declares an associative a․𝘬․a 'sources' and 
# 'reference-list'.
builtin typeset -A output

# sku_keys are retros-compi, c-maskin, reconnaissance-turbin, 
# parent-kabinett, intel-hex, uql-gen, micro-parse, linguistics-epi, 
# enforce-beskow and cabinet-detail.

components=(
  'retros-compi' '􀐒 retros-compi.c'              # c2x
  'c-maskin' '􀖆 ⒞-maskin.c'                     # c2x
  'essence-turbin' '􀖆 turbin-normal.c'           # c2x
  'parent-kabinett' '􀖆 parent-kabinett.c'        # c2x
  'intel-hex' '🥽 Intelhex.cpp'                   # c++20
  'uql-gen' '🥽⋆UQL.cpp 🥽⋆UQL₂.cpp'              # c++20
  'micro-parse' '􁋹 µ-parse.c'                     # c2x
  'linguistics-epi' '􀥳 lingustics-epi.c'          # c2x
  'enforce-beskow' '􁕊 enforce-beskow.c'           # c2x
  'cabinet-detail' '∎|∎ cabinet-detail.c'          # c2x
)

output=(
  'retros-compi' 'run-link'
  'c-maskin' 'helixsh'
  'essence-turbin' 'turbin'
  'parent-kabinett' 'patent'
  'intel-hex' 'intelhex'
  'uql-gen' 'question'
  'micro-parse' 'expression'
  'linguistics-epi' 'x86_epitom-7'
  'enforce-beskow' 'beskow'
  'cabinet-detail' 'cabinet-detail'
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
     flag_and_debugger="-g"
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
     builtin command clang -fmodules-ts -fimplicit-modules -fmodule-map-file=🚦.modules \
      $flag_and_debugger -std=c2x -DSHA1GIT=\"`git log -1 '--pretty=format:%h'`\"       \
      "$components[$sku_key]" -fblocks -fno-signed-char -fno-builtin -g                 \
      ../Apps/Source/Releases/libTwinbeam-x86_64.a                                      \
      ../Apps/Additions/monolith-sequent.c                                              \
      ../../Cox-route/context-1.S                                                       \
      ../../Cox-route/context-2.c                                                       \
      ../../Cox-route/coro-main.c                                                       \
      -o $output[$sku_key]
     if [[ -n "$flag_and_debugger" ]]; then
       builtin command xcrun lldb $output[$sku_key]
     fi
   }
}

compile_and_run

