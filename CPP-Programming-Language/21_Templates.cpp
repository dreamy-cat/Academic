#include "21_Templates.hpp"

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

void chapter_21() {
    cout << "Chapter's 5 tasks.\n";
    // Task 1.
    const char c_1 = 'a';
    function_5_1<const char>(c_1);
    function_5_1<int>(2);
    function_5_1(3);
    // Task 2.
    // Recheck.
    Stack_A<int> st_5;
    st_5.push(1);
    cout << "Value from Stack_5: " << st_5.pop() << endl;
    // Task 3.
    Stack_B<int, Stack_A > st_2;
    st_2.push(1);
    cout << "Value from Stack_5_1: " << st_2.pop() << endl;
    // Task 4. No match for 'operator==', may be not as planned.
    // Task 5. Try char.
    char string_5[4] = { 1, 2, 3, 4 };
    cout << "Sum of char (1, 2, 3, 4) = " << (int)function_5_5<char>(string_5, 0, 3, 0) << endl;
    // Task 6.
    int array_1[] = { 1, 2, 3, 4};
    double array_2[] = { 1.0, 2.0, 3.0, 4.0 };
    cout << "Sum of int (1, 2, 3, 4) in overloaded function: " << function_5_5(array_1, 0, 3, int(0)) << endl;
    cout << "Sum of double (1, 2, 3, 4) in overloaded function: " << function_5_5(array_2, 0, 3, double(0)) << endl;
    // Task 7.
    Class_5_B<int> cl_1;
    Class_5_B<Friendly> cl_2, cl_3;
    // 'int Class_5_2<Friendly>::i' is private.
    // cl_1.play(cl_3);
    cl_2.play(cl_3);
    p_ag(1, 2, 3);
    p_ag(1.0, 2.0, 3.0);
    // no matching for call to 'p_ag(int, double, double)'
    // p_ag(1, 2.0, 3.0);
    cout << "Result of function 'p_ag': " << p_ag<double>(1, 2.0, 3.0) << endl;
    // Task 8. See in .h file.
    // Task 9.
    Class_5_E<int, char> cl_4;
    Class_5_E<char, int> cl_5;
    Class_5_E<char, char> cl_6;
    cl_4.function_1();
    cl_5.function_1();
    cl_6.function_1();
    // Task 10. Strange, works but seems not usable in practice.
    Class_5_F<char> cl_7;
    Class_5_F<int> cl_8;
    cl_7.functionCalls();
    cl_8.functionCalls();
}
