#include <iostream>

using namespace std;

class FundCalculator {
	public:
		static long long totalFund;  // 전체 공금액을 저장하는 static 변수
		void setRank(int*& c, int size){
			for (int i=0;i<size-1;i++){
				for (int j=0;j<size-i-1;j++){
					if (c[j]<c[j+1]){
						//swap
						int tmp=c[j];
						c[j]=c[j+1];
						c[j+1]=tmp;
					}
				}
			}
		}
		static void cal_totalFund(int*& c, int size){
			for (int i=0;i<size;i++){
				int payment=c[i]*0.2*(size-i)/size;
				totalFund+=payment;
			}
			cout<<totalFund<<endl;
		}
		void payment(int*& c, int size){
			for (int i=0;i<size;i++){
				int pay=c[i]*0.2*(size-i)/size;
				cout<<pay<<endl;
			}
		}
};
long long FundCalculator::totalFund = 0;

int main() {

	int n;
	cin>>n;
	int* c=new int[n];
	for (int i=0;i<n;i++){
		cin>>c[i];
	}
	FundCalculator f;
	f.setRank(c,n);
	f.cal_totalFund(c,n);
	f.payment(c,n);
	
	delete [] c;

	return 0;
}