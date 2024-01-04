#include <iostream>
using namespace std;
// case 1

class Power
{
    int kick;
    int punch;

public:
    Power(int kick = 0, int punch = 0)
    {
        this -> kick = kick;
        this->punch = punch;
    }
    void show();
    Power& operator <<(int n);
};
void Power::show(){
    cout << "kick=" << kick << ','
         << "punch=" << punch << endl;
}

Power &Power::operator<<(int n){
    kick += n;
    punch += n;
    return *this; // 이 객체의 참조 리턴
}

//case 2
/*
class Power
{
    int kick;
    int punch;

public:
    Power(int kick = 0, int punch = 0)
    {
        this->kick = kick;
        this->punch = punch;
    }
    void show();
    Power operator<<(int n);
};
void Power::show()
{
    cout << "kick=" << kick << ','
         << "punch=" << punch << endl;
}

Power Power::operator<<(int n)
{
    kick += n;
    punch += n;
    return *this; // 이 객체의 리턴
}
*/

int main()
{
    Power a(1, 2), b;
    a << 3 << 5;
    a.show();

    b = (a << 3 << 5);
    a.show();
    b.show();
}