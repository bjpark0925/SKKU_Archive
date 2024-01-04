#include <iostream>
#include "6-adder.h"
#include "6-calculator.h"
using namespace std;

void Calculator::run()
{
    cout << "두 개의 수를 입력하세요>>";
    int a, b;
    cin >> a >> b;
    // 문제 난이도를 높인 부분
    Adder adder(a, b); // 어떻게 구현됐는지 알 필요 없고, 선언된 곳만 알면 됨 -> adder.h 선언 필요, adder.cpp 선언 불필요
    cout << adder.process();
}