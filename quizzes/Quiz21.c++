/*
CS371p: Quiz #21 (5 pts)
*/

/* -----------------------------------------------------------------------
1. Define the function my_reverse().
*/

#include <algorithm> // swap
#include <cassert>   // assert
#include <cstring>   // strcmp
#include <iostream>  // cout, endl

using namespace std;

template <typename RI>
void my_reverse (RI b, RI e) {
    while (b < e) {
        --e;
        std::swap(*b, *e);
        ++b;}}

int main () {
    using namespace std;

    char a[] = "abcde";
    char b[] = "edcba";
    my_reverse(a, a + 5);
    assert(strcmp(a, b) == 0);

    return 0;}
