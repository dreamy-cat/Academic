#ifndef LABS_05_CHAPTER_07_H
#define LABS_05_CHAPTER_07_H

#include <iostream>
#include <memory.h>

class Word {
public:
    Word(const char* word);
    ~Word();
    Word(const Word& rv);
    void append(const char c);
    unsigned char getSize() const;
    void setReadOnly(bool read);
    char* text();
    char& operator[](int idx) const;
    void resize(int newSize);
private:
    char* buffer;
    int size, bufferSize, pointers;
    bool readOnly;
    static char error;
};

#endif
