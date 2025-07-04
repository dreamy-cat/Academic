#include "chapter_07.hpp"

using namespace std;

char Word::error;

Word::Word(const char *word) : size(0), bufferSize(0), buffer(nullptr) , pointers(0), readOnly(false) {
    error = '0';
    int newSize = 0;
    while (*(word + newSize) != '\0') newSize++;
    size = newSize;
    cout << "Word constructor, create buffer and copy parameter, new buffer size is " << newSize << "\n";
    resize(newSize + 1);
    memset(buffer, 0, bufferSize);
    memcpy(buffer, word, size);
    cout << "Parameter " << buffer << ", size " << size << endl;
}

Word::~Word() {
    cout << "Word destructor, reset buffer and size. Word " << buffer << ", size " << size << endl;
    if (pointers > 0) cout << "Pointers used " << pointers << endl;
    memset(buffer, 0, bufferSize);
    delete[] buffer;
    size = 0;
}

Word::Word(const Word& rv) {
    cout << "Word, copy constructor, word " << buffer << ", size " << size << endl;
    buffer = new char[rv.bufferSize];
    bufferSize = rv.bufferSize;
    size = rv.size;
    memcpy(buffer, rv.buffer, bufferSize);
}

void Word::append(const char c) {
    if (readOnly) {
        cout << "Word is read only, can't append.\n";
        return;
    }
    buffer[size++] = c;
    const int factor = 2;
    if (size == bufferSize) resize(size * factor);
}

char* Word::text() {
    cout << "Returning the data of Word, pointers " << ++pointers << endl;
    return buffer;
}

void Word::resize(int newSize) {
    if (newSize != bufferSize) {
        cout << "Changing buffer to new size, " << newSize;
        char* newBuffer = new char[newSize];
        memset(newBuffer, 0, newSize);
        if (buffer != nullptr) {
            cout << ", copy old buffer.";
            if (newSize > bufferSize) memcpy(newBuffer, buffer, size); else
                memcpy(newBuffer, buffer, newSize);
            delete[] buffer;
        }
        cout << endl;
        buffer = newBuffer;
        bufferSize = newSize;
    }
}

unsigned char Word::getSize() const { return size; }

char& Word::operator[](int idx) const {
    if (idx >= size) {
        cout << "Index of operator [], out of range.";
        return error;
    }
    return buffer[idx];
}

void Word::setReadOnly(bool read) {
    readOnly = read;
}
