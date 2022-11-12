#include <iostream>
using namespace std;
void fun(int = 10, int = 20, int = 30);
void fun(int, int);
int main()
{
    fun(1, 2, 9);
    return 0;
}
void fun(int x, int y, int z)
{
    cout << x << y << z << endl;
}
void fun(int x, int y)
{
    cout << x << y << endl;
}