#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

/*  Наш вариант для Си. Лабораторая работа №3. Рациональные числа и методы для работы с ними.
 *  Рациональное число, представленное числителем со знаком и знаменателем без знака, 32 бита.
 *  Представить рациональное число в виде структуры и реализовать функции работы с ним.
 *  Все арифметические операции исполнить математически, увеличение и уменьшение на единицу - только числитель.
 *  Быть внимательным, не теряем знак. Строковый формат: "числитель/знаменатель", остальное пропускаем как незаначимое.
 *  Код должен быть максимально надежным, отработать на тестах крайние и неверные значения.
 *  Функции стараться сделать как можно более компактными, используя только сам код.
 *  Во всех функциях вывести адреса объектов, если не указано отдельно, и подробный вывод по выполнению.
 *  Функцию сравнения по адресу дополнительно. Подробнее описание в самих функциях.
 *  При переполнении типов, вывести сообщение, но оставить вычисления как есть.
 *  Можно использовать минимумы и максимумы INT_MIN, INT_MAX.
 *  Код компилируется: GCC 8.1.0, 32-bits.
 * */

// Параметр максимальной длины текста не должна превышать INT_MAX.
#define TEXT_MAX 0x100

struct rational {                                           // Простая структура представления рационального числа.
    int numerator;                                          // Числитель со знаком. Или можно было знак реализовать отдельным параметром.
    unsigned int denominator;                               // Знаменатель. Любое положительное число, выше 0. При нуле выходим с сообщением.
};

int* get_numerator(struct rational* r)
{   // Получение адреса числителя рационального числа, без вывода. Копирования в стек не происходит.
    if (r != NULL)                                          // Проверяем адрес на существование.
        return  &r->numerator;
    else {
        printf("Error get numerator, rational address is NULL.\n");
        return NULL;                                        // Возвращаем для контроля за ошибками.
    }
}

unsigned int* get_denominator(struct rational* r)
{   // Получение адреса знаменателя рационального числа, без вывода. Копирование в стек не происходит.
    if (r != NULL)                                          // Проверяем адрес на допустимость.
        return &r->denominator;
    else {                                                  // Возвращаем NULL, в случае ошибки.
        printf("Error get denominator, rational address is NULL.\n");
        return NULL;
    }
}

int is_correct(struct rational* r)
{   // Проверка числа на корректность. Без вывода, просто возвращаем результат 1 - если дробь корректна, 0 - в ином случае.
    if ((r != NULL) && *get_denominator(r) != 0)            // Или возможно одной строчкой, скобки для страховки но опасный код, лучше последовательно.
        return 1;
    else
        return 0;
}

void set_numerator(struct rational* r, int* num)
{   // Установка числителя рационального числа, через адрес.
    if (r == NULL || num == NULL) {                         // Проверка на допустимость.
        printf("Error, can't set numerator. Rational or num addresses is NULL.\n");
        return;
    }
    r->numerator = *num;                                    // Копируем, значение по адресу назначения.
}

void set_denominator(struct rational* r, unsigned int* den)
{   // Установка знаменателя рационального числа, через адреса.
    // Опасное условие, не разрушится, только если оптимизация проверит на NULL прежде чем произойдет чтение по адресу.
    if ((r == NULL || den == NULL) || (den != NULL && *den == 0 )) {
        printf("Error, can't set denominator. Addresses or parameter is NULL or 0.\n");
        return;
    }
    r->denominator = *den;                                  // Копируем, значение по адресу назначения.
}

void print(struct rational* r, int endl)
{   // Вывести все данные в структуре по формату по-умолчанию, кроме адреса объекта. В виде: "N/M", для удобного использования.
    // endl - количество пропусков строки после вывода, для удобства тестирования и вывода к консоль.
    if (!is_correct(r)) {                      // Простая проверка на корректность.
        printf("Warning, can't print. Address of Rational or number itselsf are incorrect.\n");
        return;
    }
    printf("%d/%u", *get_numerator(r), *get_denominator(r));
    while (endl--)                                          // Конец строки если требуется перенос.
        printf("\n");
}

void create(struct rational* r, int num, unsigned int den)
{   // Создание объекта заданными значениями, если знаменатель равен нулю, то создать дробь по-умолчанию 1/1.
    if (r == NULL) {                                        // Проверка адреса.
        printf("Error creating rational object, address is NULL.\n");
        return;
    }
    if (den != 0) {
        r->numerator = num;                                 // Оставляем как есть или можно через вызов дополнительных функций.
        r->denominator = den;                               // Выводим вместе с адресом объекта.
        printf("Create object from parameters, %d/%u, at (%p).\n", num, den, r);
    } else {
        r->numerator = r->denominator = 1;                  // Создание объекта по-умолчанию (1/1), если знаменатель равен нулю.
        printf("Denominator is 0, creating default rational 1/1, at (%p).\n", r);
    }
}

void copy(struct rational* dst, struct rational* src)
{   // Копирование объекта источника в объект назначения, исходник остается неизменным.
    if (!is_correct(src) || !is_correct(dst)) {             // Проверка на допустимость.
        printf("Source or destination rational objects are incorrect.\n");
        return;
    }
    set_numerator(dst, get_numerator(src));                 // Используем базовые функции для установки числителя и знаменателя.
    set_denominator(dst, get_denominator(src));             // Передача с выхода во вход происходит через адреса.
    printf("Copy rational from (%p) source ", src);         // Контрольный вывод с содрежимым объектов рациональных чисел.
    print(src, 0);
    printf(" to (%p) destination ", dst);
    print(dst, 1);
}

