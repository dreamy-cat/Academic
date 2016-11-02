#include "labs_0x04.hpp"

using namespace std;

vector<int> Labs_0x04::createVector(const int vSize)
{
    return ( std::vector<int>(vSize, 1) );
}

void Labs_0x04::chapter_1()
{
    // Part 1.1 Just some simple tests.
    cout << "First part of all parameters types." << endl;
    int i1 = 1;
    const int i2 = 2;
    const int& r1 = i1;
    function_1(i1);
    function_1(i2);
    function_1(r1);
    function_2(i1);
    function_2(i2);
    function_2(r1);
    const int *r2 = &i1;
    function_3(&i1);
    function_3(r2);
    cout << "Second part of all parameters types." << endl;
    int i3 = 3;
    const int c1 = i3;
    const int& r3 = i3;
    function_4(i3);
    function_4(c1);
    function_4(r3);
    function_4(5);
    cout << "Third part of all parameters types." << endl;
    int i4 = 4;
    const int c2 = i4;
    const int& r4 = i4;
    function_5(i4);
    function_5(c2);
    function_5(r4);
    cout << "Some tests with arrays." << endl;
    const char s1[] = "String one.";
    function_1(s1);
    cout << "Size of 'String one.' = " << sizeArray(s1) << endl;
    void (*ptr1)(const char s[]);
    cout << "Pointer to functions as templates." << endl;
    function_5(ptr1);
    function_6(ptr1);
    // Part 1.2.
    auto i5 = 1;
    auto i6(2);
    auto i7 = { 3 };
    auto i8{4};
    // Part 1.3
    vector<int> v1 = { 1, 2, 3 };
    cout << "Access to all elements in vector: ";
    for (int idx = 0; idx < v1.size(); idx++) cout << access(v1, idx) << " ";
    cout << "\nAccess to all elements in vector, using C++11 style of templates: ";
    for (int idx = 0; idx < v1.size(); idx++) cout << accessDeclare(v1, idx) << " ";
    cout << "\nAccess to all elements in vector, using C++14 style of templates: ";
    for (int idx = 0; idx < v1.size(); idx++) cout << accessDeclareAuto(v1, idx) << " ";
    cout << endl;
    // Part 1.4. Just for compiler output.
    const int i9 = 0;
    auto i10 = i9;
    auto i11 = &i9;
    // Class1<decltype(i10)> cl1;
    // Class1<decltype(i11)> cl2;
    const auto  v2 = createVector(3);
    cout << "All elements in auto vector and their types.\n";
    for (auto &element : v2) function_7(&element);
}

void Labs_0x04::chapter_2()
{
    // Part 2.1. Trying to compile, ok.
    cout << "Chapter 2." << endl;
    auto lambda1 = [] (const unique_ptr<int>& pointer1, const unique_ptr<int>& pointer2) { return (*pointer1 < *pointer2); };
    unique_ptr<int> ptr1(new int(5)), ptr2(new int(3));
    cout << "Compare two pointers with first lambda in c++11 style '" << *ptr1 << " < " << *ptr2 << "': " << lambda1(ptr1, ptr2) << endl;
    auto lambda2 = [] (const auto& pointer1, const auto& pointer2) { return ( *pointer1 < *pointer2 ); };
    cout << "Compare two pointers with second lambda in c++14 style '" << *ptr1 << " < " << *ptr2 << "': " << lambda2(ptr1, ptr2) << endl;
    // function<bool(const unique_ptr<int>& pointer1, const unique_ptr<int>& pointer2)> fPtr1;
    function<bool(const unique_ptr<int>&, const unique_ptr<int>&)> fPtr1 = [] (const unique_ptr<int>& pointer1, const unique_ptr<int>& pointer2) {
        return ( *pointer1 < *pointer2 );
    };
    vector<int> v1(5);
    unsigned size1 = v1.size();
    auto size2 = v1.size();
    cout << "Size of vector v1 = " << size1 << ", type of size(unsigned) and sizeof() " << typeid(size1).name() << ", " << size1 << endl;
    cout << "Size of vector v1 = " << size2 << ", type of size(auto) " << typeid(size2).name() << " and sizeof() " << ", " << size2 << endl;
    // Part 2.2
    vector<bool> v2(8);
    bool first = v2[1];
    auto second = v2[2];
    cout << "First element of vector<bool> and types " << first << "(" << typeid(first).name() <<
            "), second " << second << "(" << typeid(second).name() << ")" << endl;
    auto third = static_cast<bool>(v2[3]);
    cout << "Third element of vector<bool> and type " << third << "(" << typeid(third).name() << ")" << endl;
}

