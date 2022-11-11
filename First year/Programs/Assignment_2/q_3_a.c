#include<stdio.h>
int main()
{
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    int greatest;
    if(a>b){
        if(a>=c) greatest=a;
        else greatest=c;
    }
    else{
        if(b>=c) greatest=b;
        else greatest=c;
    }
    printf("The greatest of %d,%d and %d is %d",a,b,c,greatest);
return 0;
}