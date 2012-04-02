// -----------------------
// OperatorOverloading.c++
// -----------------------

#include <algorithm> // equal, fill, lexicographical_compare
#include <cassert>   // assert
#include <cstddef>   // size_t
#include <iostream>  // cout, endl, istream, ostream
#include <sstream>   // istringstream, ostringstream
#include <stdexcept> // out_of_range
#include <string>    // ==
#include <utility>   // !=, <=, >, >=

/*
namespace std     {
namespace rel_ops {

template <typename T>
inline bool operator != (const T& lhs, const T& rhs) {
    return !(lhs == rhs);}

template <typename T>
inline bool operator <= (const T& lhs, const T& rhs) {
    return !(rhs < lhs);}

template <typename T>
inline bool operator > (const T& lhs, const T& rhs) {
    return (rhs < lhs);}

template <typename T>
inline bool operator >= (const T& lhs, const T& rhs) {
    return !(lhs < rhs);}

} // rel_ops
} // std;
*/

template <typename T>
class my_vector {
    private:
        const std::size_t _s;
        T*    const       _a;

    public:
        explicit my_vector (std::size_t s = 0, const T& v = T()) :
                _s (s),
                _a (new T[_s]) {
            std::fill(begin(), end(), v);}

        ~my_vector () {
            delete [] _a;}

        T& operator [] (std::size_t i) {
            return _a[i];}

        const T& operator [] (std::size_t i) const {
            return (*const_cast<my_vector<T>*>(this))[i];}

        T& at (std::size_t i) {
            if (i >= size())
                throw std::out_of_range("my_vector::at index out of range");
            return (*this)[i];}

        const T& at (std::size_t i) const {
            return const_cast<my_vector<T>*>(this)->at(i);}

        T* begin () {
            return _a;}

        const T* begin () const {
            return const_cast<my_vector<T>*>(this)->begin();}

        T* end () {
            return _a + _s;}

        const T* end () const {
            return const_cast<my_vector<T>*>(this)->end();}

        std::size_t size () const {
            return _s;}};

template <typename T>
bool operator == (const my_vector<T>& lhs, const my_vector<T>& rhs) {
    return (lhs.size() == rhs.size()) && std::equal(lhs.begin(), lhs.end(), rhs.begin());}

template <typename T>
bool operator < (const my_vector<T>& lhs, const my_vector<T>& rhs) {
    return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());}

template <typename T>
std::istream& operator >> (std::istream& lhs, my_vector<T>& rhs) {
    for (std::size_t i = 0; i != rhs.size(); ++i)
        lhs >> rhs[i];
    return lhs;}

template <typename T>
std::ostream& operator << (std::ostream& lhs, const my_vector<T>& rhs) {
    for (std::size_t i = 0; i != rhs.size(); ++i)
        lhs << rhs[i] << " ";
    return lhs;}

int main () {
    using namespace std;
    using namespace std::rel_ops;
    cout << "OperatorOverloading.c++" << endl;

    {
    my_vector<int> x(10, 2);
    assert(x[1]    == 2);
    assert(x.at(1) == 2);
    ++x[1];
    ++x.at(1);
    assert(x[1] == 4);
    }

    {
    const my_vector<int> x(10, 2);
    assert(x[1]    == 2);
    assert(x.at(1) == 2);
//  ++x[1];                        // error: assignment of read-only location
//  ++x.at(1);                     // error: assignment of read-only location
    }

    {
    const my_vector<int> x(10, 2);
    const my_vector<int> y(10, 2);
    assert(equal(x.begin(), x.end(), y.begin()));
    }

    {
    const my_vector<int> x(10, 2);
    const my_vector<int> y(10, 2);
    assert(x == y);
    assert(x <= y);
    assert(x >= y);
    assert(!(x != y));
    assert(!(x <  y));
    assert(!(x >  y));
    }

    {
    istringstream in("2 2 2");
    my_vector<int> x(3);
    in >> x;
    ostringstream out;
    out << x;
    assert(out.str() == "2 2 2 ");
    }

    cout << "Done." << endl;
    return 0;}
