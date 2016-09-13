#ifndef LABS_0x04_HPP
#define LABS_0x04_HPP

#include <iostream>
#include <vector>
#include <string>
#include <typeinfo>
#include <iterator>

void labs_0x04();

namespace Labs_0x04 {

void chapter_1();

template<typename T>
void function_1(T& parameter)
{
    std::cout << "function_1(T& parameter) called. Parameter type " << typeid(parameter).name() << ", value " << parameter << std::endl;
}

template<typename T>
void function_2(const T& parameter)
{
    std::cout << "function_2(const T& parameter) called. Parameter type " << typeid(parameter).name() << ", value " << parameter << std::endl;
}

template<typename T>
void function_3(T* parameter) {
    std::cout << "function_3(T* parameter) called. Parameter type " << typeid(parameter).name() << ", value " << *parameter << std::endl;
}

template<typename T>
void function_4(T&& parameter) {
    std::cout << "function_4(T&& parameter) called. Parameter type " << typeid(parameter).name() << ", value " << parameter << std::endl;
}

template<typename T>
void function_5(T parameter) {
    std::cout << "function_5(T parameter) called. Parameter type " << typeid(parameter).name() << ", value " << parameter << std::endl;
}

template<typename T, std::size_t N> constexpr std::size_t sizeArray(T (&)[N]) noexcept { return N; }

template<typename T>
void function_6(T& parameter) {
    std::cout << "function_6(T& parameter) called. Parameter type " << typeid(parameter).name() << ", value " << parameter << std::endl;
}

template<typename Container, typename Idx>
auto access(Container& c, Idx i) -> decltype(c[i]) {
    return c[i];
}

template<typename Container, typename Idx>
auto accessDeclare(Container&& c, Idx i) -> decltype((c)[i]) {
    return c[i];
}

template<typename Container, typename Idx>
decltype(auto) accessDeclareAuto(Container& c, Idx i) {
    return c[i];
}

template<typename T> class Class1;

template<typename T> void function_7(const T& parameter) {
    std::cout << "Template name " << typeid(T).name() << ", parameter type " << typeid(parameter).name() << ", value " << parameter << std::endl;
}

std::vector<int> createVector(const int vSize);

}

#endif
