#include "chapter_05.h"

using namespace std;

template<> void function_5_1(const int& value) {
    std::cout << "Template int function_5_1()." << std::endl;
}

void function_5_1(const int& value) {
    std::cout << "Overloaded function_5_1()." << std::endl;
}

int function_5_5(int a[], int first, int last, int source) {
    int sum = source;
    cout << "[<int> specialization] ";
    for (int i = first; i <= last; i++)
        sum += a[i];
    return sum;
}

double function_5_5(double a[], int first, int last, double source) {
    double sum = source;
    cout << "[<doube> specialization] ";
    for (int i = first; i <= last; i++)
        sum += a[i];
    return sum;
}
