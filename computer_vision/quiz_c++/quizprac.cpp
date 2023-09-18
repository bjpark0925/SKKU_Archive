#include <iostream>

using namespace std;

//int g_var = 1;

/*struct Student
{
	int id;
	float grade;
	int gender;
};
*/
/*
typedef struct SELL
{
	int coke;
	int sprite;
	int rice;
	int pizza;
}sell;

void initialize(sell *s)
{
	s->coke = 10;
	s->sprite = 10;
	s->rice = 10;
	s->pizza = 10;
}
*/

/*namespace AA
{
	char test = 'A';
	void func(char c)
	{
		cout << "Inside AA, Input: " << c << endl;
	}
}

namespace BB
{
	char test = 'B';
	void func(char c)
	{
		cout << "Inside BB, Input: " << c << endl;
	}
}*/

/*namespace Elementary
{
	struct Student
	{
		int id;
		int age;
	};
}

namespace University
{
	struct Student
	{
		int id;
		float grade;
	};
}*/
int main()
{
	float concentration = 0;
	float real_concentration = 0;

	concentration = (30 / 40) * 100;
	cout << "Weight percent=" << concentration << endl;

	real_concentration = (float)30 / 40 * 100;
	cout << "Real Weight percent=" << real_concentration << endl;
	/*
	struct Elementary::Student eleS;

	cout << "Enter EleS id\n";
	cin >> eleS.id;
	cout << "Enter EleS age\n";
	cin >> eleS.age;

	struct University::Student uniS;

	cout << "Enter UniS id\n";
	cin >> uniS.id;
	cout << "Enter UniS age\n";
	cin >> uniS.grade;

	cout << "Ele id: " << eleS.id << endl << "Ele age: " << eleS.age << endl;
	cout << "Uni id: " << uniS.id << endl << "Uni grade: " << uniS.grade << endl;

	*/
	
	/*
	AA::func(AA::test);
	AA::func(BB::test);
	BB::func(AA::test);
	BB::func(BB::test);
	*/
	/*
	sell s;
	initialize(&s);

	while (1) {
		int order;
		cout << "Order (0: Drink, 1: Food, 2: Quit) : ";
		cin >> order;
		if (order == 0) {
			int order;
			cout << "Drink (3:Coke, 4: Sprite) : ";
			cin >> order;
			if (order == 3)
				s.coke--;
			if (order == 4)
				s.sprite--;

		}
		if (order == 1) {
			int order;
			cout << "Food (5:Rice, 6: Pizza) : ";
			cin >> order;
			if (order == 5)
				s.rice--;
			if (order == 6)
				s.pizza--;
		}
		if (order == 2)
			break;
		cout << "Remaining: Coke=" << s.coke << ", Sprite=" << s.sprite << ", Rice=" << s.rice << ", Pizza=" << s.pizza << endl;
		if (s.coke == 0 || s.sprite == 0 || s.rice == 0 || s.pizza == 0)
			break;
	}
	*/
	
	/*
	struct Student st;

	cout << "학번을 입력하세요\t";
	cin >> st.id;

	cout << "성적을 입력하세요\t";
	cin >> st.grade;

	cout << "성별을 입력하세요\t";
	cin >> st.gender;

	cout << "\n\n";
	cout << "입력하신 학생의\n";
	cout << "학번은 " << st.id << endl;

	cout.setf(ios::showpoint);
	cout.precision(2);

	cout << "성적은 " << (float)st.grade << endl;

	cout << "성별은 " << (st.gender == 1 ? "남자" : "여자") << endl;
	cout << "입니다\n";
	*/
	
	/*
	int l_var = 2;
	printf("g_var=%d,l_var=%d\n", g_var, l_var);
	*/
	/*
	int age;
	float grade;
	char name[20];
	cout << "Enter age, grade, and name:" << endl;
	cin >> age >> grade >> name;
	cout << "Stored values:\n" << "Age=" << age << ", " << "Grade=" << grade << ", " << "Name=" << name << endl;
	*/
	/*
	int var = 1;
	{
		char var = 'a'; 
		{
			cout << "1. var=" << var << '\n';
		}
		cout << "2. var=" << var << '\n';
	}
	cout << "3. var=" << var << '\n';
	*/
	
	return 0;
}