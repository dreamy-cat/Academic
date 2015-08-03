#include "labs_0x00.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>

int getLine(char line[], FILE* stream, int limit) {
    char c;
    int i;
    for (i = 0; i < limit-1 && (c = getc(stream)) != EOF && c != '\n'; ++i)
        line[i] = c;
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}

void copyLine(char dest[], char source[]) {
    /* Copy // line function. */
    int i = -1; /* Complex comment for task 1-23.
                 *
                 */ i++;
    while ((dest[i] = source[i]) != '\0') ++i;
}

void reverse(char source[], int length) {
    for (int i = 0; i < length/2; i++) {
        char c = source[i];
        source[i] = source[length-1-i];
        source[length-1-i] = c;
    }
}

float toCelsius(float fahr) {
    return (5.0/9.0) * (fahr-32);
}

void chapter_1() {
    printf("Hello World!\n");
    // unknown escape sequence '\c'
    // printf("\c");
    float fahr, celsius;
    int upper = 300, lower = 0, step = 20;
    fahr = lower;
    printf ("Fahrenheit Celsius:\n");
    while (fahr <= upper) {
        celsius = (5.0 / 9.0) * (fahr - 32);
        printf ("%8.0f %8.1f\n", fahr, celsius);
        fahr += step;
    }
    upper = 100;
    lower = -50;
    step = 10;
    celsius = lower;
    printf ("Celsius Fahrenheit:\n");
    while (celsius <= upper) {
        fahr = celsius * (9.0/5.0) + 32;
        printf ("%8.1f %8.1f\n", celsius, fahr);
        celsius += step;
    }
    printf("Fahrenheit Celsius:\n");
    for (fahr = 300; fahr >= 0; fahr -= 20)
        printf("%5.1f %8.1f\n", fahr, (5.0/9.0) * (fahr-32));
    printf("Press any key.\n");
    printf("'getchar() != EOF' = %d, EOF = %d\n", getchar() != EOF, EOF);
    FILE* text = fopen("labs_0x00/files/chapter-1.txt", "r");
    char c, pc = 0;
    int spaces = 0, tabs = 0, lines = 0;
    printf("Original file 'labs_0x00/files/chapter-1.txt'(with tabs):\n");
    while ((c = getc(text)) != EOF) {
        if (c == ' ') spaces++;
        if (c == '\t') {
            printf("\\");
            c = 't';
            tabs++;
        }
        if (c == '\n') lines++;
        printf("%c", c);
        pc = c;
    }
    printf("Spaces in text: %d, tabs: %d, full lines: %d\n\n", spaces, tabs, lines);
    fseek(text, 0, 0);
    printf("Task result:\n");
    while ((c = getc(text)) != EOF) {
        if ((c == ' ' && c != pc) || (c != ' '))
            printf("%c", c);
        pc = c;
    }
    fseek(text, 0, 0);
    int isWord = 0, words = 0, wordLength = 0;
    int wordsSizes[16], symbolsFreq[128];
    for (int i = 0; i < 16; i++) wordsSizes[i] = 0;
    for (int i = 0; i < 128; i++) symbolsFreq[i] = 0;
    printf("List of 3 first words: \n");
    while ((c = getc(text)) != EOF) {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            if (!isWord) {
                isWord = 1;
                words++;
            }
            wordLength++;
            if (words <= 3) printf("%c", c);
        } else {
            if (isWord) {
                if (wordLength < 16) wordsSizes[wordLength]++;
                wordLength = 0;
                isWord = 0;
            }
            if (words <= 3) printf("\n");
        }
        symbolsFreq[c]++;
    }
    printf("\nWords in file: %d\n", words);
    printf("Histogram of word sizes(max 16 symbols):\n");
    for (int i = 0; i < 16; i++) {
        printf("%2d:", i);
        for (int j = 0; j < wordsSizes[i]; j++) printf(".");
        printf("\n");
    }
    printf("Histogram of symbols(without 0 values):\n");
    for (int i = 0; i < 128; i++)
        if (symbolsFreq[i] > 0) {
            printf("%2d:", i);
            for (int j = 0; j < symbolsFreq[i]; j++) printf(".");
            printf("\n");
        }
    upper = 300, lower = 0, step = 20;
    fahr = lower;
    printf ("Fahrenheit Celsius(with function):\n");
    while (fahr <= upper) {
        printf ("%8.0f %8.1f\n", fahr, toCelsius(fahr));
        fahr += step;
    }
    fseek(text, 0, 0);
    // Task 16-17. Strange.
