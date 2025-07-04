#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/* Лабораторная №2.
 *
 * Разработать класс даты и времени, используя основные принципы модульного подхода и ООП со следующими полями и методами:
 *  структуры даты и времени;
 *  4 конструктора (конструктор по умолчанию, конструктор копирования, конструктор с параметрами (int, struct), конструктор перемещения);
 *  все поля сделать приватными, и для каждого поля сделать inline методы get() и set();
 *  метод печати даты и времени по заданному шаблону
 *  статический метод проверки набора чисел на корректность дате;
 *  статический метод проверки набора чисел на корректность времени;
 *  статический метод текущего времени и текущей даты;
 *  метод перевода даты и времени в строку по заданному формату. Проверить метод на примерах печати в файл и в консоль;
 *  метод date() возвращает дату в виде структуры;
 *  метод time() возвращает время в виде структуры;
 *  статический метод получения даты и времени из строки, метод должен получать 2 параметра строку с датой и строку формата;
 *  методы addSecs(), addMinutes(), addDays(), addMonths(), addYears();
 *  метод daysTo() определения дней до даты, Метод secsTo() определения секунд до даты;
 *  методы, которые работают с типом time_t из С библиотеки;
 *
 *  Обработка ошибок и некорректной даты на усмотрение студента, без try catch.
 *  Методы, которые не изменяют объект сделать константными. Без учета високосного года.
 *  Использовать модульный подход и покрыть тестами все методы.
 *
 * */

/*  Общие рекомендации: в каждой функции вывести все изменяемые параметры и саму функцию.
 *  Все объекты даты и времени существуют и динамическую память можно не использовать.
 *  Не забыть константу CLOCKS_PER_SEC.
 *  Формат представления стандартный, регистр учитывать. Минимально учесть цифры в дате и времени.
 *  "y - год, b - месяц, d - день, H - час, M - минуты, S - секунды и т.д.
 *  Остальные символы оставялем как есть. Все функции протестировать.
 *  Для удобства можно формат тестирования строку по умолчанию вынести в статику.
 *
 * */

#define TEXT_MAX 0x100

struct date_time {                                                              // Общая структура.
    struct tm date;
    time_t time;
    clock_t clocks;
};

char text_format[] = "%B %d, %A. In year %Y: week %U, day %j. Time %H:%M:%S.";

char def_fmt[] = "%d-%m-%Y %H:%M:%S";

void print_date_time(struct date_time* dt, char fmt[])
{   // Вывести все данные в структуре по формату, и можно дополнительно адрес самого объекта.
    char text[TEXT_MAX];
    for (int i = 0; i < TEXT_MAX; ++i)
        text[i] = '\0';
    printf("Date and time object at [%p], time %ld and clocks %ld, size is %u bytes.\n",
           dt, dt->time, dt->clocks, sizeof(struct date_time));
    strftime(text, TEXT_MAX, fmt, &dt->date);
    printf("Date and time: '%s'.\n", text);
}

void create_date_time(struct date_time* dt, int is_current)
{   // Создание нашего объекта даты и времени текщими значениями, можно локальными, на момент вызова или простое зануление.
    if (is_current) {
        dt->time = time(NULL);
        dt->date = *localtime(&dt->time);
        dt->clocks = clock();
    } else {
        for (unsigned int i = 0; i < sizeof(struct date_time); ++i)
            ((char*)dt)[i] = 0;
        dt->date.tm_mday = 1;
        // dt->date = *localtime(&dt->time);
    }
    printf("Create date and time. Timer %ld, clocks %ld and local time: %s",
           dt->time, dt->clocks, ctime(&dt->time));
}

void copy_date_time(struct date_time* dst, struct date_time* src)
{   // Копирование объекта источника в объект назначения. Вывести все параметры объектов.
    printf("Copy object Date_Time elements from source at [%p] to destination at [%p].\n", src, dst);
    printf("Source object:\n");
    print_date_time(src, def_fmt);
    printf("Destination object before copy:\n");
    print_date_time(dst, def_fmt);
    dst->time = src->time;
    dst->clocks = src->clocks;
    dst->date.tm_hour = src->date.tm_hour;
    dst->date.tm_isdst = src->date.tm_isdst;
    dst->date.tm_mday = src->date.tm_mday;
    dst->date.tm_min = src->date.tm_min;
    dst->date.tm_mon = src->date.tm_mon;
    dst->date.tm_sec = src->date.tm_sec;
    dst->date.tm_wday = src->date.tm_wday;
    dst->date.tm_yday = src->date.tm_yday;
    dst->date.tm_year = src->date.tm_year;
    printf("Destination object after copy:\n");
    print_date_time(dst, def_fmt);
}

