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
