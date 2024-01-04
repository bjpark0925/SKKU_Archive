#include <iostream>
#include <string>
using namespace std;

class Student {
private:
	int code;
	string name;
	double grade; //내림차순, 평균 중앙값 계산
public:
	Student(){}
	void setStudent(int _code, string _name, double _grade){
		code=_code;
		name=_name;
		grade=_grade;
	}
	int getCode(){return code;}
	string getName(){return name;}
	double getGrade(){return grade;}
};

int main() {

	int n;
	cin>>n;
	
	double sum=0;
	Student* s=new Student[n];
	for (int i=0;i<n;i++){
		int code;
		string name;
		double grade;
		cin>>code;
		cin>>name;
		cin>>grade;
		s[i].setStudent(code, name, grade);
		sum+=grade;
	}
	//정렬
	for (int i=0;i<n-1;i++){
		for (int j=0;j<n-i-1;j++){
			if (s[j].getGrade()<s[j+1].getGrade()){
				int tcode=s[j].getCode();
				string tname=s[j].getName();
				double tgrade=s[j].getGrade();
				s[j].setStudent(s[j+1].getCode(), s[j+1].getName(), s[j+1].getGrade());
				s[j+1].setStudent(tcode, tname, tgrade);
			}
		}
	}
	//평균
	double avg=sum/n;
	
	//중앙값
	double mid;
	if (n%2!=0){
		mid=s[n/2].getGrade();
	}
	else{
		mid=(s[(n/2)-1].getGrade()+s[n/2].getGrade())/2;
	}
	
	for (int i=0;i<n;i++){
		cout<<s[i].getCode()<<" "<<s[i].getName()<<" "<<s[i].getGrade()<<endl;
	}
	cout<<avg<<endl<<mid<<endl;
	
	delete [] s;

	return 0;
}