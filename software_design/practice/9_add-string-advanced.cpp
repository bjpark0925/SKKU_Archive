#include <iostream>
#include <string>
using namespace std;
/*
�� ������ ���� ���� ���ڿ��� �ݺ������� �Է¹ް� ����ϴ� ���α׷�
��, 0 �Է½� ����, �Է� �Ŀ� ������ ���� ���� ����
*/
int main()
{
    while (true)
    {
        cout << "������ �Է��ϼ���: ";
        string s;
        getline(cin, s);
        if (s == "0")
        {
            break;
        }
        // ���ڿ��� ���ڷ� �ٲ� �迭�� ����
        int strlen = s.length();
        int *pArray = new int[strlen];
        int s_pos = 0;
        int array_pos = 0;
        while (true)
        {
            int plus_index = s.find("+", s_pos);
            if (plus_index < 0)
            {
                pArray[array_pos] = stoi(s.substr(s_pos, strlen - s_pos));
                cout << pArray[array_pos] << endl;
                break;
            }
            pArray[array_pos] = stoi(s.substr(s_pos, plus_index - s_pos));
            cout << pArray[array_pos] << endl;
            s_pos = plus_index + 1;
            array_pos++;
        }
        // sum ���
        int sum = 0;
        int i = 0;
        while (i<=array_pos)
        {
            cout << pArray[i] << endl;
            sum += pArray[i];
            i++;
        }
        cout << "���ڵ��� ���� " << sum << endl;
    }

    return 0;
}