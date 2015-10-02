#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
#include <math.h>
#include <stdarg.h>
#include <sys/file.h>
#include <sys/syscall.h>
#include <sys/io.h>
#include <sys/fcntl.h>
#include <sys/unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/dir.h>
#include <syscall.h>
#include <dirent.h>

#include "labs_0x00.h"

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

void expand(char s1[], char s2[]) {
    int j = 0, k = 0;
    const char intervals[6] = { 'a', 'z', 'A', 'Z', '0', '9' };
    for (int i = 0; s1[i] != '\0'; i++) {
        for (k = 0; !(s1[i] >= intervals[k*2] && s1[i] <= intervals[k*2+1]) && k < 3; k++);
        if (k != 3 && s1[i+1] != '\0' && s1[i+2] != '\0') {
            int startSeq = i;
            while  (s1[i+1] == '-' && s1[i+2] >= intervals[k*2] && s1[i+2] <= intervals[k*2+1]) {
                i += 2;
            }
            for (char c = s1[startSeq]; c <= s1[i]; c++) s2[j++] = c;
        } else s2[j++] = s1[i];
    }
    s2[j++] = '\0';
}

void itoa(unsigned char n, int sign, char s[]) {
    int i = 0;
    while (n) {
        s[i++] = n % 10 + '0';
        n = n / 10;
    }
    if (i == 0) s[i++] = '0';
    if (sign < 0) s[i++] = '-';
    for (int j = 0; j < i / 2; j++) {
        char c = s[j];
        s[j] = s[i-1-j];
        s[i-1-j] = c;
    }
    s[i] = '\0';
}

void itob(unsigned char n, char s[], unsigned char b) {
    if (b > 16) return;
    const char characters[] = "0123456789ABCDEF";
    int i = 0;
    while (n) {
        s[i++] = characters[n % b];
        n = n / b;
    }
    if (i == 0) s[i++] = '0';
    for (int j = 0; j < i / 2; j++) {
        char c = s[j];
        s[j] = s[i-1-j];
        s[i-1-j] = c;
    }
    s[i] = '\0';
}

void itoa (unsigned char n, char s[], unsigned char field) {
    int i = 0;
    while (n) {
        s[i++] = n % 10 + '0';
        n = n / 10;
    }
    if (i == 0) s[i++] = '0';
    for (int j = i; j < field; j++)
        s[i++] = ' ';
    for (int j = 0; j < i / 2; j++) {
        char c = s[j];
        s[j] = s[i-1-j];
        s[i-1-j] = c;
    }
    s[i] = '\0';
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
    // Task 3.
    char line_31[maxLineSize] = "a-e0-3 -a-c-e-- ok.c-a", line_32[maxLineSize];
    expand(line_31, line_32);
    printf("Expand line %s to %s\n", line_31, line_32);
    // Task 4.
    char line_4[maxLineSize];
    itoa(128, -1, line_4);
    printf("Iteger -128 to string = %s\n", line_4);
    // Task 5.
    char line_5_1[maxLineSize], line_5_2[maxLineSize], line_5_3[maxLineSize];
    itob(15, line_5_1, 10);
    itob(15, line_5_2, 2);
    itob(15, line_5_3, 16);
    printf("Integer 15 in binary, decimal and hex : %s %s %s\n", line_5_1, line_5_2, line_5_3);
    // Task 6.
    char line6_1[maxLineSize];
    itoa(15, line6_1, 4);
    printf("Integer 15 and field = 4:%s\n", line6_1);
}

int strIndex(char s[], char t[]) {
    int i, j, p = -1;
    for (i = 0; s[i] != '\0'; i++) {
        for (j = 0;  t[j] != '\0' && s[i+j] != '\0' && s[i+j] == t[j]; j++);
        if (t[j] == '\0') p = i;
    }
    return p;
}

