﻿#ifndef PART_03
#define PART_03

// Глава 3. Заголовочный файл.

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

// Task 1.

void function_3_1 (void* ptr = 0);
char function_3_2 (char c);
int function_3_3 (int i);
float function_3_4 (float f);

// Task 7.

void function_3_5(std::string* str);
void function_3_6(std::string& str);

// Task 9.

void function_3_7();

// Task 10.

namespace Labs_0x01 {

static int fs;

}

// Task 12.

std::string toBinary(unsigned char n);
void rolByte(unsigned char& n);
void rorByte(unsigned char& n);

// Task 15.

typedef struct struct_3_1 {
    std::string s1,s2;
    int n;
} struct_3_1;

//Task 16.

enum colors {red, green, blue};

// Task 17.

union union_3_1 {
    int i;
    char c;
    double d;
};

// Task 20.

typedef struct {
    int i, j, k;
} point_3_20;

// Task 23.

typedef union {
    int i;
    char c;
    float f;
} primitiv_3_23;

// Task 26.

void setInt(void* ptr, int n, int value);

// Task 28.

void outDoubleArray(double* ptr, int size);

// Task 29.

void outDoubleBinary(double d);

// Task 31.

#define DEBUG

// Task 32.

int function_3_8(double d);

// Task 33.

float (*function_3_9(int n))(char d);
float function_3_10(char c);

// Task 34.

std::string function_3_11();
std::string function_3_12();
std::string function_3_13();

#endif
