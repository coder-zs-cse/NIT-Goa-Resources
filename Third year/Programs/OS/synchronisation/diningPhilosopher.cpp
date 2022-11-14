#include<iostream>
using namespace std;

void wait(int * sem)
{
    if(*sem)
        *sem = *sem -1;
}
void signal(int *sem){
    *sem = *sem+1;
}
int main()
{
    int semaphore[5]={1,1,1,1,1};
    int process[5] ={0,0,0,0,0};
    int resourceaq[5]={0,0,0,0,0};
    while(1){
        cout<<"1. Initiate Process \n"<<"2. Releasing Process\n"<<"3.Running Process\n"<<"4.exit"<<endl;
        int choice;
        cin>>choice;
        switch (choice)
        {
        case 1:
            {
                int idx;
                cout<<"Enter the process number\n";
                cin>> idx;
                if(!process[idx]){

                    cout<<"1.left 2.right"<<endl;
                    int dir;
                    cin>>dir;
                    if(dir==1){
                        if(semaphore[idx] == 1) 
                        {   wait(&semaphore[idx]);
                            resourceaq[idx]++;
                        }
                        else cout<<"Resourse is busy"<<endl;
                    }
                    if(dir==2){
                        if(semaphore[(idx+1)%5] == 1) 
                        {   wait(&semaphore[(idx+1)%5]);
                            resourceaq[idx]++;
                        }
                        else cout<<"Resourse is busy"<<endl;
                    }
                    if(resourceaq[idx] == 2){
                        process[idx] = 1;
                        cout<<"Process is running"<<endl;
                    }else{
                        cout<<"Process still needs more resources to run"<<endl;
                    }            
                } else{
                    cout<<"Process is already running"<<endl;
                }
                cout<<endl<<endl;
                break;
            }
        case 2:
            {
                int idx;
                cout<<"Enter the process number\n";
                cin>> idx;
                if(process[idx]==1){

                    if(semaphore[idx]==0)
                    {
                        signal(&semaphore[idx]);
                        resourceaq[idx]--;
                    }
                    if(semaphore[(idx+1)%5] == 0)
                    {
                        signal(&semaphore[(idx+1)%5]);
                        resourceaq[idx]--;
                    }
                    if(process[idx]<2)
                    {
                        process[idx] = 0;
                        cout<<"Process stopped"<<endl;
                    }
                } else{
                    cout<<"Process is not running"<<endl;
                }
                cout<<endl<<endl;
                break;
            }
        case 3:
        {
            for(int i = 0 ;i<5;i++){
                if(process[i] == 1)
                {
                    cout<<"Process"<<i<<" is running"<<endl;
                }
            }
            cout<<endl<<endl;
            break;
        }
        case 4:
            exit(0);
        default:
            cout<<endl<<endl;
            continue;
        }
    }
}