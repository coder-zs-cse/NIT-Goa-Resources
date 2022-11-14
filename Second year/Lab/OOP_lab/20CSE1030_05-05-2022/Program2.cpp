#include<iostream>
using namespace std;

class SET{
    int n;
    int *arr;
    public:
    SET();
    SET(const SET&);
    void read_set();
    void print();
    SET operator+(SET);
    SET operator*(SET);
    void operator=(SET);
    ~SET();
};

int main(){
    SET s1,s2,s3,s4;
    s1.read_set();
    s2.read_set();
    s3 = s1 + s2;
    s4 = s1 * s2;
    cout<<"Set s1: ";
    s1.print();
    cout<<"Set s2: ";
    s2.print();
    cout<<"Set s3: ";
    s3.print();
    cout<<"Set s4: ";
    s4.print();
    return 0;
}
SET::SET(){
    arr = NULL;
    n = 0;
}
SET::SET(const SET &obj){
    n = obj.n;
    arr = new int[n];
    for(int i=0;i<n;i++) arr[i] = obj.arr[i];
}
void sort(int *arr,int n){
    for(int i=0;i<n-1;i++){
        for(int j=n-1;j>i;j--){
            if(arr[j]<arr[j-1]){
                int temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
        }
    }
}
SET::~SET(){
    delete[] arr;
}
void SET::read_set(){
    cout<<"Enter the number of elements to be inserted into the set\n";
    cin>>n;
    arr = new int[n];
    cout<<"Enter the elements of the set one by one\n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,n);
}
void SET::print(){
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<endl;
}

SET SET::operator+(SET obj){
    SET output;
    output.n = n + obj.n;
    output.arr = new int[output.n];
    int i=0,j=0,k=0;
    while(i<n && j<output.n){
        if(arr[i]<obj.arr[j]) output.arr[k++] = arr[i++];
        else if(arr[i]>obj.arr[j]) output.arr[k++] = arr[j++];
        else{
            output.arr[k++] = arr[i++];
            j++;
        }
    }
    while(i<n) output.arr[k++]  = arr[i++];
    while(j<obj.n) output.arr[k++] = obj.arr[j++];
    output.n = k;
    return output;
}
SET SET::operator*(SET obj){
    SET output;
    int i=0,j=0,k=0;
    output.arr = new int[n+obj.n];
    while(i<n && j<obj.n){
        if(arr[i]<obj.arr[j]) i++;
        else if(arr[i]>obj.arr[j]) j++;
        else {
            output.arr[k] = arr[i];
            i++;
            j++;
            k++;
        }
    }
    output.n = k;
    return output;
}

void SET::operator=(SET obj){
    n = obj.n;
    arr = new int[n];
    for(int i=0;i<n;i++) arr[i] = obj.arr[i];
}