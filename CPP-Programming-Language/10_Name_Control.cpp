#include "10_Name_Control.hpp"

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

Labs_0x01::Class_10_11::Class_10_11 (int ii) : i(ii) {}

void Labs_0x01::Class_10_11::print () {
    cout << "Class_10_11 int i = " << i << endl;
}

// underfined ref

/*
namespace Labs_0x01 {

Class_10_11 cl10_1(3);

}
*/

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

Class_10_28::Class_10_28(const int *aPtr) : ar2(aPtr) {
    for (int i = 0; i < 3; i++) ar1[i] = i;
}

void Class_10_28::function_1() {
    // Invalid use of member 'Class_10_28::ar1' in static member function.
    // Invalid use of member 'Class_10_28::ar2' in static member function.
    // for (int i = 0; i < 3; i++) cout << ar1[i] << " " << ar2[i] << " ";
}

Class_10_29_1::Class_10_29_1(std::string init) : str(init) {}

void Class_10_29_1::print() const {
    cout << "Class_10_29_1, string = " << str;
}

Class_10_29_2::Class_10_29_2() {}

Class_10_29_1 Class_10_29_2::ar1[3] = {Class_10_29_1("first"), Class_10_29_1("second"), Class_10_29_1("third") };

const Class_10_29_1 Class_10_29_2::ar2[] = {Class_10_29_1("fourth"), Class_10_29_1("fifth"), Class_10_29_1("sixth") };

void Class_10_29_2::printArray() {
    cout << "Static array of class Class_10_29_1 : ";
    for (int i = 0; i < 3; i++) {
        ar1[i].print();
        cout << " ";
    }
    cout << "\nStatic const array of class Class_10_29_1 : ";
    for (int i = 0; i < 3; i++) {
        ar2[i].print();
        cout << " ";
    }
}

Class_10_31 Class_10_31::inst(7);

void chapter_10() {
    cout << "Chapter's 10 tasks.\n";
    // Task 1.
    int arrayInt[5] = { 1, 2, 3, 4, -1 };
    function_10_1(arrayInt);
    cout << "Integer array with static address : ";
    for (int i = 0; i < 5; i++) cout << function_10_1() << " ";
    cout << endl;
    // Task 2. Classic.
    cout << "Fibonacci sequence : ";
    for (int i = 0; i < 12; i++) cout << numberFibbonaci() << " ";
    cout << endl << "After reset sequence : ";
    numberFibbonaci(true);
    for (int i = 0; i < 12; i++) cout << numberFibbonaci() << " ";
    cout << endl;
    // Task 3.
    Class_10_3 class3(5);
    class3.print();
    // Task 4-6.
    cout << "Counter of static Class_10_4.\n";
    for (int i = 0; i < 3; i++) function_10_4();
    Class_10_4 class4;
    function_10_5(&class4);
    Class_10_5* class5 = new Class_10_5(&class4);
    delete class5;
    // Task 7. Same as previous.
    // Task 8. Correct, static objects was created in order by name of functions in _10.cpp file.
    cout << "Task 8. Class_10_8.\n";
    Class_10_8 cl8('a');
    function_10_8_1();
    function_10_8_2();
    // Task 9. Udefined refecrence, as expected. May be not correct.
    //extern ofstream stream9;
    //stream9 << "Tasks9, test.\n";
    // Task 10. Worked, but it's not convinient in current project.
    // Task 11-12. See chapter_10.cpp. Rethink task.
    // fix and recheck, namespace.
    // extern Labs_0x01::Class_10_11 cl10_1;
    // cl10_1.print();
    // Task 13.
    function_10_13();
    // Task 14.
    volatile Class_10_14 cl14;
    cl14.isr();
    // Passing 'volatile Class_10_14' as 'this' argument of 'char Class_10_14::read(int) const' discards qualifiers
    // cl14.read(0);
    // Task 15.
    int i15_1 = 0;
    register int i15_2 = 1;
    cout << "Auto and register integers : " << i15_1 << " " << i15_2 << endl;
    // Task 16.
    namespace nm16 = NameSpace_16_2;
    using namespace nm16;
    nm16::function_16_1();
    nm16::function_16_2();
    function_16_3();
    function_16_4();
    // Task 17-18.
    function_10_17();
    function_10_18();
    // Task 19.
    NameSpace_10_19::Class_10_19 cl19;
    function_10_19();
    // Task 20. May not correct...
    arithmetic();
    // Task 21.
/*
    using namespace NameSpace_10_20_2;
    Integer a(3);
    a.setSign(positive);
    cout << "NameSpace_10_20_2, get sign from Integer without operator '::' : " << a.getSign() << endl;
    NameSpace_10_20_2::a.setSign(negative);

    cout << "NameSpace_10_20_2, get sign from Integer with operator '::' : " << NameSpace_10_20_2::a.getSign() << endl;
*/
    // Task 22-23. If in global, no difference.
    using namespace NameSpace_10_22_1;
    // using namespace NameSpace_10_22_2;
    // Reference to 'Class_10_22' is ambiguous.
    Class_10_22 class22_1;
    NameSpace_10_22_2::Class_10_22 class22_2;
    // Task 24. Ok, but not as expected.
    using namespace NameSpace_10_24_3;
    Class_10_24_1 cl24_1;
    Class_10_24_2 cl24_2;
    Class_10_24_6 cl24_6;
    // Task 25.
    Class_10_25 cl25("Test string 25.");
    cl25.print();
    // Task 26.
    Class_10_26 cl26;
    cl26.print();
    // Task 27.
    Class_10_27_2 cl27;
    cl27.function_1();
    // Task 28. Too short.
    // Task 29. Constructor using string.
    Class_10_29_2 cl29;
    cl29.printArray();
    // Task 30.
    struct Structure_30 {
        Structure_30() : i(0) {}
        int i;
    };
    Structure_30 struc30[3];
    cout << "Array of Structure_30 : ";
    for (int i = 0; i < 3; i++) cout << struc30[i].i << " ";
    cout << endl;
    // Task 31.
    Class_10_31* ptr31 = Class_10_31::instance();
    cout << "Value from Class_10_31, singletone : " << ptr31->value() << endl;
    // Task 32-35. Rethink
    Mirror_32 cl32_1;
    Mirror_32 cl32_2(&cl32_1);
    cout << "Address of calling cl32_2 : " << (long)cl32_2.test() << endl;
}
