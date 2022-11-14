#include<bits/stdc++.h>
using namespace std;

class Process{
    int pid;
    int arrivalTime;
    int burstTime;
    int completionTime;
    int waitingTime;
    int turnAroundTime;
    int priority;
    public:
    void inputProcesses(unordered_map<int,int> &p,int i){
        cout<<"pid: ";
        cin>>pid;
        cout<<"arrival time: ";
        cin>>arrivalTime;
        cout<<"burst time: ";
        cin>>burstTime;

        p[pid] = i;
    }    
    
    
    friend class CPU;
};

class CPU{
    
    Process runningQueue;
    int time;
    static bool compareArrivalTime(Process &a,Process &b){
        return a.arrivalTime<b.arrivalTime;
    }
    static bool compareBurstTime(Process &a,Process &b){
        return a.burstTime<b.burstTime;
    }
    static bool comparePriority(Process &a,Process &b){
        return a.priority<b.priority;
    }

    public:
    CPU(){
        time=0;
    }
    void displayProcesses(vector<Process> &processes,int n){
        cout<<setw(4)<<"pid"<<setw(15)<<"ArrivalTime"<<setw(15)<<"BurstTime"<<setw(20)<<"CompletionTime"<<setw(15)<<"WaitingTime"<<setw(20)<<"TurnAroundTime"<<endl;
        for(int i=0;i<n;i++){
            cout<<setw(3)<<processes[i].pid<<setw(9)<<processes[i].arrivalTime<<setw(19)<<processes[i].burstTime<<setw(18)<<processes[i].completionTime<<setw(14)<<processes[i].waitingTime<<setw(19)<<processes[i].turnAroundTime<<endl;
        }
    }

    void FCFS(vector<Process> &processes,int n,unordered_map<int,int> &p){
        vector<Process> readyQueue = processes;
        sort(readyQueue.begin(),readyQueue.end(),compareArrivalTime);
        int id;
        for(int i=0;i<n;i++){
            id = readyQueue[i].pid;
            processes[p[id]].completionTime = processes[p[id]].burstTime +  (time > processes[p[id]].arrivalTime ? time : processes[p[id]].arrivalTime);
            processes[p[id]].waitingTime = processes[p[id]].completionTime - processes[p[id]].arrivalTime - processes[p[id]].burstTime;
            processes[p[id]].turnAroundTime = processes[p[id]].waitingTime + processes[p[id]].burstTime;
            time = processes[p[id]].completionTime;
        }
    }

    void SJF(vector<Process> &processes,int n,unordered_map<int,int> &p){
        vector<Process> jobQueue = processes;
        vector<Process> readyQueue;
        sort(jobQueue.begin(),jobQueue.end(),compareArrivalTime);

        while(!jobQueue.empty() || !readyQueue.empty()){

            if(!jobQueue.empty() && time<jobQueue[0].arrivalTime){  // CPU idle time
                time = jobQueue[0].arrivalTime;
            }

            while(!jobQueue.empty() && time>=jobQueue[0].arrivalTime){ //transfer the processes that have arrived from jobqueue to readyqueue
                readyQueue.push_back(jobQueue[0]);
                jobQueue.erase(jobQueue.begin());
            }

            sort(readyQueue.begin(),readyQueue.end(),compareBurstTime);
            int id = readyQueue[0].pid;
            processes[p[id]].completionTime = time + processes[p[id]].burstTime;
            processes[p[id]].waitingTime = processes[p[id]].completionTime - processes[p[id]].arrivalTime - processes[p[id]].burstTime;
            processes[p[id]].turnAroundTime = processes[p[id]].waitingTime + processes[p[id]].burstTime;

            time = processes[p[id]].completionTime;
            readyQueue.erase(readyQueue.begin());
        }

    }
    
