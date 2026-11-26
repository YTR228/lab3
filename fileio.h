#include <stdio.h>
#include "queue.h"

int file_reading(char *filename);
int file_appending(char *filename, int *array_str,int size,char *message);
int parse_line(char *line, Queue *q);
char *read_line(FILE *f);