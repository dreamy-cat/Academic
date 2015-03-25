#include "chapter_13.h"

using namespace std;

int Counted::count = 0;

Counted::Counted() : id(count++) {
    cout << "Class Counted constructor. Id = " << id << endl;
}

Counted::~Counted() {
    cout << "Class Counted destructor. Id = " << id << endl;
}

void Counted::function_1() {
    cout << "Class Counted, function_1." << endl;
}

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

void*  Class_13_11::operator new(size_t sz) {
    cout << "Class_13_11 operator new." << endl;
    return ::new char[sz];
}

void Class_13_11::operator delete(void *p) {
    cout << "Class_13_11 operator delete." << endl;
    ::delete [](Class_13_11*)p;
}

void* Class_13_11::operator new[](size_t sz) {
    cout << "Class_13_11 operator new[]." << endl;
    return new char[sz];
}

void Class_13_11::operator delete[](void* p) {
    cout << "Class_13_11 operator delete[]." << endl;
    ::delete [](Class_13_11*)p;
}


unsigned char Framis_13::pool[Framis_13::maxSize * sizeof(Framis_13)];
bool Framis_13::alloc_map[Framis_13::maxSize] = { false };

Framis_13::Framis_13() {
    // cout << "Framis_13 constructor." << endl;
}

Framis_13::~Framis_13() {
    // cout << "Framis_13 destructor." << endl;
}

void* Framis_13::operator new(size_t) {
    for (int i = 0; i < maxSize; i++)
        if (!alloc_map[i]) {
            // cout << "Using block " << i << ".\n";
            alloc_map[i] = true;
            return pool + (i * sizeof(Framis_13));
        }
    cout << "Out of memory.\n";
}

void Framis_13::operator delete(void* m) {
    if (!m) return;
    unsigned long block = (unsigned long)m - (unsigned long)pool;
    block /= sizeof(Framis_13);
    // cout << "Freeing block " << block << endl;
    alloc_map[block] = false;
}

vector<string> Class_13_14::storage;

void* Class_13_14::operator new(size_t sz, std::string str) {
    storage.push_back(str);
    ::new char[sz];
}

void Class_13_14::operator delete(void* p) {
    storage.pop_back();
    ::delete (Class_13_14*)p;
}

Widget_13::Widget_13() {
    cout << "Widget_13 constructor." << endl;
}

Widget_13::~Widget_13() {
    cout << "Widget_13 destructor." << endl;
}

vector<Widget_13*> Widget_13::storage;
vector<int> Widget_13::storageMap;

void* Widget_13::operator new(size_t sz) {
    cout << "Widget_13 operator new, size = " << sz << endl;
    void* ptr = ::new char[sz];
    Widget_13::storage.push_back((Widget_13*)ptr);
    Widget_13::storageMap.push_back(1);
    return ptr;
}

void* Widget_13::operator new[](size_t sz) {
    cout << "Widget_13 opearator new[], size = " << sz << endl;
    void* ptr = ::new char[sz];
    // Add 8 bytes for array, may be as sizeof(long). Not a good trick, but it's work.
    Widget_13* ptrW = (Widget_13*)((void*)((long)ptr+sizeof(long)));
    for (int i = 0; i < sz / sizeof(Widget_13); i++)
        Widget_13::storage.push_back(&ptrW[i]);
    Widget_13::storageMap.push_back((sz - sizeof(long))/sizeof(Widget_13));
    return ptr;
}

void Widget_13::operator delete(void* p) {
    cout << "Widget_13 operator delete." << endl;
    for (vector<Widget_13*>::iterator it = Widget_13::storage.begin(); it < Widget_13::storage.end(); it++)
        if (*it == (Widget_13*)p) Widget_13::storage.erase(it);
    ::delete (Widget_13*)p;
}

void Widget_13::operator delete[](void* p) {
    cout << "Widget_13 operator delete[]." << endl;
    int index = 0;
    for (vector<Widget_13*>::iterator it = Widget_13::storage.begin(); it < Widget_13::storage.end(); it++) {
        if (*it == (Widget_13*)p) Widget_13::storage.erase(it,(it + Widget_13::storageMap[index]));
        index++;
    }
    // Widget_13::storage.clear();
    ::delete (Widget_13*)p;
}

MemoryChecker::MemoryChecker() {}

MemoryChecker::~MemoryChecker() {
    cout << "Widget_13::storage size = " << Widget_13::storage.size() << endl;
}
