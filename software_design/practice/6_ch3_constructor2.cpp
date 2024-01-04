#include <iostream>
using namespace std;

class Circle
{
public:
    char loc;
    int rad;
    Circle(char c);
    Circle(char c, int r);
    ~Circle();
};
Circle::Circle(char c)
{
    loc = c;
    rad = 0;
    cout<< "+" << loc << rad << endl;
}
Circle::Circle(char c, int r)
{
    loc = c;
    rad = r;
    cout << "+" << loc << rad << endl;
}
Circle::~Circle()
{
    cout << "-" << loc << rad << endl;
}
Circle g1('g', 1);
Circle g2('g', 2);
void f()
{
    Circle f1('f', 1);
    Circle f2('f', 2);
}
int main()
{
    Circle m1('m');
    f();
    Circle m2('m', 2);
}