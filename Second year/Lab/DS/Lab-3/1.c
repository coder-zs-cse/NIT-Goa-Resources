#include<stdio.h>
#include<stdlib.h>
typedef struct {
    int first;
    int second;
}pair;
int check_desti(int **arr,int dest){
    
}
void update_edges(int **arr,int n){
    for(int i=0;i<n;i++){

    }
}
int main(){
    int n;
    scanf("%d",&n);
    int **array = (int**) malloc(sizeof(int*));
    for(int i=0;i<n;i++){
        array[i] = (int*) malloc(sizeof(int));
        for(int j=0;j<n;j++) array[i][j] = 0;
    }
    
    for(int i=0;i<n;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        array[a][b] = 1; 
    }





return 0;
}