void move(struct rational** dst, struct rational** src)
{   // Перемещение объекта  в объект назначения, приемник не обязателен к сохранению.
    if (dst == NULL || src == NULL) {                       // Поскольку идет только перемещение объектов, то проверяем только адреса.
        printf("Move error, source or destination pointers are NULL.\n");
        return;
    }
    printf("Move pointers to rational objects, from (%p) to (%p).\n", src, dst);
    *dst = *src;                                            // Копирование только указателей, т.к. динамических элементов структуре нет.
}

int is_int_overflow(unsigned int n, int sign)
{   // Проверка параметра integer со знаком на переполнение, с учетом знака. Осторожней с правой частью, порядком исполнения.
    // Или для проверки можно использовать любой другой способ. Вывод для демонстрации.
    unsigned int abs_int_min = INT_MIN ^ ((unsigned int)-1);// Преобразуем путем исключающего или в максимально возможное положительное число.
    // printf("Absolute integer minimum = %u, sign = %d, n = %u.\n", abs_int_min, sign, n);
    return ((sign == +1 && n > INT_MAX) || (sign == -1 && n > abs_int_min));
}

unsigned int gcd(unsigned int a, unsigned int b)
{   // Вспомогательная функция нахождения наибольшего общего делителя, если требуется, без вывода.
    while (a != 0 && b != 0)                                // Классический алгоритм Евклида.
        if (a > b)
            a %= b;
        else
            b %= a;
    return (a + b);                                         // Возврат нуля возможен.
}

unsigned int lcm(unsigned int a, unsigned int b)            // Беззнаковые.
{   // Вспомогательная функция нахождения наименьшего общего кратного, если требуется, без вывода.
    unsigned int g = gcd(a, b);                             // Используем функцию НОД.
    if (g == 0) {
        printf("Warning, greatest common divider can't be zero.\n");
        return 0;                                           // Ноль возвращаеся только в случае ошибки.
    }
    return (a * b / g);
}

int normalize(struct rational* r)
{   // Нормализация числа, с максимальным сокращением числителя и знаменателя. Возврат успешности исполнения.
    if (!is_correct(r)) {                                   // Проверка на допустимость.
        printf("Rational for normalize is incorrect, at (%p).\n", r);
        return 0;
    }   // Далее знаменатель не может быть равным нулю.
    int num = *get_numerator(r), sign = (num >= 0) ? +1 : -1;
    unsigned int den = *get_denominator(r), n = num * sign; // Параметры дроби получаем методами.
    unsigned int g = gcd(num, den);
    printf("Normalize rational %d/%u, GCD is %u, ", num, den, g);
    if (g > 1) {                                            // Если делитель больше единицы, иначе делить параметры не имеет смысла.
        num = (int)(n / g) * sign;
        den /= g;                                           // Всегда будет единица или более.
        set_numerator(r, &num);
        set_denominator(r, &den);
        printf("normalized %d/%u.\n", num, den);
        return 1;                                           // Нормализация произошла минимум на 2.
    } else {
        printf("nothing to normalize, gcd is 1 or 0.\n");
        return 0;
    }
}

void negative(struct rational* r)
{   // Преобразование рационального числа в противоположное по знаку.
    if (!is_correct(r)) {                                   // Проверка на допустимость.
        printf("Rational is incorrect at (%p), can't negative.\n", r);
        return;
    }
    int num = *get_numerator(r), sign = (num >= 0) ? +1 : -1;
    unsigned int den = *get_denominator(r), n = num * sign;
    if (is_int_overflow(n, sign * -1))                      // Проверим на случай модуля минимального числа, т.к. дополнительный код не сработает.
        printf("Warning, negative number has overflow integer type.\n");
    printf("Set rational at %p, %d/%u to negative ", r, num, den);
    num *= -1;                                              // Умножаем как есть, без дополнительных преобразований.
    set_numerator(r, &num);                                 // Вывод результата в одну строку.
    printf("%d/%u.\n", *get_numerator(r), *get_denominator(r));
}

void inverse(struct rational* r)
{   // Преобразование рационального числа в обратное, т.е. меняется местами числитель и знаментель.
    if (!is_correct(r) || *get_numerator(r) == 0) {         // Проверка, немного опасный код исходя из порядка действия.
        printf("Rational is incorrect or numerator is zero.\n");
        return;
    }
    int num = *get_numerator(r);
    int sign = (num >= 0) ? 1 : -1;                         // Знак числителя после будет перенесен на знаменатель.
    unsigned int den = *get_denominator(r);
    if (is_int_overflow(den, sign))
        printf("Warning overflow, absolute denominator is out of integer range.\n");
    int inv_num = (int)den * sign;                          // Используем стандартное преобразование без обработки.
    set_numerator(r, &inv_num);
    unsigned int inv_den = num * sign;                      // Для знаменателя, обычное умножение.
    set_denominator(r, &inv_den);
    printf("Inverse rational object at %p, %d/%u to %d/%u.\n", r, num, den, inv_num, inv_den);
}

