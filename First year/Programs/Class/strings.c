#include<stdio.h>
int main()
{
    char line[80];
    int c=0;
    char ch;
    do{
        ch=getchar();
        line[c]=ch;
        c++;
    }while(ch!='\n');
    line[c-1]='\0';
    printf("%s",line);
return 0;
}