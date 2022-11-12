#include<iostream>

using namespace std;

class test{
    int x;
    int y;

    public:
    test(){};
    test(int a,int b)
    {
        x = a;
        y = b;
    }
    test operator = (test&);
    test operator ++();
    test operator + (test&);
    test operator - (test&);
    test operator ++ (int);
    friend ostream& operator << (ostream& out,test o);
};

test test::operator = (test& o1)
{
    test ob;
    ob.x = o1.x;
    ob.y = o1.y;
    return o1;
}

test test::operator ++()
{
    test obj;
    ++obj.x;
    ++obj.y;
    return *this;
}

test test :: operator+(test& o2)
{
    test obj1;
    obj1.x = obj1.x + o2.x;
    obj1.y = obj1.y + o2.y;
    return obj1;
}

test test:: operator-(test& o3)
{
    test obj1;
    obj1.x=obj1.x-o3.x;
    obj1.y=obj1.y-o3.y;
    return obj1;
}

test test::operator ++ (int z)
{
    test obj2;
    obj2.x++;
    obj2.y++;
    return *this;
}

ostream& operator << (ostream& out, test o4)
{
    out <<" "<< o4.x;
    out <<" "<< o4.y;
    return out;
}

int main()
{
    test t1(1,2);
    test t2(4,2);
    test t3(2,3);
    test t4;
    t4 = t2;
    cout <<t4;
}