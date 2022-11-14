#include<iostream>
using namespace std;
template <typename T>
void swapping(T &a,T &b){
    T temp=a;
    a=b;
    b=temp;
}
template <typename T>
int pivot(T *array,int l,int r){
    int index=l;
    T comp = array[r];
    for(int i=l;i<r;i++){
        if(array[i]<comp){
            swapping(array[i],array[index]);
            index++;
        }
    }
    swapping(array[index],array[r]);  
    return index;
}

template <typename T>
void helper(T *array,int l,int r){
    if(l<r){
        int pi = pivot(array,l,r);
        helper(array,l,pi-1);
        helper(array,pi+1,r);
    }
}

template <typename T>
void quicksort(T *array,int n){
    helper(array,0,n-1);
}

int main(){
    int n;
    printf("Enter the number of elements\n");
    cin>>n;
    printf("Enter %d integer elements one by one\n",n);
    int *array=new int[n];
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    quicksort(array,n);
    for(int i=0;i<n;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
    printf("Enter %d float elements one by one\n",n);
    float *floatarray=new float[n];
    for(int i=0;i<n;i++){
        cin>>floatarray[i];
    }
    quicksort(floatarray,n);
    for(int i=0;i<n;i++){
        cout<<floatarray[i]<<" ";
    }
    

    return 0;
}