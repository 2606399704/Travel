#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

int login();//��½����
int user();//�û���������
int num1();//ͼ�����۹���ϵͳ
int num11();//ͼ�����۹���ϵͳ>��Ա����
int num111();//ͼ�����۹���ϵͳ > ��Ա��Ϣ���� > ��ʾ��Ա��Ϣ
int num112();//ͼ�����۹���ϵͳ > ��Ա��Ϣ���� > ������Ա��Ϣ
int num113();//ͼ�����۹���ϵͳ > ��Ա��Ϣ���� >�޸Ļ�Ա��Ϣ
int num12();//ͼ�����۹���ϵͳ >�鼮����
int num121();//ͼ�����۹���ϵͳ>�鼮����>�鼮�б�
int num122();//ͼ�����۹���ϵͳ >�鼮����>����鼮
int num123();//ͼ�����۹���ϵͳ >�鼮����>�鼮�¼�
int num13();//ͼ�����۹���ϵͳ >�������


//��Ա��Ϣ
struct id
{
	int s;
	char name[30];
	int money;
};

struct id id1[20] = { 1,"����",100 ,2,"����",600 ,3,"����",500 ,4,"½��",1000 ,5,"Ǯ��",900 ,6,"��ǿ",100 ,7,"С��",100 ,8,"����",100 };
id2 = 8;

//�鼮��Ϣ
struct books
{
	int s;
	char book[30];
	int money;
};

struct books book1[20] = { 1,"C#2.0����",88 ,2,"Java��̻���",55 ,3,"J2SE����Ӧ�ó��򿪷�",60 ,4,"���ݿ���ƺ�Ӧ��",45 ,5,"ˮ�ΰ",55 ,6,"��¥��",68 ,7,"��������",78 ,8,"�����μ�",29 };
book2 = 8;


int main()
{
	int flag = 0;
	while (1)
	{
		flag = login();
		if (flag == 2)
		{
			break;
		}
		flag = user();
		if (flag == 0)
		{
			break;
		}
		printf("��¼�ɹ���\n");
		printf("\n");
		while (1)
		{
			flag = num1();
			if (flag == 1)
			{
				while (1)
				{
					flag = num11();
					if (flag == 1)
					{
						num111();
					}
					else if (flag == 2)
					{
						num112();
					}
					else if (flag == 3)
					{
						num113();
					}
					else if (flag == 4)
					{
						break;
					}
				}
			}
			else if (flag == 2)
			{
				while (1)
				{
					flag = num12();
					if (flag == 1)
					{
						num121();
					}
					else if (flag == 2)
					{
						num122();
					}
					else if (flag == 3)
					{
						num123();
					}
					else if (flag == 4)
					{
						break;
					}
				}
			}
			else if (flag == 3)
			{
				num13();
			}
			else if (flag == 4)
			{
				break;
			}
		}
	}
	return 0;
}


//��½����
int login()
{
	int n = 0;
	char ch;
	while (1)
	{
		printf("******************************\n");
		printf("*      ͼ�����۹���ϵͳ      *\n");
		printf("*         1.��¼             *\n");
		printf("*         2.�˳�             *\n");
		printf("******************************\n");
		printf("��ѡ���������֣�1-2����");
		scanf("%d", &n);
		if (n >= 1 && n <= 2)
		{
			break;
		}
		else
		{
			printf("\n");
			printf("�����������������\n");
			while ((ch = getchar()) != EOF && ch != '\n');
		}
	}
	printf("\n");
	return n;
}


