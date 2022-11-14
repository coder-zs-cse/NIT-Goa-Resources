#include<iostream>
#include<vector>
using namespace std;

struct process{
   int pid;
   int at,bt,ct=0,wt=0,tat=0;
   bool cpu = false;
};

int tm;
vector<process> done;
vector<process>wait;

void check_who_has_arrived(vector<process> &p,vector<process>&wait);
void sort_wait(vector<process>&wait);
void display(vector<process>temp);

int main()
{
   tm = 0;
   vector<process> p;
  
   //cout<<"here";
   
   process temp;
   temp.pid = 1;
   temp.bt =3;
   temp.at=0;
   p.push_back(temp);

   temp.pid=2;
   temp.at = 1;
   temp.bt = 2;
   p.push_back(temp);

   temp.pid=3;
   temp.at = 2;
   temp.bt = 4;
   p.push_back(temp);

   temp.pid=4;
   temp.at = 4;
   temp.bt = 1;
   p.push_back(temp);
   
   
   int size = p.size(); 
   
    while(done.size() < size){

        if(p.size() !=0 )
            check_who_has_arrived(p,wait);
        if(wait.size() != 0)
            sort_wait(wait);
        
            wait[0].bt--;
            if(wait[0].cpu == false){
                wait[0].cpu = true;
                wait[0].wt = tm;
            }
            //wait[0].ct++;
            tm++; 
        
        if(wait[0].bt == 0) {
            wait[0].ct = tm;
            done.push_back(wait[0]);
            wait.erase(wait.begin()); 
        }
    }
    for(int i=0;i<done.size();i++){
        done[i].tat = done[i].ct - done[i].at;
    }
    display(done);

   return 0;
}

void check_who_has_arrived(vector<process> &p,vector<process>&wait)
{ 
   int counter=0;
   for(int i=0;i<p.size();i++)
   {
      if(p[i].at <= tm)
         counter++;
      else 
         break;
   }
   while(counter--)
   {
      //wait[0].wt = tm;
      wait.push_back(p[0]);
      wait[ wait.size()-1 ].wt = tm;
      p.erase(p.begin());
   }
}
void sort_wait(vector<process>&wait){
  for (int step = 0; step < wait.size()-1; ++step) 
  {
      
    for (int i = 0; i <wait.size() - step - 1; ++i) {
      
      if (wait[i].bt > wait[i + 1].bt) {
        
        process temp = wait[i];
        wait[i] = wait[i + 1];
        wait[i + 1] = temp;
      }
    }
}
}

void display(vector<process>temp){
   cout<<"\n";
   if(temp.size()==0){
          cout<<"************empty***********\n"; return;
          }
   
   cout<<"pid\tarrival_time\tburst_time\tcompletion_time\t\twaiting_time\tTurn_around_time\n";

   for(int i=0;i<temp.size();i++)
   {
    cout<<temp[i].pid<<"\t"<<temp[i].at<<"\t\t"<<temp[i].bt<<"\t\t"<<temp[i].ct<<"\t\t\t"<<temp[i].wt<<"\t\t"<<temp[i].tat<<"\n";
   }
}
