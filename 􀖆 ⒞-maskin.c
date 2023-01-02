/*  ⓒ-maskin.cpp | arabic and numeric keyput, non-rectangular non-fixative 
 completion from command-line. */

import Twinbeam;
import CppThread; /* ⬷ formerly #include<thread>. */
import CString;
import After_9;

/* compile with xcrun clang @ccargs_mac -o helixsh                           \
 -DSHA1GIT=`git log -1 '--pretty=format:%h'` '􀖆 ⒞-maskin.cpp'. */

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
  UC("ENCRYPT"), UC("EDGE"), UC("VERTEX"), UC("SUBGRAPH"), 
  UC("ADD"), UC("NAMED"), UC("FROM"), UC("TO"), UC("COMMIT"), 
  UC("AND"), UC("BETWEEN"), UC("ROLLBACK"), UC("SELECT"), 
  UC("DIFFERENCE"), UC("CREATE"), UC("UPDATE"), UC("DELTA"), 
  UC("GET"), UC("FOR"), UC("AFTER"), UC("BEFORE"), UC("KEY"), 
  UC("WITH"), UC("FIRST"), UC("SECOND"), UC("VALUE"), UC("OF"), 
  UC("INTEGER"), UC("FLOAT"), UC("DECIMAL"), UC("TRIBOOL"), 
  UC("REMOVE"), UC("IN"), UC("AS"), UC("SUBSCRIBE"), 
  UC("DEFINE"), UC("RETURN"), UC("IF"), UC("THEN"), UC("ELSE"), 
  UC("END"), UC("STRING"), UC("INSTANT"), UC("EXPRESSION"), 
  UC("ATTRIBUTE"), UC("LAMBDA"), UC("SERVER"), UC("DEPLOY"), 
  UC("SUM"), UC("COUNT"), UC("AVG"), UC("VARIANCE"), UC("STDDEV"), 
  UC("MIN"), UC("MAX"), UC("MEDIAN"), ΨΛΩ
};

/*
 *  a reference to a default and unique prompt allows us to quickly identify 
 *. the shell we (sometimes accidently) entered.
 */

const char32̄_t * initial₋prompt          = UC("helixsh> ");

/*
 *  this prompt is presented when user has ended a line with a backslash 
 *  character.
 */

const char32̄_t * multiline₋prompt        = UC("> ");

/*
 *  individual path components are base-64 encoded and 'recorded/stored' 
 *  somewhere in the heap.
 */

static unicode₋string /* a․𝘬․a 'vector<char32̄_t>' */ current₋graphpath;

/*
 *  stack that records all graph paths pushed and popped via 'popd' and 
 *  'pushd'.
 */

static remmingway graphpath₋stack;

/*
 *  associative map catalogue with all substitutions created with the 
 * 'alias'  command. Both 'key' and 'value' is in the heap.
 */

static thesaurus aliases;

/*
 *  a reference to each file entered at the command line to be processed. 
 *  (.helixsh, .gpl and .gpl.enc file-endings.)
 */

static vector<char8₋t *> filepaths₋sequence; /* ⬷ a․𝘬․a sequence and ˢConvoj. */

/*
 *  reference to file path to cryptology bag and with its default relative 
 *  file name given.
 */

const char8₋t * pkcs12₋filename = U8("./passwords.p12");

/*
 *  file path to a complex when currently known and checked in via a 
 *  system("git add my₋journal.gpl") call. Note that completion entering 
 *  'git add my-deleted-file' for z-shell currently is non-operational.
 */

const char8₋t * journal₋filename = ΨΛΩ;

/*
 *  determines if terminal is outputting details on its operations.
 */

int trace₋enabled = 0;

/*
 *  indicates if cerificates not rooted in a certificate authority is 
 *  allowed when authenticating a helixsh user.
 */

int allows₋selfsigning = 0;
 
int start₋interactive₋loop()
{
   print("command-line error. Run helixsh with the -h flag to get help.");
   return 0;
}

#include "⒞-gpl-parser.cxx" /* evaluate₋gpl₋files(int count, char8₋t filepaths[]) */
#include "⒞-commandline-completion.cxx" /* refresh₋command₋completion₋state() */
/* also: open-clone-init-enclosing-repository, reenter-filename, 
 specific-filename, includable, renameable, deleteable, included, 
 renamed, deleted, coagulate-with-a-commit, exclude. */
/* completion with multiple/multiple line and tablettes. */

