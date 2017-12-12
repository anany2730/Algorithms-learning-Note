//
// Created by anany on 10/12/2017.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct queue {

    int *arr;
    int lenth;
    int head;
    int tail;
} Queue;

Queue *initQueue(int length) {
    Queue *queue = malloc(sizeof(Queue));
    queue->arr = malloc(sizeof(int) * length);
    queue->head = 0;
    queue->tail = 0;
    queue->lenth = length;
    return queue;
}

int push(Queue *queue, int value) {
    queue->arr[queue->tail] = value;
    queue->tail = (++queue->tail) % queue->lenth;
    return 1;
}

int pop(Queue *queue, int *value) {
    *value = queue->arr[queue->head];
    queue->head = ++queue->head % queue->lenth;
    return 1;
}


