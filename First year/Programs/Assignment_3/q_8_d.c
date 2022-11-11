#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    // for(int i=1;i<=n;i++){
        int i=1;
        while(i<=n){
        // for(int j=0;j<n+i-1;j++) {
            int j=0;
            while(j<n+i-1){
            if(j<n-i) printf(" ");
            else {
                printf("%d ",i);
               j++;
            }
            j++;
            }
            i++;
        
        printf("\n");
    }
return 0;
}