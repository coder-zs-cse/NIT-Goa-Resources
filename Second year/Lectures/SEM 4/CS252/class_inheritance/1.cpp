#include<iostream>
using namespace std;
class base{
    public:
    int a;
    virtual void hello(){
        cout<<"I am your don i guess?\n";
    }

};
class child:public base{
    public:
    int a;
    void hello(){
        cout<<"Who do you think I am then?\n";
    }
};
int main(){
    child y;
    y.a=10;
    cout<<y.a<<" "<<y.base::a<<endl;
    y.base::hello();
    cout<<"okay";
    return 0;
}