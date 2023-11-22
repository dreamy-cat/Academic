#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//  Лабораторная. Элементарная интерполяция функции методом кубических сплайнов.
//  Функция должна быть опеределена и непрерывна на каждом итервале, как и её производные
// первого и второго порядка, т.е. не выше 3-ей. Т.е. условия сопряжения при шаге (I) и (I + 1)
// значения производных должны быть равны(пределы справа и слева).
//  Условная сетка с шагом считается равномерной.

//  Кубическим сплайном на сетке Y(x), x = [0..N], отрезка [A, B] называют функцию S(x),
// дважды непрерывно-дифференцируемую на отрезке и представляющую собой полином степени
// не выше трех, на каждом его участке.

// Дополнительные функции: нахождение нуля функции на интервале и значение интеграла (2 способа).

// Максимальное количество элементов в полиноме.
#define POLYNOM_MAX 0x100
//  Ширирна и высота виртуального экрана для консольного рисования графиков. Если будут изменения, то заглянуть в 'print_screen'.
#define SCR_WIDTH 0x80
#define SCR_HEIGHT 0x20
//  Максимальный размер буффера для текстового сообщения или для строчных преобразований.
#define TEXT_MAX 0x100

struct element {        // Структура элемента полинома одной переменной.
    int constant;
    unsigned int exponent;
};

enum int_method { int_square, int_trapezoid, int_simpson, int_not };
enum res_method { res_full, res_bisection, res_not };

// Глобальные константы для программы.
static const float float_eps = 0.01;
static const int poly_left = -SCR_WIDTH / 2, poly_right = SCR_WIDTH / 2 - 1;
static const int poly_pow_max = 3;
// static const int rnd_const_max = 10, rnd_exp_max = 4;
static const unsigned int pencil_colors = 5;                    // Всего условных цветов или градаций черного.
static const char pencil[] = { 32, 176, 177, 178, 219 };        // Коды таблицы ASCII для рисования в буффере.
static const double scale = 100.0;

// Глобальные данные, используют все функции, чтобы не передавать значения в функции каждый раз.
static char screen[SCR_HEIGHT][SCR_WIDTH];                      // Буффер виртуального текстового экрана.
static unsigned int poly_size = 5;                              // Параметры и исходный полином.
static struct element polynomial[POLYNOM_MAX] = {   { .constant = +3, .exponent = 3, },
                                                    { .constant = +5, .exponent = 1, },
                                                    { .constant = -7, .exponent = 1,},
                                                    { .constant = -1, .exponent = 2, },
                                                    { .constant = +1, .exponent = 0, }   };
static char* res_names[] = { "full data run", "bisection", "not a method" };
static char* int_names[] = { "square", "trapeziod", "Simpson's" };
double values[SCR_WIDTH];   // data

// Основной код программы.

void clear_screen(char c, int is_debug)
{   // Функция очистки буфера виртуального экрана заданным символом. Циклами или через адрес по вкусу.
    // Если флаг отладки, то заполнить буфер всеми "цветами", кроме 0-го. Можно по классике, прямоугольниками.
    if (is_debug)
        for (unsigned int i = 0, k = 1; i < SCR_HEIGHT; ++i)
            for (unsigned int j = 0; j < SCR_WIDTH; ++j)
                screen[i][j] = pencil[k + j / ((SCR_WIDTH / (pencil_colors - 1)))];
    else
        for (unsigned int i = 0; i < SCR_HEIGHT; ++i)
            for (unsigned int j = 0; j < SCR_WIDTH; ++j)
                screen[i][j] = c;
}

void print_screen(void)
{   // Функция вывода буфера в консоль. Переход на следующую строку после экрана.
    /*
    for (unsigned int i = 0; i < SCR_HEIGHT; ++i)               // Быстрый вывод через форматированную строку,
        printf("%.128s\n", screen[i]);                          //но требуется ручная подстановка параметра поля строки.
        */
    for (unsigned int i = 0; i < SCR_HEIGHT; ++i) {
        for (unsigned int j = 0; j < SCR_WIDTH; ++j)
                putchar(screen[i][j]);                          // Более медленный но также рабочий вывод.
        printf("\n");                                           // Раскоментировать, если требуется менять постоянно ширину.
    }
}

