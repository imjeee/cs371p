// -----------
// Methods.c++
// -----------

#include <cassert>  // assert
#include <iostream> // cout, endl

class A {
    private:
        static  int _cv;
                int _iv;
        mutable int _iw;

    public:
        A () :
                _iv (0),
                _iw (1) {
            cm();
            im();
            cim();
            A* p = this;}

        static void cm () {
            ++_cv;
//          ++_iv;       // error: invalid use of member 'A::_iv' in static member function
//          ++_iw;       // error: invalid use of member 'A::_iv' in static member function
//          im();        // error: cannot call member function 'void A::im()' without object
//          cim();       // error: cannot call member function 'void A::cim() const' without object
//          A* p = this; // error: ‘this’ is unavailable for static member functions
            }

        void im () {
            ++_cv;
            ++_iv;
            ++_iw;
            cm();
            cim();
                  A* p = this;
            const A* q = this;}

        void cim () const {
            ++_cv;
//          ++_iv;                // error: increment of data-member 'A::_iv' in read-only structure
            ++_iw;
            cm();
//          im();                 // error: no matching function for call to 'A::im() const'
//                A* p = this;    // error: invalid conversion from 'const A* const' to 'A*'
            const A* q = this;}};

int A::_cv;

int main () {
    using namespace std;
    cout << "Methods.c++" << endl;

    A::cm();
//  A::im();  // error: cannot call member function 'void A::im()' without object
//  A::cim(); // error: cannot call member function 'void A::cim() const' without object

    {
    A x;
    x.cm();
    x.im();
    x.cim();
    }

    {
    const A x;
    x.cm();
//  x.im();    // error: no matching function for call to 'A::im() const'
    x.cim();
    }

    cout << "Done." << endl;
    return 0;}
