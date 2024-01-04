#include <iostream>
using namespace std;

class Sphere {
private:
    int radius;
public:
    Sphere() {} 
    Sphere(int r) {radius=r;}
    double getSurfaceArea(); // 겉넓이 반환 함수
};
double Sphere::getSurfaceArea(){ // 4ㅠr^2
	return 4*3.14*radius*radius;
}

int main() {

	int n;
	cin>>n;
	Sphere* s=new Sphere[n];
	for (int i=0;i<n;i++){
		int r;
		cin>>r;
		Sphere temp(r);
		s[i]=temp;
		cout<<fixed;
    cout.precision(2);
		cout<<s[i].getSurfaceArea()<<endl;
	}
	delete [] s;
	return 0;
}