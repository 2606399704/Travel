#include<iostream>
using namespace std;
#include<queue>
#include<cstring>

//�������飬��¼�����λ�ã������ظ�����
const int maxn = 100001;
bool vis[maxn];

//�����½ṹ�壬��¼λ�úͲ���
struct node {
	int n;
	int step;
};

int main() {
	queue<node>x;
	int n, k, m, s;
	while (cin >> n >> k) {
		//������Ԫ��ȫ��Ϊ0
		memset(vis, 0, sizeof(vis));
		vis[n] = 1;
		node q = { n,0 };
		x.push(q);
		while (true) {
			//��������Ԫ��ȡ�����������������
			m = x.front().n;
			s = x.front().step;
			x.pop();
			if (2 * m == k || m + 1 == k || m - 1 == k) break;
			else {
				if (!vis[2 * m]) {
					node v = { 2 * m,s + 1 };
					x.push(v);
					vis[2 * m] = 1;
				}
				if (!vis[m + 1]) {
					node v = { m + 1,s + 1 };
					x.push(v);
					vis[m + 1] = 1;
				}
				if (!vis[m - 1]) {
					node v = { m - 1,s + 1 };
					x.push(v);
					vis[m - 1] = 1;
				}
			}
		}
		cout << s + 1 << endl;
	}
	return 0;
}