void function_9(int i)
{
    cout << "Function_9(int)." << endl;
}

void function_9(bool b)
{
    cout << "Function_9(bool)." << endl;
}

void function_9(void* ptr)
{
    cout << "Function_9(void*)." << endl;
}

int function_10(shared_ptr<Class2> ptr)
{
    cout << "Function_10(shared_ptr<Class2>)." << endl;
    return 1;
}

double function_11(unique_ptr<Class2> ptr)
{
    cout << "Function_11(unique_ptr<Class2>)." << endl;
    return 2.0;
}

bool function_12(Class2* ptr)
{
    cout << "Function_12(Class2* ptr)." << endl;
    return true;
}

Class5::Class5()
{
    cout << "Class5 constructor." << endl;
}

void Class6::function1() const
{
    cout << "Class6::function1()." << endl;
}

void Class6::function2(int i)
{
    cout << "Class6::function2() const." << endl;
}

void Class6::function3() &
{
    cout << "Class6::function3() &." << endl;
}

void Class6::function4() const
{
    cout << "Class6::function4() const." << endl;
}

void Class6_1::function1() const
{
    cout << "Class6_1::function1()." << endl;
}

void Class6_1::function2(int i)
{
    cout << "Class6_1::function2(unsigned int)." << endl;
}

void Class6_1::function3() &
{
    cout << "Class6_1::function3() &&." << endl;
}

void Class6_1::function4() const
{
    cout << "Class6_1::function4() const" << endl;
}

Class7::Class7()
{
    cout << "Elements in vector: ";
    v.insert(v.begin(), {1, 2, 3} );
    for (auto& e : v) cout << e << " ";
    cout << endl;
}

Class7 Class7::create()
{
    return *(new Class7);
}

vector<int>& Class7::data() &
{
    cout << "Return lvalue of vector<int>." << endl;
    return v;
}

vector<int>&& Class7::data() &&
{
    cout << "Return rvalue of vector<int>." << endl;
    return move(v);
}

int function_13() throw()
{
    cout << "Function_13(), throw doesn't generate warning." << endl;
    // throw -1;
}

int function_14() noexcept
{
    cout << "Function_14(), throw will always call terminate." << endl;
    // throw -1;
}

int Class8::constructor = 0;

int Class8::copyConstructor = 0;

Class8::Class8()
{
    constructor++;
}

Class8::Class8(const Class8 &)
{
    copyConstructor++;
}

void Class8::printCounters()
{
    cout << "Class8::constructor counter " << constructor << ", copy constructor counter " << copyConstructor << endl;
}

constexpr int pow(int base, int exp)
{
    return (exp == 0 ? 1 : base * pow(base, exp - 1));
}

constexpr Point::Point(double iX, double iY) noexcept : x(iX), y(iY) {}

constexpr double Point::xValue() const noexcept
{
    return x;
}

constexpr double Point::yValue() const noexcept
{
    return y;
}

constexpr void Point::setX(double sX) noexcept
{
    x = sX;
}

constexpr void Point::setY(double sY) noexcept
{
    y = sY;
}

constexpr Point middlePoint(const Point& p1, const Point& p2) noexcept
{
    return { (p1.xValue() + p2.xValue()) / 2, (p1.yValue() + p2.yValue()) / 2  };
}

constexpr Point reflection(const Point& p) noexcept
{
    Point reflect;
    reflect.setX(-p.xValue());
    reflect.setY(-p.yValue());
    return reflect;
}

std::vector<double> Polynom::roots() const
{
    lock_guard<mutex> g(m);
    if (!isValid) isValid = true;
    return rootVals;
}

Class9::Class9()
{
    cout << "Class9::Class9()" << endl;
}

