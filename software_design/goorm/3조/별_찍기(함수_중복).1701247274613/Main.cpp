#include <iostream>
#include <string>
using namespace std;

// TODO: 함수 중복을 사용해 구현하세요
void starPrint(int n, string c) {
	for (int i=n;i>0;i--){
		for (int j=0;j<n-i;j++){
			cout<<" ";
		}
		for (int j=1;j<2*i;j++){
			cout<<c;
		}
		for (int j=0;j<n-i;j++){
			cout<<" ";
		}
		cout<<endl;
	}
}

void starPrint(int n){
	starPrint(n, "*");
}

int main() {
	int M, N;
	string c;
	// TODO: main 구현
	cin>>M;
	cin>>N;
	if (M==1){
		starPrint(N);
	}
	else if (M==2){
		cin>>c;
		starPrint(N,c);
	}
	
	return 0;
}