#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sorts.h"
#include "queue.h"
#include <time.h>
#include "fileio.h"
/*
нужно добавить таймеры и сравнение алгоритмов
ввод вывод данных через файл и без него
сделать сравнение и графики
метрики придумать
*/




int main(int argc, char *argv[]) {
    for (int i = 1; i < argc; i++){
        if (strcmp(argv[i], "--file") == 0){
            file_reading(argv[i+1]);
            return 0;
        }
    }
    return 0;

}


