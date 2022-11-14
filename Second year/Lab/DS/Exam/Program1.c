#include<stdio.h>
#include<stdlib.h> // changes
int min(int a,int b) {return a<b ? a:b;}  // changes

int min_distance(int *arr,int n,int a,int b){
    int distance = n;
    int foot1 = -1;
    int foot2 = -1;
    for(int i=0;i<n;i++){
        if(arr[i]==a){
            foot1 = i;
            if(foot2!=-1) distance = min(distance,foot1-foot2);
        }
        if(arr[i]==b){
            foot2 = i;
            if(foot1!=-1) distance = min(distance,foot2-foot1);
        }

    }
    return distance;
}
int main(){
    int n;
    scanf("%d",&n);
    int *arr = (int*) malloc(sizeof(int)*n);
    for(int i=0;i<n;i++) {
        scanf("%d",&arr[i]);
    }
    int a,b; // changes
    printf("Enter m and n\n");
    scanf("%d%d",&a,&b); //  changes
    int distance = min_distance(arr,n,a,b); //changes
    printf("The minimum distance is %d",distance);
    return 0;
}