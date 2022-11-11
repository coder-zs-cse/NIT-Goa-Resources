#include<stdio.h>
typedef struct student{
    int roll;
    char name[100];
    int marks[3];
}st;
void takeinput(st candidate[]){
     for(int i=0;i<5;i++){
        printf("\nFor student %d\n",i+1);
        printf("Enter the following details\n");
        printf("roll:");
        scanf("%d",&candidate[i].roll);
        printf("name:");
        scanf("%s",candidate[i].name);
        for(int j=0;j<3;j++){
            printf("marks in subject %d:",j+1);
            scanf("%d",&candidate[i].marks[j]);
        }
     }
}
void printinput(st candidate[]){
    printf("The details of all the students are as follows\n");
    for(int i=0;i<5;i++){
        printf("\nroll no:%d\nname:%s\n",candidate[i].roll,candidate[i].name);
        for(int j=0;j<3;j++){
            printf("marks in subject %d:%d\n",j+1,candidate[i].marks[j]);
        }
    }
}
void average_st_mks(st candidate[]){
    printf("Enter the serial number(1-5) of the student whose average marks to be known\n");
    int no;
    scanf("%d",&no);
    int sum=0;
    for(int i=0;i<3;i++) sum+=candidate[no-1].marks[i];
    float avg=(float)sum/3;
    printf("The average marks candidate bearing roll:%d is %.2f\n",candidate[no-1].roll,avg);
}
void average_subj_mks(st candidates[]){
    printf("Enter the serial number(1-3) of the subject whose average is to be known\n");
    int subject_number;
    scanf("%d",&subject_number);
    int sum=0;
    for(int i=0;i<5;i++){
        sum+=candidates[i].marks[subject_number-1];
    }
    float avg=(float)sum/5;
    printf("The average score of students in subject no:%d is %.2f\n",subject_number,avg);
}
void swap(st *candidate){
    printf("Enter the serial number(1-5) of student whose subject marks are to be swapped\n");
    int i;
    scanf("%d",&i);
    printf("Enter the serial number(1-3) of two subjects whose marks to be swapped\n");
    int a,b;
    scanf("%d%d",&a,&b);
    int temp=candidate[i-1].marks[a-1];
    candidate[i-1].marks[a-1]=candidate[i-1].marks[b-1];
    candidate[i-1].marks[b-1]=temp;
}
void print_mks_student(st candidate[]){
    printf("Enter the serial number(1-5) of the student you want to print marks\n");
    int n;
    scanf("%d",&n);
    for(int i=0;i<3;i++){
        printf("subject %d: %d mks\n",i+1,candidate[n-1].marks[i]);
    }
}
void upp_to_low(st candidate[]){
    printf("Enter the serial number(1-5) of student you want to convert name to lowercase\n");
    int n;
    scanf("%d",&n);
    int i=0;
    char ch=candidate[n-1].name[i];
    do{
        if(ch>=65 && ch<=90) candidate[n-1].name[i]=ch+32;
        i++;
        ch=candidate[n-1].name[i];
    }while(ch!='\0');
    printf("student name changed to %s\n",candidate[n-1].name);
}
int main(){
    st candidate[5];
    int flag=1;
    char choice;
    do{
        fflush(stdin); // to ignore the last inputted character
        printf("\nEnter the choice from the menu as per mentioned in the question paper\n");
        printf("The choice should be between a-g(lowercase)\nEnter any other character to stop the program\n");
        scanf("%c",&choice);
        switch(choice){
        case 'a':takeinput(candidate);
        break;
        case 'b':printinput(candidate); 
        break;
        case 'c':average_st_mks(candidate);
        break;
        case 'd':average_subj_mks(candidate);
        break;
        case 'e':swap(candidate);
        break;
        case 'f':print_mks_student(candidate);
        break;
        case 'g':upp_to_low(candidate);
        break;
        default: flag=0;
        }
    }while(flag==1);
    return 0;
}