//�û���������
int user()
{
	int i = 3;
	char ch;
	char name[10] = "admin";
	int password = 123456;
	char names[10] = "";
	int passwords = 0;
	while (i)
	{
		printf("\n");
		printf("�������û�����");
		scanf("%s", names);
		printf("���������룺");
		scanf("%d", &passwords);
		printf("\n");
		if (strcmp(names, name) == 0 && passwords==password)
		{
			break;
		}
		else
		{
			i--;
			printf("�������\n");
			printf("�㻹��%d�λ���\n", i);
			while ((ch = getchar()) != EOF && ch != '\n');
		}
	}
	if (i != 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


//ͼ�����۹���ϵͳ
int num1()
{
	int n = 0;
	char ch;
	while (1)
	{
		printf("******************************\n");
		printf("*      ͼ�����۹���ϵͳ      *\n");
		printf("*         1.��Ա����         *\n");
		printf("*         2.�鼮����         *\n");
		printf("*         3.�������         *\n");
		printf("*         4.ע��             *\n");
		printf("******************************\n");
		printf("��ѡ���������֣�1-4����");
		scanf("%d", &n);
		if (n >= 1 && n <= 4)
		{
			break;
		}
		else
		{
			printf("\n");
			printf("�����������������\n");
			while ((ch = getchar()) != EOF && ch != '\n');
		}
	}
	printf("\n");
	return n;
}


//ͼ�����۹���ϵͳ>��Ա����
int num11()
{
	int n = 0;
	char ch;
	while (1)
	{
		printf("ͼ�����۹���ϵͳ>��Ա����\n");
		printf("**************************\n");
		printf("*  1.��ʾ���л�Ա        *\n");
		printf("*  2.��ӻ�Ա��Ϣ        *\n");
		printf("*  3.�޸Ļ�Ա��Ϣ        *\n");
		printf("*  4.�������˵�          *\n");
		printf("**************************\n");
		printf("��ѡ���������֣�");
		scanf("%d", &n);
		if (n >= 1 && n <= 4)
		{
			break;
		}
		else
		{
			printf("\n");
			printf("�����������������\n");
			while ((ch = getchar()) != EOF && ch != '\n');
		}
	}
	printf("\n");
	return n;
}


//ͼ�����۹���ϵͳ > ��Ա��Ϣ���� > ��ʾ��Ա��Ϣ
int num111()
{
	int i = 0;
	printf("ͼ�����۹���ϵͳ > ��Ա��Ϣ���� > ��ʾ��Ա��Ϣ\n");
	printf("��Ա��      ����     ����\n");
	for (i = 0;i < id2;i++)
	{
		printf("   %-9d%-8s%5d\n", i + 1, id1[i].name, id1[i].money);
	}
	printf("\n");
	printf("\n");
	return 0;
}


//ͼ�����۹���ϵͳ > ��Ա��Ϣ���� > ������Ա��Ϣ
int num112()
{
	printf("ͼ�����۹���ϵͳ > ��Ա��Ϣ���� > ������Ա��Ϣ\n");
	printf("�������»�Ա����:");
	scanf("%s", id1[id2].name);
	printf("�������»�Ա����:");
	scanf("%d", &id1[id2].money);
	id2 += 1;
	printf("��ӳɹ���\n");
	printf("\n");
	return 0;
}


//ͼ�����۹���ϵͳ > ��Ա��Ϣ���� >�޸Ļ�Ա��Ϣ
int num113()
{
	int i = 0;
	printf("ͼ�����۹���ϵͳ > ��Ա��Ϣ���� >�޸Ļ�Ա��Ϣ\n");
	printf("������Ҫ�޸ĵĻ�Ա��:");
	scanf("%d", &i);
	printf("������Ҫ�޸ĵĻ�Ա����:");
	scanf("%s", id1[i - 1].name);
	printf("������Ҫ�޸ĵĻ�Ա����:");
	scanf("%d", &id1[i - 1].money);
	printf("�޸ĳɹ���\n");
	printf("\n");
	return 0;
}


//ͼ�����۹���ϵͳ >�鼮����
int num12()
{
	int n = 0;
	char ch;
	while (1)
	{
		printf("ͼ�����۹���ϵͳ >�鼮����\n");
		printf("****************\n");
		printf("* 1.�鿴��Ŀ   *\n");
		printf("* 2.����鼮   *\n");
		printf("* 3.ɾ���鼮   *\n");
		printf("* 4.�������˵� *\n");
		printf("****************\n");
		printf("��ѡ���������֣�");
		scanf("%d", &n);
		if (n >= 1 && n <= 4)
		{
			break;
		}
		else
		{
			printf("\n");
			printf("�����������������\n");
			while ((ch = getchar()) != EOF && ch != '\n');
		}
	}
	printf("\n");
	return n;
}


//ͼ�����۹���ϵͳ>�鼮����>�鼮�б�
int num121()
{
	int i = 0;
	printf("ͼ�����۹���ϵͳ>�鼮����>�鼮�б�\n");
	printf("ͼ���     ͼ����                ͼ���Ǯ\n");
	for (i = 0;i < book2;i++)
	{
		printf("   %-8d%-20s%5d\n", book1[i].s, book1[i].book, book1[i].money);
	}
	printf("\n");
	printf("\n");
	return 0;
}


//ͼ�����۹���ϵͳ >�鼮����>����鼮
int num122()
{
	printf("ͼ�����۹���ϵͳ >�鼮����>����鼮\n");
	printf("������ͼ������");
	scanf("%s", book1[book2].book);
	printf("������ͼ���Ǯ��");
	scanf("%d", &book1[book2].money);
	book1[book2].s= book2 + 1;
	book2 += 1;
	printf("��ӳɹ���\n");
	printf("\n");
	return 0;
}


//ͼ�����۹���ϵͳ >�鼮����>�鼮�¼�
int num123()
{
	int i = 0;
	int j = 0;
	char book[30] = "";
	printf("ͼ�����۹���ϵͳ >�鼮����>�鼮�¼�\n");
	printf("������Ҫɾ����ͼ��������");
	scanf("%s", book);
	for (i = 0; i < book2; i++)
	{
		if (strcmp(book, book1[i].book) == 0)
		{
			j = i + 1;
			break;
		}
	}
	if (i == book2)
	{
		printf("���鲻���ڣ�\n");
	}
	else
	{
		printf("�ҵ���ͼ�飬λ��Ϊ��%d\n", book1[i].s);
		for (i = j - 1;i < book2 - 1;i++)
		{
			book1[i] = book1[i + 1];
		}
		book2 -= 1;
		printf("ɾ���ɹ���\n");
	}
	printf("\n");
	return 0;
}


//ͼ�����۹���ϵͳ >�������
int num13()
{
	printf("ͼ�����۹���ϵͳ >�������\n");
	num121();
	int z = 0;
	int i = 0;
	int j = 0;
	int m = 0;
	char yn;
	char ch;
	while (1)
	{
		while (1)
		{
			printf("�������Ա�ţ�");
			scanf("%d", &z);
			if (z >= 1 && z <= 4)
			{
				break;
			}
			else
			{
				printf("\n");
				printf("�����������������\n");
				while ((ch = getchar()) != EOF && ch != '\n');
			}
		}
		while (1)
		{
			printf("������Ҫ������鼮��ţ�");
			scanf("%d", &j);
			for (i = 0;i < book2;i++)
			{
				if (book1[i].s == j)
				{
					j == i;
					break;
				}
			}
			if (i == book2)
			{
				printf("\n");
				printf("���鲻���ڣ�����������\n");
				while ((ch = getchar()) != EOF && ch != '\n');
			}
			else
			{
				break;
			}
		}
		printf("��������Ҫ�����������");
		scanf("%d", &m);
		printf("�������ͼ��Ϊ%s������Ϊ%d���ܶ�Ϊ%d\n", book1[i].book, m, book1[i].money * m);
		if (id1[z - 1].money >= book1[i].money * m)
		{
			id1[z - 1].money -= book1[i].money * m;
		}
		else
		{
			printf("���Ļ��ֲ��㣡\n");
			printf("\n");
			return 0;
		}
		printf("�Ƿ��������y/n����");
		getchar();
		scanf("%c", &yn);
		if (yn == 'n')
		{
			break;
		}
	}
	printf("\n");
	return 0;
}