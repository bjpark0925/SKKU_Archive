#include <iostream>
#include <string>
using namespace std;

int main()
{
    string pw="C++";
    cout<<"���α׷��� �����Ϸ��� ��ȣ�� �Է��ϼ���."<<endl;
    while(1)
    {
        string input;
        cout<<"��ȣ>>";
        cin>>input;
        if (pw==input){
            cout<<"���α׷��� ���� �����մϴ�."<<endl;
            break;
        }
        else{
            cout<<"��ȣ�� Ʋ���ϴ�."<<endl;
        }
    }


    return 0;
}