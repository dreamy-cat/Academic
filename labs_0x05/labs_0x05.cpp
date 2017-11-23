#include "labs_0x05.hpp"

using namespace std;

void Labs_0x05::chapter_01()
{
    cout << "Chapter's 1 tasks.\n";
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
    // Task 1.18. A litle different from source.
    TerminalHacked(4, 7);
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
    // Tasks 2.11-12. Just theory and quick try.
    function_4("string");
    // Tasks 2.13-14. Not seen much of this examples in real.
    // Class_2_3 cl1(true);
    Class_2_3 cl2(false);       // No exception.
    // Class_2_4 cl3(true);
    Class_2_4 cl4(false);
    // Task 2.15. Example one with throw() in destructor not compile since c++11 standard.
    Class_2_5 cl5;
    Class_2_7 cl6;
    // Task 2.16-17. 'auto_ptr' depricated since c++11 and removed from c++17.
    cout << "Result of simple multyply is " << function_5(3, 5) << endl;
    cout << "Calling with two additional function, result " << function_5(function_5_1(1, 2), function_5_2(5, 0)) << endl;
    cout << "Calling function with operator new in arguments, result " << function_5_3(new int(3), new int(5)) << endl;
    // Task 2.18-19. In task 19, simple classes declarations.
    Widget cl7('a', 'b'), cl8('c', 'd');
    cout << "Widget 1 values ";
    cl7.print();
    cout << "\nWidget 2 values ";
    cl8.print();
    cout << endl;
    cl8 = cl7;
    cout << "Widget 2 after operator=() values ";
    cl8.print();
    cout << endl;
}

void Labs_0x05::chapter_03()
{
    cout << "Chapter's 3, tasks.\n";
    // Task 3.1 Some simple tries.
    Complex c1(1, 0), c2(2, 5);
    cout << "Two complex numbers and result of operator+=().\n" << c1 << c2;
    c1 += c2;
    cout << c1 << "Result of operator++().\n" << ++c1;
    cout << "Result of operator+().\n" << c1 + c2;
    // Task 3.2. Some simple calls, must be careful.
    Class_3_2 cl1;
    Class_3_2_1 cl2;
    Class_3_2* ptr1 = new Class_3_2_1;
    cl1.function_1(1.0);
    cl2.function_1(1.0);
    ptr1->function_1(1.0);
    cl1.function_2();
    cl2.function_2();
    ptr1->function_2();
    delete ptr1;
    // Task 3.3-3.4. First example not using properly with inheritance.
    Class_3_3 cl3;
    vector<string> v1;
    cout << "Class_3_3:: process() returned " << cl3.process(v1) << endl;
    // Task 3.5. See .h file, just some declarations about inheritance.
    // Task 3.6. Theoretical task, language is multi-paradigm.
    // Task 3.7. Multiple inheritance.
    // Task 3.8. Works, but only in if all methods in class defined in header file, and not as expected.
    Class_3_D cl4;
    Class_3_B* ptr2 = &cl4;
    Class_3_C* ptr3 = &cl4;
    Class_3_B& ref1 = cl4;
    Class_3_C& ref2 = cl4;
    function_3_1("Function_1(Class_3_A&), ", cl4);
    function_3_2("Function_2(Class_3_B&), ", cl4);
    function_3_3("Function_3(Class_3_C&), ", cl4);
    cout << "After first three calls.\n";
    function_3_1("Function_1(Class_3_A&), ", cl4);
    function_3_2("Function_2(Class_3_B&), ", cl4);
    function_3_3("Function_3(Class_3_C&), ", cl4);
    cout << "Trying to use dynmical casting for pointers Classes_3_B and Class_3_C: ";
    cout << ((dynamic_cast<Class_3_D*>(ptr2) != 0) ? "Ok." : "Not ok.") << " ";
    cout << ((dynamic_cast<Class_3_D*>(ptr3) != 0) ? "Ok." : "Not ok.") << endl;;
    cout << "Trying with exceptions: ";
    try {
        dynamic_cast<Class_3_D&>(ref1);
        cout << "Ok. ";
    } catch (...) {
        cout << "Not ok. ";
    }
    try {
        dynamic_cast<Class_3_D&>(ref2);
        cout << "Ok.\n";
    } catch (...) {
        cout << "Not ok.\n";
    }
    // Task 3.9. Not working as it should be, rethink.
    cout << "All calls of derived, base and base classes.\n";
    Derived_3_9A cl5;
    Base_3_9A* ptr4 = &cl5;
    Base_3_9B* ptr5 = &cl5;
    cl5.function();
    ptr4->function();
    ptr5->function();
    cout << "Imitation of multiple inheritance and calls functions.\n";
    Derived_3_9B cl6;
    Base_3_9A* ptr6 = &cl6;
    Base_3_9B* ptr7 = &cl6;
    ptr6->function();
    ptr7->function();
    // Task 3.10. Just some examples, gcc works fine and private virtual function don't called.
    cout << "Some examples with pure virtual functions.\n";
    Derived_3_10 cl7;
    cl7.function();
    Base_3_10* ptr8 = &cl7;
    // ptr8->function_1();
    // Task 3.11. Using private with base class to prevent from this.
    function_3_4(*ptr8);
}

void Labs_0x05::chapter_04()
{
    cout << "Chapter's 4 tasks.\n";
    // Tasks 4.1-4.3. Useful in complicated projects, in other case not, see .hpp file.
    // Task 4.4. Just a question, implementation pointer better contains non virtual private memebers.
    // Task 4.5. Works fine, but more theory, using pImpl, don't reinterpret.
    Class_4_5B cl1;
}

void labs_0x05()
{
    cout << "Starting Labs_0x05.\n";
    Labs_0x05::chapter_04();
}
