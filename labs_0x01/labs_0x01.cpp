#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <ctime>
#include <assert.h>

#include "labs_0x01.h"
#include "chapter_03.h"
#include "chapter_04.h"
#include "chapter_05.h"
#include "chapter_06.h"
#include "chapter_07.h"
#include "chapter_08.h"
#include "chapter_09.h"
#include "chapter_10.h"
#include "chapter_10_1.h"
#include "chapter_11.h"
#include "chapter_12.h"
#include "chapter_13.h"
#include "chapter_14.h"

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
    // Task 30 & 35. Think about it later.
    // Task 31.
#ifdef DEBUG
    cout << "Testing define flag." << endl;
#endif
    // Task 32.
    int (*fPtr)(double d) = function_3_8;
    (*fPtr)(1.0);
    // Task 33. Bonus.
    float (*(*fPtr2)(int))(char) = function_3_9;
    float (*fPtr3)(char) = (*fPtr2)(1);
    (*fPtr3)('S');
    // Task 34.
    string (*funcTable[])() = {function_3_11, function_3_12, function_3_13};
    for (int i = 0; i < 3; i++) cout << ((*funcTable[i])()) << endl;
}

void chapter_04() {
    cout << "Chapter's 4 tasks.\n";
    // Task 1. Not possible to use C flag. Try it later in separate project.
    // Task 2-6.
    structure_4_1 struc1;
    struc1.function_1(&struc1,1);
    struc1.function_2(&struc1);
    class_4_1 class1;
    // Task 7.
    Stash stashDouble;
    stashDouble.initialize(sizeof(double));
    for (int i = 0; i < 8; i++) {
        double d = i;
        stashDouble.add((void*)&d);
    }
    cout << "Fetch elements from storage: ";
    for (int i = 0; i < 8; i++) cout << *(double*)stashDouble.fetch(i) << " ";
    cout << endl;
    stashDouble.cleanup();
    // Task 8.
    double d8 = 1.0;
    Stack stackDouble;
    stackDouble.initialize();
    stackDouble.push(&d8);
    cout << "Pop double value from stack = " << *stackDouble.pop() << endl;
    // Task 9-10. Depends on compilers.
    // Task 11-12.
#ifdef TASK_11
    cout << "Define TASK_11." << endl;
#else
    cout << "Not define TASK_11." << endl;
    assert(0);
#endif
    // Task 13-14.
    Class_4_13 cl1("Test 1"), cl2("Test 2");
    cout << "Class_4_13 objects 1 & 2 = ";
    cl1.print();
    cout << " ";
    cl2.print();
    cout << endl;
    Stack2 stackClass_4_13(5);
    stackClass_4_13.push(cl1);
    cl2 = stackClass_4_13.pop();
    cout << "Stack test object 2 = object 1: ";
    cl2.print();
    cout << endl;
    // Task 15.
    cout << "Size of char = " << sizeof(char) << endl;
    cout << "Size of int = " << sizeof(int) << endl;
    cout << "Size of long = " << sizeof(long) << endl;
    cout << "Size of void* = " << sizeof(void*) << endl;
    cout << "Size of float = " << sizeof(float) << endl;
    cout << "Size of double = " << sizeof(double) << endl;
    // Task 16. Ready, old version remains commented.
    // Task 17.
    int *intPtr = new int (128);
    long *longPtr = new long (128);
    char *charPtr = new char (128);
    float *floatPtr = new float (128);
    cout << "Addresses of pointers to int, long, char, float : ";
    cout << (long)intPtr << " " << (long)longPtr << " " << (long)charPtr << " " << (long)floatPtr << endl;
    // Task 18.
    const char str1[] = "Task 18 test string";
    char* str2 = function_4_1(str1);
    cout << "Original string = " <<  str1 << ", address: " << (long)str1 << endl;
    cout << "Copy string = " << str2 << ", address: " << (long)str2 << endl;
    delete []str2;
    structure_4_2 struc2;
    struc2.n1 = 0;
    struc2.substructure.n2 = 1;
    struc2.printN();
    struc2.substructure.printN();
    // Task 20. Size > 0, becuase of addresses.
    cout << "Size of structure_4_3 = " << sizeof(structure_4_3) << endl;
    cout << "Size of structure_4_4 = " << sizeof(structure_4_4) << endl;
    cout << "Size of structure_4_5 = " << sizeof(structure_4_5) << endl;
    // Task 21. Compiles ok.
    enum_1 en1;
    union_4_1 un1;
    // Task 22-23.
    Stack3 stack_3;
    structure_4_6 struc;
    stack_3.init(8);
    struc.wrapinit(8);
    int actualRead = 0;
    fstream textFile;
    string textLine;
    textFile.open("labs_0x01/files/chapter-04.txt");
    if (textFile.is_open()) {
        cout << "File labs_0x01/files/chapter-04.txt:\n";
        while (getline(textFile, textLine, '\n')) {
            cout << "Line : " << textLine << endl;
            Stash3 line;
            line.text = textLine;
            //stack_3.push(line);
            struc.wrapPush(line);
            actualRead++;
        }
        cout << "Actual lines read " << actualRead << endl;
        cout << "Lines from stack : " << endl;
        for (int i = 0; i < actualRead; i++) {
            //Stash3 line = stack_3.pop();
            Stash3 line = struc.wrapPop();
            cout << line.text << endl;
        }
    } else cout << "Error open file /labs_0x01/files/chapte r-04.txt" << endl;
    // Task 24-25.
    List list1;
    list1.createList(&list1,4);
    cout << "List size 4 elements: ";
    list1.printList(&list1);
    cout << endl;
}

