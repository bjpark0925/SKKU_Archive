#include <iostream>
using namespace std;
class A
{
    int aa;
public:
    A() { aa = 0; }
    A(int _aa){
        aa = _aa;
    }
    void printA(){
        cout << "aa=" << aa << endl;
    }
};
class B : public A
{
    int bb;
public:
    B() { bb = 0; }
    B(int _aa, int _bb) : A(_aa)
    {
        bb = _bb;
    }
    void printB(){
        printA();
        cout << "bb=" << bb << endl;
    }
};
class C : public B
{
    int cc;
public:
    C() { cc = 0; }
    C(int _aa, int _bb, int _cc) : B(_aa, _bb)
    {
        cc = _cc;
    }
    void printC(){
        printB();
        cout << "cc=" << cc << endl;
    }
};

int main()
{
    C y(1, 2, 3); // aa, bb, cc 초기값
    y.printC();
}