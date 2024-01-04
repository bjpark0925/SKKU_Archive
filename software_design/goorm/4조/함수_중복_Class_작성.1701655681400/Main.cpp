#include <iostream>
#include <string>
using namespace std;

class Student {
	private:
	string name;
	int studentID;
	double grade;
	//bool is_int=false;

	public:
	Student(){name="Unknown"; studentID=0; grade=0.0;}
	Student(string _name, int _studentID, double _grade){
		name=_name;
		studentID=_studentID;
		grade=_grade;
	}
	
// TODO: 성적 입력 함수 중복 정의
	void inputGrade(int _grade){
		grade=_grade;
		//is_int=true;
	}
	void inputGrade(double _grade){
		grade=_grade;
	}
// TODO: 성적 출력 함수 중복 정의
	char displayGrade(int _grade) const{
		if(grade>=90){
			return 'A';
		}
		else if(grade>=80){
			return 'B';
		}
		else if(grade>=70){
			return 'C';
		}
		else if(grade>=60){
			return 'D';
		}
		else{
			return 'F';
		}
	}
	double displayGrade(double _grade) const{
		return grade;
	}
	void displayStudentInfo() const {
		cout << "Student Information:\n";
		cout << "Name: " << name << "\n";
		cout << "Student ID: " << studentID << "\n";
// TODO: 성적 출력 함수 호출
		/*
		if (is_int){
			cout << "Grade: "<<this->displayGrade((int)grade)<<endl;
		}
		else{
			cout << "Grade: "<<this->displayGrade(grade)<<endl;
		}
		*/
	}
};

int main() {
	Student student1("Alice", 101, 0.0);
	Student student2("Bob", 102, 0);
	
	//To-do: 성적 입력 함수 호출
	//student1.inputGrade(95);
  //student2.inputGrade(75.5);
	
	student1.displayStudentInfo();
	student2.displayStudentInfo();
	
	return 0;
}