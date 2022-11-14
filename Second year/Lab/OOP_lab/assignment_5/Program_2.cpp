#include<iostream>
using namespace std;
class foo{
    int a;
    public:
    void set_a(int x){
        a=x;
    }
    void print_a(){
        cout<<a<<endl;
    }
};
int main(){
    foo a;
    a.set_a(10);
    foo b=a;
    a.set_a(20);
    a.print_a();
    b.print_a();
return 0;
}