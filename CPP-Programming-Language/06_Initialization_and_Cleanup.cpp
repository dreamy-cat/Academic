#include "06_Initialization_and_Cleanup.hpp"

using namespace std;

Simple::Simple(int i) : a(i) {
    cout << "Class Simple constructor has called. Int a = " <<  a << endl;
}

Simple::~Simple() {
    cout << "Class Simple destructor has called. Int a = " << a << endl;
}

void Simple::printA() {
    cout << a << " ";
}

Class_6_6::Class_6_6() {
    simplePtr = new Simple(0);
}

Class_6_6::~Class_6_6() {
    delete simplePtr;
}

int Class_6_6::read() {
    return simplePtr->b;
}

void Class_6_6::change(int value) {
    simplePtr->b = value;
}

Stack6::Stack6() {
    storage.clear();
}

void Stack6::push(string &val){
    storage.push_back(val);
}

string Stack6::pop() {
    if (!storage.empty()) {
        string val = storage.back();
        storage.pop_back();
        return val;
    }
}

Class_6_10::Class_6_10(int a) {

}

void Class_6_10::function() {
    cout << "Simple function of Class_6_10." << endl;
}

void chapter_06() {
    cout << "Chapter's 6 tasks.\n";
    // Tasks 1-4.
    Simple class1(0), class2(1);
    for (int i = 0; i < 2; i++) {
        Simple class3(2);
        goto jump;
    }
jump: ;
    // Task 5. May be in old standard, but works fine now.
    int i = 0;
    cout << "Counters in 'for' i,j : ";
    for (; i < 3; i++) for (int i = 0; i < 3; i++) cout << i << " " << i << " ";
    cout << endl;
    // Task 6.
    Class_6_6 class66;
    cout << "Class_6_6 int = " << class66.read();
    class66.change(1);
    cout << " after change int = " << class66.read() << endl;
    // Task 7.
    double dm[3] = { 1.0, 2.0 };
    cout << "Vector of double : ";
    for (int i = 0; i < sizeof(dm)/sizeof(double); i++) cout << dm[i] << " ";
    double dm2[] = { 1.0, 2.0, 3.0 };
    cout << endl << "Second vector of double : ";
    for (int i = 0; i < sizeof(dm2)/sizeof(double); i++) cout << dm2[i] << " ";
    cout << endl;
    // Task 8.
    string sm[3] = { "one", "two", "three" };
    Stack6 class68;
    cout << "Push strings to stack : ";
    for (int i = 0; i < 3; i++) {
        cout << sm[i] << " ";
        class68.push(sm[i]);
    }
    cout << "\nPop strings from stack : ";
    for (int i = 0; i < 3; i++) cout << class68.pop() << " ";
    cout << endl;
    // Task 9.
    Simple class9[] = { Simple(1), Simple(2), Simple(3) };
    cout << "Class Simple vector, print a : ";
    for (int i = 0; i < sizeof(class9)/sizeof(Simple); i++) class9[i].printA();
    cout << endl;
    // Task 10. Just for constructor test.
    Class_6_10 class10(0);
    class10.function();
    cout << endl;
}
