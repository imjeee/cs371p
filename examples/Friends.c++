// -----------
// Friends.c++
// -----------

#include <cassert>  // assert
#include <iostream> // cout, endl

// -
// f
// -

int f1 ();

template <typename T>
int f2 ();

template <typename T>
int f3 ();

template <typename T>
int f4 ();

// -
// B
// -

struct B1 {
    int f ();};

template <typename T>
struct B2 {
    int f ();};

template <typename T>
struct B3 {
    int f ();};

template <typename T>
struct B4 {
    int f ();};

// -
// C
// -

struct C1 {
    int f ();};

template <typename T>
struct C2 {
    int f ();};

template <typename T>
struct C3 {
    int f ();};

template <typename T>
struct C4 {
    int f ();};

// -
// A
// -

template <typename T>
class A {
    // global function f1
    friend int f1 ();

    // 'int' instance  of global function template f2
    friend int f2<int>();

    // T     instance  of global function template f3
    friend int f3<T>();

    // all   instances of global function template f4
    template <typename U>
    friend int f4(); // not f4<U>()!

    // struct B1
    friend struct B1;

    // 'int' instance  of class template B2
    friend struct B2<int>;

    // T     instance  of class template B3
    friend struct B3<T>;

    // all   instances of class template B4
    template <typename U>
    friend struct B4; // not B4<U>!

    // class C1 method f
    friend int C1::f();

    // 'int' instance  of class template C2 method f
    friend int C2<int>::f();

    // T     instance  of class template C3 method f
    friend int C3<T>::f();

    // all   instances of class template C4 method f
    template <typename U>
    friend int C4<U>::f(); // not C4::f()!

    private:
        int i;

    public:
        A (int i) :
                i (i)
            {}};

// -
// f
// -

int f1 () {
    A<int> x = 2;
    return ++x.i;}

template <typename T>
int f2 () {
    A<double> x = 2;
    return ++x.i;}

template <typename T>
int f3 () {
    A<int> x = 2;
    return ++x.i;}

template <typename T>
int f4 () {
    A<bool> x = 2;
    return ++x.i;}

// -
// B
// -

int B1::f () {
    A<int> x = 2;
    return ++x.i;}

template <typename T>
int B2<T>::f () {
    A<double> x = 2;
    return ++x.i;}

template <typename T>
int B3<T>::f () {
    A<int> x = 2;
    return ++x.i;}

template <typename T>
int B4<T>::f () {
    A<bool> x = 2;
    return ++x.i;}

// -
// C
// -

int C1::f () {
    A<int> x = 2;
    return ++x.i;}

template <typename T>
int C2<T>::f () {
    A<double> x = 2;
    return ++x.i;}

template <typename T>
int C3<T>::f () {
    A<int> x = 2;
    return ++x.i;}

template <typename T>
int C4<T>::f () {
    A<bool> x = 2;
    return ++x.i;}

// ----
// main
// ----

int main () {
    using namespace std;
    cout << "Friends.c++" << endl;

    {
    assert(f1()         == 3); // f1               friend of A<int>
    assert(f2<int>()    == 3); // f2<int>          friend of A<double>
//  assert(f2<double>() == 3); // f2<double> not a friend of A<double>
    assert(f3<int>()    == 3); // f3<int>          friend of A<int>
//  assert(f3<double>() == 3); // f3<double> not a friend of A<int>
    assert(f4<int>()    == 3); // f4<int>          friend of A<bool>
    assert(f4<double>() == 3); // f4<double>       friend of A<bool>
    }

    {
    B1 x;               // B1               friend of A<int>
    assert(x.f() == 3);
    }

    {
    B2<int> x;          // B2<int>          friend of A<double>
    assert(x.f() == 3);
    }
/*
    {
    B2<double> x;       // B2<double> not a friend of A<double>
    assert(x.f() == 3);
    }
*/
    {
    B3<int> x;          // B3<int>          friend of A<int>
    assert(x.f() == 3);
    }
/*
    {
    B3<double> x;       // B3<double> not a friend of A<int>
    assert(x.f() == 3);
    }
*/
    {
    B4<int> x;          // B4<int>          friend of A<bool>
    assert(x.f() == 3);
    }

    {
    B4<double> x;       // B4<double>       friend of A<bool>
    assert(x.f() == 3);
    }

    {
    C1 x;               // C1               friend of A<int>
    assert(x.f() == 3);
    }

    {
    C2<int> x;          // C2<int>          friend of A<double>
    assert(x.f() == 3);
    }
/*
    {
    C2<double> x;       // C2<double> not a friend of A<double>
    assert(x.f() == 3);
    }
*/
    {
    C3<int> x;          // C3<int>          friend of A<int>
    assert(x.f() == 3);
    }
/*
    {
    C3<double> x;       // C3<double> not a friend of A<int>
    assert(x.f() == 3);
    }
*/
    {
    C4<int> x;          // C4<int>          friend of A<bool>
    assert(x.f() == 3);
    }

    {
    C4<double> x;       // C4<double>       friend of A<bool>
    assert(x.f() == 3);
    }

    cout << "Done." << endl;
    return 0;}
