#include<stdio.h>
int main()
{
 char a[]={'A','B','C','D'};
 char *ppp=&a[0];
*ppp++;
printf("%c ",*ppp);
printf("%c %c %c",*ppp,*ppp++,--*ppp);
 return 0;
}