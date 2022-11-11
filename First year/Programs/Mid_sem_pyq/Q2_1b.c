#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    // char string[100];
    // scanf("%s",&string);
    int n;
    scanf("%d",&n);
    int *array=malloc(n*sizeof(int));
    memset(array,-1,n*sizeof(int));
    printf("%d",array[2]);
return 0;
}