void move_date_time(struct date_time** dst, struct date_time** src)
{   // Перемещение объекта даты и времени в объект назначения, приемник не обязателен к сохранению.
    printf("Move pointers to objects Date_Time from source [%p] to destination [%p].\n", *src, *dst);
    printf("Source object, using pointer:\n");
    print_date_time(*src, def_fmt);
    printf("Destination object, using pointer:\n");
    print_date_time(*dst, def_fmt);
    *dst = *src;
    printf("Destination object after moving, using pointer:\n");
    print_date_time(*dst, def_fmt);
}

int is_correct_date_time(char src[], char fmt[])
{   // Проверка условно введенной тесктовой строки по заданному формату, на корректность объекта.
    // Символы вне параметров не обязательны для совпадения, но общее количество желательно равное.
    // Обработать можно только цифры, слова дополнительно, тогда сделать словарь.
    // "%B %d, %A. In year %Y: week %U, day %j. Time %H:%M:%S."
    const char p_digits[] = "dmYUjHMS";                 // Минимальный набор букв формата, который заменяется на цифры.
    const int p_dig_len[] = { 2, 2, 4, 2, 3, 2, 2, 2};  // Длины параметров по-умолчанию.
    // const char p_words[] = "BA";                     // Минимальный набор букв формата, проверка только на буквы, без словаря.
    printf("Checking source string '%s' as format '%s'.", src, fmt);
    for (int i = 0, j = 0, k, l; src[i] != '\0' && fmt[j] != '\0'; ) {  // // Вставить проверку на календарь, заполнив временные параметры по возможности.
        if (fmt[j++] == '%') {
            for (k = 0; fmt[j] != p_digits[k]; ++k)
                ;
            printf("\nK = %d, chars: ", k);
            if (p_digits[k] == fmt[j]) {
                for (l = 0; l < p_dig_len[k]; ++l, ++i) {
                    printf("%c", src[i]);
                    if (!(src[i] >= '0' && src[i] <= '9'))
                        break;
                }
                if (l != p_dig_len[k]) {
                    printf("Source string at %d, char '%c'. Parameter '%c' with length %d incorrect.\n",
                           i, src[i], fmt[j], p_dig_len[k]);
                    return -1;
                } else
                    printf(" parameter as '%c' correct.\n", fmt[j]);
                ++j;
            }
        } else
            printf("Just char format '%c', src '%c'.", fmt[j - 1], src[i++]);
    }
    return 0;
}

void string_to_date_time(struct date_time* dt, char src[], char fmt[])
{   // Преобразование исходной текстовой строки по формату, в объект. Проверку дополнительно.
    if (is_correct_date_time(src, fmt) == -1)
        return;
    printf("Checking source string '%s' as format '%s' is correct.\n", src, fmt);
    const char p_digits[] = "dmYUjHMS";                 // Минимальный набор букв формата, который заменяется на цифры.
    const int p_dig_len[] = { 2, 2, 4, 2, 3, 2, 2, 2 }; // Длины параметров по-умолчанию.
    const int start_year = 1900;
    char word[TEXT_MAX];
    for (int i = 0, j = 0, k, l; src[i] != '\0' && fmt[j] != '\0'; ) {
        if (fmt[j++] == '%') {
            for (k = 0; fmt[j] != p_digits[k]; ++k)
                ;
            printf("Found parameter '%c', length %d, word '", fmt[j], p_dig_len[k]);
            for (l = 0; l < p_dig_len[k]; ++l, ++i) {
                word[l] = src[i];
                printf("%c", src[i]);
            }
            word[l] = '\0';
            int p = atoi(word);
            printf("', integer %d.\n", p);
            switch (fmt[j]) {
            case 'd':
                dt->date.tm_mday = p;
                break;
            case 'm':
                dt->date.tm_mon = p - 1;    // month from 0.
                break;
            case 'Y':
                dt->date.tm_year = p - start_year;
                break;
            case 'H':
                dt->date.tm_hour = p;
                break;
            case 'M':
                dt->date.tm_min = p;
                break;
            case 'S':
                dt->date.tm_sec = p;
                break;
            default:
                printf("Parameter '%c' not saved to data, using default.\n", fmt[j]);
            }
            ++j;
        } else
            printf("Just char fmt '%c', src '%c'.\n", fmt[j - 1], src[i++]);
    }
    printf("Result of date time:\n");
    print_date_time(dt, fmt);
}

