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

void setInt(void* ptr, int n, int value) {
    int* elem = static_cast<int*>(ptr);
    for (int i = 0; i < n; i++) *elem++ = value;
}

void outDoubleArray(double* ptr, int size) {
    cout << "Double array: ";
    for (int i = 0; i < size; i++) cout << *ptr++ << " ";
    cout << endl;
}

void outDoubleBinary(double d) {
    unsigned char* ptr = (unsigned char*)&d;
    string bits;
    unsigned char mask;
    cout << "Double parts of " << d << ":\n";
    for (int i = 0; i < 6; i++) {
        bits += toBinary(*ptr++) + " ";
    }
    bits += toBinary(*ptr & 0x0F);
    cout << "Fraction = " << bits << endl;
    bits.clear();
    mask = 0xF0;
    bits += toBinary(((*ptr & mask) >> 4) | ((*(ptr+1) & 0x0F) << 4) ) + " ";
    bits += toBinary(*(++ptr) & 0x07);
    cout << "Exponent: " << bits << endl;
    mask = 0x80;
    bits.clear();
    bits += toBinary( (*ptr & mask) >> 7 );
    cout << "Sign: " << bits << endl;
}