void chapter_05 () {
    cout << "Chapter's 5 tasks.\n";
    // Task 1. Only public members compiles.
    Class_5_1 class1;
    class1.a = 0;
    class1.f1();
    /*
    class1.b = 0;
    class1.f2();
    class1.c = 0;
    class1.f3();
    */
    // Task 2.
    Structure_5_1 x;
    x.a = "Structure_5_1.a";
    x.b = "Structure_5_1.b";
    x.c = "Structure_5_1.c";
    x.s[0] = x.a;
    x.s[1] = x.b;
    x.s[2] = x.c;
    Class_5_1_2 class2;
    class2.setString("String 1",0);
    class2.setString("String 2",1);
    class2.setString("String 3",2);
    cout << "Strings from Class_5_1_2: ";
    for (int i = 0; i < 3; i++) cout << class2.getString(i) << " ";
    cout << endl;
    // Task 3.
    Class_5_3 class3;
    function_5_3(&class3);
    // Task 4.
    Class_5_4_1 class41;
    Class_5_4_2 class42;
    class41.f(&class42);
    class42.f(&class41);
    // Task 5.
    Class_5_5_1 class51;
    Class_5_5_2 class52;
    Class_5_5_3 class53;
    class52.printA(&class51);
    class53.f(&class51);
    // Task 6-7.
    Class_5_6_1 class61;
    Class_5_6_1::Class_5_6_2 class62;
    Class_5_6_1::Class_5_6_2::Class_5_6_3 class63;
    class61.display();
    class62.display();
    class63.display();
    // Task 8.
    Class_5_8 class5;
    class5.showMap();
    // Task 9. See chapter 4.
    // Task 10.
    cout << "Store 4 objects of Class_5_6_1 in Stash.\n";
    Stash stash;
    stash.initialize(sizeof(Class_5_6_1));
    for (int i = 0; i < 4; i++) {
        Class_5_6_1* clPtr = new Class_5_6_1;
        clPtr->c = '0'+i;
        stash.add(clPtr);
    }
    cout << "Fetch 4 objects of Class_5_6_1 from Stash.\n";
    for (int i = 0; i < 4; i++) {
        Class_5_6_1* clPtr = (Class_5_6_1*)stash.fetch(i);
        clPtr->print();
    }
    // Task 11. See chapter 4.
    // Task 12.
    cout << "Push 4 objects of Class_5_6_1 in Stack_5.\n";
    Stack_5 stack(5);
    for (int i = 0; i < 4; i++) {
        Class_5_6_1* clPtr = new Class_5_6_1;
        clPtr->c = '0'+i;
        stack.push((void*)clPtr);
    }
    cout << "Pop 4 objects of Class_5_6_1 from Stack_5.\n";
    for (int i = 0; i < 4; i++) {
        Class_5_6_1* clPtr = (Class_5_6_1*)stack.pop();
        clPtr->print();
    }
    // Task 13-14. Not compile, if changes in _05_1.cpp.
    StackOfInt st;
    st.stack1 = new StackImp_1(3);
    st.stack2 = new StackImp_2(3);
    cout << "Push 3 values to StackImp_1 & StackImp_2 objects.\n";
    for (int i = 0; i < 3; i++) {
        st.stack1->push(i);
        st.stack2->push(i);
    }
    cout << "Pop 3 values from StackImp_1 & StackImp_2 objects : ";
    for (int i = 0; i < 3; i++) cout << st.stack1->pop() << " " << st.stack2->pop() << " ";
    cout << endl;
}

void chapter_06() {
    cout << "Chapter's 6 tasks.\n";
    // Tasks 1-4.
    Simple class1(0), class2(1);
    for (int i = 0; i < 2; i++) {
        Simple class3(2);
        goto jump;
    }
jump: ;
    // Task 5. May be in old standard, but works fine now.
    int i = 0;
    cout << "Counters in 'for' i,j : ";
    for (; i < 3; i++) for (int i = 0; i < 3; i++) cout << i << " " << i << " ";
    cout << endl;
    // Task 6.
    Class_6_6 class66;
    cout << "Class_6_6 int = " << class66.read();
    class66.change(1);
    cout << " after change int = " << class66.read() << endl;
    // Task 7.
    double dm[3] = { 1.0, 2.0 };
    cout << "Vector of double : ";
    for (int i = 0; i < sizeof(dm)/sizeof(double); i++) cout << dm[i] << " ";
    double dm2[] = { 1.0, 2.0, 3.0 };
    cout << endl << "Second vector of double : ";
    for (int i = 0; i < sizeof(dm2)/sizeof(double); i++) cout << dm2[i] << " ";
    cout << endl;
    // Task 8.
    string sm[3] = { "one", "two", "three" };
    Stack6 class68;
    cout << "Push strings to stack : ";
    for (int i = 0; i < 3; i++) {
        cout << sm[i] << " ";
        class68.push(sm[i]);
    }
    cout << "\nPop strings from stack : ";
    for (int i = 0; i < 3; i++) cout << class68.pop() << " ";
    cout << endl;
    // Task 9.
    Simple class9[] = { Simple(1), Simple(2), Simple(3) };
    cout << "Class Simple vector, print a : ";
    for (int i = 0; i < sizeof(class9)/sizeof(Simple); i++) class9[i].printA();
    cout << endl;
    // Task 10. Just for constructor test.
    Class_6_10 class10(0);
    class10.function();
    cout << endl;
}

void chapter_07() {
    cout << "Chapter's 7 tasks.\n";
    // Task 1.
    Text class1("labs_0x01/files/chapter-07.txt");
    cout << "File chapter-07.txt : " << "\n" << class1.txt;
    // Task 2.
    Message class2("Initial string.");
    class2.print();
    class2.print("With string. ");
    // Task 3. Intresting...
    // Task 4. May be not right
    Class_7_4 class4;
    class4.f();
    class4.f(1);
    class4.f(1,2);
    class4.f(1,2,3);
    // Task 5.
    function_7_5(1, 2);
    // Task 6.
    Stash7 stashOfInt(sizeof(int));
    Stash7 stashOfChar(sizeof(char), 8);
    for (int i = 0; i < 16; i++) {
        stashOfInt.add((void*)&i);
        char c = 'a' + i;
        stashOfChar.add((void*)&c);
    }
    cout << "Stash of int : ";
    for (int i = 0; i < stashOfInt.count(); i++) cout << *((int*)stashOfInt.fectch(i)) << " ";
    cout << "\nStash of char : ";
    for (int i = 0; i < stashOfChar.count(); i++) cout << *((char*)stashOfChar.fectch(i)) << " ";
    cout << endl;
    // Task 7.
    string strings_1[] = {"one", "two", "three"};
    Stack7 r(strings_1, 3);
    cout << "Pop strings values : ";
    for (int i = 0; i < 3; i++) cout << r.pop() << " ";
    cout << endl;
    // Task 8.
    SuperVar sv[3] = { SuperVar(char('a')), SuperVar(int(1)), SuperVar(float(3.0)) };
    for (int i = 0; i < 3; i++) sv[i].print((SuperVar::vartype)i);
    // Task 9.
    string s1 = "First test string.", s2 = "Add string.", s3 = "Using default constructor.";
    String_9 s_91(s1.data());
    s_91.print(cout);
    s_91.concat(const_cast<char*>(s2.data()));
    s_91.print(cout);
    String_9 s_92;
    s_92.print(cout);
    s_92.concat(const_cast<char*>(s3.data()));
    s_92.print(cout);
    // Task 10.
    StashMem stashMemOfInt(sizeof(int));
    StashMem stashMemOfChar(sizeof(char), 8);
    for (int i = 0; i < 16; i++) {
        stashMemOfInt.add((void*)&i);
        char c = 'a' + i;
        stashMemOfChar.add((void*)&c);
    }
    cout << "StashMem class. Integers : ";
    for (int i = 0; i < stashMemOfInt.count(); i++) cout << *((int*)stashMemOfInt.fectch(i)) << " ";
    cout << "\nStashMem class. Chars : ";
    for (int i = 0; i < stashMemOfChar.count(); i++) cout << *((char*)stashMemOfChar.fectch(i)) << " ";
    cout << endl;
    // Task 11.
    Mem mem1(5);
    cout << "Mem class pointer moved : " << mem1.moved() << ". ";
    cout << "And after second call : " << mem1.moved() << endl;
}

