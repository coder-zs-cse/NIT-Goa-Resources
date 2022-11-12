/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *poly3=NULL;
    ListNode *temp1=poly1;
    ListNode *temp2=poly2;
    ListNode *temp;
    while(temp1!=NULL && temp2!=NULL){
        ListNode *current=(ListNode*) malloc(sizeof(ListNode));
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
            ListNode *current=(ListNode*) malloc(sizeof(ListNode));
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
            ListNode *current=(ListNode*) malloc(sizeof(ListNode));
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
        return poly3;
    }
};