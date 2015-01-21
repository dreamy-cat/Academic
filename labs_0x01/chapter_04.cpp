#include <iostream>
#include <string>

#include "chapter_04.h"

using namespace std;

void structure_4_1::function_1(structure_4_1 *strucPtr, int m) {
    strucPtr->n = m;
}

void structure_4_1::function_2(structure_4_1 *strucPtr) {
    cout << "Structure_4_2::Function_1 has called. N = " << strucPtr->n << endl;
}

// Task 6.

class_4_1::class_4_1() {
    s = "chapter_04";
    cout << "String from class_4_1 = " << this->s << endl;
}

// Task 7.

void Stash::initialize(int sz) {
    size = sz;
    quantity = 0;
    storage.clear();
    next = 0;
}

int Stash::add(const void *element) {
    if (next >= quantity) inflate (increment);
    int startOffs = next * size;
    unsigned char* e = (unsigned char*)element;
    for (int i = 0; i < size; i++) storage[startOffs+i] = e[i];
    next++;
}

void Stash::inflate(int increase) {
    //unsigned char* newStorage = new unsigned char[(quantity+increase)*size];
    storage.resize(quantity+increase*size);
/*
    for (int i = 0; i < quantity*size; i++) newStorage[i] = storage[i];
    delete []storage;
    storage = newStorage;
    */
    quantity += increase;
}

int Stash::count() {
    return next;
}

void* Stash::fetch(int index) {
    if (index >= next) return 0;
    //return (storage + index*size);
    return (void*)&storage[index*size];
}

void Stash::cleanup() {
//    if (storage != 0) {
    if (!storage.empty()) {
        cout << "Freeing memory.\n";
//        delete []storage;
        storage.clear();
    }
}

// Task 8.

void Stack::initialize() {
    head = 0;
}

void Stack::push(double *data) {
    Link* newLink = new Link;
    newLink->value = data;
    newLink->next = head;
    head = newLink;
}

double* Stack::pop() {
    if (head == 0) return 0;
    double* rVal = head->value;
    Link* oldHead = head;
    head = head->next;
    delete oldHead;
    return rVal;
}

// Task 13.

Class_4_13::Class_4_13(string newTitle) {
    title = newTitle;
    period = 0;
}

Class_4_13::~Class_4_13() {

}

void Class_4_13::give(string cust) {
    if (period != 0) return;
    period = 7;
    customer = cust;
}

void Class_4_13::get(string cust) {
    if (period == 0) return;
    customer.clear();
    period = 0;
}

void Class_4_13::print() {
    cout << "Title = " << title;
}

// Task 14.

Stack2::Stack2(int maxSize) : maxSz(maxSize) {
    mem = new Class_4_13*[maxSz];
    stackPointer = 0;
}

Stack2::~Stack2() {
    if (stackPointer > 0) {

    }
}

void Stack2::push(Class_4_13 &clPtr) {
    if (stackPointer >= maxSz) return;
    mem[stackPointer] = new Class_4_13(clPtr.title);
    *mem[stackPointer++] = clPtr;
}

Class_4_13 Stack2::pop() {
    if (stackPointer > 0)
        return *mem[--stackPointer];
}

// Task 18.

char* function_4_1 (const char *original) {
    int size = 0;
    while (*(original+size++) != '\0');
    char* copy = new char(size);
    for (int i = 0; i <= size; i++) copy[i] = original[i];
    return copy;
}

// Task 19.

void structure_4_2::printN() {
    cout << "Structure_4_2 N = " << n1 << endl;
}

void structure_4_2::structure_4_2_1::printN() {
    cout << "Structure_4_2_1 N = " << n2 << endl;
}

//Task 22.

void Stack3::init(int size) {
    maxSz = size;
    stackPointer = 0;
    mem = new Stash3*[maxSz];
}

void Stack3::push(Stash3 element) {
    if (stackPointer >= maxSz) return;
    Stash3* newStash = new Stash3;
    *newStash = element;
    mem[stackPointer++] = newStash;
}

Stash3 Stack3::pop() {
    if (stackPointer == 0) return Stash3();
    Stash3 val = *mem[--stackPointer];
    delete mem[stackPointer];
    return val;
}

void structure_4_6::wrapinit(int size) {
    stack.init(size);
}

void structure_4_6::wrapPush(Stash3 &element) {
    stack.push(element);
}

Stash3 structure_4_6::wrapPop() {
    return (stack.pop());
}

