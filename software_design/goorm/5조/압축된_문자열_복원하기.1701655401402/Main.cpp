#include <iostream>
#include <string>

using namespace std;

string decompress(string s, int& pos);
string decompressString(string s);

int main() {
    string compressed;
    cout << "압축된 문자열을 입력하세요: ";
    cin >> compressed;

    string decompressed = decompressString(compressed);
    cout << "복원된 문자열: " << decompressed << endl;

    return 0;
}

string decompress(string s, int& pos){
	string result;

    while (pos < s.length() && s[pos] != ']')
    {
        if (isdigit(s[pos]))
        { // s[pos]가 숫자인 경우
            int n = 0;
            while (isdigit(s[pos]))
            {
                n = n * 10 + stoi(s.substr(pos, 1));
                pos++;
            }

            pos++; // pos는 이제 [ 다음 위치
            string inner = decompress(s, pos);
            pos++; // pos는 ] 다음 위치

            for (int i = 0; i < n; i++)
            {
                result.append(inner);
            }
        }
        else
        { // s [pos]가 문자인 경우
            result += s[pos];
            pos++;
        }
    }

    return result;
}

string decompressString(string s) {

    // 코드 작성
	int pos=0;
	return decompress(s, pos);

}