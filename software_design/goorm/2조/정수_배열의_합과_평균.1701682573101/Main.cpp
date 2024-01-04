#include <iostream>
using namespace std;

void calculateSumAndAverage(int* arr, int size, int& sum, double& average) {
    // 배열의 합과 평균을 계산하는 함수 구현
	for (int i=0;i<size;i++){
		sum+=arr[i];
	}
	average=(double)sum/size;
}

int main() {
    // 사용자로부터 배열의 크기를 입력 받음
	int n;
	cin>>n;
	int* arr;
	if (n==0){
		arr=nullptr;
	}
	else{
		arr=new int[n];
	}
    // 동적으로 할당한 배열에 사용자로부터 입력 받은 정수를 저장
	for (int i=0;i<n;i++){
		int tmp;
		cin>>tmp;
		arr[i]=tmp;
	}
    // calculateSumAndAverage 함수를 호출하여 합과 평균을 계산하고 출력
	int sum=0;
	double average=0;
	if (n!=0){
		calculateSumAndAverage(arr, n, sum, average);
	}
	cout<<sum<<endl;
	cout<<fixed;
	cout.precision(2);
	cout<<average<<endl;
    // 할당한 메모리를 반드시 해제
	if (n!=0){
		delete [] arr;
	}
  return 0;
}