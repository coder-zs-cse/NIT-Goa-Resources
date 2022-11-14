#include<stdio.h>
#include<stdlib.h>
#define take(n) scanf("%d",&n)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define take_int_array(arr,n) 
#define take_float_array(arr,n) 
#define take_double_array(arr,n) 
#define error() printf("Error! Memory couldn't be allocated \n");exit(1)

void sort_int(int *arr,int n){ //sorting algo for int
    //BUbble sort
    //here we are repeatedly swapping two elements if they are in decreasing order
    
    rep(i,1,n){
        rrep(j,n-1,i){
            if(arr[j]<arr[j-1]){  //the lower element moves to the left 
                int temp=arr[j]; //swapping
                arr[j]=arr[j-1];
                arr[j-1]=temp;
            }
        }
    }
}
void sort_float(float *arr,int n){ //sorting algo for float numbers
    rep(i,1,n){
        rrep(j,n-1,i){
            if(arr[j]<arr[j-1]){
                float temp=arr[j];
                arr[j]=arr[j-1];
                arr[j-1]=temp;
            }
        }
    }
}
void sort_double(double *arr,int n){ //sorting algo for double
    rep(i,1,n){
        rrep(j,n-1,i){
            if(arr[j]<arr[j-1]){
                double temp=arr[j];
                arr[j]=arr[j-1];
                arr[j-1]=temp;
            }
        }
    }
}

int main(){

    printf("How many integer elements you want to sort\n");
    int n;
    take(n);
    printf("Enter %d elements one by one : ",n);
    int *arr1=(int*) malloc(n*sizeof(int));
    if(arr1==NULL) {error();}
    rep(i,0,n) scanf("%d",&arr1[i]);
    sort_int(arr1,n);

    printf("How many float elements you want to sort\n");
    int m;
    take(m);
    printf("Enter %d elements one by one : ",m);
    float *arr2=(float*) malloc(m*sizeof(float));
    if(arr2==NULL) {error();};
    rep(i,0,m) scanf("%f",&arr2[i]);
    sort_float(arr2,m);

    printf("How many double elements you want to sort\n");
    int o;
    take(o);
    printf("Enter %d elements one by one : ",o);
    double *arr3=(double*) malloc(o*sizeof(double));
    if(arr3==NULL) {error();};
    rep(i,0,o) scanf("%lf",&arr3[i]);
    sort_double(arr3,o);

    printf("Sorted integer array : ");
    rep(i,0,n){
        printf("%d ",arr1[i]);
    }
    printf("\n");

    printf("Sorted float array : ");
    rep(i,0,m){
        printf("%f ",arr2[i]);
    }
    printf("\n");

    printf("Sorted double array : ");
    rep(i,0,o){
        printf("%lf ",arr3[i]);
    }

return 0;
}