    void SRJF(vector<Process> &processes,int n,unordered_map<int,int> &p){
        vector<Process> jobQueue = processes;
        vector<Process> readyQueue;
        sort(jobQueue.begin(),jobQueue.end(),compareArrivalTime);

        while(!jobQueue.empty() || !readyQueue.empty()){
            
            if(!jobQueue.empty() && time<jobQueue[0].arrivalTime){
                time = jobQueue[0].arrivalTime;
            }
            while(!jobQueue.empty() && time>=jobQueue[0].arrivalTime){ //transfer the processes that have arrived from jobqueue to readyqueue
                readyQueue.push_back(jobQueue[0]);
                jobQueue.erase(jobQueue.begin());
            }

            int timelimit = jobQueue.empty() ? -1 : jobQueue[0].arrivalTime;
            sort(readyQueue.begin(),readyQueue.end(),compareBurstTime);

            if(timelimit!=-1 && timelimit - time <= readyQueue[0].burstTime){
                readyQueue[0].burstTime -= timelimit - time;
                time = timelimit;
            }
            else{
                int id = readyQueue[0].pid;
                processes[p[id]].completionTime = time + readyQueue[0].burstTime;
                processes[p[id]].waitingTime = processes[p[id]].completionTime - processes[p[id]].arrivalTime - processes[p[id]].burstTime;
                processes[p[id]].turnAroundTime = processes[p[id]].waitingTime + processes[p[id]].burstTime;

                time = processes[p[id]].completionTime;
                readyQueue.erase(readyQueue.begin());
            }
        }

    }
    void RR(vector<Process> &processes,int n,unordered_map<int,int> p){
        cout<<"time_quantum:";
        int timeQuantum;
        cin>>timeQuantum;
        vector<Process> jobQueue = processes;
        vector<Process> readyQueue;
        sort(jobQueue.begin(),jobQueue.end(),compareArrivalTime);
        Process lastExecuted;
        bool lastPending = false;
        while(!jobQueue.empty() || !readyQueue.empty() || lastPending){
            
            if(!jobQueue.empty() && time<jobQueue[0].arrivalTime){ // CPU idle time
                time = jobQueue[0].arrivalTime;
            }
            
            while(!jobQueue.empty() && time>=jobQueue[0].arrivalTime){ //transfer the processes that have arrived from jobqueue to readyqueue
                readyQueue.push_back(jobQueue[0]);
                jobQueue.erase(jobQueue.begin());
            }
            if(lastPending) readyQueue.push_back(lastExecuted);

            if(timeQuantum < readyQueue[0].burstTime){
                readyQueue[0].burstTime -= timeQuantum;
                time += timeQuantum;
                lastExecuted = readyQueue[0];
                readyQueue.erase(readyQueue.begin());
                lastPending = true;
            }
            else{
                int id = readyQueue[0].pid;
                processes[p[id]].completionTime = time + readyQueue[0].burstTime;
                processes[p[id]].waitingTime = processes[p[id]].completionTime - processes[p[id]].arrivalTime - processes[p[id]].burstTime;
                processes[p[id]].turnAroundTime = processes[p[id]].waitingTime + processes[p[id]].burstTime;

                time = processes[p[id]].completionTime;
                readyQueue.erase(readyQueue.begin());
                lastPending = false;
            }
        }
    }
    void PRIORITY(vector<Process> &processes,int n,unordered_map<int,int> &p){
        for(int i=0;i<n;i++){
            cout<<"Priority of process with pid "<<processes[i].pid<<": ";
            cin>>processes[i].priority;
        }
        vector<Process> jobQueue = processes;
        vector<Process> readyQueue;
        sort(jobQueue.begin(),jobQueue.end(),compareArrivalTime);

        while(!jobQueue.empty() || !readyQueue.empty()){
            
            if(!jobQueue.empty() && time<jobQueue[0].arrivalTime){
                time = jobQueue[0].arrivalTime;
            }
            while(!jobQueue.empty() && time>=jobQueue[0].arrivalTime){ //transfer the processes that have arrived from jobqueue to readyqueue
                readyQueue.push_back(jobQueue[0]);
                jobQueue.erase(jobQueue.begin());
            }

            sort(readyQueue.begin(),readyQueue.end(),comparePriority);
            int id = readyQueue[0].pid;
            processes[p[id]].completionTime = time + readyQueue[0].burstTime;
            processes[p[id]].waitingTime = processes[p[id]].completionTime - processes[p[id]].arrivalTime - processes[p[id]].burstTime;
            processes[p[id]].turnAroundTime = processes[p[id]].waitingTime + processes[p[id]].burstTime;

            time = processes[p[id]].completionTime;
            readyQueue.erase(readyQueue.begin());
            
        }
    }
};

int main(){

    int n;
    cout<<"Enter the number of processes: ";
    cin>>n;
    vector<Process> processes(n);
    unordered_map<int,int> p;
    for(int i=0;i<n;i++){
        processes[i].inputProcesses(p,i);
    }

    CPU CPU;  //CPU initialization


    CPU.FCFS(processes,n,p);

    // CPU.SJF(processes,n,p);

    // CPU.SRJF(processes,n,p);

    // CPU.RR(processes,n,p);

    // CPU.PRIORITY(processes,n,p);

    CPU.displayProcesses(processes,processes.size());



    return 0;
}