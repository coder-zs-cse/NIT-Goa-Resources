#include<stdio.h>
int main(){
    int array[6][3];
    for(int i=0;i<6;i++){
        printf("Enter the marks of student %d:-\n",i+1);
        for(int j=0;j<3;j++){
            printf("subject %d:",j+1);
            scanf("%d",&array[i][j]);
        }
    }
    float avg_student[6];
    for(int i=0;i<6;i++){
        int sum=0;
        for(int j=0;j<3;j++) sum+=array[i][j];
        avg_student[i]=(float)sum/3;
    }
    float avg_subject[3];
    for(int i=0;i<3;i++){
        int sum=0;
        for(int j=0;j<6;j++) sum+=array[j][i];
        avg_subject[i]=(float)sum/6;
    }
    for(int i=0;i<6;i++) printf("The average marks of student %d is %.1f\n",i+1,avg_student[i]);
    printf("\n");
    for(int i=0;i<3;i++) printf("Thr average marks of subject %d is %.1f\n",i+1,avg_subject[i]);
}