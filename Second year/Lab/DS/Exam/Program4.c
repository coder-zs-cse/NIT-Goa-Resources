#include<stdio.h>
#include<stdlib.h> // changes 
#include<limits.h>
int min(int a,int b) {return a<b ? a:b;}  // changes

typedef struct treenode{
    int data;
    struct treenode *left;
    struct treenode *right;
}TREENODE;
typedef struct tree{
    TREENODE *root;
}TREE;

TREENODE* newtreenode(int element){
    TREENODE *current = (TREENODE*) malloc(sizeof(TREENODE));
    current->data = element;
    current->left = current->right  = NULL;
    return current;
}
void min_level(TREENODE *root,int *level,int current){
    if(root==NULL) return ;
    if(root->left ==NULL && root->right==NULL){
        *level = min(*level,current);
        return;
    }
    min_level(root->left,level,current+1);
    min_level(root->right,level,current+1);
}

void sum_at_level(TREENODE *root,int *sum,int current,int level){
    if(root==NULL) return;
    if(root->left==NULL && root->right==NULL){
        if(current!=level) return;
        else {
            *sum = *sum + root->data;
            return;
        }

    }
    sum_at_level(root->left,sum,current+1,level);
    sum_at_level(root->right,sum,current+1,level);
}
int sum_at_min_level(TREE *tr){
    int level = INT_MAX;
    min_level(tr->root,&level,0);
    int sum=0;
    sum_at_level(tr->root,&sum,0,level);  // changes
    return sum;
}
int main(){
    TREE tr; // changes
    tr.root = NULL;      // changes
    tr.root  = newtreenode(1);     // changes
    tr.root->left = newtreenode(2);     // changes
    tr.root->left->left = newtreenode(4);     // changes
    tr.root->left->right = newtreenode(5);     // changes
    // tr.root->left->right->left = newtreenode(8);     // changes
    tr.root->right = newtreenode(3);     // changes
    tr.root->right->left = newtreenode(6);     // changes
    tr.root->right->right = newtreenode(7);     // changes
    tr.root->right->left->right = newtreenode(9);     // changes
    
    int sum = sum_at_min_level(&tr);
    printf("Sum at minimum level is %d",sum);
    return 0;
}