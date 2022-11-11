#include<stdio.h>
#include<stdlib.h>
#define take(n) scanf("%d",&n);
#define rep(i,a,b) for(int i=a;i<b;i++)
void printfibo1(int n){
    int *array=malloc(n*sizeof(int));
    rep(i,0,n){
        if(i==0 || i==1)  array[i]=i;
        else array[i]=array[i-1]+array[i-2];
        printf("%d ",array[i]);
    }
}
void printfibo2(int n){
    int prev=0;
    int prev_to_prev=1;
    int curr;
    rep(i,0,n){
        curr=prev+prev_to_prev;
        if(i==0 || i==1) printf("%d ",i);
        else {
        printf("%d ",curr);
        prev=prev_to_prev;
        prev_to_prev=curr;
        }
    }
}
int main()
{
    int n;
    take(n);
    printfibo1(n);
    printf("\n");
    printfibo2(n);
return 0;
}