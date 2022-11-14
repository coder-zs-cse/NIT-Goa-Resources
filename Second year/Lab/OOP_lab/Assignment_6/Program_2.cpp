#include<iostream>
using namespace std;

class DATE{
    int day;
    int month;
    int year;
    int date_to_days();
    DATE days_to_date(int);
    public:
    DATE(int,int,int);
    int operator-(DATE&);
    DATE operator+(int);
    friend ostream&operator<<(ostream&,DATE&);
};

int main(){
    cout<<"Enter date in dd mm yyyy format\n";
    int a,b,c;
    cin>>a>>b>>c;
    DATE d1(a,b,c);
    cout<<"Enter date in dd mm yyyy format\n";
    cin>>a>>b>>c;
    DATE d2(a,b,c);
    int  numberofdays = d1 - d2;
    cout<<"Number of days in between : "<<numberofdays<<endl;
    int k;
    cout<<"Enter the number of days\n";
    cin>>k;
    DATE d3 = d1 + k;

    cout<<d3;
    return 0;
}

bool isleapyear(int year){ //to check whether the year is leap year or not
    if(year%100==0) return year%400==0;
    return year%4==0;
}
int daysinmonth(int month,int year){ //returns the number of days  in a month
    switch(month){
        case 12: 
        case 10:
        case 8:
        case 7:
        case 5:
        case 3:
        case 1: return 31;
        
        case 2:  
                if(isleapyear(year)) return 29;
                return 28;
        default:
                return 30;
    }
}
int days_in_a_year(int year){ //returns number of days in a year
    if(isleapyear(year)) return 366;
    return 365;
}



DATE::DATE(int a,int b,int c){ //constructor of date
    day=a;
    month=b;
    year=c;
}
int DATE::date_to_days(){   //converts date to absolute sum of days
    int total_days=0;
    int yr = year;
    while(yr>0){
        if(isleapyear(yr))  total_days+=366;
        else total_days+=365;
        yr--;
    }
    int mt = month;
    while(mt>1){
        int num_days = daysinmonth(mt,yr);
        total_days+=num_days;
        mt--;
    }
    total_days+=day;
    return total_days;
}
DATE DATE::days_to_date(int total_days){ //converts the total number of days to date
    int dy=0,mt=1,yr=0;
    int days = total_days;
    while(total_days>days_in_a_year(yr)){
        total_days-=days_in_a_year(yr);
        yr++;
    }
    
    while(total_days>daysinmonth(mt,yr)){
        mt++;
        total_days-=daysinmonth(mt,yr);
    }
    dy+=total_days;
    DATE output(dy,mt,yr);
    return output;

}

int DATE::operator-(DATE& date2){
    int totaldays1 = date_to_days();
    int totaldays2 = date2.date_to_days();
    return totaldays1 - totaldays2;
}
DATE DATE::operator+(int add_days){
    int total_days = add_days + date_to_days();
    return days_to_date(total_days);
}
ostream& operator<<(ostream& print,DATE &d){
    print<<endl;
    print<<d.day<<"/"<<d.month<<"/"<<d.year<<endl;
    return print;
}