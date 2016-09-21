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
}

void labs_0x04()
{
    Labs_0x04::chapter_3();
}
