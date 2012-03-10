/*
CS371p: Quiz #20 (5 pts)
*/

/* -----------------------------------------------------------------------
1. What is the output of the following program?
   You MUST get the newlines right to get full credit.
   Write the word "blank" to indicate a blank line.
   (4 pts)

A() A(A) ~A() A() A(A) ~A() A() A(A) ~A()
~A() ~A() ~A()
*/

#include <iostream> // cout, endl

using namespace std;

struct A {
    A () {                     // default constructor
        cout << "A() ";}

    A (const A&) {             // copy constructor
        cout << "A(A) ";}

    A& operator = (const A&) { // copy assignment operator
        cout << "=(A) ";
        return *this;}

    ~A () {                    // destructor
        cout << "~A() ";}};

struct B : A {};

int main () {
    {
    A a[] = {B(), B(), B()};
    cout << endl;
    }
    cout << endl;

    return 0;}
