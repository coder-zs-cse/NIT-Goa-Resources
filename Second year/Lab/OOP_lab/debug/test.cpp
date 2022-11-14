#include<iostream>
using namespace std;
int main(){
    int n = 10;
    int array[n];
    for(int i=0;i<11;i++){
        array[i] =(i-1)/i;
    }
    for(int i=0;i<n;i++){
        cout<<array[i];
    }
    return 0;
}