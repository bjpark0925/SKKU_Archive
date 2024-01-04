// 작성된 코드 예시입니다.
#include <iostream>
#include <string>
using namespace std;

class Card {
private:
	int num;
	char color;
public:
	Card(){}
	/*
	Card(Card& c){
		this->num=c.num;
		this->color=c.color;
	}
	*/
	~Card(){}
	void setNum(int _num) {num=_num;}
	void setColor(char _color) {color=_color;}
	int getNum() {return num;};
	char getColor() {return color;};
};

int main()
{
	int t;
	cin>>t;
	Card c[t];
	
	string s;
	cin>>s;
	int card_pos=0;
	int pos=0;
	while(1){ // B 먼저 삽입 - 정렬 시 B W 고려 안해도 됨
		int b_index=s.find('B',pos);
		if (b_index==-1){
			break;
		}
		else{
			c[card_pos].setColor('B');
			pos=b_index+1;
			int digit=0;
			while(isdigit(s[pos])){
				digit++;
				pos++;
			}
			c[card_pos].setNum(stoi(s.substr(pos-digit,digit)));
			card_pos++;
		}
	}
	pos=0;
	while(1){ // W 삽입
		int w_index=s.find('W',pos);
		if (w_index==-1){
			break;
		}
		else{
			c[card_pos].setColor('W');
			pos=w_index+1;
			int digit=0;
			while(isdigit(s[pos])){
				digit++;
				pos++;
			}
			c[card_pos].setNum(stoi(s.substr(pos-digit,digit)));
			card_pos++;
		}
	}
	//sort
	for (int i=1;i<t;i++){
		for (int j=0;j<t-i;j++){
			// c[j] c[j+1] swap
			if (c[j].getNum()>c[j+1].getNum()){
				Card temp;
				temp=c[j];
				c[j]=c[j+1];
				c[j+1]=temp;
			}
		}
	}
	
	int num;
	cin>>num;
	if (num==0){
		for (int i=0;i<t;i++){
			cout<<c[i].getColor()<<c[i].getNum();
		}
	}
	else{
		if (c[num-1].getColor()=='W'){
			cout<<"White ";
		}
		else if (c[num-1].getColor()=='B'){
			cout<<"Black ";
		}
		cout<<c[num-1].getNum();
	}
	
	return 0;
}