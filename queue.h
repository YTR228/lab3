typedef struct {
    int *data;
    int front;
    int rear;
    int size;
    int capacity;
} Queue;

void init_Queue(Queue *q, int capacity);
void enqueue(Queue *q, int num);
int dequeue(Queue *q);
void free_Queue(Queue *q);