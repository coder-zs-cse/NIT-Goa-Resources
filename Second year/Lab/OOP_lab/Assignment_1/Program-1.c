#include<stdio.h>
#include<stdlib.h>
#define error() printf("Error! Memory couldn't be allocated \n");exit(1)

float average(float *array,int n){
    float sum=0;
    for(int i=0;i<=n;i++){
        sum+=array[i]; //sum of all elements
    }
    float avg=sum/n; //formula for average
    return avg;
}
int main(){
    int n;
    scanf("%d",&n);
    float *array=(float*) malloc(n*sizeof(float));
    if(array==NULL) {error();}

    for(int i=0;i<n;i++){
        scanf("%f",&array[i]);
    }
    printf("%.2f",average(array,n));
return 0;
}