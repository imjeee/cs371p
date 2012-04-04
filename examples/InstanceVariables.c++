// ---------------------
// InstanceVariables.c++
// ---------------------

#include <cassert>  // assert
#include <iostream> // cout, endl

template <typename T>
struct A {
//  T v = 2; // error: ISO C++ forbids initialization of member "v"
    T v;
    T w;};

template <typename T>
struct B {
          T v;
    const T cv;};

template <typename T>
struct C {
    T v;

    C () {
        std::cout << "C()" << std::endl;}

    C (const C&) {
        std::cout << "C(const C&)" << std::endl;}};

template <typename T>
struct D {
    T v;};

int main () {
    using namespace std;
    cout << "InstanceVariables.c++" << endl;

    {
    A<int> x;
    A<int> y = {};
    A<int> z = {2};
    A<int> t = {2, 3};
    }

    {
//  const A<int> x;          // error: uninitialized const "x"
    const A<int> y = {};
    const A<int> z = {2};
    const A<int> t = {2, 3};
    assert(t.v == 2);
    assert(t.w == 3);
//  assert(A<int>::v == 2);  // error: invalid use of non-static data member "A<int>::v"
    }

    {
    const A<int> x = {2, 3};
          A<int> y = x;      // A<int> y(x);
    assert(y.v == 2);
    assert(y.w == 3);
    assert(&x.v != &y.v);
    assert(&x.w != &y.w);

    {
    const A<int> x = {2, 3};
          A<int> y = {4, 5};
    y = x;
    assert(y.v  == 2);
    assert(y.w  == 3);
    assert(&x.v != &y.v);
    assert(&x.w != &y.w);
    }

    {
//  B<int> x;          // error: structure "x" with uninitialized const members
//  B<int> y = {};     // error: uninitialized const member "B<int>::cv"
//  B<int> z = {2};    // error: uninitialized const member "B<int>::cv"
    B<int> t = {2, 3};
    assert(t.v  == 2);
    assert(t.cv == 3);
    }

    {
    const B<int> x = {2, 3};
          B<int> y = x;      // B<int> y(x);
    assert(y.v  == 2);
    assert(y.cv == 3);
    assert(&x.v  != &y.v);
    assert(&x.cv != &y.cv);
    }

    {
    const B<int> x = {2, 3};
          B<int> y = {4, 5};
    assert(y.v  == 4);
    assert(y.cv == 5);
//  y = x;                   // error: non-static const member "const int B<int>::cv", can't use default assignment operator
    }
    }

    {
    C<int> x;
//  C<int> y = {};  // error: scalar object ‘y’ requires one element in initializer
//  C<int> z = {2}; // error: conversion from ‘int’ to non-scalar type ‘C<int>’ requested

    D< C<int> > r;
    D< C<int> > s = {};
    D< C<int> > t = {x};
    }

    cout << "Done." << endl;
    return 0;}

/*
InstanceVariables.c++
C()
C()
C()
C(const C&)
Done.
*/
