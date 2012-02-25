/*
CS371p: Quiz #14 (5 pts)
*/

/* -----------------------------------------------------------------------
1. What is the difference between is-a and has-a abstraction?
   [Sec. 2.2, Pg. 31]
   (2 pts)

division into specialization vs. division into parts
*/

/* -----------------------------------------------------------------------
2. What is the output of the following program?
   (2 pts)

A()

A(A)
~A()

A(A)
~A()

~A()
*/

#include <iostream> // cout, endl
#include <memory>   // allocator

using namespace std;

struct A {
    A () {                         // default constructor
        cout << "A()" << endl;}

    A (const A&) {                 // copy constructor
        cout << "A(A)" << endl;}

    ~A () {                        // destructor
        cout << "~A()" << endl;}};

int main () {
    {
    A v;
    cout << endl;

    {
    A* p = new A(v);
    delete p;
    }
    cout << endl;

    {
    allocator<A> x;
    A* p = x.allocate(1);
    x.construct(p, v);
    x.destroy(p);
    x.deallocate(p, 1);
    }
    cout << endl;
    }

    return 0;}
