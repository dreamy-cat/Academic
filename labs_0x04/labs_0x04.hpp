#ifndef LABS_0x04_HPP
#define LABS_0x04_HPP

#include <iostream>
#include <vector>
#include <string>
#include <typeinfo>
#include <iterator>
#include <memory>
#include <functional>
#include <mutex>
#include <unordered_map>
#include <list>
#include <type_traits>

void labs_0x04();

namespace Labs_0x04 {

void chapter_1();
void chapter_2();
void chapter_3();

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

template<typename It> void function_8(It a, It b) {
    while ( a != b) typename std::iterator_traits<It>::value_type value = *a;
    while ( a != b) auto value = *a;
}

class Class2
{
public:
    Class2() {
        std::cout << "Class2 constructor." << std::endl;
    }
    Class2(int i, bool b) {
        std::cout << "Class2 constructor with integer and bool(" << i << "," << b << ")." << std::endl;
    }
    Class2(int i, float f) {
        std::cout << "Class2 constructor with integer and float(" << i << "," << f << ")." << std::endl;
    }
    Class2(std::initializer_list<std::string> i1) {
        std::cout << "Class2 constructor with std::initializer_list<std::string>." << std::endl;
    }
    Class2(const Class2&) {
        std::cout << "Class2 copy constructor." << std::endl;
    }
    Class2& operator=(Class2&) {
        std::cout << "Class2 operator=()." << std::endl;
        return *this;
    }
private:
    int i1 { 1 };
    int i2 = 2;
    // int i3(3);
};

void function_9(int i);

void function_9(bool b);

void function_9(void* ptr);

int function_10(std::shared_ptr<Class2> ptr);

double function_11(std::unique_ptr<Class2> ptr);

bool function_12(Class2* ptr);

template<typename FT, typename MT, typename PT>
decltype(auto) getResult(FT function, MT& mutex, PT ptr)
{
    std::lock_guard<MT> g(mutex);
    return function(ptr);
}

typedef void(*FP)(int, const std::string&);

using FP = void (*)(int, const std::string&);

template<typename T> using List1 = std::list<T, std::allocator<T>>;     // Using 'using'...

template<typename T> struct List2 {
    typedef std::list<T, std::allocator<T>> type;
};

template<typename T> class Class3 {
private:
    typename List2<T>::type list;
};

template<typename T> using List1 = std::list<T, std::allocator<T>>;

template<typename T> class Class4 {
private:
    List1<T> list;
};

template<typename E> constexpr auto toInfoType(E enumerator) noexcept {
    return static_cast<std::underlying_type_t<E>>(enumerator);
}

class Class5 {
public:
    Class5();
    Class5(const Class5&) = delete;
    template<typename T> bool isLucky(T number);
    bool isLucky(char) = delete;
};

#endif
