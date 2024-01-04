#include <iostream>
using namespace std;

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
    friend Power operator+(Power op, int x);
    friend Power operator+(int x, Power op);
    friend Power operator+(Power op1, Power op2);
};
void Power::show()
{
    cout << "kick=" << kick << ','
         << "punch=" << punch << endl;
}
Power operator+(Power op, int x)
{
    /*
    Power tmp;
    tmp = op;
    tmp.kick += x;
    tmp.punch += x;
    */
    op.kick += x;
    op.punch += x;
    return op;
}
Power operator+(int x, Power op)
{
    //Power tmp;
    //tmp = op + x;
    /* 중복된 동작은 하나만
    tmp.kick += x;
    tmp.punch += x;
    */

    return op + x;
}

Power operator+(Power op1, Power op2)
{
    /*
    Power tmp;
    tmp.kick = op1.kick + op2.kick;
    tmp.punch = op1.punch + op2.punch;
    return tmp;
    */
    op1.kick += op2.kick;
    op1.punch += op2.punch;
    return op1;
}

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
    Power operator+(int x);
    friend Power operator+(int x, Power op);
    Power operator+(Power op);
};
void Power::show()
{
    cout << "kick=" << kick << ','
         << "punch=" << punch << endl;
}
Power Power::operator+(int x)
{
    Power temp = *this;
    temp.kick += x;
    temp.punch += x;
    return temp;
}
Power operator+(int x, Power op)
{
    return op + x;
}

Power Power::operator+(Power op)
{
    Power tmp;
    tmp.kick = kick + op.kick;
    tmp.punch = punch + op.punch;
    return tmp;
}
*/

int main()
{
    Power a(3, 5), b, c;
    a.show();
    b.show();
    c.show();
    b = a + 2;
    a.show();
    b.show();
    c = 2 + a;
    a.show();
    c.show();
    a = b + c;
    a.show();
    b.show();
    c.show();
}