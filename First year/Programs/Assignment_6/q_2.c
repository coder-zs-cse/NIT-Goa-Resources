#include<stdio.h>
#include<stdlib.h>
float avg(int *array,int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=array[i];
    }
    float average=(float)sum/n;
    return average;
}
int main(){
    int n;
    printf("Enter the number of entries\n");
    scanf("%d",&n);
    printf("Enter the elements one by one\n");
    int array[n];
    for(int i=0;i<n;i++){
        scanf("%d",&array[i]);
    }
    printf("%f",avg(array,n));
}