double aToF(const char s[]) {
    double val, power;
    int i, sign;
    for (i = 0; !(s[i] >= '0' && s[i] <= '9') && s[i] != '-' && s[i] != '+'; i++);
    if (s[i] == '-') sign = -1; else sign = +1;
    if (s[i] == '-' || s[i] == '+') i++;
    for (val = 0.0; s[i] >= '0' && s[i] <= '9'; i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.') i++;
    for (power = 1.0; s[i] >= '0' && s[i] <= '9'; i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }
    if ((s[i] == 'E' || s[i] == 'e') && (s[i+1] == '-' || s[i+1] == '+')) {
        double exp = 0.0, multiplier;
        if (s[i+1] == '+') multiplier = 10.0; else multiplier = 0.1;
        i += 2;
        while (s[i] >= '0' && s[i] <= '9')
            exp = exp * 10 + (s[i++] - '0');

        while (exp > 0) {
            power /= multiplier;
            exp -= 1.0;
        }
    }
    return sign * val / power;
}

// Chapter's 4 variables.

const int stackSize = 16;
int sp = 0;
double stack4[stackSize];
static const int bufSize = 8;
static char buf4[bufSize];

void push(double value) {
    if (sp < stackSize) stack4[sp++] = value; else printf("Push error, stack is full.\n");
}

double pop() {
    if (sp > 0) return stack4[--sp]; else { printf("Pop error, stack empty.\n"); return -1; }
}

void printTop() {
    if (sp > 0) printf("Top element in stack: %.2f\n", stack4[sp-1]); else
        printf("Stack is empty.\n");
}

void copyTop() {
    if (sp > 0) {
        stack4[sp] = stack4[sp-1];
        sp++;
        printf("Top element %.2f in stack has copied to new top.\n", stack4[sp-2]);
    } else printf("Stack is empty.\n");
}

void exchangeTop() {
    if (sp > 1) {
        double element = stack4[sp-1];
        stack4[sp-1] = stack4[sp-2];
        stack4[sp-2] = element;
        printf("Exchange top two elements %.2f and %.2f in stack.\n", stack4[sp-2], stack4[sp-1]);
    } else printf("Stack has less than two elements.\n");
}

void clearStack() {
    if (sp > 0) sp = 0; else printf("Nothing to clear. Stack is empty.\n");
}

int saveLine(char line[], FILE* stream) {
    int i, written = 1;
    for (i = 0; line[i] != '\0' && written != EOF; i++)
        written = putc(line[i], stream);
    return i;
}

int itoaRec (unsigned char n, char s[]) {
    if (n / 10) itoaRec((unsigned char)(n / 10), s);
    int i = 0;
    while (s[i] != '\0') i++;
    s[i++] = n % 10 + '0';
    s[i] = '\0';
    return i;
}

void reverseRec(char source[], int first, int last) {
    if (first+1 < last-1)
        reverseRec(source, first+1, last-1);
    char c = source[first];
    source[first] = source[last];
    source[last] = c;
}

void chapter_4() {
    printf("Chapter's 4 tasks.\n");
    // Task 1.
    char string1_1[] = "string_1 testing", string1_2[] = "ing";
    printf("Right position of substring %s, in %s string: %d.\n", string1_1, string1_2, strIndex(string1_1, string1_2));
    // Task 2.
    char string2[] = "-2.5E+2";
    printf ("E notation of number %s = %.2f\n", string2, aToF(string2));
    // Task 3-6. Errors correction works only with symbols. Task 6 - only read/write 1 variable.
    const int maxLength = 256;
    const char string3_1[] = "3 D + 4 2 X / * P 0 S + 2 4 O + 0 E + 1 W R +", symTable[] = "0123456789+-*/%PDCXSOERW";
    char operandStr[maxLength];
    int operandSize = 0;
    double operand, extraOperand, variable = 0.0;
    for (int i = 0; string3_1[i] != '\0'; i++) {
        int k;
        for (k = 0; symTable[k] != '\0' && string3_1[i] != symTable[k]; k++);
        if (symTable[k] != '\0') operandStr[operandSize++] = string3_1[i];
        if ((string3_1[i+1] == ' ' || string3_1[i+1] == '\0') && operandSize > 0) {
            if (operandStr[operandSize-1] >= '0' && operandStr[operandSize-1] <= '9') {
                operandStr[operandSize] = '\0';
                // printf("oper %s = %f\n", operandStr, aToF(operandStr));
                push(aToF(operandStr));
            } else {
                switch (operandStr[0]) {
                case '+':
                    push(pop() + pop());
                    break;
                case '-':
                    operand = pop();
                    push(pop() - operand);
                    break;
                case '*':
                    push(pop() * pop());
                    break;
                case '/':
                    operand = pop();
                    if (operand != 0) push(pop() / operand); else {
                        printf("Division by zero.\n");
                        push(0.0);
                    }
                    break;
                case '%':
                    operand = pop();
                    if (operand != 0) push((long)pop() % (long)operand); else {
                        printf("Division by zero.\n");
                        push(0.0);
                    }
                    break;
                case 'P':
                    printTop();
                    break;
                case 'D':
                    copyTop();
                    break;
                case 'C':
                    clearStack();
                    break;
                case 'X':
                    exchangeTop();
                    break;
                case 'S':
                    operand = pop();
                    printf("Sin %.2f = %.2f\n", operand, sin(operand));
                    push(sin(operand));
                    break;
                case 'E':
                    operand = pop();
                    printf("Exponential function of %.2f = %.2f\n", operand, exp(operand));
                    push(exp(operand));
                    break;
                case 'O':
                    operand = pop();
                    extraOperand = pop();
                    printf("Power value %2.f to %.2f = %.2f\n", extraOperand, operand, pow(operand, extraOperand));
                    push (pow(extraOperand, operand));
                    break;
                case 'W':
                    variable = pop();
                    printf("Write top value %.2f from stack to variable.\n", variable);
                    break;
                case 'R':
                    push(variable);
                    printf("Read variable %.2f and push to stack.\n", variable);
                    break;
                default:
                    printf("Something goes wrong with operator...\n");
                }
            }
            operandSize = 0;
        }
    }
    printf("Result of expression %s = %.2f\n", string3_1, pop());
    // Tasks 7-11. Task 11 - nothing to do, because of input method.
    FILE* source = fopen("labs_0x00/files/chapter-1.txt", "r");
    FILE* dest = fopen ("labs_0x00/files/chapter-4.txt", "w");
    char line[maxLength];
    int len;
    while ((len = getLine(line, source, maxLength)) > 0)
        saveLine(line, dest);
    fclose(dest);
    fclose(source);
    // Task 12-13.
    char line12[maxLength] = "";
    int lenStr = itoaRec(128, line12);
    printf("Integer 128 to string : %s, length = %d\n", line12, lenStr);
    reverseRec(line12, 0, lenStr-1);
    printf("Reverse previous string, using function with recursion: %s\n", line12);
    // Task 14.
#define swap(T,X,Y) \
    T temp; \
    temp = X; \
    X = Y; \
    Y = temp;
    char line14[] = "AB";
    swap(char,line14[0],line14[1]);
    printf("Swap characters in string 'AB': %s\n", line14);
}

int getInt(const char s[]) {
    int n = 0, i = 0, sign;
    while (!(s[i] >= '0' && s[i] <= '9') && s[i] != '-' && s[i] != '+' && s[i] != '\0')
        i++;
    if (s[i] == '-') sign = -1; else sign = 1;
    if (s[i] == '-' || s[i] == '+') i++;
    for (; s[i] != '\0'; i++)
        if (s[i] >= '0' && s[i] <= '9')
            n = n * 10 + s[i] - '0';
    return sign * n;
}

float getFloat(const char s[]) {
    float f = 0;
    int sign = 0, i = 0, power = 1;
    while (!(s[i] >= '0' && s[i] <= '9') && s[i] != '-' && s[i] != '+')
        i++;
    if (s[i] == '-') sign = -1; else sign = 1;
    if (s[i] == '-' || s[i] == '+') i++;
    for (; s[i] != '\0' && s[i] != '.'; i++)
        if (s[i] >= '0' && s[i] <= '9')
            f = f * 10 + s[i] - '0';
    if (s[i++] == '.')
        for (; s[i] != '\0'; i++)
            if (s[i] >= '0' && s[i] <= '9') {
                f = f * 10 + s[i] - '0';
                power *= 10;
            }
    return sign * f / power;
}

void strCat(char s[], const char t[]) {
    while (*s != '\0')
        s++;
    while (*s++ = *t++);
}

int strEnd(char s[], char t[]) {
    char *sp = s, *tp = t;
    while (*sp != '\0')
        sp++;
    while (*tp != '\0')
        tp++;
    while (*sp-- == *tp-- && sp != s && tp != t);
    if (tp == t) return 1; else return 0;
}

char* strnCpy(char s1[], char s2[], int n) {
    int m = n;
    while ((*s1++ = *s2++) && --n) ;
    return s1 - (m - n);
}

char* strnCat(char s1[], const char s2[], int n) {
    char *s3 = s1;
    while (*s1 != '\0')
        s1++;
    while ((*s1++ = *s2++) && --n);
    return s3;
}

int strnCmp(const char s1[], const char s2[], int n) {
    while (*s1 == *s2 && --n && *s1 != '\0' && *s2 != '\0') {
        s1++;
        s2++;
    }
    if (*s1 == *s2) return 0;
    if (*s1 > *s2) return 1; else return -1;
}

int getLinePtr(char line[], FILE* stream, int limit) {
    char c, *lineStart = line;
    while ((line - lineStart) < limit && (c = getc(stream)) != EOF && c != '\n')
        *line++ = c;
    if (c == '\n')
        *line++ = c;
    *line = '\0';
    return line - lineStart;
}

int itoaPtr (unsigned char n, char s[]) {
    if (n / 10) itoaPtr((unsigned char)(n / 10), s);
    int i = 0;
    while (*s != '\0')
        s++;
    *s++ = n % 10 + '0';
    *s = '\0';
    return i;
}

int atoiPtr(const char s[]) {
    int n = 0, i = 0, sign;
    while (!(*s >= '0' && *s <= '9') && *s != '-' && *s != '+' && *s != '\0')
        s++;
    if (*s == '-') sign = -1; else sign = 1;
    if (*s == '-' || *s == '+') s++;
    for (; *s != '\0'; s++)
        if (*s >= '0' && *s <= '9')
            n = n * 10 + *s - '0';
    return sign * n;
}

void reversePtr(char* first, char* last) {
    if (first+1 < last-1)
        reversePtr(first+1, last-1);
    char c = *first;
    *first = *last;
    *last = c;
}

int strIndexPtr(char s[], char t[]) {
    int i, j, p = -1;
    for ( char *sp = s;  *sp != '\0'; sp++) {
        char *tp;
        for ( tp = t;  *tp != '\0' && *(sp+(tp-t)) != '\0' && *(sp+(tp-t)) == *tp; tp++);
        if (*tp == '\0') p = sp - s;
    }
    return p;
}

// Task 5-7.

static const int maxLines = 256;
static int lines = 0;
static const char* strings[maxLines];

void readLines(const char *s[], int n) {
    if ((lines + n)>= maxLines) return;
    for (int i = 0; i < n; i++)
        strings[lines++] = s[i];
}

void writeLines(int n) {
    if (n > lines) return;
    for ( int i = 0; i < n; i++)
        printf("%2d: %s\n", i, strings[i]);
}

char toUpper(char c) {
    return (c >= 'a' && c <= 'z') ? c - ('a' - 'A') : c;
}

bool isDir(const char c) {
    return (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9' || c == ' ') ? true : false;
}

int strCmp_5(const char s1[], const char s2[], int caseSens, int dirOrder, int n) {
    while ((caseSens && (*s1 == *s2) || !caseSens && (toUpper(*s1) == toUpper(*s2))
            || (dirOrder && isDir(*s1) && isDir(*s2) && (*s1 == *s2)))
            && --n && *s1 != '\0' && *s2 != '\0') {
        s1++;
        s2++;
    }
    if (*s1 == *s2) return 0;
    if (*s1 > *s2) return 1; else return -1;
}

void swap_5(const char *v[], int i, int j) {
    const char *temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void qsort_5(const char *v[], int left, int right) {
    int i, last;
    const int maxLength = 256;
    if (left >= right) return;
    swap_5(v, left, (left + right)/2);
    last = left;
    for (i = left + 1; i <= right; i++)
        if (strCmp_5(v[i], v[left], 0, 0, maxLength) < 0)
            swap_5(v, ++last, i);
    swap_5(v, left, last);
    qsort_5(v, left, last-1);
    qsort_5(v, last+1, right);
}

// Task 5-8.

static char dayTab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

static char *tabPtr = dayTab[0];

int dayOfYear(int year, int month, int day) {
    if (!(year > 0 && year < 3000) || !(month > 0 && month <= 12) || !(day > 0 && day <= 31))
        return -1;
    int leap = (year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0);
    for (int i = 1; i < month; i++)
        day += dayTab[leap][i];
    return day;
}

void monthDay(int year, int yearday, int *pmonth, int *pday) {
    int leap = (year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0);
    if (!(year > 0 &&  year < 3000) || !(yearday > 0 && yearday <= 365+leap))
        return;
    int i;
    for (i = 1; yearday > dayTab[leap][i]; i++)
        yearday -= dayTab[leap][i];
    *pmonth = i;
    *pday = yearday;
}

int dayOfYear_2(int year, int month, int day) {
    if (!(year > 0 && year < 3000) || !(month > 0 && month <= 12) || !(day > 0 && day <= 31))
        return -1;
    char *ptr = tabPtr;
    if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))
        ptr += sizeof(dayTab[0]);
    while (month--)
        day += *ptr++;
    return day;
}

void monthDay_2(int year, int yearday, int *pmonth, int *pday) {
    int offset = 1;
    if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))
        offset += sizeof(dayTab[0]);
    if (!(year > 0 &&  year < 3000) || !(yearday > 0 && yearday <= 365 + (offset != 0)))
        return;
    int i;
    for ( i = 1; yearday > *(tabPtr + offset); i++, offset += sizeof(char))
        yearday -= *(tabPtr + offset);
    *pmonth = i;
    *pday = yearday;
}

