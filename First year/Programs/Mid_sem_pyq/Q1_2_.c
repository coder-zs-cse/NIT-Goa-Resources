#include<stdio.h>
int main()
{
    for(int i=1;i<=5;i++){
        int k=0;
        for(int j=1;j<=4+i;j++){
            if(j<=5-i || j>4+i){
                printf(" ");
            }
            else {
               if(j>5){
                   k--;
                   printf("%d",k);
               }
               else{
                   k++;
                   printf("%d",k);
               }
            }
        }
        printf("\n");
    }
return 0;
}