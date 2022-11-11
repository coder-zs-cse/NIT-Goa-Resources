#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<time.h>


int main()
{   int guess;
    bool flag;
    flag=false;
    int n=0;
    //to generate a random number 
    srand(time(0));
    int num=rand()%100+1;


    printf("\n\nWelcome to the  number guessing game.\nYou have to guess a particular number\nbetween 1 to 100 within 7 tries\n\nEnter your first guess\n\n");

    while(!flag)
    {   if(n>=1 && !flag)
        {
            printf("Number of chances left --> %d\n\n",7-n);
        }

        scanf("%d",&guess);

        n++;

        if(n==7 && guess!=num)
        {   printf("The original number was %d \nLooks like you couldnt find the number within 7 tries.\nBetter luck next time.",num);
            break;
        }
        if(guess>num)
        {
            printf("\nLower number please!\n");

        }
        else if(guess<num)
        {
            printf("\nHigher number please!\n");

        }

        else if(guess==num)
        {
            printf("You have guessed the original number %d in %d tries",num,n);
            flag=true;
            break;
        }
    }


return 0;
}