// ------------
// Arrays2D.c++
// ------------

#include <algorithm> // count, fill
#include <cassert>   // assert
#include <cstddef>   // size_t
#include <iostream>  // cout, endl
#include <vector>    // vector

const std::size_t r =  5;
const std::size_t c = 10;
const std::size_t s = r * c;

const int v = 2;

typedef int (*pointer2d) [c];

void f1 (int p[][c]) {
    assert(sizeof(p) == 8);
    ++p[2][3];
    ++(*((*(p + 2)) + 3));}

void f2 (pointer2d p) {
    assert(sizeof(p) == 8);
    ++p[2][3];
    ++(*((*(p + 2)) + 3));}

void g1 (int p[]) {
    assert(sizeof(p) == 8);
    ++p[(2 * c) + 3];
    ++*(p + 23);}

void g2 (int* p) {
    assert(sizeof(p) == 8);
    ++p[(2 * c) + 3];
    ++*(p + 23);}

void h1 (int* p[]) {
    assert(sizeof(p) == 8);
    ++p[2][3];
    ++(*((*(p + 2)) + 3));}

void h2 (int** p) {
    assert(sizeof(p) == 8);
    ++p[2][3];
    ++(*((*(p + 2)) + 3));}

int main () {
    using namespace std;
    cout << "Arrays2D.c++" << endl;

    {
    int a[r][c] = {{2, 3}, {4, 5, 6}, {7, 8, 9, 10}};
    assert(a[2][3] == 10);
    for (size_t i = 0; i != r; ++i) {
        fill(a[i], a[i] + c, v);
        assert(count(a[i], a[i] + c, v) == c);}       // warning
    assert(a[2][3] == v);
//  const int*      p = a;                            // doesn't compile
    const pointer2d p = a;
    assert(&a[2][3] == &p[2][3]);
    assert(sizeof(a) != sizeof(p));
    assert(sizeof(a) == r * c * sizeof(int));
    assert(sizeof(p) == 8);
    f1(p);
    assert(a[2][3] == v + 2);
    f2(p);
    assert(a[2][3] == v + 4);
//  g1(p);                                            // doesn't compile
//  g2(p);                                            // doesn't compile
//  h1(p);                                            // doesn't compile
//  h2(p);                                            // doesn't compile
//  const pointer2d q = a[0];                         // doesn't compile
    int* const      q = a[0];
    assert(&a[2][3] == &q[(2 * c) + 3]);
//  f1(q);                                            // doesn't compile
//  f2(q);                                            // doesn't compile
    g1(q);
    assert(a[2][3] == v + 6);
    g2(q);
    assert(a[2][3] == v + 8);
//  h1(q);                                            // doesn't compile
//  h2(q);                                            // doesn't compile
    fill(q, q + s, v);
    assert(a[2][3] == v);
    }

    {
    int* const a = new int[s];
    fill(a, a + s, v);
    assert(count(a, a + s, v) == s);                    // warning
    assert(a[(2 * c) + 3] == v);
//  f1(a);                                              // doesn't compile
//  f2(a);                                              // doesn't compile
    g1(a);
    assert(a[(2 * c) + 3] == v + 2);
    g2(a);
    assert(a[(2 * c) + 3] == v + 4);
//  h1(a);                                              // doesn't compile
//  h2(a);                                              // doesn't compile
    const pointer2d p = reinterpret_cast<pointer2d>(a);
    assert(&a[(2 * c) + 3] == &p[2][3]);
    f1(p);
    assert(p[2][3] == v + 6);
    f2(p);
    assert(p[2][3] == v + 8);
//  g1(p);                                              // doesn't compile
//  g2(p);                                              // doesn't compile
//  h1(p);                                              // doesn't compile
//  h2(p);                                              // doesn't compile
    delete [] a;
    }

    {
    int** const a = new int*[r];
    for (size_t i = 0; i != r; ++i) {
        a[i] = new int[c];
        fill(a[i], a[i] + c, v);
        assert(count(a[i], a[i] + c, v) == c);} // warning
    assert(a[2][3] == v);
//  f1(a);                                      // doesn't compile
//  f2(a);                                      // doesn't compile
//  g1(a);                                      // doesn't compile
//  g2(a);                                      // doesn't compile
    h1(a);
    assert(a[2][3] == v + 2);
    h2(a);
    assert(a[2][3] == v + 4);
    for (size_t i = 0; i != r; ++i)
        delete [] a[i];
    delete [] a;
    }

    {
    int** const a = new int*[r];
    a[0] = new int[s];
    for (size_t i = 1; i != r; ++i)
        a[i] = a[i - 1] + c;
    fill(a[0], a[0] + s, v);
    assert(count(a[0], a[0] + s, v) == s);                 // warning
    assert(a[2][3] == v);
    const pointer2d p = reinterpret_cast<pointer2d>(a[0]);
    f1(p);
    assert(a[2][3] == v + 2);
    f2(p);
    assert(a[2][3] == v + 4);
    g1(a[0]);
    assert(a[2][3] == v + 6);
    g2(a[0]);
    assert(a[2][3] == v + 8);
    h1(a);
    assert(a[2][3] == v + 10);
    h2(a);
    assert(a[2][3] == v + 12);
    delete [] a[0];
    delete [] a;
    }

    {
    vector< vector<int> > x(r, vector<int>(c, v));
    assert(x.size()    == r);
    assert(x[0].size() == c);
    assert(x[2][3]     == v);
    vector< vector<int> > y(x);
    assert(x.size() == y.size());
    assert( x[2][3] ==  y[2][3]);
    assert(&x[2][3] != &y[2][3]);
    vector< vector<int> > z(2 * r, vector<int>(2 * c, v));
    x = z;
    assert(x.size() == z.size());
    assert( x[2][3] ==  z[2][3]);
    assert(&x[2][3] != &z[2][3]);
    }

    cout << "Done." << endl;
    return 0;}
