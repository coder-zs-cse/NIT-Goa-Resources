#include<stdio.h>
int main()
{
    printf("Enter the values of num1 and num2\n");
    int a,b;
    scanf("%d%d",&a,&b);
    printf("Initially num1 = %d and num2 = %d\n",a,b);
    a=a+b;
    b=a-b;
    a=a-b;
    printf("After swapping num1 = %d and num2 = %d",a,b);
return 0;
}