void chapter_08() {
    cout << "Chapter's 8 tasks.\n";
    // Tasks 1-2. Not possible in this project.
    const int i1 = 1, i2 = 1, i3 = 1;
    const int im1[i1 + i2 + i3] = { 1, 2, 3 };
    // Task 3.
    const char c1 = 'a';
    const int i4 = 0;
    const float f1 = 0;
    const double f2 = 0;
    // Task 4.
    cout << "Task's 4, constant int = " << iTask4 << endl;
    // Task 5. Compiler error, if using any other type, not pointer.
    time_t timer;
    time(&timer);
    const char* ch1 = ctime(&timer);
    cout << "Current date & time : " << ch1;
    // Task 6. Can't change constant string.
    const char string6[] = "Task's 6 string.";
    cout << "Task's 6 string : " << string6 << endl;
    // Task 7.
    extern const int int7;
    cout << "External constant integer : " << int7 << endl;
    // Task 8. Increment of read-only location.
    const long lm1[3] = {1, 2, 3};
    const long* lmPtr1 = &lm1[0];
    cout << "Long array, first element = " << *lmPtr1 << ".";
    lmPtr1++;
    cout << " After increasing pointer, second element = " << *lmPtr1 << endl;
    // (*lmPtr1)++;
    // Task 9. Ok, be carefull.
    double dm1[3] = {1.0, 2.0, 3.0};
    double* const dmPtr = &dm1[0];
    cout << "First element of double array : " << *dmPtr << ". ";
    (*dmPtr)++;
    cout << "After increasing : " << *dmPtr << endl;
    // dmPtr++;
    // Task 10. Errors, as expected.
    const int int10 = 0;
    const int* const intPtr1 = &int10;
//    intPtr1++;
//    (*intPtr1)++;
    // Task 11. Compile error. Invalid conversation.
    int d = 1;
    const int e = 2;
    int* u = &d;
    // int* v = &e;
    int* w = (int*)&e;
    // Task 12. No errors. Non constant object can be modified.
    char string12[] = "String 12.";
    char* strPtr = string12;
    strPtr[9] = '!';
    cout << "String 12 = " << string12 << endl;
    // Task 13. Error. Increment of read-only parameter c.
    // Task 14.
    float float14 = 1.0;
    cout << "Function 14. ";
    function_8_14(float14);
    // Task 15.
    function_8_15_1() = Class_8_15(1);
    function_8_15_1().modify();
    // Invalid initialization of non-const reference of type 'Class_8_15&' from an Rvalue of type 'Class_8_15'
    // function_8_15_3(function_8_15_1());
    // Passing 'const Class_8_15' as 'this' argument of 'Class_8_15& Class_8_15::operator=(const Class_8_15&)' discard qualifiers.
    // function_8_15_2() = Class_8_15(1);
    // Passing 'const Class_8_15' as 'this' argument of 'void Class_8_15::modify()' discards qualifiers
    // function_8_15_2().modify();
    // Invalid initialization of non-const reference of type 'Class_8_15&' from an Rvalue of type 'const Class_8_15'
    // function_8_15_3(function_8_15_2());
    // Task 16.
    int x = 0;
    int* ip = &x;
    const int* cip = &x;
    function_8_16_1(ip);
    // Invalid conversation from 'const int*' to 'int*'
    // function_8_16_1(cip);
    function_8_16_2(ip);
    function_8_16_2(cip);
    // Ivalid conversation from 'const cahr*' to 'char*'
    // char* cp = function_8_16_3();
    const char* ccp = function_8_16_3();
    // Invalid conversation from 'const int*' to 'int*'
    // int* ip2 = function_8_16_4();
    const int* const ccip = function_8_16_4();
    const int* cip2 = function_8_16_4();
    // Task 17.
    int xr = 0;
    int& ipr = xr;
    const int& cipr = xr;
    function_8_17_1(ipr);
    // Invalid initialization of reference of type 'int&' from expression 'const int'
    // function_8_17_1(cipr);
    function_8_17_2(ipr);
    function_8_17_2(cipr);
    // Invalid initialization of reference of type 'const cahr&' to 'const char'
    // char& cpr = function_8_17_3();
    const char& ccpr = function_8_17_3();
    // Invalid initialization of reference of type 'int&' from expression 'const int'
    // int& ipr2 = function_8_17_4();
    const int& ccipr = function_8_17_4();
    const int& cip2r = function_8_17_4();
    // Task 18.
    // Invalid initialization of non-const reference of type 'Class_8_18&' from an Rvalue of type 'Class_8_18'
    // function_8_18_2(function_8_18_1());
    function_8_18_3(function_8_18_1());
    // Task 19.
    Class_8_19 class19((float)1.0, (float)2.0);
    // Task 20.
    StringStack8 stack8;
    string iceCream[] = {"pralines & cream", "fudge ripple", "rocky road"};
    for (int i = 0; i < 3; i++) stack8.push(&iceCream[i]);
    const string* ice;
    cout << "Ice cream from stack :\t";
    while ((ice = stack8.pop()) != 0) cout << *ice << "\t";
    cout << endl;
    // Tasks 21-22. Ok in .h & .cpp.
    // Task 23.
    Class_8_23 class23_1;
    const Class_8_23 class23_2;
    class23_1.function_1();
    class23_1.function_2();
    // passing 'const Class_8_23' as 'this' argument of 'void Class_8_23::function_1()' discards qualifiers
    // class23_2.function_1();
    class23_2.function_2();
    // Task 24-25 see in .h & .cpp.
    // Task 26
    Quoter8 class26_1;
    const Quoter8 class26_2;
    class26_1.lastQuote();
    class26_2.lastQuote();
    cout << "Quotes : " << endl;
    for (int i = 0; i < 3; i++) cout << class26_1.quote() << endl;
    // Task 27.
    Class_8_27 class27_1;
    volatile Class_8_27 class27_2;
    class27_1.function_1();
    class27_1.function_2();
    // Passing 'volatile Class_8_27' as this argument of 'void Class_8_27::function_1()' discards qualifiers
    // class27_2.function_1();
    class27_2.function_2();
    // Task 28. No error, may be not correct.
    Class_8_28_1 class28_1, *class28_1Ptr;
    Class_8_28_2 class28_2;
    class28_1.function_1();
    void* classPtr = &class28_2;
    class28_1Ptr = (Class_8_28_1*)classPtr;
    class28_1Ptr->function_1();
}

