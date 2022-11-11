#include<stdio.h>
#define take(n) scanf("%d",&n);
#define rep(i,a,b) for(int i=a;i<b;i++)
int main()
{
    int r;
    take(r);
    rep(i,1,r+1){
        rep(j,1,r+1){
            if(i+j>r) printf("%d ",r);
            else printf("%d ",i+j-1);
        }
        printf("\n");
    }
return 0;
}