/*  ⓒ-maskin.cpp | arabic and numeric keyput, non-rectangular non-
 fixative completion from command-line. */

import Twinbeam;

/**
   
   The following program mimics a traditional computer shell and understands 
   both token-based commands such as 'cd' and 'ls' and and in-case the 
   proper flags are included at start-up, texts that are assumed to be parts 
   of a graph-path program.  The helixsh allows a user to via a traditional 
   keyboard browse complex using absolute and relative graph paths:
   
   Examples:
   
   cd [O ⇥  cd [Organisations]--[SE]'
   􀉈
   cd --<55 ⇥ cd --<556601-2142>
   ✂️
   ls [Organisations]
   cd Mother-->
   cd <Vertex_3>{key_1}<<7[Subgraph_11]>--<Vertex_11>
   cd <Vertex_3>{key_1}:>1[ANC]>--<v2>{abc2}
   
   A graph-path beginning with '~' is assumed to be absolute.
   
   mkv vertex_11 vertex_12 @ 2022-07-21 19:41:31.123

 */

/* #define SCIENTIFIC₋FLAVOURS ⬷ three decimals and '+' alternatively '-'  
 and  '±' with '.' before and after fractional records. */

const char32̄_t * gpl₋keywords[] = {
  U"ENCRYPT", U"EDGE", U"VERTEX", U"SUBGRAPH", 
  U"ADD", U"NAMED", U"FROM", U"TO", U"COMMIT", 
  U"AND", U"BETWEEN", U"ROLLBACK", U"SELECT", 
  U"DIFFERENCE", U"CREATE", U"UPDATE", U"DELTA", 
  U"GET", U"FOR", U"AFTER", U"BEFORE", U"KEY", 
  U"WITH", U"FIRST", U"SECOND", U"VALUE", U"OF", 
  U"INTEGER", U"FLOAT", U"DECIMAL", U"TRIBOOL", 
  U"REMOVE", U"IN", U"AS", U"SUBSCRIBE", 
  U"DEFINE", U"RETURN", U"IF", U"THEN", U"ELSE", 
  U"END", U"STRING", U"INSTANT", U"EXPRESSION", 
  U"ATTRIBUTE", U"LAMBDA", U"SERVER", U"DEPLOY", 
  U"SUM", U"COUNT", U"AVG", U"VARIANCE", U"STDDEV", 
  U"MIN", U"MAX", U"MEDIAN", ΨΛΩ
};

/*
 *  a reference to a default and unique prompt allows us to quickly identify 
 *  the shell we (sometimes accidently) entered.
 */

char32̄_t * initial₋prompt          = UC("helixsh> ");

/*
 *  this prompt is presented when user has ended a line with a backslash 
 *  character.
 */

char32̄_t * multiline₋prompt        = UC("> ");

/*
 *  individual path components are base-64 encoded and 'recorded/stored' 
 *  somewhere in the heap.
 */

struct Unicodes current₋graphpath;

/*
 *  stack that records all graph paths pushed and popped via 'popd' and 
 *  'pushd'.
 */

struct collection /* char32̄_t */ graphpath₋stack, graphpath₋indices;

/*
 *  associative map catalogue with all substitutions created with the 
 * 'alias'  command. Both 'key' and 'value' is in the heap.
 */

thesaurus₋ref aliases;

/*
 *  a reference to each file entered at the command line to be processed. 
 *  (.helixsh, .gpl and .gpl.enc file-endings.)
 */

struct collection /* char8₋t * */ filepath₋sequence; /*  a․𝘬․a pointer₋sequence. */

/*
 *  reference to file path to cryptology bag and with its default relative 
 *  file name given.
 */

char8₋t * pkcs12₋filename = U8("./please.p12");

/*
 *  file path to a complex when currently known and checked in via a 
 *  Order("git add my₋journal.gpl") call. Note that completion entering 
 *  'git add my-deleted-file' for z-shell currently is non-operational.
 */

char8₋t * journal₋filename = ΨΛΩ;

/*
 *  indicates if cerificates not rooted in a certificate authority is 
 *  allowed when authenticating a helixsh user.
 */

int allows₋selfsigning = 0;

/*
 *  instruct operator on 'how to proceed'.
 */

int procuratio = 0;

/*
 *  determines if terminal is outputting details on its operations.
 */

int trace₋enabled = 0;

extern int evaluate₋gpl₋files(struct collection /* char8₋t * */ filepaths);
#include "⒞-gpl-parser.cxx"

#include "⒞-line-completion.cxx" /* refresh₋command₋completion₋state() */
/* also: open-clone-init-enclosing-repository, reenter-filename, 
 specific-filename, includable, renameable, deleteable, included, 
 renamed, deleted, coagulate-with-a-commit, exclude. */
/* completion with multiple/multiple line and tablettes. */

int start₋interactive₋loop()
{ int quit=0;
again:
   if (quit) { return 0; }
   print("command-line error. Run helixsh with the -h flag to get help.\n");
   goto again;
}

