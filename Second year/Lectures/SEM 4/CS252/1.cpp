#include<iostream>
using namespace std;
#define MXSIZE 100
class STACK{
    int array[MXSIZE];
    int length;
    public:
    STACK operator+(int);
    STACK operator--();
    void display();

};
int main(){
    int choice,element;
    STACK s1;
    while(1){
        printf("Enter your choice\n");
        cin>>choice;
        switch(choice){
            case 1: cin>>element;
                    s1 = s1 + element;
            break;
            case 2:  s1 = --s1;
            break;


        }
        s1.display();
    }

return 0;
}
STACK STACK::operator+(int element){
    STACK current = *this;
    if(length==MXSIZE){
        cout<<"stack overflow\n";
    }
    else{
        current.array[length]=element;
        current.length++;
    }

    return current;
}
STACK STACK::operator--(){
    STACK current = *this;
    if(length==0){
        cout<<"STACK underflow\n";
    }
    else{
        current.length--;

    }
    return current;

}
void STACK::display(){
    for(int i=0;i<length;i++){
        cout<<array[i]<<" ";

    }
    return ;
}