#include<iostream>
using namespace std;
class DATE{
    int day;
    int month;
    int year;
    public:
    DATE(){}
    DATE(char*);
    int operator-(DATE);
    DATE operator+(int);
    bool operator<(DATE);
    friend ostream& operator<<(ostream &,DATE&);
    ~DATE();
};
int main(){

    cout<<"Enter the first date in dd/mm/yyyy format: ";
    char input[20];
    cin>>input;
    DATE d1(input);
    cout<<d1<<endl;
    cout<<"Enter the second date in dd/mm/yyyy format: ";
    cin>>input;
    DATE d2(input);
    cout<<d2<<endl;
    int num_days = d2-d1;
    
    cout<<"Number of days in between is: "<<num_days<<endl;
    cout<<"Enter the number of days\n";
    int num;
    cin>>num;
    DATE d3 = d1 + num;
    cout<<d1<<" + "<<num<<" = "<<d3;
    return 0;
}
int my_stoi(char *input,int start,int len){
    int output =0;
    for(int i=start;i<start+len;i++){
        output = output*10 + input[i]-'0';
    }
    return output;
}
DATE::DATE(char *input){
    day = my_stoi(input,0,2);
    month = my_stoi(input,3,2);
    year = my_stoi(input,6,4);
}
inline bool is_leap_year(int yy){
    if(yy%400==0) return 0;
    return yy%4 ? 0: 1;
}
inline int days_in_year(int yy){
    return is_leap_year(yy) ? 366 : 365;
}
int days_in_month(int mo,int yy){
    switch(mo){
        case 1:case 3:case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2: 
            if(is_leap_year(yy)) return 29;
            else return 28;
    }
    return -1;
}
bool DATE::operator<(DATE d2){
    if(year<d2.year) return true;
    else if(year>d2.year) return false;
    if(month<d2.month) return true;
    else if(month>d2.month) return false;
    return day<d2.day;
}
int DATE::operator-(DATE d2){
    if(*this<d2) return d2-*this;

    int prefix_days_d1 =0;
    for(int i=1;i<month;i++) prefix_days_d1 += days_in_month(i,year);
    prefix_days_d1 += day;

    int suffix_days_d2=0;
    suffix_days_d2 += days_in_month(d2.month,d2.year)-d2.day;
    for(int i = d2.month+1;i<=12;i++) suffix_days_d2 += days_in_month(i,d2.year);

    int difference = suffix_days_d2 + prefix_days_d1;

    for(int i = d2.year+1 ; i<year ; i++){
        difference += days_in_year(i);
    }
    if(year==d2.year) difference -= days_in_year(year);   // overlap
    return difference;
}
ostream& operator<<(ostream &print,DATE &obj){
    if(obj.day/10 ==0) print<<"0";
    print<<obj.day;
    print<<"/";
    if(obj.month/10 ==0) print<<"0";
    print<<obj.month<<"/";
    print<<obj.year;
    return print;
}
DATE DATE::operator+(int add_days){
    DATE output;
    int dd = day;
    int mm = month;
    int yy = year;
    int current_days = days_in_month(mm,yy) - dd;
    if(add_days > current_days){  
                                    // rounding up the month
        add_days-=current_days;
        mm++;
        if(mm==13) {
            mm=1;
            yy++;
        }
    }
    else{
        dd +=add_days;
        add_days=0;
    }
    while(days_in_month(mm,yy)<add_days){
                                        // rounding up the year
        add_days-=days_in_month(mm,yy);
        mm++;
        if(mm==13) {
            mm=1;
            yy++;
            break;
        }
    }
    while(days_in_year(yy)<add_days){   //locating to the year
        add_days-=days_in_year(yy);
        yy++;
    }
    while(days_in_month(mm,yy)<add_days){ // locating to the month
        add_days-=days_in_month(mm,yy);
        mm++;
    }
    if(add_days!=0) dd = add_days;  // locating to the date
    output.day = dd;
    output.month = mm;
    output.year = yy;

    return output;
}
DATE::~DATE(){}