void draw_polynomial(int is_fill, int is_clear, int is_print, int step, unsigned char pen)
{   // Очистка экрана и рисование меток, графика и заливки с выводом.
    if (SCR_WIDTH % step != 0) {
        printf("Error draw polynomial, width of chart is not divided by step.\n");
        return;
    }
    if (is_clear)
        clear_screen(' ', 0);
    /*
    for (int i = 0; i < SCR_HEIGHT; ++i) {
        screen[i][SCR_WIDTH >> 0x01] = pencil[1];
        screen[i][(SCR_WIDTH >> 0x01) + 1] = pencil[1];
    }
    for (int j = 0; j < SCR_WIDTH; ++j) {
        screen[SCR_HEIGHT >> 0x01][j] = pencil[1];
        screen[(SCR_HEIGHT >> 0x01) + 1][j] = pencil[1];
    }
    */
    double min = values[0], max = values[0], range = 0.0;
    for (unsigned int idx = 0; idx < SCR_WIDTH; ++idx) {
        if (values[idx] > max)
            max = values[idx];
        if (values[idx] < min)
            min = values[idx];
    }
    range = max - min;
    printf("\nDrawing chart of polynomial values: "
           "minimum = %.2f, maximum = %.2f, range(IY) = %.2f.\n", min, max, range);
    if (range < float_eps) {
        printf("Range in drawing chart is less than epsilon %.2f, return.\n", range);
        return;
    }
    for (unsigned int idx = 0; idx < SCR_WIDTH; idx += step) {
        // printf("%.2f ", values[idx]);
        double iy = (SCR_HEIGHT - 1) - round((values[idx] - min) / range * (SCR_HEIGHT - 1));
        screen[(int)iy][idx] = pencil[pen];
        if (is_fill) {
            for (int j = (int)iy + 1; j < SCR_HEIGHT; ++j)
                screen[j][idx] = pencil[pen - 1];
        }
    }
    if (is_print)
        print_screen();
}

void print(const char txt[], struct element poly[POLYNOM_MAX], unsigned int size, int endl)
{   // Вывод глобального полинома в строку, дополнительный параметр переноса строк.
    printf("%s", txt);
    for (unsigned int idx = 0; idx < size; ++idx)
        printf("%+d*(X)^%u ", poly[idx].constant, poly[idx].exponent);
    while (endl--)
        printf("\n");
}

void clear(struct element poly[POLYNOM_MAX])
{   // Очистка полинома полностью по глобальному пределу.
    for (int i = 0; i < POLYNOM_MAX; ++i) {
        poly[i].constant = 0;
        poly[i].exponent = 0;
    }
}

void differential(struct element poly_dst[POLYNOM_MAX], struct element poly_src[POLYNOM_MAX], unsigned int size)
{   // Дифференциал от полинома одна степень вниз, с выводом.
    if (poly_dst == NULL || poly_src == NULL || size == 0) {
        printf("Error differential, destination or source polynomial data or size is null.\n");
        return;
    }
    clear(poly_dst);
    printf("Differential for polynomial from (%p) to (%p), size %u: ", poly_src, poly_dst, size);
    for (unsigned int idx = 0; idx < size; ++idx) {
        poly_dst[idx].constant = poly_src[idx].constant * (int)poly_src[idx].exponent;
        if (poly_src[idx].exponent > 0)
            poly_dst[idx].exponent = (poly_src[idx].exponent - 1);
    }
    print("", poly_dst, size, 1);
}

void integral(struct element poly_dst[POLYNOM_MAX], struct element poly_src[POLYNOM_MAX], unsigned int size)
{   // Интеграл от полинома, одна степень вверх, с выводом.
    if (poly_dst == NULL || poly_src == NULL || size == 0) {
        printf("Error differential, destination or source polynomial data or size is null.\n");
        return;
    }
    // print("\nSource: ", poly_src, size, 1);
    clear(poly_dst);
    printf("Integral for polynomial from (%p) to (%p), size %u: ", poly_src, poly_dst, size);
    for (unsigned int idx = 0; idx < size; ++idx) {
        poly_dst[idx].exponent = (poly_src[idx].exponent + 1);
        if (poly_src[idx].exponent == 0 && poly_src[idx].constant == 0)
            poly_dst[idx].constant = 1;
        else
            poly_dst[idx].constant = poly_src[idx].constant / (int)poly_dst[idx].exponent;
    }
    print("", poly_dst, size, 1);
}

