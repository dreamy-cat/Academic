#include "labs_0x03.hpp"
#include "chapter_01.hpp"

using namespace std;
using namespace Labs_0x03;

void Labs_0x03::chapter_01()
{
    cout << "Labs_0x03, chapter's 1 tasks.\n";
    vector<int> v1 = { 0, 2, 1, 4, 2, 5, 3, 6, 0, 4, 6, 0, 1, 3 };
    cout << "Basic connectivity tasks, source vector: ";
    for (size_t i = 0; i < v1.size(); i++) {
        cout << v1[i];
        if (i % 2 == 0) cout << "-"; else cout << " ";
    }
    cout << "\nResult as is: 0-2 1-4 2-5 3-6 0-4 6-0 1-4-0-6-3\n";
    vector<int> v2 = { 3, 4, 4, 9, 8, 0, 2, 3, 5, 6, 2, 9, 5, 9, 7, 3, 4, 8, 5, 6, 0, 2, 6, 1 };
    cout << "Source second vector of pairs: ";
    for (size_t i = 0; i < v2.size(); i++) {
        cout << v2[i];
        if (i % 2 == 0) cout << "-"; else cout << " ";
    }
    cout << "\nAdditional variants for all posible connects: ";
    cout << "3-4 4-9 8-0 2-3 5-6 2-3-4-9[2-0-8-4-9] 5-9 7-3 4-8 5-6 0-8-4-3-2 6-1\n";
    cout << "Using simple counter for both operations, later.\n\n";
    const int maxSize = 1024;
    vector<int> v3(maxSize);
    for (size_t i = 0; i < v2.size(); i++) {
    }
}

void labs_0x03()
{
    Labs_0x03::chapter_01();
}
