#include <stdio.h>
#include <stdlib.h>

/*  Вопросы и ответы №19. Лабораторная от Антона(упражнение 1).
 *
 *  Вставьте ключи: 5, 82, 19, 51, 20, 33, 12, 107, 10  в хеш-таблицу с
 * разрешением коллизий методом цепочек. Таблица имеет m ячеек, а
 * хеш функция имеет вид h(k) = k mod m. Вариант 3, параметр m = 31.
 *
 *  Вариант решения. Ключи вычисляются без учета предыдущего значения функции,
 * и сохраняется в виде цепочек в линейный массив структур по формату см.ниже.
 *  Вариант возможный интерпретации. Если рассматривать именно цепочку хешей с рекурсией,
 * то не указана глубина вызова функции по условию. Дополнительная информация в Вики.
 *
 *  Компилируется и проверено на GCC 8.1.0.
 *
 * */

#define HASH_MAX 256            // Максимальное значение массивов для отладки, т.к. была рекомендация.

struct hash_chain               // Структура цепочек хешей(можно было объединить с данными), заголовок.
{
    int keys;                   // Количество ключей в цепочке.
    int hash;                   // Само значение хеша.
    int data_index;             // Индекс данных указывающих на эти ключи в массиве hash_data.
} hash_table[HASH_MAX];         // Рабочая таблица со структурами.

int hash_data[HASH_MAX];        // Массив ключей для хэша, как было рекомендовано. Или можно применить динамическую память.

int main()
{
    printf("Questions 19. Add keys to hash table, variant 3.\n");
    const int values[] = { 5, 82, 19, 51, 20, 33, 12, 107, 10 };                // Значения по условию задания.
    int m = 31, keys = sizeof(values) / sizeof(int), table_size = 0;            // Параметры функции и размеры таблицы.

//	Ключи для отладки, генерируем случайный десяток и добавляем их в таблицу, если вместо варианта потестировать.
/*  int keys = 10, m = 5, table_size = 0;
    printf("Debug values from [0..9]: ");
    int values[HASH_MAX];
    for (int i = 0; i < keys; ++i) {
        values[i] = rand() % 10;
        printf("%d ", values[i]);
    }
    printf("\n");
    */

    printf("Hash function is H(key) = key mod M, M = %d, %d keys to insert.\n", m, keys);
    printf("Inserting values to empty hash table.\n");
    for (int i = 0, j, k, is_collision; i < keys; ++i) {                        // Основной цикл.
        int hash = values[i] % m;                                               // Вычисляем хеш функции.
        printf("\nHash H(%d) = %d, searching for collision in table.\n", values[i], hash);
        printf("Hash in table:\tHash:\tChain size:\tChain:");                   // Поиск коллизии, с уже имеющимся в таблице.
        for (j = 0, is_collision = 0; j < table_size && !is_collision; ) {
            printf("\n%d:\t\t%d\t%d\t\t", j, hash_table[j].hash, hash_table[j].keys);
            for (k = 0; k < hash_table[j].keys; ++k)                            // Выводим таблицу по ходу поиска коллизии.
                printf("%d ", hash_data[hash_table[j].data_index + k]);
            if (hash_table[j].hash == hash)
                is_collision = 1;                                               // Или можно использовать более краткую форму.
            else
                ++j;
        }
        if (is_collision) {                                                     // Если коллизия с уже существующим хешем.
            printf("\nCollision founded at %d record, index data %d and chain size is %d.\n",
                   j, hash_table[j].data_index, hash_table[j].keys);
            // printf("K > %d.\n", hash_table[j].data_index);                   // Дополнительная отладка.
            for (k = j + 1; k < table_size; ++k)                                // Сдвигаем индексы вправо по массиву.
                hash_table[k].data_index++;
            for (k = HASH_MAX - 1; k > hash_table[j].data_index; --k)
                hash_data[k] = hash_data[k - 1];                                // Сдвигаем значения вправо и освобождаем место для нового ключа.
            hash_data[hash_table[j].data_index] = values[i];
            hash_table[j].keys++;
            printf("Update chain in table. Record %d, data size %d, hash %d and keys chain: ",
                   j, hash_table[j].keys, hash_table[j].hash);                  // Обновляем цепочку ключей.
            for (k = 0; k < hash_table[j].keys; ++k)
                printf("%d ", hash_data[hash_table[j].data_index + k]);
            printf("\n");
        } else {                                                                // Если коллизии не произошло, то создаем новую запись.
            printf("\nCollision not founded in table, first free record is %d.\n", j);
            hash_table[j].keys = 1;
            hash_table[j].hash = hash;
            if (table_size)                                                     // Индекс - следующий за предыдущим.
                hash_table[j].data_index = hash_table[j - 1].data_index + hash_table[j - 1].keys;
            else
                hash_table[j].data_index = 0;                                   // Если таблица была пустой.
            hash_data[hash_table[j].data_index] = values[i];                    // Сохраняем значение ключа.
            printf("Add new hash %d to table for key %d and data size %d, at index %d.\n",
                   hash, values[i], hash_table[j].keys, hash_table[j].data_index);
            table_size++;                                                       // Увеличиваем размеры таблицы.
        }
    }
    printf("\n");
    printf("Hash table result with chains, size %d.\n", table_size);            // Выводим итоговую таблицу.
    printf("N:\tHash:\tKeys:\tData index:\tChain:");
    for (int i = 0; i < table_size; ++i) {
        printf("\n%d:\t%d\t%d\t%d\t\t", i, hash_table[i].hash, hash_table[i].keys, hash_table[i].data_index);
        for (int j = 0; j < hash_table[i].keys; ++j)
            printf("%d ", hash_data[hash_table[i].data_index + j]);
    }
    printf("\n");
    return 0;
}
