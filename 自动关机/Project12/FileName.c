#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	char input[20] = { 0 };
	system("shutdown -s -t 60");
again:
	printf("��ĵ��Խ���һ�����ڹػ�\n����ȡ����ִֹͣ��:>");
	scanf_s("%s", input,20);
	if(strcmp(input, "ȡ��") == 0)
		system("shutdown -a");
	else
		goto again;
	return 0;
}