#include<stdio.h>
#include<math.h>
int main()
{
    int n;
    scanf("%d",&n);
    int root=sqrt(n);
    printf("The factors of %d are:-\n",n);
    for(int i=1;i<root;i++){
        if(n%i==0) printf("%d %d ",i,n/i);
    }
    if(n%root==0) printf("%d",root);
return 0;
}