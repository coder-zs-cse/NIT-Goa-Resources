#include<stdio.h>
#include<stdlib.h>  //changes 
typedef struct node{
    int data;
    struct node *next;
}NODE;
typedef struct stack{
    NODE *head;
}STACK;

void push(STACK *st,int element){
    NODE *current = (NODE*) malloc(sizeof(NODE));
    current->data = element;
    current->next = st->head;
    st->head = current;
}
int empty(STACK *st){
    return st->head==NULL ? 1:0;
}
int pop(STACK*st){
    if(st->head==NULL){
        printf("STACK underflow\n");
        return -1;
    }
    int store = st->head->data;
    NODE *temp = st->head;
    st->head = st->head->next;
    free(temp);
    return store;
}
int top(STACK *st){
    if(st->head==NULL){
        printf("STACK empty\n");
        return -1;
    }
    return st->head->data;
}
void sort_using_stack(int *arr,int n){
    STACK main;
    STACK temp;
    main.head = temp.head = NULL;   // changes
    for(int i=0;i<n;i++){
        int current = arr[i];
        while(!empty(&main) && top(&main)< current){
            push(&temp,pop(&main));
        }
        push(&main,current);
        while(!empty(&temp)){
            push(&main,pop(&temp));
        }

    }
    for(int i=0;i<n;i++){
        arr[i] = pop(&main);
    }
    
}
int main(){
    int n;
    scanf("%d",&n);
    int *arr = (int*) malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    sort_using_stack(arr,n);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}