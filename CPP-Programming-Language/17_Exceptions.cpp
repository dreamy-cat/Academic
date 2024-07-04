#include "17_Exceptions.hpp"

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
/*
void Class_01_1::function_1() throw(Class_1) {
    cout << "Class_01_1. Throw exception.\n";
    throw(Class_1("Exception in function_1."));
}
*/

PStash_A::PStash_A() : quantity(0), next(0), storage(0) { }

PStash_A::~PStash_A() {
    for (int i = 0; i < next; i++)
        if (storage[i] != 0) cout << "Storage[" << i << "] not empty.\n";
    delete []storage;
}

int PStash_A::add(void *element) {
    const int inflateSize = 5;
    if (next >= quantity) inflate(inflateSize);
    storage[next++] = element;
    return(next-1);
}

void* PStash_A::operator[](int index) const {
    if (index >= next || index < 0) throw(out_of_range("Out of range in storage."));
    if (storage[index] == 0) throw(invalid_argument("Index argument not exist."));
    return storage[index];
}

void* PStash_A::remove(int index) {
    void *v = operator [](index);
    storage[index] = 0;
    return v;
}

void PStash_A::inflate(int increase) {
    const int psz = sizeof(void*);
    void** st = new void*[quantity+increase];
    memset(st, 0, (quantity+increase)*psz);
    memcpy(st, storage, quantity*psz);
    quantity += increase;
    delete []storage;
    storage = st;
}

int PStash_A::count() const { return next; }

int Class_1_5::counter = 0;

Class_1_5::Class_1_5() {}

void* Class_1_5::operator new(size_t) {
    cout << "Class_1_5::operator new.\n";
    if (counter+1 > limit) throw bad_alloc();
    counter++;
    return ::new Class_1_5;
}

void Class_1_5::operator delete(void *p) {
    cout << "Class_1_5::operator delete.\n";
    counter--;
    ::delete((Class_1_5*)p);
}

Class_1_6::Class_1_6() { cout << "Class_1_6 constructor.\n"; }

Class_1_6::~Class_1_6() {
    cout << "Class_1_6 destructor.\n";
    // throw 2;
}

void Class_1_6::function_1() {
    cout << "Class_1_6::function_1. Throwing exception.\n";
    throw 2;
}
/*
void function_01_9(int index) throw(char, int, bool, Class_1_9) {
    switch (index) {
    case 0:
        throw 'a';
        break;
    case 1:
        throw 1;
        break;
    case 2:
        throw true;
        break;
    case 3:
        throw Class_1_9();
        break;
    default:
        throw double(5.0);
    }
}
*/

void unexpectedHandler() {
    cout << "Handler unexpected exception.\n";
    exit(0);
}

Garage::Garage() {
    try {
        car_1 = new Car;
    } catch(char c) {
        cout << "Garage catch exception parameter = " << c << endl;
        throw 1;
    }
}

Garage::Car::Motor::Motor() {
    cout << "Class Motor constructor.\n";
    throw 'a';
}


void chapter_17()
{
    cout << "Chapter's 1. Tasks.\n";
    // Task 1.
    cout << "Function 01 returns " << function_01_1() << ".\n";
    function_01_2();
    std::cout << "Function 02, errno = " << errno << ".\n";
    signal(SIGINT, function_01_3);
    raise(SIGINT);
    try {
        function_01_4();
    } catch (int) {
        cout << "Catch exception from function 04.\n";
    }
    // Task 2.
    Class_01_1 class_1;
    try {
        // fix!
        // class_1.function_1();
    } catch (Class_01_1::Class_1 cl) {
        cout << "Catch exception from function_1, Class_01_1. String = " << cl.str << "\n";
    }
    // Task 3-4.
    PStash_A stash;
    const char string_1[] = "ABC";
    try {
        cout << "All objects in stash: ";
        for (int i = 0; i < 3; i++) {
            stash.add((void*)&string_1[i]);
            cout << *((char*)stash[i]) << " ";
        }
        cout << endl;
        for (int i = 0; i < 3; i++) stash.remove(i);
        cout << *((char*)stash[5]) << " ";
    } catch(out_of_range m) {
        cout << "Exception from PStash_1: " << m.what() << endl;
    } catch(invalid_argument m) {
        cout << "Exception from PStash_1: " << m.what() << endl;
    }
    // Task 5.
    Class_1_5* ptrs_1[] = { NULL, NULL, NULL, NULL, NULL };
    int i, j = 0;
    for (i = 0; i < 3; i++) ptrs_1[i] = new Class_1_5;
    for ( ; i < 5; ) {
        try {
            ptrs_1[i] = new Class_1_5;
            i++;
        } catch (bad_alloc e) {
            cout << "Exception from Class_1_5::operator new: " << e.what() << ", trying to free some space." << endl;
            delete (ptrs_1[j++]);
        }
    }
    // Task 6-8. Terminate called after throwing an instance of 'int'.
    Class_1_6* class_2 = new Class_1_6, class_3;
    try {
        class_3.function_1();       // Auto object.
        class_2->function_1();      // Heap object.
        // delete class_2;
    } catch (int n) {
        cout << "Exception from Class_1_6:: " << n << endl;
    }
    // Task 11. First, because of terminate.
    try {
        Garage class_3;
    } catch (int i) {
        cout << "Exception in Garage constructor, int = " << i << endl;
    }
    // Task 9-10. May be not as planning.
    set_unexpected(unexpectedHandler);
    for (int i = 0; i < 5; i++) {
        try {
            // function_01_9(i);
            cout << "fix.\n";
        } catch (char c) {
            cout << "Catch exception with char = " << c << endl;
        } catch (int i) {
            cout << "Catch exception with int = " << i << endl;
        } catch (bool b) {
            cout << "Catch exception with bool = " << b << endl;
        } catch (Class_1_9 cl) {
            cout << "Catch exception with Class_1_9, what(): " << cl.what() << endl;
        }
    }
}
