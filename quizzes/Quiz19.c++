/*
CS371p: Quiz #19 (5 pts)
*/

/* -----------------------------------------------------------------------
1. What is the output of the following program?
   You MUST get the newlines right to get full credit.
   Write the word "blank" to indicate a blank line.
   (4 pts)

A(int) A(int) A(int) A() A()
~A() ~A() ~A() ~A() ~A()
*/

#include <iostream> // cout, endl
#include <cstddef>  // size_t

using namespace std;

struct A {
    A () {                     // default constructor
        cout << "A() ";}

    A (int) {                  // int constructor
        cout << "A(int) ";}

    A (const A&) {             // copy constructor
        cout << "A(A) ";}

    A& operator = (const A&) { // copy assignment operator
        cout << "=(A) ";
        return *this;}

    ~A () {                    // destructor
        cout << "~A() ";}};

int main () {
    {
    const std::size_t s = 5;
    A a[s] = {2, 3, 4};
    cout << endl;
    }
    cout << endl;

    return 0;}
