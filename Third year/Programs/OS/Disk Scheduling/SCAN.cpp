#include<bits/stdc++.h>
using namespace std;
int main(){
    int i,j,k,n,m,sum=0,x,y,h;
    cout<<"Enter the size of disk\n";
    cin>>m;
    cout<<"Enter number of requests\n";
    cin>>n;
    cout<<"Enter the requests\n";
    vector <int> a(n),b;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    for(i=0;i<n;i++){
        if(a[i]>m){
            cout<<"Error, Unknown position "<<a[i]<<"\n";
            return 0;
        }
    }
    cout<<"Enter the head position\n";
    cin>>h;
    int temp=h;
    a.push_back(h); // initialize the search
    a.push_back(m);
    a.push_back(0);
    sort(a.begin(),a.end());
    for(i=0;i<a.size();i++){
        if(h==a[i]) //getting the index of the starting position in the sorted tracking numbers
            break;
    }
    k=i;
    if(k<n/2){ // if more track numbers towards the right side than left, start moving from right
        for(i=k;i<a.size();i++){ //towards right
            b.push_back(a[i]);
        }
        for(i=k-1;i>=0;i--){ //right to left
            b.push_back(a[i]);
        }
    }
    else{    
        for(i=k;i>=0;i--){ // towards left
            b.push_back(a[i]);
        }
        for(i=k+1;i<a.size();i++){ // towards right
            b.push_back(a[i]);
        }
    }
    temp=b[0];
    cout<<temp;
    for(i=1;i<b.size();i++){
        cout<<" -> "<<b[i];
        sum+=abs(b[i]-temp);
        temp=b[i];
    }
    cout<<'\n';
    cout<<"Total head movements = "<< sum<<'\n';
    cout<<"Average head movement = "<<(float)sum/n<<'\n';
    return 0;
}