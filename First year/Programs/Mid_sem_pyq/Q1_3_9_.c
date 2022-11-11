#include<stdio.h>
int main()
{
   int i,j;
   int a[8]={1,2,3,4,5,6,7,8};
   for(i=0;i<3;i++){
       a[i]=a[i]+1;
       i++;
   }
   i--;
   for(j=7;j>4;j--){
       int i=j/2;
       a[i]=a[i]-1;
   }
   printf("%d %d",i,a[i]);
return 0;
}