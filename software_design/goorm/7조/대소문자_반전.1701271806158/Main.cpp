#include <iostream>
#include <string>
using namespace std;
void change(string s, int x, int y){
	for (int i=x-1;i<y;i++){
		if (s[i]>='A'&&s[i]<='Z'){
			s[i]=s[i]-'A'+'a';
		}
		else if(s[i]>='a'&&s[i]<='z'){
			s[i]=s[i]-'a'+'A';
		}
	}
	cout<<s<<endl;
}
void change(string s, int x){
	change(s, 1, x);
}
void change(string s){
	change(s, 1, s.length());
}

int main()
{
	string s;
	int x, y;
	getline(cin,s);
	cin>>x;
	cin>>y;
	
	if (x==0){
		change(s);
	}
	else if (y==0){
		change(s, x);
	}
	else{
		change(s, x, y);
	}
    
    return 0;
}
