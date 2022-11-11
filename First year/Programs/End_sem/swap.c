#include<stdio.h>
#include<stdlib.h>
#define take(n) scanf("%d",&n);
#define rep(i,a,b) for(int i=a;i<b;i++)
int power(int a,int b){
    if(b==0) return 1;
    return a*power(a,--b);
}
// int swap(int n){
//     int m=n,no=0;
//     while(m>0){
//         no++;
//         m/=10;
//     }
//     int *array=(int*)malloc(no*sizeof(int));
//     m=n;
//     int i=0;
//     while(m>0){
//         array[i]=m%10;
//         m/=10;
//         i++;
//     }
//     int temp=array[1];
//     array[1]=array[no-1];
//     array[no-1]=temp;
//     int output=0;
//     i=0;
//     while(i<no){
//         output=output+power(10,i)*array[i];
//         i++;
//     }
//     return output;
// }
int optimized_swap(int n){
     int m=n,no=0;
    while(m>0){
        no++;
        m/=10;
    }
    int power_1=power(10,no-1);
    int a=n/power_1;
    int b=(n%100)/10;
    int output=n%power_1 + b*power_1;
    output=output-output%100 + a*10+ n%10;
    return output;
}
int main()
{
    int N;
    take(N);
    while(--N){
    int n;
    take(n);
    printf("%d",optimized_swap(n));
    }
return 0;
}