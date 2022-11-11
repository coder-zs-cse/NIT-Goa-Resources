#include<stdio.h>
int main()
{
    int i=0;
    for(int i=0;i<20;i++){
        switch(i){
            case 0:i+=5;
            case 1:i+=2;
            case 5:i+=5;
            default: i+=4;
            break;
        }
        printf("%d ",i);
        }
    
return 0;
}