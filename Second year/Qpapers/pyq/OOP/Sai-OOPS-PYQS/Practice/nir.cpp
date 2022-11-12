#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rrep(i, a, b) for (int i = a; i >= b; i--)
#define ll long long
#define take(n) \
    ll int n;   \
    cin >> n
#define mod 1000000007
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define pp pop_back()
#define array(n) ll int *array = new ll int[n]
#define such ios::sync_with_stdio(false);
#define code       \
    cin.tie(NULL); \
    cout.tie(0);

#include <iostream>
using namespace std;
class object
{
    int x;
    char ch;

public:
    object()
    {
        cout << "Normal constructor is called " << endl;
    }
    // object(object &ob){
    //     cout<<"Copy constructor is called "<<endl;
    //      this->x=ob.x;
    //      this->ch=ob.ch;
    // }
    ~object()
    {
        cout << "Destructor is Called of" << x << endl;
    }
    void set(int i)
    {
        x = i;
    }
    void get()
    {
        cout << x << endl;
    }
    void setC(char ch)
    {
        this->ch = ch;
    }
    void getC()
    {
        cout << ch << endl;
    }
};
int main()
{

    // object ob;//Normal is called
    // ob.set(1);
    // object ob1;//Normal is called
    // ob1.set(2);
    // // ob1=ob;//Nothing is called
    // ob1.get();
    // ob.get();
    // object ob2(ob);//copy is called
    // ob2.set(3);
    // object ob3=ob;//copy is called
    // ob3.set(4);
    // ob.get();
    // ob3.get();
    object ob, ob1, ob2;
    ob.setC('A');
    ob1.set(2);
    ob2.set(3);
    
    ob.set(1);
    object ob3 = ob;
    ob3.getC();
    ob.setC('B');
    ob3.get();
    ob.getC

        ();
    // ob3.set(4);
    // ob.get();
    return 0;
}