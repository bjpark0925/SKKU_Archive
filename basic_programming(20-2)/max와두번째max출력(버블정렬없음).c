#pragma warning(disable:4996)
#include<stdio.h>

int main()
{
	int n;
	int cnt = 0;
	int is_first = 1;
	int max1, max2;

	while (1) {
		scanf("%d", &n);

		if (n == 0)
			break;
		else {
			if (is_first) { // 첫 입력
				max1 = n;
				max2 = n;
				is_first = 0;
			}

			else { // 두번째 이상 입력
				if (n > max1) {
					max2 = max1;
					max1 = n;
				}
				else if (n > max2)
					max2 = n;
			}
		}
	}

	printf("%d %d\n", max1, max2);
	return 0;
}