// Task 10.

double expr(int arg_c, const char *arg_v[]) {
    const char symTable[] = "0123456789+-*/";
    const int maxLength = 256;
    double operand;
    while (--arg_c && *++arg_v != 0) {
        int i, j;
        bool isCorrectArg = true;
        for (i = 0; (*arg_v)[i] != '\0' && isCorrectArg; i++) {
            for (j = 0; (*arg_v)[i] != symTable[j] && symTable[j] != '\0'; j++);
            if (symTable[j] == '\0')
                isCorrectArg = false;
        }
        if (isCorrectArg && i > 0) {
            if ((*arg_v)[i-1] >= '0' && (*arg_v)[i-1] <= '9')
                push(aToF(*arg_v));
            else
                switch ((*arg_v)[0]) {
                case '+':
                    push(pop() + pop());
                    break;
                case '-':
                    operand = pop();
                    push(pop() - operand);
                    break;
                case '*':
                    push(pop() * pop());
                    break;
                case '/':
                    operand = pop();
                    if (operand != 0) push(pop() / operand); else {
                        printf("Division by zero.\n");
                        push(0.0);
                    }
                    break;
                default:
                    printf("Something goes wrong with operator...\n");
                }
        }
    }
    return pop();
}

void enterDeleteTabs(int arg_c, const char *arg_v[]) {
    // "+N - insert tab, -N - delete tab, if exist.
    const char *defaultTabs[] = { "cmd", "-0", "+8", "+12" };
    if (arg_c < 2) {
        arg_v = defaultTabs;
        arg_c = 4;
    }
    FILE *text = fopen("labs_0x00/files/chapter-5.txt", "r");
    const int maxLength = 256;
    char string[maxLength];
    int stringSize;
    while ((stringSize = getLine(string, text, maxLength)) > 0) {
        for (int i = 1; i < arg_c; i++) {
            int column = atoiPtr(arg_v[i]);
            // printf("c = %d\n", column);
            if (*(arg_v[i]) == '+') {
                for (int j = stringSize; j > column; j--)
                    string[j] = string[j-1];
                string[column] = '\t';
                string[stringSize + 1] = '\0';
            } else {
                column *= -1;
                if (string[column] == '\t')
                    for (int j = column; j < stringSize; j++)
                        string[j] = string[j+1];
            }
        }
        printf("%s", string);
    }
    fclose(text);
}

void tail(int arg_c, const char *arg_v[]) {
    const char *defaultN[] = { "cmd", "1" };
    if (arg_c < 2) {
        arg_v = defaultN;
        arg_c = 2;
    }
    int lines = 0;
    const int maxLength = 256;
    char string[maxLength];
    FILE *text = fopen("labs_0x00/files/chapter-5.txt", "r");
    while (getLine(string, text, maxLength))
        lines++;
    fseek(text, 0, 0);
    int linesToDisplay = atoiPtr(*++arg_v);
    while (getLine(string, text, maxLength))
        if (lines-- <= linesToDisplay)
            printf("%s", string);
    fclose(text);
}

// Task 5-14-17.

