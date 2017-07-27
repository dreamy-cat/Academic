#include "labs_0x05.hpp"

using namespace std;

void Labs_0x05::chapter_01()
{
    cout << "Chapter's 1, tasks.\n";
    // Task 1.1.
    vector<int> v1(3, 1), v2(3, 2);
    copy(v1.begin(), v2.begin(), back_inserter(v1));
    // Task 1.2-3. Too new gcc for additional task.
    StringInsens s1("String 1.");
    if (s1 == "string 1.") cout << "'String 1.' equal 'string 1.', ok.\n"; else cout << "Strings not equal.\n";
    // Task 1.4-5.
    Vector_1<int, 3> v3(1), v4(v3);
    v3.elements();
    v4.elements();
    Vector_2<int, 1> v5;
    Vector_2<int, 1> v6(v5);
    Vector_2<int, 1> v7;
    v7 = v5;
    // Task 1.6-7. Simple strings.
    list<string> list1 = { "string 1", "string 2", "string 3" };
    string s2("string 1"), s3("string");
    cout << function_1_6(list1, s2) << endl;
    cout << function_1_6(list1, s3) << endl;
    // Task 1.8. Without input from istream.
    cout << "Standard stream.\n";
    function_1_8<string, string> (s2, s3);
    // Task 1.9.
    vector<int> v8 = { 3, 5, 7, 3, 1, 4, 3, 8, 3 };
    const int i1 = 3;
    cout << "Elements in Vector 8: ";
    for (vector<int>::iterator it = v8.begin(); it != v8.end(); )
        if (*it == i1) v8.erase(it); else cout << *it++ << " ";
    cout << "\nRemoving after two elements, using simple preidcate in vector: ";
    remove_if(v8.begin(), v8.end(), Class_1_9(2));
    for (auto &e : v8) cout << e << " ";
    cout << "\nRemoving elements usging second template function: ";
    // removeValueRange(v8.begin(), v8.end(), 2);
    for (auto &e : v8) cout << e << " ";
    cout << endl;
    // Task 1.10. Lots of variants and all of them not as good as expected...
    vector<int> v9 = { 1, 2, 4 }, v10 = { 3, 5, 8 };
    cout << "Vector 9 elements: ";
    for (auto &e : v9 ) cout << e << " ";
    if (isGreater_1(v9)) cout << "\nFounded elements greater than 7.\n"; else
        cout << "\nNo elements greater than 7 founded in vector.\n";
    cout << "Vector 10 elements: ";
    for (auto &e : v10 ) cout << e << " ";
    if (isGreater_2(v10)) cout << "\nFounded elements greater than 7.\n"; else
        cout << "\nNo elements greater than 7 founded in vector.\n";
    cout << "Using functions isGreater_3 on vector_9 and isGreater_4 on vector_10.\n";
    if (isGreater_3(v9)) cout << "Founded elements greater than 7.\n"; else
        cout << "No elements greater than 7 founded in vector.\n";
    if (isGreater_4(v10)) cout << "Founded elements greater than 7.\n"; else
        cout << "No elements greater than 7 founded in vector.\n";
    Greater_4* cPtr1 = new Greater_4(3);
    delete cPtr1;
    // Task 1.11. A litle strange, but works fine.
    Class_2 cl1;
    Class_3<Class_2> cl2;
    cl2.function(&cl1);
    Class_4<Class_2> cl3;
    Class_5<Class_2> cl4;
    Class_6<Class_2> cl5;
    Class_8< Class_6<Class_2> > cl6;
    Class_10<Class_6 <Class_2> > cl7;
    Class_11<Class_2, Greater_1> cl8;
    Class_13<Class_2> cl9;
    Class_14<Class_2> cl10;
    Class_14a cl11;
    Class_14a* ptr = Class_14<Class_2>::function(&cl11);
    // Task 1.12.
    function_1(Class_16a::cl());
    function_1(Class_16b<Class_16a>::clB());
    // Task 1.13.
    vector<char> v;
    char* ptr1 = &v[0];
    function_2<vector<char>>(v);
    // Task 1.14.
    const int maxVectorSize = 5;
    int vector9[maxVectorSize] = { 1, 2, 3, 4, 5 };
    cout << "All elements in vector 9: " ;
    for (int i = 0; i < maxVectorSize; i++) cout << vector9[i] << " ";
    cout << "\nPosition of key '3' in vector 9: " << findKey(3, vector9, maxVectorSize) << endl;
    vector<int> vector10 = { 1, 2, 3, 4, 5 };
    cout << "Position of key '4' in vector 10: " << findKey(4, &vector10[0], maxVectorSize) << endl;
    vector<int> vector11(256);
    cout << "Size and capacity of vector 11 are " << vector11.size() << " " << vector11.capacity() << endl;
    vector11.erase(vector11.begin() + 128, vector11.end());
    cout << "After erase last 128 elements in vector 11, size and capacity are "
         << vector11.size() << " " << vector11.capacity() << endl;
    vector11.reserve(128);
    cout << "After reserve 128 elements in vector 11, size and capacity are "
         << vector11.size() << " " << vector11.capacity() << endl;
    vector11.shrink_to_fit();
    cout << "Using new method from standard, size and capacity "
         << vector11.size() << " " << vector11.capacity() << endl;
    // Task 1.15.
    map<int, string> map1 = {{1, "one"}, {2, "two"}, {3, "three"}};
    map<int, string>::iterator it1 = map1.find(1);
    if ( it1 != map1.end() ) const_cast<int&>(it1->first) = 5;
    cout << "Finding '5' at map 1, after replacement with cast " << map1[5] << endl;
    it1 = map1.find(3);
    if (it1 != map1.end()) {
        map1.erase(it1);
        map1.insert(make_pair(4, "four"));
    }
    cout << "Finding '4' at map 1, after replacment with erase/insert methods " << map1[4] << endl;
    // Task 1.16. Quick example.
    Class_17 cl12;
    int i2 = function_2(cl12);
    cout << "Result of function_2 is " << i2 << endl;
    // Task 1.17. Multiply calls for one overloaded function.
    double d1 = 0.5;
    float f1 = 0.3;
    complex<double> c1;
    cout << "Calling function_3() with various templates.\n";
    function_3(i2);
    function_3<int>(i2);
    function_3(i2, i2);
    function_3(c1);
    function_3(i2, f1);
    function_3(i2, d1);
    function_3(c1, &c1);
    function_3(i2, &d1);
    function_3(&d1, d1);
    function_3(&d1);
    function_3(d1, &d1);
    function_3(&i2, &i2);
}

void Labs_0x05::chapter_02()
{
    cout << "Chapter's 2 tasks.\n";
    // Task 2.1-10. One classic example, try to recompile later with c++17.
    Stack<int> stack1(5), stack2(5);
    stack1.push(1);
    stack1.push(2);
    stack1.push(3);
    cout << "Elements in stack<int> " << stack1.count() << ", values ";
    for (int i = 0; !stack1.empty(); i++) {
        cout << stack1.top() << " ";
        stack1.pop();
    }
    cout << endl;
    if ( stack1.empty() ) cout << "Stack is empty.\n"; else
        cout << "Stack is still contains some elements.\n";
    stack1.push(1);
    stack1.push(2);
    stack2.push(3);
    stack2.push(4);
    cout << "Stack 1 elements: ";
    stack1.print();
    cout<< "\nStack 2 elements: ";
    stack2.print();
    cout << "\nSwap stacks.\n" << "Stack 1 elements: ";
    stack1.swapStack(stack2);
    stack1.print();
    cout << "\nStack 2 elements: ";
    stack2.print();
    cout << endl;

}

void labs_0x05()
{
    cout << "Starting Labs_0x05." << endl;
    Labs_0x05::chapter_02();
}
