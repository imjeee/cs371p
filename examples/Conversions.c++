// ---------------
// Conversions.c++
// ---------------

#include <cassert>  // assert
#include <cstddef>  // size_t
#include <iostream> // cout, endl

template <typename T>
class Complex1 {
    friend bool operator == (const Complex1& lhs, const Complex1& rhs) {
        return (lhs._r == rhs._r) && (lhs._i == rhs._i);}

    private:
        T _r;
        T _i;

    public:
        Complex1 (const T& x) :
                _r (x),
                _i (0)
            {}};

template <typename T>
class Complex2 {
    private:
        T _r;
        T _i;

    public:
        explicit Complex2 (const T& x) :
                _r (x),
                _i (0)
            {}

        explicit Complex2 (const Complex2& that) :
                _r (that._r),
                _i (that._i)
            {}

        operator T () {
            return _r;}};

void f (const Complex1<int>&) {}
void g (const Complex2<int>&) {}
void h (int) {}

struct A {
    operator int () {
        return 2;}};

struct B : A
    {};

int main () {
    using namespace std;
    cout << "Conversions..c++" << endl;

    {
    Complex1<int> x = 2;
    x = 3;
    Complex1<int> y = x;
    }

    {
    Complex1<int> x(2);
    f(x);
    f(Complex1<int>(2));
    f(static_cast< Complex1<int> >(2));
    f(2);
    }

    {
    h(2);
    Complex1<int> x(2);
//  h(static_cast<int>(x)); // error: invalid static_cast from type 'Complex1<int>' to type 'int'
//  h(x);                   // error: cannot convert 'Complex1<int>' to 'int' for argument '1' to 'void h(int)'
    }

    {
    Complex1<int> x(2);
    Complex1<int> y(2);
    assert(x == y);
    assert(x == 2);
    assert(2 == y);
    }

    {
//  Complex2<int> x = 2; // error: conversion from 'int' to non-scalar type 'Complex2<int>' requested
//  Complex2<int> y = x; // error: no matching function for call to 'Complex2<int>::Complex2(Complex2<int>&)'
    }

    {
    Complex2<int> x(2);
    g(x);
//  g(Complex2<int>(2));                // error: no matching function for call to 'Complex2<int>::Complex2(Complex2<int>)'
//  g(static_cast< Complex2<int> >(2)); // error: no matching function for call to 'Complex2<int>::Complex2(Complex2<int>)'
//  g(2);                               // error: in passing argument 1 of 'void g(const Complex2<int>&)'
    }

    {
    h(2);
    Complex2<int> x(2);
    h(static_cast<int>(x));
    h(x);
    }

    {
    Complex2<int> x(2);
    Complex2<int> y(2);
    assert(x == y);
    assert(x == 2);
    assert(2 == y);
    }

    {
    B x;
    h(x);
    }

    cout << "Done." << endl;
    return 0;}
