#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Градиентный спуск, элементарные методы на полиноме или степенной функции.
// Непонятный полностью код, скорее всего не то что нужно, переделать в будущем полность.

// Максимальное количество элементов в полиноме.
#define POLYNOM_MAX 0x100
//  Ширирна и высота виртуального экрана для консольного рисования графиков. Если будут изменения, то заглянуть в 'print_screen'.
#define SCR_WIDTH 0x80
#define SCR_HEIGHT 0x40
//  Максимальный размер буффера для текстового сообщения или для строчных преобразований.
#define TEXT_MAX 0x400

struct element {
    int constant;
    unsigned int exponent;
    char variable;
};

// Глобальные константы для программы.
static const int info_low = -3, info_high = +3;
static const int poly_left = -SCR_WIDTH / 2, poly_right = SCR_WIDTH / 2 - 1;
static const int poly_pow_max = 3;
static const int rnd_max = 4;
static const unsigned int pencil_colors = 5;                    // Всего условных цветов или градаций черного.
static const char pencil[] = { 32, 176, 177, 178, 219 };        // Коды таблицы ASCII для рисования в буффере.

// Глобальные данные, используют все функции, чтобы не передавать значения в функции каждый раз.
static char screen[SCR_HEIGHT][SCR_WIDTH];                      // Буффер виртуального текстового экрана.
static unsigned int poly_size = 0, poly_vars = 3;               // Параметры и исходный полином.
static struct element polynomial[POLYNOM_MAX] = {   { .constant = 2, .exponent = 3, .variable = 'A' },
                                                    { .constant = 3, .exponent = 1, .variable = 'A' },
                                                    { .constant = -3, .exponent = 1, .variable = 'B' },
                                                    { .constant = 1, .exponent = 2, .variable = 'B' },
                                                    { .constant = 1, .exponent = 0, .variable = 'C' }   };
static unsigned int grad_comm_size = 0, grad_var_size = 0;
static struct element grad_common[POLYNOM_MAX];
static struct element grad_variable[POLYNOM_MAX];

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

void print_poly(const char txt[], struct element poly[POLYNOM_MAX], unsigned int size, int endl)
{   // Вывод глобального полинома в строку, дополнительный параметр переноса строк.
    printf("%s", txt);
    for (unsigned int idx = 0; idx < size; ++idx)
        printf("%+d*(%c)^%u ", poly[idx].constant, poly[idx].variable, poly[idx].exponent);
    while (endl--)
        printf("\n");
}

int polynomial_value(struct element poly[POLYNOM_MAX], int values[], unsigned int size)
{   // Вычисление значение полинома, без контроля выхода за пределы. Значения для всех переменных.
    int result = 0;
    if (size == 0) {
        printf("Error polynomial value, data is empty.\n");
        return 0;
    }
    for (unsigned int idx = 0; idx < size; ++idx) {
        int val = 1, pow = poly[idx].exponent;
        while (pow--)
            val *= values[poly[idx].variable - 'A'];
        result += val * poly[idx].constant;
    }
    return result;
}

void draw_poly(struct element poly[POLYNOM_MAX], unsigned int size, unsigned char var, int color)
{   // Рисование полинома в виртуальный экран используем относительно переменной.
    int sx, sy, sy_max = INT_MIN, sy_max_pos = 0, sy_min = INT_MAX, sy_min_pos = 0, vals[POLYNOM_MAX];
    for (unsigned int i = 0; i < POLYNOM_MAX; ++i)
        vals[i] = 0;
    for (sx = poly_left; sx <= poly_right; ++sx) {
        vals[var - 'A'] = sx;
        sy = polynomial_value(poly, vals, size);
        if (sy > sy_max) {
            sy_max = sy;
            sy_max_pos = sx;
        }
        if (sy < sy_min) {
            sy_min = sy;
            sy_min_pos = sx;
        }
        // printf("\n%d\t%d", sx, sy);
    }
    clear_screen(' ', 0);
    print_poly("\nDraw polynomial at chart: ", poly, size, 1);
    printf("Minimum values SY: %d at %d, max values SY: %d at %d, center of chart at [%d, %d].\n",
           sy_min, sy_min_pos, sy_max, sy_max_pos, 0, (sy_max - sy_min) / 2);
    printf("Polynomial of variable '%c', function 'Poly(%c)' in range.\n", var, var);
    printf("Screen sizes %d horizontal chars and %d vertical chars.", SCR_WIDTH, SCR_HEIGHT);
    if (sy_max == sy_min)    // Разрушение на горизонтальной прямой.
        ++sy_max;
    for (sx = poly_left; sx <= poly_right; ++sx) {
        vals[var - 'A'] = sx;
        sy = polynomial_value(poly, vals, size);
        double scr_y = round(((double)(sy - sy_min) / (double)(abs(sy_max - sy_min))) * (double)(SCR_HEIGHT - 1));
        screen[SCR_HEIGHT - (int)scr_y - 1][sx - poly_left] = color;
        // printf("%d\t%d\n", sx - poly_left, SCR_HEIGHT - (int)scr_y - 1);
    }
    print_screen();
}

