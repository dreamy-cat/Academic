#include "08_Constants.hpp"

using namespace std;

void function_8_13(const char c) {
    // c++;
}

void function_8_14(float f) {
    const float& fr = f;
    cout << "Reference to float = " << fr << endl;
}

Class_8_15::Class_8_15(int ii) : i(ii) {

}

void Class_8_15::modify() {
    i++;
}

Class_8_15 function_8_15_1 () {
    return Class_8_15();
}

const Class_8_15 function_8_15_2() {
    return Class_8_15();
}

void function_8_15_3 (Class_8_15& cl) {
    cl.modify();
}

void function_8_16_1 (int*) {}

void function_8_16_2 (const int* cip) {
    // Assigment of read only location '*cip'
    // *cip = 2;
    int i = *cip;
    // Invalid conversation from 'const int*'
    // int* ip2 = cip;
}

const char* function_8_16_3 () {
    return "result of function_8_16_3";
}

const int* const function_8_16_4() {
    static int i = 1;
    return &i;
}

void function_8_17_1 (int&) {}

void function_8_17_2 (const int& cip) {
    // Assigment of read only location '*cip'
    // cip = 2;
    int i = cip;
    i++;
    // Invalid initialization of reference of type 'int&' from expression of type 'const int'
    // int& ip2 = cip;
}

const char& function_8_17_3 () {
    static const char* r = "result of function_8_16_3";
    const char& rp = *r;
    return rp;
}

const int& function_8_17_4() {
    static int i = 1;
    return i;
}

Class_8_18 function_8_18_1 () {
    return Class_8_18();
}

void function_8_18_2 (Class_8_18&) {}

void function_8_18_3 (const Class_8_18&) {}

Class_8_19::Class_8_19(float f1, float f2) : float1(f1), float2(f2) {
    cout << "Class_8_19 floats : " << float1 << " " << float2 << endl;
}

StringStack8::StringStack8() : index(0) {
    memset(stack, 0, size * sizeof(string*));
}

void StringStack8::push(const string *s) {
    if (index < size) stack[index++] = s;
}

const string* StringStack8::pop() {
    if (index > 0) {
        const string* r = stack[--index];
        stack[index] = 0;
        return r;
    }
    return 0;
}

Class_8_21::Class_8_21(int ia) : a(ia) {}

Class_8_22::Class_8_22(int ii) : i(ii) {}

int Class_8_22::function() const {
    // Prototype for 'int Class_8_22::function()' does not match any in class 'Class_8_22'
    return i;
}

Class_8_23::Class_8_23 () {}

void Class_8_23::function_1() {
    cout << "Class_8_23 function 1." << endl;
}

void Class_8_23::function_2() const {
    cout << "Class_8_23 constant function 2." << endl;
}

Class_8_24::Class_8_24 () {}

void Class_8_24::function_1() {
    int a;
    a++;
}

void Class_8_24::function_2() const {
    // Passing 'const Class_8_24' as 'this' argument of 'void Class_8_24::function_1()' discards qualifiers
    // function_1();
}

Class_8_25::Class_8_25 () : i(0), j(0) {}

void Class_8_25::function_1() const {
    // increment of member 'Class_8_25::i' in read-only object
    // i++;
    j++;
}

Quoter8::Quoter8 () {
    lastquote = -1;
    srand(0);
}

int Quoter8::lastQuote() const {
    return lastquote;
}

const char* Quoter8::quote() const {
    static const char* quotes[] = {
        "Is it ... Atomic?",
        "There is no scientific evidence.",
        "Are we having fun yet?"
    };
    const int qsize = sizeof(quotes)/sizeof(*quotes);
    int qnum = rand() % qsize;
    while (lastquote >= 0 && qnum == lastquote) qnum = rand() % qsize;
    return quotes[lastquote = qnum];
}

Class_8_27::Class_8_27 () {}

void Class_8_27::function_1() {
    b++;
}

void Class_8_27::function_2() volatile {
    b++;
}

Class_8_28_1::Class_8_28_1 () {}

void Class_8_28_1::function_1() {
    cout << "Class 28_1 Function_1." << endl;
}

Class_8_28_2::Class_8_28_2 () {}


