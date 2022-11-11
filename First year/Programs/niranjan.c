// Problem_1
/*Write a program to store following details of a student.
a) Roll number
b) Name
c) Marks in 3 subjects
A) The program should store the details for 5 students.
B) Should be able to display information of all the students present.
C) Give the average of marks in all the subjects for a specific student.
D) Give the average marks of a particular subject.
E) Swap the marks in any given 2 subjects, for a particular student.
F) Should be able to display all marks of any specified student.
G) Convert the student name to lower case in case any letters are in
uppercase.
Create a menu for the above said functionalities.*/
#include <stdio.h>
struct student{
    char firstName[50];
    int roll;
    float marks_1;
    float marks_2;
    float marks_3;
}s[10000];
void storestudents(){
 int i;
    printf("Enter information of students:\n");

    // storing information for five students
    for (i = 0; i < 5; ++i) {
        s[i].roll = i + 1;
        printf("\nFor roll number:%d,\n", s[i].roll);
        printf("Enter first name: ");
        scanf("%s", s[i].firstName);
        printf("Enter marks in subject 1: ");
        scanf("%f", &s[i].marks_1);
        printf("Enter marks in subject 2: ");
        scanf("%f", &s[i].marks_2);
        printf("Enter marks in subject 3: ");
        scanf("%f", &s[i].marks_3);
    }
    printf("\n\n\n");
    main();
};
    void displaystudents(){
printf("Displaying Information:\n\n");

    // displaying the information
    for (int i = 0; i < 5; ++i) {
        printf("\nRoll number: %d\n", i + 1);
        printf("First name: ");
        puts(s[i].firstName);
        printf("Marks in subject_1: %.1f\n", s[i].marks_1);
         printf("Marks in subject_2: %.1f\n", s[i].marks_2);
         printf("Marks in subject_3: %.1f\n", s[i].marks_3);


        printf("\n");
    }


    main();
    };
    void averagestudent(){
        int i;
        float avg;

printf("Enter the roll number of the student:\n");
scanf("%d",&i);
avg=(s[i].marks_1+s[i].marks_2+s[i].marks_3)/3;
printf("The Average marks for the given student is %f\n",avg);
printf("\n\n\n");
main();
    }
void averagemarks(){
    printf("Choice the subject of interest:\n1.Subject_1\n2.Subject_2\n3.Subject_3\n");
    int choice;
    scanf("%d",&choice);
    switch(choice){
        float avg=0;
        float sum=0;
        int i;
        case 1:
for(i=0;i<=5;i++){
    sum+=s[i].marks_1;
}
avg=sum/5;
printf("The average marks in subject_1 is %f\n",avg);
main();

break;
 case 2:
for(i=0;i<=5;i++){
    sum+=s[i].marks_2;
}
avg=sum/5;
printf("The average marks in subject_2 is %f\n",avg);
main();

break;
case 3:
for(i=0;i<=5;i++){
    sum+=s[i].marks_3;
}
avg=sum/5;
printf("The average marks in subject_3 is %f\n",avg);
main();

break;


default:
printf("Error!Wrong input value!\n");
main();

break;
printf("\n\n\n");


    }
}



  void displaymarks(){
           int i;

printf("Enter the roll number of the student:\n");
scanf("%d",&i);
  printf("Marks in subject_1: %.1f\n", s[i].marks_1);
  printf("Marks in subject_2: %.1f\n", s[i].marks_2);
   printf("Marks in subject_3: %.1f\n", s[i].marks_3);
   printf("\n\n\n");
   main();

    }

 void swap(){
        int i;

printf("Enter the roll number of the student:\n");
scanf("%d",&i);
     int choice;
     printf("Marks of which two subjects would you like to swap?\n1.subject 1&2\n2.subject 2&3\n3.subject 3&1\n");
scanf("%d",&choice);
     switch(choice){
         case 1:
         s[i].marks_1== s[i].marks_2+s[i].marks_1;
          s[i].marks_2== s[i].marks_1-s[i].marks_2;
           s[i].marks_1== s[i].marks_1-s[i].marks_2;
           main();
           break;
           case 2:
            s[i].marks_2== s[i].marks_3+s[i].marks_2;
          s[i].marks_3== s[i].marks_2-s[i].marks_1;
           s[i].marks_2== s[i].marks_2-s[i].marks_3;
           main();
           break;
           case 3:
           s[i].marks_1== s[i].marks_3+s[i].marks_1;
          s[i].marks_3== s[i].marks_1-s[i].marks_3;
           s[i].marks_1== s[i].marks_1-s[i].marks_3;
           main();
           break;
           default:
           printf("Error! wrong input!\n");
           main();
           break;
           printf("\n\n\n");

     }
 }


int main() {
   
    
        int choice;
         printf("Please Press:\n1.To store details for 5 students \n2.To display information of all the students present.\n3.To give average marks in all subjects for a specific student\n4.To give average marks in a particular subject\n5.To swap the marks of any two given subjects\n6.to display all marks of any particular student\n7.To convert the name to lower case in case any letter is in uppercase\nPress any other key to exit\n\n\n");
    printf("\n");
    scanf("%d",&choice);
    switch (choice){
    case 1:
        storestudents();
        break;
    case 2:
       displaystudents();
        break;
    case 3:
      averagestudent();
      break;
   case 4:
   averagemarks();
   case 5:
   swap();
    break;

   case 6:
   displaymarks();
    break;


    default:
        printf("----------------------------------END----------------------------------------\n\n");
    }
    
    return 0;
}    
   








	 
 
 
 
