/*  ⓒ-maskin.cpp | arabic keyput, completion and command-line with parameters. */

import Twinbeam;
import CppThread; /* ⬷ formerly #include<thread>. */
import CString;
import After_9;

/* compile with xcrun clang @ccargs_mac -o helixsh                           \
 -DSHA1GIT=`git log -1 '--pretty=format:%h'` '􀖆 ⒞-maskin.cpp'. */

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
 *  an unique prompt allows us to quickly identify the shell we 
 *  (sometimes accidently) entered.
 */

const char32̄_t initial₋prompt          = UC("helixsh> ");

/*
 *  this prompt is presented when user has ended a line with a 
 *  backslash character.
 */

const char32̄_t multiline₋prompt        = UC("> ");

/*
 *  individual path components are base-64 encoded.
 */

static unicode₋string current₋graphpath;

/*
 *  stack containing all graph paths pushed and popped via 'popd' 
 *  and 'pushd'.
 */

static vector<unicode₋string> graphpath₋stack;

/*
 *  map with all aliases created with the 'alias' command.
 */

static string₋map aliases;

/*
 *  all files entered at the command line to be processed. (.helixsh, 
 *  .gpl and .gpl.enc file-endings.)
 */

static vector<utf8₋string> filepaths₋sequence;

/*
 *  file path to cryptologic bag and with its default relative file 
 *  name given.
 */

const char8₋t * pkcs12₋filename = U8("./passwords.p12");

/*
 *  file path to a complex as currently known and checked in using the 
 *  libgit2 software.
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

#include "⒞-gpl-parser.cxx" /* evaluate₋gpl₋files() */
#include "⒞-helixsh-completion.cxx" /* refresh₋command₋completion₋state() */

int start₋interactive₋loop()
{
again:
   if () { return 0; }
   goto again;
}

enum shell₋command₋type { 
 command₋help,          command₋load,         command₋list, 
 command₋goto,          command₋pwd,          command₋pushd, 
 command₋popd,          command₋mksg,         command₋mkv, 
 command₋bridge,        command₋mkkey,        command₋delta, 
 command₋commit,        command₋rollback,     command₋peek, 
 command₋sample₋before, command₋sample₋after, command₋sum, 
 command₋average,       command₋variance,     command₋stddev, 
 command₋median,        command₋difference,   command₋max, 
 command₋min,           command₋count,        command₋create₋alias, 
 command₋list₋alias,    command₋unalias,      command₋quit, 
 command₋program
};

struct shell₋command {
   int count;
   const char32̄_t * names[];
   const char32̄_t * arguments;
   const char32̄_t * text;
   int (**code)(int argc, const char * argv[]);
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
  { 1, { UC("alias") }, UC("<name> <definition>"), UC("introduce a string "
   "substitution"),                             { ΨΛΩ }, { command₋create₋alias } }, 
  { 1, { UC("aliases") }, UC(""), UC("list all string substitutions"), 
                                                { ΨΛΩ }, { command₋list₋alias } }, 
  { 1, { UC("unalias") }, UC("<name>"), UC("remove a previously added alias") }, 
                                                { ΨΛΩ }, { command₋unalias } }, 
  { 1, { UC("quit") }, UC(""), UC("exit the shell"), 
                                                { ΨΛΩ }, { command₋quit } }
};

enum option₋type { no₋argument, path₋argument, path₋last₋arguments, regular₋argument };

struct option {
  const char32̄_t * names;
  const char32̄_t * text;
  enum argument₋type unused₋option₋type;
} options[] = {
 { UC("--help,-h"), UC("print help message"),                    no₋argument       }, 
 { UC("--pkcs12-file,-f"), UC("pkcs#12 file path"),              path₋argument     }, 
 { UC("--password,-p"), UC("password for a Pkcs#12 file"),       regular₋argument  }, 
 { UC("--selfsigning-allowed,-s"), UC("allow non-rooted "
       "certificate chains inside a pkcs#12 file"),              no₋argument       }, 
 { UC("--journal,-j"), UC(".journal or .journal.enc file path"), path₋argument     }, 
 { UC("--trace,-t"), UC("print helixstore diagnostic messages"), no₋argument       }, 
 { ΨΛΩ, UC(".gpl and .gpl.enc and .helixsh input files"),      path₋last₋arguments }
};

