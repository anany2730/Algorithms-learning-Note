//
// Created by anany on 07/12/2017.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct stack {

    int *arr;
    int top;
    int lenth;

} Stack;

Stack *initStack(int len) {

    Stack *stack = malloc(sizeof(Stack));
    stack->arr = (int *) malloc(sizeof(int) * len);
    stack->lenth = len;
    stack->top = -1;

    return stack;
}

int push(Stack *stack, int value) {

    stack->arr[++stack->top] = value;

    return 1;
}

int pop(Stack *stack, int *value) {
    *value = stack->arr[stack->top--];
    return 0;
}


int is_full(Stack *stack) {

    if (stack->top > stack->lenth) {
        return 0;
    }

    return 1;
}