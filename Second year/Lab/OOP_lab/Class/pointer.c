#include<stdio.h>
#include<stdlib.h>
#define take(n) int n;scanf("%d",&n)
int main(){
    double x=20.4,y;
    double *p;
    p=&x;
    y=*p;
    p=p+5;
    printf("%p",p);
return 0;
}