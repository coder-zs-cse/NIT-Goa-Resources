#include<stdio.h>
#include<stdlib.h>
#define error() printf("Error! Memory couldn't be allocated \n");exit(1)

void copy(int *arr1,int *arr2,int n){
    for(int i=0;i<n;i++){
        arr2[i]=arr1[i];
    }
}
    
int main(){
    printf("Enter the number of elements\n");
    int n;
    scanf("%d",&n);
    printf("Enter %d elements of 1st array\n",n);
    int *arr1=(int*)malloc(sizeof(int)*n);
    if(arr1==NULL){error();}

    for(int i=0;i<n;i++){
        scanf("%d",&arr1[i]);
    }

    int *arr2=(int*) malloc(n*sizeof(int));
    if(arr2==NULL){error();}
    copy(arr1,arr2,n);
    
    printf("Elements of array 2 are\n");
    for(int i=0;i<n;i++){
        printf("%d ",arr2[i]);
    }

return 0;
}