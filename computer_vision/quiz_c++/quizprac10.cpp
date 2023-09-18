#include<iostream>
#pragma warning(disable:4996)
using namespace std;
/*
class Unit
{
private:
	int hp;
public:
	Unit()
	{
		hp = 0;
	}
	Unit(int i)
	{
		hp = i;
	}
	int GetHP() {
		return hp;
	}
	//Unit operator+(Unit right);
	//Unit operator-(Unit right);
	int operator==(Unit right);
	int operator!=(Unit right);
	Unit& operator++();
	Unit& operator++(int);
	friend Unit operator+(Unit left, Unit right);
	friend Unit operator-(Unit left, Unit right);
	Unit operator*(Unit right)
	{
		Unit temp;
		temp.hp = hp * right.GetHP();
		return temp;
	}
};
/*
Unit Unit::operator+(Unit right)
{
	Unit temp;
	temp.hp = hp + right.hp;
	return temp;
}
Unit Unit::operator-(Unit right)
{
	Unit temp;
	temp.hp = right.hp - hp;
	return temp;
}
*/
/*
int Unit::operator==(Unit right)
{
	if (hp == right.GetHP())
		return 1;
	else
		return 0;
}
int Unit::operator!=(Unit right)
{
	if (hp != right.GetHP())
		return 1;
	else
		return 0;
}
Unit& Unit::operator++()
{
	hp++;
	return (*this);
}
Unit& Unit::operator++(int)
{
	Unit tmp(*this);
	hp++;
	return tmp;
}
Unit operator+(Unit left, Unit right)
{
	Unit temp;
	temp.hp = left.hp + right.hp;

	cout << "left hp = " << left.hp << endl;
	cout << "right hp = " << right.hp << endl;
	cout << "+ result hp = " << temp.hp << endl;

	return temp;
}
Unit operator-(Unit left, Unit right)
{
	Unit temp;
	temp.hp = left.hp + right.hp;

	cout << "left hp = " << left.hp << endl;
	cout << "right hp = " << right.hp << endl;
	cout << "- result hp = " << temp.hp << endl;

	return temp;
}
*/
/*
class Unit
{
private:
	int hp;
	int mp;
	int unitSize;
	char* name;
public:
	Unit()
	{
		hp = 0;
		mp = 0;
		unitSize = 0;
		name = NULL;
	}
	Unit(int argHp, int argMp, int argSize, const char* argName) : hp(argHp), mp(argMp), unitSize(argSize)
	{
		name = new char[strlen(argName) + 1];
		strcpy(name, argName);
	}
	~Unit()
	{
		if (!name)
		{
			delete[] name;
			name = NULL;
		}
	}
	int GetSize() {
		return unitSize;
	}
	int operator+(Unit right);
	int operator-(Unit right);
	int operator*(Unit right);
};
int Unit::operator+(Unit right)
{
	return GetSize() + right.GetSize();
}
int Unit::operator-(Unit right)
{
	return GetSize() - right.GetSize();
}
int Unit::operator*(Unit right)
{
	return GetSize() * right.GetSize();
}
class HUnit : public Unit
{
public:
	HUnit(): Unit(45,125,2,"HUnit")
	{}
};
void funcUnit(Unit a)
{
	cout << a.GetSize() << endl;
}
void funcHUnit(HUnit a)
{
	cout << a.GetSize() << endl;
}
*/
/*
#define MAX_LEN 255

class Unit
{
private:
	char* pszName;
public:
	Unit()
	{
		pszName = new char[MAX_LEN];
		cout << "Normal Constructor\n";
	}
	~Unit()
	{
		if (!pszName)
		{
			delete[] pszName;
			pszName = NULL;
		}
	}
	void Print() {
		cout << pszName << endl;
	}
	void Set(char* pszIn) {
		strcpy(pszName, pszIn);
	}
	Unit& operator=(Unit& right);
};
Unit& Unit::operator=(Unit& right)
{
	cout << "operator called" << endl;
	strcpy(pszName, right.pszName);
	return *this;
}
*/
/*
double vals[] = { 1,2,3,4,5 };

double& setValues(int i) {
	return vals[i];
}
*/
/*
class Student
{
	int id;
public:
	Student(int input): id(input)
	{}
	friend ostream& operator<<(ostream& os, Student& s);
};
ostream& operator<<(ostream& os, Student& s)
{
	os << "Student ID = " << s.id;
	return os;
}
*/
#define MAX_SIZE 100
class MySet
{
private:
	int* array;
	int size;
public:
	MySet()
	{
		array = new int[MAX_SIZE];
		size = 0;
	}
	MySet(int* agArray, int agSize)
	{
		array = new int[MAX_SIZE];
		size = agSize;
		for (int i = 0; i < size; i++) {
			array[i] = agArray[i];
		}
	}
	~MySet()
	{
		if (!array) {
			delete[] array;
			array = NULL;
		}
	}
	void Print() {
		for (int i = 0; i < size; i++)
			cout << " " << array[i];
	}
	MySet operator^(MySet right)
	{
		MySet temp;
		temp.array = new int[MAX_SIZE];
		temp.size = 0;
		for (int j = 0; j < size; j++) {
			for (int i = 0; i < right.size; i++) {
				if (array[j] == right.array[i]) {
					temp.array[temp.size] = array[j];
					temp.size++;
					break;
				}
			}
		}
		return temp;
	}
	MySet operator*(MySet right)
	{
		MySet temp;
		temp.array = new int[MAX_SIZE];
		temp.size = 0;
		for (int i = 0; i < size; i++) {
			temp.array[temp.size] = array[i];
			temp.size++;
		}
		int flag = 0;
		for (int j = 0; j < right.size; j++) {
			for (int i = 0; i < size; i++) {
				if (right.array[j] == array[i]) {
					flag = 1;
					break;
				}
			}
			if (flag == 0) {
				temp.array[temp.size] = right.array[j];
				temp.size++;
			}
			flag = 0;
		}
		return temp;
	}
};
int main()
{
	int s1[] = { 1,3,5,7,9,11 };
	int s2[] = { 11,13,7,9,20 };

	MySet set1(s1, 6);
	MySet set2(s2, 5);

	cout << "SET1 = {1,3,5,7,9,11}\n";
	cout << "SET2 = {11,13,7,9,20}\n";

	MySet Inter;

	Inter = set1 ^ set2;
	cout << "SET1 ^ SET2 =";
	Inter.Print();
	cout << "\n";

	MySet Uni;
	Uni = set1 * set2;
	cout << "SET1 * SET2 =";
	Uni.Print();
	/*
	Student s(10);
	cout << s << endl;
	*/
	/*
	for (int i = 0; i < 5; i++)
		cout << vals[i] << endl;
	setValues(1) = 6;
	for (int i = 0; i < 5; i++)
		cout << vals[i] << endl;
		*/
	/*
	Unit Zerg, Spawn;
	char c[20] = "zergling";

	Zerg.Set(c);
	Zerg.Print();

	Spawn = Zerg;
	Spawn.Print();
	*/
	/*
	Unit Unit1(2), Unit2(5), Unit3;
	Unit3 = Unit1 + Unit2;
	Unit3 = Unit1 - Unit2;
	Unit3 = Unit1 * Unit2;
	cout << Unit3.GetHP();
	*/
	/*
	Unit Unit1, Unit2, Unit3(10);
	Unit1 = Unit3++;
	Unit2 = ++Unit3;

	cout << Unit1.GetHP() << endl;
	cout << Unit2.GetHP() << endl;
	*/
	/*
	Unit Unit1(1);
	cout << "Unit1 hp = " << Unit1.GetHP() << endl;
	++Unit1;
	cout << "++Unit1 hp = " << Unit1.GetHP() << endl;
	*/
	/*
	HUnit a;
	funcUnit(a);

	HUnit c1, c2;
	cout << "Total Unit size(+): " << c1 + c2 << endl;
	cout << "Total Unit size(-): " << c1 - c2 << endl;
	cout << "Total Unit size(*): " << c1 * c2 << endl;
	*/
	/*
	Unit Unit1(10), Unit2(5), Unit3(5);

	if (Unit1 != Unit2)
		cout << "Unit1 != Unit2\n";
	else
		cout << "Unit1 == Unit2\n";

	if (Unit2 != Unit3)
		cout << "Unit2 != Unit3\n";
	else
		cout << "Unit2 == Unit3\n";
		*/
	/*
	if (Unit1 == Unit2)
		cout << "Unit1 == Unit2\n";
	else
		cout << "Uni1 != Unit2\n";

	if (Unit2 == Unit3)
		cout << "Unit2 == Unit3\n";
	else
		cout << "Unit != Unit3\n";
		*/
	/*
	Unit3 = Unit1 - Unit2;

	cout << "Unit1 hp=" << Unit1.GetHP() << endl;
	cout << "Unit2 hp=" << Unit2.GetHP() << endl;
	cout << "Unit3 hp=" << Unit3.GetHP() << endl;
	*/


	return 0;
}