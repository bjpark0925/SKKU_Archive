#include <iostream>
#include "6-adder.h"
#include "6-calculator.h"
using namespace std;

void Calculator::run()
{
    cout << "�� ���� ���� �Է��ϼ���>>";
    int a, b;
    cin >> a >> b;
    // ���� ���̵��� ���� �κ�
    Adder adder(a, b); // ��� �����ƴ��� �� �ʿ� ����, ����� ���� �˸� �� -> adder.h ���� �ʿ�, adder.cpp ���� ���ʿ�
    cout << adder.process();
}