// -------------------
// GlobalVariables.c++
// -------------------

#include <cassert>  // assert
#include <iostream> // cout, endl

int v0;
int v1 = v0 + 1;

//const int cv0;     // error: uninitialized const "cv0"
  const int cv0 = 0;

static int sv0;
static int sv1 = sv0 + 1;

//static const int scv0;     // error: uninitialized const "scv0"
  static const int scv0 = 0;

int main () {
    using namespace std;
    cout << "GlobalVariables.c++" << endl;

    assert(v0   == 0);
    assert(v1   == 1);

    assert(cv0  == 0);

    assert(sv0  == 0);
    assert(sv1  == 1);

    assert(scv0 == 0);

    cout << "Done." << endl;
    return 0;}
