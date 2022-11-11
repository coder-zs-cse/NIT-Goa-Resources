#include<stdio.h>
int main()
{
    int n,p;
    printf("Enter the base number followed  by exponent number\n");
    scanf("%d %d",&n,&p);
    long long int ans=1;
    for(int i=0;i<p;i++) ans*=n;
    printf("%d to the power of %d is equal to %lld\n",n,p,ans);
return 0;
}