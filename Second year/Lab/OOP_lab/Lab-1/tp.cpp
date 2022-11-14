#include <iostream>
#include <ostream>
using namespace std;

class A
{
    protected :
        int aa;

    public:
        A(int aa) {
            cout<<"yes i am inside constructor of A"<<endl;

            this->aa = aa;
        }
        ~A(){}
        friend ostream &operator<<(ostream &os, const A& obj);
        virtual void show() {cout << "a = " << aa << "\n"; }
};



class B : public A
{
    public :
        int bb;

    public:
        B(int aa, int bb) : A(aa) {
            cout<<"yes i am inside constructor of B"<<endl;
            this->bb = bb;
            cout<<this->bb;
        }
        ~B(){}
        friend ostream &operator<<(ostream &os, const B& obj);
        void show() {cout << "a = " << aa << "\n"; cout << "b = " << bb << "\n";}
};



int main()
{
    A *obj = new B(2,3);
    cout << *obj;
    // obj->show();
    delete obj;

    return 0;
}
ostream &operator<<(ostream &os, const A& obj)
{
    for(int i=0; i<80; i++)
        os << "-";
    os << "\n";

    os << "a = " << obj.aa << "\n";

    for(int i=0; i<80; i++)
        os << "-";
    os << "\n";

    return os;
}
ostream &operator<<(ostream &os, const B& obj)
{
    for(int i=0; i<80; i++)
        os << "-";
    os << "\n";

    os << "a = " << obj.aa << "\n";
    os << "b = " << obj.bb << "\n";

    for(int i=0; i<80; i++)
        os << "-";
    os << "\n";

    return os;
}
