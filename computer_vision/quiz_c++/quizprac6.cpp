#include <iostream>
using namespace std;

/*
class Fish
{
public:
	void Swim()
	{
		printf("You invoke swim()\n");
	}
};
*/

/*
struct Quadrangle
{
	int width;
	int height;
	int area;
};

int CalculateArea(struct Quadrangle cQ)
{
	int area = cQ.width * cQ.height;
	return area;
}
*/
/*
class Quadrangle
{
private:
	int width;
	int height;
	int area;

public:
	void SetWidth(int argWidth)
	{
		width = argWidth;
	}
	void SetHeight(int argHeight)
	{
		height = argHeight;
	}
	int CalculateArea();
};
int Quadrangle::CalculateArea()
{
	area = width * height;

	return area;
}
*/
/*
class Circle
{
private:
	int radius;
public:
	void SetRadius(int argRadius)
	{
		radius = argRadius;
	}
	float CalculateArea()
	{
		return radius * radius * 3.14;
	}
};
*/
/*
class Unit
{
	int status;

public:
	Unit()
	{
		cout << "Constructor\n";
		status = 1;
	}
	~Unit()
	{
		cout << "Destructor\n";
		status = 0;
	}
	void fly()
	{
		cout << status << "\n";
	}
};
*/
/*
class Unit
{
	int status;
public:
	Unit(int a);
	~Unit();
	void fly();
};

Unit::Unit(int a): status(a)
{
	cout << "Unit constructor " << a << endl;
}

Unit::~Unit()
{
	cout << "Unit destructing..." << endl;
	status = 0;
}

void Unit::fly()
{
	cout << status << endl;
}
*/
/*
class Student
{
private:
	int year;
	int id;
	int grade;
public:
	/*void setData(int y, int i, int g)
	{
		year = y;
		id = i;
		grade = g;
	}
Student(int y, int i, int g)
{
	year = y;
	id = i;
	grade = g;
}
~Student()
{
	year = 0;
	id = 0;
	grade = 0;
}
void showData()
{
	printf("Year: %d, ID: %d, Grade: %d", year, id, grade);
}
};
*/

/*
class P
{
public:
	int x;
protected:
	int y;
private:
	int z;
public:
	P()
	{
		x = 3;
		y = 4;
		z = 5;
	}
	~P()
	{
		x = 0;
		y = 0;
		z = 0;
	}
};

class A :public P
{
public:
	void showX()
	{
		cout << "x: " << x << endl;
	}
	void showY()
	{
		cout << "y: " << y << endl;
	}
	/*
	void showZ()
	{
		cout << "z: " << z << endl;
	}
	
};

class B :protected P
{
public:
	void showX()
	{
		cout << "x: " << x << endl;
	}
	void showY()
	{
		cout << "y: " << y << endl;
	}
};

class C :private P
{
public:
	void showX()
	{
		cout << "x: " << x << endl;
	}
	void showY()
	{
		cout << "y: " << y << endl;
	}
};
*/
/*
class Plus
{
public:
	void plus(int re1, int im1, int re2, int im2)
	{
		cout << "Plus: " << re1 + re2 << "+" << im1 + im2 << "j" << endl;
	}
};

class Minus
{
public:
	void minus(int re1, int im1, int re2, int im2)
	{
		cout << "Minus: " << re1 - re2 << "+" << im1 - im2 << "j" << endl;
	}
};

class Complex : public Plus, public Minus
{
public:
	int re1;
	int im1;
	int re2;
	int im2;
	Complex()
	{
		re1 = 0;
		im1 = 0;
		re2 = 0;
		im2 = 0;
	}
	void setCom(int are, int aim)
	{
		re1 = are;
		im1 = aim;
	}
};


class NPC
{
	int defense;

public:
	void SetDefense(int n);
	int GetDefense();
};

class Grunt :public NPC
{
	int armor;

public:
	void SetArmor(int n);
	int GetArmoredDefense();
};

void NPC::SetDefense(int n)
{
	defense = n;
}

int NPC::GetDefense()
{
	return defense;
}

void Grunt::SetArmor(int n)
{
	armor = n;
}

int Grunt::GetArmoredDefense()
{
	return armor + GetDefense();
}
*/

