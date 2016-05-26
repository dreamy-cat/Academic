#ifndef L_02_CHAPTER_07_H
#define L_02_CHAPTER_07_H

#include <iostream>
#include <algorithm>
#include <list>
#include <stack>
#include <vector>

class Noisy {
public:
    Noisy();
    ~Noisy();
    Noisy(const Noisy& rv);
    Noisy& operator=(const Noisy& rv);
    static void report();
    friend bool operator<(const Noisy& lv, const Noisy& rv);
    friend bool operator==(const Noisy& lv, const Noisy& rv);
    friend std::ostream& operator<<(std::ostream& os, const Noisy& value);
private:
    int id;
    static int create, assign, copyCons, destroy;
};

template<typename T>
void function_7_2(T v) {
    std::cout << "Sorting vector and deque, container size " << v.size() << std::endl;
    std::sort(v.begin(), v.end());
}

void function_7_2(std::list<Noisy> v);

class Shape {
public:
    virtual void draw() = 0;
    virtual ~Shape();
};

class Circle : public Shape {
public:
    void draw();
    ~Circle();
};

class Triangle : public Shape {
public:
    void draw();
    ~Triangle();
};

class Square : public Shape {
public:
    void draw();
    ~Square();
};

void printStack(std::stack<int>& s, std::string name);

void sortStack(std::stack<int>& source, std::stack<int>& sorted, std::stack<int>& tail);

class Class_7_11 {
public:
    Class_7_11();
    int priority;
    friend bool operator<(const Class_7_11& lv, const Class_7_11& rv);
    friend std::ostream& operator<<(std::ostream& os, const Class_7_11& value);
};

template<typename E, template < class T1, class Alloc = std::allocator<T1> > class T > class Ring {
public:
    class iterator;
    friend class iterator;
    class iterator : public std::iterator<std::bidirectional_iterator_tag, T<E>, std::ptrdiff_t> {
    private:
        typename T<E>::iterator it;
        T<E>*  r;
    public:
        iterator(T<E>& lst, const typename T<E>::iterator& i) : r(&lst), it(i) {}

        bool operator==(const iterator& x) const {
            return (it == x.it);
        }

        bool operator!=(const iterator& x) const {
            return !(*this == x.it);
        }

        typename T<E>::reference operator*() const {
            return *it;
        }

        iterator& operator++() {
            ++it;
            if ( it == r->end() )it = r->begin();
            return *this;
        }

        iterator& operator++(int) {
            iterator tmp = *this;
            ++*this;
            return tmp;
        }

        iterator& operator--() {
            if (it == r->begin()) it = r->end();
            --it;
            return *this;
        }

        iterator& operator--(int) {
            iterator tmp = *this;
            --*this;
            return tmp;
        }

        iterator insert(const E& x) {
            return iterator(*r, r->insert(it, x));
        }

        iterator erase() {
            return iterator(*r, r->erase(it));
        }
    };

    void push_back(const E& x) {
        lst.push_back(x);
    }

    iterator begin() {
        return iterator(lst, lst.begin());
    }

    int size() {
        return lst.size();
    }

private:
    T<E> lst;
};

template <typename T> class BitBucket {
public:
    BitBucket() { std::cout << "BitBucket::BitBucket()" << std::endl; }
    void fill(std::vector<T>& data) { std::cout << "BitBucket::fill()" << std::endl; }
};

class Class_7_15 {
public:
    Class_7_15(const char l);
    bool exist(char c);
    char getLetter();
private:
    char letter;
    bool isExist;
};

struct Alpha : std::unary_function<char, bool> {
    bool operator()(char c) { return std::isalpha(c); }
};

class Delim : std::unary_function<char, bool> {
public:
    Delim() {

    }

    Delim(const std::string& exc) : exclude(exc) {

    }

    bool operator()(char c) {
        return ( exclude.find(c) == std::string::npos );
    }

private:
    std::string exclude;
};

template <class InputIt, class P = Alpha>
class TokenIt : public std::iterator<std::input_iterator_tag, std::string, std::ptrdiff_t> {
private:
    InputIt first, last;
    std::string word;
    P predicate;
public:
    TokenIt(InputIt begin, InputIt end, P pred = P()) : first(begin), last(end), predicate(pred) {
        ++*this;
    }

    TokenIt() {}

    TokenIt& operator++() {
        word.resze(0);
        first = std::find_if(first, last, predicate);
        while ( first != last && predicate(*first) ) word += *first++;
        return *this;
    }

    class Capture {
    private:
        std::string word;
    public:
        Capture(const std::string& w) : word(w) {}
        std::string operator*() { return word; }
    };

    Capture operator++(int) {
        Capture t(word);
        ++*this;
        return t;
    }

    std::string operator*() const { return word; }

    std::string* operator->() const { return &(operator*()); }

    bool operator==(const TokenIt&) {
        return (word.size() == 0 && first == last);
    }

    bool operator!=(const TokenIt& rv) {
        return (!(*this == rv));
    }

};

#endif
