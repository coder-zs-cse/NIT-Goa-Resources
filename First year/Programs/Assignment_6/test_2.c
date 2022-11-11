#include<stdio.h>
int lengthi(char a[]){
    int i=0;
    int size=0;
    while(a[i]!='\0'){
        i++;
        size++;
    }
    return size;
}
int palindrome(char a[],int size){
    int i=0,j=size-1;
    while(i<j){
        if(a[i]!=a[j]) return 0;
        i++;
        j--;
    }
    return 1;
}
int main(){
    char string[3][100];
    scanf("%s%s%s",string[0],string[1],string[2]);
    for(int i=0;i<3;i++){
        int length=lengthi(string[i]);
        printf("the length of %d string is %d",i+1,length);
        if(palindrome(string[i],length))
        printf("\n %s is a palindrome\n",string[i]);
        else 
        printf("\n %s is not a palindrome\n",string[i]);
    }
    return 0;
}