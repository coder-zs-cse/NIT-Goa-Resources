#include<stdio.h>
#include<stdlib.h>
#define take(n) scanf("%d",&n);
#define rep(i,a,b) for(int i=a;i<b;i++)
typedef struct employee{
    char name[50];
    int employee;
    int salary;
    char date[11];
}emp;
void registnew(emp *ward,int *size){
    ward=realloc(ward,(*size+1)*sizeof(emp));
    printf("Name:\n");
    fflush(stdin);
    gets(ward[*size].name);
    printf("Enter the empplyee ID number\n");
    scanf("%d",&ward[*size].employee);
    printf("Enter the salary\n");
    scanf("%d",&ward[*size].salary);
    printf("Enter the joining date\n");
    scanf(" %s",ward[*size].date);
    *size=*size+1;
}
void printdet(emp *ward,int size){
    for(int i=0;i<size;i++){
        printf("Employee name:%s\n",ward[i].name);
        printf("Employee ID:%d",ward[i].employee);
        printf("salary:%d\n",ward[i].salary);
        printf("Date of joining:%s\n",ward[i].date);
        printf("\n");
    }
}

int main()
{
    int size=0;
    emp *ward=(emp*) malloc(sizeof(emp));
    printf("Enter the details of the first employee\n");
    registnew(ward,&size);
    int choice,flag=0;
    while(flag==0){
        printf("Enter \n");
        scanf("%d",&choice);
        switch(choice){
            case 1:registnew(ward,&size);
            break;
            case 2:printdet(ward,size);
            break;
            case 3:printf("size:%d\n",size);
            break;
            // case 4:average_salary(ward,size);
            // break;
            default:flag=1;
        }
    }
    free(ward);
return 0;
}