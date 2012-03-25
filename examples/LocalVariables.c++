// ------------------
// LocalVariables.c++
// ------------------

#include <cassert>  // assert
#include <iostream> // cout, endl

int f () {
    int v = 2;
    ++v;
    return v;}

int cf () {
//  const int cv;     // error: uninitialized const "cv"
    const int cv = 2;
//  ++cv;             // error: increment of read-only variable "cv"
    return cv;}

int sf () {
    static int sv = 2;
    ++sv;
    return sv;}

int scf () {
//  static const int scv;     // error: uninitialized const "scv"
    static const int scv = 2;
//  ++scv;                    // error: increment of read-only variable "scv"
    return scv;}

int main () {
    using namespace std;
    cout << "LocalVariables.c++" << endl;

    {
    int i = f();
    assert(i == 3);
    int j = f();
    assert(j == 3);
    }

    {
    int i = cf();
    assert(i == 2);
    int j = cf();
    assert(j == 2);
    }

    {
    int i = sf();
    assert(i == 3);
    int j = sf();
    assert(j == 4);
    }

    {
    int i = scf();
    assert(i == 2);
    int j = scf();
    assert(j == 2);
    }

    cout << "Done." << endl;
    return 0;}
