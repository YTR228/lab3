#include <time.h>

double time_spent(void (*func)(int *, int), int *array, int n) {
    clock_t start = clock();
    func(array, n);
    clock_t end = clock();
    return (double)(end - start) / CLOCKS_PER_SEC;
}

double quick_time_spent(void (*func)(int *, int, int), int *array, int left, int right) {
    clock_t start = clock();
    func(array, left, right);
    clock_t end = clock();
    return (double)(end - start) / CLOCKS_PER_SEC;
}