#include <fstream>
#include <iostream>

#include "chapter_07.h"

using namespace std;

Text::Text () {
    txt.clear();
}

Text::Text (string fileName) {
    txt.clear();
    fstream textFile;
    textFile.open(fileName.data());
    if (textFile.is_open()) std::getline(textFile, txt, '\0'); else
        cout << "Error open file: " << fileName << endl;
    textFile.close();
}

Message::Message(string init) {
    msg = init;
}

void Message::print() {
    cout << "Class message print function: " << msg << endl;
}

void Message::print(string pr) {
    cout << "Class message print(string) function : " << pr << msg << endl;
}
