#include<stdio.h>
#include<stdlib.h>
#define take(n) scanf("%d",&n)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define error() printf("Error! Memory couldn't be allocated \n");exit(1)

int ** matrix_sum(int **matrix1,int **matrix2,int m,int n){
    int **matrix3=(int**) malloc(m*sizeof(int*));
    if(matrix3==NULL) {error();}
    rep(i,0,m){
        matrix3[i]=(int*) malloc(n*sizeof(int));
        rep(j,0,n){
            matrix3[i][j]=matrix1[i][j]+matrix2[i][j]; //adding corresponding elements of matrix
        }
    }
    return matrix3;
}
int main(){
    printf("Number of rows : ");
    int m,n;
    take(m);
    printf("Number of columns : ");
    take(n);
    printf("Enter the elements of Matrix1\n");
    int **matrix1=(int**) malloc(m*sizeof(int*));
    if(matrix1==NULL) {error();}
    rep(i,0,m){
        matrix1[i]=(int*) malloc(n*sizeof(int));
        rep(j,0,n){
            take(matrix1[i][j]);
        }
    }
    printf("Enter the elements of Matrix2\n");
    int **matrix2=(int**) malloc(m*sizeof(int*));
    if(matrix2==NULL) {error();}
    rep(i,0,m){
        matrix2[i]=(int*) malloc(n*sizeof(int));
        rep(j,0,n){
            take(matrix2[i][j]);
        }
    }
    
    printf("Sum of given two matrix is :-\n");
    int **matrix3=matrix_sum(matrix1,matrix2,m,n);
    rep(i,0,m){
        rep(j,0,n){
            printf("%d ",matrix3[i][j]);
        }
        printf("\n");
    }

    

    return 0;
}