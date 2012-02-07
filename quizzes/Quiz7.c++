/*
CS371p: Quiz #7 (5 pts)
*/

/* -----------------------------------------------------------------------
1. What is the output of the following program?
   (4 pts)

3 3 false
3 2 false
*/

#include <iostream> // cout, endl

int main () {
    using namespace std;
    cout << boolalpha;   // 'bool' outputs as 'true' or 'false'

    {
    int i = 2;
    int j = ++i;
    cout << i          << " ";
    cout << j          << " ";
    cout << (&i == &j) << endl;
    }

    {
    int i = 2;
    int j = i++;
    cout << i          << " ";
    cout << j          << " ";
    cout << (&i == &j) << endl;
    }

    return 0;}
