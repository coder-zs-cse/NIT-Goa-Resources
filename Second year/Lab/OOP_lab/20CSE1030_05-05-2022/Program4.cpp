#include<iostream>
#include<fstream>
using namespace std;
void remove_blank_space(string input,string output){
    ifstream in(input);
    ofstream out(output);
    char ch;
    while(in.get(ch)){
        out<<ch;
        if(ch==' '){
            while(in.get(ch)){
                if(ch!=' ') {
                    out<<ch;
                    break;
                }
            }
        }
    }
    in.close();
    out.close();
}
int main(){
    string input = "test.txt";
    string output = "output.txt";
    remove_blank_space(input,output);
    return 0;
}