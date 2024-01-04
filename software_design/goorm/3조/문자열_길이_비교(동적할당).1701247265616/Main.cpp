#include <iostream>
#include <string>
using namespace std;
int main() {
	string* s1 = new string;
	string* s2 = new string;
	
	cin >> *s1;
	cin >> *s2;
	
	if (s1->length()==s2->length())
		cout<<"동일한 길이입니다."<<endl;
	else
		cout<<"다른 길이입니다."<<endl;
	
	delete s1;
  delete s2;
	
	return 0;
}