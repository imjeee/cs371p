// -----------
// Complex.c++
// -----------

#include <cassert>  // assert
#include <iostream> // cout, endl
#include <utility>  // !=

template <typename T>
class My_Complex {
    friend bool operator == (const My_Complex& lhs, const My_Complex& rhs) {
        return (lhs._r == rhs._r) && (rhs._i == rhs._i);}

    private:
        T _r;
        T _i;

    public:
        My_Complex (const T& r = T(), const T& i = T()) :
                _r (r),
                _i (i)
            {}
/*
        My_Complex (const My_Complex& rhs) :
                _r (rhs._r),
                _i (rhs._i)
            {}

        My_Complex& operator = (const My_Complex& rhs) {
            _r = rhs._r;
            _i = rhs._i;
            return *this;}

        ~My_Complex ()
            {}
*/
        My_Complex& conjugate () {
            _i = -_i;
            return *this;}};

template <typename T>
My_Complex<T> conjugate (My_Complex<T> v) {
    return v.conjugate();}

int main () {
    using namespace std;
    using namespace std::rel_ops;
    cout << "Complex.c++" << endl;

    My_Complex<int> x;
    My_Complex<int> y(2);
    My_Complex<int> z(2, 3);

    My_Complex<int> t(y);
    assert( t ==  y);
    assert(&t != &y);

    My_Complex<int>& u = (t = z);
    assert( t ==  z);
    assert(&t != &z);
    assert(&u == &t);

    My_Complex<int>& v = z.conjugate();
    assert( z ==  My_Complex<int>(2, -3));
    assert(&v == &z);

    My_Complex<int> w = conjugate(z);
    assert(z == My_Complex<int>(2, -3));
    assert(w == My_Complex<int>(2,  3));

    cout << "Done." << endl;
    return 0;}