int from_double(struct rational* r, double n, unsigned int max_guess)
{   // Вещественное число подбирается как ближайшее к дроби. Через перебор или быстрей через шаг.
    // Максимальное предположение по разрядам, например 10 или 100 - максимальное значение числителя и знаменателя.
    // Возвращает 1, если преобразование прошло успешно, иначе 0.
    if (r == NULL || max_guess == 0)  {
        printf("Error from double to rational, address is NULL or max guess is 0.\n");
        return 0;
    }
    printf("Simple guess %.5f as closest rational, parameters limit is %d", n, max_guess);
    int sign, num = max_guess;
    unsigned int den = max_guess;
    if (n < 0) {                                            // Сразу определяем знак и оставляем абсолютное значение.
        sign = -1;
        n *= -1.0;
    } else
        sign = +1;
    double offset = n;                                      // Присвоение можно использовать или применить копирование памяти.
    for (unsigned int i = 0, j; i < max_guess; ++i)
        for (j = 1; j < max_guess; ++j) {
            double guess = n - (double)(i) / (double)(j);   // Предположение, на перебор.
            if (guess < 0)                                  // Берем абсолютное значение.
                guess *= -1.0;
            if (guess < offset) {                           // Сравнение с предыдущим смещением.
                offset = guess;
                num = i;
                den = j;
            }
        }
    if (offset != n) {                                      // Опасное сравнение, сработает только если не произошло ни одного вычисления и
        num *= sign;                                        // копирование было точным.
        set_numerator(r, &num);                             // Знаменатель от единицы.
        set_denominator(r, &den);
        printf(", closest %d/%u.\n", num, den);
        return 1;
    } else {
        num = den = 1;                                      // Или можно использовать функцию создания дроби.
        set_numerator(r, &num);
        set_denominator(r, &den);
        printf(", parameters not founded, set to default 1/1.\n");
        return 0;
    }
}

int from_string(struct rational* r, char src[])
{   // Преобразование исходной текстовой строки по формату, в объект.
    // Возвращает, если преобразование прошло успешно, иначе 0.
    // Функция должна быть максимально устойчива, т.е. даже строка вида "abcde--+++2asd4 / bac1  def2",
    //должна быть преобразована по возможности в "-24.12". Только если совсем невозможно найти параметры, то вернуть 0.
    // Для формирования дроби должен быть и числитель и знаменатель, иначе дробь по адресу не меняется.
    // Знак дроби искать только один, несколько фактически создают пустое разделеение числителя и знаменателя.
    if (r == NULL || src == NULL) {                         // Простая проверка на адреса, т.к. преобразование должно быть корректным.
        printf("Address of rational number or source string is NULL.\n");
        return 0;
    }
    const int base = 10, pars = 2;                          // Основание системы счисления и количество параметров в строке.
    const char* p_name[] = { "Numerator", "Denominator" };  // Названия параметров для отладки.
    int num = 0, sign = 1, is_any = 0, i = 0, j, k;         // Числитель, знак, флаги наличия числителя или знаменаля и индексы в строке.
    unsigned int l, n, den = 0, mult;                       // Счетчик, само число, знаменатель, множитель по основанию системы счисления.
    while ((src[i] != '+' && src[i] != '-') && (src[i] < '0' || src[i] > '9')
           && (src[i] != '\0') && (i < TEXT_MAX))           // Пропускаем все первые символы, которые не явлюятся знаком или числом.
        ++i;
    if (src[i] == '-') {                                    // Первым символом может быть только знак у числителя.
        sign = -1;                                          // Все знаки после первой цифры числителя считаются как не значимый символ.
        ++i;
    }
    if (src[i] == '+') {                                    // Знак может быть и плюсом, но по-умолчанию, знак всё равно 1.
        sign = +1;
        ++i;
    }
    printf("Trying to convert from string '%s' to rational, format 'numerator/denominator'.\n", src);
    printf("Sign is %d, starting index %u.", sign, i);
    for (l = 0, j = i; l < pars && src[i] != '\0' && j < TEXT_MAX; ++l, i = j) {
        printf("\n%s steps: ", p_name[l]);                  // Главный цикл, для обоих параметров,ограничение TEXT_MAX - дополнительно.
        while (src[j] != '/' && src[j] != '\0' && j < TEXT_MAX)
            ++j;                                            // Поиск разделителя параметра или окончания строки.
        // printf("j=%d.\n", j);                            // Дополнительная отладка, если требуется, то убрать комментарий.
        k = j; mult = 1; n = 0;
        while (--k >= i) {                                  // Преобразования строки по индексам в исходнике, в число.
            if (src[k] >= '0' && src[k] <= '9') {           // Остальные символы игнорируем.
                // printf("C='%c' ", src[k]);
                n += ((src[k] - '0') * mult);               // Цифру из строки умножаем на множитель порядка, относительно системы счисления.
                mult *= base;
                printf("%u ", n);                           // Вывод поэтапно, числа, которое получается.
                is_any |= 0x01 << l;                        // Поднимаем флаг числителя/знаменателя.
            } else
                printf("'%c' ", src[k]);                    // Иначе просто выводим символ.
        }
        if (!l) {                                           // Если числитель.
            if (is_int_overflow(n, sign))                   // Проверка на переполнение абсолютного значения числителя.
                printf("\nWarning overflow, numerator is more than integer max or less than intger min.");
            num = (int)n * sign;                            // Стандартное преобразование, как есть.
        } else
            den = n;
        if (src[j] == '/')                                  // Количество можно один или несколько по вкусу, но по логике 1 символ "/".
            ++j;
    }
    printf("\n");
    if (den != 0 && is_any == 0x03) {                       // Если знаменатель не равен 0 и числитель и знаменатель были обработаны.
        set_numerator(r, &num);
        set_denominator(r, &den);
        return 1;
    } else {                                                // Иначе дробь не изменяем даже частично.
        printf("Error, denominator is %u or rational incomplete. Nothing to set.\n", den);
        return 0;
    }
}