double value(struct element poly[POLYNOM_MAX], unsigned int size, double variable)
{   // Вычисление значения полинома в заданной точке значения.
    if (poly == NULL || size == 0 || variable < poly_left || variable > poly_right) {
        printf("Polynomial value P(%.2f) error. Address, size or variable incorrect.\n", variable);
        return 0;
    }
    double r = 0.0;
    for (unsigned int idx = 0; idx < size; ++idx) {
        // printf("-:%.5f-:\n", pow(variable, (double)poly[idx].exponent) * poly[idx].constant);
        r += (poly[idx].constant * pow(variable, (double)poly[idx].exponent));
    }
    // printf("R = %.3f.\n", r);
    return r;
}

int resolve(struct element poly[POLYNOM_MAX], unsigned int size, enum res_method type)
{   // Вычисление корней полинома с учетом максимального интервала и обновление статичных данных.
    if (poly == NULL || type >= res_not) {
        printf("Error resolve polynomial, no data (%p) or resolve type %d incorrect.\n", poly, type);
        return 0;
    }
    printf("\nResolving polynomial P(X) == 0, using %s method, scale 1/%.2f.\n", res_names[type], scale);
    double near = 1000.0, var = 0, var_val = 0.0;
    double left = (double)poly_left / scale, right = (double)poly_right / scale, center;
    switch (type) {
    case res_full: {
        printf("Full values of P([%.2f,%.2f]): ", left, right);
        for (int i = poly_left, j = 0; i <= poly_right; ++i, ++j) {
            var = (double)i / (double)scale;
            values[j] = value(poly, size, var);
            printf("%.2f ", values[j]);
            if (fabs(values[j]) < fabs(near)) {
                near = values[j];
                var_val = var;
            }
        }
        printf("\nNearest resolve is %.2f, variable P(%.2f).\n", near, var_val);
        break;
    } case res_bisection: {
        double cv, lv, rv;    // Левосторонее, правостороннее и центральное значения.
        printf("Bisection method in range [%.2f, %.2f], epsilon for solution %.2f:\n", left, right, float_eps * 10.0);
        do {
            // plv = lv; prv
            center = (left + right) / 2.0;
            lv = value(poly, size, left);
            rv = value(poly, size, right);
            cv = value(poly, size, center);
            printf("Vars and values: left [%.2f, %.2f], right [%.2f, %.2f] and center [%.2f, %.2f].\n",
                   left, lv, right, rv, center, cv);
            if (lv >= rv)
                left = center;
            else
                right = center;
            // printf("A = %.2f\n", fabs(cv));
        } while (fabs(left - right) > (float_eps * 10.0));
        printf("Nearest resolve is %.2f, variable P(%.2f).\n", cv, center);
        break;
    } default:
        printf("Type %d of resolving incorrect, somethin goes wrong.\n", type);
    }
    return 0;
}

