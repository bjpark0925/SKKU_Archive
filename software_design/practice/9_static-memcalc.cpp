#include <iostream>
#include <string>
using namespace std;

class MemCalc{
public:
    static int mem;
    static int add(int a, int b){
        return a + b;
    }
    static void memory(int a){
        //MemCalc::mem = a;
        mem = a;
    }
    static int addMemory(int a){
        //MemCalc::mem += a;
        mem += a;
    }
};
int MemCalc::mem = 0;
int main()
{
    int a, b, c;
    a = MemCalc::add(1, 2);
    MemCalc::memory(a);

    b = MemCalc::add(10, 5);
    c = MemCalc::addMemory(10);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;
    return 0;
}