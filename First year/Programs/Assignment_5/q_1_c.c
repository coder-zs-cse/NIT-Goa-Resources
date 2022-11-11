#include<stdio.h>
int add(int a,int b){
    return a+b;
}
int main()
{
    int a,b,output;
    scanf("%d%d",&a,&b);
    output=add(a,b);
    printf("%d+%d=%d",a,b,output);
return 0;
}