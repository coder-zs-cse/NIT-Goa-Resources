#include<stdio.h>
#include<stdlib.h>
int stoi(char *str){
    //the argv passed by the command lines to the main function is in char format
    //we need to convert them into int before adding up
    
    int num=0;
    for(int i=0;str[i]!='\0';i++){   //we iterate from left to right of number till null character is found
        num=num*10+str[i]-48;  //converting the ascii code of current char to int and updating num
    }
    return num;
}
int main(int argc,char **argv){ //taking input from the command line
    //Example how to input through command line
    // g++ 2.c -o 2
    // .\2 45 584
    printf("%s + %s = %d",argv[1],argv[2],stoi(argv[1])+stoi(argv[2]));
return 0;
}