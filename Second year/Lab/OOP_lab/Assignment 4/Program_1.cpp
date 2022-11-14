#include<iostream>
#include<string.h>
using namespace std;
class EMPLOYEE{
    public:
    int Employee_number;
    char Employee_Name[50];
    int Basic;
    
    void employee_init(int,char[],int);
    void calculate_Net_salary();
    void print();
    private:
    int DA;
    int IT;
    int Net_Salary;

};
void EMPLOYEE::employee_init(int num,char name[],int salary){
    Employee_number = num;
    strcpy(Employee_Name,name);
    Basic = salary;
    calculate_Net_salary();
}
void EMPLOYEE::calculate_Net_salary(){
    DA = (0.52 * Basic);
    IT = 0.3 * (Basic + DA);
    Net_Salary = Basic + DA - IT;
}
void EMPLOYEE::print(){
    cout<<"Employee Name : "<<Employee_Name<<endl;
    cout<<"Employee Number : "<<Employee_number<<endl;
    cout<<"Employee Basic Salary : "<<Basic<<endl;
    cout<<"Employee DA : "<<DA<<endl;
    cout<<"Employee IT : "<<IT<<endl;
    cout<<"Employee Net salary : "<<Net_Salary<<endl;
    cout<<endl;
}

int main(){

    printf("Enter the numbero of employees\n");
    int n;
    cin>>n;
    printf("Enter the data of employees one by one\n");
    EMPLOYEE *employee=new EMPLOYEE[n];
    for(int i=0;i<n;i++){
        int num,salary;
        char name[50];
        printf("Enter the Employee number : ");
        cin>>num;
        printf("Enter the Employee name : ");
        cin>>name;
        printf("Enter the Employee salary : ");
        cin>>salary;
        employee[i].employee_init(num,name,salary);
    }
    cout<<"\nThe data of the employees\n\n";
    for(int i=0;i<n;i++){
        employee[i].print();
    }



    return 0;
}