void Labs_0x04::chapter_3()
{
    // Part 3.1.
    cout << "Chapter 3." << endl;
    int i1(1);
    int i2 = 2;
    int i3 = { 3 };
    cout << "Simple out for all integers: " << i1 << " " << i2 << " " << i3 << endl;
    Class2 cl1;
    Class2 cl2 = cl1;
    cl1 = cl2;
    vector<int> v1 = { 1, 2, 3 };
    double d1 = 1.0, d2 = 2.0;
    // int i4 { d1 + d2 };  // Warning: Narrowing conversion.
    // Class2 cl3();        // Redeclared as different kind of symbol.
    Class2 cl3{};
    Class2 cl4(1, true);
    Class2 cl5{ "string" };
    Class2 cl6{};
    // Part 3.2.
    function_9(0);
    function_9(true);
    // call of overloaded 'function_9(NULL)' is ambigious
    // function_9(NULL);
    function_9(nullptr);
    mutex func10, func11, func12;
    lock_guard<mutex> g1(func10);
    auto result1 = function_10(0);
    lock_guard<mutex> g2(func11);
    auto result2 = function_11(NULL);
    lock_guard<mutex> g3(func12);
    auto result3 = function_12(nullptr);
    // could not convert 'ptr' from...
    // auto result4 = getResult(function_10, func10, 0);
    // auto result5 = getResult(function_11, func11, NULL);
    auto result6 = getResult(function_12, func12, nullptr);
    cout << "Results of calling all functions, 10, 11 and 12: " << result1 << " " << result2 << " " << result3 << endl;
    cout << "Results of calling function_12 with template: " << result6 << endl;
    // Part 3.3. Just compile a some declarations.
    using UPtr = std::unique_ptr<std::unordered_map<std::string, std::string>>;
    List1<Class2> cl7;
    List2<Class2>::type cl8;
    const List1<int> cl9;
    cout << typeid(remove_const_t<List1<int>>(cl9)).name() << endl;
    // Part 3.4.
    enum class Color { black, white, red };
    auto white = false;
    // Color cl10 = white;      // cannot convert 'bool' to ...
    Color cl10 = Color::white;
    // if (cl10 < 1.0) cout << "Less than...";  // no match for 'operator<'
    if ( static_cast<double>(cl10) <= 1.0)
        cout << "Color::white less than '1.0'" << endl;
    enum class Height : char { one, two, three };      // declaration
    Height cl11 = Height::one;
    cout << "Type of Height enum " << typeid(cl11).name() << endl;
    tuple<string, string, int> info("string1", "string2", 5);
    enum class InfoT { p1, p2, p3};
    auto t1 = get<static_cast<size_t>(InfoT::p1)>(info);
    cout << "First parameter in tuple " << t1 << endl;
    auto t2 = get<toInfoType(InfoT::p2)>(info);
    cout << "Second parameter in tuple " << t2 << endl;
    // Part 3.5.
    Class5 cl12;
    // cl12.isLucky('a');   // use of deleted function
    // Part 3.6. 'virtual void Class6_1::...' marked 'overrride', but does not...
    Class6* ptr1 = new Class6_1;
    ptr1->function1();
    ptr1->function2(1);
    ptr1->function3();
    ptr1->function4();
    Class7 cl13;
    auto v2 = cl13.data();
    auto v3 = cl13.create().data();
    // Part 3.7.
    vector<int>::iterator it1 = find(v3.begin(), v3.end(), 3);
    typedef vector<int>::const_iterator constIterV;
    constIterV it2 = find(static_cast<constIterV>(v3.begin()), static_cast<constIterV>(v3.end()), 3);
    cout << "Find third element in vector, with iterator " << *it1 << " and const iterator " << *it2;
    // v3.insert(static_cast<vector<int>::iterator>(it2), 4);  // no matching for function call...
    auto it3 = find(v3.cbegin(), v3.cend(), 3);
    cout << " with auto iterator " << *it3 << endl;
    findIns<vector<int>>(v3, 2, 1);
    cout << "After replace element 2, vector<int>: ";
    copy(v3.begin(), v3.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    // Part 3.8
    try {
        function_13();
        function_14();
    } catch (int) {
        cout << "Catch an exception." << endl;
    }
    vector<Class8> v4;
    v4.reserve(256);
    for (int i = 0; i < 1024; ++i) v4.push_back(Class8());
    Class8::printCounters();
    // Part 3.9
    constexpr auto vSize = 5;
    vector<int> v5(vSize);
    constexpr auto base = 2;
    cout << "Constant expression 2^5 with pow(2,5) " << pow(base, vSize) << endl;
    int i4 = 2, i5 = 5;
    cout << "In a runtime pow(2, 5) " << pow(i4, i5) << endl;
    constexpr Point p1 (1.5, 2.3);
    constexpr Point p2 ( 0.5, 3.5 );
    constexpr auto p3 = middlePoint(p1, p2);
    cout << "Points p1(" << p1.xValue() << "," << p1.yValue() << "), p2(" << p2.xValue() << "," << p2.yValue()
         << "), and middle p3(" << p3.xValue() << "," << p3.yValue() << ")" << endl;
    constexpr Point p4(3.5, 4.2);
    constexpr Point p5(2.5, 1.3);
    constexpr auto p6 = middlePoint(p4, p5);
    constexpr auto p7 = reflection(p6);
    cout << "Points p4(" << p4.xValue() << "," << p4.yValue() << "), p5(" << p5.xValue() << "," << p5.yValue()
         << "), and middle p6(" << p6.xValue() << "," << p6.yValue() << "), reflection p7("
         << p7.xValue() << "," << p7.yValue() << ")" << endl;
    // Part 3.10-11. Just compile a simple example.
    Class9 cl14, cl15;
    cl15 = cl14;
}

Class10::Class10()
{
    cout << "Class10::Class10()." << endl;
}

void Class10::function1() const
{
    // v.emplace_back(this);                    // free(): invalid next size (fast)
    // v.emplace_back(shared_from_this());      // bad_weak_ptr
    cout << "Class10::function1() has called." << endl;
}

unique_ptr<const Class10> factory3(int id)
{
    cout << "Calling unique_ptr<const Class10> factory3(int id)." << endl;
    return unique_ptr<const Class10>(new Class10);
}

shared_ptr<const Class10> factory4(int id)
{
    cout << "Calling shared_ptr<const Class10> factory4(int id)." << endl;
    static unordered_map<int, weak_ptr<const Class10>> cache;
    auto oPtr = cache[id].lock();
    if (!oPtr) {
        oPtr = factory3(id);
        cache[id] = oPtr;
    }
    return oPtr;
}

void function15(shared_ptr<int> sp, int p)
{
    cout << "Function15 with shared pointer, value " << *sp << endl;
}

Class11::Class11() : impl(make_unique<Class12>())
{
    cout << "Class11::Class11()." << endl;
}

Class11::~Class11()
{
    cout << "Class11::~Class11()." << endl;
    // Previous version.
    // delete impl;
}

Class11::Class11(Class11&& r) = default;

Class11& Class11::operator=(Class11&& r) = default;

Class11::Class11(const Class11& r) : impl(nullptr)
{
    cout << "Class11::Class11(const Class11& r)." << endl;
    if ( r.impl )
        impl = make_unique<Class12>(*r.impl);
}

Class11& Class11::operator=(const Class11& r)
{
    cout << "Class11::operator=(const Class11& r)." << endl;
    if ( !r.impl ) impl.reset(); else
        if ( !impl ) impl = make_unique<Class12>(*r.impl); else
            *impl = *r.impl;
    return *this;
}

void Labs_0x04::chapter_4()
{
    cout << "Chapter 4." << endl;
    // Part 4.1. Without C++14 style.
    int i1 = 1;
    auto cl1 = factory1(i1);
    cout << "Type returned by factory1() " << typeid(cl1).name() << endl;
    auto cl2 = factory2(i1);
    cout << "Type returned by factory1() " << typeid(cl2).name() << endl;
    shared_ptr<Class10> cl3 = factory1(i1);
    // Part 4.2.
    shared_ptr<Class10> cl4(new Class10, delClass10_1);
    shared_ptr<Class10> cl5(new Class10, delClass10_2);
    vector<shared_ptr<Class10>> v1{ cl4, cl5 };
    auto ptr1 = new Class10;
    shared_ptr<Class10> ptr2(ptr1, delClass10_1);
    // undefined behaviour
    // shared_ptr<Class10> ptr3(ptr1, delClass10_2);
    shared_ptr<Class10> ptr4(ptr2);
    Class10 cl6;
    cl6.function1();
    // Part 4.3.
    auto ptr5 = make_shared<Class10>();
    weak_ptr<Class10> ptr6(ptr5);
    ptr5 = nullptr;
    if (ptr6.expired()) cout << "Weak pointer to Class10 object is expired." << endl;
    shared_ptr<Class10> ptr7 = ptr6.lock();
    auto ptr8 = ptr6.lock();
    // try not expired weak pointer.
    ptr5 = make_shared<Class10>();
    ptr6 = weak_ptr<Class10>(ptr5);
    shared_ptr<Class10> ptr9(ptr6);
    cout << "Calling function1() using sharing pointer, converted from weak pointer." << endl;
    ptr9->function1();
    cout << "Using factory with cache to make couple pointers." << endl;
    auto ptr10 = factory4(0);
    auto ptr11 = factory4(0);
    cout << "Calling function1() from pointers, using factory with cache." << endl;
    ptr10->function1();
    ptr11->function1();
    cout << "Simple pointers status P1 -> P2 <- P3 with standard, shared and waek pointers." << endl;
    int* ptr12 = &i1, *ptr13 = ptr12, *ptr14 = ptr12;
    cout << "Standard pointers: " << *ptr13 << " " << *ptr12 << " " << *ptr14 << endl;
    int* i2 = new int(1);
    shared_ptr<int> ptr15(i2);
    shared_ptr<int> ptr17(i2);
    cout << "Shared pointers: " << *ptr15 << " " << *i2 << " " << *ptr17 << endl;
    weak_ptr<int> ptr18(ptr15);
    weak_ptr<int> ptr19(ptr17);
    cout << "Weak pointers: " << *(ptr18.lock()) << " " << *i2 << " " << *(ptr19.lock()) << endl;
    // Part 4.4
    auto ptr20(make_unique<int>());
    unique_ptr<int> ptr21(new int(1));
    auto ptr22(make_shared<int>());
    shared_ptr<int> ptr23(new int(1));
    // Both variants works.
    function15(shared_ptr<int>(new int(3)), 1);
    function15(make_shared<int>(3), 1);
    auto deleter1 = [](int* ptr) {
        cout << "Custom delter for int." << endl;
        delete ptr;
    };
    unique_ptr<int, decltype(deleter1)> ptr24(new int, deleter1);
    shared_ptr<int> ptr25(new int, deleter1);
    auto ptr26 = make_unique<vector<int>>(5, 3);
    auto ptr27 = make_shared<vector<int>>(5, 3);
    cout << "Verify elements of first vector: ";
    for (auto &e : *ptr26) cout << e << " ";
    cout << "\nSecond vector: ";
    for (auto &e : *ptr27) cout << e << " ";
    auto list1 = { 1, 2, 3, 4, 5 };
    auto ptr28 = make_shared<vector<int>> (list1);
    cout << "\nThird vector initialiazed with list: ";
    for (auto &e : *ptr28) cout << e << " ";
    cout << "\nCreate objects with many shared and weak pointers: ";
    vector<shared_ptr<int>> v2;
    vector<weak_ptr<int>> v3;
    for (int i = 0; i < 5; ++i) {
        v2.push_back(make_shared<int>(i));
        v3.push_back(weak_ptr<int>(v2[i]));
        cout << *(v2[i]) << " ";
    }
    // Probably not working as planned, or may be with specific compiler.
    cout << "\nAfter clearing shared pointers, weak pointers contains: ";
    // v2.clear();
    for (auto &e : v3) cout << *(e.lock()) << " ";
    v3.clear();
    shared_ptr<int> ptr29(new int, deleter1);
    function15(ptr29, 1);
    function15(move(ptr29), 2);
    // Part 4.5. Working but very unusual.
    Class11 cl7, cl8, cl9(cl7);
    cl8 = cl7;
}

Class13::Class13(const std::string text) : value(move(text))
{
    cout << "Class13::Class13(const std::string)." << endl;
}

void function_16(const Class13& lv)
{
    cout << "Function using lvalue." << endl;
}

void function_16(Class13 &&rv)
{
    cout << "Function using rvalue" << endl;
}

std::size_t Class13::moveCounter = 0;

Class13::Class13(Class13&& r) : value(move(r.value)), ptr(r.ptr)
{
    cout << "Move counter for Class13 = " << ++moveCounter << endl;
}

string Class13::getValue() const
{
    return value;
}

void Labs_0x04::chapter_5()
{
    cout << "Chapter 5." << endl;
    // Part 5.1.
    Class13 cl1("string 1");
    function_17(cl1);
    function_17(move(cl1));
    Class13 cl2(forward<Class13>(cl1));
    // Part 5.2.
    vector<int> v1;
    // function_18(v1);     // cannot bind 'std::vector<int> lvalue to std::vector<int>&&'
    auto lambda1 = [](auto&& f, auto&& p)
    {
        forward<decltype(f)>(f)(forward<decltype(p)>(p));
    };
    cout << "Function_17 calling as lambda.\n";
    lambda1(function_17<Class13>, forward<Class13>(cl1));
    // Part 5.3.
    Class13 cl3("object 3");
    auto str1 = new string("text");
    cl3.setValue(*str1);
    delete str1;
    cout << "Getting value from object Class13, while using rvalue: " << cl3.getValue() << endl;
}

void labs_0x04()
{
    Labs_0x04::chapter_5();
}
