// Write a C++ program to create a class called OCTAL which has the 
// characteristics  of  an  octal  number.  Implement  the  following  operations  by 
// writing an appropriate constructor and an overloaded operator +. 
// i) OCTAL h=x; where x is an integer. 
 
// ii) int y = h + k; where h is an OCTAL object and k is an integer. 
 
// iii)  Display  the  OCTAL  result  by  overloading  the  operator  <<.  Also  display 
// the values of h and y.
#include<iostream>
#define SIZE 10
using namespace std;

class OCTAL{
    int oct;
    public:
    OCTAL(int);
    int operator+(int);
    friend ostream& operator<<(ostream&,const OCTAL&);
};
int main(){
    cout<<"Enter the value of x: ";
    int x;
    cin>>x;
    
    OCTAL h = x;
    cout<<"Enter the value of k: ";
    int k;
    cin>>k;

    int y = h + k;
    cout<<"OCTAL h: "<<h<<endl;
    cout<<"Int   y: "<<y<<endl;
    return 0;
}
OCTAL::OCTAL(int x){
    int power=1;
    oct=0;
    while(x>0){
        oct += power * (x%8);
        x/=8;
        power*=10;
    }
}
ostream& operator<<(ostream &print,const OCTAL &obj){
    print<<obj.oct;
    return print;
}
int OCTAL::operator+(int k){
    int output =0;
    int temp = oct;
    int power =1;
    while(temp>0){
        output += power *(temp%10);
        temp/=10;
        power*=8;
    }
    output+=k;
    return output;
}
    