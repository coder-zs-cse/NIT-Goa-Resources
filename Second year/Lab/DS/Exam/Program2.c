#include<stdio.h>
#include<stdlib.h> //changes
int min(int a,int b) {return a<b ? a:b;}  // changes
int max(int a,int b) {return a>b ? a:b;}  // changes

typedef struct nod{
    int data;
    struct nod *next;
}NODE;
typedef struct list{
    NODE *head;
}LIST;

void insert(LIST *li,int element){                 // changes
    NODE *current = (NODE*) malloc(sizeof(NODE));
    current->data = element;
    current->next  = li->head;
    li->head = current;
}
void find_small_large(LIST *li,int *small, int *large){
    NODE *temp = li->head;
    *small = temp->data;
    *large = temp->data;
    while(temp!=NULL){
        *small = min(*small,temp->data);
        *large = max(*large,temp->data);
        temp = temp->next;
    }
}
int main(){
    LIST li;
    li.head = NULL;
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int element;
        scanf("%d",&element);
        insert(&li,element);
    }
    int small,large;
    find_small_large(&li,&small,&large);
    printf("Smallest element: %d\n Largest element: %d",small,large);
    return 0;
}