#include<stdio.h>
int main()
{
	int i = 100;
	int j = 2;
	int count = 0;
	for (i = 100; i <= 200; i++)
	{
		for (j = 2; j < i; j++)
			if (i % j == 0)
				break;
		if (i == j)
		{
			printf("%d ", i);
			count++;
		}
	}
	printf("\n��������Ϊ%d\n", count);
	return 0;
}