#include<iostream>
#define N 10
#define S 3
using namespace std;
struct Student{
    int roll;
    char name[50];
    int subj_mks[S];
};
void student_input(struct Student &student){
    cout<<"Enter roll number of student:";
    cin>>student.roll;
    cout<<"Enter name of the student:";
    cin>>student.name;
    cout<<"Enter the subject marks in "<<S<<" tests\n";
    for(int i=0;i<S;i++){
        cin>>student.subj_mks[i];
    }

}
float average_two_better(struct Student &student){
    int mini=100000;
    int sum=0;
    for(int i=0;i<S;i++){
        int marks=student.subj_mks[i];
        sum+=marks;
        if(mini>marks) mini=marks;
    }
    sum-=mini;
    return (float)sum/2;
}
void print_student_info(struct Student &student){
    cout<<"Roll:"<<student.roll<<endl<<"Name:"<<student.name<<endl;
    cout<<"Average marks in subject :"<<average_two_better(student)<<endl;
    cout<<endl;
}
int main(){
    struct Student students[N];
    for(int i=1;i<=N;i++){
        cout<<"For student:"<<i<<endl;
        student_input(students[i-1]); 
    }
    for(int i=1;i<=N;i++){
        print_student_info(students[i-1]);
    }

}