/*
class Base
{
public:
	Base(int a);
	~Base();
};
Base::Base(int a)
{
	cout << "Constructor of Base " << a << endl;
}
Base::~Base()
{
	cout << "Destructor of Base" << endl;
}
class Derived : public Base
{
public:
	Derived(int a);
	~Derived();
};

Derived::Derived(int a) : Base(a)
{
	cout << "Constructor of Derived " << a << endl;
}

Derived::~Derived()
{
	cout << "Destructor of Derived" << endl;
}
*/

class Student
{
public:
	Student()
	{
		grade = 0;
	}
	//Student(int argGrade) : grade(argGrade){}
	Student(int argGrade)
	{
		grade = argGrade;
	}
	~Student(){}

	int GetGrade()
	{
		return grade;
	}

private:
	int grade;
};

class Calculator
{
public:
	Calculator()
	{
		numberOfStudent = 0;
	}
	void AddStudent(Student argStudent);
	int Sum();

private:
	Student student[50];

protected:
	int numberOfStudent;
};

void Calculator::AddStudent(Student argStudent)
{
	student[numberOfStudent++] = argStudent;
}

int Calculator::Sum()
{
	int sum = 0;
	for (int i = 0; i < numberOfStudent; i++)
		sum += student[i].GetGrade();

	return sum;
}

class CalculatorEx : public Calculator
{
public:
	float Average()
	{
		return (float) Calculator::Sum() / numberOfStudent;
	}
};
int main()
{
	Student student1(30);
	Student student2(90);
	Student student3(100);
	Student student4(50);

	CalculatorEx cal;
	cal.AddStudent(student1);
	cal.AddStudent(student2);
	cal.AddStudent(student3);
	cal.AddStudent(student4);

	cout << "Sum of grades: " << cal.Sum() << endl;
	cout << "Average of grades: " << cal.Average() << endl;
	

	//Derived obj(1);
	/*
	Grunt oUnit;
	Grunt* pUnit;
	pUnit = &oUnit;
	pUnit->SetDefense(10);
	pUnit->SetArmor(20);

	cout << "Get Armored Defense: " << oUnit.GetArmoredDefense() << endl;

	Complex* a = new Complex;

	a->plus(a->re1, a->im1, 2, 3);
	a->minus(a->re1, a->im1, 2, 3);

	a->setCom(1, 1);
	a->plus(a->re1, a->im1, 2, 3);
	a->minus(a->re1, a->im1, 2, 3);

	delete a;
	*/
	/*
	A a;
	B b;
	C c;
	a.showX();
	a.showY();
	//a.showZ();
	b.showX();
	b.showY();
	//b.showZ();
	c.showX();
	c.showY();
	//c.showZ();
	*/
	
	/*
	Student s(2017, 100100, 1);
	s.showData();
	*/
	/*
	Unit oUnit(1);
	oUnit.fly();
	*/
	/*
	int radius = 0;
	Circle circle;

	printf("Input radius: (cm)\n");
	scanf_s("%d", &radius);

	circle.SetRadius(radius);
	printf("Area(radius=%d) = %0.3f\n", radius, circle.CalculateArea());
	*/
	/*
	int w, h;
	Quadrangle cQ;

	cout << "Enter width";
	cin >> w;
	cout << "Enter height";
	cin >> h;

	cQ.SetWidth(w);
	cQ.SetHeight(h);
	printf("Area (w=%d, h=%d) = %d\n", w, h, cQ.CalculateArea());
	*/
	/*
	Fish fish;
	fish.Swim();
	*/


	return 0;
}