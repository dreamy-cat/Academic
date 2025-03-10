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

Base_3::Base_3(const std::string& s) { cout << "Base_3, constructor.\n"; }

string Base_3::getString() { return "Base_3, getString() method."; }

Derived_3::Derived_3() : Base_3(data = getString()) {}

Base_3a::Base_3a() { cout << "Base_3a, constructor.\n"; }

Base_3b::Base_3b() { cout << "Base_3b, constructor.\n"; }

Base_3c::Base_3c() { cout << "Base_3c, constructor.\n"; }

Virtual_3a::Virtual_3a() { cout << "Virtual_3a, constructor.\n"; }

Virtual_3b::Virtual_3b() { cout << "Virtual_3b, constructor.\n"; }

Derived_3a::Derived_3a() { cout << "Derived_3a, constructor.\n"; }

Derived_3b::Derived_3b() { cout << "Derived_3b, constructor.\n"; }

void Labs_0x06::function_12(Class_7& value) {
    cout << "Friend function with Class_7 parameter, " << value.a << endl;
    if (value.a < 'z') value.a++;
    cout << "Using reinterpret_cast to this class.\n";
}

// void Derived_4::function() { Base_4::function(); }  // private

double Class_8::multiply(double d) { return d * d; }

int Class_8::multiply(int i) { return i * i; }

PtrMem Class_8::getPtr() { return &Class_8::multiply; }

Class_9::Class_9(char i) : c1(i), c2(i), c3(i), c4(i) {}

char Class_9::getChar() const { return c3; }

char Class_9::getCharP() const { return c4; }

Base_5::Base_5() { cout << "Base_5, constructor.\n"; }

int Base_5::process(const string &name) {
    cout << "Process with name " << name << endl;
    processA(name);
    processB(name);
}

Base_5::~Base_5() { cout << "Base_5, destructor.\n"; }

int Base_5::processA(const std::string& name) { cout << "Base_5, process A, name " << name << endl; }

int Base_5::processB(const string &name) { cout << "Base_5, process B, name " << name << endl; }

bool Base_5::ready() { }

Derived_5::Derived_5() { cout << "Derived_5, constructor.\n"; }

Derived_5::~Derived_5() { cout << "Derived_5, destructor.\n"; }

int Derived_5::processA(const string &name) { cout << "Derived_5, process A, name " << name << endl; }

Base_6::~Base_6() throw(int) { cout << "Base_6, destructor.\n"; }

Derived_6::~Derived_6() { cout << "Derived_6, destructor.\n"; }

Derived_6::Data::~Data() throw(int) { cout << "Data subclass, destructor.\n"; }

Base_7::Base_7(int a, int b) {
    cout << "Base_7, constructor, parameters " << a << " " << b << endl;
}

Derived_7::Derived_7(int i, int j) : Base_7(i, j) {
    cout << "Derived_7, constructor, parameters " << i << " " << j << endl;
}

Base_7::~Base_7() { cout << "Base_7, destructor.\n"; }

void* Derived_8::operator new(std::size_t) throw () {
    cout << "Operator new(size_t) throw().\n";
    return (::operator new(sizeof(Derived_8)));
}

void* Derived_8::operator new(std::size_t, const std::nothrow_t&) throw() {
    cout << "Operator new(size_t, nothrow_t) throw().\n";
    return (::operator new(sizeof(Derived_8)));
}

void* Derived_8::operator new(std::size_t, void*) throw() {
    cout << "Operator new(size_t, void*) throw().\n";
    return (::operator new(sizeof(Derived_8)));
}

const char& Labs_0x06::function_13(const int& i) {
    cout << "Function_13, object int " << i << " returning const reference to char 'a'.\n";
    // char *r = new char(i % (sizeof(char) * 0x100));
    char* r = new char('a');
    return *r;
}

void Labs_0x06::function_14(const int i) { cout << "Function_14 with parameter " << i << endl; }

float Labs_0x06::square(float side) { return side * side; }

BitsVectorChars::BitsVectorChars() : actualSize(0) { buffer.clear(); }

