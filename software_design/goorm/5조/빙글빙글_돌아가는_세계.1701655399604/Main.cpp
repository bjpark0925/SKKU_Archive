#include <iostream>
using namespace std;

class H {
private:
	int r = 0, i = 0, j = 0, k = 0; // r은 real number의 이니셜 (변수명을 '1'로 지을 수 없기 때문)
public:
	void setH(int _r, int _i, int _j, int _k) { r = _r; i = _i; j = _j; k = _k; }
	void printH() { cout << this->r << " + " << this->i << "i + " << this->j << "j + " << this->k << "k"; }

	// 구현할 부분
	H operator +(H h2){
		H h3;
		h3.setH(r+h2.r, i+h2.i, j+h2.j, k+h2.k);
		return h3;
	}
	H operator *(H h2){
		H h4;
		int h4_r=r*h2.r-i*h2.i-j*h2.j-k*h2.k;
		int h4_i=r*h2.i+i*h2.r+j*h2.k-k*h2.j;
		int h4_j=r*h2.j+j*h2.r-i*h2.k+k*h2.i;
		int h4_k=r*h2.k+i*h2.j-j*h2.i+k*h2.r;
		h4.setH(h4_r, h4_i, h4_j, h4_k);
		return h4;
	}
};

int main() {
	H H1, H2, H3, H4;
	int tempR, tempI, tempJ, tempK;

	cout << "사원수 H1을 생성합니다." << endl;
	cout << "H1 = ( ) + ( )i + ( )j + ( )k" << endl;
	cout << "정수 4개를 순서대로 입력하세요. >> ";
	cin >> tempR >> tempI >> tempJ >> tempK;
	H1.setH(tempR, tempI, tempJ, tempK);
	cout << endl << "H1 = "; H1.printH(); cout << endl << endl;

	cout << "사원수 H2를 생성합니다." << endl;
	cout << "H2 = ( ) + ( )i + ( )j + ( )k" << endl;
	cout << "정수 4개를 순서대로 입력하세요. >> ";
	cin >> tempR >> tempI >> tempJ >> tempK;
	H2.setH(tempR, tempI, tempJ, tempK);
	cout << endl << "H2 = "; H2.printH(); cout << endl << endl;

	cout << "사원수의 덧셈 연산을 실행합니다." << endl;
	H3 = H1 + H2;
	cout << "H1 + H2 = "; H3.printH(); cout << endl << endl;

	cout << "사원수의 곱셈 연산을 실행합니다." << endl;
	H4 = H1 * H2;
	cout << "H1 * H2 = "; H4.printH(); cout << endl << endl;

	return 0;
}