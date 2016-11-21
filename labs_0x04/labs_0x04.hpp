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
#include <set>

void labs_0x04();

namespace Labs_0x04 {

void chapter_1();
void chapter_2();
void chapter_3();
void chapter_4();
void chapter_5();
void chapter_6();

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

class Class10 : public std::enable_shared_from_this<Class10> {
public:
    Class10();
    void function1() const;
    virtual ~Class10() = default;
private:
    std::vector<std::shared_ptr<Class10>> v;
};

class Class10_1 : public Class10 {};

class Class10_2 : public Class10 {};

class Class10_3 : public Class10 {};

template<typename T> std::unique_ptr<Class10> factory1(T&& p)
{
    return std::unique_ptr<Class10>(new Class10);
}

auto delClass10 = [](Class10* ptr)
{
    std::cout << "Calling custom delete for unique<Class10, decltype()>." << std::endl;
    delete ptr;
};

template<typename T> std::unique_ptr<Class10, decltype(delClass10)> factory2(T&& p)
{
    std::unique_ptr<Class10, decltype(delClass10)> ptr(nullptr, delClass10);
    ptr.reset(new Class10());
    return ptr;
}

auto delClass10_1 = [](Class10* ptr)
{
    std::cout << "Second custom deleter for Class10." << std::endl;
    delete ptr;
};

auto delClass10_2 = [](Class10* ptr)
{
    std::cout << "Third custom deleter for Class10." << std::endl;
    delete ptr;
};

std::unique_ptr<const Class10> factory3(int id);

std::shared_ptr<const Class10> factory4(int id);

template<typename T, typename... Ts> std::unique_ptr<T> makeUnique(Ts&&... p)
{
    // Compile with c++11
    return std::unique_ptr<T>(new T(std::forward<Ts>(p)...));
}

void function15(std::shared_ptr<int> sp, int p);

class Class12;

class Class11 {
public:
    Class11();
    Class11(const Class11& r);
    Class11& operator=(const Class11& r);
    ~Class11();
    Class11(Class11&& r);
    Class11& operator=(Class11&& r);
private:
    std::unique_ptr<Class12> impl;
    std::shared_ptr<Class12> impl2;
};

class Class12 {
public:
    std::string name;
    std::vector<double> data;
};

template<typename T>
typename std::remove_reference<T>::type&& move1(T&& param)
{
    return static_cast<typename std::remove_reference<T>::type&&>(param);
}

template<typename T>
decltype(auto) move2(T&& param)
{
    return static_cast<std::remove_reference_t<T>&&>(param);
}

class Class13 {
public:
    explicit Class13(const std::string text);
    Class13(Class13&& r);
    Class13(const Class13& lv);

    template<typename T>
    void setValue(T&& newValue)
    {
        std::cout << "Setting value of string to " << newValue << std::endl;
        value = std::forward<T>(newValue);
    }

    std::string getValue() const;

    template<typename T>
    void function_1(T&& value)
    {
        std::cout << "Setting string value from Class13::function_1." << std::endl;
        setValue(value);
        std::forward<T>(value);
    }

    Class13 operator+(const Class13& rv);

    template<typename T>
    Class13 function_2(T&& v)
    {
        std::cout << "Class13::function_1()." << std::endl;
        return std::forward<T>(v);
    }

private:
    std::string value;
    static std::size_t moveCounter;
    std::shared_ptr<int> ptr;
};



void function_16(const Class13& lv);

void function_16(Class13&& rv);

template<typename T>
void function_17(T&& parameter)
{
    auto now = std::chrono::system_clock::now();
    std::cout << "Function_17 has called." << std::endl;
    function_16(std::forward<T>(parameter));
}

template<typename T>
void function_18(std::vector<T>&& parameter) {}

Class13 function_19();

static int counterFunc20 = 0;

template<typename T>
void function_20(T&& name, std::multiset<std::string>& data)
{
    std::cout << counterFunc20++ << ": " << name << std::endl;
    data.emplace(std::forward<T>(name));
}

void function_20(int index, std::multiset<std::string>& data);

std::string function_21(int index, std::multiset<std::string>& data);

class Class14 {
public:
    template<typename T>
    explicit Class14(T&& n) : name(std::forward<T>(n))
    {
        std::cout << "Class14 constructor with parameter " << name << std::endl;
    }

    explicit Class14(int index, std::multiset<std::string>& data) : name (function_21(index, data))
    {
        std::cout << "Class14 constructor(index) with string " << name << std::endl;
    }

    Class14(const Class14& r) = default;
    Class14(Class14&& r) = default;
private:
    std::string name;
};

class Class14_1 : public Class14 {
public:
    Class14_1(const Class14_1& r);
    Class14_1(Class14_1&& r);
};

class Class15 {
public:
    template<typename T, typename = std::enable_if_t<
                 !std::is_base_of<Class15, typename std::decay<T>::type>::value &&
                 !std::is_integral<std::remove_reference_t<T>>::value>
             >
    explicit Class15(T&& n) : name(std::forward<T>(n))
    {
        static_assert(std::is_constructible<std::string, T>::value,
                      "Cannot construct std::string from value.");
        std::cout << "Class15(T&&)" << std::endl;
    }

    explicit Class15(std::string n);
    explicit Class15(int index);
private:
    std::string name;
};

class Class15_1 : public Class15 {
public:
    Class15_1(const Class15_1& r);
    Class15_1(Class15_1&& r);
};

template<typename T>
void function_22(T&& name, std::false_type)
{
    std::cout << "Function22(T&&, std::false_type), name is " << name << std::endl;
}

void function_22(int index, std::true_type);

template<typename T>
void function_23(T&& name)
{
    function_22(std::forward<T>(name), std::is_integral<std::remove_reference_t<T>>());
}

class Class16 {
public:
    Class16();
    static constexpr std::size_t minValue = 5;
};

Class16 function_24();

void function_25(Class16 p);

template<typename T>
void function_26(T&& param)
{
    std::cout << "Function_25(T&&), " << typeid(param).name() << std::endl;
    function_25(std::forward<T>(param));
}

void function_27(const std::vector<int>& v);

void function_27(int (*pf)(int));

void function_27(std::size_t s);

template<typename T>
void function_28(T&& parameter)
{
    function_27(std::forward<T>(parameter));
}

int function_29(int p);

int function_29(int p, int q);

template<typename T>
int function_30(T p)
{
    std::cout << "Template function_30(T), with type " << typeid(p).name() << std::endl;
}

struct Struct1 {
    std::uint32_t v:4, i:4, d:6, e:2, t:16;
};

void function_31(std::vector<std::function<bool(int)>>& v);

template<typename T>
void function_32(const T& container)
{
    auto divValue = 3;
    using elementType = typename T::value_type;
    if (std::all_of(std::begin(container), std::end(container),
                    [&](const elementType& value){ return value & divValue == 0; } ))
        std::cout << "Result of std::all_of algorithm." << std::endl;
    else
        std::cout << "Result of std::all_of algorithm, non founded." << std::endl;
}

class Class17 {
public:
    Class17() = default;
    void addFilter(std::vector<std::function<bool(int)>>& v);
    bool function1();
    bool function2();
private:
    int divValue;
};

class Class17_1 {
public:
    explicit Class17_1(std::unique_ptr<Class17>&& p);
    bool operator()() const;
private:
    std::unique_ptr<Class17> ptr;
};

#endif