BitsVectorChars::~BitsVectorChars() {
    actualSize = 0;
    buffer.clear();
}

void BitsVectorChars::append(unsigned char* p, size_t n) {
    if (n == 0 || p == nullptr) return;
    unsigned char data, offset = actualSize % bitsPerChar, mask = 0x00;
    if (actualSize + n > buffer.size() * bitsPerChar) {
        int newSize = (actualSize + n) / bitsPerChar;
        if ((actualSize + n) % bitsPerChar != 0) newSize++;
        buffer.resize(newSize, 0);
        cout << "Not enough free buffer space, new size is " << buffer.size() << endl;
    } else cout << "All bits are fit in that buffer size.\n";
    unsigned char* destination = &buffer[actualSize / bitsPerChar];
    cout << "Offset is " << (int)offset << ", adding to free bits to last byte.\n";
    if (offset > 0 || (offset + n) <= bitsPerChar) {
        for (int i = 0; i < n; i++) mask = (mask << 1) | 0x01;
        *destination = *destination | (((*p) << offset) & (mask << offset));
        destination++;
    }
    if (offset + n > bitsPerChar) {
        int fullBytes = (n + offset) / bitsPerChar;
        if ((n + offset) % bitsPerChar == 0) fullBytes--;
        cout << "Some bytes needs to add, " << fullBytes << ": ";
        for (int i = 0; i < fullBytes; ++i) {
            data = (*p >> (bitsPerChar - offset));
            if (n > bitsPerChar) data = data | ((*(p+1)) << offset);
            cout << (int)data << " ";
            *destination++ = data;
            p++;
        }
        cout << endl;
    }
    actualSize += n;
}

size_t BitsVectorChars::size() const { return actualSize; }

void BitsVectorChars::get(size_t p, size_t n, unsigned char* d) {
    cout << "Get bits from vector<unsigned char>, position " << p << ", bits " << n << endl;
    if (p + n > actualSize || d == nullptr || n == 0) {
        cout << "Wrong pointer or position and size more than possible.\n";
        return;
    }
    int index = p / bitsPerChar;
    cout << "\tIndex in vector is " << index;
    unsigned char mask = 0x00, offset = p % bitsPerChar, *data = d;
    for (int i = 0; i < n && i < bitsPerChar; i++) mask = mask << 1 | 0x01;
    mask = mask << offset;
    cout << ", mask offset is " << (int)mask;
    if (offset > 0 || offset + n <= bitsPerChar) {
        *data = (buffer[index] & mask) >> offset;
        cout << "\n\tHead processing byte in data: " << (int)*data;
        index++;
    }
    cout << endl;
    if (offset + n > bitsPerChar) {
        int fullBytes = (n + offset) / bitsPerChar;
        unsigned char tailMask = 0;
        for (int i = 0; i < n % bitsPerChar + offset; ++i) tailMask = tailMask << 1 | 0x01;
        cout << "\tMain part processing full bytes range " << fullBytes << ", tail mask " << (int)tailMask << endl;
        for (int i = 0; i < fullBytes; i++) {
            cout << "\t[" << i << "]";
            if (offset > 0) *data = *data | (buffer[index] << (bitsPerChar - offset)); else
                if (i < fullBytes-1) *data = buffer[index++];
            cout << "\t" << int(*data);
            if (n > bitsPerChar) {
                cout << "\t" << int(*data);
                *(data+1) = (buffer[index] >> offset);
                if (i == fullBytes - 1) *(data+1) = *(data+1) & tailMask;
                cout << "\t" << (int)(*(data+1));
            }
            cout << endl;
            data++;
            index++;
        }
        cout << endl;
    }
}

void BitsVectorChars::print() const {
    cout << "All bits in vector, with actual size " << actualSize << " bits.";
    for (int i = 0; i < buffer.size(); ++i) {
        cout << "\n\t[" << (int)buffer[i] << "]\t";
        for (unsigned char mask = 0x80; mask != 0; mask = mask >> 1)
            if ((buffer[i] & mask) == mask) cout << "1"; else cout << "0";
    }
    cout << endl;
}

