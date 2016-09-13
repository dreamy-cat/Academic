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

void labs_0x04()
{
    Labs_0x04::chapter_1();
}
