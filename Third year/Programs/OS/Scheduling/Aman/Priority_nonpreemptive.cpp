#include<iostream>
#include<vector>
using namespace std;

struct process{
   int pid;
   int at,bt,ct=0,wt=0,tat=0;
   int pri;
};
int tm;

void display(vector<process>temp);
void sort_wait(vector<process>&wait);
void check_who_has_arrived(vector<process> &p,vector<process>&wait);
vector<process> done;
vector<process> wait;

int main(){
    tm = 0;
   vector<process> p;

   process temp;
   temp.pid = 1;
   temp.bt =3;
   temp.at=0;
   temp.pri = 2;
   p.push_back(temp);

   temp.pid=2;
   temp.at = 1;
   temp.bt = 2;
   temp.pri = 0;
   p.push_back(temp);

   temp.pid=3;
   temp.at = 2;
   temp.bt = 4;
   temp.pri = 1;
   p.push_back(temp);

   temp.pid=4;
   temp.at = 4;
   temp.bt = 4;
   temp.pri = 3;
   p.push_back(temp);
   
   
   int size = p.size();

   //first process that arrives will completely run
   tm = p[0].at;

   p[0].ct = p[0].at + p[0].bt;
   
   tm = p[0].ct;

   done.push_back(p[0]);
   p.erase(p.begin());

   check_who_has_arrived(p,wait);
   sort_wait(wait);
   
   while(wait.size() != 0)
   {
      wait[0].ct = tm + wait[0].bt;
      wait[0].wt = tm;;
      tm = wait[0].ct;
      done.push_back(wait[0]);
      wait.erase(wait.begin());
      
      if(p.size() !=0)
         check_who_has_arrived(p,wait);
      if(wait.size() != 0)
         sort_wait(wait); 
   }

   for(int i=0;i<done.size();i++){
      done[i].tat = done[i].ct - done[i].at;
      done[i].wt = done[i].tat - done[i].bt;
   } 
      cout<<"Process vector\n";
      display(p);
      cout<<"Done processes\n";
      display(done);
      cout<<"Waiting processes\n";
      display(wait);
  return 0;

}

void display(vector<process>temp){
   cout<<"\n";
   if(temp.size()==0){
          cout<<"************empty***********\n"; return;
          }
   
   cout<<"pid\tarrival_time\tburst_time\tpriority\tcompletion_time\t\twaiting_time\tTurn_around_time\n";

   for(int i=0;i<temp.size();i++)
   {
    cout<<temp[i].pid<<"\t"<<temp[i].at<<"\t\t"<<temp[i].bt<<"\t\t"<<temp[i].pri<<"\t\t\t"<<temp[i].ct<<"\t\t\t"<<temp[i].wt<<"\t\t"<<temp[i].tat<<"\n";
   }
}

void sort_wait(vector<process>&wait){
  for (int step = 0; step < wait.size()-1; ++step) 
  {
      
    for (int i = 0; i <wait.size() - step - 1; ++i) {
      
      if (wait[i].pri > wait[i + 1].pri) {
        
        process temp = wait[i];
        wait[i] = wait[i + 1];
        wait[i + 1] = temp;
      }
    }
}
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
      wait.push_back(p[0]);
      p.erase(p.begin());
   }
}