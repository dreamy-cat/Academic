#ifndef LIBRARY_H
#define LIBRARY_H

// Global defines using in all chapters of book.

#define STRING_MAX 256
#define OBJECTS_MAX 256
#define TAB 8

// Библиотечные функции, которые были написаны нами в процессе и использовались для всех частей теории и практики.

double a_power_n(double a, int n);

unsigned short int bits_multiply(unsigned char byte_1, unsigned char byte_2);

void calculate_expr_1(void);

void digits_total(int a);

int factorial(int n);

void n_power_2(int a);

int n_power_3(int n);

void print_binary_byte(unsigned char byte);

int reverse_integer(int a);

int simple_multiply(int x, int y);

double summ_seq_fact(int n);

#endif  // LIBRARY_H
