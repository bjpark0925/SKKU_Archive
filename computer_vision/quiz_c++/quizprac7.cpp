#include <iostream>
#include <string.h>
#pragma warning(disable:4996)

using namespace std;
/*
class Unit
{
	int x, y;
public:
	void set(int i, int j) {
		x = i;
		y = j;
	}
	void show() {
		cout << x << "," << y << "\n";
	}
};
*/

/*
class Unit
{
	char* str;
public:
	Unit()
	{
		cout << "I'm a default constructor\n";
		str = NULL;
	}

	Unit(char* agStr)
	{
		cout << "I'm a default constructor with parameters\n";
		int strLength = strlen(agStr);
		str = new char[strLength + 1];
		strcpy(str, agStr);
	}

	Unit(Unit& agUnit)
	{
		cout << "I'm a copy constructor\n";
		str = agUnit.str;
	}

	void set(char* agStr)
	{
		strcpy(str, agStr);
	}

	void show()
	{
		cout << str << endl;
	}

	void copyFrom(Unit& agUnit)
	{
		strcpy(str, agUnit.str);
	}

	void copyTo(Unit& agUnit)
	{
		strcpy(agUnit.str, str);
	}
};
*/

/*
class Unit
{
	int defaultArmor;
public:
	Unit()
	{
		defaultArmor = 0;
	}
	Unit(int armor)
	{
		defaultArmor = armor;
	}
	Unit(Unit& A)
	{
		cout << "copy constructor" << endl;
		defaultArmor = A.defaultArmor;
	}
	int GetDefaultArmor()
	{
		return defaultArmor;
	}

	void Show()
	{
		cout << "defaultArmor: " << defaultArmor << endl;
	}

	void Set(int armor)
	{
		defaultArmor = armor;
	}
};

Unit GetUnit()
{
	int armor;
	Unit temp;
	cout << "Enter a default armor: ";
	cin >> armor;
	temp.Set(armor);
	return temp;
}

int GetEnhancedArmor(Unit &a)
{
	return a.GetDefaultArmor() * 2;
}
*/

/*
class Unit
{
	int x, y;
public:
	Unit(int i, int j)
	{
		x = i;
		y = j;
	}
	friend bool isSame(Unit a);
};

bool isSame(Unit a)
{
	if (a.x == a.y)
		return true;
	else
		return false;
}
*/
/*
class Square
{
	int height, width;
public:
	Square(int x, int y)
	{
		height = x;
		width = y;
	}
	friend void addSquare(Square& A, Square& B)
	{
		int area = A.height * A.width + B.height * B.width;
		cout << "Sum of Areas: " << area << endl;
	}
};
*/
class Hunit;

class Unit
{
	int x, y;
public:
	Unit(int i, int j)
	{
		x = i;
		y = j;
	}
	friend bool isSame(Unit a, Hunit b);
};

class Hunit
{
	int x, y;
public:
	Hunit(int i, int j)
	{
		x = i;
		y = j;
	}
	friend bool isSame(Unit a, Hunit b);
};

bool isSame(Unit a, Hunit b)
{
	if (a.x == b.x && a.y == b.y)
		return true;
	else
		return false;
}
int main(int argc, char* argv[])
{
	Unit a(1, 2);
	Hunit b(1, 3);

	cout << "a(1,2),b(1,3): " << isSame(a, b) << endl;
	/*
	Square A(5, 3), B(4, 4);
	addSquare(A, B);
	*/
	/*
	Unit a(1, 2), b(3, 3);

	cout << "a(1,2): " << isSame(a) << endl;
	cout << "b(3,3): " << isSame(b) << endl;
	*/
	/*
	Unit a;
	a = GetUnit();
	a.Show();
	*/
	/*
	Unit A(1), B(2);
	cout << "Unit A: " << GetEnhancedArmor(A) << endl;
	cout << "Unit B: " << GetEnhancedArmor(B) << endl;
	*/
	/*
	char c1[20] = "Unit A";
	char c2[20] = "Unit B";
	char c3[20] = "Unit C";

	Unit A(c1), B(c2), C(c3);
	A.show(); B.show(); C.show(); cout << endl;
	A.copyFrom(B); C.copyTo(B);
	A.show(); B.show(); C.show(); cout << endl;
	B.set(c2);
	A.show(); B.show(); C.show(); cout << endl;
	*/
	/*
	char c1[20] = "Test1";
	char c2[20] = "Test2";
	Unit A(c1);
	Unit B = A;
	cout << "----------------------------------\n";

	A.set(c2);

	A.show();
	B.show();
	*/
	/*
	Unit A, B;
	A.set(12, 4);
	B = A;
	A.show();
	B.show();
	*/

	return 0;
}