void swapPtr(void *v[], int i, int j) {
    void *temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

int numCmp_5(char *s1, char *s2) {
    double v1 = aToF(s1), v2 = aToF(s2);
    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}

void qsortPtr(void *v[], int left, int right, int order, int caseSens, int dir, int (*comp)(void *, void*, int, int)) {
    int i, last;
    if (left >= right)
        return;
    last = left;
    swapPtr(v, left, (left + right)/2);
    for (i = left + 1; i <= right; i++)
        if (((*comp)(v[i], v[left], caseSens, dir) < 0 && order == 1 ) || ((*comp)(v[i], v[left], caseSens, dir) > 0 && order == -1))
            swapPtr(v, ++last, i);
    swapPtr(v, left, last);
    qsortPtr(v, left, last-1, order, caseSens, dir, comp);
    qsortPtr(v, last+1, right, order, caseSens, dir, comp);
}

// Tasks 5-18-20.

void dirDcl(const char source[], char name[], char destination[], int *sp);

void dcl(const char source[], char name[], char destination[], int *sp) {
    int ns;
    for (ns = 0; source[*sp] == '*' && source[*sp] != '\0'; (*sp)++)
        ns++;
    dirDcl(source, name, destination, sp);
    while (ns--)
        strCat(destination, " pointer to");
}

void dirDcl(const char source[], char name[], char destination[], int *sp) {
    int type;
    const int maxLength = 256;
    if (source[*sp] == '(') {
        (*sp)++;
        dcl(source, name, destination, sp);
        if (source[*sp] != ')') {
            printf("Error: missing ')'.\n");
            return;
        }
        (*sp)++;
    } else {
        // Name - only letters, case insensitive.
        int j;
        for ( j = 0; toUpper(source[*sp]) >= 'A' && toUpper(source[*sp]) <= 'Z'; (*sp)++)
            name[j++] = source[*sp];
        name[j] = '\0';
        if (j == 0) {
            printf("Error: expecting name or (dcl).\n");
            return;
        }
    }
    if (source[*sp] == '(') {
        strCat(destination, " function");
        while (source[*sp] != ')')
            strnCat(destination, source+(*sp)++, 1);
        strCat(destination, ") returning");
        (*sp)++;
    }
    if (source[*sp] == '[') {
        strCat(destination, " array");
        while (source[*sp] != ']')
            strnCat(destination, source+(*sp)++, 1);
        strCat(destination, "] of");
        (*sp)++;
    }
}

void declarationToText(const char source[]) {
    const int maxLength = 256;
    char type[maxLength] = "", name[maxLength] = "", output[maxLength] = "";
    int i, j = 0;
    for (i = 0; source[i] != ' ' && source[i] != '\0'; i++)
        type[j++] = source[i];
    type[j] = '\0';
    if (strnCmp(type, "const", 5) == 0) {
        type[j++] = ' ';
        for ( i++ ; source[i] != ' ' && source[i] != '\0'; i++)
            type[j++] = source[i];
    }
    if (source[i] != ' ')
        return;
    while (source[i] == ' ')
        i++;
    dcl(source, name, output, &i);
    printf("Declaration '%s' : %s - %s %s\n", source, name, output, type);
}

void chapter_5() {
    printf("Chapter's 5 tasks.\n");
    // Task 1-2.
    const char string1[] = "-64";
    const char string2[] = "-24.32";
    printf("Function getInt(%s) = %d\n", string1, getInt(string1));
    printf("Function getFloat(%s) = %.2f\n", string2, getFloat(string2));
    // Task 3.
    char string3[] = "String_1", string4[] = "String_2";
    printf("Strings concat %s + %s = ", string3, string4);
    strCat(string3, string4);
    printf("%s\n", string3);
    // Task 4.
    char string5[] = "String_5", string6[] = "ing_5";
    printf("Is %s, substring of %s : %d\n", string6, string5, strEnd(string5, string6));
    // Task 5.
    char string7[] = "destination", string8[] = "source", string9[] = "sourz";
    printf("Copy 4 symbols of string '%s' to '%s' = ", string8, string7);
    strnCpy(string7, string8, 4);
    printf("%s\n", string7);
    printf("Concat 3 symbols of string '%s' with '%s' = ", string7, string8);
    strnCat(string7, string8, 3);
    printf("%s\n", string7);
    printf("Compare first 3 symbols of '%s' with '%s' = %d\n", string8, string7, strnCmp(string7, string8, 3));
    printf("Compare first 5 symbols of '%s' with '%s' = %d\n", string8, string7, strnCmp(string7, string8, 5));
    printf("Compare first 5 symbols of '%s' with '%s' = %d\n", string9, string7, strnCmp(string7, string9, 5));
    // Task 6.
    FILE *text = fopen("labs_0x00/files/chapter-5.txt", "r");
    const int maxLength = 256;
    char string10[maxLength];
    printf("File chapter-5.txt, using getLinePtr function : \n");
    while (getLinePtr(string10, text, maxLength))
        printf("%s", string10);
    fclose(text);
    itoaPtr(128, string10);
    printf("Integer %d to string, using function itoaPtr = %s\n", 128, string10);
    printf("String '%s' to integer, using function atoiPtr = %d\n", string10, atoiPtr(string10));
    printf("Reverse string '%s' using function reversePtr = ", string10);
    char *first = string10;
    char *last = first;
    while (*last)
        last++;
    reversePtr(first, last-1);
    printf("%s\n", string10);
    char string11[] = "rz";
    printf("Index of substring '%s' in '%s' = %d\n", string11, string9, strIndexPtr(string9, string11));
    // Task 7.
    const char *strings_7[] = { "A_string", "C_string", "B_string" };
    readLines(strings_7, 3);
    printf("Lines in array before unsort : \n");
    writeLines(3);
    qsort_5(strings, 0, 2);
    printf("And after sort : \n");
    writeLines(3);
    // Task 8.
    printf("Day of the '01 aug 2015' = %d\n", dayOfYear(2015, 8, 1));
    int mon = 0, day = 0;
    monthDay(2015, 213, &mon, &day);
    printf("Day and month of '01 aug 2015' = %d %d\n", day, mon);
    // Task 9.
    printf("Day of the '01 aug 2015' using alternative function = %d\n", dayOfYear_2(2015, 8, 1));
    monthDay_2(2015, 213, &mon, &day);
    printf("Day and month of '01 aug 2015' using alternative function = %d %d\n", day, mon);
    // Task 10.
    const char *args[] = { "expr", "21", "3", "4", "+", "/" };
    // printf("args = %d\n", sizeof(args)/sizeof(char*));
    printf("Expression '2*(3+4)' = %.2f\n", expr(sizeof(args)/sizeof(char*), args));
    // Task 11-12. Hard to find in chapter 1. Enter tabs in position and delete them.
    printf("File chapter-5.txt(original see above) with tabs deleted at 0 column and add tabs at 8, 12 columns: \n");
    enterDeleteTabs(1, args);
    // Task 13.
    printf("\nPrint 3 last lines from chapter-5.txt file : \n");
    const char *args_2[] = { "cmd", "3" };
    tail(2, args_2);
    // Task 14-17. Task 17 works, but a not with fields, simplify using function parameters.
    int argc_3 = 4;
    const char *arg_v[] = { "qsort", "-r", "-f", "-d", "1", "3", "2", "string_a", "string_C", "string_b" };
    int order = 1, caseSensitive = 1, dirOrder = 0;
    int (*funcPtr)(void*, void*, int, int) = (int (*)(void*, void*, int, int))(strCmp_5);
    for (int i = 0; i < sizeof(arg_v)/sizeof(char*)-1; i++) {
        if (strCmp_5(arg_v[i], "-r", caseSensitive, 0, 2) == 0)
            order = -1;
        if (strCmp_5(arg_v[i], "-n", caseSensitive, 0, 2) == 0)
            funcPtr = (int (*)(void*, void*, int, int))(numCmp_5);
        if (strCmp_5(arg_v[i], "-f", caseSensitive, 0, 2) == 0)
            caseSensitive = 0;
        if (strCmp_5(arg_v[i], "-d", caseSensitive, 0, 2))
            dirOrder = 0;
    }
    qsortPtr((void**)arg_v, 7, 9, order, caseSensitive, dirOrder, funcPtr);
    printf("Result of qsortPtr, strings with keys '-r' '-d': ");
    for (int i = 7; i < 10; i++)
        printf("%s ", *(arg_v+i));
    printf("\n");
    printf("Result of qsortPtr, numbers with key '-n' : ");
    funcPtr = (int (*)(void*, void*, int, int))(numCmp_5);
    qsortPtr((void**)arg_v, 4, 6, 1, 0, 0, funcPtr);
    for (int i = 4; i < 7; i++)
        printf("%s ", *(arg_v+i));
    printf("\n");
    // Tasks 18-20. Except undeclaration function, becuase of input method.
    const char *decls[] = { "const char **argv;", "const int (*daytab)[13];", "int *daytab[13];", "void *comp(int, int);",
                            "void (*comp)(char);", "char (*(*x())[3])();", "char (*(*x[3])())[5];" };
    for (int i = 0; i < sizeof(decls)/sizeof(char*); i++)
        declarationToText(decls[i]);
}

// Chapter 6.

struct Key {
    const char *word;
    int count;
};

struct Def {
    const char *word;
    int length;
};

static const int maxWordLen = 32;
static const int maxDefs = 16;

Key keys[] = { "for", 0, "if", 0, "while", 0 };
Def defTab[] = { "#define", 7, "#ifdef", 6, "#ifndef", 7, "#endif", 6 };
char defs[maxDefs][maxWordLen];
static int defsCount = 0;

int binSearch(char *word, Key tab[], int n) {
    int cond, low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high)/2;
        if ((cond = strnCmp(word, tab[mid].word, maxWordLen)) < 0)
            high = mid - 1;
        else if (cond > 0)
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}

