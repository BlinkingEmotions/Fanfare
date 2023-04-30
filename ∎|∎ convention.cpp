/*  convention.cpp | constructor bonanza. */

#include <stdio.h>

struct Summary {
   int a,b;
   Summary() { printf("(2) default constructor\n"); }
   Summary(int a, int b) { initialize(a,b); printf("(3) user-defined constructor\n"); }
   Summary(const Summary& other) {
     if (this != &other) { 
       printf("(6) copy constructor\n");
       initialize(other.a,other.b);
     }
   }
   Summary(const Summary && other) { printf("(8) move constructor\n"); initialize(other.a,other.b); }
   Summary& operator=(const Summary& other) { printf("(10) copy assignment\n"); initialize(other.a,other.b); return *this; }
   Summary& operator=(Summary&& other) { printf("(4) move assignment\n"); initialize(other.a,other.b); return *this; }
   void initialize(int a, int b) { this->a=a,this->b=b; }
};

Summary Increment(Summary s)
{
   printf("(7) In increment\n");
   s.a+=1,s.b+=1;
   return s;
}

int main(int argc, char * argv[])
{
   printf("(1) *** begin ***\n");
   Summary original; 
   original = Summary(1,2);
   original.a=13; original.b=17;
   printf("(5) will call 'Increment'\n");
   Summary moved = Increment(original);
   printf("(9) %d and %d\n",moved.a,moved.b);
   moved = original;
   printf("(11) *** end ***\n");
   return 0;
}

/* clang -g -std=c++2b '∎|∎ convention.cpp' */

