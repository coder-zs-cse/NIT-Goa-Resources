#include<iostream>
using namespace std;
typedef struct{
    int real;
    int imaginary;
}COMPLEX;
COMPLEX ADD(int number,COMPLEX s2){
    s2.real+=number;
    return s2;
}
COMPLEX ADD(COMPLEX s1,COMPLEX s2){
    s2.real+=s1.real;
    s2.imaginary+=s1.imaginary;
    return s2;
}
void take_input(COMPLEX &s1){
    cout<<"Enter the real part : ";
    cin>>s1.real;
    cout<<"Enter the imaginary part : ";
    cin>>s1.imaginary;
}
void print_complex(COMPLEX s1){
    cout<<s1.real;
    if(s1.imaginary!=0){
        cout<<" + "<<s1.imaginary<<"i";
    }
    cout<<endl;
}
using namespace std;
int main(){
    COMPLEX s1;
    take_input(s1);
    int num;
    cout<<"Enter the value of a : ";
    cin>>num;
    s1=ADD(num,s1);
    print_complex(s1);
    COMPLEX s2;
    take_input(s2);
    COMPLEX s3=ADD(s1,s2);
    print_complex(s3);

    return 0;
}