unsigned int gradient(unsigned char variable)
{   // Построение градиента по заданной переменной, если переменная равна пробелу, то вычисляется общий дифференциал.
    if ((unsigned int)(variable - 'A') > poly_vars && (char)variable != ' ') {
        printf("Error gradient, variable in polynomial not exist, last variable is '%c'.\n", 'A' + poly_vars - 1);
        return 0;
    }
    unsigned int idx = 0;
    unsigned char var_first, var_last;
    if (variable == ' ') {
        grad_comm_size = 0;
        var_first = 'A';
        var_last = 'A' + poly_vars - 1;
        printf("Get function differentials from '%c' to '%c' variables and save to common gradient.\n", 'A', var_last);
    } else {
        var_first = var_last = variable;
        printf("\nGet function differential for '%c' variable and save to variable gradient.\n", variable);
    }
    for (unsigned char var = var_first; var <= var_last; ++var) {
        for (idx = 0, grad_var_size = 0; idx < poly_size; ++idx)
            if (polynomial[idx].variable == var) {
                if (polynomial[idx].exponent >= 1) {
                    grad_variable[grad_var_size].exponent = polynomial[idx].exponent - 1;
                    grad_variable[grad_var_size].constant = polynomial[idx].constant * polynomial[idx].exponent;
                    grad_variable[grad_var_size].variable = polynomial[idx].variable;
                    if (variable == ' ')
                        grad_common[grad_comm_size++] = grad_variable[grad_var_size++];
                    else
                        grad_var_size++;
                }
            } else if (variable == ' ')
                grad_common[grad_comm_size++] = polynomial[idx];
        printf("Differential for variable '%c': ", var);
        print_poly("", grad_variable, grad_var_size, 1);
    }
    if (variable == ' ')
        print_poly("Common gradient as sum of partial diffrentials: ", grad_common, grad_comm_size, 1);
    if (variable == ' ')
        return grad_comm_size;
    else
        return grad_var_size;
}

void print_poly_grad_table(void)
{   // Вывод полной таблицы с условными занчениями функции, градиента и частной производной.
    printf("\nPolynomial, gradients and partial differentials information.\n");
    int poly_values[POLYNOM_MAX], grad_comm_vals[POLYNOM_MAX], vals[POLYNOM_MAX];
    int grad_var_vals[POLYNOM_MAX][POLYNOM_MAX];    // Для каждого частного дифференциала.
    for (unsigned int i = 0, j; i < POLYNOM_MAX; ++i) {
        for (j = 0; j < POLYNOM_MAX; ++j)
            grad_var_vals[i][j] = 0;
        poly_values[i] = grad_comm_vals[i] = vals[i] = 0;
    }
    printf("Pre-calculate all data for table.\n");
    for (int i = 0; i <= info_high - info_low; ++i) {
        vals[0] = info_low + i; vals[1] = info_high - info_low - i; vals[2] = info_high - i;
        poly_values[i] = polynomial_value(polynomial, vals, poly_size);
        grad_comm_vals[i] = polynomial_value(grad_common, vals, grad_comm_size);
        for (unsigned int j = 0; j < poly_vars; ++j) {
            gradient('A' + j);
            grad_var_vals[i][j] = polynomial_value(grad_variable, vals, grad_var_size);
        }
    }
    printf("\nFull table for variables, polynomial function, gradient and partial differentials.\n");
    print_poly("Source polynomial: ", polynomial, poly_size, 1);
    print_poly("Common gradient: ", grad_common, grad_comm_size, 1);
    for (unsigned int var = 0; var < poly_vars; ++var)
        printf("'%c':\t", 'A' + var);
    printf("Poly(X):\tGrad(Poly):\t");
    for (unsigned char i = 0; i < poly_vars; ++i)
        printf("Diff(%c):\t", 'A' + i);
    for (int i = 0; i <= info_high - info_low; ++i) {
        printf("\n%d\t%d\t%d\t", info_low + i, info_high - info_low - i, info_high - i);
        printf("%d\t\t%d\t\t", poly_values[i], grad_comm_vals[i]);
        for (unsigned int j = 0; j < poly_vars; ++j)
            printf("%d\t\t", grad_var_vals[i][j]);
    }
    printf("\n");
}

