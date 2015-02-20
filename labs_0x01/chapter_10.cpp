#include "chapter_10.h"

using namespace std;

int Class_10_3::var2 = 0;

int function_10_1(int init[]) {
    static int* elemAddr = 0;
    if (init != 0) {
        elemAddr = init;
        return 0;
    }
    if (*elemAddr != -1) return (*(elemAddr++));
    return 0;
}

int numberFibbonaci(bool reset) {
    static int fn1 = 0;
    static int fn2 = 1;
    if (reset) { fn1 = 0; fn2 = 1; return 0; }
    int number = fn1 + fn2;
    fn1 = fn2;
    fn2 = number;
    return number;
}

int Class_10_4::counter = 0;

Class_10_4::Class_10_4 () {}

void Class_10_4::print () {
    cout << "Counter = " << counter << endl;
}

void Class_10_4::count () {
    counter++;
}

void Class_10_4::decrement() {
    counter--;
}

void function_10_4() {
    static Class_10_4 stat;
    stat.count();
    stat.print();
}

Class_10_5::Class_10_5 (Class_10_4* ptr) {
    cout << "Class_10_5 constructor.\n";
    clPtr = ptr;
    clPtr->count();
    clPtr->print();
}

Class_10_5::~Class_10_5() {
    cout << "Class_10_5 destructor.\n";
    clPtr->decrement();
    clPtr->print();
}

void function_10_5 (Class_10_4* ptr) {
    cout << "In function_10_5.\n";
    static Class_10_5 cl(ptr);
}

Class_10_8::Class_10_8(char cc) : c(cc) {
    cout << "Constructor of Class_10_8, init char = " << c << endl;
}

Class_10_8::~Class_10_8() {
    cout << "Destructor of Class_10_8, char = " << c << endl;
}

void function_10_8_1() {
    static Class_10_8 cl8_1('c');
}

void function_10_8_2() {
    static Class_10_8 cl8_2('b');
}

Class_10_11::Class_10_11 (int ii) : i(ii) {}

void Class_10_11::print () {
    cout << "Class_10_11 int i = " << i << endl;
}

Class_10_11 cl10_1(3);

// Undefined reference
// static Class_10_11 cl10_1(3);

void function_10_13 () {
    cout << "In function_10_13." << endl;
}

int Class_10_14::index = 0;

const unsigned char Class_10_14::byte = 0;

unsigned char Class_10_14::flag = 0;

unsigned char Class_10_14::buf[Class_10_14::bufsize];

Class_10_14::Class_10_14 () {}

void Class_10_14::isr() {
    cout << "Class_10_14 isr method." << endl;
    flag = 0;
    buf[index++] = byte;
    if (index >= bufsize) index = 0;
}

char Class_10_14::read (int index) const {
    if (index < 0 || index >= bufsize) return '0';
    return buf[index];
}

void NameSpace_16_1::function_16_1() {}

void NameSpace_16_1::function_16_2() {
    NameSpace_16_1::function_16_1();
}

void NameSpace_16_2::function_16_3() {
    using namespace NameSpace_16_1;
    function_16_1();
}

void NameSpace_16_2::function_16_4() {}

void function_10_18() {
   function_10_17();
}

void function_10_19() {
    cout << "Friend function for NameSpace_10_19." << endl;
}

// Otherwise need to create separate .h

void arithmetic () {
    using namespace NameSpace_10_20_1;
    Integer int1(1), int2(2);
    cout << "Sign of Integers of NameSpace_10_20_1: " << int1.getSign() << " " << int2.getSign() << endl;
}

double Class_10_26::doubleP = 1;
long Class_10_26::longP = 3;

Class_10_26::Class_10_26() {}

void Class_10_26::print() { cout << "Class_10_26. Double and long parameters : " << doubleP << " " << longP << endl; }

Class_10_27_1 Class_10_27_2::cl(3);

Class_10_27_2::Class_10_27_2() {}

void Class_10_27_2::function_1() {
    cout << "Class_10_27_2 static function_1 : ";
    cl.print();
    cout << endl;
}
