#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <limits.h>
#include "queue.h"
#define N 2         
#define MAX_LEN 2048 


int file_reading(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Ошибка открытия файла");
        return 1;
    }

    char lines[N][MAX_LEN];
    int count = 0;

    while (fgets(lines[count % N], MAX_LEN, file) != NULL) {
        count++;
    }

    int total = (count < N) ? count : N;
    int start = (count < N) ? 0 : (count % N);

    for (int i = 0; i < total; i++) {
        printf("%s", lines[(start + i) % N]);
    }

    fclose(file);
    return 0;

}
int file_appending(char *filename, int *array_str,int size,char *message) {
    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        perror("Ошибка открытия файла");
        return 1;
    }
    fprintf(file, "%s ", message);
    for (int i = 0; i < size; i++) {
        fprintf(file, "%d ", array_str[i]);
    }
    fprintf(file, "\n");

    fclose(file);
    return 0;


}


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

char *read_line(FILE *f) {
    size_t cap = 256, len = 0;
    char *buf = malloc(cap);
    if (buf == NULL) return NULL;

    int c;
    while ((c = fgetc(f)) != EOF && c != '\n') {
        if (len + 1 >= cap) {                 
            char *tmp = realloc(buf, cap * 2);
            if (tmp == NULL) { free(buf); return NULL; }
            buf = tmp;
            cap *= 2;
        }
        buf[len++] = (char)c;
    }
    if (c == EOF && len == 0) {               
        free(buf);
        return NULL;
    }
    buf[len] = '\0';
    return buf;
}