#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Person
{
	
// 접근지정자 수정 불가
private:
	string name;
	string sex;
	double height;
	double weight;
	double muscle;
	
	double BMI;
	double muscle_ratio;
	
	string obesity_rate;
	string body_muscle_type;

public:
	Person(string _name, string _sex, double _height, double _weight, double _muscle);
	void set_obesity_rate(); // 비만도 계산
	void set_body_muscle_type(); // 근육유형 결정
	void print(); // 출력함수
};
Person::Person(string _name, string _sex, double _height, double _weight, double _muscle){
	name=_name;
	sex=_sex;
	height=_height;
	weight=_weight;
	muscle=_muscle;
}
void Person::set_obesity_rate(){
	BMI=(weight/height)/height;
	if (BMI>=0&&BMI<18.5){
		obesity_rate="underweight";
	}
	else if(BMI>=18.5&&BMI<23){
		obesity_rate="normal weight";
	}
	else if(BMI>=23&&BMI<25){
		obesity_rate="overweight";
	}
	else if(BMI>=25){
		obesity_rate="obesity";
	}
}
void Person::set_body_muscle_type(){
	muscle_ratio=(muscle/weight)*100;
	if (sex=="man"){
		if (muscle_ratio>=0&&muscle_ratio<30){
			body_muscle_type="slim body";
		}
		else if (muscle_ratio>=30&&muscle_ratio<45){
			body_muscle_type="fit body";
		}
		else if (muscle_ratio>=45){
			body_muscle_type="strong body";
		}
	}
	else if (sex=="woman"){
		if (muscle_ratio>=0&&muscle_ratio<20){
			body_muscle_type="slim body";
		}
		else if (muscle_ratio>=20&&muscle_ratio<30){
			body_muscle_type="fit body";
		}
		else if (muscle_ratio>=30){
			body_muscle_type="strong body";
		}
	}
}
void Person::print(){
	cout<<name<<" is "<<obesity_rate<<" and "<<body_muscle_type<<endl;
	double new_weight=21*height*height;
	double goal=new_weight-weight;
	double result = trunc(goal*10) / 10;
	cout<<fixed;
  cout.precision(1);
	cout<<result<<endl;
}

int main()
{

	string name, sex;
	double height, weight, muscle;
	getline(cin, name);
	cin>>sex;
	cin>>height;
	cin>>weight;
	cin>>muscle;
	
	Person min(name, sex, height, weight, muscle);
	min.set_obesity_rate();
	min.set_body_muscle_type();
	min.print();
	
	return 0;
}