#include<stdio.h>
#define take(n) scanf("%d",&n);
#define rep(i,a,b) for(int i=a;i<b;i++)
void add(int *array){
    printf("%d ",array[0]+array[1]);
}
int main()
{
    int array[10];
    rep(i,0,10) array[i]=i+1;
    int *p=array;
    add(p);
    add(array);
return 0;
}