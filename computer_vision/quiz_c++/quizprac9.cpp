#include <iostream>
#include<string.h>
#pragma warning(disable: 4996)
using namespace std;

/*
int Add(int argNum1, int argNum2)
{
	cout << "Add int 2°³" << endl;
	return argNum1 + argNum2;
}
double Add(double argNum1, double argNum2)
{
	cout << "Add double 2°³" << endl;
	return argNum1 + argNum2;
}
double Add(int argNum1, double argNum2)
{
	cout << "add int 1 double 1" << endl;
	return argNum1 + argNum2;
}
*/
/*
void Sub(int a, int b)
{
	cout << a << " - " << b << " = " << a - b << endl;
}
void Sub(float a, float b)
{
	cout << a << " - " << b << " = " << a - b << endl;
}
*/
/*
int sign(float a)
{
	if (a > 0)
		return 1;
	else if (a == 0)
		return 0;
	else
		return -1;
}
double sign(double a)
{
	if (a > 0)
		return 1;
	else if (a == 0)
		return 0;
	else
		return -1;
}
*/
/*
class Triangle
{
	int width;
	int height;
public:
	Triangle(){}
	Triangle(int argWidth, int argHeight): width(argWidth),height(argHeight)
	{}
	int GetWidth() {
		return width;
	}
	int GetHeight() {
		return height;
	}
};
class Square
{
private:
	int width;
public:
	Square(){}
	Square(int argSide): width(argSide)
	{}
	int GetWidth() {
		return width;
	}
};
class Circle
{
	int radius;
public:
	Circle(){}
	Circle(int argRadius): radius(argRadius)
	{}
	int GetRadius() {
		return radius;
	}
};
int Calculate(Triangle t)
{
	return t.GetHeight() * t.GetWidth() / 2;
}
int Calculate(Square s)
{
	return s.GetWidth() * s.GetWidth();
}
double Calculate(Circle c)
{
	return c.GetRadius() * c.GetRadius() * 3.14;
}
*/

/*
class Unit
{
	int level, type;
public:
	Unit()
	{
		level = 0;
		type = 0;
	}
	Unit (int n, int m): level(n), type(m)
	{}
	int GetLevel() {
		return level;
	}
	int GetType() {
		return type;
	}
};
*/
/*
class Circle
{
private:
	double radius;
public:
	Circle(int agRadius): radius(agRadius)
	{}
	Circle(double agRadius): radius(agRadius)
	{}
	double CalculateArea()
	{
		return radius * radius * 3.14;
	}
};
*/
/*
#define MAX_LEN 255
class Unit
{
	char* pszName;
public:
	Unit()
	{
		pszName = new char[MAX_LEN];
		cout << "Normal Constructor\n";
	}
	~Unit()
	{
		delete[] pszName;
		//cout << "Destroy Constructor\n";
	}
	Unit(const Unit& unit);

	void Print() {
		cout << pszName << endl;
	}
	void Set(char* pszIn) {
		strcpy(pszName, pszIn);
	}
};
Unit::Unit(const Unit& unit)
{
	pszName = new char[MAX_LEN];
	strcpy(pszName, "Untitled");
	//strcpy(pszName, unit.pszName);
	cout << "Copy Constructor\n";
}
*/
/*
void set(int x = 0, int y = 0)
{
	cout << "x: " << x << ", y: " << y << endl;
}
*/

/*
class Star
{
private:
	int num;
public:
	Star(){}
	Star(int agNum)
	{
		num = agNum;
	}
	void printStar(int n);
	void printStar(char n);
	void printStar(float n);
	void printStar(double n);
};
void Star::printStar(int n)
{
	for (int i = 0; i < n; i++)
		cout << "*";
	cout << endl;
}
void Star::printStar(char n)
{
	n = n - '0';
	for (int i = 0; i < n; i++)
		cout << "*";
	cout << endl;
}
void Star::printStar(float n)
{
	for (int i = 0; i < n; i++)
		cout << "*";
	cout << endl;
}
void Star::printStar(double n)
{
	for (int i = 0; i < n; i++)
		cout << "*";
	cout << endl;
}
*/