BitsVectorBools::BitsVectorBools() : actualSize(0) { buffer.clear(); }

BitsVectorBools::~BitsVectorBools() {
    actualSize = 0;
    buffer.clear();
}

void BitsVectorBools::append(unsigned char* p, size_t n) {
    cout << "Adding bits to vector<bool>: ";
    if (n == 0 || p == nullptr) {
        cout << "Pointer or amount of bits incorrect.\n";
        return;
    }
    unsigned char byte = 0x00;
    for (int i = 0; i < n; ) {
        unsigned char mask = 0x01 << (i % bitsPerChar);
        buffer.push_back(*p & mask);
        cout << ((*p & mask) > 0);
        byte = byte | ((unsigned char)(*p & mask) << ((bitsPerChar - 1) - i % bitsPerChar));
        ++i;
        if (i % bitsPerChar == 0 || i == (n - 1)) {
            p++;
            cout << " [" << (int)byte << "] ";
            byte = 0x00;
        }
    }
    cout << endl;
    actualSize += n;
}

void BitsVectorBools::get(size_t p, size_t n, unsigned char* d) {
    cout << "Get bits from vector<bool> to data.\n";
    if (p + n > buffer.size() || n == 0 || d == nullptr) {
        cout << "Incorrect position or destination is null pointer or N more than size of buffer<bool>.\n";
        return;
    }
    unsigned char byte = 0x00, mask = 0x00;
    for (int i = p; i < p + n; ) {
        unsigned char byteSize = (i - p) % bitsPerChar;
        byte = byte | ((unsigned char)buffer[i++] << ((bitsPerChar - 1) - byteSize));
        if ((i - p) % bitsPerChar == 0 || i == (p + n)) {
            *d++ = byte;
            byte = 0x00;
        }
    }
}

void BitsVectorBools::print() const {
    cout << "All bits and bytes in vector<bool>, with actual size " << buffer.size() << " bits.\n\t";
    unsigned char mask = 0x01, byte = 0x00;
    for (int i = 0; i < buffer.size(); ) {
        byte = byte | ((unsigned char)buffer[i] << ((bitsPerChar - 1) - i % bitsPerChar));
        cout << (char)('0' + (buffer[i] == true)) << " ";
        i++;
        if (i % bitsPerChar == 0 || i == buffer.size()) {
            cout << " [" << (int)byte << "]\n\t";
            byte = 0x00;
        }
    }
    cout << endl;
}

size_t BitsVectorBools::size() const { return actualSize; }

int Class_10::operator()(bool) { return 1; }

