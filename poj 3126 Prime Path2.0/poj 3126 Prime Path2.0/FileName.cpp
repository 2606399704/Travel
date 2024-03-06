#include<iostream>
using namespace std;
#include<queue>
#include<cstring>

const int maxn = 100001;
bool vis1[maxn];//��¼����
bool vis2[maxn];//��¼�������

struct node {
	int c;
	int count;
};

int main() {
	//�Ƚ�����ȫ��ֵΪ1
	memset(vis1, 1, sizeof(vis1));
	//�����������ı�ǳ���
	for (int i = 1;i <= maxn - 1;i++) {
		for (int j = 2;j < i;j++) {
			if (i % j == 0) {
				vis1[i] = 0;
				break;
			}
		}
	}
	//��������
	int s, n;
	node p;
	node m;
	int a[4];
	while (cin >> s >> n) {
		//��Ϊ����û��һ������Ĺ��ܣ��������������������в����������ʴ�����ѭ����
		queue<node>q;
		//����¼���
		memset(vis2, 0, sizeof(vis2));
		//�������
		p.count = 0;
		p.c = s;
		//����Ƿ����
		int flag = 0;
		//�洢
		q.push(p);
		while (!q.empty()) {
			p = q.front();
			m = p;
			q.pop();
			//����Ƿ����
			if (p.c == n) {
				cout << p.count << endl;
				break;
			}
			a[0] = p.c / 1000;
			a[1] = p.c % 1000 / 100;
			a[2] = p.c % 100 / 10;
			a[3] = p.c % 10;
			//�ı�һλ���ʹ洢
			m.count++;
			for (int i = 0;i < 4;i++) {
				int orgin_place = a[i];
				for (int j = 0;j < 10;j++) {
					if (i == 0 && j == 0)//ǧλ��Ϊ��
						continue;
					if (j == a[i])
						continue;
					a[i] = j;
					int temp = a[0] * 1000 + a[1] * 100 + a[2] * 10 + a[3];
					if (vis1[temp] == 1 && vis2[temp] == 0) {
						m.c = temp;
						q.push(m);
						vis2[temp] = 1;
						if (temp == n) {
							cout << m.count << endl;
							flag = 1;//�����˳�����Լ����
							break;
						}
					}
				}
				//�ظ����޸ĵ���
				a[i] = orgin_place;
				if (flag == 1) {
					break;
				}
			}
			if (flag == 1) {
				break;
			}

		}

	}
	return 0;
}