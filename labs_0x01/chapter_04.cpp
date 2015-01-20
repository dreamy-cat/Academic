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
    storage = 0;
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
    unsigned char* newStorage = new unsigned char[(quantity+increase)*size];
    for (int i = 0; i < quantity*size; i++) newStorage[i] = storage[i];
    delete []storage;
    storage = newStorage;
    quantity += increase;
}

int Stash::count() {
    return next;
}

void* Stash::fetch(int index) {
    if (index >= next) return 0;
    return (storage + index*size);
}

void Stash::cleanup() {
    if (storage != 0) {
        cout << "Freeing memory.\n";
        delete []storage;
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
