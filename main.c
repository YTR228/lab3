#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sorts.h"
#include "queue.h"
#include "fileio.h"
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <limits.h>
#include "timer.h"

int parse_line(char *line, Queue *q) {
    int count = 0;
    char *word = strtok(line, " \t\n");          /* первое слово */

    while (word != NULL) {
        char *end;
        errno = 0;
        long value = strtol(word, &end, 10);     /* слово -> число */

        if (*end != '\0') {                      /* после числа мусор: "abc", "12abc", "-" */
            return -1;
        }
        if (errno == ERANGE || value < INT_MIN || value > INT_MAX) {  /*проверка диапазона */
            return -1;
        }

        enqueue(q, (int)value);
        count++;
        word = strtok(NULL, " \t\n");            /* следующее слово */
    }
    return count;
}




int main(int argc, char *argv[]) {
    /* Режим файла: ./lab3 --file имя */
    if (argc == 3 && strcmp(argv[1], "--file") == 0) {
        file_reading(argv[2]);
        return 0;
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
            
            
            free(array);
        }
        free_Queue(&q);

        printf("Повторить? (y/n): ");
        if (fgets(input, sizeof(input), stdin) == NULL || input[0] != 'y') {
            break;
        }
    }
    return 0;
}