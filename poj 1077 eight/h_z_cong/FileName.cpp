#include<iostream>
using namespace std;
#include<queue>
#include<string>
#define x 0;//����xΪ0


int vis[362881];//��¼����ȫ����
int start[9];//��¼��ʼ����
int goal[9];//��¼Ŀ������
long int f[] = { 1,1,2,6,24,120,720,5040,40320,362880 };//��ǰ��9�������������Լ������ʱ��

//�����½ṹ�壬��¼״̬�͸ı�Ĺ���
struct node {
	int a[9];
	string b;
};

//����˳ʱ�롪�����ϡ��ҡ���
int dis[4][4] = { {-1,0},{0,-1},{1,0},{0,1} };

//����չ��
int cantor(int str[]) {
	int res = 0;
	for (int i = 0;i < 9;i++) {
		int count = 0;
		for (int j = i + 1;j < 9;j++) {
			if (str[i] > str[j]) ++count;//��¼��ǰС�ڴ�λ��������
		}
		res += count * f[9 - i - 1];//�ۼ����еĿ��ܣ��������ʱ�������ŵڼ�
	}
	if (!vis[res]) {//����Ӧ��λ�ü�¼��״̬�ѳ��֣���Լ����
		vis[res] = 1;
		return 1;
	}
	return 0;
}

node bfs() {
	queue<node>q;
	node p;
	//����
	memcpy(p.a, start, sizeof(start));
	q.push(p);
	while (!q.empty()) {
		p = q.front();
		q.pop();
		if (memcmp(p.a, goal, sizeof(goal)) == 0) {//�Ƚ��Ƿ����
			return p;
		}
		int z = 0;
		for (int i = 0;i < 9;i++) {
			if (p.a[i] == 0) {
				z = i;//�ҵ���ʱx��λ��
				break;
			}
		}
		//���Ͻ�����Ϊ��0,0��
		//�����ʼ����
		int x1 = z % 3;
		int y1 = z / 3;
		int x2 = 0;
		int y2 = 0;
		for (int i = 0;i < 4;i++) {
			//���ν��иı�
			x2 = x1 + dis[i][0];
			y2 = y1 + dis[i][1];
			if (x2 >= 0 && x2 < 3 && y2 >= 0 && y2 <= 3) {//�ж��Ƿ񳬳����귶Χ
				int z2 = y2 * 3 + x2;//���¼���x��λ��
				node m = p;
				swap(m.a[z], m.a[z2]);//��x�ƶ���Ŀ��λ��
				if (cantor(m.a)) {//���أ���¼�ı����
					if (i == 0) m.b += 'l';
					else if (i == 1) m.b += 'u';
					else if (i == 2) m.b += 'r';
					else m.b += 'd';
					q.push(m);
				}
			}
		}
	}
	node m;
	m.b = "unsolvable";
	return m;
}
int main() {
	memset(vis, 0, sizeof(vis));
	char ch;
	for (int i = 0;i < 9;i++) {
		
		scanf_s("%c", &ch);
		getchar();
		if (ch == 'x') start[i] = 0;
		else start[i] = ch - '0';
	}
	for (int i = 0;i < 9;i++) {
		scanf_s("%c", &ch);
		getchar();
		if (ch == 'x') goal[i] = 0;
		else goal[i] = ch - '0';
	}
	cantor(start);//��ǳ�ʼλ��
	node c = bfs();
	cout << c.b << endl;
	return 0;
}