#include "chapter_04.h"

using namespace std;

std::ostream& newMan(std::ostream& os) {
    os << "TEST" << endl;
}

FieldWidth::FieldWidth(string message, int n) : maxWidth(n), msg(message) {}

ostream& operator<<(ostream& os, const FieldWidth& fw) {
    FieldWidth tmp = fw;
    if (tmp.msg.size() > tmp.maxWidth) tmp.msg.resize(tmp.maxWidth);
    os << tmp.msg;
    return os;
}

DataBase_1::DataBase_1(std::string dbName) : fileName(dbName) {
    file.open(fileName.data(), ios::out | ios::in | ios::trunc);
}

DataBase_1::~DataBase_1() {
    file.close();
}

size_t DataBase_1::query(size_t n) {
    file.seekg(n*sizeof(Cat));
}

DataBase_1::Cat DataBase_1::retrieve(size_t n) {
    query(n);
    Cat value;
    file.read((char*)&value, sizeof(Cat));
    return value;
}

void DataBase_1::add(const Cat& value) {
    file.write((char*)&value, sizeof(Cat));
}

ostream& operator<<(ostream& os, const DataBase_1::Cat& value) {
    os << "(" << value.id << "," << value.name << ")";
}

int DataBase_1::fromString(const std::string backup) {
    int recordBegin = 0, recordEnd = 0;
    while ((recordEnd = backup.find('\n', recordBegin)) != string::npos) {
        string line(backup, recordBegin, recordEnd-recordBegin);
        int idPos, nextPos;
        if ((idPos = line.find(':', 0)) != string::npos) {
            cout << "Id:" << atoi(string(line, 0, idPos).data());
            cout << ", Name: " << string(line, ++idPos, line.size()-idPos);
        } else cout << "Error in line, no ':' founded." << endl;
        recordBegin = recordEnd+1;
        cout << endl;
    }
}

string toString(int i, int base) {
    string result;
    int sign;
    if (i < 0) sign = -1; else sign = 1;
    do {
        result.insert(result.begin(), char('0' + i % base));
        i /= base;
    } while (i);
    if (sign == -1) result.insert(result.begin(), '-');
    return result;
}

int fromHexString(const std::string source) {
    int value = 0, pos = 0;
    const char hexTab[] = "0123456789ABCDEF";
    for (int i = source.size()-1; i >= 0; --i) {
        char c = toupper(source[i]);
        int index = 0;
        while (index < 16 && c != hexTab[index]) index++;
        if (index != 16) value += index << pos;
        pos += 4;
    }
    return value;
}
