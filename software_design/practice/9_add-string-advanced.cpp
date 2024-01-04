#include <iostream>
#include <string>
using namespace std;
/*
두 정수의 덧셈 식을 문자열로 반복적으로 입력받고 계산하는 프로그램
단, 0 입력시 종료, 입력 식에 공백이 있을 수도 있음
*/
int main()
{
    while (true)
    {
        cout << "수식을 입력하세요: ";
        string s;
        getline(cin, s);
        if (s == "0")
        {
            break;
        }
        // 문자열을 숫자로 바꿔 배열에 삽입
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
        // sum 계산
        int sum = 0;
        int i = 0;
        while (i<=array_pos)
        {
            cout << pArray[i] << endl;
            sum += pArray[i];
            i++;
        }
        cout << "숫자들의 합은 " << sum << endl;
    }

    return 0;
}