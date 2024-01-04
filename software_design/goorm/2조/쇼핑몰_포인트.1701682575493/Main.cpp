// 작성된 코드 예시입니다.
#include <iostream>
#include <string>
using namespace std;

class shopPoint {
private:
	int consume;
	static int point;
public:
	shopPoint(){consume=0;}
	~shopPoint(){}
	void addConsume(int price) {consume+=price;}
	static void addPoint(int price) {
		if (price<10000){
			point+=price*0.05;
		}
		else{
			point+=price*0.1;
		}
	}
	int getConsume() {return consume;}
	static int getPoint() {return point;}
};
int shopPoint::point=0;

int main()
{
	shopPoint A, B, C;
	while(1){
		string order;
		cin>>order;
		if (order=="Q"){
			break;
		}
		else if (order=="P"){
			cout<<"Point : "<<shopPoint::getPoint()<<endl;
		}
		else if (order=="M"){
			cout<<"A : "<<A.getConsume()<<endl;
			cout<<"B : "<<B.getConsume()<<endl;
			cout<<"C : "<<C.getConsume()<<endl;
		}
		else{
			int price;
			cin>>price;
			if (order=="A"){
				A.addConsume(price);
				A.addPoint(price);
			}
			else if (order=="B"){
				B.addConsume(price);
				B.addPoint(price);
			}
			else if (order=="C"){
				C.addConsume(price);
				C.addPoint(price);
			}
		}
	}
	
	return 0;
}