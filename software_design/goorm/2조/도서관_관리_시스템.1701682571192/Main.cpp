#include <iostream>
#include <string>
using namespace std;

struct Book {
    string title;
    string author;
    int publicationYear;
public:
	void setBook(string _title, string _author, int _public){
		title=_title;
		author=_author;
		publicationYear=_public;
	}
	string getTitle(){
		return title;
	}
};

struct Member {
    string name;
    int memberId;
    int borrowedBooks; // 현재 대출 중인 도서의 수
    Book* borrowedBookList; // 대출 중인 도서의 목록 (도서는 최대 5권 대출 가능)
public:
	Member(){
		borrowedBooks=0;
		borrowedBookList=nullptr;
	}
	void setMember(string _name, int _memberId){
		name=_name;
		memberId=_memberId;
		borrowedBookList=new Book[5];
	}
	string getName(){
		return name;
	}
	void borrow(Book &b){
		borrowedBookList[borrowedBooks]=b;
		borrowedBooks++;
	}
	void turn(){
		borrowedBooks--;
	}
	~Member(){
		delete [] borrowedBookList;
	}
};

int main()
{
	int n;
	cin>>n;
	Book* b=new Book[n];
	for (int i=0;i<n;i++){
		string ititle, iauthor;
		int ipublic;
		cin>>ititle;
		cin>>iauthor;
		cin>>ipublic;
		b[i].setBook(ititle, iauthor, ipublic);
	}
	
	int p;
	cin>>p;
	Member* m=new Member[p];
	for (int i=0;i<p;i++){
		string iname;
		int imemberId;
		cin>>iname;
		cin>>imemberId;
		m[i].setMember(iname, imemberId);
	}
	
	if (n==0){
		cout<<"대출 가능한 도서가 없습니다."<<endl;
	}
	else{
		int order;
		cin>>order;

		if (order!=1&&order!=2){
			cout<<"대출 또는 반납을 선택해주세요."<<endl;
		}

		int b_index, m_index;
		cin>>m_index;
		cin>>b_index;

		if (b_index>n||m_index>p){
			if (b_index>n){
				cout<<"존재하지 않는 도서입니다."<<endl;	
			}
			if (m_index>p){
				cout<<"등록되지 않은 회원입니다."<<endl;
			}
		}
		else{
			if (order==1){ // 대출
				cout<<"도서 \""<<b[b_index-1].getTitle()<<"\"이(가) 회원 \""<<m[m_index-1].getName()<<"\"에게 대출되었습니다."<<endl;
				m[m_index-1].borrow(b[b_index-1]);
			}
			else if(order==2){ // 반납
				cout<<"도서 \""<<b[b_index-1].getTitle()<<"\"이(가) 회원 \""<<m[m_index-1].getName()<<"\"에게 반납되었습니다."<<endl;
				m[m_index-1].turn();
			}
		}
	}
	
	delete [] b;
	delete [] m;
	
	return 0;
}