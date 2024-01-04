#include <iostream>
using namespace std;
// 작성할 부분
int sum(int a, int b)
{
    int s = 0;
    for (int i = a; i <= b; i++)
        s += i;
    return s;
}
/*
int sum(int a)
{
    int s = 0;
    for (int i = 0; i <= a; i++)
        s += i;
    return s;
}
*/
int sum(int a)
{
    // 똑같은 동작은 하나의 함수에만. 호출해서 갖다 씀
    return sum(0, a);
}
int main()
{
    cout << sum(3, 5) << endl;
    cout << sum(3) << endl;
    cout << sum(100) << endl;
}