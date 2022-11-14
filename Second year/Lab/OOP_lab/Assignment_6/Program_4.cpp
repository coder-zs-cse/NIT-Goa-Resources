#include<iostream>
using namespace std;
class NODE{
    public:
    int data;
    NODE *next;
    NODE(int);
};
class LIST{
    NODE *head;
    public:
    LIST();
    LIST operator+(int);
    LIST operator-(int);
    bool operator==(LIST&); 
    LIST operator--(int);
    friend ostream&operator>>(ostream&,LIST&);
};

int main(){
    int choice,element;
    LIST list;
    for(;;)
    {
        cout<<"\n1.Insert element at front\n";
        cout<<"2.Pop a particular element from list\n";
        cout<<"3.Remove duplicates from list\n";
        cout<<"-1. Exit\n";
        cin>>choice;
        switch (choice)
        {
            case 1: 
                    cout<<"Enter the value to insert\n";
                    cin>>element;
                    list = list + element;
            break;

            case 2: 
                    cout<<"Enter the value of the element to delete\n";
                    cin>>element;
                    list = list - element;
            break;

            case 3: 
                    list--;
            break;
            case -1:
                    goto out;
        default:
                cout<<"Invalid entry please check the menu and try again\n";
        }
        cout>>list;
    }
    out:

    return 0;
}





NODE::NODE(int element){
    data=element;
    next=NULL;
}
LIST::LIST(){
    head=NULL;
}
LIST LIST::operator+(int element){   //add the elemenet at the start of the list
    NODE *current = new NODE(element);
    current->next = head;
    head=current;
    return *this;
}
LIST LIST::operator-(int element){
    NODE *temp = head, *prev=NULL;
    while(temp!=NULL){
        if(temp->data==element){   //if element found, delete it
            if(temp==head) head=head->next;
            else prev->next = temp->next;
            delete temp;
            return *this;
        }
        prev=temp;
        temp=temp->next;
    }
    cout<<"Element was not found\n";
    return *this;
}
bool LIST::operator==(LIST &list){
    NODE *temp1=head,*temp2=list.head;
    while(temp1!=NULL && temp2!=NULL){ 
        if(temp1->data!=temp2->data) return false;   //if elements are not equal then return false;
        temp1=temp1->next;
        temp2=temp2->next;
    }
    if(temp1!=NULL || temp2!=NULL) return false;     //if size of both list is not equal  
    return true;
}

LIST LIST::operator--(int x){
    NODE *temp=head;
    while(temp!=NULL){
        NODE *temp2=temp->next,*prev=temp;
        int current_val = temp->data;   // checking if current element is there in further parts of linkedlist

        while(temp2!=NULL){
            if(temp2->data==current_val){ //if duplicate found, delete the node and move forward
                prev->next=temp2->next;
                delete temp2;
                temp2=prev->next;
            }
            else{ //just move forward
                prev = temp2;
                temp2=temp2->next;
            }
        }
        temp=temp->next; //check duplicacy for next element
    }
    return *this;
}
ostream&operator>>(ostream& print,LIST &list){//printing the elements of the list
    NODE *temp=list.head;
    print<<endl;
    while(temp!=NULL){
        print<<temp->data<<" ";
        temp=temp->next;
    }
    print<<endl;
    return print;
}