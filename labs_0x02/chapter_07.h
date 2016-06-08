#ifndef L_02_CHAPTER_07_H
#define L_02_CHAPTER_07_H

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <list>
#include <stack>
#include <vector>
#include <valarray>
#include <typeinfo>

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
    void altDraw();
    virtual ~Shape();
};

class Circle : public Shape {
public:
    Circle();
    void draw();
    ~Circle();
    int radius;
};

class Triangle : public Shape {
public:
    Triangle();
    ~Triangle();
    void draw();
    int line;
};

class Square : public Shape {
public:
    Square();
    void draw();
    ~Square();
    int perimeter;
};

class Rectangle : public Shape {
public:
    Rectangle();
    void draw();
    ~Rectangle();
};

// Couple functions, using in chapter 8.

bool greaterRadius(const Circle* lv, const Circle* rv);

bool greaterPerimeter(const Square* lv, const Square* rv);

void printStack(std::stack<int>& s, std::string name);

void sortStack(std::stack<int>& source, std::stack<int>& sorted, std::stack<int>& tail);

class Class_7_11 {
public:
    Class_7_11();
    int priority;
    friend bool operator<(const Class_7_11& lv, const Class_7_11& rv);
    friend std::ostream& operator<<(std::ostream& os, const Class_7_11& value);
};

template<typename E, template < class T1, class Alloc = std::allocator<T1> > class T >
class Ring {
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
        word.resize(0);
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

template<typename T>
class FList {
public:
    FList() : first(NULL) {
        std::cout << "FList::FList()" << std::endl;
    }

    ~FList() {
        std::cout << "FList::~FList()" << std::endl;
    }

    struct node {
        T element;
        node* next;
    };

    class iterator : public std::iterator<std::forward_iterator_tag, T> {
    public:
        iterator() : pos(NULL) {}

        iterator(node* n) : pos(n) {
            // std::cout << "iterator(node)" << std::endl;
        }

        T& operator*() {
            return pos->element;
        }

        node* getNode() const {
            return pos;
        }

        bool operator==(const iterator& x) const {
            return (this->pos == x.pos);
        }

        bool operator!=(const iterator& x) const {
            return !(this->pos == x.pos);
        }

        iterator& operator++() {
            pos = pos->next;
            return *this;
        }

        iterator& operator++(int) {
            iterator tmp = *this;
            ++*this;
            return tmp;
        }

    private:
        node* pos;
    };

    bool empty() const {
        return (!first);
    }

    T front () const {
        return first->element;
    }

    void push(const T& elem) {
        node* n = new node;
        n->element = elem;
        n->next = first;
        first = n;
    }

    void pop() {
        node* next = first->next;
        delete first;
        first = next;
    }

    void insertAfter(iterator& pos, const T& elem) {
        iterator it = begin();
        while (it != pos && it != end())
            it++;
        if (it == end()) return;
        node* founded = it.getNode();
        node* next = founded->next;
        node* newNode = new node;
        newNode->element = elem;
        newNode->next = next;
        founded->next = newNode;
    }

    void eraseAfter(iterator& pos) {
        iterator it = begin();
        while (it != pos && it != end())
            it++;
        if (it == end()) return;
        node* founded = it.getNode();
        if (founded->next == NULL) return;
        node* next = founded->next;
        founded->next = next->next;
        delete next;
    }

    iterator begin() {
        return iterator(first);
    }

    iterator end() {
        node* it = first;
        while (it != NULL) it = it->next;
        return iterator(it);
    }

    void print() {
        std::cout << "Forward list elements: ";
        for (FList<T>::iterator it = begin(); it != end(); it++) std::cout << *it << " ";
        std::cout << std::endl;
    }

private:
    node* first;
};

template<class T>
void printMatrix(const std::valarray<T>& matrix, size_t n, size_t l) {
    std::cout << "Matrix [" << n << "]:\n";
    for (size_t i = 0; i < n; i++) {
        std::cout << std::setw(3) << matrix[i];
        if ( (i + 1) % l ) std::cout << ' '; else std::cout << '\n';
    }
}

template<class T>
std::valarray<T> multiplyMatrix(const std::valarray<T> m1, size_t m1_rows, size_t m1_columns, const std::valarray<T> m2, size_t m2_rows, size_t m2_columns) {
    std::valarray<T> result(m1_rows * m2_columns);
    for (size_t i = 0; i < m1_rows; i++)
        for (size_t j = 0; j < m2_columns; j++) {
            std::valarray<T> row = m1[std::slice(m1_columns * i, m1_columns, 1)];
            std::valarray<T> col = m2[std::slice(j, m2_rows, m2_columns)];
            result[i * m2_columns + j] = (row * col).sum();
        }
    return result;
}

#endif
