#include<stdio.h>
#include<stdlib.h>
#define take(n) scanf("%d",&n);
#define rep(i,a,b) for(int i=a;i<b;i++)

typedef struct nod{
    int degree;
    int coeff;
    struct nod* next;
}node;

void insert_node(node **head,node *current){
    node *temp=*head,*prev;

    while(temp!=NULL && temp->degree>=current->degree){
        prev=temp;
        temp=temp->next;
    }
    if(temp!=*head){
    prev->next=current;
    current->next=temp;
    }
    else{
        current->next=*head;
        *head=current;
    }

}

node *takeinput(){
    node *head=NULL;
    printf("Enter the number of terms in the polynomial: ");
    int n;
    take(n);
    rep(i,0,n){
        printf("Degree: ");
        int deg;
        take(deg);
        node *current=(node *) malloc(sizeof(node));
        printf("Coefficient of degree %d: ",deg);
        int cof;
        take(cof);
        current->next=NULL;
        current->degree=deg;
        current->coeff=cof;
        if(head==NULL) head=current;
        else insert_node(&head,current);
    }
    return head;
}

void printpoynomial(node *head){
    node *temp=head;
    int first=1;
    while(temp!=NULL){
        if(first==1) first=0;
        else printf(" + ");
        if(temp->degree!=0) printf("%dx^%d",temp->coeff,temp->degree);
        else printf("%d",temp->coeff);
        temp=temp->next;
    }
    printf("\n");
}

void poly_add(node *poly1,node *poly2,node **poly3){
    *poly3=NULL;
    node *temp1=poly1;
    node *temp2=poly2;
    node *temp;
    while(temp1!=NULL && temp2!=NULL){
        node *current=(node*) malloc(sizeof(node));
        if(temp1->degree>temp2->degree){
            current->coeff=temp1->coeff;
            current->degree=temp1->degree;
            temp1=temp1->next;
        }
        else if(temp1->degree<temp2->degree){
            current->coeff=temp2->coeff;
            current->degree=temp2->degree;
            temp2=temp2->next;
        }
        else {
            current->coeff=temp1->coeff+temp2->coeff;
            current->degree=temp1->degree;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        current->next=NULL;
        if(*poly3==NULL) {
            *poly3=current;
            temp=current;
        }
        else {
            temp->next=current;
            temp=temp->next;
        }
    }
    while(temp1!=NULL){
            node *current=(node*) malloc(sizeof(node));
            current->coeff=temp1->coeff;
            current->degree=temp1->degree;
            temp1=temp1->next;
        if(*poly3==NULL) {
            *poly3=current;
            temp=current;
        }
        else {
            temp->next=current;
            temp=temp->next;
        }
            current->next=NULL;
    }
    while(temp2!=NULL){
            node *current=(node*) malloc(sizeof(node));
            current->coeff=temp2->coeff;
            current->degree=temp2->degree;
            temp2=temp2->next;
        if(*poly3==NULL) {
            *poly3=current;
            temp=current;
        }
        else {
            temp->next=current;
            temp=temp->next;
        }
            current->next=NULL;
    }
}
void delete_poly(node **head){
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
    node *poly1=takeinput();
    node *poly2=takeinput();
    node *poly3;
    poly_add(poly1,poly2,&poly3);

    printf("First Polynomial : ");
    printpoynomial(poly1);

    printf("Second Polynomial : ");
    printpoynomial(poly2);

    printf("Sum of above two Polynomials : ");
    printpoynomial(poly3);

    delete_poly(&poly1);
    delete_poly(&poly2);
    delete_poly(&poly3);
return 0;
}