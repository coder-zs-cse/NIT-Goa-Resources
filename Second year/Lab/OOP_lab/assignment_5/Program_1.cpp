#include<iostream>
using namespace std;
int power(int n,int m){
    if(m==0) return 1;
    return n*power(n,m-1);
}
class OCTAL{
    int oct;
    int integer_equivalent;
    public:
    OCTAL();
    OCTAL(int x);
    int operator+(int);
    void display();
};

int main(){
    int x=265;
    OCTAL h=x;
    int k=10;
    int y = h+k;
    h.display();
    cout<<y<<endl;

    return 0;
}
OCTAL::OCTAL(){
    oct=0;
    integer_equivalent=0;
}
OCTAL::OCTAL(int x){
    integer_equivalent=x;
    int base_of_x=10;
    int p=0;
    oct=0;
    while(x>0){
        oct+= (x%8)*power(base_of_x,p);
        x/=8;
        p++;
    }
}
int OCTAL::operator+(int x){
    return integer_equivalent +x;
}
void OCTAL::display(){
    cout<<oct<<endl;
}