void get_date(struct date_time* dt, struct tm* date)
{   // Получение даты стандартной структуры из объекта.
    printf("Get date struct 'tm' from Date_Time object at [%p] to [%p] .\n", dt, date);
    *date = dt->date;
}

void get_time(struct date_time* dt, time_t* time)
{   // Получение объекта времени из структуры объекта.
    printf("Get time struct 'time_t' from Date_Time object at [%p] to [%p].\n", dt, time);
    *time = dt->time;
}

void add_date_time(struct date_time* dst, struct date_time* src)
{   // Сложение объектов времени, назначение и приёмник.
    // Источник как количественный показатель, а не как дата, но должна быть корректна.
    printf("Add one Date_Time at [%p] to other object at [%p].\n", dst, src);
    if (dst->date.tm_isdst != src->date.tm_isdst) {
        printf("Summer time parameter is not equal in dates.\n");
        return;
    }
    printf("Destination Date_Time: ");
    print_date_time(dst, def_fmt);
    printf("Source Date_Time: ");
    print_date_time(src, def_fmt);
    char time_txt[TEXT_MAX];
    const int days_month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    const int sec_per_min = 60, min_per_hour = 60, hours_per_day = 24;
    int extra, leap_year;

    dst->date.tm_sec += src->date.tm_sec;
    if ((dst->date.tm_sec) >= sec_per_min) {
        dst->date.tm_sec %= sec_per_min;
        extra = 1;
    } else
        extra = 0;
    dst->date.tm_min += src->date.tm_min + extra;
    if (dst->date.tm_min >= min_per_hour) {
        dst->date.tm_min %= min_per_hour;
        extra = 1;
    } else
        extra = 0;
    dst->date.tm_hour += src->date.tm_hour + extra;
    if (dst->date.tm_hour >= hours_per_day) {
        dst->date.tm_hour %= hours_per_day;
        extra = 1;
    } else
        extra = 0;

    // 25 feb + 5 days = 1 mar + 1 day.
    // 31 jan + 32 days = 28 feb + 3 days = 3 march.
    // 1 feb + 31 days = 30 % 31 = 1

    // printf("%d\n", 29 % 31);

    int days = src->date.tm_mday + extra;
    // days = 2; dst->date.tm_mday = 29; dst->date.tm_mon = 6;
    printf("%d_%d_mon_%d days add %d.\n", dst->date.tm_mday, src->date.tm_mday, dst->date.tm_mon, days);
    while ((dst->date.tm_mday + days) > days_month[dst->date.tm_mon]) {
        int to_month = days_month[dst->date.tm_mon] - dst->date.tm_mday + 1;
        printf("To month: %d, days before %d, ", to_month, days);
        days -= to_month;
        printf("days after %d.\n", days);
        dst->date.tm_mday = 1;
        dst->date.tm_mon++;
    }
    dst->date.tm_mday += days;
    printf("result = %d.\n", dst->date.tm_mday);

    dst->date.tm_mon += src->date.tm_mon;
    if (dst->date.tm_mon > 12) {
        dst->date.tm_mon %= 12;
        extra = 1;
    } else
        extra = 0;

    printf("Y = %d_%d.\n", dst->date.tm_year, src->date.tm_year);
    dst->date.tm_year += src->date.tm_year + extra;
    strftime(time_txt, TEXT_MAX, "%d-%m-%Y %H:%M:%S", &dst->date);
    printf("Destination as string: '%s'.\n", time_txt);

    // string_to_date_time();
}

time_t diff_date_time(struct date_time* dt_a, struct date_time* dt_b)
{   // Разница между двумя объектами дат. Выход по времени.

    time_t left = mktime(&dt_a->date), right = mktime(&dt_b->date);
    time_t diff = difftime(left, right);
    printf("Time in source: %ld, destination %ld and diff is %ld.\n", left, right, diff);
    return diff;
}

