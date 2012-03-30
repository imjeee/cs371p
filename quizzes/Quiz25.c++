/*
CS371p: Quiz #25 (5 pts)
*/

/* -----------------------------------------------------------------------
1. What is the output of the following program?
   Alternatively, the line might not compile.
   If a line doesn't compile, which line is illegal.

false
doesn't compile
false
doesn't compile
*/

#include <iostream> // cout, endl

template <typename T>
struct A {
    static int si;
    static T   sv;};

template <typename T>
int A<T>::si;

template <typename T>
T A<T>::sv;

int main () {
    using namespace std;
    cout << boolalpha;   // bool outputs as true or false

    cout << (&A<int>::si == &A<double>::si) << endl;
//  cout << (&A<int>::sv == &A<double>::sv) << endl;

    A<int>    x;
    A<double> y;

    cout << (&x.si == &y.si) << endl;
//  cout << (&x.sv == &y.sv) << endl;

    return 0;}
