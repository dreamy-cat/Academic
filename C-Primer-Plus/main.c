#include <stdio.h>

/*  Добавить комментарий относительно конфигурации компиляции и сборки.
 *  Все теоретические части, которые были рассмотрены на вещаниях.
 *  // Учебник - Прата(6-ое издание), КиР, стандарт языка и немного видео материалов.
 * Для компиляции используется: GCC 8.1.0, 32-bit, QtCreator.
 *
 * */

/*


 Перенести постепенно в исходный код вместе с примерами для разбора.
 Язык программирования Си, Стивен Прата, 6-ое издание.


 Вопросы и темы для обсуждения по теории, по ходу практических занятий.


 Глава 1.

 
 Глава 2. Введение в язык Си

 Запустить среду разработки и набросать минимальный пример с перой переменных, отдельно их обьявления и определения. Вывести их на экран и простую сумму. Отметить про инициализаицию переменных и значения по умолчанию, для активного компилятора и вывести их оба на экран.
 Немного обсудить структуру программы на Си, на примере выше, каждую строку комментируем. Функций, область видимости, операторы и составные операторы.
 Директивы препроцессора, быстро как работает(заголовок + библиотечный код) и почему использовать стоит осторожно. Подумать над организацией исходников для всех. По аналогии с обычными проектами.
 Функция main, по оформлению и немного про назначение.
 Комментарии, здесь только немного про однострочные и многострочные отметить.
 Обьявления. Определение. Схема тип данных и имя(идентификатор). Порядок обьявления и захват ресурсов памяти и оптимизация компилятора. Выбор имени относительно краткое, но чтобы было ясно. Зарезервированные слова и регистр.
 Пару слов про статичную типизацию, в Си она слабая и статичная в отличии от Питона.
 Присваивание, загрузка в память на стеке, статичную или динамическую. Функции, аргументы формальные и фактические. Быстро на примере printf().
 Структура простой программы на Си, на примере схемы 2.4. Оператор вызова функции, заголовок функции и параметры.
 По оформлению будем придерживаться КиР.
 Множественные обьявления через запятую.
 Снова немного про обьявления и использование функций. Прототипы функций.
 Синтаксические и семантические ошибки. На уровне определений. Синтаксис - правила языка программирования, регламентирующие использование конструкций, операторов и данных. Семантика - смысловая нагрузка, того что имеется под операторами. Или что планировалось сделать.
 Трассировка программы, её состояния и вывод через печать. Ключевые слова в Си, их немного, но стоит того чтобы запомнить.
 

 Глава 3. Данные в языке Си


 Глава 9. Функции

 Обзор функций

 Немного по терминологии: функция, процедура и подпрограмма. Самодостаточная единица кода программы, спроектированная для отдельной задачи.
 Модульность программы и повторяемость кода. Даже один раз использование функции, может помочь с восприятием кода. Организация кода и назначение действий, декларация действия алгоритма. Пара слов о надежности и отладке функций.
 Не обязательно знать как именно работает функция, главное знать что именно она делает. И как именно её вызывать с передачей параметров.
 Немного по терминологии: прототип функции, определение функции и вызов функции. Там же про части функции: идентификатор, параметры и пустой параметр относительно стандарта. Сигнатура функции - обьявление функции.
 Вызов начинается с главное функции, и продолжатеся далее по алгоритму с вызовом других функции. Вызывающая и вызываемая. Также стоит рассказать про область видимости функции и составные операторы. Видимость относительно других функций, основной и глобальных переменных. Где создаются элементарные типы во время исполнения.
 Аргументы функций, их количество и универсальность функций. Типы аргументов(формальные аргументы, формальные параметры) и какие значения допустимы для использования: переменные, константы, выражения. Присвоение переменных идет в начале функции и они копируются по значению. Перечисление одного типа и множества переменных не допустимо. Без типа, у нас по умолчанию будет целочисленный.
 В прототипе функции, имена переменных можно не указывать.
 Еще немного про фактический аргумент и формальный параметр. Глянем ассемблер.
 Возвращаемое значение, может быть извлечено с левой стороны или быть частью выполнения выражений. Быть внимательными относительно объектов, которые возвращаются и учитывать динамическую память. Попробовать неявное преобразование типа, и рассказать про предыдущую задачу. Оператор возврата может быть использован в разных местах функции.
 Типы функций, всё тут же повторяется. И надо быть внимательным при объявлении/определении функции. Заголовки библиотечных файлов содержат только обьявления функций, но часто не код.

 Вопросы дополнительные для проверки, после уже вещаний для повторения: что такое функция; прототип функции; вызов функции; определение функции; сигнатура функции и структура прототипа функции; стек вызовов функций и поток исполнения кода; область видимости и локальные переменные; формальные параметры и аргументы; тип возвращаемго значения по умолчанию(древний код).

 Создание прототипов функций в ANSI C

 Обьявление функции без формальных параметров и невозможность проверить аргументы. Аргументы при вызове помещаются в/на стек, на глубину количества параметров и их размерности. Интерпретация в ассемблере была разная, слева направо и наоборот.
 По решению стандарта можно указывать как количество аргументов так и их тип, имена переменных являются фиктивными и при определении функции они могут быть другими. Быть осторожным с автоматическим преобразованием. Вспомнить наш пример на сравнение величин двойной точности. Выдать совет про преобразование в целочисленный. Но быть осторожней.
 Отсутствие аргументов, не забыть про void и неопределенное количество аргументов в виде многоточия. Прототипы позволяют отслеживать ошибки на этапе компиляции. Мы обьединяем прототипы и определения функции.

 Рекурсия

 Рекурсия это вызов функции из самой себя. Типы рекурсии в программировании. Простая и прямая или сложная и косвенная с вызовом через сторонние функции. Глубина рекурсии. Цикл заменяется и обязательно должен быть в наличии стек. Может выглядеть красиво, но не всегда эффективно с точки зрения времени выполнения. Решение с рекурсией часто не очевидно. Также существует двойная рекурсия в зависимости от количества вызовов.
 Про последовательность и стек вызова. Переменные на стеке, заменяются или обладают уникальными адресами и каждый раз мы можем протягивать свои значения. Выход из рекурсии. Рекурсивная функция может быть разделена на условно три части: до вызова самой себя, после вызова самой себя и точка выхода или окончания рекурсии. Порядок исполнения частей имеет смысл. Баланс вызова и возврата будет обязательно, если не зациклимся. Код не дублируется, только данные. Не забыть код окончания рекурсии.
 Хвостовая рекурсия, с вызовом в конце перед возвратом. С примеров факториала. Также помнить о размерности стека.
 Рекурсия и изменение порядка на противоположный. Здесь просто пример и возможно что часть параметров необходимо тянуть вместе с собой.
 Преимущества и недостатки рекурсии. Наглядность и красота реализации, но быстрое исчерпание стека как недостаток. Рост параметров может идти по экспоненте, или даже линейно. Для больших массивов память надежнее выделять в операционной системе. Пространства имен в Си не существует, поэтому надо быть осторожней. Максимум это переменные структур или обьединений.
 
 Компиляция программ, состоящих из двух или более файлов исходного кода

 Unix. Файлы отдельно плюс команда СС раздельная компиляция в отдельные обьектные файлы.
 Linux. Раздельная компиляция на месте, но выходной файл один.
 DOS. Получается файл obj, компиляторы всё еще есть, можно посмотреть. На ассемблере у нас это и будет, файл типа com.
 IDE - интегрированная среда разработки, пара слов ооб использовании, ресурсы проекта, файлы и т.д.

 Использование заголовочных файлов

 Заголовочный файл, содержит обьявления имен, переменных, константы, дирекивы препроцессора и функции. Можно немного вспомнить про обьявление и определение. Иначе директиву дефайн, придется делать в каждом файле, а они всё еще используются, активно. Про двойные кавычки, лучше использовать знаки "<>" для системных библиотек и для своих заголовочных файлов использовать просто кавычки. Также зависит от системы, но вопросу откуда будет осуществляться поиск. Пример так себе в книге, лучше констнты делать переменными и вводить статиеческие данные.

 Выяснение адресов: операция &

 Концепция указателей или адресов, часто возникают трудности в освоении. Лучше если знать архитектуру железа и немного как действует процессор. Также сталкивались уже когда передавали значения в функции, которые нужно изменить. Операция взятия адреса, возвращает номер ячейки. Копирование параметров по значению.

 Измнение переменных в вызывающей функции

 Простая функция обмена значений переменных через обмен. При копировании значений или использовании адресов. 
 
 Указатели: первое знакомство

 Указатель - это переменная или объект данных, значением которого является адрес в памяти. Для Си это также может быть как адрес любого другого объекта, в т.ч. и функции.
 Операция разыменования: *, также снятие косвенности. Можно продемонстировать на примере с обменом, что где и как называется. Или, еще "значение которое храниться по указанному адресу".
 Обьявленеи указаетелей, используем также звезду, вопрос постановки пробела, лучше использовать ближе к типу, так наглядней, но разницы никакой нету по оформлению.
 Для демонстрации адресов, взять несколько базовых типов, которые обьявлены один за другим и вывести их адреса.

Общие заметки и планы на вещания по программированию на классическом Си.

Вещание №5.

Глава 7, теория.

Логика, оператор ветвления или выбора. С простым или составным. Проехаться по офоромлению, один оператор не надо в фигурные скобки, а блок елсе если что объединять вместе со скобками. В сложных выражениях(несколько операторов), не использовать лестницу из строк, а если уж где-то длинные вычисления, то их или переносить по знаку, или уже делать несколько строк операций. Внимательность при цикле, если приоритет присваивания ниже, чем у сравнения.

ctype.h - функции использовать активно, но мы для обучения напишем свои. Список на странице 255.

Конструкция множественного выбора лесенкой if else. Возможно не очень удобно смотрится, но с точки зрения машинного кода достаточно хорошо оптимизирована, поэтому можно активно ей пользоваться. Если лестница совсем получается большой, то уже возможно стоит пересмотреть подход к проектированию алгоритма, или уже нужна таблица переходов или данных, как это в примере в книге с расчетом тарифа.

Если не определено, к какому блоку относиться елсе, то остается только ставить фигурные скобки. Если их нету, то по последнему условному оператору.

Пример с вычислением делителей. Там где лишние итерации в алгоритме можно упустить, это всегда стоит применить. Высокоуровневая оптимизация дает самый как правило лучший результат с точки зрения выигрыша.

По вопросу логических операторов и множества условий в одном ИФе. Если выражение совсем становиться громоздким и/или нечитаемым, то лучше через дополнительные переменные. У отрицания достаточно высокий приоритет.

Программу подсчета слов в предложении мы сдалаем свою тоже. Использовать краткую логическую форму в условии - по вкусу. Также касается и тернарного оператора - использовать по вкусу. С практической точки зрения может быть удобным, но для целей обучения если исползовать полную классическую форму ИФа тоже можно.

Континуе и брейк применять можно, но если их появляется сильно много, то уже стоит задуматься о построении алгоритмов в программе. Также можно использовать для целей оформления, но только если самому удобно.

Оператор Свитч. Почти не используется в С++, но возможно. Можно объединять метки пропуская брейк, дополнять метки парой и т.д. В Си можно использовать и с хитростью, но если выбор огромный, то фактически уже лучше применить таблицу вызовов адресов.

Оператор ГоТо: использовать только в крайнем случае и то потом всё таки лучше поправить. Оставим этот оператор для нашего РетроКода.

Вопросы для самоконтроля пробежаться глазами.

Задачи, Златопольский, глава 4, по разделам.
Теоретические вопросы:
1. Полный и не полный, выражение может быть односложным или состоять из множества операндов с выходом и без.
2. Полная схема с if else и по вопросу оформления уплотнять строчки.
3. Неполный оператор, если дальше у нас восстанавливается обычный ход программы. Для оптимизации лучше когда идет, условие, которое выполняется по основному ИФу или если неполный, то лучше если его пропускать(но зависит от компилятора).
4. Вложенный условный оператор идет у нас если имеется достаточно сложная логика и требуется ветвление в завсимиости от последовательности параметров. Если параметров множество, то мы просто анализируем всё в одном операторе, или требуются дополнительные высиления
5. Вариант выбора в Си использовать можно, в плюсах его уже фактически нету, но он мне лично чем-то нравился, более того он исполняет инструкции проваливаясь, до оператора break, так что можно строить достаточно интересные дополняющие друг-друга конструкции.

Вещание №4.

Задачи, Златопольский, глава 3.
1: Проверить условное выражение вида (2 > 0), операции сравнения, унарные опарации. Напомнить про справочник на странице 833. 
2: Результатом выполнения опепации отношения является логический ноль или логическая единица или в терминах Си 0 и не 0.
3: Составное условие из множества операндов и операций между ними, "И", "ИЛИ", "НЕ", приоритете регулируется скобками.
4: Если имеется ввиду только условия однозначные, то получается что 2, переставив их местами. Если их там 4-то факториал 4.
5: Тоже самое по факториалу 3! = 6 различных комбинаций. Но тут под вопросом, если условие существует или нет, то получается 8 комбинаций, по количеству условных бит.

Задачи, глава 3. 
Величины логического типа: 3.1-10 - четные или нечетные по выбору; 3.11-12 - одну на выбор; 3.13-26 - любую каждую третью(14,17,20,23...).
Составление логических выражений: 3.27-31 - две на выбор; 3.32-33 - одну на выбор; 3.34-35 - дополнительно, не обязательно, но 3-4 варианта из каждой реализовать, они небольшие.

Вещание №3.

Теоретические вопросы.

Макросы и препроцессор уже понемногу уходит, но всё еще встречаются достаточное количество старого кода, в которых он есть. Поэтому читать и править их нужно уметь, но самому уже стараться использовать по минимуму. Лучше использовать классические константы, если нет необходимости.

По массивам и разным их форматам, не стеснятся если что использовать другой формат или даже можно изобрести велеосипед для тренировки, мы это будем делать активно, и не будем использовать стандартную библиотеку. С длиной аккуратней и стоит помнить, что большие массивы стоит уже запрашивать через системную функцию выделения памяти, по умолчанию мелкий массив должен быть только в стеке.

Скобки для sizeof рекомендую ставитьв любом случае.

Стараемся избегать магических цифр и непонятно откуда взявшихся чисел, на разве что 0, 1, -1 которые несут в выражении однозначный смысл и то существует NULL для адресов еще есть и nullptr. Константы для препроцессора использовать заглавные.

Модификатор конст, обратить внимания на сообщения компилятора. 

Страница 130 для всех спецификаторов вывода, а модификаторы можно посмотреть на 133. Для sizeof использовать беззнаковое целое. Минус первый раз увидел, для текста может подойти. И решетка в выводе 16-ти ричном, добавялет 0х комбинацию.

Про передачу параметров через стек, это стандартный механизм еще со времен ассемблера, но фактически первое, это передача через регистры процессора. Как именно делает компилятор вопрос открытый и можно посмотреть в машинном коде, но фактически так делать не стоит.

Справочная информация для функции СканФ на странице 145. Длину поля удобней использовать для ограничения текста строки. Учитывать неопределенность результата СканФ для чисел. Насчет пробелов, необходимо нажать ввод. * - для пропуска переменной.

Глава 5.

Рвалуе, ЛВалуе и операнды. Немного общих комментариев, но главное это то что сохраняется по результату. Оператор у нас может быть составным или простым, состоит из операндов и действий над ними. Приоритет операций по справочнику.

По операторам префиксной и постфиксного инкремента, предпочесть префиксную форму. Порядок вызова аргументов в функции, при вычислении. Быть осторожней не нарваться на пересечение переменных и не расчитывать на порядок инкремента и декремента.

Цикл с условием, ноль или не ноль, и с составным или простым оператором и напомнить про точку с запятой.

Операторы, про последовательность, функции. Составной оператор не использовать, фигурные скобки там где один оператор, просто следующая строка. А так где составной, то фигурную скобку ставить сразу, кроме функций.

Преобразование типов, не злоупотреблять. Если повышение типа идет хорошо, то вниз могут возникнуть проблемы. Если преобразование типов слишком часто, то возможно стоит задуматься над тем правильно ли, сформулирована программа.

Про аргументы и параметры, сказать про указатель, про копию. И напомнить про обьявление и определением функции.

Задачи дополнительные:

1. Глава 1. Посмотреть на Тубе как работает механика мини-игры в серии Фолла по взлому терминала. Выполнить простое проектирование этой игры, рассказать про этапы разработки и последовательности действий в самой игре. 5-7 буквально предложений. Записать подробнее правила игры и прикинуть теоретически алгоритм решения этой задачи со стороны пользователя(ну т.е. как мы и играли в Фолле).

- генерация слова или шифра из цифр;
- генерация слов из словаря: длина слов, зависит от сложности терминала; количество слов для отгадывания зависело от интеллекта или науки; количество попыток 4;
- оказывается есть подсказки, если их применить, анализ знаков;
- первый вариант идет без выбора;
- запуск цикл:
- выбор слова;
- анализ слова;
- если все буквы совпали, то всё;

2. Глава 2. Построить стандартную таблицу символов АСКИИ, начиная с 32-ого кода и до 128-ого. Использовать while и простые индексы. Не забыть шапку таблицы, в которой нужны минимум: код символа, код в 16-ти ричном формате и сам символ. Остальное просто по строчкам можно. Размеры таблицы произвольны, сколько влезет по ширине отображения в нашей консоли. Использовать табуляцию "\t" или просто пробелы по вкусу.

3. Глава 3. Проэксперементировать с типом char. Выяснить сколько байт(бит) он занимает в памяти на плафторме разработки и как влияет знак/беззнак на него и диапазон значений не прибегая к прямому выводу. Можно использовать как while так и оператор sizeof. Лучше двумя способами последовательно. Ну и совсем хорошо, если будут использованы для проверки вычислений заголовочный файл #include <limits.h> и его константы. https://en.cppreference.com/w/cpp/header/climits

4. Глава 4. Построить таблицу температур в градусах, келивинах и фаренгейтах. В заголовке оставить шапку, сделать вывод в двух разных форматах по вкусу, в десятичном представлении и экспоненциальной форме чисел с плавающей точкой, с учетом ширины полей и форматирования. Старт можно брать от градусов на 5-10 строк в таблице, через параметр и цикл while. Использовать #define и/или const char.

5. Глава 4. Если формат строки уже более или менее понятен, то можно рискнуть написать функцию strlen, которая была в книге, но свою версию, попытаться оформить функцию, если не получается, то просто по тексту программы. Ну и еще пару классических функций: переворот строки в обратном порядке, и подсчет в ней частоты определенного символа, который можно задать через константу или на входе в функцию. Использовать цикл while и индексы с учетом длины строки и терминального символа. Дополнительно: реализовать функцию поиска подстроки в строке(применить вложенные циклы while).

6. Глава 5. Дополнительное. Написать функцию печати бинарного представления числа с типом char, 8 бит. Оформить ввиде функции. "void print_binary(char n);". Пригодится нам позже при заданиях на работу с битовыми полями.

7. Глава 5. Дополнительное. Попробовать написать функцию подсчета количества бит в заданном числе, типа char или unsigned char, по вкусу. Можно обчединить с предыдущей и сразу же проверить. Можно применять целочисленные опарации или битовые, если заглянуть в справочник.

Вещание №2. Глава 2 и немного теории.

Теория Прата: читать 3,4,5 главы и нарезать задачи из них сколько возможно. Златопольский пока отложить, 3-ая глава ждет. Таблица операций с приоритетами, 833-ая страница. 5-ая и 6-ая глава в задачнике возможно будет сразу, после 5-ой главы учебника.

По теории добавить: при сравнени или вычислении выражений, то учитывать автоматическое преобразование типов. Если используешь условия, то старатся более понятно делать. ГОТО - байка, про использование. Свитч, это фактически метки, с приветом из ассемблера. Континуе и бреак не желательно использовать, если много циклов, то лучше предусмотреть условия или вопрос оптимизации.

Задачи, Стивен Прата, глава 3. 1 - провести эксперимент с типом char на переполнение, можно отложить использование заголовочных файлов, sizeof использовать по желанию. 2. Построить немного таблицу АСКИИ. 

Первая глава теоретическая, просто для ознакомления. Задания, которые можно пропустить.

1.15 - ж, з,к 
1.16 - 3-5 на выбор.
1.17 - ж, н, г
1.20 - всё.

Во второй главе пробежаться по заголовкам, возможно стоит решить упражнения тоже.

Третья глава. Уточнить знания по битам/байтам/словам и попробовать перевод систем счисления. Плавающая точка. Указатель на справочник.

Задачи, Златопольский, первая, глава. Кроме тех что уже сделаны: 1.22-23, 1.25-29, 1.30 - один вариант, 1.31 обязательно, 1.35 и 37. 1.39-42 - любую на выбор, 1.44-1.51 - пара на выбор, 1.52-1.56 - по желанию любые, 1.57 - обязательно(58-ая часть её). 1.59-60 - обязательно, 1.61-62 - пару на выбор.

Задачи, Златопольсикй, глава 2.
Раздел "Простейшие задачи": 2.1-2.9 - три на выбор.
Раздел "Выделение цифр в записи числа": 2.12-18 - обязательно, для вычислений и последовательности действий. 2.21-23 - одну по желанию(или можно пропустить).
Раздел "Нахождение целого числа по информации о его цифрах": 2.24-2.33 - три-пять на выбор, число Н другие параметры вводить с клавиатуры не надо, просто задать его как переменную.
Раздел: "Задачи повышенной сложности". 2.34-46 - дополнительно, но подьемно, любая. 2.37-38 - одна на дополнительный выбор. 2.39-42 - запутанно, но одну на выбор можно. 2.43 - попытаться применить хитрость.

*/

