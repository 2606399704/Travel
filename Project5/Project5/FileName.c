#include<stdio.h>
#include<string.h>
int main()
{
	char arr1[] = { "123456" };
	char arr2[20] = { 0 };
	int i = 0;
	for (i == 0; i < 3; i++)
	{
		printf("���������룺");
		scanf_s("%s", arr2, 20);
		if (strcmp(arr1, arr2) == 0)
		{
			printf("������ȷ");
			break;
		}
		else
		{
			printf("������󣡣���");
		}
	}
	return 0;
}