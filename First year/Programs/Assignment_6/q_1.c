#include<stdio.h>
int main(){
    int n;
    printf("Enter the number of entries\n");
    scanf("%d",&n);
    int array[n];
    printf("Enter the entries one by one\n");
    for(int i=0;i<n;i++){
        scanf("%d",&array[i]);
    }
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=array[i];
    }
    float avg=(float)sum/n;
    printf("the average of given %d numbers is %f\n",n,avg);
}