enum shell₋command₋type { 
 command₋help,         command₋load,          command₋list, 
 command₋goto,         command₋pwd,           command₋pushd, 
 command₋popd,         command₋mksg,          command₋mkv, 
 command₋bridge,       command₋voluntary,     command₋mkkey, 
/* note that structures may be 
 - 'strict' 
 - 'blobby' navier-stokes
 - 'field with div/rot/curl' and 'böjer av med' vid modellering 
 - crosstalk/paracitic-model. */
/* Find new abstraction to enhance clarity compared to '#include'. */
/* transmissions alternatively nätelement. */
/* Consider 'includes' and 'preclude'. */
 command₋preclude, /*  a․𝘬․a 'parent⁻¹', possibly 'command₋indirect' alternatively 
 'command₋direct' possibly with a 'weak'and 'strong' components of a directed graph. */
 /* 
 Notice ARM big.Little and earlier 'virtual/sandbox'. */
 command₋delta,        command₋commit,        command₋rollback, 
 command₋peek,         command₋sample₋before, command₋sample₋after, 
 command₋sum,          command₋average,       command₋variance, 
 command₋stddev,       command₋median,        command₋difference, 
 command₋max,          command₋min,           command₋count, 
 command₋create₋alias, command₋list₋alias,    command₋unalias, 
 command₋quit,         command₋program,       command₋publish, /* material in plain-text suitable for copy-paste to inte-r-net */
 command₋steganographic₋rewrite
};

typedef int (*Feature)(int argc, const char * argv[]);

struct shell₋command {
   int count;
   char32̄_t * names[9]; char32̄_t *arguments,*text;
   Feature feature[9];
   enum shell₋command₋type types[9];
} commands[] = {
  { 1, { U"help" }, U"", U"display this help", 
                                                { ΨΛΩ }, { command₋help } }, 
  { 1, { U"load" }, U"", U"load a .gpl or a .gpl.enc program", 
                                                { ΨΛΩ }, { command₋load } }, 
  { 1, { U"ls" }, U"<graph path>", U"list the content at a "
   "location in the complex",                   { ΨΛΩ }, { command₋list } }, 
  { 1, { U"pwd" }, U"", U"list current location in a complex", 
                                                { ΨΛΩ }, { command₋goto } }, 
  { 1, { U"mksg" }, U"<regular token>", U"create a new sub graph", 
                                                { ΨΛΩ }, { command₋mksg } }, 
  { 1, { U"mkv" }, U"<regular token>", U"create a new vectice", 
                                                { ΨΛΩ }, { command₋mkv } }, 
  { 1, { U"bridge-to" }, U"<regular token> <vertex graph path>", U"", 
                                                { ΨΛΩ }, { command₋bridge } }, 
  { 1, { U"mkkey" }, U"<regular token>", U"", 
                                                { ΨΛΩ }, { command₋mkkey } }, 
  { 1, { U"delta" }, U"<single or double value>", U"", 
                                                { ΨΛΩ }, { command₋delta } }, 
  { 1, { U"commit" }, U"<optional instant>", U"", 
                                                { ΨΛΩ }, { command₋commit } }, 
  { 1, { U"rollback" }, U"", U"",      { ΨΛΩ }, { command₋rollback } }, 
  { 1, { U"peek" }, U"", U"",          { ΨΛΩ }, { command₋peek } }, 
  { 1, { U"samplea" }, U"", U"",       { ΨΛΩ }, { command₋sample₋after } }, 
  { 1, { U"sampleb" }, U"", U"",       { ΨΛΩ }, { command₋sample₋before } },
  { 9, { U"sum", U"average", U"variance", U"stddev", 
   U"median", U"difference", U"max", U"min", 
   U"count" }, U"<closed beg.> <open end>", 
   U"aggregate a key from [closed beg., open end)]", 
                                                { ΨΛΩ }, { command₋sum, command₋average, 
    command₋variance, command₋stddev, command₋median, command₋difference, command₋max, 
    command₋min, command₋count } }, 
  { 1, { U"pushd" }, U"", U"add the current location to the top "
   "of the directory stack",                    { ΨΛΩ }, { command₋pushd } }, 
  { 1, { U"popd" }, U"", U"go to the path stored on the top of "
   "the dicrectory stack",                      { ΨΛΩ }, { command₋popd } }, 
  { 1, { U"alibi" }, U"<name> <definition>", U"introduce a string "          /* formerly 'alias', later 'shortform'. */
   "substitution",                              { ΨΛΩ }, { command₋create₋alias } }, 
  { 1, { U"alibis" }, U"", U"list all string substitutions", 
                                                { ΨΛΩ }, { command₋list₋alias } }, 
  { 1, { U"unalibi" }, U"<name>", U"remove a previously added alias", 
                                                { ΨΛΩ }, { command₋unalias } }, 
  { 1, { U"quit" }, U"", U"exit the shell", 
                                                { ΨΛΩ }, { command₋quit } }
};

#include <unistd.h>

int IsFileSuffix(const char * suffix, char8₋t * text)
{ return 0; }

void keyput₋rewrite(char8₋t * utf8) { }

