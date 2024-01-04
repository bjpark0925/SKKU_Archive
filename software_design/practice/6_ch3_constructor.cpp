#include <iostream>
using namespace std;
/*
+b +d +e +g
main함수 블럭: +c +a -a -c +f -f
-g -e -d -b
*/
//블럭이니까 블럭 호출될때 만들어야지
//블럭 끝날 때 소멸해야지
class Test{
    char s;
public:
    Test(char c);
    ~Test();
    void fun(){
        Test a('a');
    }
};

Test::Test(char c)
{
    s=c;
    cout<<"+"<<s<<endl;
}

Test::~Test()
{
    cout<<"-"<<s<<endl;
}

Test b('b');

void fun()
{
    Test c('c');
    c.fun();
}

Test d('d'), e('e');

int main()
{
    fun();
    Test f('f');
}

Test g('g');