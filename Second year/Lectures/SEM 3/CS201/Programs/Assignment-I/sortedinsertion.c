#include<stdio.h>
#include<stdlib.h>
#define take(n) scanf("%d",&n);
#define rep(i,a,b) for(int i=a;i<b;i++)

typedef struct nod{
    int data;
    struct nod *next;
}node;

void insert_sorted(node **head,node *element){
    node *temp=*head,*prev;
    while(temp!=NULL && element->data>temp->data){
        prev=temp;
        temp=temp->next;
    }
    if(temp!=*head){
    prev->next=element;
    element->next=temp;
    }
    else {
        element->next=*head;
        *head=element;
    }
}

node *takesortedinput(){
    node *head=NULL,*temp;
    printf("Enter the number of elements in the linkedlist : ");
    int n;
    take(n);
    rep(i,0,n){
        node *element=(node *) malloc(sizeof(node));
        printf("Enter the value of element no %d : ",i+1);
        int value;
        take(value);
        element->data=value;
        element->next=NULL;
        if(head==NULL) head=element;
        else insert_sorted(&head,element);
    }
    return head;
}

void printlinkedlist(node *head){
    printf("Sorted Linkedlist : ");
    node *temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
void delete_linkedlist(node **head){
    node *temp=*head;
    while(*head!=NULL){
        temp=*head;
        *head=(*head)->next;
        free(temp);
    }
}
int main()
{
    printf("\n");
    node *node1=takesortedinput();
    printlinkedlist(node1);
    delete_linkedlist(&node1);
return 0;
}