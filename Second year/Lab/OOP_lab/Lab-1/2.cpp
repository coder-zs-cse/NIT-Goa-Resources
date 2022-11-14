// Write a C++ program to create a class called STUDENT with data members USN, Name
// and Age. Using inheritance, create the classes UGSTUDENT and PGSTUDENT having
// fields as Semester, Fees and Stipend. Enter the data for at least 5 students. Find the
// semester wise average age for all UG and PG students separately.
#include<iostream>
using namespace std;
class STUDENT{
    int USN;
    char name[50];
    int age;
    public:
    STUDENT(){
        cout<<"USN: ";
        cin>>USN;
        cout<<"Name: ";
        cin>>name;
        cout<<"Age: ";
        cin>>age;
    }
    friend ostream& operator<<(ostream&,STUDENT);
};
ostream& operator<<(ostream &print,STUDENT s){
    print<<"USN: "<<USN<<endl;
    print<<"Name: "<<Name<<endl;
    print<<"Age: "<<age<<endl;
    return print;
}
class UGSTUDENT: public STUDENT{
    int semester;
    float fees;
    float stipend;
    public:
    UGSTUDENT(){
        cout<<"Semester: ";
        cin>>semester;
        cout<<"fees: ";
        cin>>fees;
        cout<<"stipend: ";
        cin>>stipend;
    }
    friend ostream& operator<<(ostream &print,UGSTUDENT s){
        print STUDENT::<< s;
        print<<"Semester: "<<semester<<endl;
        print<<"Fees: "<<fees<<endl;
        print<<"Age: "<<age<<endl;
        return print;
    }
    

};
class PGSTUDENT: public STUDENT{
    int semester;
    float fees;
    float stipend;
};

int main(){
    int n_ug;
    cin>>n_ug;
    int n_pg;
    cin>>n_pg;
    UGSTUDENT *nitgoa_ug = new UGSTUDENT[n_ug];
    UGSTUDENT *nitgoa_pg = new UGSTUDENT[n_pg];
    
    return 0;
}