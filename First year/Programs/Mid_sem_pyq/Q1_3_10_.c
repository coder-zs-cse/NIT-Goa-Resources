#include<stdio.h>
int main()
{
    int a[]={2,3,4,5,6};
    int *p[]={a,a+1,a+3,a+4};
    int **ptr=p;
    printf("%d %d ",**ptr,**p);
    ++*ptr;
    
    printf("%d %d %d %d %d",a[1], ptr,p,*ptr-a,**ptr);
return 0;
}