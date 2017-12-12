//
// Created by anany on 11/12/2017.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct queue {
    struct queue *next;
    int value;
} Queue;

typedef struct link_queue {
    Queue *head;
    Queue *tail;
    int length;
} LinkQueue;

LinkQueue *createLinkQueue() {

    Queue *queue = malloc(sizeof(Queue));
    queue->next = NULL;
    queue->value = 0;

    LinkQueue *linkQueue = malloc(sizeof(LinkQueue));
    linkQueue->head = queue;
    linkQueue->tail = queue;
    linkQueue->length = 0;

    return linkQueue;
}

int insert(LinkQueue *linkQueue, int value) {

    Queue *tailLinkQueue = linkQueue->tail;

    Queue *newQueue = malloc(sizeof(Queue));
    newQueue->value = value;
    newQueue->next = NULL;

    if (linkQueue->length == 0) {   // 空队列
        linkQueue->head = newQueue;
    } else {
        tailLinkQueue->next = newQueue;
    }
    linkQueue->tail = newQueue;
    linkQueue->length++;

    return 1;
}

int delete(LinkQueue *linkQueue, int *value) {

    if (linkQueue->length == 0) {
        return 0;
    }
    Queue *headQueue = linkQueue->head;     // 头节点
    *value = headQueue->value;
    Queue *nextQueue = headQueue->next;     // 头节点的下一个节点
    linkQueue->head = nextQueue;

    linkQueue->length--;
    free(headQueue);

    return 1;
}


