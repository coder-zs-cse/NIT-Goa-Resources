#include<iostream>
using namespace std;
 
typedef struct NOD{
    int data;
    struct NOD* next;
}NODE;


class LIST{
    NODE *head;
    public:
    LIST();
    LIST(const LIST&);
    void insert(int);
    bool ispresent(int);
    bool isequal(LIST&);
    LIST& operator+(int);
    LIST& operator-(int);
    LIST operator==(LIST&);
    LIST& operator++(int);
    void operator=(LIST);
    NODE* sort_ll(NODE*);
    bool empty();
    friend ostream& operator<<(ostream&,LIST&);
    ~LIST();
};
void build_list(LIST &l){
    int choice,ele;
    while(1){
        LIST l2,l3;
        cout<<"\n1. Insert an element into the LIST\n";
        cout<<"2. L = L + ele  (Add ele to all elements who are less than ele)\n";
        cout<<"3. L = L - ele  (remove the node from the list)\n";
        cout<<"4. L = L++ (convert negative values to positive and sort\n";
        cout<<"5. L3 = L1==L2 (concatenate the lists if equal)\n";
        cout<<"-1. Finish building list\n";
        cout<<"\nEnter you choice: ";
        cin>>choice;
        switch(choice){
            case 1: 
                    
                    cout<<"Enter the value of the element\n";
                    cin>>ele;
                    l.insert(ele);
            break;
            case 2:
                    if(l.empty()) cout<<">This operation cannot be performed on empty LIST<\n";
                    else {
                        cout<<"Enter the value of the element\n";
                        cin>>ele;
                        l = l + ele;
                    }

            break;
            case 3: 
                    if(l.empty()) cout<<"LIST is already empty\n";
                    else{
                        cout<<"Enter the value of the element\n";
                        cin>>ele;
                        l = l - ele;

                    }
            break;
            case 4:
                    if(l.empty()) cout<<">This operation cannot be performed on empty LIST<\n";
                    else l = l++;
            break;
            case 5: 
                    cout<<"\nTaking input for LIST 2\n";
                    build_list(l2);
                    cout<<"LIST 1: "<<l<<endl;
                    cout<<"LIST 2: "<<l2<<endl;
                    if(l.isequal(l2) && l2.isequal(l)){
                        l3 = l==l2;
                        cout<<"LIST 3: "<<l3<<endl;
                    }
                    else{
                        cout<<"\n>LIST L1 and L2 are not equal, so concatenation could not be processed<\n";
                    }
            break;
            case -1:
                    return;
            default:
                    cout<<"Invalid entry, please check the menu and try again\n";
        }
        cout<<"LIST: "<<l<<endl;
    }
    
}



int main(){

    LIST l;
    build_list(l);
    return 0;
}

LIST::LIST(){
    head = NULL;
}
LIST::LIST(const LIST& obj){
    head = NULL;
    NODE *temp = obj.head;
    NODE *connect = NULL;
    while(temp){
        this->insert(temp->data);
        temp = temp->next;
    }
}
bool LIST::empty(){
    return head==NULL;
}
void LIST::insert(int ele){
    NODE *current = new NODE;
    current->data = ele;
    current->next = NULL;
    NODE *temp = head;
    if(!temp) {
        head = current;
        return;
    }
    while(temp->next) temp = temp->next;
    temp->next = current;
}
bool LIST::ispresent(int element){
    NODE *temp = head;
    while(temp){
        if(temp->data == element) return true;
        temp = temp->next;
    }
    return false;
}
LIST& LIST::operator+(int ele){
    NODE *temp = head;
    while(temp){
        if(temp->data < ele) temp->data += ele; 
        temp = temp->next;
    }
    return *this;
}

LIST& LIST::operator-(int ele){
    NODE *temp = head;
    NODE *prev = NULL;
    while(temp){
        if(temp->data == ele) {
            if(prev) prev->next = temp->next;
            else head = temp->next;
            delete temp;
            return *this;
        }
        prev = temp;
        temp = temp->next;
    }
    cout<<"Element not found in the list\n";
    return *this;
}
bool LIST::isequal(LIST &l2){

    NODE *temp1 = head;
    while(temp1){
        if(!l2.ispresent(temp1->data)) {
            return false;
        }
        temp1 = temp1->next;
    }
    return true;
}
void LIST::operator=(LIST obj){
    this->head = NULL;
    NODE *temp = obj.head;
    while(temp){
        this->insert(temp->data);
        temp = temp->next;
    }
}
LIST LIST::operator==(LIST &obj){
    LIST output;
    if(!this->isequal(obj)) {
        return output;
    }

    NODE *temp = head;
    while(temp){
        output.insert(temp->data);
        temp = temp->next;
    }
    temp = obj.head;
    while(temp){
        output.insert(temp->data);
        temp = temp->next;
    }
    return output;
}

NODE* merge_sorted_list(NODE *list1,NODE *list2){
    if(!list1) return list2;
    if(!list2) return list1;
    if(list1->data<list2->data){
        list1->next = merge_sorted_list(list1->next,list2);
        return list1;
    }
    else {
        list2->next = merge_sorted_list(list1,list2->next);
        return list2;
    }
}
NODE* LIST::sort_ll(NODE *current){
    if(!current || !current->next) return current;
    NODE *slow = current;
    NODE *fast = current;
    NODE *prev = NULL;
    while(fast && fast->next){
        if(prev) prev = prev->next;
        else prev = current;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next = NULL;
    current = sort_ll(current); 
    slow = sort_ll(slow);
    return merge_sorted_list(current,slow);
}
LIST& LIST::operator++(int){
    NODE *temp = head;
    while(temp){
        if(temp->data<0) temp->data *= -1;
        temp = temp->next;
    }
    head = sort_ll(head);
    return *this;
}
ostream& operator<<(ostream &print, LIST &obj){
    
    NODE *temp  = obj.head;
    if(!temp) print<<" EMPTY";
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    return print;
}
LIST::~LIST(){
    NODE *temp = head;
    while(temp){
        NODE *store = temp->next;
        delete temp;
        temp = store;
    }
}