#include<stdio.h>
#include<math.h>
// #define take(n) scanf("%d",&n);
// #define rep(i,a,b) for(int i=a;i<b;i++)
int main()
{
    printf("Enter the coefficients of x^2 followed by x followed by constant\n");
    float a,b,c;
    scanf("%f%f%f",&a,&b,&c);
    float D=sqrt(b*b-4*a*c);
    float root1=(-b+D)/(2*a);
    float root2=(-b-D)/(2*a);
    printf("The roots of %.fx^2+%.fx+%.f=0 are %f and %f",a,b,c,root1,root2);
return 0;
}