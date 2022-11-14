#include<iostream>
#include<fstream>
using namespace std;
void reverse_word(char *buff,int len){
    for(int i=0;i<len/2;i++){
        int temp = buff[i];
        buff[i] = buff[len-i-1];
        buff[len-i-1] = temp;
    }
}

//input:        well boy school
//intermediate: lles yob loohcs    // reverse each word one by one
//output:       school boy well    // reverse entire sentence

void reverse_print(char *words){
    int i=0;
    char buff[50];
    int k=0;
    int len=0;
    while(words[i]!='\0'){
        if(words[i]==' '){
            reverse_word(buff,len);
            for(int j = 0; j<len;j++){
                words[i-len+j] = buff[j];
            }
            len = 0;
        }
        else {
            buff[len] = words[i];
            len++;
        }
        i++;
    }
    reverse_word(buff,len);
    for(int j = 0; j<len;j++){
        words[i-len+j] = buff[j];
    }
    len=0;
    while(words[len]!='\0') len++;
    reverse_word(words,len);
}

void reverse_content(string filename){
    ifstream in(filename);
    char ch;
    char buff[50];
    while(!in.eof()){
        in.get(buff,50);
        reverse_print(buff);
        cout<<buff<<endl;
        in.get();
    }
    in.close();
}

int main(){
    string filename = "text.txt";
    reverse_content(filename);
    return 0;
}
