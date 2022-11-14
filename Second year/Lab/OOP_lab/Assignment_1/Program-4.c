#include<stdio.h>
#include<stdlib.h>
#define take(n) scanf("%d",&n)
#define take_array(arr,n) for(int i=0;i<n;i++) scanf("%d",&arr[i])
#define error() printf("Error! Memory couldn't be allocated \n");exit(1)

int duplicates(int *arr,int n){
    int *visited=(int*) calloc(n,sizeof(int)); // TO mark duplicates as visited
    if(visited==NULL) {error();}
    int uniq_count=0;
    for(int i=0;i<n;i++){
        if(visited[i]==0){  //only non duplicates will be processed
            uniq_count++; 
            for(int j=i+1;j<n;j++){
                if(arr[j]==arr[i]) {
                    visited[j]=1; // all duplicates of the number will be marked visited
                }
            }
        }
    }
    free(visited); //freeing the extra allocated dynamic memory 
    return n-uniq_count; //total - unique number = duplicates
}

int main(){
    printf("Enter the number of elements\n");
    int n;
    take(n);
    int *arr=(int*) malloc(n*sizeof(int));
    if(arr==NULL){error();}
    printf("Enter %d elements one by one : ",n);
    take_array(arr,n);

    printf("The number of duplicates in given array are: %d\n",duplicates(arr,n));

return 0;
}