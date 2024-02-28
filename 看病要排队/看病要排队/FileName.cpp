#include<iostream>
using namespace std;
#include<queue>
#include<string>

//��������
struct node {
	//���ȼ�
	int p;
	//���ID
	int id;
	//�Զ������ȼ�
	//Ҫ�����Լ�д��˳��n1����n2����
	friend bool operator<(node n1, node n2) {
		if (n1.p != n2.p)
			return n1.p < n2.p;
		else
			return n1.id > n2.id;
	}

};

int main() {
	//�������ȶ���
	priority_queue<node> q[3];
	//��������
	int n;
	//ҽ�� ���ȼ� ҽ��
	int a, b, c;
	//һλ����
	node t;
	//in or out
	string str;
	while (true) {
		//���˵ĳ�ʼID
		int m = 0;
		//��������
		cin >> n;
		//�����Ƿ��ļ�β
		if (n == EOF) break;
		for (int i = 0;i < n;i++) {
			//����in or out
			cin >> str;
			//�����˹����ҽ��
			if (str == "IN") {
				scanf_s("%d%d", &a, &b);
				q[a - 1].push({ b,++m });
			}
			//ҽ������
			else if (str == "OUT") {
				scanf_s("%d", &c);
				if (!q[c - 1].empty()) {
					printf("%d\n", q[c - 1].top().id);
					q[c - 1].pop();
				}
				else printf("EMPTY\n");
			}
		}

	}
	return 0;
}