#include <iostream>
#include <string>
using namespace std;

int main() {
    string *str1 = new string;
    string *str2 = new string;
	
	cin>>*str1;
	cin>>*str2;
	
	if (*str1==*str2)
		cout<<"같음"<<endl;
	else
		cout<<"다름"<<endl;
	
	delete str1;
	delete str2;
	
	return 0;
}