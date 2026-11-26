#define func_time(func_call) do { \
    clock_t start = clock(); \
    func_call; \
    clock_t end = clock(); \
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC; \
    printf("%f\n", time_spent); \
} while (0)

