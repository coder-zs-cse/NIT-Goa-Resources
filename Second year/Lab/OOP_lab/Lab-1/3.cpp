#include<iostream>
using namespace std;
typedef struct{
    int data;
    TREE_NODE *left;
    TREE_NODE *right;
}TREE_NODE;

class BIN_TREE{
    TREE_NODE *root;
    public:
    BIN_TREE();
    void print_preorder(TREE_NODE*);
    void print_postorder(TREE_NODE*);
    void print_inorder(TREE_NODE*);
    void operator+(int)
};
int main(){
    return 0;
}
void BIN_TREE::print_inorder(TREE_NODE *current = NULL){
    if(current==NULL) current = root;
    if(current->left) print_inorder(current->left);
    cout<<current->data<<" ";
    if(current->right) print_inorder(current->right);
}
void BIN_TREE::print_preorder(TREE_NODE *current = NULL){
    if(current==NULL) current = root;
    cout<<current->data<<" ";
    if(current->left) print_inorder(current->left);
    if(current->right) print_inorder(current->right);
}
void BIN_TREE::print_postorder(TREE_NODE *current = NULL){
    if(current==NULL) current = root;
    if(current->left) print_inorder(current->left);
    if(current->right) print_inorder(current->right);
    cout<<current->data<<" ";
}