#include <iostream>
#include <cstring> //<string.h>
using namespace std;

int main()
{
    char pw[11] = "C++";
    cout << "���α׷��� �����Ϸ��� ��ȣ�� �Է��ϼ���." << endl;
    while (1)
    {
        char input[11];
        cout << "��ȣ>>";
        cin >> input;
        if (strcmp(pw, input) == 0)
        {
            cout << "���α׷��� ���� �����մϴ�." << endl;
            break;
        }
        else
        {
            cout << "��ȣ�� Ʋ���ϴ�." << endl;
        }
    }

    return 0;
}