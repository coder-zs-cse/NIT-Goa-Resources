#include <iostream>
using namespace std;
struct marks
{
    int p : 3;
    int c : 3;
};
int main()
{
    struct marks s = {2, 10};
    printf("%d %d", s.p, s.c);
    return 0;
}