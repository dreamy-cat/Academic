#include "chapter_05.h"

using namespace std;

template<> void function_5_1(const int& value) {
    std::cout << "Template int function_5_1()." << std::endl;
}

void function_5_1(const int& value) {
    std::cout << "Overloaded function_5_1()." << std::endl;
}

