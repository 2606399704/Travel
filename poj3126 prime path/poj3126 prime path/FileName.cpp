#include<iostream>
using namespace std;
#include<queue>
#include<cstring>

const int maxn = 100001;
bool vis1[maxn];//��¼����
bool vis2[maxn];//��¼�������

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
	queue<int>q;
	int s, n;
	int p;
	int a[4];
	while (cin >> s >> n) {
		//����¼���
		memset(vis2, 0, sizeof(vis2));
		//�������
		int count = 0;
		//�洢
		q.push(s);
		while (!q.empty()) {
			int remain = q.size();
			while (remain--) {
				//����ȡ����ɾ��
				p = q.front();
				q.pop();
				//����Ƿ����
				if (p == n) {
					cout << count << endl;
					break;
				}
				a[0] = p / 1000;
				a[1] = p % 1000 / 100;
				a[2] = p % 100 / 10;
				a[3] = p % 10;
				//�ı�һλ���ʹ洢
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
							q.push(temp);
							vis2[temp] = 1;
						}
					}
					//�ظ����޸ĵ���
					a[i] = orgin_place;
				}
			}
			++count;
		}

	}
	return 0;
}