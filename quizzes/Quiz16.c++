/*
CS371p: Quiz #16 (5 pts)
*/

/* -----------------------------------------------------------------------
1. What is the output of the following blocks?
   Alternatively, the blocks might not compile.
   If a block doesn't compile, which line is illegal.
   (4 pts)
*/

#include <iostream> // cout, endl

int main () {
    using namespace std;

    {
    typedef const int* pointer;
    int      i = 2;
    pointer  p = &i;
    pointer& r = p;
//  *r = 0;                     // doesn't compile
    r  = 0;
    cout << i << " ";
    cout << p << endl;
    }

    {
    typedef int* const pointer;
    int      i = 2;
    pointer  p = &i;
    pointer& r = p;
    *r = 0;
//  r  = 0;                     // doesn't compile
    cout << i << " ";
    cout << p << endl;
    }

    return 0;}
