#include<stdio.h>
void sum_50(int *ans){
    for(int i=1;i<=50;i++) *ans+=i;
}
int main()
{
    int output=0;
    sum_50(&output);
    printf("%d",output);
return 0;
}