/*

Это тоже перенести в теорию для Си, в исходный код.

 Частично перенесено в репозиторий и там же и оставить вместе с кодом.


Глава 7. теория.

Логика, оператор ветвления или выбора. С простым или составным. Проехаться по офоромлению, один оператор не надо в фигурные скобки, а блок елсе если что объединять вместе со скобками. В сложных выражениях(несколько операторов), не использовать лестницу из строк, а если уж где-то длинные вычисления, то их или переносить по знаку, или уже делать несколько строк операций. Внимательность при цикле, если приоритет присваивания ниже, чем у сравнения.

ctype.h - функции использовать активно, но мы для обучения напишем свои. Список на странице 255.

Конструкция множественного выбора лесенкой if else. Возможно не очень удобно смотрится, но с точки зрения машинного кода достаточно хорошо оптимизирована, поэтому можно активно ей пользоваться. Если лестница совсем получается большой, то уже возможно стоит пересмотреть подход к проектированию алгоритма, или уже нужна таблица переходов или данных, как это в примере в книге с расчетом тарифа.

Если не определено, к какому блоку относиться елсе, то остается только ставить фигурные скобки. Если их нету, то по последнему условному оператору.

Пример с вычислением делителей. Там где лишние итерации в алгоритме можно упустить, это всегда стоит применить. Высокоуровневая оптимизация дает самый как правило лучший результат с точки зрения выигрыша.

По вопросу логических операторов и множества условий в одном ИФе. Если выражение совсем становиться громоздким и/или нечитаемым, то лучше через дополнительные переменные. У отрицания достаточно высокий приоритет.

Программу подсчета слов в предложении мы сдалаем свою тоже. Использовать краткую логическую форму в условии - по вкусу. Также касается и тернарного оператора - использовать по вкусу. С практической точки зрения может быть удобным, но для целей обучения если исползовать полную классическую форму ИФа тоже можно.

Континуе и брейк применять можно, но если их появляется сильно много, то уже стоит задуматься о построении алгоритмов в программе. Также можно использовать для целей оформления, но только если самому удобно.

Оператор Свитч. Почти не используется в С++, но возможно. Можно объединять метки пропуская брейк, дополнять метки парой и т.д. В Си можно использовать и с хитростью, но если выбор огромный, то фактически уже лучше применить таблицу вызовов адресов.

Оператор ГоТо: использовать только в крайнем случае и то потом всё таки лучше поправить. Оставим этот оператор для нашего РетроКода.

Глава 8. Символьный ввод-вывод и проверка достоверности ввода.

 Односимвольный ввод-вывод. Путчар и Гетчар функции стандартные и древние еще со времен Юниксов и их поддержка есть как правило повсюду, включаемый файл sdtio.h.

 Буферизация. При вводе используется буферизация, это более удобно и быстродействие выше. Если что не стесняться использовать свои велосипеды. Полностью буферизированный ввод-вывод и построчный. У нас используется построчный, и также мы делали функцию ввода одной строки через отдельные символы. Размеры буфера могут быть разные, но нам хватит точно на ввод простых строчек. Функции getch() и getche() ввод без вывода и с эхом, в conio.h.

 Завершение клавиатурного ввода. Файлы и потоки. Поддержка файлов есть в стандартном Си. Его удобней рассматривать как поток, мы будем работать в основном с текстовыми файлами. Клавиатура и консольный вывод тоже потоки. Мысль про контрол-Зет, любопытна но сейчас такого уже наверное нету и имеется размер файла и его можно имитировать. ЕОФ - признак конца файла или потока, можно будет посмотреть на его значение, он имеет тип интежер, чтобы быьб чуть шире чара и гетчар тоже возвращает инт.

 Перенаправление и файлы. Стандартный поток ввода это клавиатура, а поток вывода это консоль(экран). Можно будет менять, по умолчанию, попрбуем это позже. Из командной строки негобходимо поставить знак направления >. Особенно не понадобиться, но стоит поиграть с консолью и поставить виртаульную машину. Посмотреть пример работы с файлом.

 Создание дружественного пользовательского интерфейса. Оформление консольных приложений идет достаточно просто, но чаще всего используются аргументы командной строки или файлы конфигурации. Если что псевдографику тоже можно использовать.

 Числа и символы при вводе. Удобней всего получать текст при вводе ввиде строки и потом уже можно будет из нее доставать и анализировать. Классическая конструкция через цикл вайл и гетчар.

 Просмотр меню. Схема часто используемая именно в заданиях на учебе. Не стесняемся использовать оператор Свитч и Кейс.

Глава 9. 

*/

void part_01(void);     // Предварительные сведения.
void part_02(void);     // Введение в язык Си.
void part_03(void);     // Данные в языке Си.
void part_04(void);     // Символьные строки и форматированный ввод-вывод.
void part_05(void);     // Операции, выражения и операторы.
void part_06(void);     // Управляющие операторы Си: циклы.
void part_10(void);     // Массивы и указатели.
void part_13(void);     // Файловый ввод-вывод.

// Вопросы по ходу кода, повторяем с учетом предыдущих глав.

int main(void)
{
    printf("C Programming Language.\nBased on Stephen Prata 'C Primer Plus' Sixth Edition.\n\n");
    part_06();
    return 0;
}