bool Struct_5::function(int *ptr) { return ptr && 0[ptr] and not ptr[1:>>ptr[2]; }

Class_11& Class_11::operator++() { return *this; }

Class_11& Class_11::operator+() { return *this; }

void Class_11::operator&&(int) {}

void Class_11::operator<<(int) {}

void Class_11::operator||(int) {}

BaseCallFPtr::~BaseCallFPtr() {}

Union_1::Union_1(std::string si) : s(si) {}

Union_1::~Union_1() {}

string Union_1::getString() const { return s; }

void Labs_0x06::function_15() {
    union U {
        U() : s("") {}
        U(int* ptr) : p(ptr) {}
        U& operator=(int* ptr) { *p = *ptr; }
        ~U() {}
        string s;
        unique_ptr<int> p;
    };
    U obj;
    obj.s = "String in Union, first parameter.\n";
    obj.p = unique_ptr<int>(new int(4));
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
    // Task 14. Not try reinterpret_cast.
    // Derived_3 cl9;      // compiles, but crashed as expected.
    cout << "Classes structure, all constructors included in Class_6.\n";
    Class_6 cl10;
    Class_7 cl11('a');
    function_12(cl11);
    cout << "Second variant using #define public and private.\n";
    cout << "Using structure, ";
    cl11.function(Struct_2());
    // Task 15. Using just 5, is private or ambigious.
    Base_4 cl12;
    // cl12.function();     // private.
    cout << "Address of object of Class_8, " << (&cl12.function) << endl;
    Class_8 cl13;
    cout << "Twice with integer parameter 5, " << cl13.multiply(5.0) << endl;
    // Task 16. Last part as previous.
    PtrMem ptr7 = cl13.getPtr();
    cout << "Using pointer to method of Class::multiply(), parameter 3.0, " << (cl13.*ptr7)(3.0) << endl;
    // Task 17. Calling protected method not possible.
    Class_9 cl14('a');
    cout << "Using public method to get char: " << cl14.getChar() << endl;
    // cout << "Using protected method to get char: " << cl14.getCharP() << endl;
    Pair<char, int> cl15;
    // Task 18. Virtual functions are private, unary_function with delete works not as planned.
    Base_5* ptr8 = new Derived_5;
    // ptr8->processA("derived object");
    ptr8->process("derived polymorphic object");
    delete ptr8;
    // Task 19. Looser throw for ~Derived_6(). Don't use virtual for operator=().
    Base_6 cl16;
    Derived_6 cl17;
    Base_6* ptr9 = new Derived_6;
    delete ptr9;
    // class { auto_ptr<int> i }. auto_ptr depricated since c++11.
    Derived_7* ptr10 = new Derived_7(1, 2);      // Use of deleted function.
    delete ptr10;
    // Task 20-21. Some theory.
    Struct_3 str1;
    cout << "Actual size of Struct_3[char, long, char] local object " << sizeof(str1) << endl;
    Struct_4 str2;
    cout << "Actual size of Struct_4[long, char, char] local object " << sizeof(str2) << endl;
    // Tasks 22-23.
    void* ptr11 = ::operator new(sizeof(int));
    new (ptr11)int(3);
    cout << "Create integer in memory, " << *((int*)ptr11) << endl;
    void* ptr12 = ::operator new(1024);
    new (ptr12)char('a');
    // new (42, 3.0, "abc")char('b');   // example of custom operator new.
    char* ptr13 = new(std::nothrow)char('b');
    cout << "Operators new with chars " << *((char*)ptr12) << " and " << *ptr13 << endl;
    Derived_8* ptr14 = new Derived_8, *ptr15 = new(nothrow)Derived_8;
    new (ptr12) Derived_8;
    cout << "After adding derived class for operator new.\n";
    Derived_8* ptr16 = new Derived_8, *ptr17 = new(nothrow) Derived_8;
    new (ptr12) Derived_8;
    const int dataSize = 4;
    char* ptr18 = new char[dataSize];
    char ptr19[dataSize];
    // memset(ptr18, 0, dataSize);      // zeros anyway.
    cout << "All array of char creating by operator new and old plain data[]: ";
    for (int i = 0; i < dataSize; i++) cout << (int)ptr18[i] << "[" << (int)ptr19[i] << "] ";
    cout << endl;
    // Task 24. Simple examples.
    function_13(1);
    function_14(2);
    // Task 25. Don't using inline, only if perfomance issue.
    cout << "Function square, within labs_0x06.hpp file, parameter 3, result " << square(3) << endl;
    // Tasks 26-27. Refactor later, very poor solution.
    BitsVectorChars bits;
    const int dSize = 4;
    // unsigned char data[dSize] = { 3, 3, 9, 4, 5, 1, 255, 5, 26, 5 };    // bits data & amount for testing.
    unsigned char data[dSize] = { 6, 173, 155, 79};
    unsigned char dest1[dSize] = { 0, 0, 0, 0 }, dest2[dSize] = {0, 0, 0, 0};
    cout << "Adding bits to buffer, using vector<unsigned char> container.\n";
    bits.append(&data[0], 1);
    bits.print();
    bits.append(&data[1], 19);
    bits.print();
    bits.get(2, 17, &dest1[0]);
    cout << "Result of new data: ";
    for (int i = 0; i < dSize; ++i) cout << (int)dest1[i] << " ";
    cout << "\nAdding bits to buffer, using vector<bool> container.\n";
    BitsVectorBools bitsBool;
    bitsBool.append(&data[0], 4);
    bitsBool.append(&data[1], 17);
    bitsBool.print();
    bitsBool.get(0, 21, dest2);
    cout << "Result of read vector<bool>: ";
    for (int i = 0; i < dSize; i++) cout << (int)dest2[i] << " ";
    cout << endl;
    // Task 28. Not compile, theory.
    if (true) cout << "Just a true statement at if(true).\n";
    if (5) cout << "Another statement with integer at if.\n";
    /*
    class if {
    public:
        if(char);
    };
    */
    // Class_10 if; // expected unqualified-id before 'if'
    // auto since c++11 has other mean.
    // Task 29. Commenting some lines because of console input.
    deque<string> deque1 = { "one", "two", "three" }, deque2;
    copy(deque1.begin(), deque1.end(), back_inserter(deque2));
    cout << "Check deque copy source: ";
    for (auto& e : deque1) cout << e << " ";
    cout << "and destination: ";
    for (auto& e : deque2) cout << e << " ";
    cout << endl;
    typedef istream_iterator<string> (FunctionType)();
    deque<string> deque3(istream_iterator<string>, FunctionType);
    // Using extra pair of ().
    // deque<string> deque4((istream_iterator<string>(cin)), istream_iterator<string>());
    // Using extra variables.
    // istream_iterator<string> first(cin), last;
    // deque<string> deque5(first, last);
    // Task 30. Too long to wait with float, may be a bad conversion.
    double d2 = 1e8;
    while (d2 > 0) --d2;
    /*
    float f1 = 1e8;
    while (f1 > 0) --f1;
    */
    // Task 31. Works fine with actual compiler.
    // Task 32. Very intresting but compiles ok.
    int i6 = 1;
    for (int i = 0; i < 5; ++i);
    ++i6;
    cout << "Result of simple example with error at for(...): " << i6 << endl;
    // Task 33. Very danger to use in real world.
    Class_11 cl18;
    +++++cl18;
    typedef void (Class_11::*FPtr)(int);
    // Task 34. Last element still not sorted, as is example.
    const int vSize = 5;
    int vector3[vSize] = { 3, 4, 2, 1, 2 };
    vector<int> vector4(vector3, vector3 + vSize);
    vector<int> index(vSize);
    SortIdx_1(vector4.begin(), vector4.end(), index.begin());
    cout << "All elements of vector after sort.\n\t[Index] and element first example:";
    for (int i = 0; i < vSize; ++i)
        cout << " [" << index[i] << "] " << vector4[index[i]];
    vector<int> vector5(vector3, vector3 + vSize);
    cout << "\n\tSecond example using pair:";
    ComparePair<vector<int>::iterator, vector<int>::iterator> Sort2;
    Sort2.SortIdx_2(vector5.begin(), vector5.end(), index.begin());
    for (int i = 0; i < vSize; ++i)
        cout << " [" << index[i] << "] " << vector5[index[i]];
    cout << "\n\tThird example using pair and map: ";
    vector<int> vector6(vector3, vector3 + vSize);
    SortIdx_3(vector6.begin(), vector6.end(), index.begin());
    for (int i = 0; i < vSize; ++i)
        cout << " [" << index[i] << "] " << vector6[index[i]];
    cout << endl;
    // Task 35. Quick testing.
    vector< CallFPtr<Class_1> > vector7;
    Class_1 cl19('a');
    vector7.push_back(CallFPtr<Class_1>(cl19, &Class_1::function));
    runFPtr(cl19, &Class_1::function)();
    // Task 36.
    Union_1 un1("Union_1, structure string.");
    Union_1 un2("Second union for operator=().");
    un1.i = 3;
    cout << "Testing simple union, integer " << un1.i;
    un1.f = 3.14;
    cout << ", float " << un1.f << endl;
    function_15();
    cout << "String from union " << un1.getString() << endl;
    cout << "String from second union, " << un2.getString() << endl;
    un2 = un1;
    cout << "After using operator=(), by compiler, " << un2.getString() << endl;
    // Tasks 37-40. Only theory.
}
