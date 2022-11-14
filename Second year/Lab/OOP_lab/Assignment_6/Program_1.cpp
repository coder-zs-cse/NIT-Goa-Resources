#include<iostream>
using namespace std;
#define SIZE 15
class OCTAL{
    int oct[SIZE];
    int len;
    public:
    OCTAL();
    OCTAL(int );
    int operator+(int );
    friend ostream &operator<< (ostream&,OCTAL &);
};

int main(){

    int x = 16644,k = 25;
    OCTAL h = x;
    int y = h + k;
    cout<<h<<endl;
    return 0;
}






// OCTAL class in member functions declaration
OCTAL::OCTAL(){
    len=0;
}
OCTAL::OCTAL(int element){
    int i=SIZE;
    int k = element;
    while(k>0){
        i--;
        oct[i]=k%8;
        k/=8;
    }
    len = SIZE - i ;

}
int OCTAL::operator+(int element){
    int output=0;
    int p = 0;
    for(int i=SIZE-len;i<SIZE;i++){
        output = output*8 + oct[i];
    }
    return output+element;
}

ostream &operator<<(ostream& out,OCTAL &o){
    for(int i=SIZE-o.len;i<SIZE;i++){
        out<<o.oct[i];
    }
    return out;
}




