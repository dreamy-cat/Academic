#ifndef L_02_CHAPTER_04_H
#define L_02_CHAPTER_04_H

#include <iostream>
#include <fstream>

std::ostream& newMan(std::ostream& os);

class FieldWidth {
public:
    FieldWidth(std::string message, int n);
    friend std::ostream& operator<<(std::ostream& os, const FieldWidth& fw);
private:
    int maxWidth;
    std::string msg;
};

#endif
