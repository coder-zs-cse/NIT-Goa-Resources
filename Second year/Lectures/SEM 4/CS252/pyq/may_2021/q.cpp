#include <iostream>
using namespace std;
class base
{
public:
    int i;
};
class derived1 : virtual public base
{
public:
    int j;
};
class derived2 : virtual public base
{
public:
    int k;
};
class derived3 : public derived1, public derived2
{
public:
    int sum;
};
int main()
{
    derived3 ob;
    ob.i = 10;
    ob.j = 20;
    ob.k = 30;
    /* the rest of the code is on
    right side*/
    /* continuation of main()*/
    ob.sum = ob.i + ob.j + ob.k;
    cout << ob.i << “ ” << ob.j << “ ”;
    cout << ob.k << “ ” cout << ob.sum;
    return 0;
} /*End of main()*/