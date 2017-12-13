#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct node {
    int value;
    struct node *next;
} Node;

typedef struct node_list {
    Node *head;
} NodeList;

NodeList *createNodeList() {
    NodeList *nodeList = malloc(sizeof(NodeList));
    Node *headNode = malloc(sizeof(Node));
    headNode->next = NULL;
    headNode->value = 0;
    nodeList->head = headNode;
    return nodeList;
}

int insert(NodeList *nodeList, int value) {
    Node *headNode = nodeList->head;

    Node *newNode = malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = headNode->next;

    headNode->next = newNode;
    return TRUE;
}

void reverse(NodeList *nodeList) {
    Node *p = nodeList->head->next;
    Node *temp = NULL;
    nodeList->head->next = NULL;    // 切断头节点和后面的关系，相当于初始化链表

    while (p != NULL) {
        temp = p;
        p = p->next;
        temp->next = nodeList->head->next;
        nodeList->head->next = temp;
    }
}

int main(void) {

    NodeList *nodeList = createNodeList();
    insert(nodeList, 12);
    insert(nodeList, 5);
    insert(nodeList, 6);
    insert(nodeList, 7);

    reverse(nodeList);

    Node *temp = nodeList->head->next;
    while (temp != NULL) {
        printf("%d\n", temp->value);
        temp = temp->next;
    }

    return 0;
}