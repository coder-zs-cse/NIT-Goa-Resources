#include<stdio.h>
#include<stdlib.h>
int max(int A[],int n){
    int m=A[0];
    for(int i=0;i<n;i++){
        if(A[i]>m){
            m=A[i];
        }
    }
    return m;
}

void duplicate(int A[],int n){
    int size=max(A,n)+1;
    int *H=(int*)malloc(size*sizeof(int));
    
    
    int i;
    
    for(i=0;i<size;i++){
        H[i]=0;
    }
    for( i=0;i<n;i++){
        H[A[i]]++;
    }
    for(i=0;i<size;i++){
        if(H[i]!=0){
            printf("%d ",i);
        }
    }
    printf("\n");
    i=0;
    int cnt=0;
    while(i<size){
      
        if(H[i]>=0){
            H[i]--;
            cnt++;
            if(H[i]==0){
            printf("%d ",cnt);
        }
        }
     
        else if(H[i]<0){
            cnt=0;
            i++;
        }
    }
}

int main(){
    int arr[]={5,15,5,100};
    
    printf("\n");
    duplicate(arr,4);
    
}