void chapter_09 () {
    cout << "Chapter's 9 tasks.\n";
    // Task 1.
    // 'x' was not declared in this scope
// #define F (x) (x+1)
#define F(x) (x+1)
    int i1 = F(1);
    cout << "F(1) = " << i1 << endl;
    // Task 2.
#define FLOOR1(x,b) x<=b?1:0
    cout << "Macros FLOOR first version result : ";
    if (FLOOR1(5,3)) cout << "true" << endl; else cout << "false" << endl;
    cout << "Macors FLOOR incorrect result : ";
    int a = 0x0F;
    if (FLOOR1(a&0x0F,a&0x07)) cout << "true" << endl; else cout << "false" << endl;
    // Task 3.
#define BAND(x) (((x)>5 && (x)<10) ? (x) : 0)
    cout << "Testing macro BAND.\n";
    for (int i = 4; i < 11; i++) {
        int a = i;
        cout << "a = " << a << " " << "BAND(a+1) = " << BAND((a+1));
        cout << ", a = " << a << endl;
    }
    // Task 4-5. Strange, recheck.
    time_t time;
    tm local;
    local = *std::localtime(&time);
    cout << "Starting second : " << local.tm_sec;
    for (int i = 0; i < 1000; i++)
        for(int j = 0; j < 100000; j++) function_9_4_1();
    local = *std::localtime(&time);
    cout << " after calling standart function : " << local.tm_sec;
    for (int i = 0; i < 1000; i++)
        for(int j = 0; j < 100000; j++) function_9_4_2();
    local = *std::localtime(&time);
    cout << ", after calling inline function : " << local.tm_sec << endl;
    // Task 6. in .h, .cpp
    Class_9_6 class6;
    cout << "Address of class6 : " << (long)&class6 << ", address of 'this' in class function t() : ";
    class6.t();
    cout << endl;
    // Task 7.
    Class_9_7 class7('a');
    cout << "Result of memset char text[] : ";
    class7.print();
    // Task 8.
    Structure_9_8 struc90;
    Structure_9_8::Structure_9_8_1 struc91(&struc90);
    cout << "Values from Structure_9_8_1 : ";
    for (int i = 0; i < 3; i++) { struc91.set(i); struc91.next(); }
    for (int i = 0; i < 3; i++) { struc91.previous(); cout << struc91.read() << " "; }
    cout << endl;
    // Task 9.
    string strings1[] = { "one", "two", "three" };
    StringStack9 stack9;
    cout << "Strings of class StringStacks9 : ";
    for (int i = 0; i < 3; i++) stack9.push(&strings1[i]);
    for (int i = 0; i < 3; i++) cout << *stack9.pop() << " ";
    cout << endl;
    // Task 10-11.
    Color9 class10(Color9::blue);
    class10.color(Color9::blue);
    cout << "Color from Color9 class : " << class10.color() << endl;
    // Task 12. See task 4-5. Later.
    // Task 13.
    Class_9_13 class13;
    class13.function_1();
    // Task 14.
    Class_9_14_2 class14;
    // Task 15. Not convinient without suppress console output.
    const int maxObjs = 4;
    Class_9_14_2* objects[maxObjs];
    for (int i = 0; i < maxObjs; i++) {
        objects[i] = new Class_9_14_2;
    }
    // Task 16.
#define DEBUG16(x) cout << "Debug macros : " #x " " << x << endl;
    string str16 = "Task 16";
    while (!str16.empty()) {
        DEBUG16(str16[str16.size() - 1]);
        str16.resize(str16.size()-1);
    }
    // Task 17.
#define TRACE16(s) cout << "Trace marcos : " << #s << endl , s;
    TRACE16(cout << "Trace paramter.\n");
    // Task 18-19. Very strange, may be not correct.
    char txt18[] = "Task 18.";
    Record9 class18 (txt18);
    cout << "Class Record9, select method : " << class18.select(1) << endl;
    cout << "Class Record9, one_get method : " << class18.one_get() << endl;
    // Task 20. Need arguments, not possible.
    // Task 21.
#define IFOPEN(var,name) \
    ifstream var; \
    var.open(name); \
    if (var.is_open()) cout << "File " << name << " open. Ok.\n"; else cout << "Error open " << name << " file.\n"; \
    var.close();
    IFOPEN(textFile,"labs_0x01/files/chapter-02.txt");
    // Task 22. Bonus.
}

