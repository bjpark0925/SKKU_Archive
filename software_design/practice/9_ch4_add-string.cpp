#include <iostream>
#include <string>
using namespace std;
// 포인터 연산 이용해 error 발생
int main()
{
    while (1)
    {
        string s;
        cout << "Enter the string: ";
        getline(cin, s);
        if (s == "0")
            break;

        int strlen = s.size();
        int *pArray = new int[strlen];
        int s_pos = 0;
        while (1)
        {
            int plus_index = s.find("+", s_pos);
            if (plus_index == string::npos)
            {
                *pArray = stoi(s.substr(s_pos, strlen - s_pos));
                break;
            }
            *pArray = stoi(s.substr(s_pos, plus_index - s_pos));
            pArray++;
            s_pos = plus_index + 1;
        }

        // sum
        int sum = 0;
        while (pArray)
        {
            cout << *pArray << endl;
            sum += *pArray;
            pArray++;
        }
        cout << "sum: " << sum << endl;
        delete[] pArray;
    }
    return 0;
}