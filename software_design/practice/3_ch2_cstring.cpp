#include <iostream>
#include <cstring> //<string.h>
using namespace std;

int main()
{
    char pw[11] = "C++";
    cout << "프로그램을 종료하려면 암호를 입력하세요." << endl;
    while (1)
    {
        char input[11];
        cout << "암호>>";
        cin >> input;
        if (strcmp(pw, input) == 0)
        {
            cout << "프로그램을 정상 종료합니다." << endl;
            break;
        }
        else
        {
            cout << "암호가 틀립니다." << endl;
        }
    }

    return 0;
}