int keyput₋equal(const char8₋t * src, const char * text, const char * fulltext)
{
   const char * keyput = (const char *)src;
   return strstr(keyput,text) == 0 || strstr(keyput,fulltext) == 0;
}

int filepath₋next(int argc, const char8₋t * argv[], int curr₋argc, 
 const char8₋t **filepath)
{ struct stat st; const char8₋t * token;
   if (curr₋argc + 1 >= argc) { return -1; }
   else { token = argv[curr₋argc]; }
   if (stat((const char *)token,&st) != 0) {
     print("the file '⬚' does not exisits. Did not process any files.\n", ﹟s8(token)); 
     return -1;
   }
   return 0;
}

int regular₋next(int argc, const char8₋t * argv[], int curr₋argc, 
 const char8₋t **argument)
{
  if (curr₋argc + 1 >= argc) { return -1; }
  *argument = argv[curr₋argc];
  return 0;
}

int option₋machine₋interprets(int argc, const char8₋t * argv[])
{ int i=1, input₋files₋ahead=0; const char8₋t *token, next₋token;
   if (argc <= 1) { return -1; }
again:
   if (argc <= i) { return 0; }
   token = argv[i];
   if (token[0] != '-') { input₋files₋ahead=true; }
   if (input₋files₋ahead) { 
     if (filepath₋next(argc,argv,token,&next₋token)) { return -2; }
     else { filepath₋sequence.append(next₋token); }
   } else if (keyput₋equal(token, "-h", "--help")) { return -1; }
   else if (keyput₋equal(token, "-f", "--pkcs12-file")) {
     if (filepath₋next(argc,argv,i,&v)) { print("pkcs12 file path not given\n"); 
     return -2; } }
   else if (keyput₋equal(token, "-p", "--password")) {
     if (regular₋next(argc,argv,i,&x)) { print("password not given\n");
     return -2; } }
   else if (keyput₋equal(token, "-s", "--selfsigning-allowed")) {
     allows₋selfsigning=1; }
   else if (keyput₋equal(token, "-j", "--journal")) {
     if (filepath₋next(argc,argv,i,&z)) { print("journal file path not given\n"); 
     return -2; } }
   else if (keyput₋equal(token, "-t", "--trace")) { trace₋enabled=1; }
   else { return -1; }
   goto again;
}

void help()
{ int i=0;
   print("usage: helixsh [options] <.helixsh, .gpl and .gpl.enc input files>\n\n");
again:
   struct option * arg = *(i + options);
   print("⬚ ⬚\n", ﹟S(arg->names), ﹟S(arg->text));
   if (arg->names == ΨΛΩ) { print("\n"); return; }
   i += 1; goto again;
}

void greeting()
{
   __builtin_int_t cores = std::thread::hardware_concurrency();
   print("the helixshell, revision ⬚\nfor ⬚ on ⬚ virtual cpu core⬚.\n\n", 
    ﹟s7(SHA1GIT), ﹟s7("Macbook Pro"), ﹟d(cores), 
    ﹟s7(cores > 1 ? ﹟s7("s") : ﹟s7("")));
}

int
main(
  int argc, 
  const char * argv[]
)
{
   greeting();
   int options₋parsed = option₋machine₋interprets(argc,(const char8₋t **)argv);
   switch (options₋parsed) {
   case -1: help(); return 2;
   case -2: return 1;
   }
   if (evaluate₋gpl₋files()) { return 3; }
   if (start₋interactive₋loop()) { return 4; }
   print("helixsh quitted\n\n");
   return 0;
}

