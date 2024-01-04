#include <iostream>
#include <string>
using namespace std;
// userPrint 구현
void userPrint(string s1, string s2)
{
    static int cnt = 0;
    cnt++;

    cout << "cnt " << cnt << ">" << s1 << " " << s2 << endl;
}
int main()
{
    string sec1 = "Section 1";
    userPrint(sec1, "1st sentence");
    userPrint(sec1, "2nd sentence");
    userPrint(sec1, "3rd sentence");
    string sec2 = "Section 2";
    userPrint(sec2, "1st sentence");
    userPrint(sec2, "2nd sentence");
    userPrint(sec2, "3rd sentence");
}