#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "labs_0x01.h"
#include "chapter_03.h"

using namespace std;

void chapter_02 () {
    cout << "Chapter's 2 tasks.\n";
    // Tasks 1,2.
    cout << "Radius:  ";
    double radius = 0;
    double pi = 3.1415;
    cin >> radius;
    cout << "Area of circle with radius " << radius << " = " << pi*radius*radius << endl;
    // Tasks 3,4,5.
    fstream textFile;
    string text, searchWord, currentWord, textLine;
    vector<string> textLines;
    textFile.open("labs_0x01/files/chapter-02.txt");
    if (textFile.is_open()) {
        std::getline(textFile,text,'\0');
        cout << "Textfile: \n" << text << endl;
        textFile.seekg(0);
        while (std::getline(textFile, textLine, '\n')) textLines.push_back(textLine);
        cout << "Enter word to find: ";
        cin >> searchWord;
        int words = 0, foundedWords = 0;
        bool inWord = false;
        for (int i = 0; i < text.size(); i++) {
            if ( (text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z') ) {
                if (!inWord) {
                    inWord = true;
                    words++;
                }
                currentWord.push_back(text[i]);
            } else {
                if (currentWord == searchWord) foundedWords++;
                currentWord.clear();
                inWord = false;
            }
        }
        cout << "Words in text " << words << endl;
        cout << "Word '" << searchWord << "' was founded: " << foundedWords << endl;
        if (!textLines.empty()) {
            cout << "Text file from vector lines in reverse: \n";
            for (int i = textLines.size()-1; i > 0; i--) cout << textLines[i] << endl;
        } else cout << "File is empty.\n";
    } else cout << "Error open file: ./labs_0x01/files/chapther-02.txt" << endl;
    textFile.close();
    // Tasks 8,9,10.
    vector<float> first, second, third;
    for (int i = 0; i < 25; i++) {
        first.push_back(i);
        second.push_back(i%5);
        third.push_back(first[i]+second[i]);
    }
    cout << "First vector of floats: \n";
    for (int i = 0; i < 25; i++) cout << first[i] << " ";
    cout << "\nSecond vector of floats: \n";
    for (int i = 0; i < 25; i++) cout << second[i] << " ";
    cout << "\nThird vector of floats: \n";
    for (int i = 0; i < 25; i++) cout << third[i] << " ";
    cout << "\nSquares of elements in third vector: \n";
    for (int i = 0; i < 25; i++) {
        third[i] = third[i] * third[i];
        cout << third[i] << " ";
    }
    cout << endl;
}

void chapter_03 () {
    cout << "Chapter's 3 tasks.\n";
    // Task 1.
    function_3_1();
    char c = 'a';
    c =  function_3_2(c);
    cout << "Return value = '" << c << "'\n";
    int ix = 0;
    ix = function_3_3(ix);
    cout << "Return value = " << ix << "\n";
    float f = 2;
    f = function_3_4(f);
    cout << "Return value = " << f << "\n";
    // Task 2.
    cout << "Primary numbers: ";
    for (int i = 2; i < 100; i++)
        for (int j = 2; (i % j != 0 || i == j) && j <= i; j++)
            if (j == i) cout << i << " ";
    cout << endl;
    // Task 3. Better skip it.
    fstream textFile;
    string text, word1 = "port", word2 = "factory", word3 = "corporate";
    textFile.open("labs_0x01/files/chapter-03.txt");
    if (textFile.is_open()) {
        cout << "File labs_0x01/files/chapter-03.txt:\n";
        while (true) {
            text.clear();
            getline(textFile, text, '\n');
            cout << "Line : " << text << " ";
            int d = 3;
            if (text.find(word1) != string::npos) d = 0;
            if (text.find(word2) != string::npos) d = 1;
            if (text.find(word3) != string::npos) d = 2;
            switch (d) {
            case 0:
                cout << "Find word '" << word1 << "' at position " << text.find(word1) << endl;
                break;
            case 1:
                cout << "Find word '" << word2 << "' at position " << text.find(word2) << endl;
                break;
            case 2:
                cout << "Find word '" << word3 << "' at position " << text.find(word3) << ", exit from while." << endl;
                break;
            default:
                cout << "Words not found." << endl;
            }
            if (d == 2) break;
        }
    } else cout << "Error open file: ./labs_0x01/files/chapter-03.txt" << endl;
    // Task 4. Short.
    cout << "Menu: 1,2,3."  << endl;
    while (true) {
        char c;
        cin >> c;
        switch (c) {
        case '1':
            cout << "First item.\n";
            break;
        case '2':
            cout << "Second item.\n";
            break;
        case '3':
            cout << "Third. Exit.\n";
            break;
        default:
            cout << "Enter 1,2 of 3 for exit.\n";
        }
        if (c == '3') break;
    }
    // Task 5.
    int a, x = 1, y = 2, z = 2;
    a = x + y - 2/2 + z;
    cout << "a = x + y - 2/2 + z = " << a << endl;
    a = x + (y - 2)/(z + 2);
    cout << "a = x + (y - 2)/(z + 2) = " << a << endl;
    // Task 6.
    char cat;
    int dog;
    float fish;
    double bird;
    cout << "Types and memory.\n";
    cout << "Char 'cat'. Size =  " << sizeof(cat) << " bytes. Address: " << (long)&cat << endl;
    cout << "Int 'dog'. Size = " << sizeof(dog) << " bytes. Address: " << (long)&dog << endl;
    cout << "Float 'fish'. Size = " << sizeof(fish) << " bytes. Address: " << (long)&fish << endl;
    cout << "Double 'bird'. Size = " << sizeof(bird) << " bytes. Address: " << (long)&bird << endl;
    cout << "Function chapter_03 address: " << (long)&chapter_03 << endl;
    // Task 7.
    string str = "Calls: ";
    string* str1 = &str;
    string& str2 = str;
    function_3_5(str1);
    str += " ";
    function_3_6(str2);
    cout << str1 << endl << str2 << endl;
    // Task 8. Skip, because gcc doesn't support trigraph.
    // Task 9.
    for (int i = 0; i < 3; i++) function_3_7();
    // Task 10. Undefined reference, if 'fs' loacate in other file.
    extern int fs;
    cout << "Static int = " << fs << endl;
    // Tasks 11-13.
    double p1, p2;
    cout << "Double arguments 1 & 2:\n";
    cin >> p1;
    cin >> p2;
    cout << "p1 > p2 is " << (p1 > p2) << endl;
    cout << "p1 < p2 is " << (p1 < p2) << endl;
    cout << "p1 >= p2 is " << (p1 >= p2) << endl;
    cout << "p1 <= p2 is " << (p1 <= p2) << endl;
    cout << "p1 == p2 is " << (p1 == p2) << endl;
    cout << "p1 != p2 is " << (p1 != p2) << endl;
    cout << "p1 && p2 is " << (p1 && p2) << endl;
    cout << "p1 || p2 is " << (p1 || p2) << endl;
    cout << "Binary p1 | p2 = " << ((int)p1 | (int)p2) << endl;
    cout << "Binary p1 & p2 = " << ((int)p1 & (int)p2) << endl;
    unsigned char b1 , b2;
    int n1, n2;
    cout << "Byte arguments 1 & 2:\n";
    cin >> n1; cin >> n2;
    b1 = n1; b2 = n2;
    cout << "Binary arguments b1 & b2:" << toBinary(b1) << " " << toBinary(b2) << endl;
    cout << "b1 | b2 = " << toBinary(b1 | b2) << endl;
    cout << "b1 & b2 = " << toBinary(b1 & b2) << endl;
    cout << "b1 ^ b2 = " << toBinary(b1 ^ b2) << endl;
    cout << "~b1 = " << toBinary(~b1) << endl;
    cout << "~b2 = " << toBinary(~b2) << endl;
    unsigned char mask = 0x5a;
    cout << "Binary mask 0x5a = " << toBinary(mask) << endl;
    cout << "b1 | mask = " << toBinary(b1 | mask) << endl;
    b2 &= mask;
    cout << "b2 & mask = " << toBinary(b2) << endl;
    cout << "b2 ^ b1 = " << toBinary(b2 ^ b1) << endl;
    for (int i = 0; i < 4; i++) {
        rolByte(b1);
        rorByte(b2);
        cout << "Rotate left b1: " << toBinary(b1) << " , rotate right b2: " << toBinary(b2) << endl;
    }
    // Task 14.
    (b2 > 0) ? cout << "b2 > 0, using operator '?'\n" : cout << "b2 <= 0, using operator '?'\n";
    // Task 15.
    struct_3_1 st1;
    struct_3_1* st1Ptr;
    st1.s1 = "String 1";
    st1.s2 = "String 2";
    st1.n = 3;
    st1Ptr = &st1;
    cout << "String 1 from struct_3_1 = " << st1Ptr->s1 << ", string 2 from struct_3_1 = " << st1Ptr->s2 << endl;
    cout << "Int from struct_3_1 = " << st1Ptr->n << endl;
    // Task 16.
    for (int i = red; i <= blue; i++) cout << "Color number " << i << " ";
    cout << endl;
    // Task 17. Deleting element 'double' decrease size.
    union_3_1 union1;
    union1.i = 17;
    cout << "Union_3_1 int = " << union1.i << ", char = " << union1.c << ", double = " << union1.d << endl;
    // Task 18. May be worked, in old compilers. Offset = 3.
    int m1[2] = {0, 1};
    int m2[2] = {2, 3};
    int* ptrInt = &m1[1];
    ptrInt += 3;
    cout << "Pointer out of range, int = " << *ptrInt << endl;
    // Task 19.
    int im[3];
    char cm[3];
    float fm[3];
    long lm[3];
    cout << "Addresses of arrays int, char, float, long: " << endl;
    for (int i = 0; i < 3; i++)
        cout << "int:" << (long)&im[i] << " char:" << (long)&cm[i] << " float:" << (long)&fm[i] << " long:" << (long)&lm[i] << endl;
    // Task 20.
    point_3_20 pts[3];
    cout << "Size of array = " << sizeof(pts) << ", size of point_3_20 = " << sizeof(point_3_20) << endl;
    cout << "Addresses of elements structure_3_20: " << (long)&pts[0].i << " : " << (long)&pts[0].j << " : " << (long)&pts[0].k << endl;
    // Task 21.
    string ms[3];
    cout << "String array: ";
    for (int i = 0; i < 3; i++) {
        ms[i] = "string ";
        ms[i].push_back('0'+i);
        cout << ms[i] + " ";
    }
    cout << endl;
    // Task 22.
    const char param1[] = "1024";
    const char param2[] = "3.3";
    cout << "Long argument from string = " << atol(param1) << ", float argument from string =  " << atof(param2) << endl;
    // Task 23.
    primitiv_3_23 union2[3];
    primitiv_3_23* prim_3_23 = union2;
    cout << "Size of union 'prim' = " << sizeof(union2) << ", address = " << (long)union2 << ", pointer = " << (long)prim_3_23 << endl;
    prim_3_23++;
    cout << "Next pointer = " << (long)prim_3_23 << endl;
    // Task 24.
    long lArray[10];
    for (int i = 0; i < 10; i++) lArray[i] = i;
    long* lPtr = lArray;
    cout << "*lPtr = " << *lPtr << ", *++lPtr = " << *++lPtr << ", *(lPtr+5) = " << *(lPtr+5) << endl;
    long* lPtr2 = lPtr + 5;
    cout << "*lPtr2 = " << *lPtr2 << ", *(lPtr2-4) = " << *(lPtr2-4) << ", *--lPtr2 = " << *--lPtr2 << endl;
    cout << "lPtr2 - lPtr = " << lPtr2-lPtr << endl;
    // Task 25.
    float f2 = 1;
    unsigned char* f2Ptr = (unsigned char*)&f2;
    cout << "Float " << f2 << " in memory:\n";
    for (int i = 0; i < sizeof(float); i++) {
        string offS = "Offset ";
        offS.push_back('0'+i);
        cout << offS << ": " << toBinary(*f2Ptr++) << endl;
    }
    // Task 26.
    int iArr[5];
    void* arrPtr = static_cast<void*>(&iArr);
    setInt(arrPtr,5,3);
    cout << "Set all elements in array int[5] = ";
    for (int i = 0; i < 5; i++) cout << iArr[i] << " ";
    cout << endl;
    // Task 27.
    const double mcd[3] = {1, 2, 3};
    volatile double mvd[3];
    cout << "Const and volatile arrays of doulbe: ";
    for (int i = 0; i < 3; i++) {
        *(const_cast<double*>(&mcd[i])) = i;
        *(const_cast<double*>(&mvd[i])) = i + 1;
        cout << mcd[i] << "," << mvd[i] << " ";
    }
    cout << endl;
    // Task 28. Extra task.
    double dm[3];
    for (int i = 0; i < 3; i++) dm[i] = 0;
    outDoubleArray(dm,3);
    unsigned char* dArrayPtr = reinterpret_cast<unsigned char*>(dm);
    for (int i = 0; i < sizeof(dm); i++) *dArrayPtr++ = 1;
    outDoubleArray(dm,3);
    // Task 29.
    double td = -1;
    outDoubleBinary(td);
}

void Labs_0x01() {
    // chapter_02();
    chapter_03();
}

