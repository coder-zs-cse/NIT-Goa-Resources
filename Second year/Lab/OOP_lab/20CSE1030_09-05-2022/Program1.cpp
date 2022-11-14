#include<iostream>
using namespace std;

class STACK{
    int size;
    int len;
    int *arr;
    public:
    STACK(int);
    friend STACK& operator+(int,STACK&);
    STACK& operator--(int);
    STACK& operator++(int);
    bool isfull();
    bool isempty();
    friend ostream& operator<<(ostream&, STACK&);
    ~STACK();
};

int main(){

    int size;
    while(1){
        cout<<"\nEnter the size of the stack: ";
        cin>>size;
        try{
            if(size<=0) throw size;
            break;
        }
        catch(int){
            cout<<"Error! Invalid size of stack\n";
        }
    }
    STACK s1(size);
    int choice,element;
    while(1){
        cout<<"\n1.  s1 = element + s1\n";
        cout<<"2.  s1 = s1--\n";
        cout<<"3.  s1 = s1++\n";
        cout<<"-1. exit\n";
        cout<<"\nPlease enter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                    if(s1.isfull()){
                        cout<<"Error! STACK is already full\n";
                    }
                    else{
                        cout<<"Enter the value of the element to add: ";
                        cin>>element;
                        s1 = element + s1;
                    }
            break;
            case 2:
                    if(s1.isempty()){
                        cout<<"Error! STACK is already empty\n";
                    }
                    else s1 = s1--;
            break;
            case 3:
                    s1 = s1++;
            break;
            case -1:
                    goto out;
            default:
                    cout<<"Invalid entry, Please check the menu and try again\n";
        }
        cout<<"\nSTACK: "<<s1<<endl;
    }
    out:

    return 0;
}
STACK::STACK(int sz){
    size = sz;
    len = 0;
    arr = new int[size];
}
STACK& operator+(int ele,STACK &obj){
    obj.arr[obj.len]= ele;
    obj.len++;
    return obj;
}
bool STACK::isfull(){
    return len==size;
}
bool STACK::isempty(){
    return len==0;
}
STACK& STACK::operator--(int){
    len--;
    return *this;
}

STACK& STACK::operator++(int){
    for(int i=0;i<len;i++) arr[i] += 1;
    return *this;
}

ostream& operator<<(ostream &print,STACK &obj){
    if(obj.len==0) cout<<"EMPTY STACK";
    for(int i = obj.len-1; i>=0; i--){
        print<<obj.arr[i]<<" ";
    }
    return print;
}

STACK::~STACK(){
    delete[] arr;
}