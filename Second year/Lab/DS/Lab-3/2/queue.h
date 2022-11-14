#include<stdlib.h>
typedef struct NOD{
    TREENODE* data;
    struct NOD *next;
}NODE;
typedef struct{
    NODE *head;
    NODE *rear;
    int size;
}QUEUE;
int size(QUEUE *head){
    return head->size;
}
void push(QUEUE *root,TREENODE* data){
    NODE *current  = (NODE*) malloc(sizeof(NODE));
    current->data = data;
    if(root->rear==NULL)   root->head = current;
    else root->rear->next = current;
    root->rear = current;
    current->next = NULL;
    root->size++;
}
void pop(QUEUE *root){
    if(root->head==root->rear){
        root->head = root->rear = NULL;
    }
    else root->head = root->head->next;
    root->size--;
}

TREENODE* front(QUEUE *root){
    return root->head->data;
}
int empty(QUEUE *root){
    return root->size==0;
}