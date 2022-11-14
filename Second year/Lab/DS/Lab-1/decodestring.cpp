#include<iostream>
using namespace std;
typedef struct NOD{
    char data;
    NOD *next;
}NODE;
class STACK{
    NODE *head;
    void printSTACK_sec_func(NODE*);
    public:
    STACK();
    void push(char);
    void pop();
    int top();
    bool empty();
    void printSTACK();
};
void decodestring(string s){
    STACK record;
    for(int i=0;i<s.length();i++){
        if(s[i]==']'){
            string text = "";
            while(record.top()>='a' && record.top()<='z'){
                text += record.top();
                record.pop();
            }
            record.pop();
            int freq = 0;
            int power = 1;
            while(!record.empty() && record.top()>='0' && record.top()<='9'){
                freq = power*(record.top()-'0') + freq;
                power*=10;
                record.pop();
            }
            for(int f = 0;f<freq;f++){
                for(int i = text.length()-1;i>=0;i--){
                    record.push(text[i]);
                }
            }
        }
        else {
            record.push(s[i]);
        }
    }
    record.printSTACK();
}
int main(){
    string s;
    cin>>s;
    decodestring(s);
    return 0;
}
STACK::STACK(){
    head=NULL;
}
void STACK::push(char element){
    NODE *current = new NODE;
    current->data = element;
    current->next = head;
    head = current;
    return;
}
void STACK::pop(){
    NODE *save = head;
    head = head->next;
    delete save;
}
int STACK::top(){
    if(empty()) return -1;
    return head->data;
}
bool STACK::empty(){
    return head==NULL;
}
void STACK::printSTACK(){
    printSTACK_sec_func(head);
}
void STACK::printSTACK_sec_func(NODE *current){
    if(current) {
        printSTACK_sec_func(current->next);
        cout<<current->data;
    }
}