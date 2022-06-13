#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    printf("Chapter 13. File Input/Output.\n");
    // Для перенаправления вывода мы можем исползовать символ >.
    // Хранение файлов относится к уровню ОС, и на уровне библиотеки нас это не интересует.
    // Немного истории про первые ДОС, тогда можно было написать самостоятельно, ссылки про ФАТ32.
    // Важно понимать, что индексация и доступ огранизован по байтно, т.е. минимально доступная для чтения единица - байт.
    // Про текстовый формат пару слов и конвертацию и настройки в среде.
    printf("New line can be Unix \\n, DOS/WIN \\r\\n or MAC \\r.\n");
    // Формат использования функций, библиотека или интерфейс ОС, для портативности.
    // Стандартный ввод и вывод.

#define STRING_MAX 256
    char s[STRING_MAX];
    int i = 0, c;
    /*
    printf("Input some text, using 'getchar': ");
    while ((c = getchar()) != '\n' && i < STRING_MAX)
        s[i++] = c;
    s[i] = '\0';
    printf("Text and keyboard, using 'putchar': ");
    for (i = 0; s[i] != '\0'; ++i)
        putchar(s[i]);
    printf("\nInput text, using scanf: ");
    scanf("%s", s);
    printf("Text using 'puts': ");
    puts(s);
    // Кратко про параметры командной строки ретурн и выход.
*/
    // Открываем файл и читаем цифры в массивы. Режимы икс по стандарту С11.
    FILE* src = fopen("source.txt", "rb");  // r
    FILE* dst = fopen("destination.txt", "wb");
    if (src == NULL)
        printf("File 'source.txt' not found.\n");
    else
        printf("File exist and opened in read only mode.\n");
    if (dst == NULL)
        printf("Can't open/create file 'destination.txt'.\n");
    else
        printf("File 'destination.txt' create or opened in write only mode.\n");

    // Читаем файл до признака конца файла EOF. Первый символ за последним байтом.
    /*
     * 5 8 1
       7 3 0
     * */

    printf("Source file data, searching minimum and maximum.\n");

    int is_number = 0, counter = 0, offset, num_len = 0, max = 0, min = 100;
    while ((c = getc(src)) != EOF) {
        offset = ftell(src);
        printf("Char readed from file '%c' and code %d, offset %d and counter %d.\n", c, c, offset, counter);
        if (!is_number && (c >= '0' && c <= '9' || c == '-' || c == '+')) { // read number to string.
            is_number = 1;
            num_len = 0;
            printf("Number founded at %d position.\n", counter);
        }
        if (is_number && !(c >= '0' && c <= '9' || c == '-' || c == '+')) {
            is_number = 0;
            printf("Number ended at %d position.\n", counter);
            if (num_len) {
                s[num_len] = '\0';
                int num = atoi(s);
                printf("Number in buffer: '%s', length %d and intger %d.\n", s, num_len, num);
                if (num < min)
                    min = num;
                if (num > max)
                    max = num;
                printf("Min %d and max %d.\n", min, max);
                num_len = 0;
            }
        }
        if (is_number)
            s[num_len++] = c;
        counter++;
    }
    printf("Writing minimum %d and maximum %d to file.\n", min, max);
    itoa(min, s, 10);
    i = 0;
    while (s[i] != '\0')
        putc(s[i++], dst);
    putc('\n', dst);
    itoa(max, s, 10);
    fputs(s, dst);      // using fputs

    printf("\nSeek source file to start and output, using fscanf and fprintf.\n");
    fseek(src, 0l, SEEK_SET);
    while ((fscanf(src, "%s", s)) == 1)
        printf("%s\n", s);
    printf("\nReading file in reverse, using 'fseek'.\n");
    offset = 0;
    while ((fseek(src, -offset, SEEK_END)) == 0) {
        c = getc(src);
        putchar(c);
        ++offset;
    }
    // Пару слов о переносимости и форматах снова.
    printf("\n");
    // Длина файлов и размерности.
    // fgetpos();
    // fgetpos64();

    // Описание модели работы.

    // Буфер и открытые файлы на примерер getchar.
    printf("Maximum open files %u, temporary files %u, buffer size %u.\n", FOPEN_MAX, TMP_MAX, BUFSIZ);

    while ((c = getc(stdin)) != '\n') {
        printf("Char '%c' from input.\n", c);
        ungetc(c, stdin);
        c = getc(stdin);
        printf("Char '%c' from input, after unget\n", c);
    }

    c = setvbuf(src, s, _IOFBF, STRING_MAX);
    printf("Change buffer for source file, code %d.\n", c);
    c = setvbuf(src, NULL, _IOFBF, STRING_MAX);
    printf("Reset buffer for source file, code %d.\n", c);

    printf("Binary and text code to file, %d = '%c'.\n", 33, 33);

    printf("Write some binary data to file and verify after, data: ");
    fseek(dst, 0, SEEK_SET);
    unsigned char data[STRING_MAX];
    const int data_size = 5;
    for (int i = 0; i < data_size; ++i) {
        data[i] = '0' + rand() % 10;
        printf("%d(%c) ", data[i], data[i]);
    }
    c = fwrite(data, sizeof(unsigned char), data_size, dst);
    fflush(dst);
    printf("\nBytes trying to save %d and actual written is %d.\n", data_size, c);
    printf("Verify and read data, ");
    fseek(dst, 0, SEEK_SET);
    clearerr(dst);
    c = fread(data, sizeof(unsigned char), data_size, dst);
    printf("actual read is %d bytes: ", c);
    for (i = 0; i < data_size; ++i)
        printf("%d(%c) ", data[i], data[i]);
    printf("\n");

    c = ferror(src);
    printf("Error last reading file, result %d.\n", c);
    c = feof(dst);
    printf("EOF in file, result %d.\n", c);

    fflush(src);
    if (fclose(src) != 0)
            printf("Something goes wrong with source file.\n");         // Buffer.
    fflush(dst);
    if (fclose(dst) != 0)
            printf("Something goes wrong with destination file.\n");    // Buffer.

    return 0;
}
