#include<iostream>
#define MAXSIZE 50
using namespace std;

class STACK{
    int len;
    int maxsize;
    int *ptr;
    public:
    STACK();
    STACK operator+(int);
    STACK operator-();
    void peek();
    int empty();
    void display();
};
int main(){
    int choice,element;
    STACK st;
    
    while(1){
        cout<<"Press 1 to insert an element into the stack\n";
        cout<<"Press 2 to pop an element from the stack\n";
        cout<<"Press 3 to get the first element of the stack\n";
        cout<<"Press 4 to check if the stack is empty\n";
        cout<<"Press -1 to exit the program\n";
        cin>>choice;
        switch(choice){
            case 1: 
                    printf("Enter the value of the element you want to insert\n");
                    cin>>element;
                    st = st + element;
            break;
            case 2: 
                    st =-st;
            break;
            case 3:
                    st.peek();
            break;
            case 4:
                    if(!st.empty()){
                        cout<<"Stack is currently not empty\n";
                    }
            break;
            case -1: 
                    goto out;
            default: 
                    cout<<"Invalid entry, please check the menu and try again\n";
        }
        st.display();
    }
    out:

    return 0;
}
STACK::STACK(){
    len=0;
    maxsize = MAXSIZE;
    ptr=new int[maxsize];
}
STACK STACK::operator+(int element){
    if(len==maxsize){
        cout<<"Stack overflow\n";
    }
    else{
        ptr[len] = element;
        len++;
    }
    return *this;
}
STACK STACK::operator-(){
    if(len==0){
        cout<<"Stack underflow\n";
    }
    else{
        len--;
        ptr[len]=0;
    }
    return *this;
}
void STACK::peek(){
    if(len==0){
        cout<<"Stack is empty\n";
    }
    else{
        cout<<"Top element of Stack : "<<ptr[len-1]<<endl;
    }
}
int STACK::empty(){
    return len==0;
}
void STACK::display(){
    if(len==0) {
        cout<<"Stack is empty\n";
    }
    else{
        cout<<"Stack : ";
        for(int i=0;i<len;i++){
            cout<<ptr[i]<<" ";
        }
        cout<<endl;
    }
}