#include <float.h>

int main()
{
    printf("Laboratory 2. Standard time library, structure and functions.\n\n");
    printf("Object of 'date_time' size is %u and 'clocks per second' %u.\n",
           sizeof(struct date_time), CLOCKS_PER_SEC);                           // Общий размер объекта.
    struct date_time dt_a, dt_b, dt_c;                                          // Тестовые объекты.
    struct date_time* dt_ptr_a = &dt_a, *dt_ptr_b = &dt_b;                      // Адреса объектов дат для перемещения.
    printf("Offset:\tSize:\tComment:\n");                                       // Смещение данных в базовом объекте и их размеры, таблица.
    printf("%u\t%u\tStructure 'tm' for date and time.\n", (void*)&dt_c.date - (void*)&dt_c, sizeof(dt_c.date));
    printf("%u\t%u\tTime in seconds from start of epoch.\n", (void*)&dt_c.time - (void*)&dt_c, sizeof(dt_c.time));
    printf("%u\t%u\tClocks from start.\n", (void*)&dt_c.clocks - (void*)&dt_c, sizeof(dt_c.clocks));
    printf("\nCreating pair of object Date_Time 'A' and 'B'.\n");
    create_date_time(&dt_a, 1);
    print_date_time(&dt_a, def_fmt);
    create_date_time(&dt_b, 0);
    print_date_time(&dt_b, def_fmt);
    printf("\nCopy object Date_Time from 'A' to 'B'.\n");
    copy_date_time(&dt_b, &dt_a);
    printf("\nClear object B and move pointer object 'A' at [%p] to 'B' at [%p].\n", dt_ptr_a, dt_ptr_b);
    create_date_time(&dt_b, 0);
    move_date_time(&dt_ptr_b, &dt_ptr_a);

    printf("\nConvert string to Date Time object, using string format.\n");
    // is_correct_date_time("2001-01", "%Y-%d");
    create_date_time(&dt_c, 1);
    string_to_date_time(&dt_c, "31-01-2001 23:58:55", "%d-%m-%Y %H:%M:%S");
    // print_date_time(&dt_c, "%d-%m-%Y %H:%M:%S");

    printf("\nAdd.\n");

    string_to_date_time(&dt_a, "31-01-2001 23:58:55", "%d-%m-%Y %H:%M:%S");
    string_to_date_time(&dt_c, "31-01-1900 00:01:04", "%d-%m-%Y %H:%M:%S");
    add_date_time(&dt_a, &dt_c);

    diff_date_time(&dt_a, &dt_b);


    return 0;
}   // 190

