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
    if (textFile.is_open()) std::getline(textFile, txt); else
        cout << "Error open file: " << fileName << endl;
    textFile.close();
}
