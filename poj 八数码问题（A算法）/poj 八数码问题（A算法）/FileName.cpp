#include<iostream>
using namespace std;
#include<queue>
#include<stack>

//��¼�����������
int vis[362881];
//��Լ������ֱ���г�9��
int f[] = { 1,1,2,6,24,120,720,5040,40320,362880 };
//0���ƶ�����--���ϡ��ҡ���
int walk[4][4] = { {-1,0},{0,-1},{1,0},{0,1} };
const int Max_Step = 32;//����������

//�������̽ṹ��
struct Chess {
	int chessnum[9];
	int value=0;
	Chess* Parent;//���ڵ�
};

//��ӡ����
void PrintChess(struct Chess* TheChess){
	cout << "����ֵΪ" << TheChess->value;
	for (int i = 0;i < 9;i++) {
		if (i % 3 == 0) {
			printf("\n");
		}
		printf("%d ", TheChess->chessnum[i]);
	}
	printf("\n\n");
}

//�����㷨�����ж��ٸ�������Ŀ��λ��Ϊ����ֵ��Խ��Խ����
void Estimate(struct Chess* TheChess, struct Chess* Goal) {
	int num = 0;
	for (int i = 0;i < 9;i++) {
		if (TheChess->chessnum[i] != Goal->chessnum[i]) num++;
	}
	TheChess->value = num;
}

//�ڶ�������һ���ط��洢�µ����̣��ƶ�����λ�ã����ص�ַ
struct Chess* MoveChess(struct Chess* TheChess, int i){
	struct Chess* NewChess;
	NewChess = new Chess;
	int z = 0;
	for (int i = 0;i < 9;i++) {
		if (TheChess->chessnum[i] == 0) {
			z = i;
			break;
		}
	}
	int x1 = z % 3;
	int y1 = z / 3;
	int x2, y2;
	x2 = x1 + walk[i][0];
	y2 = y1 + walk[i][1];
	if (x2 >= 0 && x2 < 3 && y2 >= 0 && y2 < 3) {
		int nz = x2 + y2 * 3;
		for (int i = 0;i < 9;i++) {
			NewChess->chessnum[i] = TheChess->chessnum[i];
		}
		NewChess->chessnum[z] = TheChess->chessnum[nz];
		NewChess->chessnum[nz] = TheChess->chessnum[z];
	}
	return NewChess;
}

//����չ����������ѹ������
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


void bfs(struct Chess* Begin, struct Chess* Goal) {
	memset(vis, 0, sizeof(vis));
	//p1�洢�Ӷ���ȡ��������
	//p2�洢�仯���������
	//p�洢��������
	Chess* p1, * p2, * p;
	p2 = new Chess;
	int Step = 0;//���
	p = NULL;
	queue<Chess*>q;
	q.push(Begin);
	while (p == NULL ||!q.empty()) {
		p1 =q.front();
		q.pop();
		for (int i = 0;i < 4;i++) {
			p2 = MoveChess(p1, i);
			Estimate(p2, Goal);
			if (p2->value <= p1->value&& cantor(p2->chessnum)) {
				p2->Parent = p1;
				q.push(p2);
				if (p2->value == 0)//�������
				{
					p = p2;
				}
			}
			//������ֵ�����⣬��ɾ���ڵ�
			else
			{
				delete p2;//Ϊ���ʽڵ�������
				p2 = NULL;
			}
		}
		Step++;
		if (Step > Max_Step)
			p=NULL;
	}
	//����ջ�����Ŵ洢·��������ջ���ص�������
	stack<Chess*>s;
	s.push(p);
	Chess* p3 = p;
	while (p3->Parent != NULL) {
		p3 = p3->Parent;
		s.push(p3);
	}
	while (s.size()) {
		PrintChess(s.top());
		s.pop();
	}
}

int main() {
	Chess Goal;
	Chess* Begin;
	Begin = new Chess;
	for (int i = 0;i < 9;i++) {
		scanf_s("%d", &Begin->chessnum[i]);
	}
	for (int i = 0;i < 9;i++) {
		scanf_s("%d", &Goal.chessnum[i]);
	}
	Estimate(Begin, &Goal);
	Begin->Parent = NULL;
	Goal.value = 0;
	printf("%s","��ʼ����:");
	PrintChess(Begin);
	printf("%s", "Ŀ������:");
	PrintChess(&Goal);
	bfs(Begin, &Goal);
	return 0;
}