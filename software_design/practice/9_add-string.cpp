#include <iostream>
#include <string>
using namespace std;
/*
�� ������ ���� ���� ���ڿ��� �ݺ������� �Է¹ް� ����ϴ� ���α׷�
��, 0 �Է½� ����, �Է� �Ŀ� ������ ���� ���� ����
*/
int main()
{
    while(true){
        cout << "������ �Է��ϼ���: ";
        string s;
        getline(cin, s);
        if (s=="0"){
            break;
        }
        //���ڿ��� ���ڷ� �ٲ� �迭�� ����
        int strlen = s.length();
        int *pArray = new int[strlen];
        int pos = 0;
        while(true){
            int plus_index = s.find("+");
            if (plus_index<0){
                *pArray = stoi(s.substr(pos, strlen - pos));
                break;
            }
            *pArray = stoi(s.substr(pos, plus_index - pos));
            pos += plus_index + 1;
            pArray++;
        }
        //sum ���
        int sum = 0;
        while(pArray){
            cout << *pArray << endl;
            sum += *pArray;
            pArray++;
        }
        cout << "���ڵ��� ���� " << sum << endl;
    }
    
    return 0;
}