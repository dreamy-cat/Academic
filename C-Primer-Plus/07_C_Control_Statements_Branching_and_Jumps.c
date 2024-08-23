﻿#include <stdio.h>
#include <iso646.h>
#include <ctype.h>

// Глава 7. Управляющие операторы Си: ветвление и переходы.
// Условный оператор в книге идет после оператора цикла, если удобней возможно изменить порядок изучения.

// Максимальная длина текстовой строки, через подстановку, 256 байт.
#define TEXT_MAX 0x100

int is_alpha(char c)
{	// Функиця проверки, является-ли символ параметр буквой латинского алфавита.
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return 1;											// Или можно одной строчкой, по желанию.
	else
		return 0;
}

void part_07(void)
{
	printf("Part 7. C Control Statements: Branching and Jumps.\n");
	int a, b, c, d;											// Объявляем целочисленные общие переменные для всей главы.
	// Что такое оператор if и его строение, выбор и ветвление. Логическое выражение. В ассемблере команды условного перехода.
	printf("\nFull operator IF.\n");
	a = -5; b = +5; c = 0; d = 0;
	printf("Values in range [-5, +5]: ");
	while (a <= b) {										// Сокращенная форма, минимум строк. Или полная с фигурными скобками.
		printf("%d ", a);
		if (a < 0) {										// Дополнительный вопрос о краткой и полной форме оператора if.
			c++;
			a++;
		} else {											// Повторение: простой и составной оператор.
			d++;
			a += 2;
		}													// Схему можно посмотреть в книге.
	}
	printf("\nNegative %d elements and %d zero or positive elements.\n", c, d);
	// Функции putchar и getchar, посимвольный ввод строки через цикл. Дополнительно и для тренировки.
	// Идиома присваивания и сравнения прямо в логическом выражении оператора цикла с приоритетом.
	int text[TEXT_MAX];										// Для удобства отладки, можно следующий пример закомментировать.
	printf("\nInput and output string line, using 'putchar' and 'getchar' functions.\nInput: ");
	a = b = 0;
	while ((c = getchar()) != '\n' && a < TEXT_MAX - 1)
		text[a++] = c;
	text[a] = '\0';
	printf("Output, size %d: ", a);
	while (b < a)
		putchar(text[b++]);
	// c.type - библиотеку можно пропустить или базовые функции можно реализовать самостоятельно для практики.
	char e = 'd';
	printf("\n\nLibrary function 'is_alpha' from <ctype.h>, is '%c' alpha: ", e);
	if (is_alpha(e))										// Вызов функции в условном выражении.
		printf("yes.\n");
	else
		printf("no.\n");
	// Конструкция множественного или многовариантного выбора "лесенкой" if-else-if...
	// Если конструкция становится совсем объемной, то можно использовать техники с таблицами сравнения или вызовов адресов функций.
	a = 5; b = 3; c = 7;
	printf("\nIf-else combination in choice. A = %d, B = %d, C = %d.\n", a, b, c);
	if (a > b && a > c)										// Возможно не очень удобно смотрится, но с точки зрения машинного кода хорошо оптимизирована.
		printf("A is more than B and C.\n");
	else if (a > b && a < c)								// Если лестница совсем получается большой, то уже возможно стоит пересмотреть алгоритм.
		printf("A is more than B, but less than C.\n");		// Или уже нужна таблица переходов или данных.
	else if (a > c && a < b)								// Если не определено, к какому блоку относиться иначе, то можно ставить фигурные скобки. 
		printf("A is more than C, but less than B.\n");		// По умолчанию к последнему условному оператору.
	else													// Оставшийся вариант можно без условия.
		printf("A is less than B and C.\n");
	// Образование вложенных пар if-else, общие правила и быть внимательней с блоками.
	printf("\nUsing if-else with {}, A = %d, B = %d.\n", a, b);
	a = 5; b = 3;
	if (a == 1) {											// Быть внимательным, к какому составному оператору или блоку относится фигурная открывающая скобка.
		if (b > 2)											// Последовательность может быть важна, если невозможно выполнить вторую проверку не сломав первую.
			printf("A is equal 1 and B is more than 2.\n");	// Схема графики 7.2, 258-ая страница.
		else
			printf("A is equal 1, but B less than 2.\n");
	} else													// Простой оператор можно записать без лишних скобок.
		printf("A is not equal 1.\n");
	// Другие вложенные операторы if. Классическая задачка на делители, повторить делеение, рассмотреть её подробнее и поработать с флагами.
	a = 100; c = 0;
	printf("\nAll dividers for %d from [1..100]: ", a);
	for (b = 2; (b * b) <= a; ++b)							// Инициализация.
		if (a % b == 0) {									// У этого условия только основная часть. Можно без фигурных.
			if (b * b != a) {								// Полный условный оператор.
				d = (a / b);
				printf("%d %d ", b, d);
				c += 2;										// Выводим и увеличиваем счетчик сразу на два значения.
		} else {
				printf("%d ", b);
				c++;
			}												// Лишние итерации всегда стараться сократить.
		}													// Высокоуровневая оптимизация дает как правило лучший результат относительно затрат.
	printf("- total %d numbers.\n", c);
	// Основные логические операции и их приоритет. Множества условий в одном if.
	printf("\nLogical operators and combinations.\n");
	// Дана последовательность из 4-ех чисел, определяем если: не (1-2-ое или 3-4-ое равны между собой), или первая цифра 7.
	a = 1; b = 1; c = 3; d = 4;								// Для использования операций условий.
	printf("\nSequence of digits %d - %d - %d - %d.\n", a, b, c, d);
	printf("If not((%d equal %d) and (%d not equal %d)) or (%d equal 7) = ", a, b, c, d, a);
	a = !((a == b) and (c != d)) or (a == 7);				// Допустимо, если использовать #include <iso646.h>. 
	if (a != 0)												// Повторение: приоритет и скобки. У отрицания достаточно высокий приоритет.
		printf("%d, yes, expression is true.\n", a);		// Если выражение совсем становится нечитаемым, то применить дополнительные переменные.
	else													// Логические выражения вычисляются слева направо.
		printf("%d, no, expression is false.\n", a);		// Если дальнейшие вычисления бессмысленны, то они не выполняются, можно рискнуть с кодом.
	// 1 <= a < 5 - ошибка, не допустимо, вместо необходимо (a >= 1 && a < 5).
	// Программу подсчета слов в предложении мы сдалаем свою тоже. Использовать краткую логическую форму в условии - по вкусу.
	// Лучше продемонстрировать это на примере программы частоты цифр в числе.
	int digits[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	a = 361830120; b = 10;
	printf("\nDigits [counter] in number %d: ", a);
	while (a > 0) {
		c = a % b;											// Получаем последнюю цифру числа взятием остатка от деления на основание системы счисления т.е. 10.
		digits[c]++;										// Увеличиваем счетчик полученной цифры на единицу.
		a /= b;												// Делим число на основание и смещяем его 
	}
	for (a = 0; a < b; ++a)									// Выводим результат подсчетов.
		printf("%d[%d] ", a, digits[a]);
	// Условная операция ?:, использовать если удобно.
	a = 5; b = (a > 0) ? 1 : 0;								// С практической точки зрения может быть удобным, но для целей обучения, если исползовать полную форму условия.
	printf("\n\nUsing operator '?' IF (%d > 0) ? 1 : 0 = %d.\n", a, b);
	// Вспомогательные операторы break, continue и последовательность исполнения программы.
	printf("\nOperators continue and break in simple loops:\n");
	printf("A:\tB:\tLoop command:\n");
	for (a = 10, b = 0; a >= b; --a) {						// Параметры стремятся к друг-другу и уже после исполняем continue и break.
		printf("%d\t%d\t", a, b);
		if (a % 2 == 0) {
			printf("continue and decrease A;\n");			// Также можно использовать для целей оформления, но только если самому удобно.
			continue;										// Выполнение итерации цикла for прекращается и переходим к следующей итерации.
		}
		while (++b) 										// Если четное, подумать над примером.
			if (b % 2 == 0) {
				printf("break loop to increase B mod 2;");
				break;										// Выход из вложенного(внутреннего) цикла, иначе программа зациклится.
			}
		printf("\n");
	}
	// Выбор из множества вариантов: операторы switch, break. Для чего используется конструкция, можно немного добавить про ассемблер.
	printf("\nOperator switch and break.\n");
	printf("Switch operator and logical statements 0 - not, 1 - or, 2 - and, 3,4 - (or not):\n");
	printf("Index:\tA:\tOperator:\tB:\tResult:\n");
	// Выбор из множества варинатов: операторы switch и break.
	for (c = 0, a = 1, b = 0; c < 5; ++c)					// С постепенным увеличением параметра.
		switch (c) {										// Оператор 'switch'. Редко используется в С++, но возможно.
		case 0:
			d = !a;
			printf("%d\t%d\tnot\t\t\t%d;\n", c, a, d);
			break;
		case 1:
			d = a || b;
			printf("%d\t%d\tor\t\t%d\t%d;\n", c, a, b, d);
			break;
		case 2:
			d = a && b;
			printf("%d\t%d\tand\t\t%d\t%d;\n", c, a, b, d);
			break;
		case 3:												// Можно объединять метки пропуская брейк, дополнять метки парой и т.д.
			d = !b;
			printf("%d\t\tnot\t\t%d\t%d;\n", c, b, d);
		case 4:												// Если выбор большой, то уже лучше применить таблицу вызовов адресов и оператор скобки().
			d = a || d;
			printf("%d\t%d\tor\t\t%d\t%d;\n", c, a, !b, d);
			break;
		default:
			printf("Default message for C = %d.\n", c);
		}
	// Оператор  'goto'. Рекомендуется только в крайнем случае и позже всё таки лучше исправить. Оставим этот оператор для наших посиделок с Ретро Кодом. :)
	a = 0;
	printf("\nOperator 'goto', labels and starting parameter %d.\n", a);
label_a:													// Для Ретро-кода! :)
	if (++a < 3) {
		printf("A = %d, less than 3, goto 'label_a'.\n", a);
		goto label_a;
	} else 
		printf("A = %d is equal 3, no goto operator and execute next code.\n", a);
}
