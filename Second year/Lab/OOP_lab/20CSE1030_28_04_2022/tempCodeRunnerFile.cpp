#include<iostream>
using namespace std;

typedef struct NODE{
    int data;
    NODE *next;
}NODE;
class LIST{
    NODE *head;
    public:
    LIST();
    LIST(const LIST&);
    LIST operator+(int);
    LIST operator-(int);
    bool operator==(LIST&);
    LIST operator++(int);
    LIST operator--(int);
    friend ostream& operator<<(ostream&,LIST&);
    friend ostream& operator<<(ostream&,const LIST&);
    ~LIST();
};
int main(){
    LIST l;
    int choice,ele;
    while(1){
        cout<<"1. L = L + ele\n";
        cout<<"2. L = L - ele\n";
        cout<<"3. L = L++ \n";
        cout<<"4. L = L--\n";
        cout<<"-1: Exit\n";
        cin>>choice;
        switch(choice){
            case 1: 
                    cout<<"Enter the value of the element\n";
                    cin>>ele;
                    l = l + ele;
            break;
            case 2:
                    cout<<"Enter the value of the element\n";
                    cin>>ele;
                    l = l - ele;
            break;
            case 3:
                    l = l++;
            break;
            case 4: 
                    l = l--;
            break;
            case -1:
                    goto out;
            default:
                    cout<<"Invalid entry\n";
        }
        break;
        cout<<"List: "<<l;
    }
    out:
    return 0;
}

LIST::LIST(){
    head=NULL;
}
LIST::LIST(const LIST& obj){
    this->head=NULL;
    NODE *temp = obj.head;
    NODE *connect;
    while(temp){
        NODE *current = new NODE;
        current->data = temp->data;
        current->next = NULL;
        if(this->head==NULL) this->head = current;
        else connect->next = current;
        connect = current;
        temp = temp->next;
    }
}
bool ispresent(NODE* chain,NODE *end,int key){
    NODE *temp = chain;
    while(temp!=end){
        if(temp->data==key) return true;
        temp = temp->next;
    }
    if(end!=NULL) return end->data == key ? 1:0;
    return false;
}
LIST LIST::operator--(int){
    NODE *distinct_head = NULL;
    NODE *distinct_connect = NULL;
    NODE *duplicate_head=NULL;
    NODE *duplicate_connect = NULL;
    NODE *temp = head;
    while(temp){
        if(ispresent(distinct_head,distinct_connect,temp->data)){
            if(!duplicate_connect) duplicate_head = temp;
            else duplicate_connect->next = temp;
            duplicate_connect = temp;
        }
        else{
            if(!distinct_connect) distinct_head = temp;
            else distinct_connect->next = temp;
            distinct_connect = temp;
        }
        NODE *store = temp->next;
        temp->next = NULL;
        temp = store;
    }
    distinct_connect->next  = duplicate_head;
    head = distinct_head;
    return *this;
}
LIST LIST::operator++(int){
    NODE *temp = head;
    while(temp){
        temp->data = temp->data +1;
        temp=temp->next;
    }
    return *this;
}
bool LIST::operator==(LIST &l2){
    NODE *temp1 = head;
    NODE *temp2 = l2.head;
    if(temp1 == NULL && temp2 == NULL) return true;
    if(temp1==NULL || temp2==NULL) return false;
    while(temp1 && temp2){
        if(temp1->data!=temp2->data) return false;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return temp1 || temp2 ? 0:1;
}
LIST LIST::operator-(int element){
    NODE *temp = head;
    NODE *prev= NULL;
    while(temp){
        if(temp->data==element){
            if(!prev) head=head->next;
            else prev->next = temp->next;
            delete temp;
            return *this;
        }
        prev=temp;
        temp=temp->next;
    }
    cout<<*this<<endl;
    return *this;
}
LIST LIST::operator+(int element){
    cout<<"No";
    NODE *current = new NODE;
    current->data = element;
    current->next = NULL;
    NODE *temp = head;
    if(!temp){
        head = current;
        cout<<"done"<<endl;
        return *this;
    }