#include<stdio.h>
#include<stdlib.h>
#define take(n) scanf("%d",&n);
#define rep(i,a,b) for(int i=a;i<b;i++)

typedef struct nod{
    int data;
    struct nod *next;
}node;

node* takeinput(){
    printf("Enter the number of elements in the linkedlist\n");
    int n;
    take(n);
    node *temp,*head=NULL;
    rep(i,0,n){
        node *current=(node*) malloc(sizeof(node));
        int value;
        printf("Enter the value of element no %d : ",i+1);
        take(value);
        current->data=value;
        current->next=NULL;
        if(i==0) head=current;
        else  temp->next=current;
        temp=current;
    }
    return head;
}

void printlinkedlist(node *head){

    node *temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

node *concatenate(node *node1,node *node2){
    node *head=NULL;
    node *temp,*prev;
    temp=node1;
     
    while(temp!=NULL){
        node *current=(node *) malloc(sizeof(node));
        current->data=temp->data;
        current->next=NULL;
        if(head==NULL) head=current;
        else prev->next=current;
        temp=temp->next;
        prev=current;
    }
    temp=node2;
    
    while(temp!=NULL){
        node *current=(node *) malloc(sizeof(node));
        current->data=temp->data;
        current->next=NULL;
        if(head==NULL) head=current;
        else prev->next=current;
        temp=temp->next;
        prev=current;
    }
    return head;
}
void delete_linkedlist(node **head){
    node *temp=*head;
    while(*head!=NULL){
        temp=*head;
        *head=(*head)->next;
        free(temp);
    }
}

//    node* delete_linkedlist(node *head){
//     node*ptr=head;
//     while(1){
//     if(head==NULL) return head;
//         head=head->next;
//         free(ptr);
//         ptr=head;
//     }
// }
int main()
{
    printf("\n");
    node *node1=takeinput();
    node *node2=takeinput();
    node *node3=concatenate(node1,node2);
    printf("\n");
    printf("First Linkedlist : ");
    printlinkedlist(node1);
    printf("Second Linkedlist : ");
    printlinkedlist(node2);
    printf("Concatenated Linkedlist : ");
    printlinkedlist(node3);
    delete_linkedlist(&node1);
    delete_linkedlist(&node2);
    delete_linkedlist(&node3);
return 0;
}