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
class LIST{
    public:
    int size;
    NODE *head;
    LIST(){
        size=0;
        head=NULL;
    }
    void insert_element(int);
    void delete_element();
    void print_list();
};

void LIST::insert_element(int value){
    NODE *newhead = new NODE (value);
    newhead->next = head;
    head = newhead;
    size++;
}
void LIST::delete_element(){
    if(size==0){
        cout<<"LIST is empty, element could not be deleted\n";
    }
    else{
        NODE *temp= head;
        head = head->next;
        size--;
        delete temp;
    }
}
void LIST::print_list(){
    NODE *temp=head;
    if(size==0){
        cout<<"LIST is empty\n";
        return;
    }
    cout<<"LIST : ";
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main(){
    int choice;
    LIST list;
    while(1){
        cout<<"Press 1 to insert an element into the list\n";
        cout<<"Press 2 to delete an element into the list\n";
        cout<<"Press 0 to exit\n";
        cin>>choice;
        switch(choice){
            case 1: 
                printf("Enter the value of the element\n");
                int value;cin>>value;
                list.insert_element(value);
            break;
            case 2:
                list.delete_element();
            break;
            case 0: goto out;
            default: 
                cout<<"Invalid entry, please check the menu and try again\n";
        }
        list.print_list();

    }
    out:
    return 0;
}