#include<stdio.h>
void add(int a,int b){
    printf("%d+%d=%d",a,b,a+b);
}
int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    add(a,b);
return 0;
}