#define MAXLENGTH 256
    char line[MAXLENGTH], maxLine[MAXLENGTH];
    int sizeOfLine = 0, maxSizeLine = 0;

    while (sizeOfLine = getLine(line, text, MAXLENGTH)) {
        if (sizeOfLine > maxSizeLine) {
            copyLine(maxLine, line);
            maxSizeLine = sizeOfLine;
        }
    }
    printf("Maximum line: ");
    if (maxSizeLine > 0) printf("%s", maxLine); else printf("Not exist.");
    fseek (text, 0,0);
    // Task 18-19.
    printf("Packed text with reverse lines(no empty lines):");
    while (sizeOfLine = getLine(line, text, MAXLENGTH)) {
        for (int i = 0; i < sizeOfLine-1; i++) {
            if (line[i] == '\t') line[i] = ' ';
            while (line[i] == ' ' && line[i+1] == ' ') {
                int j = i;
                while (line[j] != '\0') {
                    line[j] = line[j+1];
                    j++;
                }
                sizeOfLine--;
            }
        }
        if (line[0] == '\n' && sizeOfLine == 1) line[0] = '\0';
        reverse(line, sizeOfLine);
        printf("%s", line);
    }
    printf("\n");
    // Task 20.
    printf("Replace tabs with spaces from text:\n");
    fseek(text, 0, 0);
    int tabSpaces = 8;
    while ((sizeOfLine = getLine(line, text, MAXLENGTH)) > 0) {
        for (int i = 0; i < sizeOfLine; i++)
            if (line[i] == '\t') {
                for (int j = 0; j < sizeOfLine-(i+1); j++) {
                    line[sizeOfLine-1-j+tabSpaces-1] = line[sizeOfLine-1-j];
                }
                for (int j = 0; j < tabSpaces; j++) line[i+j] = ' ';
                sizeOfLine += tabSpaces-1;
                line[sizeOfLine] = '\0';
            }
        printf("%s", line);
    }
    // Task 21.
    printf("Replace spaces with tabs from text:\n");
    fseek(text, 0,0);
    while ((sizeOfLine = getLine(line, text, MAXLENGTH)) > 0) {
        int spaceCounter = 0;
        for (int i = 0; i < sizeOfLine; i++) {
            if (line[i] == ' ') {
                spaceCounter++;
                if (spaceCounter == tabSpaces) {
                   for (int j = 0; i+j < sizeOfLine; j++)
                       line[i-(tabSpaces-1-1)+j] = line[i+1+j];
                   i -= tabSpaces-1;
                   line[i] = '\t';
                   sizeOfLine -= tabSpaces-1;
                   line[sizeOfLine] = '\0';
                   spaceCounter = 0;
                }
            } else spaceCounter = 0;
        }
        printf("%s", line);
    }
   // Task 22.
   printf("Text align to 40 symbols:\n");
   int textWidth = 40;
   fseek(text, 0, 0);
   char printLine[256];
   while ((sizeOfLine = getLine(line, text, MAXLENGTH)) > 0) {
       while (sizeOfLine) {
           int isWord = 0, lastWord = -1;
           for (int j = 0; j < textWidth && j < sizeOfLine; j++) {
               if ((line[j] >= 'a' && line[j] <= 'z') || (line[j] >= 'A' && line[j] <= 'Z')) {
                   isWord = 1;
               } else {
                   if (isWord) lastWord = j;
                   isWord = 0;
               }
           }
           copyLine(printLine, line);
           if (lastWord == -1) lastWord = textWidth;
           if (sizeOfLine < textWidth) {
               lastWord = sizeOfLine;
               printLine[lastWord] = '\0';
           } else {
               printLine[lastWord] = '\n';
               printLine[lastWord+1] = '\0';
           }
           printf("%s", printLine);
           for (int j = 0; j < sizeOfLine-lastWord; j++)
               line[j] = line[lastWord+j];
           sizeOfLine -= lastWord;
       }
   }
   fclose(text);
   // Task 23-24.
   fopen("labs_0x00/labs_0x00.cpp", "r");
   printf("Main source file labs_0x00.cpp, without comments. First 30 lines and braces counters.\n");
   int inComment = -1, inString = 0, viewLines = 0;
   int openBraces = 0, closeBraces = 0;
   while ((sizeOfLine = getLine(line, text, MAXLENGTH))) {
       for (int i = 0; i < sizeOfLine-1; i++) {
           if (line[i] == '"' || line[i] == '\'') inString = inString ^ 1;
           if (!inString) {
               if (line[i] == '/' && line[i+1] == '/' && inComment == -1) {
                   sizeOfLine = i+1;
                   line[i] = '\n';
                   line[i+1] = '\0';
               }
               if (line[i] == '/' && line[i+1] == '*' && inComment == -1) {
                   inComment = i;
               }
               if (line[i] == '*' && line[i+1] == '/' && inComment != -1) {
                   for (int j = 0; j < sizeOfLine-i-2; j++)
                       line[inComment+j] = line[i+2+j];
                   inComment = -1;
                   sizeOfLine -= (i+2-inComment);
                   line[sizeOfLine+1] = '\0';
               }
           }
       }
       if (inComment != -1) {
           line[inComment] = '\n';
           line[inComment+1] = '\0';
           inComment = 0;
       } else
           for (int i = 0; line[i] != '\0'; i++) {
               if (line[i] == '{') openBraces++;
               if (line[i] == '}') closeBraces++;
           }
       if (viewLines < 30) {
           printf("%s", line);
           viewLines++;
       }
   }
   printf("Open braces in source file = %d, close braces = %d.\n", openBraces, closeBraces);
   fclose(text);
}

