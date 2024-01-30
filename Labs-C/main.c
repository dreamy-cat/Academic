#include <stdio.h>

// Базовые практические задания. Условные уровни добавить отдельно, здесь полностью все задания.

// Все практические главы распределены и оформлены по файлам.

void labs_01(void);                     //  Ввод и вывод числовых данных. Оператор присваивания.
void labs_02(void);                     //  Целочисленная арифметика.
void labs_03(void);                     //  Величины логического типа.
void labs_04(void);                     //  Условный оператор.
void labs_05(void);                     //  Оператор цикла с параметром.
void labs_06(void);                     //  Операторы цикла с условием.
void labs_07(void);                     //  Сочетание оператора цикла и условного оператора.
void labs_08(void);                     //  Вложенные циклы.
void labs_09(void);                     //  Строки символов.
void labs_10(void);                     //  Функции и процедуры.
void labs_11(void);                     //  Одномерные массивы.
void labs_12(void);                     //  Двумерные массивы.
void labs_13(void);                     //  Структуры данных и массивы.
void labs_14(void);                     //  Файлы, текст и структуры.
void labs_15(void);                     //  Дополнительная глава с практикой.

void olymp(void);                       // Дополнительные олимпиадные задания, возможно после вынести отдельно.
void gfx(const char[], int, int);       // Построение графики в .BMP файл(ы), без подключения дополнительных библиотек.
void Den_code_review(void);

int main(void)
{
    printf("Laboratory for basic tasks in C programming language.\n");
    printf("Compile using x86, or 32-bits GCC or MSVS tools.\n\n");
    labs_04();
    //Den_code_review();
    // olymp();

    // gfx("scr_dst.bmp", 1280, 640);   // Later updated from Danya.

    // list_of_schools();   // move to questions.
}
