#include<stdio.h>
#include "treenode.h"
#include "queue.h"

int* largestindex(TREENODE *root){
    QUEUE record;
    record.head=NULL;
    record.rear = NULL;
    record.size =0 ;
    push(&record,root);
    int *output = (int*) malloc(5*sizeof(int));
    int row =0;
    while(!empty(&record)){
        int sz = size(&record);
        int value = 0;
        while(sz--){
            TREENODE *current = record.head->data;
            if(current->data>value) value = current->data;
            pop(&record);
            if(current->left) push(&record,current->left);
            if(current->right) push(&record,current->right);
        }
        output[row++] = value;
    }
    return output;
}
int main(){
    TREENODE *root = newTREENODE(1);
    root->left = newTREENODE(3);
    
    root->left->left = newTREENODE(5);
    root->left->left->left = newTREENODE(10);
    root->left->left->left->left = newTREENODE(20);

    // root->left->right = newTREENODE(3);
    // root->right = newTREENODE(2);
    // root->right->right = newTREENODE(9);
    int *rowlarge = largestindex(root);
    for(int i=0;i<5;i++){
        printf("Max element of row : %d is %d \n",i+1,rowlarge[i]);
    }
    

    return 0;
}