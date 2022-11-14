#include<stdio.h>
#include<stdlib.h>
#define take(n) int n;scanf("%d",&n)
void reverse(int *array,int n){
    for(int i=0;i<n/2;i++){
        int temp=array[i];
        array[i]=array[n-i-1];
        array[n-i-1]=temp;
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int *array=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        scanf("%d",&array[i]);
    }
    reverse(array,n);
    for(int i=0;i<n;i++){
        printf("%d ",array[i]);
    }
return 0;
}