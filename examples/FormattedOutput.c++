// -------------------
// FormattedOutput.c++
// -------------------

#include <cassert>  // assert
#include <ios>      // fmtflags
#include <iostream> // cout, endl, fixed, flags, ios_base, left, precision, scientific, streamsize
#include <iomanip>  // setfill, setprecision, setw
#include <sstream>  // ostringstream
#include <string>   // ==

int main () {
    using namespace std;
    cout << "FormattedOutput.c++." << endl;

    ios_base::sync_with_stdio(false); // turn off synchronization with C I/O
    const double pi = 3.1415926536;

    {
    ostringstream out;
    out << pi;
    assert(out.str() == "3.14159");
    }

    {
    ostringstream out;
    out << setfill('x') << setprecision(3) << setw(7) << pi << pi;
    out << setw(7) << pi;
    assert(out.str() == "xxx3.143.14xxx3.14");
    }

    {
    ostringstream out;
    out << left << setfill('x') << setw(10) << pi;
    assert(out.str() == "3.14159xxx");
    }

    {
    ostringstream out;
    out << fixed << setfill('x') << setw(11) << pi;
    assert(out.str() == "xxx3.141593");
    }

    {
    ostringstream out;
    out << scientific << setfill('x') << setw(15) << pi;
    assert(out.str() == "xxx3.141593e+00");
    }

    {
    ostringstream out;
    out << setw(10) << pi;
    out << left << setfill('x') << setprecision(3) << setw(7) << pi;
    assert(out.str() == "   3.141593.14xxx");
    out.fill(' ');
    out.unsetf(out.flags());
    out.precision(6);
    out << setw(10) << pi;
    assert(out.str() == "   3.141593.14xxx   3.14159");
    }

    {
    ostringstream out;
    const char               fill      = out.fill();
    const ios_base::fmtflags flags     = out.flags();
    const streamsize         precision = out.precision();
    out << setw(10) << pi;
    out << left << setfill('x') << setprecision(3) << setw(7) << pi;
    assert(out.str() == "   3.141593.14xxx");
    out.fill(fill);
    out.flags(flags);
    out.precision(precision);
    out << setw(10) << pi;
    assert(out.str() == "   3.141593.14xxx   3.14159");
    }

    cout << "Done." << endl;
    return 0;}
