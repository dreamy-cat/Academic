#include "chapter_06.hpp"

using namespace std;

int Class_6_4::counter = 0;

Class_6_1A::~Class_6_1A() { cout << "Class_6_1A, destructor.\n"; }

void* Class_6_1A::operator new(size_t count) {
    cout << "Class_6_1A, operator new.\n";
    return ::operator new(count);
}

void* Class_6_1A::operator new[](size_t count) {
    cout << "Class_6_1A, operator new[].\n";
    return ::operator new[](count);
}

void Class_6_1A::operator delete( void* ptr, size_t ) throw() {
    cout << "Class_6_1A, operator delete.\n";
    ::operator delete(ptr);
}

void Class_6_1A::operator delete[](void* ptr, size_t ) throw() {
    cout << "Class_6_1A, operator delete[].\n";
    ::operator delete[](ptr);
}

void Class_6_1A::function(void* ptr, size_t s) { cout << "Class_6_1A, function(void*, size_t).\n"; }

Class_6_1B::~Class_6_1B() { cout << "Class_6_1B, destructor.\n"; }

void* Class_6_1B::operator new(size_t count) {
    cout << "Class_6_1B, operator new.\n";
    return ::operator new(sizeof(Class_6_1B));
}

void* Class_6_1B::operator new[](size_t count) {
    cout << "Class_6_1B, operator new.\n";
    ::operator new[](count);
}

void Class_6_1B::operator delete(void* ptr) throw() {
    cout << "Class_6_1B, operator delete.\n";
    ::operator delete(ptr);
}

void Class_6_1B::operator delete[](void* ptr) throw() {
    cout << "Class_6_1B, operator delete[].\n";
    ::operator delete[](ptr);
}

void* Class_6_2A::operator new(size_t s, int) throw( std::bad_alloc ) { return ::operator new(s); }

void Class_6_2A::operator delete(void* ptr, size_t) { ::operator delete(ptr); }

void* Shared_6::allocate(size_t s) {
    cout << "Shared_6::allocate().\n";
    return ::operator new(s);
}

void Shared_6::deallocate(void* p) {
    cout << "Shared_6::deallocate().\n";
    return ::operator delete(p);
}

// Task 6.2. Using operator delete, but custom operator new not defined.

// void operator delete(void* p) throw() { Shared_6::deallocate(p); }

// void operator delete(void* p, std::nothrow_t&) throw() { Shared_6::deallocate(p); }

Class_6_3::Class_6_3() : ptr(new char) { *ptr = 'a'; }

Class_6_3::~Class_6_3() {}

void Labs_0x05::function_6_1() {
    unique_ptr<char> ptr1(new char);
    unique_ptr<char> ptr2;
    // ptr2 = ptr1; // use of deleted function.
}

void function_6_2() {
    unique_ptr<char> ptr1(new char);
    unique_ptr<char> ptr2;
    // ptr2 = ptr1;     // use of deleted function.
    *ptr1 = 'a';
    char* ptr3 = ptr1.get();
    cout << "Pointer to char " << *ptr1 << ", and method get(), " << *ptr3 << endl;
}

unique_ptr<char> function_6_3() {
    unique_ptr<char> ptr (new char);
    *ptr = '1';
    return ptr;
}

void function_6_4(std::unique_ptr<char>& ptr) { cout << "Function_6_4, with unique_ptr, parameter, " << *ptr << endl; }

string function_6_5() {
    string result = "function_6_5";
    cout << "Function_6_5, has called.\n";
    return result;
}

Class_6_4::Class_6_4() { counter++; }

Class_6_4::~Class_6_4() { counter--; }

Class_6_5::Class_6_5(char c) : pointer1(new char (c)), pointer2(new char (c)) {
    cout << "Class_6_5, constructor, values in pointers " << *pointer1 << " " << *pointer2 << endl;
}

Class_6_5::Class_6_5(const Class_6_5& rv) : pointer2(rv.pointer2.get()) {
    pointer1 = new char (*rv.pointer1);
    cout << "Class_6_5, copy constructor, values in pointers " << *pointer1 << " " << *pointer2 << endl;
}

Class_6_5::~Class_6_5() {
    cout << "Class_6_5, destructor, values in pointers " << *pointer1 << " " << *pointer2 << endl;
    delete pointer1;
    // pointer2 destructor.
}

Class_6_5& Class_6_5::operator=(const Class_6_5& rv) {
    pointer1 = new char(*rv.pointer1);
    pointer2.reset(rv.pointer2.get());
}
