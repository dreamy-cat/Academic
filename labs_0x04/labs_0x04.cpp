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

void labs_0x04()
{
    Labs_0x04::chapter_2();
}
