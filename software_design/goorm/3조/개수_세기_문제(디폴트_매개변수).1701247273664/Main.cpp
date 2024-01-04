#include <iostream>
using namespace std;

// TODO: 디폴트 매개변수를 이용해 구현하세요, 함수 추가로 구현 금지
int countMultiple(int a, int b, int n=1) {
	int count=0;
	for (int i=a;i<=b;i++){
		if (i%n==0){
			count++;
		}
	}
	return count;
}

int main() {
	int M, a, b, n;
	// TODO: main 구현
	cin>>M;
	cin>>a;
	cin>>b;
	if (M==2){
		cout<<countMultiple(a,b)<<endl;
	}
	else if (M==3){
		cin>>n;
		cout<<countMultiple(a,b,n)<<endl;
	}

	return 0;
}