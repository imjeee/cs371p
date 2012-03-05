/*
CS371p: Quiz #12 (5 pts)
*/

/* -----------------------------------------------------------------------
1. What are the five iterator categories?
   List them from weakest to strongest.
   (2 pts)

input
output
forward
bidirectional
random access
*/

/* -----------------------------------------------------------------------
2. What kind of iterator does the following algorithm need?
   (2 pts)

forward
*/

#include <cassert>  // cout
#include <iostream> // cout, endl

template <typename I, typename T>
    void f (I b, I e, const T& v) {
        while (b != e) {
            *b = v;
            ++b;}}

int main () {
    using namespace std;
    const int s = 3;
          int x[s];
    f(x, x + s, 2);
    assert(x[0] == 2);
    assert(x[1] == 2);
    assert(x[2] == 2);
    cout << "Done." << endl;
    return 0;}
