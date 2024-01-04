#include <iostream>
using namespace std;

/* Power를 선언해도 op.kick, op.punch 뭔지 모름
class Power;
Power &operator-=(Power &op, int n)
{
    op.kick -= n;
    op.punch -= n;
    return op; // 변경된 객체 자신의 참조 리턴
}
*/
class Power;
Power &operator-=(Power &op, int n);
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
    friend Power &operator-=(Power &op, int n); // friend 안쓴다면, private를 public으로
    friend Power &operator--(Power &op);
    friend Power operator--(Power &op, int n);
};
void Power::show()
{
    cout << "kick=" << kick << ','
         << "punch=" << punch << endl;
}
Power &operator-=(Power &op, int n)
{
    op.kick -= n;
    op.punch -= n;
    return op; // 변경된 객체 자신의 참조 리턴
}
Power &operator--(Power &op)
{
    op.kick--;
    op.punch--;
    return op; // 변경된 객체 자신의 참조 리턴
}
Power operator--(Power &op, int n)
{
    Power tmp = op;
    op.kick--;
    op.punch--;
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