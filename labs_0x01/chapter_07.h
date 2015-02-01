#ifndef CHAPTER_07_H
#define CHAPTER_07_H

#include <string>

class Text {
public:
    Text();
    Text(std::string fileName);
    std::string txt;
};

class Message {
public:
    Message(std::string init);
    void print();
    void print(std::string pr);
private:
    std::string msg;

};

#endif
