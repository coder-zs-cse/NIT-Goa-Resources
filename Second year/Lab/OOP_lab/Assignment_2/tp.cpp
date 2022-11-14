#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
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
int main(){

    int *p=new int[10];
    rep(i,0,10) p[i]=i+1;
    rep(i,0,10) cout<<p[i]<<" ";
    nl;
    int *q=p;
    delete p;
    p=xcor;

    rep(i,0,4) cout<<p[i]<<" ";nl;
    rep(i,0,10) cout<<q[i]<<" ";

return 0;
}