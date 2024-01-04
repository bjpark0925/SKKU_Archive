#include <iostream>
using namespace std;

void f(char c, int num){
    for (int j = 0; j < num;j++)
    {
        for (int i = 0; i < 10; i++)
        {
            cout << c;
        }
        cout << endl;
    }
}
void f(char c){
    f(c, 1);
}
void f(){
    f('*', 1);
}
int main(){
    f();
    f('%');
    f('@', 5);
}