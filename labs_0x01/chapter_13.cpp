#include "chapter_13.h"

using namespace std;

int Counted::count = 0;

Counted::Counted() : id(count++) {
    cout << "Class Counted constructor. Id = " << id << endl;
}

Counted::~Counted() {
    cout << "Class Counted destructor. Id = " << id << endl;
}

void Counted::function_1() {}

PStash::PStash() : quantity(0), next(0), storage(0) {}

PStash::~PStash()
{
    for (int i = 0; i < next; i++)
        if (storage[i] != 0) cout << "PStash not cleaned up." << endl;
    delete []storage;
}

int PStash::add(void* element) {
    const int inflateSize = 10;
    if (next >= quantity) inflate(inflateSize);
    storage[next++] = element;
    return (next - 1);
}

void* PStash::operator[](int index) const {
    if (index >= next || index < 0) {
        cout << "PStash, operator[], index out of range." << endl;
        return 0;
    }
    return storage[index];
}

void* PStash::remove(int index) {
    void* element = operator [](index);
    if (element == 0) {
        cout << "PStash, remove(index), index out of range" << endl;
        return 0;
    }
    storage[index] = 0;
    return element;
}

int PStash::count() const { return next; }

void PStash::inflate(int increase) {
    void** st = new void*[quantity + increase];
    memset(st, 0, (quantity + increase) * sizeof(void*));
    memcpy(st, storage, quantity * sizeof(void*));
    quantity += increase;
    delete []storage;
    storage = st;
}