int start₋interactive₋loop()
{
again:
   if () { return 0; }
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
 command₋preclude, /* ⬷ a․𝘬․a 'parent⁻¹', possibly 'command₋indirect' alternatively 
 'command₋direct' possibly with a 'weak'and 'strong' components of a directed graph. */
 /* 
 Notice ARM big.Little and earlier 'virtual/sandbox'. */
 command₋delta,        command₋commit,        command₋rollback, 
 command₋peek,         command₋sample₋before, command₋sample₋after, 
 command₋sum,          command₋average,       command₋variance, 
 command₋stddev,       command₋median,        command₋difference, 
 command₋max,          command₋min,           command₋count, 
 command₋create₋alias, command₋list₋alias,    command₋unalias, 
 command₋quit,         command₋program
};

struct shell₋command {
   int count;
   const char32̄_t * names[];
   const char32̄_t * arguments;
   const char32̄_t * text;
   int (**feature)(int argc, const char * argv[]);
   enum shell₋command₋type types[];
} commands[] = {
  { 1, { UC("help") }, UC(""), UC("display this help"), 
                                                { ΨΛΩ }, { command₋help } }, 
  { 1, { UC("load") }, UC(""), UC("load a .gpl or a .gpl.enc program"), 
                                                { ΨΛΩ }, { command₋load } }, 
  { 1, { UC("ls") }, UC("<graph path>"), UC("list the content at a "
   "location in the complex"),                  { ΨΛΩ }, { command₋list } }, 
  { 1, { UC("pwd") }, UC(""), UC("list current location in a complex"), 
                                                { ΨΛΩ }, { command₋goto } }, 
  { 1, { UC("mksg") }, UC("<regular token>"), UC("create a new sub graph"), 
                                                { ΨΛΩ }, { command₋mksg } }, 
  { 1, { UC("mkv") }, UC("<regular token>"), UC("create a new vectice"), 
                                                { ΨΛΩ }, { command₋mkv } }, 
  { 1, { UC("bridge-to") }, UC("<regular token> <vertex graph path>"), 
                                                { ΨΛΩ }, { command₋bridge } }, 
  { 1, { UC("mkkey") }, UC("<regular token>"), UC(""), 
                                                { ΨΛΩ }, { command₋mkkey } }, 
  { 1, { UC("delta") }, UC("<single or double value>"), UC(""), 
                                                { ΨΛΩ }, { command₋delta } }, 
  { 1, { UC("commit") }, UC("<optional instant>"), UC(""), 
                                                { ΨΛΩ }, { command₋commit } }, 
  { 1, { UC("rollback") }, UC(""), UC(""),      { ΨΛΩ }, { command₋rollback } }, 
  { 1, { UC("peek") }, UC(""), UC(""),          { ΨΛΩ }, { command₋peek } }, 
  { 1, { UC("samplea") }, UC(""), UC(""),       { ΨΛΩ }, { command₋sample₋after } }, 
  { 1, { UC("sampleb") }, UC(""), UC(""),       { ΨΛΩ }, { command₋sample₋before } }, 
  { 9, { UC("sum"), UC("average"), UC("variance"), UC("stddev"), 
   UC("median"), UC("difference"), UC("max"), UC("min"), 
   UC("count") }, UC("<closed beg.> <open end>"), 
   UC("aggregate a key from [closed beg., open end)]"), 
                                                { ΨΛΩ }, { command₋sum, command₋average, 
    command₋variance, command₋stddev, command₋median, command₋difference, command₋max, 
    command₋min, command₋count } }, 
  { 1, { UC("pushd") }, UC(""), UC("add the current location to the top "
   "of the directory stack"),                   { ΨΛΩ }, { command₋pushd } }, 
  { 1, { UC("popd") }, UC(""), UC("go to the path stored on the top of "
   "the dicrectory stack"),                     { ΨΛΩ }, { command₋popd } }, 
  { 1, { UC("alibi") }, UC("<name> <definition>"), UC("introduce a string "          /* formerly 'alias', later 'shortform'. */
   "substitution"),                             { ΨΛΩ }, { command₋create₋alias } }, 
  { 1, { UC("alibis") }, UC(""), UC("list all string substitutions"), 
                                                { ΨΛΩ }, { command₋list₋alias } }, 
  { 1, { UC("unalibi") }, UC("<name>"), UC("remove a previously added alias") }, 
                                                { ΨΛΩ }, { command₋unalias } }, 
  { 1, { UC("quit") }, UC(""), UC("exit the shell"), 
                                                { ΨΛΩ }, { command₋quit } }
};

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

