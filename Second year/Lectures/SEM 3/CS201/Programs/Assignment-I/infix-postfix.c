#include<stdio.h>
#define take(n) scanf("%d",&n);
#define rep(i,a,b) for(int i=a;i<b;i++)

typedef struct nod{
    char data;
    struct nod *next;
}node;

typedef struct stac{
    node *head;
    int number;
}stack;

void push(stack **st,char element){
    node *current=(node*) malloc(sizeof(node));
    current->data=element;
    current->next=NULL;
    // if((*st)->number==0){
    //    (*st)->head=current;
    // }
    // else{
        current->next=(*st)->head;
        (*st)->head=current;
        (*st)->number++;
    // }
}
void pop(stack **st){
    if((*st)->number==0) return;
    (*st)->head=(*st)->head->next;
    (*st)->number--;
}
char top(stack **st){
    if((*st)->number==0) return;
    return (*st)->head->data;
}
char *takeinput(char *infix){
    char *
    stack postfix;
    postfix.head=NULL;
    postfix.number=0;
    int i=0;
    while(infix[i]!='\0'){
        
    }
}
int main()
{
    char infix[100];
    gets(infix);
    
return 0;
}