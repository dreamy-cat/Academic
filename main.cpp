#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "labs-0x01/chapter02.h"

using namespace std;

void chapter02 () {
    cout << "Tasks from chapter 2.\n";
    cout << "Enter radius:  ";
    double radius = 0;
    double pi = 3.1415;
    cin >> radius;
    cout << "Area of circle with radius " << radius << " = " << pi*radius*radius << endl;
    fstream textFile;
    string text;
    textFile.open("files/chapter-02.txt");
    if (textFile.is_open()) {
        std::getline(textFile,text,'\0');
        cout << "Textfile: \n" << text << endl;
        int index = 0, spaceCounter = 0;
        while ((index = text.find(' ',index)) != -1) { spaceCounter++; index++; }
        cout << "Spaces in text " << spaceCounter << endl;
    } else cout << "Error open file: files/chapther-02.txt" << endl;
    textFile.close();
}

int main(int argc, char** argv)
{
    Chapter02 t;
    chapter02();
    return 0;
}

