#include <iostream>

#include "chapter_03.h"

using namespace std;

void function_3_1 (void* ptr) {
    std::cout << "Function 1 has called. Return void." << endl;
}

char function_3_2 (char c) {
    std::cout << "Function 2 with argument char = '"  << c << "' has called. Return char++." << endl;
    return (++c);
}

int function_3_3 (int i) {
    std::cout << "Function 3 with argument int = " << i << " has called. Return integer++." << endl;
    return (++i);
}

float function_3_4 (float f) {
    std::cout << "Function 4 with argument float = " << f << " has called. Return float+1." << endl;
    return (f+1);
}

void function_3_5(string *str) {
    *str += "function_5";
}

void function_3_6(string &str) {
    str += "function_6";
}

void function_3_7() {
    static int i = 0;
    cout << "Function 7. i = " << ++i << endl;
}

string toBinary (unsigned char n) {
    string r;
    r.resize(8,'0');
    for (int i = 0; i < 8 && n > 0; i++) {
        if (n % 2) r[7-i] = '1';
        n = n >> 1;
    }
    return r;
}

void rolByte (unsigned char& n) {
    if (n & 0x80) n = (n << 1) + 1; else n = n << 1;
}

void rorByte (unsigned char& n) {
    if (n & 0x01) n = (n >> 1) + 0x80; else n = n >> 1;
}
