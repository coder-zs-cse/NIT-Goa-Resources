#include<iostream>
using namespace std;
void test(int x) throw(double)
{
    try
    {
        if (x == 1)
            throw x;
        else if (x == -1)
            throw 3.4;
        else if (x == 0)
            throw 's';
    }
    catch(int i)
    {
        cout<< "caught an integer\n";
        throw ;
    }

    catch(float s)
    {
        cout << "caught a float\n";
    }
    catch (char c)
    {
        cout << "caught a character\n";
    }
    catch (...)
    {
        cout <<"caught an error \n";
    }
}
int main()
{
    try{
    test(1);
    test(-1);
    test(0);
    }
    catch(double){
        cout<<"double inside emain functon\n";
    }
    catch(int){
        cout<<"catch inside main function\n";
    }
    return 0;
}
    // void test(int x)
    // {
    //     try
    //     {
    //         if (x == 1)
    //             throw x;
    //         else if (x == -1)
    //             throw 3.4;
    //         else if (x == 0)
    //             throw ‘s’;
    //     }
    //     catch (…)
    //     {
    //         cout <<”caught an error …”;
    //     }