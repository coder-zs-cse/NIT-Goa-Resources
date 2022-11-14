



// Write  a  C++  program  to  create  a  QUEUE  class  with  member  functions  to  add  an 
// element  and  delete  an  element  from  the  queue.  Using  these  member  functions, 
// implement a queue of integers and doubles. Demonstrate the operations by displaying 
// the contents of the queue after every operation.


#include<iostream>
using namespace std;

class NODE{
    public:
    int data;
    NODE *next;
    NODE(int value){
        data=value;
        next=NULL;
    }
};

class QUEUE{
    public:
    int size;
    NODE *head;
    NODE *tail;
    QUEUE(){
        size=0;
        head=NULL;
        tail=NULL;
    }
    void insert_element(int);
    void delete_element();
    void print_queue();
};

void QUEUE::insert_element(int value){
    NODE *newnode = new NODE(value);
    if(head!=NULL) 
        head->next=newnode;
    head=newnode;
    if(tail==NULL) tail = newnode;
    size++;
}
void QUEUE::delete_element(){
    if(tail==NULL) {
        cout<<"QUEUE is empty, deletion not possible\n";
        return;
    }
    NODE *temp=tail;
    if(head==tail){
        head=tail=NULL;
    }
    else {
        tail = tail->next;
    }
    size--;
    delete temp;
}
void QUEUE::print_queue(){
    if(tail==NULL){
        cout<<"Currently, queue is empty\n";
        return;
    }
    NODE *temp=tail;
    cout<<"QUEUE : ";
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}


int main(){
    QUEUE queue;
    int choice;
    while(1){
        printf("Press 1 to insert element into the queue\n");
        printf("Press 2 to delete an element of a queue\n");
        printf("Press 0 to exit the program\n");
        cin>>choice;
        switch(choice){
            case 1: cout<<"Enter the value of the element you want to insert\n";
                int element;cin>>element;
                queue.insert_element(element);
            break;
            case 2:
                queue.delete_element();
            break;
            case 0: goto out;
            default:
                printf("Invalid entry, please check the menu and try again\n");
        
        }
        queue.print_queue();
    }
    out:
    return 0;
}