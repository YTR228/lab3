#include <stdio.h>
#include <stdlib.h>
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

    printf("Последние %d строк(и):\n", total);
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