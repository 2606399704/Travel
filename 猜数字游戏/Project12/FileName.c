#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void menu()
{
	printf("******************************\n");
	printf("**** 1 .play     0 .exit *****\n");
	printf("******************************\n");
	printf("������:>");
}
void game()
{
	int i = 0;
	int ret = 0;
	ret = rand()%100+1;
    while (1)
	{
		printf("���һ������:>");
		scanf_s("%d", &i);
		if (i > ret)
			printf("̫����\n");
		else if (i < ret)
			printf("̫С��\n");
		else
		{
			printf("��ϲ�㣬����ˣ�����\n");
			break;
		}
	}

}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�������\n");
			break;
		}
	} while (input);
	return 0;
}