#include <iostream>
using namespace std;
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
    Power& operator-=(int n);
    Power& operator--();
    Power operator--(int n);
};
void Power::show()
{
    cout << "kick=" << kick << ','
         << "punch=" << punch << endl;
}
Power &Power::operator-=(int n)
{
    kick -= n;
    punch -= n;
    return *this; // 변경된 객체 자신의 참조 리턴
}
Power &Power::operator--()
{
    kick--;
    punch--;
    return *this; // 변경된 객체 자신의 참조 리턴
}
Power Power::operator--(int n)
{
    Power tmp = *this;
    kick--;
    punch--;
    return tmp; // 증가 이전의 객체 리턴
}

int main()
{
    Power a(6, 5), b, c;
    a.show();
    a -= 2;
    b = --a;
    c = a--;
    b.show();
    c.show();
    a.show();
}