#include <iostream>

using namespace std;

class A
{
private: // ⭐⭐⭐
    static int s_value;
public:
    int getStatic() { return s_value; }
};

int A::s_value = 1; // 👈 private이더라도 전역범위에서 정의 및 초기화 가능

int main()
{
    A a;
    cout << a.getStatic() << endl;

    // A::s_value = 1; // 👈 💥에러!💥 private이므로 s_value 에접근이 불가능하다.

    return 0;
}