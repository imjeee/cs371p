/*
CS371p: Quiz #10 (5 pts)
*/

/* -----------------------------------------------------------------------
1. In the paper "Totally Awesome Software" how did Beck at Chrysler
   eliminate the need for exhaustive specifications and a large 'quality
   assurance' team?
   (2 pts)

writing tests before writing code
*/

/* -----------------------------------------------------------------------
2. What is the output of the following program?
   (2 pts)

3 true
3 false
*/

#include <iostream> // cout, endl

int main () {
    using namespace std;
    cout << boolalpha;   // bool outputs as true or false

    {
    int   i  = 2;
    int*  p  = &i;
    int** pp = &p;
    int** qq = pp;
    ++**qq;
    cout << i          << " ";
    ++qq;
    cout << (pp == &p) << endl;
    }

    {
    int    i  = 2;
    int*   p  = &i;
    int**  pp = &p;
    int**& qq = pp;
    ++**qq;
    cout << i          << " ";
    ++qq;
    cout << (pp == &p) << endl;
    }

    return 0;}
