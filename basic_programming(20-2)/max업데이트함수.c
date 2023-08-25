#pragma warning(disable: 4996)
#include<stdio.h>

int max1 = 0, max2 = 0;

void update_max(int x)
{

	if (x > max1) {
		max2 = max1;
		max1 = x;
	}
	else if (x > max2) {
		max2 = x;
	}

}

int main()
{
	int is_first = 1;
	int cnt = 0;
	int a;

	while (1) {
		scanf("%d", &a);

		if (a == 0 && cnt>=2) {
			break;
		}
		else {
			if (is_first) {
				max1 = a;
				is_first = 0;
			}
			else {
				update_max(a);
			}
		}

		cnt++;
	}

	printf("%d %d\n", max1, max2);
	return 0;
}

