#ifndef L_02_CHAPTER_07_H
#define L_02_CHAPTER_07_H

#include <iostream>
#include <algorithm>
#include <list>

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

#endif
