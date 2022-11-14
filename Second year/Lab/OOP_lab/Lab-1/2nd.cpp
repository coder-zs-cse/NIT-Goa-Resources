#include<iostream>
using namespace std;
class STUDENT{
    protected:
    int USN;
    char name[50];
    int age;
};
class UGSTUDENT: public STUDENT{
    int semester;
    float fees;
    float stipend;
    public:
    UGSTUDENT();
    int get_age();
    int get_sem();
    friend ostream& operator<<(ostream &,UGSTUDENT);
};
class PGSTUDENT: public STUDENT{
    int semester;
    float fees;
    float stipend;
    public:
    PGSTUDENT();
    int get_age();
    int get_sem();
    friend ostream& operator<<(ostream &,PGSTUDENT);
};
int main(){
    int n_ug,n_pg;
    cout<<"Enter the number of UG students\n"; 
    cin>>n_ug;
    cout<<"Enter the number of PG students\n"; 
    cin>>n_pg;
    UGSTUDENT *nitgoa_ug = (UGSTUDENT*)malloc(n_ug*sizeof(UGSTUDENT));
    PGSTUDENT *nitgoa_pg = (PGSTUDENT*)malloc(n_pg*sizeof(PGSTUDENT));
    for(int i=0;i<n_ug;i++){
        cout<<"Enter the details for UG student "<<i+1<<":-"<<endl;
        nitgoa_ug[i] = UGSTUDENT();
    }
    for(int i=0;i<n_pg;i++){
        cout<<"Enter the details for PG student "<<i+1<<":-"<<endl;
        nitgoa_pg[i] = PGSTUDENT();
    }
    for(int i=0;i<n_ug;i++){
        cout<<"Details of UG student "<<i+1<<":-"<<endl;
        cout<<nitgoa_ug[i]<<endl;
    }
    for(int i=0;i<n_ug;i++){
        cout<<"Details of PG student "<<i+1<<":-"<<endl;
        cout<<nitgoa_pg[i]<<endl;
    }
    for(int sem = 1;sem<=8;sem++){
        int sum_age=0;
        for(int ug_st=1;ug_st<=n_ug;ug_st++){
            if(nitgoa_ug[ug_st].get_sem()==sem)
                sum_age+= nitgoa_ug[ug_st].get_age();
        }
        if(sum_age>0)
            cout<<"Average age of UG students studying in "<<sem<<" semester is: "<<(float)sum_age/n_ug<<endl;
        else
            cout<<"No UG students are studying in "<<sem<<" semester\n";
    }
    for(int sem = 1;sem<=8;sem++){
        int sum_age=0;
        for(int pg_st=1;pg_st<=n_pg;pg_st++){
            if(nitgoa_pg[pg_st].get_sem()==sem)
                sum_age+= nitgoa_pg[pg_st].get_age();
        }
        if(sum_age>0)
            cout<<"Average age of PG students studying in "<<sem<<" semester is: "<<(float)sum_age/n_pg<<endl;
        else
            cout<<"No PG students are studying in "<<sem<<" semester\n";
    }
    return 0;
}
UGSTUDENT::UGSTUDENT(){
    cout<<"USN: ";
    cin>>USN;
    cout<<"Name: ";
    cin>>name;
    cout<<"Age: ";
    cin>>age;
    cout<<"Semester: ";
    cin>>semester;
    cout<<"fees: ";
    cin>>fees;
    cout<<"stipend: ";
    cin>>stipend;
}
PGSTUDENT::PGSTUDENT(){
    cout<<"USN: ";
    cin>>USN;
    cout<<"Name: ";
    cin>>name;
    cout<<"Age: ";
    cin>>age;
    cout<<"Semester: ";
    cin>>semester;
    cout<<"fees: ";
    cin>>fees;
    cout<<"stipend: ";
    cin>>stipend;
}
ostream& operator<<(ostream &print,UGSTUDENT s){
    print<<"USN: "<<s.USN<<endl;
    print<<"Name: "<<s.name<<endl;
    print<<"Age: "<<s.age<<endl;
    print<<"Semester: "<<s.semester<<endl;
    print<<"Fees: "<<s.fees<<endl;
    print<<"Stipend: "<<s.stipend<<endl;
    return print;
}
ostream& operator<<(ostream &print,PGSTUDENT s){
    cout<<endl;
    print<<"USN: "<<s.USN<<endl;
    print<<"Name: "<<s.name<<endl;
    print<<"Age: "<<s.age<<endl;
    print<<"Semester: "<<s.semester<<endl;
    print<<"Fees: "<<s.fees<<endl;
    print<<"Stipend: "<<s.stipend<<endl;
    return print;
}
int UGSTUDENT::get_age(){
    return age;
}
int PGSTUDENT::get_age(){
    return age;
}
int UGSTUDENT::get_sem(){
    return semester;
}
int PGSTUDENT::get_sem(){
    return semester;
}