double value_integral(struct element poly[POLYNOM_MAX], unsigned int size, unsigned int steps, enum int_method type)
{   // Вычисление значения полинома с выводом графика на экран.
    double r = 0.0;
    double var, val, left, right, step_size = (abs(poly_left) + abs(poly_right) + 1) / steps;
    printf("\nValue of integral polynom P(X), using '%s' method and draw chart, step size %.2f.\n",
           int_names[type], step_size);
    resolve(poly, size, res_full);
    draw_polynomial(1, 1, 1, 1, 4);
    struct element poly_int[POLYNOM_MAX];
    integral(poly_int, poly, size);
    // integral(poly_int, poly, size);
    switch (type) {
    case int_square:
        printf("Square all steps: %d.\n", steps);
        printf("Areas of squares for integral function: ");
        var = poly_left;
        while (var < poly_right) {
            val = fabs(value(poly_int, size, var / scale) * step_size);
            r += val;
            printf("%.2f(%.2f) ", val, r);
            var += step_size;
        }
        printf("\nResult of all square area: %.2f.\n", r);
        break;
    case int_trapezoid:
        printf("Trapezoid constant step, using 'Kotes formula': %d.\n", steps);
        printf("Areas of trapezoids, (F(X) + F(X + step) div 2): ");
        var = poly_left;
        while (var < poly_right) {
            left = fabs(value(poly_int, size, var / scale));
            right = fabs(value(poly_int, size, (var + step_size) / scale));
            val = ((left + right) / 2) * step_size;
            r += val;
            printf("%.2f(%.2f) ", val, r);
            var += step_size;
        }
        printf("\nResult of all trapezoid area: %.2f.\n", r);
        break;
    case int_simpson:
        printf("Simpson's method, using polynomial of power up to 3.\n");
        left = poly_left / scale; right = poly_right / scale;
        printf("Nearest: ((%.2f - %.2f) / 6) * ((P(%.2f) + 4*P((%.2f + %.2f) / 2) + P(%.2f).\n",
               right, left, left, left, right, right);
        double lv = value(poly, size, left), rv = value(poly_int, size, right);
        double cv = value(poly, size, (left + right) / 2.0);
        r = fabs(((right - left) / 6.0) * (lv + 4 * cv + rv)) * step_size;
        printf("\nResult of Simpson's area: %.2f.\n", r);
        break;
    default:
        printf("Value integral has incoorrect type %d.\n", type);
        return 0.0;
    }
    return r;
}

void spline(struct element poly[POLYNOM_MAX], unsigned int size, unsigned int points)
{   // Кубический сплайн по количеству точек, кратных ширине, контрольных точек в два раза больше.
    // Трехдиагональная матрица решается методом "прогонки" или алгоритм Томаса.
    if (poly == NULL || size == 0 || SCR_WIDTH % (points - 1) != 0) {
        printf("Error in spline, polynom is null or range not divived by %u points.\n", points);
        return;
    }
    printf("\nSpline for source polynomial, size %u and starting ranges %u:\n", size, points - 1);
    printf("Just for better chart, amount of points is *2(%d), low resolution.\n", (points - 1) * 2);
    printf("Values of function and spline in points is close as possible %.2f or equal.\n", float_eps * 10.0);
    resolve(poly, size, res_full);
    print("Source polyinomial: ", poly, size, 1);
    struct element first[POLYNOM_MAX], second[POLYNOM_MAX];
    printf("First and second differential polynoms:\n");
    differential(first, poly, size);
    differential(second, first, size);
    printf("\nSpline define as: S[i](X) = a[i] + (b[i] * (X - X[i])) + (c[i]/2 * (X - X[i])^2) + (d[i]/6 * (X - X[i])^3).\n");
    printf("First differential: S'[i](X) = b[i] + (c[i] * (X - X[i])) + (d[i]/2 * (X - X[i])^2).\n");
    printf("Second differential S''[i](X) = c[i] + (d[i] * (X - X[i]).\n");
    printf("\nUsing Thomas or tridiagonal matrix algorithm to find constants 'a', 'b', 'c', 'd'.\n");
    double tridiagonal[POLYNOM_MAX][POLYNOM_MAX];
    for (unsigned int i = 0; i < points; ++i)
        for (unsigned int j = 0; j < points; ++j)
           tridiagonal[i][j] = 0.0;
    double range = (SCR_WIDTH / (points - 1)) / scale;
    printf("Ranges for main diagonal: 2 * (x[i + 1] - x[i]) = %.2f.\n",  range);
    tridiagonal[0][0] = tridiagonal[4][4] = 1;
    tridiagonal[1][1] = tridiagonal[2][2] = tridiagonal[3][3] = 2.0 * range;
    for (int i = 0; i < 3; ++i) {
        tridiagonal[1 + i][i] = range;
        tridiagonal[1 + i][2 + i] = range;
    }
    printf("Source tridiagonal matrix and 'C' vector as multiply:\n");
    for (unsigned int i = 0; i < points; ++i) {
        for (unsigned int j = 0; j < points; ++j)
            printf("%.2f\t", tridiagonal[i][j]);
        if (i == 2)
            printf("* ");
        else
            printf("  ");
        printf("C[%d]\n", i);
    }
    double vars[POLYNOM_MAX], left = poly_left / scale, right = poly_right / scale;
    double step_size = (fabs(left) + fabs(right) + 1) / (points - 1);
    vars[0] = 2 * value(poly, size, left); vars[4] = 2 * value(poly, size, right);
    for (unsigned int i = 1; i < (points - 1); ++i) {
        left += step_size;
        vars[i] = value(first, size, left);  // tridiagonal[i][i] *
    }
    printf("\nSource vector of f(X[i]) for matrix: ");
    for (unsigned int i = 0; i < points; ++i)
        printf("f(%d) = %.2f; ", i, vars[i]);
    draw_polynomial(0, 1, 0, 8, 4);
    double vals[POLYNOM_MAX];
    vals[0] = vars[0]; vals[4] = vars[4];   // Граничные условия.
    // range *= range;
    // printf("R = %.2f\n", range);
    for (unsigned int i = (points - 1); i >= 1; --i)
        vals[i] = range * (((vars[i + 1] - vars[i]) / range) - ((vars[i] - vars[i - 1]) / range));
    vals[2] *= -1; vals[3] /= 12;
    printf("\nValues of matrix as vector:\n"
           "M * C(0) = %.2f;\n"
           "M * C(1) = ((f(x[2]) - f(x[1]) / range) - ((f(x[1] - f(x[0]) / range) = %.2f;\n"
           "M * C(2) = ((f(x[3]) - f(x[2]) / range) - ((f(x[2] - f(x[1]) / range) = %.2f;\n"
           "M * C(3) = ((f(x[4]) - f(x[3]) / range) - ((f(x[3] - f(x[2]) / range) = %.2f;\n"
           "M * C(4) = %.2f;\n", vals[0], vals[1], vals[2], vals[3], vals[4]);
    struct element cubic[POLYNOM_MAX];
    for (unsigned int i = 0; i < size; ++i) {
        cubic[i].constant = (int)round(vals[i]);
        cubic[i].exponent = poly[i].exponent;
    }
    // cubic[2].constant *= -1; cubic[3].constant /= 12;
    // print("Source polyinomial: ", poly, size, 0);
    print("\nCubic polynomial with constants: ", cubic, size, 1);
    resolve(cubic, size, res_full);
    draw_polynomial(0, 0, 1, 1, 3);
}

