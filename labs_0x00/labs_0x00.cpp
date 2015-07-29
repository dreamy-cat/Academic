#include "labs_0x00.h"
#include <stdio.h>
#include <stdlib.h>

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
   // Task 23.
   fopen("labs_0x00/labs_0x00.cpp", "r");
   printf("Main source file labs_0x00.cpp, without comments. First 30 lines.\n");
   int inComment = -1, inString = 0;
   for (int k = 0; k < 30; k++) {
       sizeOfLine = getLine(line, text, MAXLENGTH);
       for (int i = 0; i < sizeOfLine-1; i++) {
           if (line[i] == '"') inString = inString ^ 1;
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
       }
       printf("%s", line);
   }
   fclose(text);
}

void labs_0x00() {
    chapter_1();
}
