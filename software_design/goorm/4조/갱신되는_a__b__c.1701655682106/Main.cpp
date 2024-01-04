#include <iostream>
using namespace std;
void first(int &a, int b){
	a=a+b;
}
void second(int a, int &b, int c){
	b=a*c;
}
void third(int a, int b, int &c){
	c=a+b;
}
void print(int a, int b, int c){
	cout<<"a: "<<a<<", b: "<<b<<", c: "<<c<<endl;
}
int main() {

	int a,b,c;
	cin>>a;
	cin>>b;
	cin>>c;
	first(a,b);
	second(a,b,c);
	third(a,b,c);
	print(a,b,c);
	
	return 0;
}