void inc(struct rational* dst)
{   // Увеличение числителя объекта на единицу.
    if (!is_correct(dst)) {                                 // Проверка на допустимость.
        printf("Error in destination %p, can't increase rational numerator.\n", dst);
        return;
    }
    int num = *get_numerator(dst);
    if (num == INT_MAX)
        printf("Warning, numerator has maximum value, increasing cause overflow to integer minimum.\n");
    printf("Numerator berfore increase %d, ", num);
    num++;                                                  // Обычное увеличение с контролем результата.
    set_numerator(dst, &num);
    printf("after increase %d.\n", *get_numerator(dst));
}

void dec(struct rational* dst)
{   // Уменьшение числителя объекта на единицу.
    if (!is_correct(dst)) {                                 // Проверка на допустимость.
        printf("Error in destination, can't decrease rational numerator.\n");
        return;
    }
    int num = *get_numerator(dst);
    if (num == INT_MIN)
        printf("Warning, numerator has minimum value, decreasing cause overflow to integer maximum.\n");
    printf("Numerator berfore decrease %d, ", num);
    num--;                                                  // Обычное уменьшение с контролем результа.
    set_numerator(dst, &num);
    printf("after decrease %d.\n", *get_numerator(dst));
}

int to_common_den(struct rational* left, struct rational* right)
{   // Приведение пары дробей к общему знаменателю, значения объектов изменяются.
    // Возвращает НОК или 0 в случае ошибки.
    if (!is_correct(left) || !is_correct(right)) {          // Проверка на допустимость.
        printf("Error finding common denominator in left %p or right %p.\n", left, right);
        return 0;
    }
    int nl = *get_numerator(left), nr = *get_numerator(right);
    int sign_l = (nl < 0) ? -1 : 1, sign_r = (nr < 0) ? -1 : 1;
    unsigned int unl = nl * sign_l, unr = nr * sign_r;      // Переводим числители в беззнаковый формат.
    unsigned int dl = *get_denominator(left), dr = *get_denominator(right);
    unsigned int l = lcm(dl, dr);                           // Наименьшее общее кратное.
    printf("Converting pair to common denominator: (%d/%u) : (%d/%u). LCM: %u.\n", nl, dl, nr, dr, l);
    if (is_int_overflow(unl, sign_l) || is_int_overflow(unr, sign_r))
        printf("Warning, left or right numerator is more than integer max: left %u, right %u.\n", unl, unr);
    unl = unl * (l / dl);                                   // Числитель слева умножаем пропорционально.
    nl = unl * sign_l;                                      // Знаменатель, заменяем на НОК.
    set_numerator(left, &nl);
    set_denominator(left, &l);
    unr = unr * (l / dr);                                   // Числитель справа умножаем пропорционально.
    nr = unr * sign_r;
    set_numerator(right, &nr);                              // Установка через функции, или можно создать отдельно.
    set_denominator(right, &l);
    return l;                                               // Успешно возвращаем НОК.
}

enum op_type { op_nop, op_add, op_sub, op_mul, op_div };    // Дополнительная функция, не обязательно, можно напрямую проверить.

int is_op_overflow(struct rational* left, struct rational* right, enum op_type type)
{   // Проверка на переполнение с учетом типа арифметического действия. Функция для удобства. Возвращает успешность 1 иначе 0.
    if (!is_correct(left) || !is_correct(right) || type < op_nop || type > op_div) {
        printf("Error in operation overflow, type index %u.\n", type);
        return 0;
    }                                                       // По умолчанию считаем что дроби корректны до операции.
    int nl = *get_numerator(left), nr = *get_numerator(right), rs;
    int sign_l = (nl >= 0) ? +1: -1, sign_r = (nr >= 0) ? + 1: -1, sign_overflow = 0;
    unsigned int unl = nl * sign_l, unr = nr * sign_r, ru;  // Проверка на переполнениен имеет смысл при различных знаках.
    switch (type) {
    case op_nop:
        printf("Warning, empty operator rational, nothing to check.\n");
        return 0;
    case op_add:                                            // Сложение и вычитание одновременно.
    case op_sub:
        if (sign_l == sign_r)                               // Если знаки различны, то нужно предварительно проверить результат.
            ru = unl + unr;
        else
            rs = nl + nr;                                   // Сложение с разными знаками, или вычитание.
        break;
    case op_mul:                                            // Умножение и деление вместе.
    case op_div:
        if (sign_l == sign_r)                               // Умножение с одинаковыми знаками, дает всегда неотрицательное.
            ru = unl * unr;
        else
            rs = nl * nr;                                   // Если знак требуется сохранить.
        break;
    default:
        printf("Operataion check type is incorrect.\n");    // Если каким-то образом не попали в тип.
        return 0;
    }
    if (sign_l == sign_r)                                   // Простая проверка на переполнение с одинковыми знаками.
        sign_overflow = sign_l;
    else {                                                  // Преобразование работает корректно, даже если умножается минимальное.
        sign_overflow = (rs >= 0) ? +1 : -1;                // отрицательное число и оно больше знакового целого. Строка ниже для 0 + INT_MIN.
        ru = rs * sign_overflow;                            // При умножении возможен результат INT_MIN * -1 > INT_MAX.
        // printf("\nAdd temporary result %u, from signed %d, and "
        //       "INT_MIN %d to INT_MAX %d, sign %d.\n", ru, rs, INT_MIN, INT_MAX, sign_overflow);
    }
    return is_int_overflow(ru, sign_overflow);
}

