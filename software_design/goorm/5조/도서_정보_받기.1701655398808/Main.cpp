#include <iostream>
#include <string>
using namespace std;
class Book {
	private:
	string title;
	string author;
	public:
	// 생성자
	Book(){}
	// 제목 반환 함수
	string getTitle() const {
		return title;
	}
	// 저자 반환 함수
	string getAuthor() const {
		return author;
	}
	// 제목 설정 함수
	void setTitle(string _title) {
		title=_title;
	}
	// 저자 설정 함수
	void setAuthor(string _author) {
		author=_author;
	}
	// 정보 출력 함수
	void displayInfo() const {
		//cout<<"Title: "<<title<<", Author: "<<author<<endl;
		cout<<"Title: "<<getTitle()<<", Author: "<<getAuthor()<<endl;
	}
};

int main() {
// 도서 정보를 저장할 클래스 객체 생성
	Book b;
// 사용자로부터 도서 정보 입력 받기
	string ititle, iauthor;
	cout<<"Enter the title of the book: ";
	getline(cin, ititle);
	cout<<"Enter the author of the book: ";
	getline(cin, iauthor);
	b.setTitle(ititle);
	b.setAuthor(iauthor);
// 입력 받은 정보 출력
	cout<<endl<<"Book Information:"<<endl;
	b.displayInfo();
}