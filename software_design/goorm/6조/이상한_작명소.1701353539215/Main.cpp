#include <iostream>
// <string> 라이브러리 사용 금지
#include <cstring>

using namespace std;

// 아래의 클래스를 작성한 후 활용
// 복사생성자 활용
class Person {
public:
	char name[100];
	Person(char* _name){
		cout<<"+"<<endl;
		strcpy(name,_name);
	}
	Person(Person& p){
		cout<<"#"<<endl;
		strcpy(name,p.name);
		//swap
		char tmp=name[1];
		name[1]=name[2];
		name[2]=tmp;
	}
};

int main() {

	char name[100];
	cin>>name;
	
	if (strlen(name)<3||strlen(name)>50){
		cout<<"invalid"<<endl;
	}
	else{
		Person old(name);
		Person renewal(old);
		cout<<renewal.name<<endl;
		cout<<old.name<<endl;
	}

	return 0;
}