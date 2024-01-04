#include <iostream>
#include <string>
using namespace std;

void print(int n, string const& s)
{
    if (n==string::npos)
        cout << "not found\n";
    else
        cout << "found: " << s.substr(n) << endl;
}
int main()
{
    int n;
    string const s = "This is a string";

    //s의 처음부터 찾는다
    n = s.find("is");
    cout << n << endl;
    print(n, s);

    //s의 5번째 문자부터 찾는다
    n = s.find("is", 5);
    print(n, s);

    //단일 문자 a를 찾는다
    n = s.find('a');
    print(n, s);

    n = s.find('q');
    print(n, s);
    return 0;
}