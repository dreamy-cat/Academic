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
#include <algorithm>

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

class Class6 {
public:
    virtual void function1() const;
    virtual void function2(int i);
    virtual void function3() &;
    virtual void function4() const;
};

class Class6_1 : public Class6 {
public:
    virtual void function1() const override;
    virtual void function2(int i) override;
    virtual void function3() & override;
    virtual void function4() const override;
};

class Class7 {
public:
    Class7();
    Class7 create();
    std::vector<int>& data() &;
    std::vector<int>&&  data() &&;
private:
    std::vector<int> v;
};

template<typename C, typename V> void findIns(C& container, const V& element1, const V& element2)
{
    auto it = std::find(std::cbegin(container), std::cend(container), element1);
    container.insert(it, element2);
}

int function_13() throw();

int function_14() noexcept;

class Class8 {
private:
    static int constructor;
    static int copyConstructor;
public:
    Class8();
    Class8(const Class8&);
    static void printCounters();
};

constexpr int pow(int base, int exp);

class Point {
public:
    constexpr Point(double iX = 0, double iY = 0) noexcept;
    constexpr double xValue() const noexcept;
    constexpr double yValue() const noexcept;
    constexpr void setX(double sX) noexcept;
    constexpr void setY(double sY) noexcept;
private:
    double x, y;
};

constexpr Point middlePoint(const Point& p1, const Point& p2) noexcept;

constexpr Point reflection(const Point& p) noexcept;

class Polynom {
public:
    std::vector<double> roots() const;
private:
    mutable std::mutex m;
    mutable bool isValid{};
    mutable std::vector<double> rootVals{};
};

class Class9 {
public:
    Class9();
    Class9(const Class9&) = default;
    Class9& operator=(const Class9&) = default;
    template<typename T> Class9(const T&);
    template<typename T> Class9& operator=(const T& r);
    Class9(Class9&& r) = default;
    Class9& operator=(Class9&& r);
    virtual ~Class9() = default;
};

#endif
