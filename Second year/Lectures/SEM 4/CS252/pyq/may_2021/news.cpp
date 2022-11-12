#include <iostream>
using namespace std;
class Test
{
    int x;

public:
    void *operator new(size_t size);
    void operator delete(void *);
    Test(int i)
    {
        x = i;
        cout << "Constructor called \n";
    }
    ~Test() { cout << "Destructor called \n"; }
};
void *Test::operator new(size_t size)
{
    void *storage = malloc(size);
    cout << "new called \n";
    return storage;
}
void Test::operator delete(void *p)
{
    cout << "delete called \n";
    free(p);
}
int main()
{
    Test *m = new Test(5);
    delete m;
    return 0;
}