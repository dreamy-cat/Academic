#include "chapter_05_1.h"

StackImp_1::StackImp_1 (int maxSz) {
    maxSize = maxSz;
    storage = new int[maxSize];
    sp = 0;
}

void StackImp_1::push(int value) {
    if (sp == maxSize) return;
    storage[sp++] = value;
}

int StackImp_1::pop() {
    if (sp == 0) return 0;
    return storage[--sp];
}

StackImp_2::StackImp_2(int maxSz) {
    storage.reserve(maxSz);
    maxSize = maxSz;
}

void StackImp_2::push(int value) {
    storage.push_back(value);
}

int StackImp_2::pop() {
    if (!storage.empty()) {
        int val = storage.back();
        storage.pop_back();
        return val;
    }
    return -1;
}
