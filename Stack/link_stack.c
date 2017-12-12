//
// Created by anany on 12/12/2017.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
    struct stack *next;
    int value;
} Stack;

typedef struct link_stack {
    struct stack *top;
    int length;
} LinkStack;

LinkStack *createLinkStack() {
    LinkStack *linkStack = malloc(sizeof(LinkStack));
    linkStack->length = 0;
    linkStack->top = NULL;
    return linkStack;
}

int push(LinkStack *linkStack, int value) {

    Stack *topStack = linkStack->top;

    Stack *newStack = malloc(sizeof(Stack));
    newStack->value = value;

    if (topStack == NULL) {
        newStack->next = NULL;
    } else {
        newStack->next = topStack;
    }

    linkStack->top = newStack;
    linkStack->length++;

    return 1;
}

int pop(LinkStack *linkStack, int *value) {

    Stack *topStack = linkStack->top;
    if (topStack == NULL) {
        printf("当前为空栈");
        return 0;
    }
    *value = topStack->value;

    Stack *prevStack = topStack->next;
    if (prevStack != NULL) {
        linkStack->top = prevStack;
    }
    free(topStack);
    linkStack->length--;

    return 1;
}
