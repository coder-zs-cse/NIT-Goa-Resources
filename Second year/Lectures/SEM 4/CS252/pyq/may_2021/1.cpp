#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
#define ull unsigned ll
#define take(n) ll int n;cin>>n
#define mod 1000000007
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define pp pop_back()
#define array(n,name) ll int *name=new ll int[n]
#define takearray(n,name) rep(i,0,n) cin>>name[i];
#define Zubin ios::sync_with_stdio(false);
#define Shah cin.tie(NULL);cout.tie(0);
#define nl cout<<endl;
using namespace std;

class myclass{
    int a;
    int b;
    public:
    myclass(){
        a = 0;
        b = 0;
    }
    myclass& operator++(){
        a++;
        b++;
        return *this;
    }
    myclass operator++(int){
        myclass obj = *this;
        a++;
        b++;
        // return *this;
        return obj;
    }
    myclass operator+(const myclass &obj2){
        myclass output;
        output.a = a + obj2.a;
        output.b = b + obj2.b;
        return output;
    }
    myclass operator-(const myclass &obj2){
        myclass output;
        output.a = a - obj2.a;
        output.b = b - obj2.b;
        return output;
    }
    friend ostream& operator<<(ostream& print,myclass &obj){
        print<<obj.a<<" "<<obj.b<<" ";
        return print;
    }

    
};


int main(){

    Zubin Shah

    myclass obj1,obj2,obj3,obj4;
    obj4 = ++obj1 + obj2 + obj3++;
    cout<<obj1<<obj2<<obj3<<obj4;

return 0;
}