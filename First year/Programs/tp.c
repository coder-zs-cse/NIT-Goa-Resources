#include<stdio.h>
#define take(n) scanf("%d",&n);
#define rep(i,a,b) for(int i=a;i<b;i++)
void add_10(int n){
    printf("Enter a number\n");
    int x;
    take(x);
    printf("%d+%d=%d\n",n,x,n+x);
}
void multiply_10(int n){
    printf("Enter a number\n");
    int x;
    take(x);
    printf("%d*%d=%d\n",n,x,n*x);
}

int main()
{
    int n=10;
    char choice;
    int flag=0;
    do{
        printf("Enter your choice either a or b, any other to exit\n");
        scanf("%c",&choice);
        switch(choice){
            case 'A':
            case 'a': add_10(n);
            break;
            case 'B':
            case 'b': multiply_10(n);
            break;
            default: flag=1;
        }
    }while(flag==0);
return 0;
}