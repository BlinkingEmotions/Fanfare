#!/usr/bin/env /bin/zsh

builtin typeset progname=$0
builtin typeset -a sequence # array declaration.
builtin typeset debugger=""
builtin typeset -A components # associative array.
builtin typeset -A output
builtin typeset scriptpath=`realpath $progname`
builtin typeset directory=`dirname $scriptpath`

components=(
  'retros-compi' '􀐒 retros-compi.c'              # c2x
  'c-maskin' '􀖆 ⒞-maskin.c'                     # c2x
  'essence-turbin' '􀖆 turbin-normal.c'           # c2x
  'parent-kabinett' '􀖆 parent-kabinett.c'        # c2x components_C
  'intel-hex' '🥽 Intelhex.cpp'                   # c++20 components_CXX
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
)

function usage
{
   command cat << HEREDOC
   
   Usage $progname [-d] Sku-key
   
   optional arguments:
     -h, --help          show this help message and exit.
     -n, --nodebug       start debugger after compilation.
   
   Sku-keys are:
   
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
   -n | --nodebug )
     builtin shift
     debugger="y"
     ;;
   -help | --help | -h | --h | -\? )
     usage
     builtin bye 1
     ;;
   * )
     sequence+="$1"
     builtin shift
     ;;
  esac
done

function compile_and_run()
{
   for sku ($sequence) {
     builtin command clang -std=c2x -g -fblocks -fno-signed-char -fno-builtin           \
      -DSHA1GIT=\"`git log -1 '--pretty=format:%h'`\"                                   \
      -I "$directory/../Apps/"                                                          \
      -o "$directory/$output[$sku]"                                                     \
      "$directory/$components[$sku]"                                                    \
      "$directory/../Apps/Source/Releases/libTwinbeam-x86_64.a"                         \
      "$directory/../Apps/Additions/monolith-sequent.c"                                 \
      "$directory/../../Cox-route/context-1.S"                                          \
      "$directory/../../Cox-route/context-2.c"                                          \
      "$directory/../../Cox-route/coro-main.c"                                          \
       -lreadline
     if [[ -n "$debugger" ]]; then
       builtin command xcrun lldb $directory/$output[$sku]
     fi
   }
}

compile_and_run

