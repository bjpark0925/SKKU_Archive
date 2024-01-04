#include <iostream>

using namespace std;

namespace LeapYear {

	bool isYoon(int x){
		if ((x%4==0)&&(x%100!=0)||(x%400==0)){
			return true;
		}
		else{
			return false;
		}
	}
}

int main() {

	int x;
	cin>>x;
	if (LeapYear::isYoon(x)){
		cout<<"입력한 연도는 윤년입니다."<<endl;
	}
	else{
		cout<<"입력한 연도는 윤년이 아닙니다."<<endl;
	}

	return 0;
}