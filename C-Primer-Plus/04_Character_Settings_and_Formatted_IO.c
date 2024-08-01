#include <stdio.h>
#include <limits.h>
#include <string.h>

// Глава 4. Символьные строки и форматированный ввод-вывод.

// Демонстрация препроцессора, константы и ограничение размеров строки 255 символов и "\0".
#define STRING_MAX 0x100

void part_04(void)
{   
    printf("Part 4. Strings of chars and input/output format.\n\n");
    // Краткое встпуление и создание строковой переменной.
    // Вопрос. Что представляет из себя символьная строка в языке Си, структура и размещение в памяти.
    char string[STRING_MAX] = "Strings in C!";
    printf("Source string: '%s'.\n", string);
    // Посмотрим по адресам и кодам ASCII массив типа char, нулевой символ и размерность.
    printf("Size of string: %u bytes and length %d chars.\n", sizeof(string), strlen(string));
    printf("Address:\tCode:\tChar:\n");
    for (int i = 0; i <= strlen(string) /* string[i] != '\0' */; ++i)
        printf("%u:\t%d\t'%c'\n", (unsigned int)(&string[i]), string[i], string[i]);
    // Строка может быть использована как константа через define и при вызове функции непосредственно.
    // Также доспутен ввод строк через scanf, getline, fgets и через getchar.
    // Вопрос. Различия между строковыми и символьными константами. Функции strlen и оператор sizeof, массив строк.
    char c = 'a';
    char s[] = "a";
    printf("Size of constants char '%c' is %d, size of string '%s' is %d bytes.\n", c, sizeof(c), s, sizeof(s));
    // Функцию длины строки уже делали или можно использовать библиотеку string.h.
    // Оператор sizeof от типа или конкретного объекта, без скобок не работает тип данных.
    // Вопрос. Виды констант, общие правила и рекомендации, магических чисел стоит избегать, кроме общих.
    // Читаемость, изменяемость. Препроцессор и define - символические константы. Подстановка во время компиляции.
    // Если уж использовать define, то строго прописными буквами, чтобы в глаза бросалось, уточнить constexpr в C++.
    // Вопрос. Константы, их виды, вывод и общие рекомендации по стилю, префиксы и условную компиляцию.
    // Квалификатор или модификатор, зависит от перевода, но лучше ориентироваться на стандарт.
    // Define и limits.h, float.h. Системное использование. Отметить про разные платформы и условную компиляцию.
    const int bits = CHAR_BIT;
    printf("Bits in one char %d.\n", bits);
    // Функции ввода-вывода. Управляющая-строка со спецификаторами преобразования, таблицы разные есть по справочникам.
    // Вопрос. Спецификаторы ввода-вывода, кратко и почему для массивов не требуется взятие адреса, обзорно таблицы.
    printf("Signed integer: %d, hex: 0x%X, double: %.2f, exponent: %.2e.\n", -3, 12, 2.5, 3.5);
    // printf("Specs for %d and %d.\n", 5);                     // Неопределенные данные при выводе. Знак % при выводе.
    // Модификаторы спецификаторов для функции вывода, между спецификатором и знаком %. %z - для sizeof.
    printf("Sign: %+-d, field: %5d, precision %.3g, short: %hu, unsigned char: %hhu, unsigned long: %llu.\n",
        +3, 7, 2.5, 50000, UCHAR_MAX, ULLONG_MAX);
    // Немного про форматирование здесь же отметить. Быть осторожным с округлением чисел с плавайющей точкой.
    float f = 7.5;                     
    printf("Float and double: %.2f.\n", f);
    // Флаги модификаторов функции вывода. Не забыть про ведущий пробел, нули и знаки.
    // Вопрос. Модификаторы вывода тоже просто обзорно по таблице, стараться придерживаться флагов по типам.
    printf("Left align: '%-4d', with plus '%+3d', hex with prefix '%#2X', with zeros '%03d'.\n", 15, +5, 28, -7);
    // Вывод строк. Форматирование. Точка для ограничения вывода и знак для выравнивания.
    printf("String more than filed: '%3s'.\n", string);
    printf("Field more than string: '%20s'.\n", string);
    printf("String with right align: '%20.5s'.\n", string);
    printf("String with left align: '%-20.5s'.\n", string);
    // Спецификатор преобразования работает из данных в представление, спецификатор не всегда может быть однозначен относительно данных.
    // Знаковое и беззнаковое представление чисел. Предупреждение. Поразрядное дополнение до двух. Почему?
    // Вопрос.Чуть внимательней, на спецификаторах и преобразовании типов, лучше кодом, дополнение до двух.
    short int i1 = 49152;                                   // Не всегда срабатывает отбрасывание знака.
    printf("Short int with sign %hd, unsgined char %hu, sizeof type %d bytes.\n", i1, i1, sizeof(short int));
    unsigned int i2 = 0xFE14A5B1;
    unsigned short int i3 = (unsigned short int)i2;
    unsigned char i4 = (unsigned char)i3;
    printf("Unsigned integer: %X, unsigned short: %hX, unsigned char: %X in hex.\n", i2, i3, i4);
    // Смешение целочисленного типа и типа с плавающей точкой, еще более необычно. Предупреждение компилятора.
    f = -1048.576f;                                        // Оформление буквы.
    printf("Float %.2f as unsigned int %u.\n", f, f);
    printf("Unsigned int %u as double %5.5e.\n", i2, i2);
    // Простая реинтерпритация данных, которые расположены в памяти.
    // Возвращаемое значение функции вывода количество всех символов плюс управление, если -1 то ошибка.
    int r = printf("Float %.2f, integer %d.\n", f, i1);
    printf("Function printf() return %d.\n", r);
    // Разбивка оператора на несколько строк, поддержка компилятором.
    // Вопрос. Передача аргументов функций через стек, выделение памяти - просто для ознакомления и длинные строки.
    printf("First line string,\n"
            "second line, parameter %d.\n",
           i1);
    // Функция scanf. В целом всё тоже самое. Спецификаторы и модификаторы подробнее в документации.
    // Вопрос. Ввод по словам функцией scanf и строки в целом через символы разделители и EOF.
    // EOF - для Windows консоли может работать CTRL+Z, для UNIX - CTRL+D, но не всегда.
    printf("Input words as string, use CTRL+Z or CTRL+D and enter to exit.\n");
    while ((r > 0) && (r = scanf("%s", string)))
        printf("Input parameters %d, string '%s' length %d.\n", r, string, strlen(string));
    // Вопрос. Ввод данных с преобразованием, аналогично выводу.
    printf("Enter integer, float, char and string: ");
    double d1;                                                  // %f - спецификатор по умолчанию ожидает float.
    r = scanf("%hd %lf %c %s", &i1, &d1, &c, string);
    printf("Scanf returns %d and parameters: int %d, float %.2f, char '%c' and string '%s'.\n", r, i1, d1, c, string);
    // Обработка ввода функцией scanf. По поток ввода, пока не найден символ разделитель. Или возврат в поток ввода.
    // Обычные символы интерпретируются как условное форматирование.
    printf("Enter two digits with '-' separator: ");
    r = scanf("%hd-%u", &i1, &i2);
    printf("Integers with '-' sep: %d and %d.\n", i1, i2);
    // Вопрос. Модификатор как переменная "*" или пропуск при вводе с подстановкой параметра.
    int l1 = 8, l2 = 3;
    printf("Double with parameters of width %%%d.%d: %*.*f.\n", l1, l2, l1, l2, d1);
}
