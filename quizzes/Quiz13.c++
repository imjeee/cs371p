/*
CS371p: Quiz #13 (5 pts)
*/

/* -----------------------------------------------------------------------
1. What is the output of the following program?
   (4 pts)

-40
12
*/

#include <iostream> // cout, endl

using namespace std;

template <typename T, std::size_t N>
struct Allocator {
    char a[N];
    ...};

int& view (char& c) {
    return *reinterpret_cast<int*>(&c);}

int main () {
    assert(sizeof(double) == 8);
    Allocator<double, 100> x;

    x.allocate(5);
    x.allocate(3);

    cout << view(x.a[0])  << endl;
    cout << view(x.a[96]) << endl;
    return 0;}
