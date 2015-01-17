#include <iostream>
#include <string>

#include "chapter_04.h"

using namespace std;

void structure_4_1::function_1(structure_4_1 *strucPtr, int m) {
    strucPtr->n = m;
}

void structure_4_1::function_2(structure_4_1 *strucPtr) {
    cout << "Structure_4_2::Function_1 has called. N = " << strucPtr->n << endl;
}

// Task 6.

class_4_1::class_4_1() {
    s = "chapter_04";
    cout << "String from class_4_1 = " << this->s << endl;
}
