#include<stdio.h>
#include<stdlib.h>
#define take(n) int n;scanf("%d",&n)
typedef struct nod{
    int data;
    struct nod *next;
}node;
typedef struct queu{
    node *front;
    node *rear;
}queue;
void initiailizequeue(queue *q){
    q->front=NULL;
    q->rear=NULL;
}
int front(queue q){
    if(q.front==NULL) {
        printf("\nError! Queue underflow\n");
        return -1;
    }
    return q.front->data;
}
void push(queue *q,int element){
    node *newnode= (node*) malloc(sizeof(node));
    newnode->data=element;
    newnode->next=NULL;
    if(q->front==NULL){
        q->front=newnode;
        q->rear=newnode;
    }
    else{
        q->rear->next=newnode;
        q->rear=newnode;
    }
}
void pop(queue *q){
    if(q->front==NULL){
        printf("\nError! Queue underflow\n");;
    }
    else{
        node *current=q->front;
        if(q->front==q->rear){
            q->rear=NULL;
        }
        q->front=q->front->next;
        free(current);
    }
}
int main(){
    queue q;
    int top,element;
    initiailizequeue(&q);
    do{
        printf("Press 1 to get the front of queue\n");
        printf("Press 2 to push a element in the queue\n");
        printf("Press 3 to pop a element from the queue\n");
        printf("Press any other number to exit\n");
        take(choice);
        switch(choice){
            case 1: 
                top=front(q);
                if(top!=-1)   printf("The top element of the stack is %d\n",top);
                break;
            case 2: 
                printf("Enter the element you want to insert\n");
                scanf("%d",&element);
                push(&q,element);
                break;
            case 3: 
                pop(&q);
                break;
            default:
                 exit(0);
        }
        
    }while(1);
return 0;
}