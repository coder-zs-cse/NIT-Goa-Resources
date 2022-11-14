#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}NODE;

typedef struct list{
    NODE *head;
}STACK;

void push(STACK *stack,int ele){
    NODE *current = (NODE*) malloc(sizeof(NODE));
    current->data = ele;
    current->next = stack->head;
    stack->head = current;
}
void pop(STACK *stack){
    stack->head = stack->head->next;
}
int peek(STACK *stack){
    if(stack->head==NULL) return -1;
    return stack->head->data;
}
int isempty(STACK *stack){
    return stack->head==NULL;
}

void sort_array_using_stack(int *arr,int n){
    STACK main_stack;
    main_stack.head = NULL;
    STACK temp_stack;
    temp_stack.head = NULL;

    for(int i=0;i<n;i++){
        int current = arr[i];
        while(!isempty(&main_stack) && current > peek(&main_stack)){
            int value = peek(&main_stack);
            pop(&main_stack);
            push(&temp_stack,value);
        }
        push(&main_stack,current);
        while(!isempty(&temp_stack)){
            int value = peek(&temp_stack);
            push(&main_stack,value);
            pop(&temp_stack);
        }
    }
    for(int i=0;i<n;i++){
        arr[i] = peek(&main_stack);
        pop(&main_stack); 
    }
}


int main() {
    
    int n;
    scanf("%d",&n);
    int *arr = (int*) malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    sort_array_using_stack(arr,n);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }


    
    return 0;
}