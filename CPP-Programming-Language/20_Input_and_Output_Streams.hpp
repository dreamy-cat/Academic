﻿#ifndef CHAPTER_20_H
#define CHAPTER_20_H

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>

std::ostream& newMan(std::ostream& os);

class FieldWidth {
public:
    FieldWidth(std::string message, int n);
    friend std::ostream& operator<<(std::ostream& os, const FieldWidth& fw);
private:
    int maxWidth;
    std::string msg;
};

class DataBase_1 {
public:
    DataBase_1(std::string dbName);
    ~DataBase_1();
    size_t query(size_t n);
    struct Cat {
        int id;
        char name[8];
    };
    Cat retrieve(size_t n);
    void add(const Cat& value);
    int fromString(const std::string backup);
    friend std::ostream& operator<<(std::ostream& os, const Cat& value);
private:
    std::string fileName;
    std::fstream file;
};

std::string toString(int i, int base = 10);

int fromHexString(const std::string source);

#endif
