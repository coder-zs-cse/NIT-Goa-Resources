#include<stdio.h>
#include<stdlib.h>

int rotate_array_one_position(int arr[],int n)
{
    int store = arr[n-1];
    int prev = arr[0];
    for(int i=1;i<n;i++){
        int temp = arr[i];
        arr[i] = prev;
        prev = temp;
    }
    arr[0] = store;   
}

int main()
{
    int n;
    printf("enter the size of array");
    scanf("%d",&n);
    int *arr = (int*)malloc(sizeof(n));
    for(int i=0;i<n;i++)
    {
        printf("enter %dth element",i);
        scanf("%d",&arr[i]);
    }

    printf("Input: ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    rotate_array_one_position(arr,n);
    printf("Output: ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }

}
