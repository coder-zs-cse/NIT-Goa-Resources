#include<stdio.h>
#define take(n) scanf("%d",&n);
#define rep(i,a,b) for(int i=a;i<b;i++)
int main()
{
    int x=19;
    int *p=&x;
    printf("%u",p);
return 0;
}