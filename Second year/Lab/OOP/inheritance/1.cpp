#include<iostream>
using namespace std;
class base{
    int i;
    int j;
    protected:
    base(int x,int y){
        i =x;
        j = y;
    }
    void truy(){
        cout<<i+j;
    }
};
class derived : public base{
    int k;
    public:
    derived(int a,int b) : base(a,b){
        k = a+b;
    }
    void truy(){
        cout<<k;
    }


};
int main(){
    derived obj(5,10);
    obj.truy();
    cout<<sizeof(base)<<" ";
    // cout<<sizeof(obj)<<" "<<sizeof(obj2)<<" "<<sizeof(int);
}