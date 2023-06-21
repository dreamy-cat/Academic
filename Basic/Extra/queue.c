#include <stdio.h>
#include <stdlib.h>

#define QUEUE_MAX 256

unsigned char queue[QUEUE_MAX];
int queue_size;

struct queue_object {
    short code;
    char name;
};

void queue_init(void)
{
    printf("Initialization of queue, size zero and clear all data.\n");
    queue_size = 0;
    for (int i = 0; i < QUEUE_MAX; ++i)
        queue[i] = 0;
}

void queue_print(int field, int is_all)
{
    printf("Print queue, size %d.\n", queue_size);
    printf("Index:\tDH:\tDL:\tCode:\t\tName:\n");
    const int size = sizeof(struct queue_object), base = 10;
    for (int i = 0; i < queue_size * size || (is_all && i < QUEUE_MAX); i += size) {
        struct queue_object obj;
        obj.code = queue[i] + (queue[i + sizeof(char)] << CHAR_BIT);
        obj.name = queue[i + sizeof(short)];
        printf("%d\t%d\t%d\t", i, queue[i + sizeof(char)], queue[i]);
        char code[QUEUE_MAX];
        code[field] = '\0';
        for (int j = field - 1; j >= 0; --j) {    // while (field) { // or obj.code
            code[j] = '0' + obj.code % base;
            obj.code /= base;
        }
        printf("%s\t%c\n", code, obj.name);
    }
}

int queue_first(struct queue_object* object)
{
    if (!queue_size) {
        printf("Queue is empty, error reading first element.\n");
        return -1;
    }
    object->code = queue[0] + (queue[sizeof(char)] << CHAR_BIT);
    object->name = queue[sizeof(short)];
    printf("First element of queue has %d code and name '%c'.\n", object->code, object->name);
    return 0;
}

int queue_last(struct queue_object* object)
{
    if (!queue_size) {
        printf("Queue is empty, error reading last element.\n");
        return -1;
    }
    int last = queue_size - sizeof(struct queue_object);
    object->code = queue[last] + (queue[last + sizeof(char)] << CHAR_BIT);
    object->name = queue[last + sizeof(short)];
    printf("Last element of queue has %d code and name '%c'.\n", object->code, object->name);
    return 0;
}

int queue_push(struct queue_object* object)
{
    if (queue_size == QUEUE_MAX / sizeof(struct queue_object)) {
        printf("Queue is full, size %d. Can't push new element.\n", queue_size);
        return -1;
    }
    const int size = sizeof(struct queue_object);
    for (int next = (queue_size + 1) * size; next >= size; --next)
        queue[next] = queue[next - size];
    unsigned char dh = (object->code >> CHAR_BIT), dl = object->code & UCHAR_MAX;
    queue[0] = object->code & UCHAR_MAX;
    queue[sizeof(char)] = (object->code >> CHAR_BIT);
    queue[sizeof(short)] = object->name;
    queue_size++;
    printf("Push new element to start queue, code %d(DH = %d, DL = %d), name '%c' and new size is %d.\n",
           object->code, dh, dl, object->name, queue_size);
    return 0;
}

int queue_pop(struct queue_object* object)
{
    if (!queue_size) {
        printf("Queue is empty, nothing to pop.\n");
        return -1;
    }
    int last = (--queue_size) * sizeof(struct queue_object);
    object->code = queue[last] + (queue[last + sizeof(char)] << CHAR_BIT);
    object->name = queue[last + sizeof(short)];
    printf("Pop last element from queue, code %d, name '%c' and new size is %d.\n",
           object->code, object->name, queue_size);
    return 0;
}

int queue_reverse(void)
{
    if (queue_size < 2) {
        printf("Queue is empty or has less than two elements, nothing to reverse.\n");
        return -1;
    }
    printf("Reverse elements in queue.\n");
    struct queue_object obj;
    const int size = sizeof(struct queue_object);
    for (int i = 0; i < queue_size / 2; ++i) {
        int idx_a = i * size, idx_b = (queue_size - 1 - i) * size;
        obj.code = queue[idx_a] + (queue[idx_a + sizeof(char)] << CHAR_BIT);
        obj.name = queue[idx_a + sizeof(short)];
        printf("Left element, code %d, name '%c' at index data %d.\n", obj.code, obj.name, idx_a);
        obj.code = queue[idx_b] + (queue[idx_b + sizeof(char)] << CHAR_BIT);
        obj.name = queue[idx_b + sizeof(short)];
        printf("Right element, code %d, name '%c' at index data %d.\n", obj.code, obj.name, idx_b);
        for (int j = 0; j < size; ++j)
            queue[idx_b + j] = queue[idx_a + j];
        queue[idx_a] = obj.code & UCHAR_MAX;
        queue[idx_a + sizeof(char)] = obj.code >> CHAR_BIT;
        queue[idx_a + sizeof(short)] = obj.name;
    }
    return 0;
}

void queue_and_array(void)
{
    const int debug_elements = 5;
    struct queue_object obj;
    printf("Simple queue with structures.\n");
    printf("Size of structure %u, size of char %u, size of short %u, bits in char %u, uchar max %u.\n",
           sizeof(struct queue_object), sizeof(char), sizeof(short), CHAR_BIT, UCHAR_MAX);
    printf("Name:\tOffset:\t\tSize:\n");
    printf("Code:\t%p\t%u\n", NULL, sizeof(obj.code));
    printf("Name:\t%p\t%u\n\n", (void*)((void*)&obj.name - (void*)&obj), sizeof(obj.name));
    for (int i = 0; i < debug_elements; ++i) {
        obj.code = rand() % SHRT_MAX;
        obj.name = 'A' + rand() % 26;
        printf("\nAdding element to queue, code %d and name '%c'.\n", obj.code, obj.name);
        queue_push(&obj);
        queue_print(8, 0);
    }
    printf("\n");
    queue_first(&obj);
    queue_last(&obj);
    printf("\nPop elements from queue, size %d.\n\n", queue_size);
    for (int i = 0; i < debug_elements - 4; ++i) {
        printf("Pop %d element from queue tail.\n", i);
        queue_pop(&obj);
    }
    printf("\n");
    queue_print(8, 0);
    printf("\n");
    queue_reverse();
    printf("\n");
    queue_print(8, 0);
    printf("\n");
}
