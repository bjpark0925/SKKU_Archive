#include <iostream>
using namespace std;

class MyStack{
    int *p;   //스택 메모리 주소
    int size; // 스택 최대 크기
    int tos; // 스택의 탑 인덱스
public: //구현할 부분
    MyStack(int num){
        size = num;
        tos = -1;
        p = new int[size];
    }
    MyStack(const MyStack &stack){
        size = stack.size;
        tos = stack.tos;
        p = new int[size];
        for (int i=0;i<=tos;i++){
            p[i] = stack.p[i];
        }
    }
    void push(int num){
        tos++;
        p[tos] = num;
    }
    void pop(int &num){
        num = p[tos];
        tos--;
    }
};

int main()
{
    MyStack a(10);
    a.push(10);
    a.push(20);

    MyStack b = a;
    b.push(30);
    int popA, popB;
    a.pop(popA);
    b.pop(popB);
    cout << "a.pop : " << popA << endl;
    cout << "b.pop : " << popB << endl;
    return 0;
}