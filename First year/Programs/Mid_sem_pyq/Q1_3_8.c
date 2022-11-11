#include<stdio.h>
int main()
{
    int cnt=1;
    do{
        printf("%d",cnt);
        cnt+=1;
    }while(cnt>=10);
    printf("\n %d",cnt);
    while(cnt>=10){
        printf("%d",cnt);
        cnt+=1;
    }
    printf("\n%d",cnt);
return 0;
}