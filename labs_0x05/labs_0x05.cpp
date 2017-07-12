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
}

void labs_0x05()
{
    cout << "Starting Labs_0x05." << endl;
    Labs_0x05::chapter_01();
}
