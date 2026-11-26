#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sorts.h"
#include "queue.h"
#include "fileio.h"
#include "timer.h"
#include "benchmark.h"

int run_benchmark(const char *in_name) {
    FILE *in = fopen(in_name, "r");
    if (in == NULL) {
        perror("Ошибка открытия файла");
        return 1;
    }

    char *line = read_line(in);   /* читаем одну строку любой длины */
    fclose(in);
    if (line == NULL) {
        printf("Файл пустой.\n");
        return 1;
    }

    Queue q;
    init_Queue(&q, 1);
    int n = parse_line(line, &q);
    free(line);

    if (n <= 0){
        printf("Ошибка: не удалось прочитать числа из файла.\n");
        free_Queue(&q);
        return 1;
    }
    int *a = malloc(n * sizeof(int));   /* копия для выбора */
    int *b = malloc(n * sizeof(int));   /* копия для Хоара */
    if (a == NULL || b == NULL) {
        printf("Не хватило памяти.\n");
        free(a);
        free(b);
        free_Queue(&q);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        a[i] = dequeue(&q);
    }
    memcpy(b, a, n * sizeof(int));

    double ts = time_spent(selection_sort, a, n);
    double tq = quick_time_spent(quick_sort, b, 0, n - 1);

    printf("Количество чисел: %d\n", n);
    printf("Сортировка выбором: %f секунд\n", ts);
    printf("Быстрая сортировка: %f секунд\n", tq);

    free(a);
    free(b);
    free_Queue(&q);
    return 0;
}