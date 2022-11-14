#include<stdio.h>
#include<stdlib.h>
#define take(n) int n;scanf("%d",&n)
int *merge(int *array1,int *array2,int n,int m){
    int *array3=(int*) malloc((n+m)*sizeof(int));
    for(int i=0;i<n;i++){
        array3[i]=array1[i];
    }
    for(int i=0;i<m;i++){
        array3[i+n]=array2[i];
    }
    return array3;
}
int main(){
    int n;
    scanf("%d",&n);
    int *array1=(int*) malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        scanf("%d",&array1[i]);
    }
    int m;
    scanf("%d",&m);
    int *array2=(int*) malloc(m*sizeof(int));
    for(int i=0;i<m;i++){
        scanf("%d",&array2[i]);
    }
    int *array3=merge(array1,array2,n,m);
    for(int i=0;i<n+m;i++){
        printf("%d ",array3[i]);
    }


return 0;
}