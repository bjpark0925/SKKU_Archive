#include <iostream>
#include <string>

using namespace std;

int main(){
	string doc, word;
	getline(cin, doc);
	getline(cin, word);
	
	int cnt=0;
	int pos=0;
	while(1){
		int index=doc.find(word,pos);
		if (index==-1){
			break;
		}
		else{ // 단어 등장
			cnt++;
			pos=index+word.length();
		}
	}
	cout<<cnt<<endl;
	
	return 0;
}