void add(struct rational* dst, struct rational* src)
{   // Сложение объектов с сохранением результата, чтобы не вводить 3-ий параметр.
    if (!is_correct(src) || !is_correct(dst) || src == dst) {
        printf("Error add rationals source %p and destination %p or self object assignment.\n", src, dst);
        return;                                             // Проверка на допустимость, сложение само с собой недопустимо.
    }
    int nl = *get_numerator(dst), nr = *get_numerator(src); // Числители и знаменатели только для вывода.
    unsigned int dl = *get_denominator(dst), dr = *get_denominator(src);
    printf("Add %d/%u + %d/%u.\n", nl, dl, nr, dr);
    struct rational src_copy;                               // Создаем копию, для приведения к общему делителю.
    copy(&src_copy, src);
    to_common_den(dst, &src_copy);                          // Приводим к общему знаменателю.
    nl = *get_numerator(dst); nr = *get_numerator(&src_copy);
    if (is_op_overflow(dst, &src_copy, op_add))
        printf("Warning, adding cause integer overflow in result.\n");
    int s = nl + nr;                                        // Сложение всё равно исполняется как есть.
    set_numerator(dst, &s);                                 // Устанавливаем только числитель, знаменатель уже установлен.
    printf("Result of add: %d/%u.\n", *get_numerator(dst), *get_denominator(dst));
}

void sub(struct rational* dst, struct rational* src)
{   // Вычитание рациональных чисел через сложение с негативным правостороннем значением.
    if (!is_correct(src) || !is_correct(dst) || src == dst) {
        printf("Error sub rationals in source (%p) or destination (%p).\n", src, dst);
        return;                                             // Проверка на допустимость и самоприсваивание.
    }
    int nl = *get_numerator(dst), nr = *get_numerator(src); // Числители и знаменатели для вывода.
    unsigned int dl = *get_denominator(dst), dr = *get_denominator(src);
    printf("Sub %d/%u - %d/%u using add function.\n", nl, dl, nr, dr);
    struct rational src_copy;                               // Создаем копию, для приведения к общему делителю.
    copy(&src_copy, src);
    negative(&src_copy);                                    // Копия становится дробью с обратным знаком.
    add(dst, &src_copy);                                    // Вызываем функцию сложения с дробью с обратным знаком.
    printf("Sub result: %d/%u.\n", *get_numerator(dst), *get_denominator(dst));
}

void multiply(struct rational* dst, struct rational* src)
{   // Умножение рациональных чисел с сохранением результата в назначение.
    if (!is_correct(src) || !is_correct(dst) || src == dst) {
        printf("Error multiply rationals source %p and destination %p or object self assgnment.\n", src, dst);
        return;                                             // Проверка на допустимость и самоприсваивание.
    }
    int nl = *get_numerator(dst), nr = *get_numerator(src); // Только для вывода.
    unsigned int dl = *get_denominator(dst), dr = *get_denominator(src);
    printf("Multiply %d/%u * %d/%u = (%d * %d) / (%d * %d).\n",
           nl, dl, nr, dr, nl, nr, dl, dr);
    if (is_op_overflow(dst, src, op_mul))                   // Проверка на переполнение.
        printf("Warning, multiply cause integer overflow in result.\n");
    nl *= nr; dl *= dr;                                     // Умножение происходит как есть, ограничения были проверены выше.
    set_numerator(dst, &nl);                                // Используем функции присваивания.
    set_denominator(dst, &dl);
    printf("Result of multiply: %d/%u.\n", nl, dl);
}

void divide(struct rational* dst, struct rational* src)
{   // Деление рациональных чисел путём умножения с обратной дробью.
    if (!is_correct(src) || !is_correct(dst) || src == dst) {
        printf("Error divide, in source, destination or right numerator is 0.\n");
        return;                                             // Проверка на допустимость и самоприсваивание.
    }
    int nl = *get_numerator(dst), nr = *get_numerator(src); // Только для вывода.
    unsigned int dl = *get_denominator(dst), dr = *get_denominator(src);
    printf("Divide %d/%u / %d/%u, using inverse and multiply function.\n", nl, dl, nr, dr);
    struct rational src_copy;                               // Создаем копию для обратной дроби.
    copy(&src_copy, src);
    inverse(&src_copy);                                     // Меняем числитель и знаменатель местами.
    multiply(dst, &src_copy);                               // Вызываем функцию умножения и там же проверка.
    printf("Result of divide: %d/%u.\n", *get_numerator(dst), *get_denominator(dst));
}

void modulus(struct rational* dst, struct rational* src)
{   // Остаток от деления по правилам математике остается в объекте назначения.
    // Можно использовать все функции предыдущие или реализовать отдельно.
    if (src == dst || !is_correct(src) || !is_correct(dst) || *get_numerator(src) == 0) {
        printf("Error modulus source %p destination %p. Right numerator is 0 or self assignmet.\n", src, dst);
        return;                                             // Кроме обычных, числитель делителя не может быть равен нулю.
    }
    int nl = *get_numerator(dst), nr = *get_numerator(src); // Для вывода параметы дробей.
    unsigned int dl = *get_denominator(dst), dr = *get_denominator(src);
    printf("Modulus %d/%u mod %d/%u, using div, mul and sub.\n", nl, dl, nr, dr);
    struct rational src_copy, dst_copy, sub_int_div;        // Используем долгий способ для тестирования.
    copy(&src_copy, src);
    copy(&dst_copy, dst);
    divide(&dst_copy, &src_copy);                           // Делим дроби нацело и получаем частное по делению.
    nl = *get_numerator(&dst_copy);
    dl = *get_denominator(&dst_copy);
    int int_div = nl / dl;                                  // Определяем сколько целых дробей поместилось при делении.
    printf("Integer divider for rational is %d.\n", int_div);
    create(&sub_int_div, int_div, 1);
    multiply(&sub_int_div, &src_copy);                      // Умножаем на целое число дробей и получаем вычитаемое.
    sub(dst, &sub_int_div);                                 // Вычитаем и остаток от деления и будет результатом функции.
    printf("Modulus result: %d/%u.\n", *get_numerator(dst), *get_denominator(dst));
}

