#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int temp=0;
    int m=n;
    while(m>0){
        int unit=m%10;
        temp=temp*10+unit;
        m/=10;
    }
    if(temp==n) printf("Yes, the number is a palindrome");
    else printf("no, the number is not a palindrome");
return 0;
}