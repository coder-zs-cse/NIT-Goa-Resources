#include<iostream>
using namespace std;

template <typename T> 
void mysort(T *array,int n){ // bubble sort
    for(int i=n-1;i>=1;i--){
        for(int j=0;j<i;j++){
            if(array[j]>array[j+1]){
                T temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}
int main(){
    int n;
    cout<<"Enter the number of integer elements: ";
    cin>>n;
    int *arr;
    try{
        if(n<=0) throw -1;
        else{
            arr = new int[n];
            cout<<"Enter the integer elements of the array\n";
            for(int i=0;i<n;i++) cin>>arr[i];
            mysort(arr,n);
            cout<<"Sorted integer array\n";
            for(int i=0;i<n;i++) cout<<arr[i]<<" ";
            cout<<endl;
        }
    }
    catch(int){
        cout<<"Error! Invalid number of elements\n";
    }

    int m;
    cout<<"Enter the number of double elements: ";
    cin>>m;
    double *arr_d;
    try{
        if(m<=0) throw -1;
        else{
            arr_d = new double[m];
            cout<<"Enter the double elements of the array\n";
            for(int i=0;i<m;i++) cin>>arr_d[i];
            mysort(arr_d,m);
            cout<<"Sorted double array\n";
            for(int i=0;i<m;i++) cout<<arr_d[i]<<" ";
            cout<<endl;

        }
    }
    catch(int){
        cout<<"Error! Invalid number of elements\n";
    }
    
    delete []arr;
    delete []arr_d;
    return 0;
}