void power(struct rational* dst, int pow)
{   // Возведение в степень, по правилам математики, можно через простое умножение.
    // Также не забыть про отрицательную степень и условный нуль.
    if ((!is_correct(dst)) || (pow < 0 && *get_numerator(dst))) {
        printf("Error power, destination %p or numerator is zero with negative parameter.\n", dst);
        return;                                             // Проверяем на допустимость, немного опасно при попытке чтения.
    }
    int nl = *get_numerator(dst);                           // Выводим все параметры функции.
    unsigned int dl = *get_denominator(dst);
    printf("Rational %d/%u to power %d, using multiply and reverse.\n", nl, dl, pow);
    if (pow == 0) {                                         // Если степень равно нулю, то возвращаем дробь 1/1.
        nl = 1; dl = 1;
        set_numerator(dst, &nl);
        set_denominator(dst, &dl);
        printf("Power is zero, so set destination rational to %d/%u.\n", nl, dl);
        return;
    }
    if (pow < 0) {                                          // Если степень отрицательная, то делаем дробь обратной.
        printf("Power is negative, so calling inverse to rational and make parameter absolute.\n");
        inverse(dst);                                       // Дополнительной проверки не требуется.
        pow = abs(pow);
    }
    struct rational dst_copy;
    copy(&dst_copy, dst);
    while (pow--) {                                         // Умножаем до упора. Или применить любой другой алгоритм.
        printf("\nMultiply counter for power: %d.\n", pow);
        multiply(dst, &dst_copy);
    }
    printf("Result of power: %d/%u.\n", *get_numerator(dst), *get_denominator(dst));
}

int is_equal(struct rational* left, struct rational* right)
{   // Проверка, если дроби равны. Возвращаем 1 или 0 в зависимости от результата.
    if (!is_correct(left) || !is_correct(right)) {          // Проверяем на допустимость и возвращаем -1 как признак ошибки.
        printf("Error is equal, left %p or right %p.\n", left, right);
        return -1;
    }
    int nl = *get_numerator(left), nr = *get_numerator(right);
    int sign_l = (nl >= 0) ? +1 : -1, sign_r = (nr >= 0) ? +1 : -1;
    unsigned int dl = *get_denominator(left), dr = *get_denominator(right);
    printf("Check if (%d/%u == %d/%u).\n", nl, dl, nr, dr); // Выводим изначальные числители и знаменатели слева и справа.
    if (sign_l != sign_r) {                                 // Если знаки у дробей отличаются, то вычислять далее нет смысла.
        printf("Signs of left and right numerators are different, rationals not equal.\n");
        return 0;
    }
    struct rational l_copy, r_copy;                         // Создаем копии объектов и приводим к общему знаменателю.
    copy(&l_copy, left);
    copy(&r_copy, right);
    to_common_den(&l_copy, &r_copy);                        // Приводим к общему знаменателю.
    nl = *get_numerator(&l_copy); nr = *get_numerator(&r_copy);
    printf("With common denominator (%d/%u == %d/%u) is ",
           nl, *get_denominator(&l_copy), nr, *get_denominator(&r_copy));
    if (nl == nr) {
        printf("equal.\n");                                 // Сравнение идет только по числителю.
        return 1;
    } else {
        printf("not equal.\n");                             // Если не равно, то возвращаем 0.
        return 0;
    }
}

int is_more(struct rational* left, struct rational* right)
{   // Проверка, если первое число больше второго. Возвращаем 1 или 0, в зависимости от результата.
    if (!is_correct(left) || !is_correct(right)) {          // Проверяем на допустимость и возвращаем -1 как признак ошибки.
        printf("Error is more, in left %p or right %p.\n", left, right);
        return -1;
    }
    int nl = *get_numerator(left), nr = *get_numerator(right);
    int sign_l = (nl >= 0) ? +1 : -1, sign_r = (nr >= 0) ? +1 : -1;
    unsigned int dl = *get_denominator(left), dr = *get_denominator(right);
    printf("Check if (%d/%u > %d/%u).\n", nl, dl, nr, dr);  // Выводим изначальные числители и знаменатли слева и справа.
    if (sign_l > sign_r) {                                  // Быстрое сравнение знаков числителей.
        printf("Sign of left is positive and right negative, left rational is more.\n");
        return 1;
    } else if (sign_l < sign_r) {
        printf("Sign of left is less than right, left rational is less.\n");
        return 0;
    }
    struct rational l_copy, r_copy;                         // Создаем копии и приводим к общему знаменателю.
    copy(&l_copy, left);
    copy(&r_copy, right);
    to_common_den(&l_copy, &r_copy);
    nl = *get_numerator(&l_copy); nr = *get_numerator(&r_copy);
    printf("With common denominator (%d/%u > %d/%u) is ",
           nl, *get_denominator(&l_copy), nr, *get_denominator(&r_copy));
    if (nl > nr) {                                          // Левый числитель больше правого.
        printf("more.\n");
        return 1;
    } else {
        printf("not more.\n");
        return 0;
    }
}

