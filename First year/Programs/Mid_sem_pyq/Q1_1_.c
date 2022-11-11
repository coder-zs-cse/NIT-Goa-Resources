#include<stdio.h>
int main(){
   printf("Enter the numbers and the operator in between\n");
   float a,b;
   char operator;
   float output;
   scanf("%f %c %f",&a,&operator,&b);
   int is_valid=1;
   switch(operator){
       case '+':output=a+b;
        break;
        case '-': output=a-b;
        break;
        case '*':output=a*b;
        break;
        case '/':output=a/b;
        break;
        default: 
        is_valid=0;
        printf("Invalid character");
   }
  if(is_valid) printf("%f %c %f = %f\n",a,operator,b,output);
}