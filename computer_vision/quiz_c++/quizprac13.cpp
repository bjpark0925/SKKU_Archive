#include<iostream>
using namespace std;
/*
int user_abs(int a)
{
	int ret;
	ret = a < 0 ? -a : a;
	cout << "processing abs: " << ret << endl;
	return ret;
}
float user_abs(float a)
{
	float ret;
	ret = a < 0 ? -a : a;
	cout << "processing abs: " << ret << endl;
	return ret;
}
double user_abs(double a)
{
	double ret;
	ret = a < 0 ? -a : a;
	cout << "processing abs: " << ret << endl;
	return ret;
}
*/
/*
template <typename T>
T user_abs(T a)
{
	T ret;
	ret = a < 0 ? -a : a;
	cout << "processing abs: " << ret << endl;
	return ret;
}
*/
/*
template <typename T>
T generic_inc(T n)
{
	return ++n;
}
*/
/*
template <typename T, typename Y>
T avg(T a, Y b)
{
	T ret = (a + b) / 2;
	cout << "avg=" << ret << endl;
	return ret;
}
*/
/*
template <typename T, typename Y>
void generic_swap(T& x, Y& y)
{
	T temp = x;
	x = y;
	y = temp;
}
*/
/*
#define MAX_SIZE 50

template <typename TYPE>
class stack 
{
	TYPE data[MAX_SIZE];
	int nCount;
public:
	stack()
	{
		nCount = 0;
	}
	void add(TYPE in)
	{
		data[nCount++] = in;
		if (nCount == MAX_SIZE)
			cout << "overflow: " << nCount << endl;
	}
	TYPE pop(void)
	{
		if (nCount <= 0) {
			cout << "empty" << endl;
			return data[0];
		}
		else
			return data[--nCount];
	}
};
*/
/*
template <typename T>
class list
{
	T data;
	list* pNext;
public:
	list(T a)
	{
		data = a;
		pNext = NULL;
	}
	void add(list* pNode)
	{
		pNode->pNext = this;
		pNext = NULL;
	}
	list* getNext()
	{
		return pNext;
	}
	int getData()
	{
		return data;
	}
};
*/
/*
template <typename T, typename Y>
class calc
{
	T a;
	Y b;
public:
	calc(T _a, Y _b);
	T add();
	T mul();
};
template <typename T, typename Y>
calc<T, Y>::calc(T _a, Y _b)
{
	a = _a;
	b = _b;
}
template <typename T, typename Y>
T calc<T, Y>::add()
{
	return a + b;
}
template <typename T, typename Y>
T calc<T, Y>::mul()
{
	return a * b;
}
*/
template <typename T>
class Vec
{
private:
	T* data;
	T size;
public:
	Vec(T* array, int agSize)
	{
		data = new T[agSize];
		for (int i = 0; i < agSize; i++) {
			data[i] = array[i];
		}
		size = agSize;
	}
	~Vec()
	{
		delete[] data;
		data = NULL;
	}
	void print() {
		for (int i = 0; i < size; i++)
			cout << data[i] << " ";
		cout << endl;
	}
	T getData(int i) {
		return data[i];
	}
	void addFront(T agData);
	void addBack(T agData);
	T getFront();
	T getBack();
};
template <typename T>
void Vec<T>::addFront(T agData)
{
	for (int i = size - 1; i >= 0; i--) {
		data[i + 1] = data[i];
	}
	data[0] = agData;
	size += 1;
}
template <typename T>
void Vec<T>::addBack(T agData)
{
	data[size] = agData;
	size += 1;
}
template <typename T>
T Vec<T>::getFront()
{
	T temp = data[0];
	for (int i = 1; i < size; i++) {
		data[i - 1] = data[i];
	}
	size -= 1;
	return temp;
}
template <typename T>
T Vec<T>::getBack()
{
	T temp = data[size - 1];
	size -= 1;
	return temp;
}
int main(int argc, char* argv[])
{
	int ibuf[4] = { 2,3,4,5 };
	Vec<int> v1(ibuf, 4);

	v1.addFront(1);
	v1.addBack(6);
	v1.addBack(7);

	cout << "v1=";
	v1.print();

	cout << v1.getFront() << " " << v1.getBack() << " " << endl;

	cout << "v1=";
	v1.print();

	/*
	calc<int, double> iCalc(2, 3.1);
	calc<float, int> fCalc(2.1f, 3);
	calc<double, float> dCalc(2.1, 3.1f);

	cout << "i add=" << iCalc.add() << endl;
	cout << "f add=" << fCalc.add() << endl;
	cout << "d add=" << dCalc.add() << endl;

	cout << "i mul=" << iCalc.mul() << endl;
	cout << "f mul=" << fCalc.mul() << endl;
	cout << "d mul=" << dCalc.mul() << endl;
	*/
	/*
	list<int> List1(0);
	list<int>* pNode, * pLast;

	pLast = &List1;
	for (int i = 1; i <= 10; i++) {
		pNode = new list<int>(i);
		pNode->add(pLast);
		pLast = pNode;
	}

	pNode = &List1;
	while (pNode) {
		cout << pNode->getData() << endl;
		pNode = pNode->getNext();
	}
	*/
	/*
	stack<int> stack1;
	stack<float> stack2;
	int i;
	float j;

	for (i = 0; i < 10; i++)
		stack1.add(i);

	for (j = 0; j < 10; j += .4)
		stack2.add(j);

	cout << "Stack1: ";
	for (i = 0; i < 10; i++)
		cout << stack1.pop() << " ";

	cout << endl << "Stack2: ";
	for (i = 0; i < 10; i++)
		cout << stack2.pop() << " ";

	cout << endl;
	*/
	/*
	int a = 57, b = 2;
	cout << "a=" << a << " b=" << b << endl;
	generic_swap(a, b);
	cout << "after swap: a=" << a << " b=" << b << endl;

	double c = 5.7;
	float d = 2.3f;
	cout << "c=" << c << " d=" << d << endl;
	generic_swap(c, d);
	cout << "after swap: c=" << c << " d=" << d << endl;
	*/
	/*
	int x1 = 10;
	int x2 = 0;
	float x3 = 5.1f;

	avg(x1, x2);
	avg(x1, x3);
	*/
	/*
	int x1 = 10, t1;
	float x2 = 5.1f, t2;
	double x3 = -2.3, t3;

	t1 = generic_inc(x1);
	cout << t1 << endl;
	t2 = generic_inc(x2);
	cout << t2 << endl;
	t3 = generic_inc(x3);
	cout << t3 << endl;
	*/
	/*
	int x1 = 10;
	float x2 = 10.1f;
	double x3 = -2.3;
	user_abs(x1);
	user_abs(x2);
	user_abs(x3);
	*/


	return 0;
}