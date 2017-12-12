

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0


typedef struct Node {
    struct Node * link;
    int value;
} Node;

int insert(Node ** root,int new_value){
    
    Node * temp = *root;
    Node * prev = NULL;
    
    while (temp != NULL && temp->value < new_value) {
            prev = temp;
            temp = temp->link;
    }
    
    Node * new = malloc(sizeof(Node));
    new->value = new_value;
    new->link = temp;
    
    if (prev == NULL){
        *root = new;
    } else {
        prev->link = new;
    }
    
    return TRUE;
}

int delete(Node ** rootTemp,int value){
    
    if(rootTemp == NULL){
        return FALSE;
    }
    
    Node * current = * rootTemp;
    
    Node * prev = NULL;
    while (current != NULL && current->value != value){
        prev = current;
        current = current->link;
    }
    
    if(current == NULL){
        return FALSE;
    }
    
    if(prev == NULL){
        *rootTemp = current->link;
    } else {
        prev->link = current->link;
    }
    
    free(current);
    
    return TRUE;
}

int main(void) {
    
    Node * root = NULL;
    insert(&root,5);
    insert(&root,15);
    insert(&root,8);
    insert(&root,2);
    
    Node * temp = root;
    while (temp != NULL) {
        printf("%d\n",temp->value);
        temp = temp->link;
    }
    
    return 0;
}