unsigned int const_half_step(unsigned int precision, unsigned char variable, int* value, int is_const)
{   // Метод спуска с постоянным или переменным адаптивным шагом, по параметру.
    if (variable >= 'A' + poly_vars) {
        printf("Error const step, variable not in polynomial '%c'.\n", variable);
        return 0;
    }
    printf("\nGradient descent using constant steps, precision %u, variable '%c'.\n", precision, variable);
    int center = rand() % (poly_right - poly_left - precision) + precision;
    int left = center - precision, right = center + precision;
    int values[POLYNOM_MAX], step, diff = precision, prev_diff = precision * precision;
    unsigned int i, iterations = 0;
    for (i = 0; i < POLYNOM_MAX; ++i)
        values[i] = 0;
    gradient(variable);
    values[variable - 'A'] = center;
    int center_val = polynomial_value(grad_common, values, grad_comm_size);
    values[variable - 'A'] = left;
    int left_val = polynomial_value(polynomial, values, grad_comm_size);
    values[variable - 'A'] = right;
    int right_val = polynomial_value(grad_common, values, grad_comm_size);
    printf("Gradient polynomial center grad(%d) = %d, left grad(%d) = %d, right grad(%d) = %d.\n",
           center, center_val, left, left_val, right, right_val);
    if (center_val - left_val < center_val - right_val) {
        center  = left;
        printf("Left shift value is %+d, gradient is less than right value %d, choose direction from right to left.\n",
               center_val - left_val, center_val - right_val);
        step = +1;
    } else if (center - right_val < center_val - left_val) {
        center = right;
        printf("Right shift value is %+d, gradient is less than left value %d, choose direction from right to left.\n",
               center_val - right_val, center_val - left_val);
        step = -1;
    } else {
        printf("Warning, gradient in point is 0, may be correct result or error of try.\n");
        return center_val;
    }
    printf("Starting point at %d and step direction %+d for next Poly('%c').\n",
           center, step, variable);
    do {
        values[variable - 'A'] = center;
        center_val = polynomial_value(polynomial, values, poly_size);
        values[variable - 'A'] = center + step;
        *value = polynomial_value(polynomial, values, poly_size);
        diff = abs(*value - center_val);
        printf("%d:%d\t%d:%d\t%d\t%d\n", center, center_val, center + step, *value, diff, step);
        if (is_const == 0) {            // Если адаптивный шаг.
            if (prev_diff > diff) {
                step <<= 0x01;
            } else {
                if (step >= 0)
                    step = +1;
                else
                    step = -1;
            }
        }
        prev_diff = diff;
        iterations++;
        center += step;
    } while ((unsigned int)diff >= precision);
    return iterations;
}

void generate_polynomial(int debug_size)
{   // Автоматическая генерация полинома для отладки, с учетом глобальных параметров.
    for (int i = 0; i < debug_size; ++i, poly_size++) {
        int sign = ((rand() % rnd_max) >= (rnd_max >> 0x01)) ? +1 : -1;
        polynomial[i].constant = (rand() % rnd_max) * sign;
        polynomial[i].exponent = rand() % poly_pow_max;
        polynomial[i].variable = 'A' + rand() % poly_vars;
    }
    poly_size = debug_size;
}

int main()
{   // Основная программа и тестирование.
    printf("Simple gradient descent using constant and half step methods for polynomial.\n");
    printf("Size of char %u, short %u, int %u and address width %u bits.\n",
           sizeof(char), sizeof(short), sizeof(int), sizeof(char*) * CHAR_BIT);
    srand(3);
    const unsigned int debug_size = 5;
    unsigned int it;
    int value;
    // Тестирование базовых функций вывода и сгенерированный полином.
    printf("\nGenerate polynomial function size %u, maximum power %u and %u variables.\n",
           debug_size, poly_pow_max, poly_vars);
    // generate_polynomial(debug_size);
    poly_size = debug_size;
    print_poly("Source polynomial: ", polynomial, poly_size, 1);
    gradient(' ');
    print_poly_grad_table();
    printf("\n\nFind minimum of Poly('%c'), using constant step of gradient.\n", 'A');
    it = const_half_step(10, 'A', &value, 1);
    printf("Total iterations of constant step method is %u, minimum value %d.\n", it, value);
    printf("\n\nFind minimum of Poly('%c'), using adaptive step of gradient.\n", 'B');
    it = const_half_step(10, 'B', &value, 0);
    printf("Total iterations of adaptive step method is %u, minimim value %d.\n", it, value);
    printf("\n\nDraw polynomial charts for 'A' and 'B' variables.\n");
    draw_poly(polynomial, poly_size, 'A', pencil[4]);
    printf("\n\n");
    draw_poly(polynomial, poly_size, 'B', pencil[3]);
    return 0;
}