void chapter_10() {
    cout << "Chapter's 10 tasks.\n";
    // Task 1.
    int arrayInt[5] = { 1, 2, 3, 4, -1 };
    function_10_1(arrayInt);
    cout << "Integer array with static address : ";
    for (int i = 0; i < 5; i++) cout << function_10_1() << " ";
    cout << endl;
    // Task 2. Classic.
    cout << "Fibonacci sequence : ";
    for (int i = 0; i < 12; i++) cout << numberFibbonaci() << " ";
    cout << endl << "After reset sequence : ";
    numberFibbonaci(true);
    for (int i = 0; i < 12; i++) cout << numberFibbonaci() << " ";
    cout << endl;
    // Task 3.
    Class_10_3 class3(5);
    class3.print();
    // Task 4-6.
    cout << "Counter of static Class_10_4.\n";
    for (int i = 0; i < 3; i++) function_10_4();
    Class_10_4 class4;
    function_10_5(&class4);
    Class_10_5* class5 = new Class_10_5(&class4);
    delete class5;
    // Task 7. Same as previous.
    // Task 8. Correct, static objects was created in order by name of functions in _10.cpp file.
    cout << "Task 8. Class_10_8.\n";
    Class_10_8 cl8('a');
    function_10_8_1();
    function_10_8_2();
    // Task 9. Udefined refecrence, as expected. May be not correct.
    //extern ofstream stream9;
    //stream9 << "Tasks9, test.\n";
    // Task 10. Worked, but it's not convinient in current project.
    // Task 11-12. See chapter_10.cpp.
    extern Class_10_11 cl10_1;
    cl10_1.print();
    // Task 13.
    function_10_13();
    // Task 14.
    volatile Class_10_14 cl14;
    cl14.isr();
    // Passing 'volatile Class_10_14' as 'this' argument of 'char Class_10_14::read(int) const' discards qualifiers
    // cl14.read(0);
    // Task 15.
    auto int i15_1 = 0;
    register int i15_2 = 1;
    cout << "Auto and register integers : " << i15_1 << " " << i15_2 << endl;
    // Task 16.
    namespace nm16 = NameSpace_16_2;
    using namespace nm16;
    nm16::function_16_1();
    nm16::function_16_2();
    function_16_3();
    function_16_4();
    // Task 17-18.
    function_10_17();
    function_10_18();
    // Task 19.
    NameSpace_10_19::Class_10_19 cl19;
    function_10_19();
    // Task 20. May not correct...
    arithmetic();
    // Task 21.
    using namespace NameSpace_10_20_2;
    Integer a(3);
    a.setSign(positive);
    cout << "NameSpace_10_20_2, get sign from Integer without operator '::' : " << a.getSign() << endl;
    NameSpace_10_20_2::a.setSign(negative);
    cout << "NameSpace_10_20_2, get sign from Integer with operator '::' : " << NameSpace_10_20_2::a.getSign() << endl;
    // Task 22-23. If in global, no difference.
    using namespace NameSpace_10_22_1;
    // using namespace NameSpace_10_22_2;
    // Reference to 'Class_10_22' is ambiguous.
    Class_10_22 class22_1;
    NameSpace_10_22_2::Class_10_22 class22_2;
    // Task 24. Ok, but not as expected.
    using namespace NameSpace_10_24_3;
    Class_10_24_1 cl24_1;
    Class_10_24_2 cl24_2;
    Class_10_24_6 cl24_6;
    // Task 25.
    Class_10_25 cl25("Test string 25.");
    cl25.print();
    // Task 26.
    Class_10_26 cl26;
    cl26.print();
    // Task 27.
    Class_10_27_2 cl27;
    cl27.function_1();
    // Task 28. Too short.
    // Task 29. Constructor using string.
    Class_10_29_2 cl29;
    cl29.printArray();
    // Task 30.
    struct Structure_30 {
        Structure_30() : i(0) {}
        int i;
    };
    Structure_30 struc30[3];
    cout << "Array of Structure_30 : ";
    for (int i = 0; i < 3; i++) cout << struc30[i].i << " ";
    cout << endl;
    // Task 31.
    Class_10_31* ptr31 = Class_10_31::instance();
    cout << "Value from Class_10_31, singletone : " << ptr31->value() << endl;
    // Task 32-35. Rethink
    Mirror_32 cl32_1;
    Mirror_32 cl32_2(&cl32_1);
    cout << "Address of calling cl32_2 : " << (long)cl32_2.test() << endl;
}