int getWord(const char *text, char *word, int index) {
    if (text[index] == '\0')
        return -1;
    bool isWord = true;
    int i, j, next;
    for (j = 0, i = index;  isWord && text[i] != '\0'; ) {
        if (text[i+1] != '\0') {
            if (text[i] == '/' && text[i+1] == '*') {
                while (!(text[i] == '*' && text[i+1] == '/') && text[i+1] != '\0')
                    i++;
            }
            if (text[i] == '/' && text[i+1] == '/') {
                while (text[i] != '\n' && text[i] != '\0')
                    i++;
            }
        }
        if (text[i] == '"') {
            while (text[++i] != '"');
            i++;
        }
        if (strnCmp(text+i, defTab[0].word, defTab[0].length) == 0) {
            i += defTab[0].length + 1;
            next = getWord(text, defs[defsCount++], i);
            if (next == i)
                printf("Error in #define.\n");
            i = next;
        }
        int defType = 0;
        if (strnCmp(text+i, defTab[1].word, defTab[1].length) == 0)
            defType = 1;
        if (strnCmp(text+i, defTab[2].word, defTab[2].length) == 0)
            defType = 2;
        if (defType) {
            char parameter[maxWordLen] = "";
            i += defTab[defType].length + 1;
            int next = getWord(text, parameter, i);
            if (next == i)
                printf("Error in #ifdef or #ifndef expression.\n");
            i = next;
            bool isExist = false;
            for (int k = 0; k < defsCount && !isExist; k++)
                if (strnCmp(defs[k], parameter, maxWordLen) == 0)
                    isExist = true;
            if (defType == 1 && !isExist || defType == 2 && isExist)
                while (text[i] != '\0' && strnCmp(text + i, defTab[3].word, defTab[3].length) != 0)
                    i++;
        }
        if (strnCmp(text+i, defTab[3].word, defTab[3].length) == 0)
            i += defTab[3].length;
        if (toUpper(text[i]) >= 'A' && toUpper(text[i]) <= 'Z' ||
                i > index && text[i] >= '0' && text[i] <= '9' ||
                text[i] == '_') {
            word[j++] = text[i++];
        } else
            isWord = false;
    }
    word[j] = '\0';
    return i;
}

// Task 6.2-6-4.

int strLen(char s[]) {
    int i = 0;
    while (s[i] != '\0')
        i++;
    return i;
}

struct tNode {
    char *word;
    int count;
    int *nLines;
    tNode *left;
    tNode *right;
};

tNode *addNode(tNode *ptr, char *word, int maxLen, int nLine) {
    int cmp;
    if (ptr == NULL) {
        ptr = (tNode*)malloc(sizeof(tNode));
        ptr->word = (char*)malloc(strLen(word));
        ptr->nLines = (int*)malloc(sizeof(int));
        *ptr->nLines = nLine;
        strnCpy(ptr->word, word, maxWordLen);
        ptr->count = 1;
        ptr->left = ptr->right = 0;

    } else if ((cmp = strnCmp(word, ptr->word, maxLen)) == 0) {
        int *lines = (int*)malloc(sizeof(int)*(ptr->count+1));
        for (int i = 0; i < ptr->count; i++)
            lines[i] = ptr->nLines[i];
        lines[ptr->count] = nLine;
        free(ptr->nLines);
        ptr->nLines = lines;
        ptr->count++;
    }
    else if (cmp < 0)
        ptr->left = addNode(ptr->left, word, maxLen, nLine);
    else if (cmp > 0)
        ptr->right = addNode(ptr->right, word, maxLen, nLine);
    return ptr;
}

void printTree(tNode *ptr, bool printLines) {
    if (ptr != NULL) {
        printTree(ptr->left, printLines);
        printf("%4d %s", ptr->count, ptr->word);
        if (printLines) {
            printf(" [ ");
            for (int i = 0; i < ptr->count; i++)
                printf("%d ", ptr->nLines[i]);
            printf ("]\n");
        } else
            printf("\n");
        printTree(ptr->right, printLines);
    }
}

