#include "13_Dynamic_Object_Creation.hpp"

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
    vector<int>::iterator itMap = Widget_13::storageMap.begin();
    for (vector<Widget_13*>::iterator it = Widget_13::storage.begin(); it < Widget_13::storage.end(); it++) {
        if (*it == (Widget_13*)p) {
            Widget_13::storage.erase(it);
            Widget_13::storageMap.erase(itMap);
        }
        itMap++;
    }
    ::delete (Widget_13*)p;
}

void Widget_13::operator delete[](void* p) {
    cout << "Widget_13 operator delete[]." << endl;
    vector<int>::iterator itMap = Widget_13::storageMap.begin();
    for (vector<Widget_13*>::iterator it = Widget_13::storage.begin(); it < Widget_13::storage.end(); it++) {
        if (*it == (Widget_13*)(void*)((long)p + sizeof(long))) {
            Widget_13::storage.erase(it,(it + *itMap));
            Widget_13::storageMap.erase(itMap);
        }
        itMap++;
    }
    ::delete (Widget_13*)p;
}

MemoryChecker::MemoryChecker() {}

MemoryChecker::~MemoryChecker() {
    cout << "Widget_13::storage size = " << Widget_13::storage.size() << endl;
}

void chapter_13() {
    cout << "Chapter's 13 tasks.\n";
    // Task 1.
    Counted cl1_1, cl1_2;
    cl1_1.function_1();
    cl1_2.function_1();
    // Task 2.
    Counted* clPtr2_1 = new Counted;
    Counted* clPtr2_2 = new Counted[3];
    delete []clPtr2_2;
    delete clPtr2_1;
    // Task 3. Not good example, count() method doesn't work.
    PStash cl3;
    cl3.add((void*)&cl1_1);
    cl3.add((void*)&cl1_2);
    cl3.remove(1);
    cl3.remove(0);
    // Tasks 4-5.
    vector<Counted*> vec4;
    for (int i = 0; i < 3; i++) vec4.push_back(new Counted);
    cout << "Objects of Counted in vector.\n";
    for (int i = 0; i < 3; i++) {
        cout << (long)vec4[i] << ": ";
        vec4[i]->function_1();
    }
    for (int i = 0; i < 3; i++) delete vec4[i];
    // Task 6.
    PStash cl6;
    cl6.add((void*) new Counted);
    cl6.add((void*) new Counted);
    cout << "Counted objects from PSTash.\n";
    for (int i = 0; i < 2; i++) {
        Counted* ptr = (Counted*)cl6[i];
        ptr->function_1();
    }
    cl6.remove(1);
    cl6.remove(0);
    // Task 7. fix!
    /*
    Stack st7;
    st7.initialize();
    cout << "Task 7 with Stack structure from chapter 4, doubles : ";
    for (int i = 0; i < 3; i++) st7.push(new double(i));
    for (int i = 0; i < 3; i++) cout << *st7.pop() << " ";
    cout << endl;
    */
    // Tasks 8-9.
    Counted* ar8 = new Counted[3];
    // invalid pointer
    // delete ar8;
    delete []ar8;
    Counted* ptr9 = new Counted;
    void* ptr9_1 = (void*)ptr9;
    // deleting 'void*' is undefined
    // delete ptr9_1;
    delete ptr9;
    // Task 10. Bonus.
    // Task 11.
    Class_13_11* cl13_1 = new Class_13_11;
    Class_13_11* cl13_2 = new Class_13_11[3];
    delete cl13_1;
    delete []cl13_2;
    // Task 12. Faster x4. Multiplier was decreased x10.
    time_t time;
    tm local;
    time = std::time(NULL);
    local = *std::localtime(&time);
    int startTimer = local.tm_sec;
    cout << "Starting second : " << startTimer;
    for (int i = 0; i < 10000; i++) for (int j = 0; j < 1000; j++) {
        Framis_13* framis_ptr = ::new Framis_13;
        ::delete framis_ptr;
    }
    time = std::time(NULL);
    local = *std::localtime(&time);
    int finishTimer = local.tm_sec;
    cout << ", after calling standart operators new & delete : " << finishTimer << endl;
    cout << "After calling Framis operators: ";
    for (int i = 0; i < 10000; i++) for (int j = 0; j < 1000; j++) {
        Framis_13* framis_ptr = new Framis_13;
        delete framis_ptr;
    }
    time = std::time(NULL);
    local = *std::localtime(&time);
    finishTimer = local.tm_sec;
    cout << finishTimer << endl;
    // Task 13. Bonus.
    // Task 14.
    char s14_1[8], s14_2[8];
    sprintf(s14_1, "%d", __LINE__);
    sprintf(s14_2, "%d", __LINE__);
    Class_13_14* cl14_1 = new(string(s14_1)) Class_13_14;
    Class_13_14* cl14_2 = new(string(s14_2)) Class_13_14;
    cout << "Class_13_14, storage : ";
    for (int i = 0; i < Class_13_14::storage.size(); i++)
        cout << Class_13_14::storage[i] << " ";
    cout << endl;
    // Task 15.
    MemoryChecker mChecker;
    Widget_13* cl15_1 = new Widget_13;
    Widget_13* cl15_2 = new Widget_13[2];
    cout << "Widget_13 pointers : " << (long)cl15_1 << " " << (long)&cl15_2[0] << " " << (long)&cl15_2[1] << endl;
    cout << "Widget_13, storage : ";
    for (int i = 0; i < 3; i++) cout << (long)Widget_13::storage[i] << " ";
    cout << endl;
    delete []cl15_2;
    delete cl15_1;
}
