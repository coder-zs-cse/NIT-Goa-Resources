#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node(int val){
        data=val;
        next=NULL;
    }
};
class stack{
    Node *head;
    public:
    stack(){
        head=NULL;
    }
    void push(int element){
        Node *current=new Node(element);
        current->next=head;
        head=current;
    }
    void pop(){
        Node *temp=head;
        head=head->next;
        delete temp;
    }
    bool empty(){
        return head==NULL;
    }
    int top(){
        if(this->empty()) return -1;
        return head->data;
    }
};
int rainwater_algo(int *arr,int n){
    stack water;
    
}
int main(){
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int rainwater = rainwater_algo(arr,n);
}