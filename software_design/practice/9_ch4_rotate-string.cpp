#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cout << "Enter string: ";
    getline(cin, s);
    int strlen = s.length();
    for (int i = 0; i < strlen;i++){
        string tail = s.substr(0, 1);
        string body = s.substr(1, strlen - 1);
        s = body.append(tail);
        //body.append(tail);
        //s = body;
        cout << s << endl;
    }

    return 0;
}
// string substr (int pos, int n) pos위치부터 길이가 n인 문자열을 리턴