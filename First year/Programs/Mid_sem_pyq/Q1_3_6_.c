#include<stdio.h>
// #include<string.h>
int main()
{
    int sum=0,maxsum=0,i,n=6;
    int a[6]={2,-2,-1,3,4,2};
    for(i=0;i<n;i++){
        if(i==0||a[i]<0||a[i]<a[i-1]){
            if(sum>maxsum)
                maxsum=sum;
             sum=(a[i]>0) ? a[i]:0;
        }
        else sum+=a[i];
    }
        if(sum>maxsum) maxsum=sum;
        printf("%dn",maxsum);
    // string s;

    
return 0;
}