int htol(const char hex[]) {
    int n = 0;
    if (hex[0] != '0' && hex[1] != 'x')
        return n;
    for (int i = 2; hex[i] != '\0'; i++) {
        if (hex[i] >= '0' && hex[i] <= '9')
            n = n * 16 + (hex[i] - '0');
        if (hex[i] >= 'A' && hex[i] <= 'F')
            n = n * 16 + (hex[i] - 'A' + 10);
    }
    return n;
}

void squeeze(char source[], char toFind[]) {
    int i, j, k;
    for (i = 0, j = 0; source[i] != '\0'; i++) {
        k = 0;
        while (toFind[k] != '\0' && source[i] != toFind[k])
            k++;
        if (toFind[k] == '\0')
            source[j++] = source[i];
    }
    source[j] = '\0';
}

int any(char source[], char toFind[]) {
    for (int i = 0; source[i] != '\0'; i++) {
        for (int j = 0; toFind[j] != '\0'; j++)
            if (source[i] == toFind[j]) return i;
    }
    return -1;
}

unsigned char setBits(unsigned char x, unsigned char p, unsigned char n, unsigned char y) {
    if (n > p+1 || n > 8 || p > 7) return 0;
    y = y & (0xFF >> sizeof(char)*8-n);
    x = x & ((0xFF << p+1) | (0xFF >> sizeof(char)*8-(p+1-n)));
    x = x | (y << (p+1-n));
    return x;
}

unsigned char invertBits(unsigned char x, unsigned char p, unsigned char n) {
    if (n > p+1 || n > 8 || p > 7) return 0;
    unsigned char mask = 0xFF << p+1 | 0xFF >> sizeof(char)*8-(p+1-n);
    x = x & mask | (~x & ~mask);
    return x;
}

unsigned char rollRightBits(unsigned char x, unsigned char n) {
    for (int i = 0; i < n; i++)
        if (x & 0x01) x = (x >> 1) | 0x80; else x = x >> 1;
    return x;
}

int bitCount(unsigned char x) {
    int b;
    for (b = 0; x > 0; b++) x &= (x-1);
    return b;
}

void lower(char text[]) {
    for (int i = 0; text[i] != '\0'; i++)
        (text[i] >= 'A' && text[i] <= 'Z') ? text[i] += 32 : text[i] = text[i];
}

