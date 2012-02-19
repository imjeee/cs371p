// -------------
// Arguments.c++
// -------------

#include <cassert>  // assert
#include <iostream> // cout, endl

void f (int v, int* p, int& r) {
    ++v;
    ++(*p);
    ++r;}

void g (int p[]) {
    assert(sizeof(p) == 8);
    ++p;
    ++p[0];
    ++*p;}

void h (int* p) {
    assert(sizeof(p) == 8);
    ++p;
    ++p[0];
    ++*p;}

int main () {
    using namespace std;
    cout << "Arguments.c++" << endl;

    {
    int i = 2;
    int j = 2;
    int k = 2;
    f(i, &j, k);
    assert(i == 2);
    assert(j == 3);
    assert(k == 3);
    }

    {
    int a[] = {2, 3, 4};
    assert(sizeof(a) == 12);
    assert(a[1]      ==  3);
    g(a);
    assert(a[1]      ==  5);
    h(a);
    assert(a[1]      ==  7);
    }

    cout << "Done." << endl;
    return 0;}
