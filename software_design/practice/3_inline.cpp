#include <iostream>
#include <ctime>
using namespace std;

int odd(int x)
{
	return (x % 2);
}

inline int odd_inline(int x)
{
	return (x % 2);
}

int main()
{
	int itr = 1000000;
	int cnt = 0;
	clock_t s, e;

	s = clock();
	for (int i = 1; i <= itr; i++) {
		if (odd(i))
			cnt++;
	}
	cout << cnt << endl;
	e = clock();

	cout << "normal: " << (double)(e - s) / CLOCKS_PER_SEC << endl;

	cnt = 0;
	s = clock();
	for (int i = 1; i <= itr; i++) {
		if (odd_inline(i))
			cnt++;
	}
	cout << cnt << endl;
	e = clock();

	cout << "inline: " << (double)(e - s) / CLOCKS_PER_SEC << endl;
}