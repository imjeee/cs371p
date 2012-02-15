/*
CS371p: Quiz #11 (5 pts)
*/

/* -----------------------------------------------------------------------
1. What is the output of the following program?
   (4 pts)

3 false
3 true
*/

#include <iostream> // cout, endl

int*& f (int*& r) {
    ++*r;
    return r;}

int main () {
    using namespace std;
    cout << boolalpha;   // bool outputs as true or false

    {
    int  i = 2;
    int* p = &i;
    int* q = f(p);
    cout << i          << " ";
    cout << (&q == &p) << endl;
    }

    {
    int   i = 2;
    int*  p = &i;
    int*& q = f(p);
    cout << i          << " ";
    cout << (&q == &p) << endl;
    }

    return 0;}
