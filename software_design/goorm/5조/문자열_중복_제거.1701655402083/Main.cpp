#include <iostream>
#include <string>
using namespace std;

string removeDuplicates(string s);

int main() {
    string inputStr;
    cout << "문자열을 입력하세요: ";
    cin >> inputStr;

    string result = removeDuplicates(inputStr);
    cout << result << endl;

    return 0;
}


string removeDuplicates(string s) {

    // 코드 작성
	int pos=0;
	while(pos<s.length()){
		int index=s.find(s[pos],pos+1);
		if (index!=-1){
			s.erase(index,1);
		}
		else{
			pos++;
		}
	}
	return s;
    
}