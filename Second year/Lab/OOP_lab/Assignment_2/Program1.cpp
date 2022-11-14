#include<iostream>
using namespace std;
struct DATE{
    int day;
    int month;
    int year;
};
void take_date(struct DATE &date){
    char date_format[11];
    cin>>date_format;
    date.day=0;
    for(int i=0;i<2;i++){
        date.day=date.day*10+date_format[i]-48;
    }
    date.month=0;
    for(int i=3;i<5;i++){
        date.month=date.month*10+date_format[i]-48;
    }
    date.year=0;
    for(int i=6;i<10;i++){
        date.year=date.year*10+date_format[i]-48;
    }
}
void print_date(struct DATE &date){
    cout<<date.day<<"/"<<date.month<<"/"<<date.year<<endl;
}
int difference(struct DATE D1,struct DATE D2){
    int output;
    int days1=D1.day+D1.month*30 + D1.year*360;
    int days2=D2.day+D2.month*30 + D2.year*360;
    output=days1-days2;
    return output<0 ? -output : output;
}
struct DATE add_days(struct DATE date, int no_of_days){
    struct DATE D2;
    D2.year = date.year + no_of_days /360;
    no_of_days%=360;
    D2.month = date.month + no_of_days / 30;
    no_of_days%=30;
    if(D2.month>12){
        D2.year+=D2.month/12;
        D2.month%=12;
    }
    D2.day= date.day + no_of_days;
    if(D2.day>30){
        D2.month++;
        if(D2.month>12) {
            D2.month%=12;
            D2.year++;
        }
        D2.day%=30;
    }
    return D2;
}
int main(){
    //For simplicity, this program assumes 30 days in all months and 360 days in all years
    cout<<"Enter two dates in dd/mm/yyyy format"<<endl;
    struct DATE D1;
    take_date(D1);
    struct DATE D2;
    take_date(D2);
    int no_of_days=difference(D1,D2);
    cout<<"Number of days between these two dates is : "<<no_of_days<<endl;
    D2=add_days(D1,no_of_days);
    cout<<"New date of D2 is :";
    print_date(D2);
}