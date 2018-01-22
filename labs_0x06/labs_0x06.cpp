#include "labs_0x06.hpp"

using namespace std;
using namespace Labs_0x06;

void Labs_0x06::function_1(std::vector<int>& v) {
    // in memory junk.
    cout << "First element in vector, using operator[0], " << v[0] << endl;
    // out_of_range check, exception.
    cout << "First element in vector, using method 'at', " << v.at(0) << endl;
}

template<typename T>
void toStringT(T value, char* buffer);

template<> void toStringT<int>(int value, char* buffer) {
    cout << "Using function with integer parameter.\n";
    sprintf(buffer, "%d", value);
}

template<> void toStringT<char>(char value, char* buffer) {
    cout << "Using function with char parameter.\n";
    sprintf(buffer, "%c", value);
}

void Labs_0x06::toString(int i, char* buffer, const int maxSize) {
    if (maxSize <= sprintf(buffer, "%4d", i)) cout << "Buffer overflowed at 'int to string' function.\n"; else
        cout << "Buffer worked as expected at 'int to string' function.\n";
}

Class_1::Class_1(char i) : c(i) {}

void Class_1::function() { cout << "Class1, function with parameter " << c << endl; }

Base_1::~Base_1() { cout << "Virtual Base_1 destructor.\n"; }

void Base_1::function_1() { cout << "Base_1, function_1.\n"; }

void Base_1::function_2() { cout << "Base_1, function_2.\n"; }

void Derived_1::function_1() { cout << "Derived class, first function.\n"; }

void Derived_1::function_2() { cout << "Derived class, second functiom.\n"; }

void Labs_0x06::function_2(Base_1& value) {
    value.function_1();
    value.function_2();
}

void Class_2::function_1(bool b) { cout << "CLass_2, bool parameter " << b << endl; }

void Class_2::function_2() { cout << "Class_2, function_2.\n"; }

void Class_3::function_1() { cout << "Class_3, function_1.\n"; }

void Class_3::function_2(double d) { cout << "Class_3, double parameter " << d << endl; }

template<class T>
function_3(T& v) {
    v.function_1();
    v.function_2();
}

template<class T1, class T2>
void create(T1* m, const T2& n) {
    cout << "Using constructor with both template's parameters.\n";
    new (m) T1(n);
}

template<class T1>
void create(T1* m, const T1& n) {
    cout << "Using constructor with one template's parameter.\n";
    new (m) T1(n);
}

template<class T>
void destroy(T* ptr) {
    cout << "Destroy single object.\n";
    ptr->~T();
}

template<class It>
void destroy(It first, It last) {
    cout << "Destroy array of objects.\n";
    while (first != last) {
        destroy(first);
        first++;
    }
}

Class_4::Class_4(char i) : c(i) {}

void Class_4::swap(Class_4& r) {
    char t = c;
    c = r.c;
    r.c = t;
}

template<class T>
void swapT(T& a, T& b) {
    T tmp(a);
    a = b;
    b = tmp;
}

template<>
void swapT(Class_4& l, Class_4& r) {
    l.swap(r);
}

template<class T>
void swapCD(T& a, T& b) {
    if (&a != &b) {
        cout << "Swapping objects with create and destroy, needs an allocated memory.\n";
        T tmp(a);
        destroy(&a);
        create(&a, b);
        destroy(&b);
        create(&b, tmp);
    }
}

template<class T> void function_4(T value) {
    std:: cout << "Using general template function, parameter " << value << std::endl;
}

template<class T> void function_4(int i, T value, double d) {
    std::cout << "Using general template with additional parameters, " << i << " " << value << " " << d << std::endl;
}

template<class T> void function_4(T* ptr) {
    std::cout << "Using general template with pointer, value " << *ptr << std::endl;
}

template<> void function_4(int i) {
    std::cout << "Using specialization with parameter int, " << i << std::endl;
}

void function_4(double d) {
    std::cout << "Using specialization with parameter double, " << d << std::endl;
}

template<class T> void function_5(T value) {
    std::cout << "General template function with parameter " << value << std::endl;
}

template<class T> void function_5(T* ptr) {
    std::cout << "General template function with pointer " << *ptr << std::endl;
}

template<> void function_5<int>(int* ptr) {
    std::cout << "Specialization template function with int parameter " << *ptr << std::endl;
}

template<class T> void function_6(T value) {
    Struct_1<T>::function(value);
}

void Labs_0x06::function_7() throw(int, char) {
    throw(string("Throwing unexpected exception."));
}

void Labs_0x06::UnxpectedHandler() {
    cout << "Handler for unxepected exception.\n";
}

void Labs_0x06::function_8() {
    cout << "Function with any exception.\n";
    throw('a');
}

int Labs_0x06::function_9() throw() {
    cout << "Function without exceptions.\n";
    throw('a');
}

int Labs_0x06::function_10() throw(int, bool) {
    cout << "Function with specified exceptions.\n";
    throw(true);
}

