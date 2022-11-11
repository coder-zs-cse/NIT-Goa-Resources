#include<stdio.h>
int power(int a,int b){
    int ans=1;
    while(b--) ans*=a;
    return ans;
}
int main()
{
    int a,b,output;
    scanf("%d%d",&a,&b);
    output=power(a,b);
    printf("%d^%d=%d",a,b,output);
    return 0;
}