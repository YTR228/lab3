#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sorts.h"
#include "queue.h"

int main(int argc, char *argv[]) {
    // Проверяем, передан ли флаг --file и есть ли после него само имя файла
    if (argc == 3 && strcmp(argv[1], "--file") == 0) {
        const char *filename = argv[2];
        
        // Тут вызываем функцию чтения и вывода из filename
        printf("Читаем файл: %s\n", filename);
        return 0; // Завершаем программу, чтобы не идти в обычный ввод
    }

    // Если аргументов нет — идет обычный код (ввод чисел, сортировка, запись в файл)
    printf("Обычный запуск программы\n");
    return 0;
}
