#include<stdio.h>
int main()
{
    int a;
    int b;
    double c;
    double d;
    printf("Enter two integers followed by two real numbers\n");
    scanf("%d%d%lf%lf",&a,&b,&c,&d);
    int output1=a+b;
    double output2=c+d;
    printf("The sum of two integers is %d\nThe sum of two real numbers is %lf\n",output1,output2);
return 0;
}