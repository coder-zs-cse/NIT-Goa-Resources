// Given  that  an  EMPLOYEE  structure  contains  following  members:  data  members: 
// Employee  number,  Employee  name,  Basic,  DA,  IT,  Net  Salary  and  print  data 
// members. Write a C++ program to read the data of N employee and compute Net 
// salary  of  each  employee  (DA=52%  of  Basic  and  Income  Tax  (IT)  =30%  of  the 
// gross salary).
#include<iostream>
using namespace std;
typedef struct{
    int Employee_number;
    char Employee_name[100];
    long Basic;
    long DA;
    long IT;
    long Net_salary;
}EMPLOYEE;
void take_employee_input(EMPLOYEE &employee){
    cout<<"Enter employee number : ";
    cin>>employee.Employee_number;
    cout<<"Enter employee name : ";
    cin>>employee.Employee_name;
    cin.ignore();
    cout<<"Enter employee basic salary : ";
    cin>>employee.Basic;
}
void salary_calc(EMPLOYEE &employee){
    employee.DA = 0.52 * employee.Basic;
    long gross= employee.Basic + employee.DA;
    employee.IT = 0.30 * gross;
    employee.Net_salary = gross - employee.IT;
}
void print_employee_data(EMPLOYEE employee){
    cout<<endl;
    cout<<"Employee number : "<<employee.Employee_number<<endl;
    cout<<"Employee name : "<<employee.Employee_name<<endl;
    cout<<"Employee basic salary : "<<employee.Basic<<endl;
    cout<<"Employee DA : "<<employee.DA<<endl;
    cout<<"Employee IT : "<<employee.IT<<endl;
    cout<<"Employee net salary : "<<employee.Net_salary<<endl;
}
int main(){
    cout<<"Enter the number of employees : ";
    int n;
    cin>>n;
    EMPLOYEE *employee=new EMPLOYEE[n];
    for(int i=0;i<n;i++){
        take_employee_input(employee[i]);
    }
    for(int i=0;i<n;i++){
        salary_calc(employee[i]);
    }
    for(int i=0;i<n;i++){
        print_employee_data(employee[i]);
    }
    return 0;

}