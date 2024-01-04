#include <iostream>

using namespace std;

//아래 이름을 갖는 함수로 함수 중복 활용
double calculateArea(double x1, double x2, double x3) {
	return 0.5*(x1+x2)*x3;
}
double calculateArea(double x1, double x2) {
	return calculateArea(x1, 0, x2);
}

int main() {

	double x1, x2, x3;
	cin>>x1;
	cin>>x2;
	cin>>x3;
	if (x3==0){
		cout<<calculateArea(x1, x2)<<endl;
	}
	else{
		cout<<calculateArea(x1, x2, x3)<<endl;
	}

	return 0;
}