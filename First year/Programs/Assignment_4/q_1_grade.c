#include<stdio.h>
int main()
{
    int a,b,c,d;
    float avg;
    char grade;
    printf("Enter the marks out of 100 of four subjects of the student\n");
    scanf("%d %d %d %d",&a,&b,&c,&d);
    avg=(float)(a+b+c+d)/4;
    printf("The average is %.1f\n",avg);
    int temp=avg/10;
    switch(temp){
        case 5: grade='E';
        break;
        case 6: grade ='D';
        break;
        case 7: grade='C';
        break;
        case 8: grade='B';
        break;
        case 9:
        case 10: grade='A';
        default:grade='F';
    }
    printf("Final grade of the student is %c\n",grade);
    grade=='F' ? printf("Fail") : printf("Pass");
return 0;
}