#include "chapter_09.hpp"

using namespace std;

Class_9_1::Class_9_1(char ic) : c(ic) {}

Class_9_1::Class_9_1(const Class_9_1& rv) {
    if (this != &rv) cout << "New object not exist yet, addresess will be always different.\n";
    c = rv.c;
}

Class_9_1& Class_9_1::operator=(const Class_9_1& rv) {
    cout << "Class_9, operator=(), with verification of self-copy.\n";
    if (this == &rv) {
        cout << "Class_9, operator=(), self-copy, original object returned.\n";
        return *this;
    }
    cout << "Address of object is different, return this object, parameter is " << rv.c << endl;
    c = rv.c;
    return *this;
    // Risky way in task 9.4.
    // this->~Class_9_1();
    // new (this) Class_9_1(rv.c);
}

Class_9_1::Class_9_1(const char* text) {
    cout << "Non explicit constructor with constant char, " << text << endl;
    c = text[0];
}

Class_9_1::~Class_9_1() {
    cout << "Class_9_1, destructor, parameter is " << c << endl;
}

Class_9_1& Class_9_1::operator-(const Class_9_1& rv) {
    cout << "Class_9_1, operator-(), " << c << " and " << rv.c << endl;
    return *this;
}

void Class_9_1::function() {
    cout << "Class_9_1, function try to destruct the object.\n";
    this->~Class_9_1();
    new (this) Class_9_1('e');
}

Class_9_2::Class_9_2(char ic) : Class_9_1(ic) {}

Class_9_2& Class_9_2::operator=(const Class_9_2& rv) {
    cout << "Class_9_2, derived operator=(), with parameter " << rv.c << endl;
    if (this != &rv) {
        Class_9_1::operator=(rv);
        c = rv.c;
    }
    return *this;
}
