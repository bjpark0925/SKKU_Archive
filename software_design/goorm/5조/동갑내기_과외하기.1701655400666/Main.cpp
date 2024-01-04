#include <iostream>
using namespace std;

// 구현할 부분
class 전교꼴등;

class 전교일등 {
private:
	int 성적 = 94;
public:
	int 성적보정() {
		if (this->성적 > 100) { this->성적 = 100; cout << endl << "도우너가 최고 성적에 도달했습니다." << endl; return 100; }
		return -1;
	}
	int 시험보기() { return this->성적; }
	void 공부하기() {
		cout << endl << "도우너가 성실히 공부하여 성적이 3점 올랐습니다." << endl;
		this->성적 += 3;
		성적보정();
		cout << endl;
	}
	// 구현할 부분
	void 공부시키기(전교꼴등 &둘리);
};
class 전교꼴등 {
private:
	int 성적 = 5;
public:
	int 성적보정() {
		if (this->성적 < 0) { this->성적 = 0; cout << endl << "둘리가 최저 성적에 도달했습니다." << endl; return 0; }
		if (this->성적 > 100) { this->성적 = 100; cout << endl<<"둘리가 최고 성적에 도달했습니다." << endl; return 100; }
		return -1;
	}
	int 시험보기() { return this->성적; }
	void 놀기() {
		cout << endl << "둘리가 놀면서 시간을 보냅니다. 성적이 1점 떨어졌습니다." << endl;
		this->성적--;
		성적보정();
		cout << endl;
	}
	void 공부하기() {
		cout << endl << "둘리가 책상 앞에 앉았습니다.";
		놀기();
	}
	// 구현할 부분
	friend void 전교일등::공부시키기(전교꼴등 &둘리);
};

// 구현할 부분
void 전교일등::공부시키기(전교꼴등 &둘리){
	cout<<endl<<"도우너가 둘리를 공부시켜 둘리의 성적이 10점 올랐습니다."<<endl;
	둘리.성적+=10;
	둘리.성적보정();
	cout<<endl;
}

int main() {
	전교일등 도우너;
	전교꼴등 둘리;
	int menu = 0;

	cout << "동갑내기 과외하기를 시작합니다." << endl;
	cout << "도우너의 성적: " << 도우너.시험보기() << endl;
	cout << "둘리의 성적: " << 둘리.시험보기() << endl << endl;

	while (menu != 6)
	{
		cout << "=============================" << endl;
		cout << "1. 도우너 - 공부하기" << endl;
		cout << "2. 둘  리 - 놀기" << endl;
		cout << "3. 둘  리 - 공부하기" << endl;
		cout << "4. 도우너 - 둘리 공부시키기" << endl;
		cout << "5. 시험보기" << endl;
		cout << "6. 프로그램 종료" << endl;
		cout << "=============================" << endl;
		cout << "선택지를 고르세요. >> ";
		cin >> menu;
		switch (menu)
		{
		case 1:
			도우너.공부하기();
			break;
		case 2:
			둘리.놀기();
			break;
		case 3:
			둘리.공부하기();
			break;
		case 4:
			도우너.공부시키기(둘리);
			break;
		case 5:
			cout << endl << "도우너의 성적: " << 도우너.시험보기() << endl;
			cout << "둘리의 성적: " << 둘리.시험보기() << endl << endl;
			break;
		case 6:
			cout << "동갑내기 과외하기 프로그램을 종료합니다.";
			break;
		default:
			cout << endl << "잘못된 입력입니다. 다시 입력해 주세요." << endl << endl;
			break;
		}
	}
	return 0;
}