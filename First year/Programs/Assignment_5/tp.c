#include<stdio.h>
#include<stdbool.h>
#define take(n) scanf("%d",&n);
#define rep(i,a,b) for(int i=a;i<b;i++)
union exam{
   int cutoff;
   struct{
      int SAT;
      int CAT;
   }foreign;
   struct{
   int NEET;
   int JEE;
   int UPSC;
   }indian;
};
int main()
{
   union exam zub;
   zub.cutoff=2020;
   zub.foreign.SAT=186;
   zub.foreign.CAT=1;
   zub.indian.NEET=2020;
   printf("%d ",zub.foreign.SAT);
   printf("%d ",zub.indian.JEE);
   printf("%d ",zub.indian.NEET);
   // zub.NEET=520;
   // printf("%d ",zub.JEE);
   // printf("%d ",zub.NEET);
   // printf("%d ",zub.UPSC);

return 0;
}