#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    int j = 0;
    if (j == 0)
    {
        int i = ((5, (j = 3)), j = 10);
        cout << i<<" "<<j;
    }
    else
        cout << "Equal";

    // int i = 10,b = 100;
    // int j = (i,b = 200);
    // cout<<j<<endl;
    // cout<<b<<endl;

    // int a = 1;
    // int b = (1, 2);
    // cout << a << " " << b;
    return 0;
}