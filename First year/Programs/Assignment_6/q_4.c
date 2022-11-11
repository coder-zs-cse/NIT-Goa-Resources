#include<stdio.h>
int ispresent(int *array,int n,int k){
    for(int i=0;i<n;i++)  if(array[i]==k) return 1;
    return 0;
}
int main(){
    int n;
    printf("Enter the number of entries\n");
    scanf("%d",&n);
    int array[n];
    printf("Enter the elements one by one\n");
    for(int i=0;i<n;i++) scanf("%d",&array[i]);
    int k;
    printf("Enter the element you want to search\n");
    scanf("%d",&k);
    if(ispresent(array,n,k)) printf("%d is present in the given array\n",k);
    else printf("%d is not in the given array\n",k);
}