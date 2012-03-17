// ----------
// Count1.c++
// ----------

#include <algorithm> // count, count_if
#include <cassert>   // assert
#include <cstddef>   // ptrdiff_t
#include <cstring>   // strlen
#include <iostream>  // cout, endl

std::ptrdiff_t count_1 (const char* b, const char* e, char v) {
    std::ptrdiff_t c = 0;
    while (b != e) {
        if (*b == v)
            ++c;
        ++b;}
    return c;}

template <typename II, typename T>
std::ptrdiff_t count_2 (II b, II e, const T& v) {
    std::ptrdiff_t c = 0;
    while (b != e) {
        if (*b == v)
            ++c;
        ++b;}
    return c;}

std::ptrdiff_t count__if_1 (const char* b, const char* e, bool (*f) (char)) {
    std::ptrdiff_t c = 0;
    while (b != e) {
        if (f(*b))
            ++c;
        ++b;}
    return c;}

template <typename II, typename UP>
std::ptrdiff_t count__if_2 (II b, II e, UP f) {
    std::ptrdiff_t c = 0;
    while (b != e) {
        if (f(*b))
            ++c;
        ++b;}
    return c;}

bool my_isupper (char c) {
    return (c >= 'A') && (c <= 'Z');}

int main () {
    using namespace std;
    cout << "Count1.c++" << endl;

    typedef bool (*CUP) (char);

    const char a[] = "abCbA";
    const int  s   = strlen(a);
    const CUP  p   = my_isupper;

    assert(count   (a, a + s, 'b')        == 2);
    assert(count   (a, a + s, 'd')        == 0);
    assert(count_if(a, a + s, my_isupper) == 2);
    assert(count_if(a, a + s, p)          == 2);

    assert(count_1   (a, a + s, 'b')        == 2);
    assert(count_1   (a, a + s, 'd')        == 0);
    assert(count__if_1(a, a + s, my_isupper) == 2);
    assert(count__if_1(a, a + s, p)          == 2);

    assert(count_2   (a, a + s, 'b')        == 2);
    assert(count_2   (a, a + s, 'd')        == 0);
    assert(count__if_2(a, a + s, my_isupper) == 2);
    assert(count__if_2(a, a + s, p)          == 2);

    cout << "Done." << endl;
    return 0;}
