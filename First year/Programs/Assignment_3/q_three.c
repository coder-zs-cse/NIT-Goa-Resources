#include <stdio.h>
#include<math.h>
int main()
{
    int n;
    scanf("%d",&n);
    int is_prime=1;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0) {
            is_prime=0;
            break;
        }
    }
    printf("%d is ",n);
    if(n==1) is_prime=0;
   is_prime==0 ? printf("not a"):printf("a");
   printf(" prime number\n");
    return 0;
}