#include<stdio.h>
#define take(n) scanf("%d",&n);
#define rep(i,a,b) for(int i=a;i<b;i++)
int main()
{
    int n;
    take(n);
    int binary=0,m=n,p=1;
    while(m>0){
        binary=binary+p*(m%2);
        p*=10;
        m/=2;
    }
    printf("%d",binary);
return 0;
}