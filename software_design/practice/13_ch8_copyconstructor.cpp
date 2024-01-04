#include <iostream>
using namespace std;

class A
{
    int aa;

public:
    A() 
    {
        aa = 0;
        cout << "+A=" << aa << endl;
    }
    A(A& objA)
    {
        aa = objA.aa + 1;
        cout << "#A=" << aa << endl;
    }
};
class B : public A
{
    int bb;

public:
    B()
    {
        bb = 0;
        cout << "+B=" << bb << endl;
    }
    B(B &objB) : A(objB)
    {
        bb = objB.bb + 1;
        cout << "#B=" << bb << endl;
    }
};
class C : public B
{
    int cc;

public:
    C()    
    {
        cc = 0;
        cout << "+C=" << cc << endl;
    }
    C(C &objC) : B(objC)
    {
        cc = objC.cc + 1;
        cout << "#C=" << cc << endl;
    }
};

int main()
{
    C x;
    C y(x);
}