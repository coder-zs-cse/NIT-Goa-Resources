#include<iostream>
#include<string>
#include<stack>
using namespace std;

class EXPRESSION{
    string infix;
    string postfix;
    EXPRESSION();
    EXPRESSION(string);
    void process_postfix();
    friend ostream& operator<<(ostream&,EXPRESSION&);
};

int main(){

    return 0;
}

EXPRESSION::EXPRESSION(){
    infix = postfix = "";
}
EXPRESSION::EXPRESSION(string input){
    infix = input;
    process_postfix();
    

}
void EXPRESSION::process_postfix(){

    stack<char> oper;
    

}