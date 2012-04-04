// ---------------------------
// ConstructorsDestructors.c++
// ---------------------------

#include <cassert>  // assert
#include <iostream> // cout, endl

class A {
    private:
        int  _v;
        int* _p;
        int& _r;

    public:
        A (int v, int* p, int& r) :
                _r (r) {
            _v = v;
            _p = p;
            std::cout << "A(int, int*, int&)" << std::endl;}

        A (const A& that) :
                _r (that._r) {
            _v = that._v;
            _p = that._p;
            std::cout << "A(const A&)" << std::endl;}

        ~A () {
            std::cout << "~A()" << std::endl;}};

struct B {
    private:
        A _x;

    public:
        B (int v, int* p, int& r) :
                _x (v, p, r) {
            std::cout << "B(int, int*, int&)" << std::endl;}

        B (const A& x) :
                _x (x) {
            std::cout << "B(const A&)" << std::endl;}

        ~B () {
            std::cout << "~B()" << std::endl;}};

int main () {
    using namespace std;
    cout << "ConstructorsDestructors.c++" << endl;

    {
    int  v = 2;
    int* p = &v;
    int& r = v;

    A x(v, p, r);
    cout << endl;

    {
    B y(v, p, r);
    }
    cout << endl;

    {
    B z(x);
    }
    cout << endl;
    }

    cout << "Done." << endl;
    return 0;}

/*
ConstructorsDestructors.c++
A(int, int*, int&)

A(int, int*, int&)
B(int, int*, int&)
~B()
~A()

A(const A&)
B(const A&)
~B()
~A()

~A()
Done.
*/
