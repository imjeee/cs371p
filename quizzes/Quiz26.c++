/*
CS371p: Quiz #26 (5 pts)
*/

/* -----------------------------------------------------------------------
1. What is a "hallway usability test"?
   [The Joel Test]
   (2 pts)

A hallway usability test is where you grab the next person that passes by
in the hallway and force them to try to use the code you just wrote. If
you do this to five people, you will learn 95% of what there is to learn
about usability problems in your code.
*/

/* -----------------------------------------------------------------------
2. What is the output of the following program?
   Alternatively, the line might not compile.
   If a line doesn't compile, which line is illegal.
   (2 pts)

false
false
*/

#include <iostream> // cout, endl

template <typename T>
struct A {
    int i;
    T   v;};

int main () {
    using namespace std;
    cout << boolalpha;   // bool outputs as true or false

    A<int> x = {2, 3};
    A<int> y = {2, 3};

    cout << (&x.i == &y.i) << endl;
    cout << (&x.v == &y.v) << endl;

    return 0;}