void labs_0x06()
{
    cout << "Starting Labs_0x06.\n";
    // Task 1. Simple using of vector.
    vector<int> vector1;
    cout << "Capacity of vector1, " << vector1.capacity() << ", ";
    vector1.reserve(2);
    // assert(vector1.capacity() >= 2);
    if (vector1.capacity() >= 2) cout << "new capacity is more than 2.\n"; else
        cout << "new capacity is less than 2.\n";
    cout << "Source vector 1, elements, vector1 size " << vector1.size() << ": ";
    const int elements = 2;
    for (int i = 0; i < elements; ++i) {
        vector1.push_back(i);
        cout << vector1.back() << " ";
    }
    cout << endl;
    function_1(vector1);
    // Tasks 2-3. Works with smaller sizes, but may be undefined behaviour in the future.
    const int smallSize = 5, bigSize = 25;
    int i1 = 25;
    char buffer[smallSize], result[bigSize];
    toString(i1, buffer, smallSize);
    cout << "Using other version of convert, 'int to string':\n";
    cout << "Result of sprintf: " << sprintf(buffer, "%%%ds", smallSize - 1) << endl;
    // scanf(buffer, result);       // need to press keys.
    toStringT(10, buffer);
    cout << "Buffer after calling template of function: " << buffer << endl;
    toStringT('a', buffer);
    cout << "Buffer after calling template of function: " << buffer << endl;
    cout << "Using snprintf, returning " << snprintf(buffer, smallSize, "%4d", 35);
    cout << ", buffer: " << buffer << endl;
    ostringstream stream1;
    stream1 << "Using ostringstream to convert: " << setw(4) << i1 << endl;
    string s1 = stream1.str();
    // strstream stream2;   // depricated, using stringstream instead.
    stringstream stream2;
    stream2 << i1;
    cout << "Using stringstream class, " << stream2.str() << endl;
    cout << "Skip lexical_cast from boost.\n";
    // Task 4. mem_fun depricated in c++17.
    vector<Class_1> vector2;
    for (char i = 'a'; i < 'd'; ++i) vector2.push_back(Class_1(i));
    for_each(vector2.begin(), vector2.end(), mem_fun_ref(&Class_1::function));
    // Tasks 5-6. Works fine.
    Derived_1 cl1;
    function_2(cl1);
    Class_2 cl2;
    Class_3 cl3;
    function_3<Class_2>(cl2);
    function_3<Class_3>(cl3);
    Base_1* ptr1 = new Base_1[smallSize];
    Derived_1* ptr2 = new Derived_1[smallSize];
    for (int i = 0; i < bigSize; result[i++] = 0);
    create<char>(result, 'a');
    cout << "Buffer after create of 'a' char: " << result << endl;
    double buffer2[smallSize];
    create(buffer2, 2.5);
    create(buffer2, 4);        // no errors in all variants.
    Base_1 cl4;
    Derived_1 cl5;
    create(ptr1, cl4);
    create(ptr2, cl5);
    Derived_1* ptr3 = new Derived_1;
    destroy(ptr3);
    const int tinySize = 3;
    char* array[tinySize];
    for (int i = 0; i < tinySize; ++i) array[i] = new char('a' + i);
    destroy(&array[0], &array[2]);
    int i2 = 2, i3 = 3;
    cout << "Integers with swap templates, source " << i2 << " " << i3;
    swapT<int>(i2, i3);
    cout << ", after swap " << i2 << " " << i3 << endl;
    Class_4 cl6('a'), cl7('b');
    swapT(cl6, cl7);
    cout << "Class_4, objects, after using specified template swap " << cl6.c << " " << cl7.c << endl;
    cout << "Creating second object of Derived_1, in new memory location.\n";
    Derived_1 cl8;
    Derived_1* ptr4 = new Derived_1[smallSize];
    create(ptr4, cl8);
    swapCD<Derived_1>(cl5, cl8);
    // Task 7. May be some changes in new standard, not fully worked examples.
    bool b1 = true;
    int i4 = 3;
    double d1 = 5.0;
    function_4(b1);
    function_4(i4, 42, d1);
    function_4(&i4);
    function_4(i4);
    function_4(d1);
    int *ptr5 = new int(5);
    function_5(ptr5);
    function_6<int>(5);
    // Task 8. Using boost, so just quick try with previous classes.
    // Tasks. 9-10. In c++17, keyword 'export' reserved, but unused since c++03.
    // Task 11. Quick try and catch.
    const int i5 = 1;
    try {
        if (i5 > 0) throw string("Throw exception with string."); else
            throw(1);
    } catch (const string& s) {
        cout << "Catching exception with string parameter.\n";
    } catch (...) {
        cout << "Catching exception with other parameter.\n";
    }
    // Task 12. Just some theory about code stability.
    // Task 13. Shorts examples.
    set_unexpected(&UnxpectedHandler);      // terminated anyway.
    try {
        // function_7();
        function_8();
    } catch (const char& c) {
        cout << "Catching exception with char, " << c << endl;
    }
    try {
        // function_9();        // no exceptions.
    } catch (const char& c) {
        cout << "Catching exception with char, " << c << endl;
    }
    try {
        function_10();
    } catch (const bool& b) {
        cout << "Catch exception with bool, " << b << endl;
    }
    void (*ptr6)() throw(char, bool, int);   // compiles ok in both cases.
    ptr6 = function_11;
}
