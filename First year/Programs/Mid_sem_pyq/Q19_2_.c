#include<stdio.h>
int main()
{
    int p=0;
    int n;
    scanf("%d",&n);
    for(int i=0;i<=n;i++ ){
        if(i%2==0)p=1;
        else p=0;
        for(int j=1;j<=i;j++){
            switch(p){
                case 1: printf("0 ");
                p=0;
                break;
                case 0: printf("1 ");
                p=1;
            }
        }
        printf("\n");
    }
return 0;
}