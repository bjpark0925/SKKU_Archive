#include <iostream>
#include <string>
using namespace std;

class Clothes
{
public:
	string type;
	string color;
	int price;
	
	// 필요 시 생성자 추가 가능
	Clothes() {}
	Clothes(string _type, string _color, int _price){
		type=_type;
		color=_color;
		price=_price;
	}
};

class PresentSet
{
public:
	string name;
	int number;
	Clothes *set;
	
	PresentSet(string _name, int _number);
	PresentSet(PresentSet &s);
	PresentSet(string _name, PresentSet &s1, PresentSet &s2);
	~PresentSet();
	void add_clothes(int n); // set 에 clothes 추가 (인자 자유롭게 변형 가능)
	void set_name(string _name);
	void replace(int _index, Clothes& c); // 의류 대체 함수 (인자 자유롭게 변형 가능)
	void print();
};
PresentSet::PresentSet(string _name, int _number){
	name=_name;
	number=_number;
}
PresentSet::PresentSet(PresentSet &s){
	name=s.name;
	number=s.number;
	set=new Clothes[number];
	for (int i=0;i<number;i++){
		set[i]=s.set[i];
	}
}
PresentSet::PresentSet(string _name, PresentSet &s1, PresentSet &s2){
	name=_name;
	number=s1.number+s2.number;
	set=new Clothes[number];
	for (int i=0;i<s1.number;i++){
		set[i]=s1.set[i];
	}
	for (int i=s1.number;i<number;i++){
		set[i]=s2.set[i-s1.number];
	}
}
PresentSet::~PresentSet(){
	delete [] set;
}
void PresentSet::add_clothes(int n){
	set=new Clothes[n];
	for (int i=0;i<n;i++){
		int clothes_price;
		string clothes_type;
		string clothes_color;
		cin>>clothes_type;
		cin>>clothes_color;
		cin>>clothes_price;
		set[i]=Clothes(clothes_type, clothes_color, clothes_price);
	}
}
void PresentSet::set_name(string _name){
	name=_name;
}
void PresentSet::replace(int _index, Clothes& c){
	set[_index]=c;
	/*
	set[_index].type=c.type;
	set[_index].color=c.color;
	set[_index].price=c.price;
	*/
}
void PresentSet::print(){
	cout<<name<<endl;
	for (int i=0;i<number;i++){
		cout<<i+1<<". "<<set[i].type<<"("<<set[i].color<<"): "<<set[i].price<<" WON"<<endl;
	}
}

int main()
{
	//선물세트1
	int n; // 의류 개수
	string set1_name; // 선물세트1 이름
	
	cin>>set1_name;
	cin>>n;
	
	PresentSet set1(set1_name, n);
	set1.add_clothes(n);
	
	//선물세트2
	string set2_name;
	PresentSet set2(set1);
	
	cin>>set2_name;
	set2.set_name(set2_name);
	
	//대체될 의류 인덱스
	int replace_index;
	cin>>replace_index;
	
	//대체할 의류 정보
	int rclothes_price;
	string rclothes_type;
	string rclothes_color;
	cin>>rclothes_type;
	cin>>rclothes_color;
	cin>>rclothes_price;
	Clothes temp(rclothes_type, rclothes_color, rclothes_price);
	
	set2.replace(replace_index, temp);
	
	//선물세트3
	string set3_name;
	cin>>set3_name;
	
	PresentSet set3(set3_name, set1, set2);
	
	//print
	set1.print();
	set2.print();
	set3.print();
	
	return 0;
}