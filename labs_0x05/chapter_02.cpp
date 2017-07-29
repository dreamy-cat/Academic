#include "chapter_02.hpp"

using namespace std;

string function_4(string s)
{
    cout << "Function 4 finding string more secure, ";
    string r;
    if (s == "string" || s == "String") r = "founded."; else r = "not founded.";
    cout << r << endl;
    return r;
}

Class_2_1::Class_2_1(bool isException) {
    cout << "Class_2_1 constructor.\n";
    if (isException) throw("Throwing excetion.\n");
}

Class_2_1::~Class_2_1() { cout << "Class_2_1 destructor.\n"; }

Class_2_2::Class_2_2(bool isException) {
    cout << "Class_2_1 constructor.\n";
    if (isException) throw("Throwing exception.");
}

Class_2_2::~Class_2_2() {
    cout << "Class_2_2 destructor.\n";
}

Class_2_3::Class_2_3(bool isException) try : Class_2_1(isException), obj(isException)
{

} catch ( ... ) {
    cout << "Catching exception from base classes.\n";
}

Class_2_4::Class_2_4(bool isException) try
    : Class_2_1(isException)
      /*        // incorrect using static_cast.
      i(new int(static_cast<int*>(this))),
      c(new char(static_cast<char*>(this)))
            */
{
    cout << "Class_2_4 constructor.\n";
} catch ( ... ) {
    cout << "Catching exception.\n";
}

Class_2_4::~Class_2_4() { cout << "Class_2_4 destructor.\n"; }
