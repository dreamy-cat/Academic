#ifndef CHAPTER_05_1
#define CHAPTER_05_1

#include <string>
#include <vector>

class StackImp_1 {
public:
    StackImp_1(int maxSz);
    void push(int value);
    int pop();
private:
    int* storage;
    int sp, maxSize;
};

class StackImp_2 {
public:
    StackImp_2(int maxSz);
    void push(int value);
    int pop();
private:
    std::vector<int> storage;
    int maxSize;
};

#endif // CHAPTER_05_1
