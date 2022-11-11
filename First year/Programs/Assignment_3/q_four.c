#include<stdio.h>
int main()
{ 
    int n;
    scanf("%d",&n);
    int m=n;
    int temp=0;
    while(m>0){
        temp=temp*10+m%10;
        m/=10;
    }
    printf("Original number:%d\nReversed number:%d\n",n,temp);
    if(temp==n) printf("%d is a palindrome\n",n);
    else printf("%d is not a palindrome\n",n);
return 0;
}