void swapTNode(tNode *v[], int i, int j) {
    tNode *temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void sortNodes(tNode *v[], int left, int right) {
    int i, last;
    if (left >= right)
        return;
    swapTNode(v, left, (left+right)/2);
    last = left;
    for (i = left+1; i <= right; i++)
        if (v[left]->count < v[i]->count)
            swapTNode(v, ++last, i);
    swapTNode(v, left, last);
    sortNodes(v, left, last-1);
    sortNodes(v, last+1, right);
}

void printTreeDescending(tNode *ptr) {
    static int maxCounter = 0;
    int nextCounter = 0;
    if (ptr == NULL)
        return;
    tNode *nodes[1024];
    int sp = 0, bp = 0;
    nodes[sp++] = ptr;
    while (bp < sp) {
        if (ptr->count > maxCounter)
            maxCounter = ptr->count;
        if (ptr->left != NULL)
            nodes[sp++] = ptr->left;
        if (ptr->right != NULL)
            nodes[sp++] = ptr->right;
        ptr = nodes[++bp];
    }
    if (maxCounter == 0) {
        printf("Error, no counters founded.\n");
        return;
    }
    sortNodes(nodes, 0, sp-1);
    printf("Word's counters in descending order: \n");
    for (int i = 0; i < sp; i++)
        printf("%4d %s\n", nodes[i]->count, nodes[i]->word);
}

bool isType(char *word) {
    const char *types[] = { "char", "int", "float", "double" };
    for (int i = 0; i < sizeof(types)/sizeof(char*); i++)
        if (strnCmp(word, types[i], maxWordLen) == 0)
            return true;
    return false;
}

// Tasks 6.5-6.6

struct nList {
    nList *next;
    char *name;
    char *defn;
};

static const unsigned int hashSize = 256;

nList *hashTab[hashSize];

unsigned char hash(char *s) {
    unsigned int hashVal;
    for (hashVal = 0; *s != '\0'; s++)
        hashVal = *s + 31 * hashVal;
    return hashVal % hashSize;
}

nList *lookup(char *s) {
    nList *np;
    for (np = hashTab[hash(s)]; np != NULL; np = np->next)
        if (strnCmp(s, np->name, maxWordLen) == 0)
            return np;
    return NULL;
}

nList *install(char *name, char *definition) {
    nList *np;
    unsigned char hashVal;
    if ((np = lookup(name)) == NULL) {
        np = (nList*)malloc(sizeof(*np));
        if (np == NULL)
            return NULL;
        np->name = (char*)malloc(sizeof(char)*strLen(name));
        strnCpy(np->name, name, strLen(name));
        hashVal = hash(name);
        np->next = hashTab[hashVal];
        hashTab[hashVal] = np;
    } else {
        free((void*)np->defn);
    }
    np->defn = (char*)malloc(sizeof(char)*strLen(definition));
    if (np->defn == NULL)
        return NULL;
    strnCpy(np->defn, definition, strLen(definition));
    return np;
}

nList *undef(char *s) {
    nList *np = lookup(s);
    if (np == NULL)
        return NULL;
    free((void*)np->defn);
    hashTab[hash(np->name)] = NULL;
    free((void*)np->name);
    np->next = NULL;
    nList *r = np;
    free((void*)np);
    return r;
}

// Task 6-6.

struct Define {
    Define *next;
    char *name;
    char *parameter;
};

Define *addDefine(Define *node, char *name, char *parameter) {
    if (node == NULL) {
        node = (Define*)malloc(sizeof(Define));
        node->name = (char*)malloc(sizeof(char)*strLen(name));
        strnCpy(node->name, name, strLen(name));
        node->parameter = (char*)malloc(sizeof(char)*strLen(parameter));
        strnCpy(node->parameter, parameter, strLen(parameter));
        node->next = NULL;
    } else {
        node->next = addDefine(node->next, name, parameter);
    }
    return node;
}

Define *isExistDef(Define *node, char *name) {
    while (node != NULL) {
            if (strnCmp(node->name, name, strLen(name)) == 0) {
                return node;
            }
        node = node->next;
    }
    return NULL;
}

int countDef(Define *node) {
    int counter = 0;
    while (node != NULL)
        counter++;
    return counter;
}

int getNextWord(char *source, char *word, int n) {
    int counter;
    for (counter = 0; n > 0 && source[counter] != ' ' && source[counter] != '\n' && source[counter] != '\0'; counter++, n--)
        word[counter] = source[counter];
    word[counter] = '\0';
    return counter;
}

void chapter_6() {
    printf("Chapter's 6 tasks.\n");
    // Task 1. For #define works only #ifdef and #ifndef. Defines must be upper their using.
    const int maxLength = 1024;
    char string_1[maxLength], string_2[maxLength];
    FILE *file_1 = fopen("labs_0x00/files/chapter-6.txt", "r");
    // (string_1, 1024);
    int lengthLine = 0, stringSize = 0;
    while ((lengthLine = getLine(string_1+stringSize, file_1, maxLength)) != 0)
        stringSize += lengthLine;
    int i = 0, next;
    printf("All words[index] in file 'chapter-6.txt' : \n");
    while ((next = getWord(string_1, string_2, i)) != -1 ) {
        if (string_2[0] != '\0') {
            printf("%s[%d] ", string_2, i);
            int pos;
            if ((pos = binSearch(string_2, keys, sizeof(keys)/sizeof(Key))) >= 0)
                keys[pos].count++;
        }
        if (next == i) next++;
        i = next;
    }
    printf("\nWords and counters: \n");
    for (int i = 0; i < sizeof(keys)/sizeof(Key); i++)
        printf("%s : %d\n", keys[i].word, keys[i].count);
    fclose(file_1);
    // Tasks 2. Only standard types.
    FILE *sourceFile = fopen("labs_0x00/labs_0x00.cpp", "r");
    char source[maxLength * 128];
    int sourceLength = 0;
    while ((source[sourceLength++] = getc(sourceFile)) != EOF);
    source[sourceLength] = '\0';
    tNode* root = NULL;
    tNode* references = NULL;
    int wordLen = 5, nLine = 1, refLen = 12;
    char word[maxWordLen];
    for (int i = 0; i < sourceLength; i++) {
        if (source[i] == '/' && source[i+1] == '/') {
            while (i < sourceLength && source[i] != '\n')
                i++;
        }
        if (source[i] == '/' && source[i+1] == '*')
            while (i < sourceLength && (source[i] != '*' || source[i+1] != '/')) {
                if (source[i] == '\n')
                    nLine++;
                i++;
            }
        if (source[i] == '"' && !(i > 0 && source[i-1] == '\'')) {
            i++;
            while (source[i++] != '"');
        }
        if (toUpper(source[i]) >= 'A' && toUpper(source[i]) <= 'Z') {
            int j;
            for (j = 0; toUpper(source[i]) >= 'A' && toUpper(source[i]) <= 'Z' ||
                 source[i] >= '0' && source[i] <= '9' || source[i] == '_'; j++, i++) {
                word[j] = source[i];
            }
            word[j] = '\0';
            if (j >= refLen) {
                references = addNode(references, word, j, nLine);
            }
            if (isType(word) && source[i] == ' ') {
                i++;                            // Only with one space after variable declaration.
                int j;
                for (j = 0; toUpper(source[i]) >= 'A' && toUpper(source[i]) <= 'Z' || (j == 0 && source[i] == '*') ||
                     (j > 0 && (source[i] >= '0' && source[i] <= '9' || source[i] == '_')); j++, i++) {
                    word[j] = source[i];
                }
                word[j] = '\0';
                if (j > 0 && source[i] != '(') {
                    root = addNode(root, word, wordLen, nLine);
                }
            }
        }
        if (source[i] == '\n')
            nLine++;
    }
    printf("Full binary tree from 'root' compare up to 'length' = %d. Groups of variables and their counters:\n", wordLen);
    printTree(root, false);
    printf("Lines found = %d, and source string length = %d\n", nLine, sourceLength);
    printf("Words references with length more than %d: \n", refLen);
    printTree(references, true);
    printTreeDescending(references);
    // Task 5.
    const char *strings_5[] = { "name_1", "def_1", "name_2", "def_2" };
    install((char*)strings_5[0], (char*)strings_5[1]);
    install((char*)strings_5[2], (char*)strings_5[3]);
    printf("Adding to hash table 'name_1', 'name_2' and definitions 'def_1', 'def_2'.\n");
    printf("Result of lookup function for 'name_1', 'name_2': %s %s\n", lookup((char*)strings_5[0])->defn, lookup((char*)strings_5[2])->defn);
    undef((char*)strings_5[2]);
    printf("Undefine 'name_2' from hash table, lookup again: ");
    nList *r;
    if ((r = lookup((char*)strings_5[0])) != NULL)
        printf("%s ", r->defn);
    if ((r = lookup((char*)strings_5[2])) != NULL)
        printf("%s ", r->defn);
    printf("\n");
    fclose(sourceFile);
    // Task 6.

    sourceFile = fopen("labs_0x00/files/chapter-6.txt", "r");
    sourceLength = 0;
    while ((source[sourceLength++] = getc(sourceFile)) != EOF);
    source[sourceLength] = '\0';
    fclose(sourceFile);

    Define *listDefs = NULL;
    for (int i = 0; i < 512; i++) {
        if (source[i] == '/' && source[i+1] == '/') {
            while (i < sourceLength && source[i] != '\n')
                i++;
        }
        if (source[i] == '/' && source[i+1] == '*')
            while (i < sourceLength && (source[i] != '*' || source[i+1] != '/')) {
                if (source[i] == '\n')
                    nLine++;
                i++;
            }
        if (source[i] == '"' && !(i > 0 && source[i-1] == '\'')) {
            i++;
            while (source[i++] != '"');
        }
        int j;
        char name[maxWordLen], parameter[maxWordLen], word[maxWordLen];
        for (j = 0; j < 3 && strnCmp(&source[i], defTab[j].word, defTab[j].length) != 0; j++);
        if (j < 3) {
            i += defTab[j].length + 1;      // One space after.
            if (getNextWord(&source[i], name, maxWordLen) == 0) {
                printf("Error, no name after #define or #ifdef or #ifndef.\n");
                return;
            }
            i += strLen(name) + 1;  // One more space.
            if (j == 0) {
                if (getNextWord(&source[i], parameter, maxWordLen) == 0) {
                    printf("Error, no parameter after name.\n");
                    return;
                }
                i += strLen(parameter);
            }
        }
        if (j == 1 && !isExistDef(listDefs, name) ||
                j == 2 && isExistDef(listDefs, name)) {
            printf("Skipping #ifdef or #ifndef '%s'.\n", name);
            while (source[i] != '\0' && strnCmp(&source[i], defTab[3].word, defTab[3].length) != 0)
                i++;
        }
        if (j == 0) {
            printf("Adding word and parameter '%s', '%s'.\n", name, parameter);
            listDefs = addDefine(listDefs, name, parameter);
        }
        if (getNextWord(&source[i], word, maxWordLen) > 0) {
            Define *p = isExistDef(listDefs, word);
            if (p != NULL)
                printf("Define '%s' has founded. Parameter '%s'.\n", p->name, p->parameter);
        }
    }
}

// Chapter's 7 functions and data...

char *toLowerCase(char *s) {
    for (int i = 0; s[i] != '\0'; i++)
        if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] = s[i] + 32;
    return s;
}

char *toUpperCase(char *s) {
    for (int i = 0; s[i] != '\0'; i++)
        if (s[i] >= 'a' && s[i] <= 'z')
            s[i] = s[i] - 32;
    return s;
}

