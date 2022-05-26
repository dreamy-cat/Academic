#include <stdio.h>

int main()
{
    /* Упражнение 1.
     * Вставьте ключи: 5, 82, 19, 51, 20, 33, 12, 107, 10.
     * в хеш-таблицу с разрешением коллизий методом цепочек.
     * Таблица имеет m ячеек, а хеш функция имеет вид h(k) = k mod m.
     * Вариант 3, параметр m = 31.
     */

    /* Вариант решения. Ключи вычисляются без учета предыдущего значения функции,
    и сохраняется в виде цепочек в линейный массив структур по формату см.ниже. */

    /* Вариант возможный интерпретации. Если рассматривать именно цепочку хешей с рекурсией,
    то не указана глубинаызова функции по условию.*/

#define HASH_MAX 256

    struct hash_chain       // Структура цепочек хешей(можно было объединить с данными).
    {
        int keys;           // Количество ключей в цепочке.
        int hash;           // Само значение хеша.
        int data_index;     // Индекс данных указывающих на эти ключи в массиве hash_data;
    };

    struct hash_chain hash_table[HASH_MAX];
    int hash_data[HASH_MAX];
    const int values[] = { 5, 82, 19, 51, 20, 33, 12, 107, 10 };
    int m = 31, keys = sizeof(values) / sizeof(int), table_size = 0;
    printf("Variant 3.\n");
    printf("Hash chain parameter M = %d, %d keys to insert: ", m, keys);


/*	Ключи для отладки, генерируем случайный десяток и добавляем их в таблицу, если вместо варианта посмотреть.
 *
    int values[HASH_MAX];
    keys = 10;
    for (int i = 0; i < keys; ++i) {
        values[i] = rand() % 10;
        printf("%d ", values[i]);
    }
    printf("\n");
*/

    printf("Hash function is H(key) = key mod M.\n");
    printf("Inserting values to empty hash table.\n");
    for (int i = 0, j, k, is_collision; i < keys; ++i) {       // Main cycle.
        // int hash = values[i] % m;
        int hash = values[i] % 5;
        printf("\nHash H(%d) = %d, searching for collision in table.\n", values[i], hash);
        printf("Hash in table:\tHash:\tChain size:\tChain:");
        for (j = 0, is_collision = 0; j < table_size && !is_collision; ) {
            printf("\n%d:\t\t%d\t%d\t\t", j, hash_table[j].hash, hash_table[j].keys);
            for (k = 0; k < hash_table[j].keys; ++k)
                printf("%d ", hash_data[hash_table[j].data_index + k]);
            if (hash_table[j].hash == hash)
                is_collision = 1;               // Или можно использовать более краткую форму.
            else
                ++j;
        }
        if (is_collision) {
            printf("\nCollision founded at %d record, index data %d and chain size is %d.\n",
                   j, hash_table[j].data_index, hash_table[j].keys);
            // printf("K > %d.\n", hash_table[j].data_index);
            for (k = j + 1; k < table_size; ++k)            // Move indexes righter than founded hash.
                hash_table[k].data_index++;
            for (k = HASH_MAX - 1; k > hash_table[j].data_index; --k)
                hash_data[k] = hash_data[k - 1];        // Move data to insert new value.
            hash_data[hash_table[j].data_index] = values[i];
            hash_table[j].keys++;
            printf("Update chain in table. Record %d, data size %d, hash %d and keys chain: ",
                   j, hash_table[j].keys, hash_table[j].hash);
            for (k = 0; k < hash_table[j].keys; ++k)
                printf("%d ", hash_data[hash_table[j].data_index + k]);
            printf("\n");
        } else {
            printf("\nCollision not founded in table, first free record is %d.\n", j);
            hash_table[j].keys = 1;
            hash_table[j].hash = hash;
            if (table_size)
                hash_table[j].data_index = hash_table[j - 1].data_index + hash_table[j - 1].keys;
            else
                hash_table[j].data_index = 0;
            hash_data[hash_table[j].data_index] = values[i];
            printf("Add new hash %d to table for key %d and data size %d, at index %d.\n",
                   hash, values[i], hash_table[j].keys, hash_table[j].data_index);
            table_size++;
        }
    }
    printf("\n");
    printf("Hash table result with chains.\n");
    printf("N:\tHash:\tKeys:\tData index:\tChain:");
    for (int i = 0; i < table_size; ++i) {
        printf("\n%d:\t%d\t%d\t%d\t\t", i, hash_table[i].hash, hash_table[i].keys, hash_table[i].data_index);
        for (int j = 0; j < hash_table[i].keys; ++j)
            printf("%d ", hash_data[hash_table[i].data_index + j]);
    }
    printf("\n");
    return 0;
}
