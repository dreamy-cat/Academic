#include "labs_0x05.hpp"

using namespace std;

void Labs_0x05::chapter_01()
{
    cout << "Chapter's 1, tasks.\n";
    vector<int> v1(3, 1), v2(3, 2);
    copy(v1.begin(), v2.begin(), back_inserter(v1));
    String1 s1;
}

void labs_0x05()
{
    cout << "Starting Labs_0x05." << endl;
    Labs_0x05::chapter_01();
}
