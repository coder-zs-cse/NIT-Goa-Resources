#include<iostream>
using namespace std;

void copy_ints(int *arr1,int k,int *arr2){
    for(int i=0;i<k;i++){
        arr2[i]=arr1[i];
    }
}

int main(){

    int n;
    cin>>n;
    int *arr1=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr1[i];
    }
    int *arr2=new int[n];
    int k;
    cin>>k;
    copy_ints(arr1,k,arr2);
    for(int i=0;i<k;i++){
        cout<<arr2[i]<<" ";
    }





    return 0;
}