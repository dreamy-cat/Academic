#include "chapter_01.h"

using namespace std;

int function_01_1() {
    return 1;
}

void function_01_2() {
    errno = 1;
}

void function_01_3(int sig) {
    cout << "Function 03, signal recieved.\n";
}

void function_01_4() {
    throw 1;
}

void Class_01_1::function_1() throw(Class_1) {
    cout << "Class_01_1. Throw exception.\n";
    throw(Class_1("Exception in function_1."));
}

PStash_1::PStash_1() : quantity(0), next(0), storage(0) { }

PStash_1::~PStash_1() {
    for (int i = 0; i < next; i++)
        if (storage[i] != 0) cout << "Storage[" << i << "] not empty.\n";
    delete []storage;
}

int PStash_1::add(void *element) {
    const int inflateSize = 5;
    if (next >= quantity) inflate(inflateSize);
    storage[next++] = element;
    return(next-1);
}

void* PStash_1::operator[](int index) const {
    if (index >= next || index < 0) throw(out_of_range("Out of range in storage."));
    if (storage[index] == 0) throw(invalid_argument("Index argument not exist."));
    return storage[index];
}

void* PStash_1::remove(int index) {
    void *v = operator [](index);
    storage[index] = 0;
    return v;
}

void PStash_1::inflate(int increase) {
    const int psz = sizeof(void*);
    void** st = new void*[quantity+increase];
    memset(st, 0, (quantity+increase)*psz);
    memcpy(st, storage, quantity*psz);
    quantity += increase;
    delete []storage;
    storage = st;
}

int PStash_1::count() const { return next; }

int Class_1_5::counter = 0;

Class_1_5::Class_1_5() {}

void* Class_1_5::operator new(size_t) {
    cout << "Class_1_5::operator new().\n";
    if (counter+1 == limit) throw bad_alloc();
    counter++;
    return ::new Class_1_5;
}

void Class_1_5::operator delete(void *p) {
    cout << "Class_1_5::operator delete().\n";
    ::delete((Class_1_5*)p);
}
