#include <fstream>
#include <iostream>

#include "chapter_07.h"

using namespace std;

Text::Text () {
    txt.clear();
}

Text::Text (string fileName) {
    txt.clear();
    fstream textFile;
    textFile.open(fileName.data());
    if (textFile.is_open()) std::getline(textFile, txt, '\0'); else
        cout << "Error open file: " << fileName << endl;
    textFile.close();
}

Message::Message(string init) {
    msg = init;
}

void Message::print() {
    cout << "Class message print function: " << msg << endl;
}

void Message::print(string pr) {
    cout << "Class message print(string) function : " << pr << msg << endl;
}

// Task's 4 changing.

void Class_7_4::f (int a, int b, int c, int d) {
    cout << "Class_7_4, function f with 4 arguments." << endl;
}

/*
void Class_7_4::f1(int a) {}

void Class_7_4::f2(int a, int b) {}

void Class_7_4::f3(int a, int b, int c) {}
*/

void function_7_5(int a, int) {
    cout << "Function_7_5 int a = " << a << endl;
}

Stash7::Stash7(int sz, int initQuantity) : increment(5) {
    if (initQuantity < 0) initQuantity = 0;
    size = sz;
    quantity = next = 0;
    storage = 0;
    inflate(initQuantity);
}

Stash7::~Stash7() {
    if (storage != 0) delete []storage;
}

int Stash7::add(void *element) {
    if (next >= quantity) inflate(increment);
    int startOffset = next * size;
    unsigned char* e = (unsigned char*)element;
    for (int i = 0; i < size; i++) storage[startOffset + i] = e[i];
    next++;
    return (next - 1);
}

void* Stash7::fectch(int index) {
    if (index < 0 && index > next) return 0;
    return &(storage[index * size]);
}

int Stash7::count() {
    return next;
}

void Stash7::inflate(int increase) {
    if (increase <= 0) return;
    unsigned char* b = new unsigned char[(quantity + increase) * size];
    for (int i = 0; i < quantity * size; i++) b[i] = storage[i];
    delete []storage;
    storage = b;
    quantity += increase;
}

Stack7::Stack7() {
    storage.clear();
}

Stack7::Stack7(string value, int size) {
    storage.clear();
    for (int i = 0; i < size; i++) storage.push_back(value);
}

void Stack7::push(string value) {
    storage.push_back(value);
}

string Stack7::pop() {
    if (!storage.empty()) storage.pop_back();
}