int option₋machine₋interprets(int argc, char8₋t ** argv)
{ int i=1,y₁,y₂,pkcs12₋filepath=0,password=0,journal₋filepath=0; 
   char8₋t * token, *msg = U8("");
again:
   if (i>=argc) { goto unagain; }
   token = *(i + argv);
   keyput₋rewrite(token);
   if (pkcs12₋filepath) { pkcs12₋filepath=0; goto next; }
   if (password) { password=0; goto next; }
   if (journal₋filepath) { journal₋filepath=0; goto next; }
   y₁ = IsPrefixOrEqual((const char *)token,"-h");
   y₂ = IsPrefixOrEqual((const char *)token,"--help");
   if (y₁ || y₂) { procuratio=true; goto next; }
   y₁ = IsPrefixOrEqual((const char *)token,"-f");
   y₂ = IsPrefixOrEqual((const char *)token,"--pkcs12-file");
   if (y₁ || y₂) { pkcs12₋filepath=1; goto next; }
   y₁ = IsPrefixOrEqual((const char *)token,"-p");
   y₂ = IsPrefixOrEqual((const char *)token,"--password");
   if (y₁ || y₂) { password=1; goto next; }
   y₁ = IsPrefixOrEqual((const char *)token,"-s");
   y₂ = IsPrefixOrEqual((const char *)token,"--selfsigning-allowed");
   if (y₁ || y₂) { allows₋selfsigning=1; goto next; }
   y₁ = IsPrefixOrEqual((const char *)token,"-j");
   y₂ = IsPrefixOrEqual((const char *)token,"--journal");
   if (y₁ || y₂) { journal₋filepath=1; goto next; }
   y₁ = IsPrefixOrEqual((const char *)token, "-t");
   y₂ = IsPrefixOrEqual((const char *)token, "--trace");
   if (y₁ == 0 || y₂ == 0) { trace₋enabled=1; goto next; }
   if (IsFileSuffix(".helixsh",token)) { goto next; }
   if (IsFileSuffix(".gpl",token)) { goto next; }
   if (IsFileSuffix(".gpl.enc",token)) { goto next; }
   goto generic₋error;
next:
   i+=1; goto again;
generic₋error:
   vfprint("Abridged command-line interpretation error\n");
   return -1;
descriptive₋error:
   vfprint("Command-line interpretation error '⬚'\n", ﹟s8(msg));
   return -1;
unagain:
   if (pkcs12₋filepath) { msg=U8("no pkcs12 file given"); goto descriptive₋error; }
   if (password) { msg=U8("no password given"); goto descriptive₋error; }
   if (journal₋filepath) { msg=U8("no journal file given"); goto descriptive₋error; }
   return 0;
}

struct commandline₋option {
  char * names; char * text;
} options[] = {
 { "--help,-h", "print help message" }, 
 { "--pkcs12-file,-f", "pkcs#12 file path" }, 
 { "--password,-p", "password for a Pkcs#12 file" }, 
 { "--selfsigning-allowed,-s", "allow non-rooted "
       "certificate chains inside a pkcs#12 file" }, 
 { "--journal,-j", ".journal or .journal.enc file path" }, 
 { "--trace,-t", "print helixstore diagnostic messages" }, 
 { ΨΛΩ, ".gpl and .gpl.enc and .helixsh input files" }
};

void help()
{ int i=0; struct commandline₋option parameter;
   print("usage helixsh [options] <optional .helixsh, .gpl and .gpl.enc input files>\n\n");
again:
   parameter = *(i + options);
   print("⬚ ⬚\n", ﹟s7(parameter.names), ﹟s7(parameter.text));
   if (parameter.names == ΨΛΩ) { print("\n"); return; }
   i+=1; goto again;
}

void greeting()
{
   __builtin_int_t cores = sysconf(_SC_NPROCESSORS_ONLN);
   char * Identity; Identity₋Tb(&Identity);
   print("the helixshell, revision ⬚ and tb-⬚\nfor ⬚ on ⬚ virtual cpu core⬚.\n\n", 
    ﹟s7(SHA1GIT), ﹟s7(Identity), ﹟s7("Macbook Pro"), ﹟d(cores), 
    ﹟s7(cores > 1 ? "s" : ""));
}

int
main(
  int argc, 
  const char * argv[]
)
{
   greeting();
   if (option₋machine₋interprets(argc,(char8₋t **)argv)) { exit(1); }
   if (procuratio) { help(); exit(2); }
   if (evaluate₋gpl₋files(filepath₋sequence)) { exit(3); }
   if (start₋interactive₋loop()) { exit(4); }
   print("helixsh quitted\n\n");
   return 0;
}

/*  compile with ./retro-mac.sh c-maskin 
 
 xcrun clang -g -fmodule-ts -fimplicit-modules -fmodule-map-file=🚦.modules  \
  -o helixsh -DSHA1GIT=\"`git log -1 '--pretty=format:%h'`"\"                \
  '􀖆 ⒞-maskin.cpp' ../Apps/Source/Releases/libTwinbeam-x86_64.a            \
  ../Apps/Addions/monolith-sequence.c */

