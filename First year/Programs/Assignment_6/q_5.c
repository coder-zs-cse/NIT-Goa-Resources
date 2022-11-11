#include<stdio.h>
int main()
{
    char sentence[1000];
    scanf("%[^\n]",sentence);
    printf("%s",sentence);
return 0;
}