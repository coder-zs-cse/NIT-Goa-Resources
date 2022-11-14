#include<iostream>
using namespace std;
class A{
    public:
    int data;
};
class B: virtual public A{
    public:
    int data;
};
class C: virtual public A{
    public:
    int data;
};
class D: public B, public C{
    public:
    int data;
    // Ddata, Bdata, Cdata, Adata
};
// class D{
//     int Ddata;
//     // Ddata, Bdata, Cdata, Adata
// };

int main(){
    D obj;
    A  aobj;
    cout<<sizeof(aobj)<<endl;
    B  bobj;
    cout<<sizeof(bobj)<<endl;
    C  cobj;
    cout<<sizeof(cobj)<<endl;
    cout<<endl;
    cout<<sizeof(obj)<<" "<<sizeof(int)<<endl;
    cout<<sizeof(obj.data);
    return 0;
}