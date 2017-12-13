//
// Created by anany on 13/12/2017.
//

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct node {
    int value;
    struct node *prev;
    struct node *next;
} Node;

typedef struct node_list {
    int size;
    Node *head;
} NodeList;

NodeList *createNodeList() {

    NodeList *nodeList = malloc(sizeof(NodeList));
    nodeList->size = 0;
    nodeList->head = createNode(0);

    return nodeList;
}

Node *createNode(int value) {
    Node *node = malloc(sizeof(Node));
    node->value = value;
    node->prev = NULL;
    node->next = NULL;

    return node;
}

int insert(NodeList *nodeList, int value) {

    Node *newNode = createNode(value);
    newNode->value = value;
    newNode->next = nodeList->head->next;
    if (newNode->next != NULL) {
        newNode->next->prev = newNode;
    }
    newNode->prev = nodeList->head;
    nodeList->head->next = newNode;

    nodeList->size++;

    return TRUE;
}

int delete(NodeList *nodeList, int value) {
    Node *temp = nodeList->head->next;
    while (temp != NULL) {
        if (temp->value == value) {
            temp->prev->next = temp->next;
            nodeList->size--;
            free(temp);
            return TRUE;
        }
        temp = temp->next;
    }
    return FALSE;
}