/*

int analyzer_3000(char src[], const char** list, int *k, int *index, int length_of_list)
{
    int src_len = strlen(src), j = 0;
    char substr[4]; // на первые три буквы + '\0'
    substr[3] = '\0';
    for (j = 0; j < 3 && *k + j < src_len; ++j)
        substr[j] = src[*k + j];
    int* pos;
    int length = 0, idx = -1;
    for (j = 0; j < length_of_list; ++j)
        if ((strstr(list[j], substr) - list[j]) == 0) {
            length = strlen(list[j]);
            idx = j;
            break;
        }
    if (idx != -1)
        for (j = *k; (j - *k ) < length && j < src_len; ++j)
            if (src[j] != list[idx][j - *k])
                break;
    if ((j - *k) != length || idx == -1) {
        printf("src error in month on %d;\n", *k);
        return -1;
    }
    *k += strlen(list[idx]);
    *index = idx;
    return 0;
}

int analyzer_3000_v2(char src[], const int length, int upper_limit, int lower_limit, int *k, int *number)
{
    char day[length + 1];
    day[length] = '\0';
    int i = 0;
    for (; i < length; ++i)
        day[i] = src[*k + i];
    int num = atoi(day);
    if (num < lower_limit || num > upper_limit)
        return -1;
    *k += length;
    *number = num;
    return 0;
}

int is_correct_date_time(char src[], char fmt[])
{   // Проверка условно введенной текстовой строки по заданному формату, на корректность объекта.
    int src_len = strlen(src), fmt_len = strlen(fmt);
    if (src_len == 0 || fmt_len == 0) {
        printf("src or fmt have the incorrect size;\n");
        return -1;
    }
    const char* months[] = {"January", "February", "March", "April", "May", "June", "July",
                            "August", "September", "October", "November", "December"};
    const char* days_of_the_week[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    const char commands[] = "BdAYUjHMS";
    int com_len = strlen(commands);
    const int months_in_year = 12;
    const int days_in_week = 7;
    int start_pos = 0, flag = 0;
    for (int i = 0, j; i < fmt_len; ++i) {
        j = 0;
        flag = 0;
        if (fmt[i] == '%') {
            for (; j < com_len; ++j)
                if (commands[j] == fmt[i + 1]) {
                    flag = 1;
                    break;
                }
        }
        if (flag) {
            start_pos = i;
            break;
        }
    }
    for (int i = start_pos, k = start_pos, j = 0, f = 0; i < fmt_len && k < src_len; ++i) {
        if (fmt[i] == '%') {
            switch (fmt[i + 1]) {
            case 'B': {
                int number = 0;
                int result = analyzer_3000(src, months, &k, &number, months_in_year);
                if (result == -1)
                    return result;
            }   break;
            case 'd': {
                const int length_of_day = 2;
                int number = 0;
                int result = analyzer_3000_v2(src, length_of_day, 31, 1, &k, &number);
                if (result == -1) {
                    printf("src error in day on %d;\n", k - length_of_day);
                    return result;
                }
            } break;
            case 'A': {
                int number = 0;
                int result = analyzer_3000(src, days_of_the_week, &k, &number, days_in_week);
                if (result == -1)
                    return result;
            } break;
            case 'Y': {
                const int length_of_year = 4;
                int number = 0;
                int result = analyzer_3000_v2(src, length_of_year, 9999, 1900, &k, &number);
                if (result == -1) {
                    printf("src error in year on %d;\n", k - length_of_year);
                    return result;
                }
            } break;
            case 'U': {
                const int length_of_weeks_in_year = 2;
                int number = 0;
                int result = analyzer_3000_v2(src, length_of_weeks_in_year, 53, 0, &k, &number);
                if (result == -1) {
                    printf("src error in week in year on %d;\n", k - length_of_weeks_in_year);
                    return result;
                }
            } break;
            case 'j': {
                const int length_of_days_in_year = 3;
                int number = 0;
                int result = analyzer_3000_v2(src, length_of_days_in_year, 366, 1, &k, &number);
                if (result == -1) {
                    printf("src error in days in year on %d;\n", k - length_of_days_in_year);
                    return result;
                }
            } break;
            case 'H': {
                const int length_of_hours_in_day = 2;
                int number = 0;
                int result = analyzer_3000_v2(src, length_of_hours_in_day, 23, 0, &k, &number);
                if (result == -1) {
                    printf("src error in hours in day on %d;\n", k - length_of_hours_in_day);
                    return result;
                }
            } break;
            case 'M': {
                const int length_of_minutes_in_hour = 2;
                int number = 0;
                int result = analyzer_3000_v2(src, length_of_minutes_in_hour, 59, 0, &k, &number);
                if (result == -1) {
                    printf("src error in minutes in hour on %d;\n", k - length_of_minutes_in_hour);
                    return result;
                }
            } break;
            case 'S': {
                const int length_of_seconds_in_minute = 2;
                int number = 0;
                int result = analyzer_3000_v2(src, length_of_seconds_in_minute, 59, 0, &k, &number);
                if (result == -1) {
                    printf("src error in seconds in minute on %d;\n", k - length_of_seconds_in_minute);
                    return result;
                }
            } break;
            default:
                break;
            }
            for (j = i + 2; j < fmt_len; ++j) {
                f = 0;
                flag = 0;
                if (fmt[j] == '%')
                    for (; f < com_len; ++f)
                        if (commands[f] == fmt[j + 1]) {
                            flag = 1;
                            break;
                        }
                if (flag) {
                    k += j - (i + 2);
                    break;
                }
            }
        }
    }
    return 0;
}

void string_to_date_time_alt(struct date_time* dt, char src[], char fmt[])
{   // Преобразование исходной текстовой строки по формату, в объект. Проверку дополнительно.
    int src_len = strlen(src), fmt_len = strlen(fmt);
    if (src_len == 0 || fmt_len == 0) {
        printf("src or fmt have the incorrect size;\n");
        return;
    }
    const char* months[] = {"January", "February", "March", "April", "May", "June", "July",
                            "August", "September", "October", "November", "December"};
    const char* days_of_the_week[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    const char commands[] = "BdAYUjHMS";
    int com_len = strlen(commands);
    const int months_in_year = 12;
    const int days_in_week = 7;
    int start_pos = 0, flag = 0;
    for (int i = 0, j; i < fmt_len; ++i) {
        j = 0;
        flag = 0;
        if (fmt[i] == '%') {
            for (; j < com_len; ++j)
                if (commands[j] == fmt[i + 1]) {
                    flag = 1;
                    break;
                }
        }
        if (flag) {
            start_pos = i;
            break;
        }
    }
    for (int i = start_pos, k = start_pos, j = 0, f = 0; i < fmt_len && k < src_len; ++i) {
        if (fmt[i] == '%') {
            switch (fmt[i + 1]) {
            case 'B': {
                int number = 0;
                int result = analyzer_3000(src, months, &k, &number, months_in_year);
                if (result == -1)
                    return;
                else
                    dt->date.tm_mon = number;
            }   break;
            case 'd': {
                const int length_of_day = 2;
                int number = 0;
                int result = analyzer_3000_v2(src, length_of_day, 31, 1, &k, &number);
                if (result == -1) {
                    printf("src error in day on %d;\n", k - length_of_day);
                    return;
                } else
                    dt->date.tm_mday = number;
            } break;
            case 'A': {
                int number = 0;
                int result = analyzer_3000(src, days_of_the_week, &k, &number, days_in_week);
                if (result == -1)
                    return;
                else
                    dt->date.tm_wday = number;
            } break;
            case 'Y': {
                const int length_of_year = 4;
                int number = 0;
                int result = analyzer_3000_v2(src, length_of_year, 9999, 1900, &k, &number);
                if (result == -1) {
                    printf("src error in year on %d;\n", k - length_of_year);
                    return;
                } else
                    dt->date.tm_year = number;
            } break;
            case 'U': {
                int number = 0;
                const int length_of_weeks_in_year = 2;
                int result = analyzer_3000_v2(src, length_of_weeks_in_year, 53, 0, &k, &number);
                if (result == -1) {
                    printf("src error in week in year on %d;\n", k - length_of_weeks_in_year);
                    return;
                }
            } break;
            case 'j': {
                int number = 0;
                const int length_of_days_in_year = 3;
                int result = analyzer_3000_v2(src, length_of_days_in_year, 366, 1, &k, &number);
                if (result == -1) {
                    printf("src error in days in year on %d;\n", k - length_of_days_in_year);
                    return;
                } else
                    dt->date.tm_yday = number - 1;
            } break;
            case 'H': {
                int number = 0;
                const int length_of_hours_in_day = 2;
                int result = analyzer_3000_v2(src, length_of_hours_in_day, 23, 0, &k, &number);
                if (result == -1) {
                    printf("src error in hours in day on %d;\n", k - length_of_hours_in_day);
                    return;
                } else
                    dt->date.tm_hour = number;
            } break;
            case 'M': {
                int number = 0;
                const int length_of_minutes_in_hour = 2;
                int result = analyzer_3000_v2(src, length_of_minutes_in_hour, 59, 0, &k, &number);
                if (result == -1) {
                    printf("src error in minutes in hour on %d;\n", k - length_of_minutes_in_hour);
                    return;
                } else
                    dt->date.tm_min = number;
            } break;
            case 'S': {
                int number = 0;
                const int length_of_seconds_in_minute = 2;
                int result = analyzer_3000_v2(src, length_of_seconds_in_minute, 59, 0, &k, &number);
                if (result == -1) {
                    printf("src error in seconds in minute on %d;\n", k - length_of_seconds_in_minute);
                    return;
                } else
                    dt->date.tm_sec = number;
            } break;
            default:
                break;
            }
            for (j = i + 2; j < fmt_len; ++j) {
                f = 0;
                flag = 0;
                if (fmt[j] == '%')
                    for (; f < com_len; ++f)
                        if (commands[f] == fmt[j + 1]) {
                            flag = 1;
                            break;
                        }
                if (flag) {
                    k += j - (i + 2);
                    break;
                }
            }
        }
    }
}

* */



