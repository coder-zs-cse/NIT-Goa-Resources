#include<iostream>
using namespace std;

class STRING{
    char *str;
    int length;
    public:
    STRING();
    STRING(const char*);
    STRING(const STRING&);
    STRING operator+(STRING);
    friend ostream& operator<<(ostream&,STRING&);
    ~STRING();
};

int main(){
    STRING s1 = "NIT";
    STRING s2 = "GOA";
    STRING s3 = s1 + s2;
    cout<<s1<<endl;
    cout<<s2<<endl;
    cout<<s3<<endl;
    return 0;
}
STRING::STRING(){
    str = NULL;
    length = 0;
}
STRING::STRING(const STRING& obj){
    length = obj.length;
    str = new char[length+1];
    for(int i=0;i<length;i++) str[i] = obj.str[i];
}
STRING::STRING(const char* input){
    int len = 0;
    while(input[len]!='\0'){
        len++;
    }
    str = new char[len+1];
    for(int i=0;i<len;i++){
        str[i] = input[i];
    }
    str[len] = '\0';
    length = len;
}
STRING STRING::operator+(STRING s2){
    STRING output;
    output.length = length + s2.length;
    output.str = new char[output.length+1];
    for(int i=0;i<length;i++){
        output.str[i] = str[i];
    } 
    for(int i = 0;i<s2.length;i++){
        output.str[length + i] = s2.str[i];
    }
    output.str[output.length] = '\0';
    return output;
}
ostream& operator<<(ostream &print,STRING &obj){
    for(int i=0;i<obj.length;i++) print<<obj.str[i]; 
    return print;
}
STRING::~STRING(){
    delete []str;
}