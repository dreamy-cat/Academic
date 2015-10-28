#include <iostream>
#include <errno.h>
#include <signal.h>

#include "labs_0x02.h"
#include "chapter_01.h"

using namespace std;

void chapter_01() {
    cout << "Chapter's 1. Tasks.\n";
    // Task 1.
    cout << "Function 01 returns " << function_01_1() << ".\n";
    function_01_2();
    std::cout << "Function 02, errno = " << errno << ".\n";
    signal(SIGINT, function_01_3);
    raise(SIGINT);
    try {
        function_01_4();
    } catch (int) {
        cout << "Catch exception from function 04.\n";
    }
    // Task 2.
    Class_01_1 class_1;
    try {
        class_1.function_1();
    } catch (Class_01_1::Class_1 cl) {
        cout << "Catch exception from function_1, Class_01_1. String = " << cl.str << "\n";
    }
    // Task 3-4.
    PStash_1 stash;
    const char string_1[] = "ABC";
    try {
        cout << "All objects in stash: ";
        for (int i = 0; i < 3; i++) {
            stash.add((void*)&string_1[i]);
            cout << *((char*)stash[i]) << " ";
        }
        cout << endl;
        for (int i = 0; i < 3; i++) stash.remove(i);
        cout << *((char*)stash[5]) << " ";
    } catch(out_of_range m) {
        cout << "Exception from PStash_1: " << m.what() << endl;
    } catch(invalid_argument m) {
        cout << "Exception from PStash_1: " << m.what() << endl;
    }
    // Task 5. 'terminate', think about it later...
    Class_1_5* ptrs_1[] = { NULL, NULL, NULL, NULL, NULL };
    int i, j = 0;
    for (i = 0; i < 3; i++) ptrs_1[i] = new Class_1_5;
    for ( ; i < 5; i++) {
        try {
            ptrs_1[i] = new Class_1_5;
        } catch (bad_alloc) {
            cout << "Exception from Class_1_5::operator new: " << " trying to free some space." << endl;
            delete (ptrs_1[j++]);
        }
    }

}

void labs_0x02() {

    chapter_01();
}

