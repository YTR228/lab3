#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int *data;
    int front;
    int rear;
    int size;
    int capacity;
} Queue;


void init_Queue(Queue *q, int capacity) {
    q ->capacity = capacity;
    q ->data = malloc(capacity * sizeof(int));
    if (q -> data == NULL){
        printf("Memory allocation failed\n");
        exit(1);
    }    
    q -> front = 0;
    q -> size = 0;
    q -> rear = 0;
}


void enqueue(Queue *q, int num){
    if (q->size == q->capacity){
        int *new_data = malloc(q->capacity *2 * sizeof(int));
        if (new_data == NULL){
            printf("Memory allocation failed\n");
            exit(1);
        }
        for (int i = 0; i< q->size; i++){
            new_data[i] = (q->data)[(q->front + i) % q->capacity];
        }
        free(q->data);
        q->data = new_data;
        q->front = 0;
        q-> rear = q->size;
        q->capacity *=2;
        }
    q-> data[q->rear] = num;
    q->rear = (q->rear +1)%q->capacity;
    q->size +=1;
}
