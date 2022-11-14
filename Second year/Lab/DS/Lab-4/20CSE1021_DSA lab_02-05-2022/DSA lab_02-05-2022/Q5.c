#include<stdio.h> 
#include<stdlib.h>
typedef struct Node 
{ 
    int data; 
    struct Node* left, *right; 
}Node; 

Node* getNode(int data) 
{ 
    Node* newNode = (Node*)malloc(sizeof(Node)); 
    newNode->data = data; 
    newNode->left = newNode->right = NULL; 
    return newNode; 
} 
void sumOfLongRootToLeafPath(Node* root, int current_sum, int len, int *maxLen, int *maxSum) 
{  
    if (!root) { 
        if (len > *maxLen) { 
            *maxLen = len; 
            *maxSum = current_sum; 
        } 
        else if (*maxLen == len && current_sum > *maxSum) 
            *maxSum = current_sum; 
        return; 
    } 
  
    sumOfLongRootToLeafPath(root->left, current_sum + root->data,len + 1, maxLen, maxSum); 

    sumOfLongRootToLeafPath(root->right, current_sum + root->data,len + 1, maxLen, maxSum); 
} 
  

int sumOfLongRootToLeafPathUtil(Node* root) 
{ 
    if (!root) return 0; 
    int maxSum = 0, maxLen = 0; 
    sumOfLongRootToLeafPath(root, 0, 0, &maxLen, &maxSum); 
    return maxSum; 
} 
  

int main() 
{ 
    Node* root = getNode(4);     
    root->left = getNode(2);       
    root->right = getNode(5);      
    root->left->left = getNode(7);   
    root->left->right = getNode(1);  
    root->right->left = getNode(2);  
    root->right->right = getNode(3);
    root->left->right->left = getNode(6); 
    int sum = sumOfLongRootToLeafPathUtil(root); 
    printf("Required Sum : %d",sum);
  
    return 0; 
} 