#include <iostream>
using namespace std;
//12p 모르겠음
/*
class Unit
{
private:
	int x;
	int y;
public:
	Unit* p;

	Unit(int a, int b, Unit* p)
	{
		x = a;
		y = b;
		this->p = p;
	}
	
	void Print()
	{
		cout << x << "," << y << endl;
		if (this->p == NULL)
			return;
		this->x = p->x;
		this->y = p->y;
		this->p = p->p;
		Print();
	}
};
*/
/*
class Unit
{
private:
	int x;
	int y;
public:
	Unit(int a, int b)
	{
		x = a;
		y = b;
	}
	void Print()
	{
		cout << x << "," << y << endl;
	}
};
*/
/*
void swap(int& x, int& y)
{
	int t;
	t = x;
	x = y;
	y = t;
}
*/
class St
{
public:
	int grade;
	St(int grade)
	{
		this->grade = grade;
	}
};
/*
int FindMaxNumber(int* argGrade)
{
	int maxIndex = 0;
	int max = argGrade[0];
	for (int i = 1; i < 10; i++) {
		if (argGrade[i] > max) {
			maxIndex = i;
			max = argGrade[i];
		}
	}
	return maxIndex;
}
*/
void deSort(int* argGrade)
{
	for (int j = 0; j < 9; j++) {
		for (int i = 9; i > j; i--) {
			if (argGrade[i] > argGrade[i - 1]) {
				//swap
				int tmp = argGrade[i];
				argGrade[i] = argGrade[i - 1];
				argGrade[i - 1] = tmp;
			}
		}
	}
}
void deSortClass(St* s)
{
	for (int j = 0; j < 9; j++) {
		for (int i = 9; i > j; i--) {
			if (s[i].grade > s[i - 1].grade) {
				//swap
				int tmp = s[i].grade;
				s[i].grade = s[i - 1].grade;
				s[i - 1].grade = tmp;
			}
		}
	}
}
int main(int argc, char* argv[])
{
	//int aGrade[10] = { 90,88,85,55,47,92,87,30,89,65 };
	St s[10]= { 90,88,85,55,47,92,87,30,89,65 };
	int maxGradeIndex = 0;

	//deSort(aGrade);
	deSortClass(s);

	cout << "Result\n";
	cout << s[0].grade << "," << s[1].grade << "," << s[2].grade << "," << s[3].grade << "," << s[4].grade << ","
		<< s[5].grade << "," << s[6].grade << "," << s[7].grade << "," << s[8].grade << "," << s[9].grade << endl;

	//maxGradeIndex = FindMaxNumber(aGrade);
	/*
	int max = s[0].grade;
	for (int i = 1; i < 10; i++) {
		if (s[i].grade > max) {
			maxGradeIndex = i;
			max = s[i].grade;
		}
	}

	cout << "점수는 " << s[maxGradeIndex].grade << endl;
	cout << maxGradeIndex + 1 << "번째 학생" << endl;
	*/
	/*
	int i = 4;
	int j = 7;

	cout << "i: " << i << ",\t";
	cout << "j: " << j << "\n";
	swap(i, j);
	cout << "i: " << i << ",\t";
	cout << "j: " << j << "\n";
	*/
	/*
	Unit* pUnit = new Unit[2]{ Unit(1, 2),Unit(3,4) };
	for (int i = 0; i < 2; i++) {
		pUnit[i].Print();
	}

	delete[] pUnit;
	*/
	/*
	int* pInteger = NULL;
	pInteger = new int;

	if (!pInteger)
	{
		cout << "Allocation Fail...\n";
		return -1;
	}
	*pInteger = 777;
	cout << "pInteger=" << *pInteger << endl;
	
	delete pInteger;
	*/
	//12p 모르겠음
	/*
	Unit c(5, 6, NULL);
	Unit b(3, 4, &c);
	Unit a(1, 2, &b);

	cout << "[Print a]" << endl; a.Print();
	cout << "[Print b]" << endl; b.Print();
	cout << "[Print c]" << endl; c.Print();
	*/
	/*
	int num = 45;
	int* pNum = NULL;

	pNum = &num;

	cout << "Address of Num=" << pNum << endl;
	cout << "Value of Number=" << *pNum << endl;
	*/
	/*
	Unit aUnit[2] = { Unit(1,2),Unit(3,4) };
	Unit* pUnit = aUnit;

	cout << "Using '->' operator\n";
	for (int i = 0; i < 2; i++) {
		pUnit->Print();
		pUnit++;
	}
	pUnit = aUnit;

	cout << "Using '.' operator\n";
	for (int i = 0; i < 2; i++) {
		(*pUnit).Print();
		pUnit++;
	}
	*/
	/*
	for (int i = 0; i < 2; i++) {
		cout << "aUnit[" << i << "]=";
		aUnit[i].Print();
	}
	*/


	return 0;
}