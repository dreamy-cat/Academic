#include "05_Hiding_the_Implementation.hpp"

using namespace std;

void Class_5_1::f1() {
    c++;
}

void Class_5_1_2::setString(std::string str, int index) {
    if (index >= 0 && index < 3) s[index] = str;
}

std::string Class_5_1_2::getString(int index) {
    if (index >= 0 && index < 3) return s[index];
}

void function_5_3 (Class_5_3* clPtr) {
    cout << "Private member Class_5_3::int 'a' = " << clPtr->a++ << endl;
}

void Class_5_4_1::f(Class_5_4_2 *ptr) {
    cout << "Class_5_4_1 function." << endl;
}

void Class_5_4_2::f(Class_5_4_1 *ptr) {
    cout << "Class_5_4_2 function." << endl;
}

void Class_5_5_2::printA(Class_5_5_1* ptr) {
    cout << "Class_5_5_2 print 'a' from Class_5_5_1: " << ptr->a << endl;
}

void Class_5_5_3::f(Class_5_5_1* ptr) {
    cout << "Class_5_5_3 print 'a' from Class_5_5_1: " << ptr->a << endl;
}

void Class_5_6_1::display() {
    cout << "Display function of Class_5_6_1. Char from Class_5_6_2 = " << this->cl.a << endl;
}

void Class_5_6_1::print() {
    cout << "Class_5_6_1 char = " << c << endl;
}

void Class_5_6_1::Class_5_6_2::display() {
    cout << "Display function of Class_5_6_1::Class_5_6_2. Char from Class_5_6_3 = " << this->cl.b << endl;
}

void Class_5_6_1::Class_5_6_2::Class_5_6_3::display() {
    cout << "Display function of Class_5_6_1::Class_5_6_2::Class_5_6_3." << endl;
}

void Class_5_8::showMap() {
    cout << "Address of this [Class_5_8] and members: ";
// FIX
    // cout << (long)this << " " << (long)&this->a << " " << (long)&this->b << " " << (long)&this->c << endl;
}

Stack_5::Stack_5(int maxSz) {
    maxSize = maxSz;
    storage = new void*[maxSz];
    sp = 0;
}

void Stack_5::push(void* value) {
    if (sp == maxSize) return;
    storage[sp++] = value;
}

void* Stack_5::pop() {
    if (sp == 0) return NULL;
    return storage[--sp];
}

void Part_05_Hiding_the_Implementation(void) {
    cout << "Chapter's 5 tasks.\n";
    // Task 1. Only public members compiles.
    Class_5_1 class1;
    class1.a = 0;
    class1.f1();
    /*
    class1.b = 0;
    class1.f2();
    class1.c = 0;
    class1.f3();
    */
    // Task 2.
    Structure_5_1 x;
    x.a = "Structure_5_1.a";
    x.b = "Structure_5_1.b";
    x.c = "Structure_5_1.c";
    x.s[0] = x.a;
    x.s[1] = x.b;
    x.s[2] = x.c;
    Class_5_1_2 class2;
    class2.setString("String 1",0);
    class2.setString("String 2",1);
    class2.setString("String 3",2);
    cout << "Strings from Class_5_1_2: ";
    for (int i = 0; i < 3; i++) cout << class2.getString(i) << " ";
    cout << endl;
    // Task 3.
    Class_5_3 class3;
    function_5_3(&class3);
    // Task 4.
    Class_5_4_1 class41;
    Class_5_4_2 class42;
    class41.f(&class42);
    class42.f(&class41);
    // Task 5.
    Class_5_5_1 class51;
    Class_5_5_2 class52;
    Class_5_5_3 class53;
    class52.printA(&class51);
    class53.f(&class51);
    // Task 6-7.
    Class_5_6_1 class61;
    Class_5_6_1::Class_5_6_2 class62;
    Class_5_6_1::Class_5_6_2::Class_5_6_3 class63;
    class61.display();
    class62.display();
    class63.display();
    // Task 8.
    Class_5_8 class5;
    class5.showMap();
    // Task 9. See chapter 4.
    // Task 10.
    cout << "Store 4 objects of Class_5_6_1 in Stash.\n";
    /*
    Stash stash;
    stash.initialize(sizeof(Class_5_6_1));
    for (int i = 0; i < 4; i++) {
        Class_5_6_1* clPtr = new Class_5_6_1;
        clPtr->c = '0'+i;
        stash.add(clPtr);
    }
    cout << "Fetch 4 objects of Class_5_6_1 from Stash.\n";
    for (int i = 0; i < 4; i++) {
        Class_5_6_1* clPtr = (Class_5_6_1*)stash.fetch(i);
        clPtr->print();
    }
    */
    // Task 11. See chapter 4.
    // Task 12.
    cout << "Push 4 objects of Class_5_6_1 in Stack_5.\n";
    Stack_5 stack(5);
    for (int i = 0; i < 4; i++) {
        Class_5_6_1* clPtr = new Class_5_6_1;
        clPtr->c = '0'+i;
        stack.push((void*)clPtr);
    }
    cout << "Pop 4 objects of Class_5_6_1 from Stack_5.\n";
    for (int i = 0; i < 4; i++) {
        Class_5_6_1* clPtr = (Class_5_6_1*)stack.pop();
        clPtr->print();
    }
    // Task 13-14. Not compile, if changes in _05_1.cpp.
    StackOfInt st;
    st.stack1 = new StackImp_1(3);
    st.stack2 = new StackImp_2(3);
    cout << "Push 3 values to StackImp_1 & StackImp_2 objects.\n";
    for (int i = 0; i < 3; i++) {
        st.stack1->push(i);
        st.stack2->push(i);
    }
    cout << "Pop 3 values from StackImp_1 & StackImp_2 objects : ";
    for (int i = 0; i < 3; i++) cout << st.stack1->pop() << " " << st.stack2->pop() << " ";
    cout << endl;
}
