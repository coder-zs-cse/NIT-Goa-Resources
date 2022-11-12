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

int xcor[4]={-1,0,0,+1};
int ycor[4]={0,-1,1,0};

ull int power(ull n,int x){
    if(x==0) return 1;
    return n * power(n,x-1);
}

int main(){

    Zubin Shah

    vector<int> v;
    v.pb(0);
    v.pb(1);
    v.pb(2);
    v.pb(3);//0 1 2 3 //0 2 3
    v.pb(4);//0 1 2 3 //0 2 3
    v.pb(5);//0 1 2 3 //0 2 3
    v.pb(6);//0 1 2 3 //0 2 3
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<endl;
        if(i==1) {
            v.erase(v.begin()+i);
            i--;
        }
    }

return 0;
}