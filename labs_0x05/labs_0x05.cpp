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
}

void labs_0x05()
{
    cout << "Starting Labs_0x05." << endl;
    Labs_0x05::chapter_01();
}