class Unit
{
private:
	int x;
	int y;
public:
	Unit() {
		x = 0;
		y = 0;
	}
	Unit(int a, int b = 0)
	{
		x = a;
		y = b;
	}
	Unit(Unit& agUnit)
	{
		x = agUnit.x + 1;
		y = agUnit.y - 1;
		cout << "copy constructor" << endl;
	}
	int GetX() {
		return x;
	}
	int GetY() {
		return y;
	}
};
int main(int argc, char* argv[])
{
	Unit a(1, 2), b(3, 3), d(4, 5);
	a = b;
	cout << "A: " << a.GetX() << ", " << a.GetY() << endl;
	cout << "B: " << b.GetX() << ", " << b.GetY() << endl;
	cout << "d: " << d.GetX() << ", " << d.GetY() << endl;
	cout << endl;
	b = d;
	cout << "A: " << a.GetX() << ", " << a.GetY() << endl;
	cout << "B: " << b.GetX() << ", " << b.GetY() << endl;
	cout << "d: " << d.GetX() << ", " << d.GetY() << endl;
	cout << endl;
	Unit c = d;
	cout << "A: " << a.GetX() << ", " << a.GetY() << endl;
	cout << "B: " << b.GetX() << ", " << b.GetY() << endl;
	cout << "c: " << c.GetX() << ", " << c.GetY() << endl;
	cout << "d: " << d.GetX() << ", " << d.GetY() << endl;
	

	/*
	int a;
	char b;

	printf("Int: ");
	scanf("%d", &a);
	printf("Char: ");
	scanf("%*c%c", &b);

	Star s1(a);
	Star s2(b);
	Star s3(4.4);
	Star s4(2.2);
	
	s1.printStar(a);
	s2.printStar(b);
	s3.printStar(4.4);
	s4.printStar(2.2);
	*/
	
	/*
	Unit Drone(10, 20);
	Unit Unknown;

	cout << "Drone: " << Drone.GetX() << ", " << Drone.GetY() << endl;
	cout << "Unknown: " << Unknown.GetX() << ", " << Unknown.GetY() << endl;
	*/
	/*
	set();
	set(1);
	set(1, 4);
	*/
	/*
	//Unit Zerg, Spawn;
	Unit Zerg;
	char c[20] = "zergling";
	Zerg.Set(c);
	Zerg.Print();

	Unit Spawn = Zerg;
	Spawn.Print();
	*/
	/*
	Circle c1(5);
	Circle c2(5.5);
	cout << "area=" << c1.CalculateArea() << endl;
	cout << "area=" << c2.CalculateArea() << endl;
	*/
	/*
	Unit A[4];
	Unit B[4] = { Unit(1,2),Unit(3,4),Unit(5,6),Unit(7,8) };
	for (int i = 0; i < 4; i++) {
		cout << "A[" << i << "]: " << "level=" << A[i].GetLevel() << " type=" << A[i].GetType() << endl;
		cout << "B[" << i << "]: " << "level=" << B[i].GetLevel() << " type=" << B[i].GetType() << endl;
	}
	*/

	/*
	Triangle tri(5, 2);
	Square square(5);
	Circle circle(5);

	cout << "Triangle= " << Calculate(tri) << endl;
	cout << "Square= " << Calculate(square) << endl;
	cout << "Circle= " << Calculate(circle) << endl;
	*/
	/*
	float x = 10.09;
	double y = 10.09;

	cout << sign(x) << endl << sign(y) << endl;
	cout << sign(10) << endl;
	*/
	/*
	Sub(10, 1);
	Sub(10.5f, 1.8f);
	*/
	/*
	Add(1, 1);
	Add(1, 1.0);
	Add(1.0, 1.0);
	*/


	return 0;
}