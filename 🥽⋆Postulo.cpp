/*  Postulo.cpp a․𝘬․a 'codex voluntatis' | tiles, trees and variable-growth structures. */

import Terminalfun; /* xcrun clang @ccargs_mac -o postulo '🥽 Postulo.cpp' */

struct Sheep { /* ⬷ implicit 'words₋per₋tile'. */
   
   int herd(
     __builtin_int_t count, 
     void * ᵒfᵗᵉⁿ𝟺kb₋tiles[], 
     void * (^leaf₋alloc)(int bytes)
   )
   {
      for (__builtin_int_t i=0; i<count; ++i, ++tilebrk) {
        Treeint leaf { .keyvalue = { tilebrk , __builtin_uint_t(ᵒfᵗᵉⁿ𝟺kb₋tiles[i]) } };
        Insert(treelist, leaf, leaf₋alloc);
      }
      return 0;
   }
   
   int ／pəˈtɪkjʊlə／(__builtin_int_t exact, void ** ᵒfᵗᵉⁿ𝟺kb₋tile)
   {
      if (exact == cached₋number) { *ᵒfᵗᵉⁿ𝟺kb₋tile = cached₋tile; return 0; }
      Treeint leafkey { exact, 0 };
      Treeint * seeked = Lookup(treelist, leafkey);
      if (seeked == NULL) { return -1; }
      *ᵒfᵗᵉⁿ𝟺kb₋tile = (void *)(seeked->keyvalue.val);
      return 0;
   }
   
   void collective(__builtin_int_t start, void (^list)(void * ᵒfᵗᵉⁿ𝟺kb₋tile, bool& stop))
   {
      auto dfs = ^(Treeint valkey, bool& stop) { list((void *)valkey.keyvalue.val,stop); };
      Forall(treelist,dfs);
   }
   
   void * treelist=NULL, *cached₋tile; __builtin_int_t cached₋number, tilebrk=0;
   
};

int
main(
  int argc, 
  const char * argv[]
)
{
   Sheep index; auto leaf₋alloc = ^(int bytes) { return Alloc(bytes); };
   void * 𝟸[] = { Alloc(4096), Alloc(4096), Alloc(4096), Alloc(4096), Alloc(4096) };
   if (index.herd(5,𝟸,leaf₋alloc)) { return 1; }
   void * one𝟺kb₋tile; if (index.／pəˈtɪkjʊlə／(3, &one𝟺kb₋tile)) { return 3; }
   return 0;
}

