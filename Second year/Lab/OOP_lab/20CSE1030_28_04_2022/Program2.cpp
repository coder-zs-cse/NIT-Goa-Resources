#include<iostream>
using namespace std;

class MATRIX{
    int row;
    int col;
    int **array;
    public:
    MATRIX();
    MATRIX(const MATRIX&);
    MATRIX(int,int);
    void takeinput();
    MATRIX operator+(MATRIX);
    MATRIX operator-(MATRIX);
    bool operator==(MATRIX);
    friend ostream& operator<<(ostream&,MATRIX);
    ~MATRIX();
};
int main(){

    int r,c;
    cout<<"Enter number of rows for matrix m1: ";
    cin>>r;
    cout<<"Enter number of columns for matrix m1: ";
    cin>>c;
    MATRIX m1(r,c);
    m1.takeinput();
    cout<<"Enter number of rows for matrix m2: ";
    cin>>r;
    cout<<"Enter number of columns for matrix m2: ";
    cin>>c;
    MATRIX m2(r,c);
    m2.takeinput();
    cout<<"Matrix m1 :-"<<endl<<m1;
    cout<<"Matrix m2 :-"<<endl<<m2;
    MATRIX m3,m4;
    if(m1==m2){
        MATRIX m3 = m1 + m2;
        cout<<"Matrix m3 :-"<<endl;
        cout<<m3;
        MATRIX m4 = m1 - m2;
        cout<<"Matrix m4 :-"<<endl;
        cout<<m4;
    }
    else{
        cout<<"Error! The dimensions of both the operand matrices are not same\n";
    }
    return 0;
}

MATRIX::MATRIX(int r,int c){
    row = r;
    col = c;
    array = new int*[r];
    for(int i=0;i<r;i++){
        array[i] = new int[c];
        for(int j=0;j<c;j++) {
            array[i][j] = 0;
        }
    }
}
MATRIX::MATRIX(const MATRIX& obj){
    row = obj.row;
    col = obj.col;
    array = new int*[row];
    for(int i=0;i<row;i++){
        array[i] = new int[col];
        for(int j=0;j<col;j++){
            array[i][j] = obj.array[i][j];
        }
    }
}
void MATRIX::takeinput(){
    for(int i=1;i<=row;i++){
        for(int j=1;j<=col;j++){
            cout<<"Enter ("<<i<<", "<<j<<") element: ";
            cin>>array[i-1][j-1];
        }
    }
}
MATRIX::MATRIX(){
    row=0;
    col=0;
    array=NULL;
}
MATRIX MATRIX::operator+(MATRIX m2){
    MATRIX output(row,col);
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            output.array[i][j] = array[i][j] + m2.array[i][j];
        }
    }
    return output;
}
MATRIX MATRIX::operator-(MATRIX m2){
    MATRIX output(row,col);
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            output.array[i][j] = array[i][j] - m2.array[i][j];
        }
    }
    return output;
}
ostream& operator<<(ostream &print, MATRIX m){
    for(int i=0;i<m.row;i++){
        for(int j=0;j<m.col;j++){
            print<<m.array[i][j]<<" ";
        }
        print<<endl;
    }
    return print;
}
bool MATRIX::operator==(MATRIX m2){
    return (row==m2.row && col==m2.col) ? true:false;
}

MATRIX::~MATRIX(){
    for(int i=0;i<row;i++){
        delete []array[i];
    }
    delete []array;
}