void chapter_2() {
    printf("Chapter's 2 tasks.\n");
    // Task 1.
    printf ("Table of types(limits.h).\n");
    printf("Type:\t\tBits:\tMIN:\t\t\tMAX:\n");
    printf("Char\t\t%d\t%d\t\t\t%d\n", (int)sizeof(char)*8, SCHAR_MIN, SCHAR_MAX);
    printf("Unsigned char\t%d\t%d\t\t\t%d\n", (int)sizeof(char)*8, 0, UCHAR_MAX);
    printf("Short\t\t%d\t%d\t\t\t%d\n", (int)sizeof(short)*8, SHRT_MIN, SHRT_MAX);
    printf("Unsigned short\t%d\t%d\t\t\t%d\n", (int)sizeof(short)*8, 0, USHRT_MAX);
    printf("Int\t\t%d\t%d\t\t%d\n", (int)sizeof(int)*8, INT_MIN, INT_MAX);
    printf("Unsigned int\t%d\t%d\t\t\t%u\n", (int)sizeof(int)*8, 0, UINT_MAX);
    printf("Long\t\t%d\t%ld\t%lu\n", (int)sizeof(long)*8, LONG_MIN, LONG_MAX);
    printf("Unsigned long\t%d\t%d\t\t\t%lu\n", (int)sizeof(long)*8, 0, ULONG_MAX);
    printf("Float\t\t%d\t%.1f\t\t\t%.1f\n", (int)sizeof(float)*8, FLT_MIN, FLT_MAX);
    // Task 2.
    char c;
    const int limit = 1;
    for (int i = 0; i < limit; i++) {
        if ((c = getchar()) != EOF) {
            if (c != '\n') printf("Symbol: %c", c);
        }
    }
    printf("\n");
    // Task 3.
    const char hex[] = "0x1F";
    printf("Function hex 0x1F to integer:%d\n", htol(hex));
    const int maxString = 256;
    // Task 4-5.
    char string_1[maxString] = "String_1", string_2[maxString] = "tn";
    printf("Source string = %s. Symbols to cut = %s.\n", string_1, string_2);
    printf("First position in source string, where found any of symbol of string %s = %d.\n", string_2, any(string_1, string_2));
    squeeze(string_1, string_2);
    printf("String after squeeze = %s.\n", string_1);
    // Tasks 6-8.
    printf("Set 2 last bits from 0x03 byte to position 2 of 0x0F byte(hex): %x\n", setBits(0x0F, 2, 2, 0x03));
    printf("Invert 2 bits from 0x0F from position 2(hex): %x\n", invertBits(0x0F, 2, 2));
    printf("Roll cyclic 0x07 to the right, 3 bits(hex): %x\n", rollRightBits(0x07, 3));
    // Task 9.
    printf("Bits in 0x0F: %d\n", bitCount(0x0F));
    // Task 10.
    char string_10[] = "StRiNg_10";
    printf("Source string: %s\n", string_10);
    lower(string_10);
    printf("String after calling function lower: %s\n", string_10);
}

int binSearch(int x, int v[], int n) {
    int low = 0, high = n-1, mid = (low+high)/2;
    while (low <= high && v[mid] != x) {
        if (x < v[mid]) high = mid -1; else low = mid + 1;
        mid = (low + high) / 2;
    }
    if (low <= high) return mid; else return -1;
}

void escape(char s[], char t[]) {
    int j = 0;
    for (int i = 0; t[i] != '\0'; i++)
        switch (t[i]) {
        case '\t':
            s[j++] = '\\';
            s[j++] = 't';
            break;
        case '\n':
            s[j++] = '\\';
            s[j++] = 'n';
            break;
        default:
            s[j++] = t[i];
            break;
        }
    s[j] = '\0';
}

void toText(char s[], char t[]) {
    int j = 0;
    for (int i = 0; t[i] != '\0'; i++)
        switch (t[i]) {
        case '\\':
            switch (t[i+1]) {
            case 't':
                s[j++] = '\t';
                i++;
                break;
            case 'n':
                s[j++] = '\n';
                i++;
                break;
            default:
                s[j++] = t[i];
            }
            break;
        default:
            s[j++] = t[i];
        }
    s[j] = '\0';
}

void chapter_3() {
    printf("Chapter's 3 tasks.\n");
    // Task 1. May be not right...
    const int arraySize = 5;
    int array_1[arraySize];
    printf("Array of int: ");
    for (int i = 0; i < arraySize; i++) {
        array_1[i] = i;
        printf("%d ", array_1[i]);
    }
    printf("\nFind position of element = 1: %d\n", binSearch(1, array_1, arraySize));
    // Task 2.
    FILE* textFile = fopen("labs_0x00/files/chapter-3.txt", "r");
    const int maxLineSize = 128;
    char text[maxLineSize], line_1[maxLineSize], line_2[maxLineSize];
    int lineSize;
    printf("File 'chapter-3.txt' with special symbols, as is: \n");
    while ((lineSize = getLine(text, textFile, maxLineSize))) {
        escape(line_1, text);
        printf("%s\n", line_1);
        toText(line_2, line_1);
        printf("Original text: %s", line_2);
    }
    fclose(textFile);
}

void labs_0x00() {
    chapter_3();
}
