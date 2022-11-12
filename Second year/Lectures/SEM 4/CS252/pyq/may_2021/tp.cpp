#include <iostream>
using namespace std;

class Pot
{
public:
    int a;
    Pot(int x) { a = x; }
};
class Tom : public Pot
{
public:
    int b;
    Tom() : Pot(5)
    {
        b = 0;
        a = 0;
    }
};
int main()
{
    Tom bar;
    cout << bar.a << "\n"
         << bar.b;
    return 0;
}
