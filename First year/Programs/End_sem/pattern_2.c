#include<stdio.h>
// #include<conio.h>
#define take(n) scanf("%d",&n);
#define rep(i,a,b) for(int i=a;i<b;i++)
int main()
{
    int r;
    take(r);
    rep(i,1,r+1){
        rep(j,i,r+1){
            printf("%d ",j);
        }
        for(int j=i;j>1;j--){
            printf("%d ",j-1);
        }
        printf("\n");
    }
    // getch();
return 0;
}