void chapter_11 () {
    cout << "Chapter's 11 tasks.\n";
    // Task 1. Not possible to using C compiler.
    int* intPtr1;
    char* charPtr1;
    void* voidPtr1 = charPtr1;
    // Invalid conversation from 'void*' to 'int*'
    // intPtr1 = voidPtr1;
    // Task 2.
    int int2 = 0;
    int& r = int2;
    cout << "Integer reference = " << r << endl;
    r++;
    cout << "Integer reference = " << r << endl;
    // Task 3.
    // a. ref3 declared as reference but not initialized
    int int3 = 3;
    int& ref3 = int3;
    // Worked but
    cout << "Task's 3 reference = " << ref3 << endl;
    ref3 = int2;
    cout << "Task's 3 reference = " << ref3 << endl;
    // Only values.
    ref3 = 0;
    // Task 4.
    int int4 = 4;
    cout << "Task's 4 integer = " << int4 << ", after calling function_11_4 integer = ";
    function_11_4(int4);
    cout << int4 << endl;
    // Task 5.
    Class_11_5 cl5;
    const Class_11_5* cl5Addr = &cl5;
    // Task 6.
    int ar1[3] = {1, 2, 3};
    int* element = &ar1[0];
    function_11_6(element);
    cout << "Function_11_6 has called, result : " << *element << endl;
    // Task 7.
    int int7_1 = 1, int7_2 = 2;
    int* ar7[2] = {&int7_1, &int7_2};
    int** elem7 = &ar7[0];
    function_11_7(elem7);
    cout << "Function_11_7 has called, result : " << **elem7 << endl;
    // Task 8. Positive.
    char c8 = 'a';
    char& cRef = c8;
    cout << "Task's 8 char = " << cRef;
    function_11_8(cRef);
    cout << ", after function_11_8 = " << cRef << endl;
    // Task 9. see .h and .cpp files.
    // Tasks 10-13. Bonus. See .cpp file.
    char c11 = 'a';
    int i11 = 10;
    float f11 = 0;
    double d11 = 0;
    function_11_11(c11, i11, f11, d11);
    Structure_13 st13;
    st13 = function_11_13(st13);
    // Task 14.
    function_11_14(3);
    // Task 15.
    Class_11_15_2 cl15;
    cl15.s = 3;
    cl15.clP.t = 5;
    function_11_15(1, cl15);
    // Task 16. Try again
    Class_11_16 cl16;
    function_11_16_1(cl16);
    Class_11_16 cl16_2 = function_11_16_2();
    cl16_2.str = "new 2";
    // Task 17.
    Class_11_17 cl17(3);
    function_11_17(cl17);
    // Task 18.
    Class_11_18 cl18;
    function_11_18(cl18);
    // Task 19.
    Class_11_19_2 cl19;
    cl19.function_1(cl19);
    // Task 20.
    // ivalid initialization of non-const reference of type 'Class_11_20&' from an rvalue 'Class_11_20'.
    function_11_20_2(function_11_20_1());
    // Task 21.
    Class_11_21 cl21;
    // 'Class_11_21::Class_11_21(const Class_11_21&)' is private
    // function_11_21(cl21);
    // Task 22. Not clear...
    // Task 23. Copy constructor instead of constructor overload.
    String_11 str23("Class String_11 string.");
    str23.print(std::cout);
    str23.concat(" And let's test a copy constructor.");
    str23.print(std::cout);
    function_11_23_1(str23);
    Mem_11 mem23(16);
    function_11_23_2(mem23);
    // Task 24.
    Class_11_24 cl24(3);
    Class_11_24* clPtr = &cl24;
    double Class_11_24::*clDouble = &Class_11_24::d;
    void (Class_11_24::*printPtr)() = &Class_11_24::print;
    cout << "Double from Class_11_24. Call as object = " << cl24.*clDouble << endl;
    cout << "Double from Class_11_24. Call as pointer = " << clPtr->*clDouble << endl;
    cout << "Calling function print(), Class_11_24." << endl;
    (clPtr->*printPtr)();
    // Task 25.
    int ar25[3] = {1, 2, 3};
    Class_11_25 cl25(ar25);
    int (Class_11_25::*intPtr)[3] = &Class_11_25::ar;
    cout << "Elements of array in Class_11_25 : ";
    for (int i = 0; i < 3; i++) {
        cout << (cl25.*intPtr)[i] << " ";
    }
    cout << endl;
    // Task 26.
    Class_11_26 cl26;
    int (Class_11_26::*f1Ptr)(float) const = &Class_11_26::f;
    int (Class_11_26::*f2Ptr)(bool) const = &Class_11_26::f;
    cout << "Return of function f(float) from Class_11_26 : " << (cl26.*f1Ptr)(float(1.0)) << endl;
    cout << "Return of function f(bool) from Class_11_26 : " << (cl26.*f2Ptr)(bool(true)) << endl;
    // Task 27-28.
    Class_11_27 cl27;
    void (Class_11_27::*funcPtr)() = &Class_11_27::function_1;
    cl27.add(funcPtr);
    funcPtr = &Class_11_27::function_2;
    cl27.add(funcPtr);
    funcPtr = &Class_11_27::function_3;
    cl27.add(funcPtr);
    cl27.run();
}

