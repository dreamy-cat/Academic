#include <iostream>

#include "chapter_03.h"

using namespace std;

void function_1 (void* ptr) {
    std::cout << "Function 1 has called. Return void." << endl;
}

char function_2 (char c) {
    std::cout << "Function 2 with argument char = '"  << c << "' has called. Return char++." << endl;
    return (++c);
}

int function_3 (int i) {
    std::cout << "Function 3 with argument int = " << i << " has called. Return integer++." << endl;
    return (++i);
}

float function_4 (float f) {
    std::cout << "Function 4 with argument float = " << f << " has called. Return float+1." << endl;
    return (f+1);
}
