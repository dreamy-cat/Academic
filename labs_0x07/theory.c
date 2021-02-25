#include "labs_0x07.h"

// Все теоретические части, которые были рассмотрены на вещаниях.
// Учебник - Прата(6-ое издание), КиР, стандарт языка и немного по видео.

void theory_04(void)
{
    printf("Theory and examples for stream, chapter 4.\n");
    printf("Strings of chars and string format.\n");
    // Небольшое встпуление и создание переменных. Строка как последовательность символов.
    char string[256] = "This is text string.";
    printf("String: '%s'.\n", string);
    // Массив типа чар, нулевой символ и размерность. Посмотрим по адресам и кодам АСКИИ.
    printf("Size of string: %d.\n", sizeof(string));
    printf("Address:\tCode:\tChar:\n");
    for (int i = 0;  i < 25/* string[i] != '\0' */; ++i)
        printf("%u:\t%d\t'%c'\n", (unsigned int)(&string[i]), string[i], string[i]);
    // Строка может быть использована как константа через define и при вызове функции непосредственно.
    // Отметить про ввод строк через сканф, фгетс и через getchar.
    // Различия между строковыми и символьными константами. Каков размер в памяти?
    char c1 = 'a';
    char s1[] = "a";
    printf("Size of char '%c' is %d, size of string '%s' is %d.\n", c1, sizeof(c1), s1, sizeof(s1));
    // Функцию длины строки уже все делали, это классика. string.h или strings.h
    // Про sizeof от типа или конкретного объекта, без скобок не работает.
    // Константы и препроцессор. Магических чисел стоит избегать, кроме обычно -1, 0, 1. Что предпочесть?
    // Читаемость, изменяемость. Препроцессора лучше избегать define - символические константы. Подстановка во время компиляции.
    // Если уж использовать define, то строго прописными буквами, чтобы в глаза бросалось. constexpr в с++.
    const int bits = CHAR_BIT;      // Квалификатор или модификатор, зависит от перевода.
    // Далее про define и limits.h и системное использование. float.h. Отметить про разные платформы и условную компиляцию.
    printf("Bits in one char %d.\n", bits);
    // Функции ввода-вывода, не являются частью языка. Управляющая-строка со спецификаторами преобразования, таблицы разные есть по справочникам.
    printf("Signed integer: %d, hex: 0x%X, double: %.2f, exponent: %.2e.\n", -3, 12, 2.5, 3.5);
    // printf("Specs for %d and %d.\n", 5);     // Неопределенные данные при выводе. Знак % при выводе.
    // Модификаторы спецификаторов для функции вывода, между спецификатором и знаком %. %z - для sizeof.
    printf("Sign: %+-d, field: %5d, precision %.3g, short: %hu, unsigned char: %hhu, unsigned long: %llu.\n", +3, 7, 2.5, 50000, UCHAR_MAX, ULLONG_MAX);
    float f1 = 7.5;     // Немного про форматирование здесь же отметить. Быть осторожным с округлением.
    printf("Float and double: %.2f.\n", f1);
    // Флаги функции вывода. Не забыть про ведущий пробел.
    printf("Left align: '%-4d', with plus '%+3d', hex with prefix '%#2X', with zeros '%03d'.\n", 15, +5, 28, -7);
    // Вывод строк. Форматирование. Точка для ограничения вывода и знак для выравнивания.
    char s[] = "8-Bit Tea Party!";
    printf("String more than filed: '%3s'.\n", s);
    printf("Field more than string: '%20s'.\n", s);
    printf("String with right align: '%20.5s'.\n", s);
    printf("String with left align: '%-20.5s'.\n", s);
    // Спецификатор преобразования работает из данных в представление, спецификатор не всегда может быть однозначен относительно данных.
    // Знаковое и беззнаковое представление чисел. Предупреждение. Поразрядное дополнение до двух. Почему?
    short int i1 = 49152;       // Не всегда срабатывает отбрасывание знака.
    printf("Short int with sign %hd, unsgined char %hu, sizeof type %d.\n", i1, i1, sizeof(short int));
    unsigned int i2 = 0xFE14A5B1;
    unsigned short int i3 = (unsigned short int)i2;
    unsigned char i4 = (unsigned char)i3;
    printf("Unsigned integer: %X, unsigned short: %hX, unsigned char: %X.\n", i2, i3, i4);
    // Смешение целочисленного типа и типа с плавающей точкой, еще более необычно. Предупреждение компилятора.
    f1 = -1048.576f;            // Оформление буквы.
    printf("Float %.2f as unsigned int %u.\n", f1, f1);
    printf("Unsigned int %u as double %5.5e.\n", i2, i2);
    // Простая реинтерпритация данных, которые расположены в памяти.
    // При передаче printf аргументов работает стек и память выделяется на нём.
    // Возвращаемое значение функции вывода количество всех символов плюс управление, если -1 то ошибка.
    int r = printf("Float %.2f, integer %d.\n", f1, i1);
    printf("Function printf() return %d.\n", r);
    // Разбивка оператора на несколько строк, поддержка компилятором.
    printf("First line string,\n"
            "second line, parameter %d.\n",
           i1);
    // Функция scanf. В целом всё тоже самое. Спецификаторы и модификаторы все в силе.
    char buffer[256];
    printf("Enter integer, float, char and string: ");
    double d1;      // %f - спецификатор по умолчанию ожидает float.
    r = scanf("%hd %lf %c %s", &i1, &d1, &c1, buffer);
    printf("Scanf returns %d and parameters: int %d, float %.2f, char '%c' and string '%s'.\n", r, i1, d1, c1, buffer);
    // Обработка ввода функцией scanf. По поток ввода, пока не найден символ разделитель. Или возврат в поток ввода.
    // Строка считывает фактически слово.
    // Обычные символы интерпретируются как условное форматирование.
    printf("Enter two digits with '-':");
    scanf("%d-%d", &i1, &i2);
    printf("Integers with '-' sep: %d and %d.\n", i1, i2);
    // Модификатор * для определения поля с подстановкой параметра.
    int l1 = 8, l2 = 3;
    printf("Double with parameters of width: %*.*f.\n", l1, l2, d1);
    // Фиксированная длинна/ширина полей для столбцов и таблиц.
    // Про локальную, использовать как есть пока что.
    // Ключевые вопросы: как представлен символ, строка и как они хранятся.
    // define - стараться избегать. Быть осторожным с интерпретацией float и double.
    // Формат строки Си.
}
