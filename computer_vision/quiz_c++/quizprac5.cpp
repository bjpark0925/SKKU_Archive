#include <iostream>
using namespace std;

//void printDebugMsg(int);
/*
void printArea(int x, int y)
{
	int area = x * y;
	cout << "Area:" << area << endl;
}
int getArea(int x, int y)
{
	int area = x * y;
	return area;
}
*/
/*
void calArea(int r)
{
	float pi = 3.14;
	cout << "Radius " << r << "=" << pi << "x" << r << "x" << r << "=" << pi * r * r << endl;
}
*/
/*
inline int increase(int x)
{
	return x + 1;
}
*/
/*
void recursiveFunction(int num)
{
	printf("%d\n", num);

	if (num < 4)
		recursiveFunction(num + 1);
}

void recursiveFunction2(int num)
{
	if (num < 4)
		recursiveFunction2(num + 1);

	printf("%d\n", num);
}
*/
/*
int Sum(int n)
{
	if (n == 1)
		return 1;
	else
		return n + Sum(n - 1);
}
*/
/*
int Factorial(int n)
{
	if (n == 1)
		return 1;
	return n * Factorial(n - 1);
}
*/
int Fibo(int n)
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	/*int x = 1;
	if (n <= 2)
		return x;*/
	else
		return Fibo(n - 1) + Fibo(n - 2);
}

int main(int argc, char* argv[])
{
	int result = Fibo(8);
	cout << "Fibo:" << result << endl;
	/*
	int result = Factorial(4);
	cout << "Factorial: " << result << endl;
	*/
	/*
	int result = Sum(4);
	cout << "Sum: " << result << endl;
	*/
	/*
	int i = 0;
	recursiveFunction2(i);
	*/
	/*
	int i;
	cout << "Enter Number: ";
	cin >> i;
	cout << increase(i) << endl;
	*/
	
	/*
	int min, max;
	cout << "Enter Min(1~10):";
	cin >> min;
	cout << "Enter Max(min~10):";
	cin >> max;

	for (int i = min; i <= max; i++) {
		calArea(i);
	}
	*/
	
	/*
	int width, height;
	cout << "Enter width: ";
	cin >> width;
	cout << "Enter height: ";
	cin >> height;

	int area = getArea(width, height);
	cout << "Area: " << area << endl;
	*/
	
	/*
	int i;
	for (i = 0; i < 2; i++) {
		printDebugMsg(i);
	}

	printDebugMsg(i);
	*/
	


	return 0;
}

/*void printDebugMsg(int i)
{
	cout << "print debug message:i=" << i << "\n";
}*/