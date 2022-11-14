#include<iostream>
#define error() cout<<"Error!wrong input value,please try again:"<<endl
using namespace std;

typedef struct {
int dd,mm,yyyy;

}DATE;

bool isleapyear(int year){
 
   if (year % 400 == 0) {
      return true;
   }
   
   else if (year % 100 == 0) {
    return false;
   }
   
   else if (year % 4 == 0) {
     return true;
   }
   else {
      return false;
   }

}

int Difference(DATE D1,DATE D2)
{

 int i,nod1,nod2,nody,lc,no_of_days;
 nod1=nod2=lc=no_of_days=0;

  for(i=1;i<D1.mm;i++)
 {
     if(i==1||i==3||i==5||i==7||i==8||i==10||i==12)
     nod1+=31;
     else if(i==2)
     nod1+=28;
     else
     nod1+=30;
 }

 nod1+=D1.dd;

 for(i=1;i<D2.mm;i++)
 {
         if(i==1||i==3||i==5||i==7||i==8||i==10||i==12)
         nod2+=31;
        else if(i==2)
        nod2+=28;
        else
        nod2+=30;
 }

 nod2+=D2.dd;
nody=(D1.yyyy-D2.yyyy)*365;

 for(i=D2.yyyy;i<D1.yyyy;i++)
 if((i%4)==0)
 lc++;

 int y4=D1.yyyy-D2.yyyy;
 while(y4>400)
 {
 lc++;
 y4-=400;
 }

 if((D1.mm>2) && (D1.yyyy%4)==0)
 lc++;
 if((D2.mm>2) && (D2.yyyy%4)==0)
 lc--;

 no_of_days=nody+nod1-nod2+lc;

return no_of_days;
}

void getDate(int* day,int* month,int* year){

    int dd,mm,yyyy;
    cout<<"Enter day in the format dd/mm/yyyy:"<<endl;
     START:
     cin>>dd>>mm>>yyyy;
     if((mm==2) && (dd>29))
{

error();
 goto START;

 }

 if((mm>12)||(dd>31))
 {


error();
 goto START;

}

 if((mm==4||mm==6||mm==9||mm==11) && (dd>30))
 {

error();

 goto START;

 }

 if(!isleapyear(yyyy) && (mm==2) && (dd>28))
 {


error();
 goto START;

 }
*day=dd;
*month=mm;
*year=yyyy;
}

 DATE Add_days(DATE D1,int days)
{
 DATE D2;
int dd=D1.dd;
int mm=D1.mm;
int yyyy=D1.yyyy;
 while(days>365)
 {
 yyyy++;
 days-=365;
 }

 while(days>30)
 {
 if(mm==1||mm==3||mm==5||mm==7||mm==8||mm==10||mm==12)
 {
 days-=31;
 mm++;
 }
 else if(mm==2)
 {
 days-=28;
 mm++;
 }
 else
 {
 days-=30;
 mm++;
 }

 if(mm>12)
 {
 yyyy++;
 mm=1;
 }
 }

 dd=dd+days;
 if(dd>30)
 {
 if(mm==4||mm==6||mm==9||mm==11)
 {
 mm++;
 dd-=30;
 }
 else if(mm==2)
 {
 mm++;
 dd-=28;
 }
 else if(dd>31)
 {
 mm++;
 dd-=31;
 }
 if(mm>12)
 {
 yyyy++;
 mm=1;
 }
 }

 D2.mm=mm;
 D2.dd=dd;
 D2.yyyy=yyyy;

 return(D2);
}

int main(){
DATE D1,D2;

       cout<<"Enter date of D1:"<<endl;
    getDate(&D1.dd,&D1.mm,&D1.yyyy);
    cout<<"D1 is:"<<endl;
    cout<<D1.dd<<"/"<<D1.mm<<"/"<<D1.yyyy<<endl;

     cout<<"Enter date of D2:"<<endl;
    getDate(&D2.dd,&D2.mm,&D2.yyyy);
     cout<<"D2 is:"<<endl;
 cout<<D2.dd<<"/"<<D2.mm<<"/"<<D2.yyyy<<endl;



int No_of_days=Difference(D1,D2);
 cout<<"Difference of days of date D1 and D2 is :"<<No_of_days<<endl;


 cout<<"Enter number of days you wish to add:"<<endl;
 cin>>No_of_days;
D2=Add_days(D1,No_of_days);

cout<<"New date after addition of days is:"<<endl;
 cout<<D2.dd<<"/"<<D2.mm<<"/"<<D2.yyyy<<endl;
    return 0;
}