int is_less(struct rational* left, struct rational* right)
{   // Проверка, если первое число меньше второго. Возвращаем 1 или 0, в зависимости от результата.
    if (!is_correct(left) || !is_correct(right)) {          // Проверяем на допустимость и возвращаем -1 как признак ошибки.
        printf("Error is less, in left %p or right %p.\n", left, right);
        return -1;
    }
    int nl = *get_numerator(left), nr = *get_numerator(right);
    int sign_l = (nl >= 0) ? +1 : -1, sign_r = (nr >= 0) ? +1 : -1;
    unsigned int dl = *get_denominator(left), dr = *get_denominator(right);
    printf("Check if (%d/%u < %d/%u).\n", nl, dl, nr, dr);  // Выводим изначальные значения.
    if (sign_l < sign_r) {                                  // Быстрое сравнение знаков числителей.
        printf("Sign of left is negative and right positive, left rational is less.\n");
        return 1;
    } else if (sign_l > sign_r) {
        printf("Sign of left is positive and right negative, left rational is more.\n");
        return 0;
    }
    struct rational l_copy, r_copy;                         // Создаем копии и приводим к общему знаменателю.
    copy(&l_copy, left);
    copy(&r_copy, right);
    to_common_den(&l_copy, &r_copy);
    nl = *get_numerator(&l_copy); nr = *get_numerator(&r_copy);
    printf("With common denominator (%d/%u < %d/%u) is ",
           nl, *get_denominator(&l_copy), nr, *get_denominator(&r_copy));
    if (nl < nr) {                                          // Если числитель слева меньше числителя справа.
        printf("less.\n");
        return 1;
    } else {
        printf("not less.\n");                              // Иначе нет.
        return 0;
    }
}

int compare(struct rational* left, struct rational* right,
            int(*cmp)(struct rational*, struct rational*))
{   // Дополнительная функция сравнения, на вход дополнительно адрес функции для сравнения.
    if (!is_correct(left) || !is_correct(right) || cmp == NULL) {
        printf("Error in source or destination, can't multiply rational numbers.\n");
        return -1;
    }       // Лучше было-бы реализовать полностью как одно сравнение, а в функцию сравнения вынести минимум.
    return cmp(left, right);                                // Вызываем функцию сравнения с параметрами, по адресу.
}

double to_double(struct rational* src)
{   // Простое преобразование из рационального в действительное, точность без ограничения.
    printf("Converting rational as double, size %u bytes.\n", sizeof(double));
    if (!is_correct(src)) {                                 // Простая проверка на корректность.
        printf("Error converting to double type in source %p.\n", src);
        return 0.0;
    }
    double num = (double)*get_numerator(src);               // Используем стандартное преобразование типов.
    double den = (double)*get_denominator(src);
    return num / den;
}

int to_string(struct rational* src, char* dst)
{   // Преобразование в строку, аналогичное функции print. На выходе - количество фактических символов или 0.
    // Контроль максимульно допустимого размера буффера через определение TEXT_MAX.
    // Желательно не применять стандартную библотеку.
    if (!is_correct(src) || dst == NULL) {                  // Проверка на корректность источника.
        printf("Rational to string incorrect or destination string address is NULL.\n");
        return 0;
    }
    int num = *get_numerator(src);
    const unsigned int base = 10, pars = 2;                 // Основание системы счисления и количество параметров в дроби.
    unsigned int i = 0, j, den = *get_denominator(src);
    unsigned int mult, dc, mc;                              // Множитель, копии данных.
    if (num < 0) {                                          // Первым символом всегда должен быть знак, если число меньше нуля.
        dst[i++] = '-';
        num *= -1;                                          // Далее нас интересует только абсолютное значение.
    }
    for (j = 0; j < pars; ++j) {                            // Преобразовываем в числитель и знаменатель.
        if (j == 0)
            dc = num;
        else
            dc = den;                                       // Копируем временно данные в зависимости от числителя или знаменателя.
        mult = 1; mc = dc;                                  // Вычисляем максимальный порядок числа.
        while ((mc /= base))
            mult *= base;
        // printf("%d dc = %d\n", mult, dc);                // Для отладки, дополнительно раскоментировать.
        while (mult) {                                      // Разбираем число и заполняем строку.
            dst[i++] = (dc / mult) % base + '0';
            // printf("'%c' ", string[i - 1]);
            mult /= base;                                   // Уменьшаем множитель, в соответствием с разрядом.
        }
        if (j == 0)
            dst[i++] = '/';                                 // Если был числитель, то устанавливаем знак дроби.
        else
            dst[i] = '\0';                                  // Если прошел знаменатель, то уже признак конца строки.
    }
    return i;                                               // Возвращаем актуальную длину.
}

int input(struct rational* r, char* dst)
{   // Ввод рационального числа с клавиатуры. Все лишние символы игнорируются.
    if (r == NULL || dst == NULL) {                         // Проверка на допустимость адресов.
        printf("Error input, addresses of rational or string is NULL.\n");
        return 0;
    }
    const unsigned int pars = 2;                            // Количество параметров в дроби.
    unsigned int i = 0, j = 0, c;
    printf("Enter rational as 'num/den' format: ");
    while ((c = getchar()) != '\n' && j < pars) {           // Вводим по символу.
        if (i == 0 && (c == '-' || c == '+'))               // Знак только в самом начале.
            dst[i++] = c;
        if ((c >= '0' && c <= '9') || c == '/')
            dst[i++] = c;
        if (c == '/')                                       // Следующий параметр.
            j++;
    }
    dst[i] = '\0';
    return from_string(r, dst);                             // Вызываем преобразование из строки.
}

