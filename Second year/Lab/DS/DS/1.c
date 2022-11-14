#include<stdio.h>
#include<stdlib.h>
#define take(n) int n;scanf("%d",&n)
#define error() printf("\nError! Memory couldn't be allocated.");exit(1);
void shiftcyclically(int *array,int n){
    int start=array[0];
    for(int i=0;i<n-1;i++){
        array[i]=array[i+1];
    }
    array[n-1]=start;
}
int main(){
    int n;
    scanf("%d",&n);
    int *array=(int*) malloc(n*sizeof(int));
    if(array==NULL) {error();}
    for(int i=0;i<n;i++){
        scanf("%d",&array[i]);

    }
    shiftcyclically(array,n);
    for(int i=0;i<n;i++){
        printf("%d ",array[i]);
    }
return 0;
}