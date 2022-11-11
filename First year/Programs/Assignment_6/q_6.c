#include<stdio.h>
void input(char *sentence){
    int i=0;
    char c;
    do{
        c=getchar();
        sentence[i]=c;
        i++;
    }while(c!='\n');
    sentence[i-1]='\0';
}
int is_present(char *sentence,char c){
    int i=0;
    while(sentence[i]!='\0'){
        if(sentence[i]==c) return 1;
        i++;
    }
    return 0;
}
int main()
{
    char sentence[1000];
    printf("Enter the string\n");
    input(sentence);
    char c;
    printf(" Enter the character \n");
    scanf("%c",&c);
    if(is_present(sentence,c)) printf("%c is present in the given string\n",c);
    else printf("%c is not there is the given string\n",c);
return 0;
}