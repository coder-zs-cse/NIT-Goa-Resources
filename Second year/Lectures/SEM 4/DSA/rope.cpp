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
int funct(ll int n, ll int a,ll int b,ll int c){
    cout<<"N= "<<n<<",A= "<<a<<",B = "<<b<<", C= "<<c<<endl;
    if(n<0) return -1;
    if(n==0) return 0;
    int output = funct(n-a,a,b,c);
    output = max(output,funct(n-b,a,b,c));
    output = max(output,funct(n-c,a,b,c));
    if(output==-1) return -1;
    return 1+ output;
}
int main(){

    Zubin Shah

    take(n);
    take(a);
    take(b);
    take(c);

    int output = funct(n,a,b,c);
    cout<<"Number of pieces: "<<output;

return 0;
}