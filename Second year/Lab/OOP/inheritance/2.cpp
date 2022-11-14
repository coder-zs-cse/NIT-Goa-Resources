#include<iostream>
using namespace std;
class class1{
    int i;
};
class class2 : public class1{
    int j;
};
class class3 : public class2{
    int k;
};

int main(){
    // cout<<sizeof(class3);
    int a=10;
    delete &a;
    cout<<a;
    printf("h");
}