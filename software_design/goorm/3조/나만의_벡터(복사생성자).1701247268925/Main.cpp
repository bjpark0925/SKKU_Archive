#include <iostream>

using namespace std;

int n;

class MyVector {
int* value;
public:
    // 생성자와 복사생성자 활용하여 구성
	MyVector(int* p){
		value=p;
	}
	MyVector(MyVector& _vector){
		value=_vector.value;
	}
	void print(){
		for(int i=0;i<n;i++){
			cout<<" "<<value[i];
		}
		cout<<endl;
	}
};

int main() {

    // main 함수 구성
	cin>>n;
	
	int* p=new int[n];
	for (int i=0;i<n;i++){
		cin>>p[i];
	}
	
	MyVector vector1(p);
	MyVector vector2(vector1);
    cout << "Original Vector:";
    vector1.print();
    cout << "Copied Vector:";
    vector2.print();

	delete [] p;
    return 0;
}