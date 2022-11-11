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
int vowel_consonant(char *sentence,int *a,int *b){
    int i=0;
    int count=0;
    while(sentence[i]!='\0'){
        char current=sentence[i];
        if((current>=65 && current <=90) ||( current>=97 && current<=122)){
            switch(current){
                case 'a': 
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                case 'A': 
                case 'E':
                case 'I':
                case 'O':
                case 'U': *a=*a+1;
                break;
                default: *b=*b+1;
            }
        }
        i++;
    }
}
int main()
{
    char sentence[1000];
    printf("Enter the string\n");
    input(sentence);
    int count_vowels=0;
    int count_consonants=0;
    vowel_consonant(sentence,&count_vowels,&count_consonants);
    printf("The number of vowels are %d\nThe number of consonants are %d\n",count_vowels,count_consonants);
return 0;
}