int main()
{
    printf("Laboratory 3. Rational numbers and operators.\n\n");
    printf("Integer size is %u bytes and integer minimum %d and maximum %d.\n", sizeof(int), INT_MIN, INT_MAX);
    printf("Object of 'Rational' size is %u and data:\n", sizeof(struct rational));
    struct rational r1, r2, r3;                             // Общий размер объекта и тестовые объекты.
    struct rational* ptr1 = &r1, *ptr2 = &r2, *ptr3 = &r3;  // Адреса объектов для перемещения и тестов.
    printf("Offset:\tSize:\tComment:\n");                   // Смещение данных в базовом объекте и их размеры, таблица.
    printf("+%u\t%u\tNumerator for rational with sign.\n", (void*)&r1.numerator - (void*)&r1, sizeof(r1.numerator));
    printf("+%u\t%u\tDenominator for rational unsigned.\n", (void*)&r1.denominator - (void*)&r1, sizeof(r1.denominator));
    // Вывести таблицу адресов для функций: is_equal, is_more, is_less.
    printf("\nAddress table, of compare functions:\n");
    printf("Name:\t\tAddr:\n");
    printf("Is equal\t%p\n", &is_equal);
    printf("Is more\t\t%p\n", &is_more);
    printf("Is less\t\t%p\n", &is_less);                    // Инициализируем значение.
    // Все тесты включают и минмум один неверный вызов, для отслеживания ошибки по входным данным.
    // 1. Создание объектов, их копирование и перемещение.
    int r;                                                  // Вспомогательные переменные.
    unsigned int ur;
    char txt[TEXT_MAX];
    printf("\nCreate objects include one incorrect, copy and move to other object.\n");
    ptr3 = NULL;
    create(ptr1, 1, 3);
    create(ptr2, 0, 0);
    create(ptr3, 2, 3);
    ptr3 = &r3;
    copy(ptr3, ptr1);
    move(&ptr2, &ptr1);
    printf("After moving rational from (%p) to (%p), using print function: ", ptr1, ptr2);
    print(ptr2, 1);
    // 2. Вызываем методы чтения/записи и проверки на корректность.
    printf("\nGetting and setting parameters for rational and check is correct.\n");
    printf("Set rational to 1/2, using functions set/get and one incorrect.\n");
    r = 1; ur = 2;
    set_numerator(ptr2, &r);
    set_denominator(ptr2, NULL);
    set_denominator(ptr2, &ur);
    printf("Reading result of rational: %d/%u, ", *get_numerator(ptr2), *get_denominator(ptr2));
    printf("is correct rational %d.\n", is_correct(ptr1));
    // 3. Функции конвертации и нормализации рационального числа.
    printf("\nConverting functions rationals and normalize.\n");
    r = from_double(ptr3, 0.33, 10);
    printf("Converting from double to rational, result is %d: ", r);
    print(ptr3, 1);
    r = from_double(ptr3, 0.0, 10);
    r = from_string(ptr3, "abc de---+++1_gh 2  / abc_def 4__8gh");
    printf("Converting from string result %d: ", r);
    print(ptr3, 1);
    r = from_string(ptr3, "-2147483648/2");
    r = normalize(ptr3);
    printf("Normalize rational, result %d: ", r);
    print(ptr3, 1);
    r = normalize(NULL);
    r = to_string(ptr3, txt);
    printf("Convert to string, length %d: '%s'.\n", r, txt);
    r = to_string(NULL, txt);
    // 4. Арифметические операции все сразу, один крупный вариант.
    printf("\nAll arithmetic operations and inc/dec.\n");
    printf("\nCheck overflow with maximum %d and %d minimum integers.\n", INT_MIN, INT_MAX);
    int num_pairs_add[] = { 0, INT_MAX, INT_MIN, -1, INT_MIN + 1, INT_MAX, INT_MAX, 1 };
    for (unsigned int i = 0, d = 1; i < sizeof(num_pairs_add) / sizeof(int) / 2; ++i) {
        set_numerator(ptr2, &num_pairs_add[i * 2]);
        set_denominator(ptr2, &d);
        set_numerator(ptr3, &num_pairs_add[i * 2 + 1]);
        set_denominator(ptr2, &ur);
        add(ptr2, ptr3);
        printf("\n");
    }
    printf("Check other arithmetic functions, using 1/2 and 1/3 to check.\n");
    printf("\nDecrease:\n");
    dec(ptr1);
    printf("\nIncrease:\n");
    inc(ptr1);
    printf("\n");
    r = from_double(ptr1, 0.5, 10);
    ptr2 = &r2;
    r = from_double(ptr2, 0.33, 10);
    printf("\nSubtraction:\n");
    sub(ptr1, ptr2);
    create(ptr1, INT_MAX, 1); create(ptr3, -1, 1);
    printf("\nMultiply without overflow:\n");
    multiply(ptr1, ptr3);
    create(ptr1, INT_MIN, 1);
    printf("\nMultiply without overflow:\n");
    multiply(ptr1, ptr3);
    printf("\nDivide correct:\n");
    create(ptr1, 5, 6); create(ptr2, 1, 3);
    divide(ptr1, ptr2);
    create(ptr3, 5, 6);
    printf("\nModulus:\n");
    modulus(ptr3, ptr2);
    printf("\nTo power:\n");
    power(ptr2, 2);
    // 5. Функции сравнения и вызова по адресу функции.
    printf("\nCompare functions.\n");
    is_equal(ptr1, ptr2);
    is_more(ptr1, ptr2);
    is_less(ptr1, ptr2);
    printf("\nCalling functions using compare.\n");
    int(*cmp_ptr)(struct rational*, struct rational*) = &is_equal;
    compare(ptr1, ptr2, cmp_ptr);
    // 6. Тестирование ввода исполняем последним, его удобней закоментировать.
    printf("\nTrying to input rational, all incorrect characters ignored.\n");
    r = input(ptr3, txt);
    printf("Result of input %d, text '%s' and rational ", r, txt);
    print(ptr3, 1);
    return 0;
}
