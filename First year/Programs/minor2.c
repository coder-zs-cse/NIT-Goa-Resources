#include<stdio.h>
#define take(n) scanf("%d",&n);
#define rep(i,a,b) for(int i=a;i<b;i++)
int number_of_bits(char a[]){
    int i=0;
    while(a[i]!='\0'){
        i++;
    }
    return i;
}
int powi(int a,int b){
    if(b==0) return 1;
    return a*powi(a,--b);
}
int string_to_decimal(char c[],int length){
    int binary=0;
    int i=0;
    while(c[i]!='\0'){
        binary+=(c[i]-48)*powi(2,length-i-1);
        i++;
    }
    printf("Number of bits in %s is %d\n",c,i);
    return binary;
}
int decimal_to_binary(int decimal){
    int i=0;
    int binary=0;
    while(decimal>0){
        int rem=decimal%2;
        binary+=rem*powi(10,i);
        i++;
        decimal/=2;
    }
    return binary;
}
int main()
{
    char binary[3][100];
    int no_bit[3];
    rep(i,0,3) scanf("%s",binary[i]);
    rep(i,0,3){
        no_bit[i]=number_of_bits(binary[i]);
        printf("the number of bits in %s is %d\n",binary[i],no_bit[i]);
    }
    int decimal_no[3];
    rep(i,0,3) {
        decimal_no[i]=string_to_decimal(binary[i]);
        printf("%d:%d\n",i+1,decimal_no[i]);
    }
    int sum=0;
    rep(i,0,3) sum+=decimal_no[i];
    int sum_binary=decimal_to_binary(sum);
    printf("The sum in given 3 numbers is\nBinary form:%d\nDecimal form:%d\n",sum,sum_binary);
    
return 0;
}