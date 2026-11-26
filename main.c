#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sorts.h"
#include "queue.h"
#include "fileio.h"
#include "timer.h"
#include "benchmark.h"





int main(int argc, char *argv[]) {
    /* Режим файла: ./lab3 --file имя */
    if (argc == 3 && strcmp(argv[1], "--file") == 0) {
        file_reading(argv[2]);
        return 0;
    }
    if (argc == 3 && strcmp(argv[1], "--benchmark") == 0) {
        return run_benchmark(argv[2]);
    }

    /* Любые другие аргументы — ошибка */
    if (argc != 1) {
        printf("Использование: %s [--file имя_файла]\n", argv[0]);
        return 1;
    }
    
    char input[4096];

    while (1) {
        printf("Введите числа через пробел:\n");

        if (fgets(input, sizeof(input), stdin) == NULL) {   /* Ctrl+D */
            break;
        }

        Queue q;
        init_Queue(&q, 1);
        int n = parse_line(input, &q);

        if (n == -1) {
            printf("Ошибка: вводите только целые числа.\n");
        } else if (n == 0) {
            printf("Ошибка: вы ничего не ввели.\n");
        } else {
            /* Перекладываем очередь в массив по порядку */
            int *array = malloc(n * sizeof(int));
            if (array == NULL) {
                printf("Не хватило памяти.\n");
                free_Queue(&q);
                return 1;
            }
            for (int i = 0; i < n; i++) {
                array[i] = dequeue(&q);
            }

            printf("Исходный ряд: ");
            for (int i = 0; i < n; i++) {
                printf("%d ", array[i]);
            }
            printf("\n");

            file_appending("output.txt", array, n, "Исходный ряд:");
            int *selection_array = malloc(n * sizeof(int));
            if (selection_array == NULL) {
                printf("Не хватило памяти.\n");
                free(array);
                free_Queue(&q);
                return 1;
            }
            memcpy(selection_array, array, n * sizeof(int));

            int *quick_array = malloc(n * sizeof(int));
            if (quick_array == NULL) {
                printf("Не хватило памяти.\n");
                free(array);
                free(selection_array);
                free_Queue(&q);
                return 1;
            }
            memcpy(quick_array, array, n * sizeof(int));

            double selection_time = time_spent(selection_sort, selection_array, n); 
            printf("Время сортировки выбором: %f секунд\n", selection_time);
            double quick_time = quick_time_spent(quick_sort, quick_array, 0, n - 1);
            printf("Время быстрой сортировки: %f секунд\n", quick_time);
            printf("Отсортированный ряд: ");
            for (int i = 0; i < n; i++) {
                printf("%d ", quick_array[i]);
            }
            file_appending("output.txt", selection_array, n, "Отсортированный ряд:\n");
            
            
            free(array);
            free(selection_array);
            free(quick_array);
        }
        free_Queue(&q);

        printf("Повторить? (y/n): ");
        if (fgets(input, sizeof(input), stdin) == NULL || input[0] != 'y') {
            break;
        }
    }
    return 0;
}