#include<stdio.h>
#include<stdlib.h>
#define take(n) int n;scanf("%d",&n)

typedef struct nod{
    int data;
    struct nod *next;
}node;

typedef struct stac{
    node *head;

}stack;
void initializestack(stack *st){
    st->head = NULL;
}

int top(stack st){
    if(st.head==NULL) {
        printf("\nError! Stack underflow\n");
        return -1;
    }
    return st.head->data;
}
void push(stack *st,int element){
    node *newnode=(node*) malloc(sizeof(node));
    newnode->data=element;
    newnode->next=st->head;
    st->head=newnode;
}
void pop(stack *st){
    if(st->head==NULL) {
        printf("\nError! Stack underflow\n");
    }
    else{
        node *prevnode = st->head->next;
        free(st->head);
        st->head=prevnode;
    }
}
int main(){
    stack st;
    int value,element;
    initializestack(&st);
    do{
        printf("Press 1 to get the top of the stack\n");
        printf("Press 2 to push a element in the stack\n");
        printf("Press 3 to pop a element from the top of the stack\n");
        printf("Press any other number to exit\n");
        take(choice);
        switch(choice){
            case 1: 
                value=top(st);
                if(top!=-1)   printf("The top element of the stack is %d\n",value);
                break;
            case 2: 
                printf("Enter the element you want to insert\n");
                scanf("%d",&element);
                push(&st,element);
                break;
            case 3: 
                pop(&st);
                break;
            default:
                 exit(0);
        }
        
    }while(1);
return 0;
}