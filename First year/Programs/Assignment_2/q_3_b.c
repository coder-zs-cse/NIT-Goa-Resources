#include<stdio.h>
int main()
{
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    int greatest;
    if(a>=b && a>=c) greatest=a;
    else if(b>=a && b>=c) greatest=b;
    else greatest=c;
    printf("The greatest on %d,%d and %d is %d",a,b,c,greatest);
return 0;
}