#include<bits/stdc++.h>
using namespace std;
int indexPageExists(vector<int> &pageMemory,int page){
    for(int i=0;i<pageMemory.size();i++){
        if(pageMemory[i]==page) return i;
    }
    return -1;
}
int secondChance(vector<int> &pages,int frames){
    int n = pages.size();
    vector<int> chance(frames,0);
    int pointer=0;
    int pageFaults=0;
    vector<int> pageMemory;

    for(int i=0;i<n;i++){
        int index = indexPageExists(pageMemory,pages[i]);
        if(index!=-1){
            chance[index] = 1;
        }
        else{
            if(pageMemory.size()<frames) pageMemory.push_back(pages[i]);
            else{
                while(chance[pointer]==1){
                    chance[pointer] = 0;
                    pointer = (pointer+1)%frames;
                }
                pageMemory[pointer] = pages[i];
                pointer = (pointer+1)%frames;
            }
            pageFaults++;
        }
        cout<<"Memory: ";
        for(auto it:pageMemory) cout<<it<<" ";
        cout<<" | chances: ";
        for(auto it:chance) cout<<it<<" ";
        cout<<" | "<<pages[i]<<" "<<pageFaults<<endl;
    }
    cout<<endl;
    return pageFaults;
}
void stringToVector(string &s,vector<int> &pages);
int main(){
    string s;
    getline(cin,s);
    vector<int> pages;
    stringToVector(s,pages);
    int frames;
    cin>>frames;
    int numberPageFaults = secondChance(pages,frames);
    cout<<"Number of page faults is "<<numberPageFaults;

}
void stringToVector(string &s,vector<int> &pages){
    int current=0;
    for(int i=0;i<s.length();i++){
        if(s[i]==' ') {
            pages.push_back(current);
            current=0;
        }
        else current = current*10 + s[i]-'0';
    }
    if(current) pages.push_back(current);
}