void chapter_12() {
    cout << "Chapter's 12 tasks.\n";
    // Task 1. no 'operator++(int) declared for postfix '++'
    Class_12_1 cl1;
    ++cl1;
    cl1++;
    // Task 2-8. Prefix never used as right value.
    Class_12_2 cl2_1(3), cl2_2(5), cl2_3(2);
    cout << "Integers of Class_12_2 : " << endl;
    cout << cl2_1; //.print(std::cout);
    cout << cl2_2;
    cout << "Operator '+' result, integer : ";
    cl2_1 = cl2_1 + cl2_2;
    cout << cl2_1;
    cout << "Expression 'a + b - c' = ";
    cl2_1 = cl2_1 + cl2_3 - cl2_2;
    cout << cl2_1;
    cout << "Class_12_2, prefix operator ++ : ";
    ++cl2_1;
    cout << cl2_1;
    cl2_3 = cl2_1++;
    cout << "Class_12_2, third object (c) = a++ : ";
    cout << cl2_3;
    cout << "Class_12_2, first object after postfix operator '++' = ";
    cout << cl2_1;
    cout << "Class_12_2, operator (-) for first object = ";
    cl2_1 = -cl2_1;
    cout << cl2_1;
    // Task 9-10.
    Class_12_9 cl9('a');
    cout << cl9;
    cin >> cl9;
    cout << cl9;
    cl9++;
    cl9--;
    // Task 11-12.
    Number_12 cl11_1(1), cl11_2(2), cl11_3(3);
    cout << "Class Number_12 (a+b) : " << cl11_1 + cl11_2;
    cout << "Class Number_12 (c-b) : " << cl11_3 - cl11_2;
    cout << "Class Number_12 (a*b*c) : " << cl11_1*cl11_2*cl11_3;
    function_12_12(cl11_1);
    // Task 13.
    int ar13[] = { 1, 2 };
    Class_12_13 cl13_1(&ar13[0]), cl13_2(&ar13[1]);
    cl13_1.print();
    cl13_2.print();
    cl13_1 = cl13_2;
    cout << "Objects after operator= : ";
    cl13_1.print();
    // Task 14-17. Public operator and copy constructor, not private.
    // Rethink about optimization.
    Bird_12 cl14_1(1), cl14_2(2), cl14_3(4);
    cout << cl14_1 << cl14_2;
    cl14_1 = cl14_2;
    cout << "Class Bird_12 object after operator= : " << cl14_1;
    cout << "Bird_12 object 1 + Bird_12 object 2 = " << cl14_1 + cl14_2;
    cout << "Bird_12 object 2 - Bird_12 object 1 = " << cl14_2 - cl14_1;
    cout << "Bird_12 object 3 * Bird_12 object 2 = " << cl14_3 * cl14_2;
    cout << "Bird_12 object 3 / Bird_12 object 2 = " << cl14_3 / cl14_2;
    BirdHouse_12 cl15_1(cl14_1, cl14_2, cl14_3, 1);
    BirdHouse_12 cl15_2(cl14_2, cl14_3, cl14_3, 2);
    BirdHouse_12 cl15_3(cl14_1, cl14_1, cl14_1, 3);
    cl15_3 = cl15_2 = cl15_1;
    cout << cl15_1 << cl15_2 << cl15_3;
    BirdHouse_12 cl15_4(cl14_1, cl14_1, cl14_1, 4);
    BirdHouse_12 cl15_5(cl14_1, cl14_1, cl14_1, 5);
    cout << "BirdHouse object 4 + BirdHouse object 5 : \n" << cl15_4 << cl15_5;
    cout << "Result of operator+ for objects above :\n" << cl15_4 + cl15_5;
    cout << "Result of operator- for objects above :\n" << cl15_4 - cl15_5;
    cout << "Result of operator* for objects above :\n" << cl15_4 * cl15_5;
    cout << "Result of operator/ for objects above :\n" << cl15_4 / cl15_5;
    // Task 18.
    Obj_18 objects[3];
    ObjContainer_18_1 cont18;
    for (int i = 0; i < 3; i++) cont18.add(&objects[i]);
    SmartPointer_18_1 it(cont18);
    do {
        it->f();
        it->g();
    } while (it++);
    cout << "Decreasing iterator.\n";
    while (it--) {
        it->f();
        it->g();
    }
    cout << "Nested smart pointer :\n";
    ObjContainer_18_2 cont18_2;
    for (int i = 0; i < 3; i++) cont18_2.add(&objects[i]);
    ObjContainer_18_2::SmartPointer_18_2 it2 = cont18_2.begin();
    do {
        it2->f();
        it2->g();
    } while (it2++);
    cout << "Decreasing iterator.\n";
    while (it2--) {
        it2->f();
        it2->g();
    }
    // Task 19. conversation from 'int' to non-scalar type 'Class_12_19_2' requested
    Class_12_19_2 cl19_1;
    Class_12_19_1 cl19_2;
    cl19_1 = cl19_2;
    // Task 20. see chapter_12.cpp
    // Task 21. May be not correct.
    Class_12_21 cl21_1("Class_12_21 string."), cl21_2;
    cout << "Class_12_21 string = " << cl21_1.s;
    cl21_1 = cl21_2;
    cout << " after operator= : " << cl21_1.s << endl;
    // Task 22. If new object doesn't create, then application crash, while trying to free memory.
    DogHouse_12_1 dh1(new Dog_12_1("Dog-1"), "Dog's-1 house");
    cout << dh1 << endl;
    DogHouse_12_1 dh2 = dh1;
    cout << dh2 << endl;
    dh2.getDog()->rename("Dog-1-rename");
    dh2.rename("Dog-1's house-rename");
    cout << dh2 << endl;
    dh1 = dh2;
    cout << "After operator= : " << dh1 << endl;
    // Task 23.
    cout << "Task 23.\n";
    DogHouse_12_2 dh2_1(Dog_12_2::make("Fido"), "FidoHouse"), dh2_2(Dog_12_2::make("Spot"), "SpotHouse");
    cout << "Entering copy-construction.\n";
    DogHouse_12_2 dh2_3(dh2_1);
    cout << "After copy-constructing bobs.\n";
    cout << "fidos: " << dh2_1 << endl;
    cout << "spots: " << dh2_2 << endl;
    cout << "bobs: " << dh2_3 << endl;
    cout << "Entering spots = fidos.\n";
    dh2_2 = dh2_1;
    cout << "After spots = fidos.\n";
    cout << "spots: " << dh2_2 << endl;
    cout << "Entering self assigment.\n";
    dh2_3 = dh2_3;
    cout << "After self-assigment.\n";
    cout << "bobs: " << dh2_3 << endl;
    // Task 24.
    Class_12_24_1 cl24_1("String-24-1"), cl24_2("String-24-2");
    Class_12_24_2 cl24_3("String-24-3"), cl24_4("String-24-4");
    cl24_2 = cl24_1;
    cout << "Class_12_24_1 object 2, string = " << cl24_2.s << endl;
    cl24_4 = cl24_3;
    cout << cl24_4;
    // Task 25.
    Integer_12 cl25_1(1), cl25_2(2), cl25_3;
    cout << "Trying all operators...\n";
    cl25_1 = +cl25_1;
    cl25_1 = -cl25_1;
    cl25_1 = ~cl25_1;
    cl25_1 = !cl25_1;
    cl25_1 = *(&cl25_1);
    ++cl25_1;
    cl25_1++;
    --cl25_1;
    cl25_1--;
    cl25_3 = cl25_1 + cl25_2;
    cl25_3 = cl25_1 - cl25_2;
    cl25_3 = cl25_1 * cl25_2;
    cl25_3 = cl25_1 / cl25_2;
    cl25_3 = cl25_1 % cl25_2;
    cl25_3 = cl25_1 ^ cl25_2;
    cl25_3 = cl25_1 & cl25_2;
    cl25_3 = cl25_1 | cl25_2;
    cl25_3 = cl25_1 << cl25_2;
    cl25_3 = cl25_1 >> cl25_2;
    cl25_3 += cl25_2;
    cl25_3 -= cl25_2;
    cl25_3 *= cl25_2;
    cl25_3 /= cl25_2;
    cl25_3 %= cl25_2;
    cl25_3 ^= cl25_2;
    cl25_3 &= cl25_2;
    cl25_3 |= cl25_2;
    cl25_3 >>= cl25_2;
    cl25_3 <<= cl25_2;
    bool r25;
    r25 = (cl25_1 == cl25_2);
    r25 = (cl25_1 != cl25_2);
    r25 = (cl25_1 > cl25_2);
    r25 = (cl25_1 < cl25_2);
    r25 = (cl25_1 >= cl25_2);
    r25 = (cl25_1 <= cl25_2);
    r25 = (cl25_1 && cl25_2);
    r25 = (cl25_1 || cl25_2);
    // Task 26.
    cout << "Task 26.\n";
    Dog_26 d26;
    Dog_26::pmf ptr = &Dog_26::run;
    cout << (d26->*ptr)(1) << endl;
    ptr = &Dog_26::eat;
    cout << (d26->*ptr)(1) << endl;
    ptr = &Dog_26::sleep;
    cout << (d26->*ptr)(1) << endl;
    void (Dog_26::*ptv)() const;
    ptv = &Dog_26::function_1;
    (d26->*ptv)();
    ptv = &Dog_26::function_2;
    (d26->*ptv)();
    // Task 27. Rethink.
    cout << "Task_27.\n";
    Obj_27::fPtr ptr27 = &Obj_27::function_1;
    Obj_27 obj27_1(1, ptr27);
    ObjContainer_27 cont27;
    cont27.add(&obj27_1);
    (cont27->*ptr27)();
    ptr27 = &Obj_27::function_2;
    (cont27->*ptr27)();
    // Task 28.
    Orange_12 cl28;
    cout << "Task 28. Function called.\n";
    function_12_28(cl28);
    // Task 29.
    Number_12_1 n1(1), n2(3);
    cout << "Nmber_12_1 reflexivity test." << endl;
    n1 * n2;
    n1 * 1;
    3 * n2;
    // Task 30.
    Class_12_30_1 cl31_1(1);
    Class_12_30_2 cl31_2(2);
    cl31_1 + cl31_2;
    cl31_2 + cl31_1;
    // Task 31. call of overloaded 'function_31(Apple_12_1&)' is ambigious
    Apple_12_1 cl31;
    // function_31(cl31);
}

