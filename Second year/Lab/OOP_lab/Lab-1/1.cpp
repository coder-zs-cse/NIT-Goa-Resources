#include<iostream>
using namespace std;
class NODE{
    int data;
    NODE *next;
    friend class DLIST;
};
class DLIST{
    NODE *head;
    public:
    DLIST();
};
int main(){
    printf("hello world\b");
    return 0;
}