void minPrintf(char *fmt, ...) {
    va_list ap;
    char *p, *sval;
    int ival;
    double dval;
    char ch;
    va_start(ap, fmt);
    for (p = fmt; *p; p++) {
        if (*p != '%') {
            putchar(*p);
            continue;
        }
        switch (*++p) {
        case 'd':
            ival = va_arg(ap, int);
            printf("%d", ival);
            break;
        case 'f':
            dval = va_arg(ap, double);
            printf("%f", dval);
            break;
        case 's':
            for (sval = va_arg(ap, char*); *sval; sval++)
                putchar(*sval);
            break;
        case 'c':
            ch = va_arg(ap, int);
            printf("%c", ch);
            break;
        default:
            putchar(*sval);
            break;
        }
    }
    va_end(ap);
}

void minScanf(char *fmt, ...) {
    va_list ap;
    char *p, *sval;
    int *ival;
    double *dval;
    char *ch;
    va_start(ap, fmt);
    for (p = fmt; *p; p++) {
        if (*p != '%') {
            putchar(*p);
            continue;
        }
        switch (*++p) {
        case 'd':
            ival = va_arg(ap, int*);
            scanf("%d", ival);
            break;
        case 'f':
            dval = va_arg(ap, double*);
            scanf("%lf", dval);
            break;
        case 's':
            sval = va_arg(ap, char*);
            scanf("%s", sval);
            break;
        case 'c':
            ch = va_arg(ap, char*);
            // Strange...
            scanf(" %c", ch);
            break;
        default:
            break;
        }
    }
}

int isUpper(char c) {
    return ((c >= 'A' && c <= 'Z') ? 1 : 0);
}

void chapter_7() {
    printf("Chapter's 7 tasks.\n");
    // Task 1.
    const char *argv[] = { "conversion", "CONVERSION" };
    char strings_1[][maxWordLen] = { "STRING_1", "string_2" };
    for (int i = 0; i < sizeof(argv)/sizeof(char*); i++) {
        if (argv[i][0] >= 'a' && argv[i][0] <= 'z') {
            printf("String '%s' to lower case = ", strings_1[i]);
            toLowerCase(strings_1[i]);
            printf("%s\n", strings_1[i]);
        }
        if (argv[i][0] >= 'A' && argv[i][0] <= 'Z') {
            printf("String '%s' to upper case = ", strings_1[i]);
            toUpperCase(strings_1[i]);
            printf("%s\n", strings_1[i]);
        }
    }
    // Task 2.
    const char string_1[] = "Task's 2 string with 3 tabulatations. \t \t \t.\n"
                            "Next line of string.\n";
    const int maxLineLength = 12;
    printf("Print source string '%s' with length = %d:", string_1, maxLineLength);
    for (int i = 0, j = 0; string_1[i] != '\0'; i++) {
        if (j >= maxLineLength || (string_1[i] < ' ' && j >= maxLineLength-4)) {
            printf("\n");
            j = 0;
        }
        if (string_1[i] < ' ') {
            printf("0x%x ", string_1[i]);
            j += 4;
        }
        else {
            printf("%c", string_1[i]);
            j++;
        }
    }
    printf("\n");
    // Task 3.
    char string_2[] = "String for minPrintf(): integer = %d, float = %f, string = %s, char = %c.\n";
    printf("Calling minPrintf with parameter '%s':", string_2);
    minPrintf(string_2, 1, 3.0, "Hello World!", 'A');
    // Task 4.
    int int_1;
    char ch_1;
    double doub_1;
    char string_3[] = "Calling function minScanf():\nintger = %d, float = %f, char = %c, string[16] = %s.\n";
    char string_4[maxWordLen];
    minScanf(string_3, &int_1, &doub_1, &ch_1, string_4);
    printf("Result of minScanf(): integer = %d, float = %f, string = %s, char = %c.\n", int_1, doub_1, string_4, ch_1);
    // Task 5. Something with stream...
    char string_5[MAXLENGTH] = "", operandStr[MAXLENGTH] = "";
    char symTable[] = "0123456789+-/*";
    int operandSize = 0;
    double operand;
    printf("Enter operands to calculate, as it was task in chapter 4. Type 'ok' to calculate.\n");
    while (strnCmp(operandStr, "ok", MAXLENGTH) != 0) {
        scanf("%s", operandStr);
        if (strnCmp(operandStr, "ok", MAXLENGTH) != 0) {
            strnCat(string_5, operandStr, MAXLENGTH);
            strnCat(string_5, " ", MAXLENGTH);
        }
        // printf("operand = %s\n", operandStr);
    }
    printf("s = %s\n", string_5);
    for (int i = 0; string_5[i] != '\0'; i++) {
        int k;
        for (k = 0; symTable[k] != '\0' && string_5[i] != symTable[k]; k++);
        if (symTable[k] != '\0') operandStr[operandSize++] = string_5[i];
        if ((string_5[i+1] == ' ' || string_5[i+1] == '\0') && operandSize > 0) {
            if (operandStr[operandSize-1] >= '0' && operandStr[operandSize-1] <= '9') {
                operandStr[operandSize] = '\0';
                push(aToF(operandStr));
            } else {
                switch (operandStr[0]) {
                case '+':
                    push(pop() + pop());
                    break;
                case '-':
                    operand = pop();
                    push(pop() - operand);
                    break;
                case '*':
                    push(pop() * pop());
                    break;
                case '/':
                    operand = pop();
                    if (operand != 0) push(pop() / operand); else {
                        printf("Division by zero.\n");
                        push(0.0);
                    }
                    break;
                }
            }
            operandSize = 0;
        }
    }
    printf("Result of expression %s = %.2f\n", string_5, pop());
    // Task 6.
    FILE* file_1 = fopen("labs_0x00/files/chapter-7-1.txt", "r");
    FILE* file_2 = fopen("labs_0x00/files/chapter-7-2.txt", "r");
    char line_1[MAXLENGTH], line_2[MAXLENGTH];
    while (fgets(line_1, MAXLENGTH, file_1) != NULL && fgets(line_2, MAXLENGTH, file_2) != NULL)
        if (strnCmp(line_1, line_2, MAXLENGTH) != 0) {
            printf("Different lines in files:\n%s%s", line_1, line_2);
            break;
        }
    fclose(file_1);
    fclose(file_2);
    // Task 7-8.
    const char *fileNames[] = { "labs_0x00/files/chapter-7-1.txt", "labs_0x00/files/chapter-7-2.txt" };
    int filesCount = sizeof(fileNames)/sizeof(char*);
    FILE* txtFile;
    char txtLine[MAXLENGTH], toFind[MAXLENGTH] = "ine";
    printf("All lines in files, contain %s substring.\n", toFind);
    for (int i = 0; i < filesCount; i++) {
        printf("All lines in file '%s':\n", fileNames[i]);
        txtFile = fopen(fileNames[i], "r");
            while (fgets(txtLine, MAXLENGTH, txtFile) != NULL) {
                if (strIndex(txtLine, toFind) != -1)
                    printf("Substring founded: ");
                printf("%s",txtLine);
            }
        fclose(txtFile);
    }
    printf("Is 'c' and 'A' upper = %d %d\n", isUpper('c'), isUpper('A'));
}

// Chapter 8.

#define OPEN_MAX 8

struct FileFlags {
    unsigned int _READ : 1;
    unsigned int _WRITE : 1;
    unsigned int _UNBUF : 1;
    unsigned int _EOF : 1;
    unsigned int _ERR : 1;
};

typedef struct _iobuf {
    int cnt;
    char *ptr;
    char *base;
    FileFlags flag;
    int fd;
} FILE_8;

#define PERMS 0777

#define feof(p)     (((p)->flag._EOF)  != 0)
#define ferror(p)   (((p)->flag._ERR) != 0)
#define fileno(p)   (((p)->fd))

static FileFlags clearFlag = { 0, 0, 0, 0, 0 };
static int openedStreams = 3;

