#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string s) {
// 함수 구성
	int len=s.length();
	for (int i=0;i<len/2;i++){
		if (s[i]!=s[len-1-i]){
			return false;
		}
	}
	return true;
}

string findLongestPalindrome(string input) {
// 함수 구성
	int len=input.length();
	int max=0;
	string answer;
	for (int pos=0;pos<len;pos++){
		for (int n=len-pos;n>=1;n--){
			if (isPalindrome(input.substr(pos,n))){
				if (max<n){
					max=n;
					answer=input.substr(pos,n);
				}
			}
		}
	}
	return answer;
}

int main() {
    //cout << "문자열을 입력하세요: ";
    string input;
    cin >> input;

    string longestPalindrome = findLongestPalindrome(input);

    //cout << "가장 긴 팰린드롬 부분 문자열: " << longestPalindrome << endl;
	cout << longestPalindrome << endl;

    return 0;
}