void chapter_08() {
    cout << "Chapter's 8 tasks.\n";
    // Tasks 1-2. Not possible in this project.
    const int i1 = 1, i2 = 1, i3 = 1;
    const int im1[i1 + i2 + i3] = { 1, 2, 3 };
    // Task 3.
    const char c1 = 'a';
    const int i4 = 0;
    const float f1 = 0;
    const double f2 = 0;
    // Task 4.
    cout << "Task's 4, constant int = " << iTask4 << endl;
    // Task 5. Compiler error, if using any other type, not pointer.
    time_t timer;
    time(&timer);
    const char* ch1 = ctime(&timer);
    cout << "Current date & time : " << ch1;
    // Task 6. Can't change constant string.
    const char string6[] = "Task's 6 string.";
    cout << "Task's 6 string : " << string6 << endl;
    // Task 7.
    extern const int int7;
    cout << "External constant integer : " << Labs_0x01::int7 << endl;
    // Task 8. Increment of read-only location.
    const long lm1[3] = {1, 2, 3};
    const long* lmPtr1 = &lm1[0];
    cout << "Long array, first element = " << *lmPtr1 << ".";
    lmPtr1++;
    cout << " After increasing pointer, second element = " << *lmPtr1 << endl;
    // (*lmPtr1)++;
    // Task 9. Ok, be carefull.
    double dm1[3] = {1.0, 2.0, 3.0};
    double* const dmPtr = &dm1[0];
    cout << "First element of double array : " << *dmPtr << ". ";
    (*dmPtr)++;
    cout << "After increasing : " << *dmPtr << endl;
    // dmPtr++;
    // Task 10. Errors, as expected.
    const int int10 = 0;
    const int* const intPtr1 = &int10;
//    intPtr1++;
//    (*intPtr1)++;
    // Task 11. Compile error. Invalid conversation.
    int d = 1;
    const int e = 2;
    int* u = &d;
    // int* v = &e;
    int* w = (int*)&e;
    // Task 12. No errors. Non constant object can be modified.
    char string12[] = "String 12.";
    char* strPtr = string12;
    strPtr[9] = '!';
    cout << "String 12 = " << string12 << endl;
    // Task 13. Error. Increment of read-only parameter c.
    // Task 14.
    float float14 = 1.0;
    cout << "Function 14. ";
    function_8_14(float14);
    // Task 15.
    function_8_15_1() = Class_8_15(1);
    function_8_15_1().modify();
    // Invalid initialization of non-const reference of type 'Class_8_15&' from an Rvalue of type 'Class_8_15'
    // function_8_15_3(function_8_15_1());
    // Passing 'const Class_8_15' as 'this' argument of 'Class_8_15& Class_8_15::operator=(const Class_8_15&)' discard qualifiers.
    // function_8_15_2() = Class_8_15(1);
    // Passing 'const Class_8_15' as 'this' argument of 'void Class_8_15::modify()' discards qualifiers
    // function_8_15_2().modify();
    // Invalid initialization of non-const reference of type 'Class_8_15&' from an Rvalue of type 'const Class_8_15'
    // function_8_15_3(function_8_15_2());
    // Task 16.
    int x = 0;
    int* ip = &x;
    const int* cip = &x;
    function_8_16_1(ip);
    // Invalid conversation from 'const int*' to 'int*'
    // function_8_16_1(cip);
    function_8_16_2(ip);
    function_8_16_2(cip);
    // Ivalid conversation from 'const cahr*' to 'char*'
    // char* cp = function_8_16_3();
    const char* ccp = function_8_16_3();
    // Invalid conversation from 'const int*' to 'int*'
    // int* ip2 = function_8_16_4();
    const int* const ccip = function_8_16_4();
    const int* cip2 = function_8_16_4();
    // Task 17.
    int xr = 0;
    int& ipr = xr;
    const int& cipr = xr;
    function_8_17_1(ipr);
    // Invalid initialization of reference of type 'int&' from expression 'const int'
    // function_8_17_1(cipr);
    function_8_17_2(ipr);
    function_8_17_2(cipr);
    // Invalid initialization of reference of type 'const cahr&' to 'const char'
    // char& cpr = function_8_17_3();
    const char& ccpr = function_8_17_3();
    // Invalid initialization of reference of type 'int&' from expression 'const int'
    // int& ipr2 = function_8_17_4();
    const int& ccipr = function_8_17_4();
    const int& cip2r = function_8_17_4();
    // Task 18.
    // Invalid initialization of non-const reference of type 'Class_8_18&' from an Rvalue of type 'Class_8_18'
    // function_8_18_2(function_8_18_1());
    function_8_18_3(function_8_18_1());
    // Task 19.
    Class_8_19 class19((float)1.0, (float)2.0);
    // Task 20.
    StringStack8 stack8;
    string iceCream[] = {"pralines & cream", "fudge ripple", "rocky road"};
    for (int i = 0; i < 3; i++) stack8.push(&iceCream[i]);
    const string* ice;
    cout << "Ice cream from stack :\t";
    while ((ice = stack8.pop()) != 0) cout << *ice << "\t";
    cout << endl;
    // Tasks 21-22. Ok in .h & .cpp.
    // Task 23.
    Class_8_23 class23_1;
    const Class_8_23 class23_2;
    class23_1.function_1();
    class23_1.function_2();
    // passing 'const Class_8_23' as 'this' argument of 'void Class_8_23::function_1()' discards qualifiers
    // class23_2.function_1();
    class23_2.function_2();
    // Task 24-25 see in .h & .cpp.
    // Task 26
    Quoter8 class26_1;
    const Quoter8 class26_2;
    class26_1.lastQuote();
    class26_2.lastQuote();
    cout << "Quotes : " << endl;
    for (int i = 0; i < 3; i++) cout << class26_1.quote() << endl;
    // Task 27.
    Class_8_27 class27_1;
    volatile Class_8_27 class27_2;
    class27_1.function_1();
    class27_1.function_2();
    // Passing 'volatile Class_8_27' as this argument of 'void Class_8_27::function_1()' discards qualifiers
    // class27_2.function_1();
    class27_2.function_2();
    // Task 28. No error, may be not correct.
    Class_8_28_1 class28_1, *class28_1Ptr;
    Class_8_28_2 class28_2;
    class28_1.function_1();
    void* classPtr = &class28_2;
    class28_1Ptr = (Class_8_28_1*)classPtr;
    class28_1Ptr->function_1();
}
