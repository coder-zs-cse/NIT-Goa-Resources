#include<iostream>
using namespace std;
int a  =10;
float ans(int a,char x,float b = 5){
    return ::a + x + b;
}
int main(){
    int a = 100;
    float x = 11.1;
    cout<<ans(a,x);
}