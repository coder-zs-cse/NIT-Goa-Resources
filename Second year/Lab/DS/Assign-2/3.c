#include<stdio.h>
#include<stdlib.h>
#define take(n) scanf("%d", &n);
#define rep(i, a, b) for (int i = a; i < b; i++)
#define SIZE 100

int arr[SIZE];
int front=-1;
int rear=-1;

void Enqueue(){              //O(1)
if((front==0&&rear==SIZE-1)||(rear+1==front)){
 printf("Queue is Overflow\n");
}
else
{
 printf("Enter the element you wish to insert:\n");
 int x;
 take(x);
 if(rear==-1){
     front=0;
     rear=0;
 }
 else if(rear==SIZE-1){
     rear=0;
 }
 else rear++;
 arr[rear]=x;

}

}

void Dequeue(){//O(1)
    int a;
    if(front==-1){
printf("Queue is underflow\n");
return;
    }
    else{
a=arr[front];
if(front==rear){
    front=-1;
    rear=-1;
}
else if(front==SIZE-1){
    front=0;
}
else{
    front++;
}
printf("Dequeued element is :%d\n",a);
    }
}

void displayQueue(){
    int i,j;
    if(front==-1&&rear==-1){
printf("Queue is underflow\n");

    }
    else
    {
    
    
    printf("The Queue is:\n");
    if(front>rear){
        rep(i,front,SIZE){
            printf("%d ",arr[i]);
        }
        rep(j,0,rear+1){
            printf("%d ",arr[j]);

        }
    }
    else{
       rep(i,front,rear+1){
            printf("%d ",arr[i]);

        }

    }
 printf("\n");
    }
}


int main(){
;

int choice=0;
do{
        printf("----------------------------------------------------------------------------------\n\n");
        printf("Enter 1 to input element inside queue\n");
        printf("Enter 2 to delete the element from the queue\n");
        printf("Enter 3 to display the queue\n");
        printf("Enter any other number to exit\n\n");
        printf("----------------------------------------------------------------------------------\n");
        take(choice);
switch (choice)
{
case 1:
Enqueue();
break;
case 2:
Dequeue();
break;
case 3:
displayQueue();
    break;

default:
   exit(0);
    break;
}



}while(choice);

return 0;

}