#include<stdio.h>
void main()
{
    printf("Enter the numbers and operation that you want to perform\n");
    int a,b,output,flag=0;
    char c;
    scanf("%d%c%d",&a,&c,&b);
    if(c=='+') output=a+b;
    else if(c=='-') output=a-b;
    else if(c=='*') output=a*b;
    else if(c=='/') output=a/b;
    else {
        printf("Invalid character\n");
        flag=1;
    }
   if(flag==0) printf("%d %c %d = %d",a,c,b,output);
    return;
}