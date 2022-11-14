#include<stdlib.h>
typedef struct TREEN{
    int data;
    struct TREEN *left;
    struct TREEN *right;
}TREENODE;

TREENODE* newTREENODE(int value){
    TREENODE *current  = (TREENODE*) malloc(sizeof(TREENODE));
    current->data = value;
    current->left = NULL;
    current->right = NULL;
    return current;
}