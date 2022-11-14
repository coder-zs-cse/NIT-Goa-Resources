#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
#define ull unsigned ll
#define take(n) int n;cin>>n
#define mod 1000000007
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define pp pop_back()
#define array(n,name) ll int *name=new ll int[n]
#define takearray(n,name) rep(i,0,n) cin>>name[i];
#define printarray(n,nums) rep(i,0,n) cout<<nums[i]<<" ";
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
int recursive_engine(int a,int b,vector<vector<int>> &transitions, vector<vector<int>> &table,int n){
    if(a==b) return 1;
    if(table[a][b]==-1) {
        return -1;
    }
    rep(i,0,2){
        int temp = recursive_engine(table[a][i],table[b][i],transitions,table,n);
        if(temp==-1){
            table[a][b] = -1;
            return -1;
        }
    }
    table[a][b] = 1;
    return 1;
}
vector<vector<int>> MinimizeDFA(int n,vector<int> states,vector<vector<int>> transitions,int initial,vector<int> final){
    vector<vector<int>> table;
    rep(i,0,n){
        rep(j,0,n){
            table[i][j] = 0;
        }
    }
    unordered_set<int> fStates;
    int m = final.size();
    rep(i,0,m){
        fStates.insert(final[i]);
    }
    vector<vector<int>> output;
    rep(i,0,m){
        rep(j,0,n){
            if(final[i]!=j){
            table[final[i]][j] = -1;
            table[j][final[i]] = -1;

            }
        }
    }
    rep(i,0,n){
        rep(j,0,n){
            if(j<i){
                table[i][j] = recursive_engine(i,j,transitions,table,n);
            }
        }
    }
    rep(i,0,n){
        rep(j,0,n){
            cout<<table[i][j]<<" ";
        }
        nl;
    }
    return {{}};

}
int main(){

    Zubin Shah

    take(n);
    vector<vector<int>> transitions;
    rep(i,0,n){
        take(a);
        take(b);
        transitions.push_back({a,b});
    }
    take(initial);
    take(m);
    vector<int> final;
    rep(i,0,m){
        take(value);
        final.pb(value);
    }
    transitions = MinimizeDFA(n,{0,1},transitions,initial,final);
return 0;
}