int main()
{
    printf("Cubic spline for polynomial function differential of left and right points are zero.\n");
    printf("Size of char %u, short %u and int is %u bytes. Address width is %u bits.\n",
           sizeof(char), sizeof(short), sizeof(int), sizeof(void*) * CHAR_BIT);
    printf("Width of virtual screen %u, height %u chars.\n", SCR_WIDTH, SCR_HEIGHT);
    printf("Warning, to correct draw charts, all polynomial values better be small values.\n");
    printf("Polynomial maximum size %u, maximum power %u.\n", POLYNOM_MAX, poly_pow_max);
    // Вывод исходного полинома для тестирования и построение графика его решений с заливкой.
    printf("\n\nTesting resolving preset polynomial and drawing chart with pencil.\n\n");
    printf("\nRange for polynomial variable [%d, %d], scale by %.2f, step 0.01.\n", poly_left, poly_right, scale);
    print("Source polynomial: ", polynomial, poly_size, 1);
    resolve(polynomial, poly_size, res_full);
    resolve(polynomial, poly_size, res_bisection);
    draw_polynomial(0, 1, 1, 1, 4);
    // Тестирование вычисления интеграла и дифференциала по отдельности.
    struct element poly_int[POLYNOM_MAX], poly_diff[POLYNOM_MAX];
    print("\nTesting integral and differential for polynomial: ", polynomial, poly_size, 1);
    integral(poly_int, polynomial, poly_size);
    differential(poly_diff, polynomial, poly_size);
    // Тестирование вычисления площади(интеграла) двумя методами.
    print("\n\nTesting area, or integral value for source polynomial: ", polynomial, poly_size, 2);
    value_integral(polynomial, poly_size, 8, int_square);
    value_integral(polynomial, poly_size, 4, int_trapezoid);
    value_integral(polynomial, poly_size, 4, int_simpson);
    // Тестирование сплайна по заданному количеству точек. 5 точек и 4 интервала. Но отображается X2.
    spline(polynomial, poly_size, 5);
    return 0;
}