void chapter_13() {
    cout << "Chapter's 13 tasks.\n";
    // Task 1.
    Counted cl1_1, cl1_2;
    cl1_1.function_1();
    cl1_2.function_1();
    // Task 2.
    Counted* clPtr2_1 = new Counted;
    Counted* clPtr2_2 = new Counted[3];
    delete []clPtr2_2;
    delete clPtr2_1;
    // Task 3. Not good example, count() method doesn't work.
    PStash cl3;
    cl3.add((void*)&cl1_1);
    cl3.add((void*)&cl1_2);
    cl3.remove(1);
    cl3.remove(0);
    // Tasks 4-5.
    vector<Counted*> vec4;
    for (int i = 0; i < 3; i++) vec4.push_back(new Counted);
    cout << "Objects of Counted in vector.\n";
    for (int i = 0; i < 3; i++) {
        cout << (long)vec4[i] << ": ";
        vec4[i]->function_1();
    }
    for (int i = 0; i < 3; i++) delete vec4[i];
    // Task 6.
    PStash cl6;
    cl6.add((void*) new Counted);
    cl6.add((void*) new Counted);
    cout << "Counted objects from PSTash.\n";
    for (int i = 0; i < 2; i++) {
        Counted* ptr = (Counted*)cl6[i];
        ptr->function_1();
    }
    cl6.remove(1);
    cl6.remove(0);
    // Task 7.
    Stack st7;
    st7.initialize();
    cout << "Task 7 with Stack structure from chapter 4, doubles : ";
    for (int i = 0; i < 3; i++) st7.push(new double(i));
    for (int i = 0; i < 3; i++) cout << *st7.pop() << " ";
    cout << endl;
    // Tasks 8-9.
    Counted* ar8 = new Counted[3];
    // invalid pointer
    // delete ar8;
    delete []ar8;
    Counted* ptr9 = new Counted;
    void* ptr9_1 = (void*)ptr9;
    // deleting 'void*' is undefined
    // delete ptr9_1;
    delete ptr9;
    // Task 10. Bonus.
    // Task 11.
    Class_13_11* cl13_1 = new Class_13_11;
    Class_13_11* cl13_2 = new Class_13_11[3];
    delete cl13_1;
    delete []cl13_2;
    // Task 12. Faster x4. Multiplier was decreased x10.
    time_t time;
    tm local;
    time = std::time(NULL);
    local = *std::localtime(&time);
    int startTimer = local.tm_sec;
    cout << "Starting second : " << startTimer;
    for (int i = 0; i < 10000; i++) for (int j = 0; j < 1000; j++) {
        Framis_13* framis_ptr = ::new Framis_13;
        ::delete framis_ptr;
    }
    time = std::time(NULL);
    local = *std::localtime(&time);
    int finishTimer = local.tm_sec;
    cout << ", after calling standart operators new & delete : " << finishTimer << endl;
    cout << "After calling Framis operators: ";
    for (int i = 0; i < 10000; i++) for (int j = 0; j < 1000; j++) {
        Framis_13* framis_ptr = new Framis_13;
        delete framis_ptr;
    }
    time = std::time(NULL);
    local = *std::localtime(&time);
    finishTimer = local.tm_sec;
    cout << finishTimer << endl;
    // Task 13. Bonus.
    // Task 14.
    char s14_1[8], s14_2[8];
    sprintf(s14_1, "%d", __LINE__);
    sprintf(s14_2, "%d", __LINE__);
    Class_13_14* cl14_1 = new(string(s14_1)) Class_13_14;
    Class_13_14* cl14_2 = new(string(s14_2)) Class_13_14;
    cout << "Class_13_14, storage : ";
    for (int i = 0; i < Class_13_14::storage.size(); i++)
        cout << Class_13_14::storage[i] << " ";
    cout << endl;
    // Task 15.
    MemoryChecker mChecker;
    Widget_13* cl15_1 = new Widget_13;
    Widget_13* cl15_2 = new Widget_13[2];
    cout << "Widget_13 pointers : " << (long)cl15_1 << " " << (long)&cl15_2[0] << " " << (long)&cl15_2[1] << endl;
    cout << "Widget_13, storage : ";
    for (int i = 0; i < 3; i++) cout << (long)Widget_13::storage[i] << " ";
    cout << endl;
    delete []cl15_2;
    delete cl15_1;
}

void chapter_14() {
    cout << "Chapter's 14 tasks.\n";
    // Task 1.
    Car_14 cl1(1);
    // Task 2.
    Class_14_2_3 cl2;
    // Task 3.
    Class_14_3_3 cl3;
    // Task 4-5.
    Combined_D cl4(3);
    // Task 6.
    Derived_6_3 cl6(1);
    // Task 7-8.
    string s7 = "Task7";
    Derived_7_1 cl7_1;
    int i7 = cl7_1.f();
    Derived_7_2 cl7_2;
    // no matching for call to 'Derived_7_2::f(std::string&'
    // cl7_2.f(s7);
    Derived_7_3 cl7_3;
    // note: candidate expects 0 arguments, 1 provided
    // i7 = cl7_3.f();
    Derived_7_4 cl7_4;
    i7 = cl7_4.f(1);
    cl7_1.h(1);
    // Task 9. invalid conversation. Task not clear.
    StringStack cl9;
    void* ptr = (void*)&s7;
    cl9.push_back(&s7);
    // cl9.push_back(ptr);
}

void Labs_0x01() {
    chapter_14();
}
