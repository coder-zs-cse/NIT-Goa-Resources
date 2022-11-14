
// sorting is not working in 
// the function first_process_run

#include<iostream>
#include<vector>
using namespace std;

struct process{
   int pid;
   int at,bt,ct=0,wt=0,tat=0;
};
int tm;

vector<process> done;
vector<process>wait;

void first_process_run(vector<process>&p);
void check_who_has_arrived(vector<process> &p,vector<process>&wait);
void display(vector<process>temp);
void sort_wait(vector<process>&wait);
void add_process_to_p(vector<process>&p,int n);
int main()
{
   tm = 0;
   int ideal_time;
   vector<process> p;
   int n;
   cout<<"enter number of processes\n";
   cin>>n;
   add_process_to_p(p,n);

   //cout<<"here";
   
   // process temp;
   // temp.pid = 1;
   // temp.bt =3;
   // temp.at=0;
   // p.push_back(temp);

   // temp.pid=2;
   // temp.at = 1;
   // temp.bt = 2;
   // p.push_back(temp);

   // temp.pid=3;
   // temp.at = 2;
   // temp.bt = 4;
   // p.push_back(temp);

   // temp.pid=4;
   // temp.at = 4;
   // temp.bt = 4;
   // p.push_back(temp);
   
   int size = p.size();       //size of job queue p
   
   first_process_run(p);

   p[0].ct = p[0].at + p[0].bt;
   
   tm = p[0].ct;
   ideal_time =p[0].at;       // for the first process the ideal time will be arrival time
   done.push_back(p[0]);
   p.erase(p.begin());
   
   check_who_has_arrived(p,wait);
   sort_wait(wait);
   

   while(done.size() < size)
   {
      if(wait.size() ==0 && p.size() !=0){
         tm++;
         ideal_time++;
         check_who_has_arrived(p,wait);
      }

      else{
         wait[0].ct = tm + wait[0].bt + ideal_time;
         tm = wait[0].ct;
         done.push_back(wait[0]);
         wait.erase(wait.begin());
         
         if(p.size() !=0)
            check_who_has_arrived(p,wait);
         if(wait.size() != 0)
            sort_wait(wait); 
   }
   }
   for(int i=0;i<done.size();i++){
      done[i].tat = done[i].ct - done[i].at;
   } 
      cout<<"Process vector\n";
      display(p);
      cout<<"Done processes\n";
      display(done);
      cout<<"Waiting processes\n";
      display(wait);
      cout<<"\n**************************\n"<<"Ideal time = "<<ideal_time;
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
      wait.push_back(p[0]);
      p.erase(p.begin());
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

void first_process_run(vector<process>&p)
{
   int k;
   for(k=0;k<p.size()-1;k++){
      if(p[k].at != p[k+1].at)
         break;
   }
   //sort the processes a/c to the burst time
   for (int step = 0; step < k-1; ++step) 
  {
      
    for (int i = 0; i <k - step - 1; ++i) {
      
      if (p[i].bt > p[i + 1].bt) {
        
        process temp = p[i];
        p[i] = p[i + 1];
        p[i + 1] = temp;
      }
    }
   }
   cout<<"*************************\n";
   display(p);
   cout<<"\n*************************\n";
   cout<<"returned from here";
   return;
}

void add_process_to_p(vector<process>&p,int n){
   for(int i=0;i<n;i++){
      process temp;
      temp.pid = i+1;
      cout<<"enter arrival time for process"<<i+1<<" ";
      cin>>temp.at;

      cout<<"\nenter burst time for process"<<i+1<<" ";
      cin>>temp.bt;
      cout<<endl;
      p.push_back(temp);
   }
}