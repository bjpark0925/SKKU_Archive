#pragma warning(disable:4996)
#include<stdio.h>

#define TRUE 1
#define FALSE 0

void update_max(int x);

int max1, max2;

int main()
{
	int bool_iteration = TRUE, bool_first = TRUE;
	int cnt = 0;
	int z;

	while (bool_iteration)
	{
		scanf("%d", &z);

		if (z == 0)
		{

			bool_iteration = FALSE;
		}
		else
		{
			if (bool_first)
			{
				max1 = z;
				max2 = z;
				bool_first = FALSE;
			}
			else
			{
				update_max(z);
			}
		}

	}

	printf("%d %d\n", max1, max2);
	return 0;
}

void update_max(int x)
{

	if (x > max1)
	{
		max2 = max1;
		max1 = x;
	}
	else if (x > max2)
	{
		max2 = x;
	}

}