FILE_8 _iob[OPEN_MAX] = {
    { 0, (char*) 0, (char*) 0, { 1, 0, 0, 0, 0 }, 0 },
    { 0, (char*) 0, (char*) 0, { 0, 1, 0, 0, 0 }, 1 },
    { 0, (char*) 0, (char*) 0, { 0, 1, 1, 0, 0 }, 2 }
};

int fillBuf(FILE_8 *fp);
int flushBuf(FILE_8 *fp);

unsigned char getChar(FILE_8 *file) {
    unsigned char w = ' ';
    if (--(file)->cnt < 0) {
        // printf("W.\n");
        return fillBuf(file);
    }
    return (unsigned char)*(file)->ptr++;
}

int putChar(FILE_8 *file, unsigned char c) {
    if (file->base == NULL)
        flushBuf(file);
    int bufSize = (file->flag._UNBUF) ? 1 : BUFSIZ;
    if (++(file)->cnt <= bufSize)
        *(file)->ptr++ = c;
    else {
        printf("Actual write = %d\n", flushBuf(file));
    }
}

FILE_8* fOpen(const char *name, char *mode) {
    int fd;
    if (*mode != 'r' && *mode != 'w' && *mode != 'a')
        return NULL;
    if (openedStreams == OPEN_MAX) {
        printf("Reach limit of opened files.\n");
        return NULL;
    }
    FILE_8* fp = &_iob[openedStreams++];
/*
    for (fp = _iob; fp < _iob + OPEN_MAX; fp++)
        if (fp->flag._READ == 0 && fp->flag._WRITE == 0)
            break;
            */
    // printf("Create with _iob = %ld\n", (long)fp);
    if (fp > _iob + OPEN_MAX)
        return NULL;
    if (*mode == 'w')
        fd = creat(name, PERMS);
    else if (*mode == 'a') {
        if ( (fd = open(name, O_WRONLY, 0)) == -1)
            fd = creat(name, PERMS);
        lseek(fd, 0L, 2);
    } else
        fd = open(name, O_RDONLY);
    if (fd == -1)
        return NULL;
    fp->fd = fd;
    fp->cnt = 0;
    fp->base = NULL;
    fp->flag = clearFlag;
    if (*mode == 'r')
        fp->flag._READ = 1;
    else
        fp->flag._WRITE = 1;
    return fp;
}

int fSeek(FILE_8 *file, long offset, int origin) {
    if (file == NULL) {
        printf("No file.\n");
        return EOF;
    }
    int seekMode;
    switch (origin) {
    case 0:
        seekMode = SEEK_SET;
        break;
    case 1:
        seekMode = SEEK_CUR;
        break;
    case 2:
        seekMode = SEEK_END;
        break;
    default:
        seekMode = SEEK_SET;
    }
    if (lseek(file->fd, offset, seekMode) == -1) {
        printf("Error seek in file.\n");
        return EOF;
    }
    file->flag._EOF = 0;
    return 0;
}

int fClose(FILE_8 *file) {
    if (file->base == NULL)
        return EOF;
    if (file->flag._WRITE == 1 && file->cnt > 0) {
        printf ("\nActual bytes written = %d\n", flushBuf(file));
    }
    free( (void*)file->base );
    close(file->fd);
    file->fd = 0;
    file->flag = clearFlag;
    file->ptr = NULL;
    file->base = NULL;
    openedStreams--;
    return 0;
}

int fillBuf(FILE_8 *fp) {
    int bufsize;
    if (fp->flag._READ == 0 || fp->flag._EOF == 1 || fp->flag._ERR == 1)
        return EOF;
    bufsize = (fp->flag._UNBUF == 1) ? 1 : BUFSIZ;
    if (fp->base == NULL)
        if ( (fp->base = (char*)malloc(bufsize)) == NULL)
            return EOF;
    fp->ptr = fp->base;
    fp->cnt = read(fp->fd, fp->ptr, bufsize);
    if (--fp->cnt < 0) {
        if (fp->cnt == -1)
            fp->flag._EOF = 1;
        else
            fp->flag._ERR = 1;
        fp->cnt = 0;
        return EOF;
    }
    return (unsigned char) *fp->ptr++;
}

int flushBuf(FILE_8 *fp) {
    int actualWrite;
    if (fp->flag._WRITE == 0 || fp->flag._EOF == 1 || fp->flag._ERR == 1)
        return EOF;
    int bufsize = (fp->flag._UNBUF == 1) ? 1 : BUFSIZ;
    if (fp->base == NULL) {
        if ( (fp->base = (char*)malloc(bufsize)) == NULL)
            return EOF;
        fp->ptr = fp->base;
    }
    actualWrite = fp->cnt;
    fp->cnt -= write(fp->fd, fp->base, fp->cnt);
    fp->ptr = fp->base + fp->cnt;
    if (fp->cnt > 0) {
        printf("Error writing to stream.\n");
        fp->flag._ERR = 1;
        return EOF;
    }
    return (actualWrite-fp->cnt);
}

#define MAX_PATH 256

void filesInfo(char *directory);

void dirWalk(char *dir, void (*fcn)(char*)) {
    char name[MAX_PATH];
    dirent *dp;
    DIR *dfd;
    if ((dfd = opendir(dir)) == NULL) {
        printf("Error, can't open %s\n", dir);
        return;
    }
    while ((dp = readdir(dfd)) != NULL) {
        if (strnCmp(dp->d_name, ".", MAX_PATH) == 0 || strnCmp(dp->d_name, "..", MAX_PATH) == 0)
            continue;
        if (strLen(dir) + strLen(dp->d_name) > sizeof(name))
            printf("Skipping dir %s, name too long.\n", dir);
        else {
            sprintf(name, "%s/%s", dir, dp->d_name);
            (*fcn)(name);
        }
    }
    closedir(dfd);
}

void filesInfo(char *directory) {
    struct stat stBuf;
    if (stat(directory, &stBuf) == -1) {
        printf("Error, cat't access %s\n", directory);
        return;
    }
    if ((stBuf.st_mode & S_IFMT) == S_IFDIR)
        dirWalk(directory, filesInfo);
    printf("%8ld %4ld %s\n", stBuf.st_size, stBuf.st_blocks, directory);
}

void chapter_8() {
    printf("Chapter's 8 tasks.\n");
    // Task 1.
    char buf[BUFSIZ];
    const char *fileNames[] = { "labs_0x00/files/chapter-8-1.txt", "labs_0x00/files/chapter-8-2.txt" };
    int filesCounter = sizeof(fileNames)/sizeof(char*);
    int actualBytes;
    int desc_1 = open(fileNames[0], O_RDONLY, 0777);
    printf("Cat file '%s', descriptor = %d:\n\n", fileNames[0], desc_1);
    while ((actualBytes = read(desc_1, buf,1)) > 0)
        write(1, buf, 1);
    close(desc_1);
    // Task 2-4. Task 4, may be not correct...
    char modeR = 'r', modeW = 'w';
    FILE_8 *desc_2 = fOpen("labs_0x00/files/chapter-8-1.txt", &modeR);
    FILE_8 *desc_3 = fOpen("labs_0x00/files/chapter-8-2.txt", &modeW);
    printf("\nRead file 'chapter-8-1.txt and write it to 'chapter-8-2.txt':\n");
    unsigned char c_2;
    while (!feof(desc_2)) {
        c_2 = getChar(desc_2);
        printf("%c", c_2);
        putChar(desc_3, c_2);
    }
    fClose(desc_3);
    printf("Reading file 'chapter-8-1.txt from offset 10:\n");
    fSeek(desc_2, 10, 0);
    while (!feof(desc_2)) {
        c_2 = getChar(desc_2);
        printf("%c", c_2);
    }
    printf("\n");
    fClose(desc_2);
    // Task 5. Need more...
    printf("Files sizes and blocks counters in directory ./labs_0x00:\n");
    filesInfo((char*)"labs_0x00");
}

void labs_0x00() {
    chapter_8();
}
