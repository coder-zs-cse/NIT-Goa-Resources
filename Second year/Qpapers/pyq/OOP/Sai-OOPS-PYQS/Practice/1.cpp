#include<iostream>
using namespace std;

class matrix{
    int row;
    int col;
    int **array;
    public:
    matrix();
    matrix(int,int);
    matrix(const matrix&);
    void takeinput();
    friend ostream& operator<<(ostream&,matrix&);
    matrix sum(matrix m2){
        matrix output;
        output.row = row;
        output.col = col;
        output.array = new int*[row];
        for(int i=0;i<row;i++){
            output.array[i] = new int[col];
            for(int j=0;j<col;j++)  output.array[i][j] = array[i][j] + m2.array[i][j];
        }    
        printf("okay\n");
        return output;
    }
    matrix operator+(matrix m2){
        matrix output;
        output.row = row;
        output.col = col;
        output.array = new int*[row];
        for(int i=0;i<row;i++){
            output.array[i] = new int[col];
            for(int j=0;j<col;j++)  output.array[i][j] = array[i][j] + m2.array[i][j];
        }    
        return output;
    }
    ~matrix(){
        printf("Desctructor is called\n");
        for(int i=0;i<row;i++) delete []array;
        delete []array;
    }
};
int main(){

    matrix m1(2,2);
    m1.takeinput();
    matrix m2 = m1;
    m2.takeinput();
    cout<<m1;
    cout<<m2;
    matrix m3 = m1.sum(m2);
    cout<<m3;
    cout<<"start"<<endl;
    matrix m4 = m3;
    cout<<m4;
    cout<<"end"<<endl;
    return 0;
}


matrix::matrix(){
    printf("Contructor with no parameter is called\n");
    row=0;
    col=0;
    array=NULL;
}
matrix::matrix(int r,int c){
    row=r;
    col=c; 
    array=new int*[r];
    for(int i=0;i<r;i++){
        array[i]=new int[c];
        for(int j=0;j<c;j++) array[i][j]=0;
    }
    printf("Hello, yeah the constructor is called\n");

}
matrix::matrix(const matrix& m2){
    printf("yea,yea,yea Copy contructor is called\n");
    row=m2.row;
    col = m2.col;
    array=new int*[row];
    for(int i=0;i<row;i++){
        array[i]=new int[col];
        for(int j=0;j<col;j++) array[i][j]=m2.array[i][j];
    }

}

ostream& operator<<(ostream& print,matrix &m){
    for(int i=0;i<m.row;i++){
        for(int j=0;j<m.col;j++){
            print<<m.array[i][j]<<" ";
        }
        print<<endl;
    }
    return print;
}
void matrix::takeinput(){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>array[i][j];
        }
    }
}