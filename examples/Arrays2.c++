// -----------
// Arrays2.c++
// -----------

#include <cassert>  // assert
#include <iostream> // cout, endl
#include <string>   // string

std::string f1 (int a[]) {
    return "f1(int a[])";}

std::string f2 (int* a) {
    return "f2(int* a)";}

std::string g1 (int a[][20]) {
    return "g1(int a[][20])";}

std::string g2 (int (*a)[20]) {
    return "g2(int (*a)[20])";}

std::string h1 (int* a[]) {
    return "h1(int** a)";}

std::string h2 (int** a) {
    return "h2(int** a)";}

int main () {
    using namespace std;
    cout << "Arrays2.c++" << endl;

    int  a[10];
    int  b[10][20];
    int* c[10];

    f1(a);
//  f1(b); // error: cannot convert 'int (*)[20]' to 'int*' for argument '1' to 'std::string f1(int*)'
//  f1(c); // error: cannot convert 'int**' to 'int*' for argument '1' to 'std::string f1(int*)'

    f2(a);
//  f2(b); // error: cannot convert 'int (*)[20]' to 'int*' for argument '1' to 'std::string f1(int*)'
//  f2(c); // error: cannot convert 'int**' to 'int*' for argument '1' to 'std::string f1(int*)'

//  g1(a); // error: cannot convert 'int*' to 'int (*)[20]' for argument '1' to 'std::string g1(int (*)[20])'
    g1(b);
//  g1(c); // error: cannot convert 'int**' to 'int (*)[20]' for argument '1' to 'std::string g1(int (*)[20])'

//  g2(a); // error: cannot convert 'int*' to 'int (*)[20]' for argument '1' to 'std::string g1(int (*)[20])'
    g2(b);
//  g2(c); // error: cannot convert 'int**' to 'int (*)[20]' for argument '1' to 'std::string g1(int (*)[20])'

//  h1(a); // error: cannot convert 'int*' to 'int**' for argument '1' to 'std::string h(int**)'
//  h1(b); // error: cannot convert 'int (*)[20]' to 'int**' for argument '1' to 'std::string h(int**)'
    h1(c);

//  h2(a); // error: cannot convert 'int*' to 'int**' for argument '1' to 'std::string h(int**)'
//  h2(b); // error: cannot convert 'int (*)[20]' to 'int**' for argument '1' to 'std::string h(int**)'
    h2(c);

    cout << "Done." << endl;
    return 0;}
