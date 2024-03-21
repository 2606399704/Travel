#include<iostream>
using namespace std;
#include<cstring>

int sudo[10][10];//��������ͽ��
bool row[10][10];//��Ǹ����ڴ����Ƿ��Ѿ�����
bool column[10][10];//��Ǹ����ڴ����Ƿ��Ѿ�����
bool grid[10][10];//��Ǹ����Ƿ��ڴ�С�Ź������Ѿ�����


//��⺯�����ж��Ƿ��������
bool check(int r, int j,int n) {
	if (row[n][r] == 1 || column[n][j] == 1|| grid[n][(r / 3) * 3 + j / 3+1]==1)
		return false;
	return true;
}


int DFS(int r,int j) {
	//����Ѿ�������ɣ�����1��ʾ���û���
	if (r == 10) {
		return 1;
	}
	//���ڼ�¼�Ƿ�Ҫ����
	int f = 0;

	if (sudo[r][j]) {
		if (j == 9) {
			//����
			f = DFS(r + 1, 1);
		}
		else {
			//����
			f = DFS(r, j + 1);
		}
		//�ж��Ƿ�Ҫ����
		// 1 ��ʾ����
		// 0 ��ʾҪ
		if (f) {
			return 1;
		}
		else {
			return 0;
		}
	}
	else {
		//��1��ʼ���
		for (int n = 1;n < 10;n++) {
			if (check(r, j, n)) {
				//��¼
				row[n][r] = 1;
				column[n][j] = 1;
				grid[n][(r / 3) * 3 + j / 3+1] == 1;
				sudo[r][j] = n;
				if (j == 9) {
					//����
					f = DFS(r + 1, 1);
				}
				else {
					//����
					f = DFS(r, j + 1);
				}
				if (f) {
					return 1;
				}
				else {
					//������ݣ�ɾ�����
					row[n][r] = 0;
					column[n][j] = 0;
					grid[n][(r / 3) * 3 + j / 3+1] == 0;
					sudo[r][j] = 0;
				}

			}

		}
	}
	//�����ٽ����ԵȲ������������
	return 0;
}

int main() {
	int t = 0;
	cin >> t;
	char sudu;
	while (t) {
		t--;
		//������������
		memset(row, 0, sizeof(row));
		memset(column, 0, sizeof(column));
		memset(grid, 0, sizeof(grid));
		memset(sudo, 0, sizeof(sudo));
		for (int i = 1;i < 10;i++) {
			for (int j = 1;j < 10;j++) {
				cin >> sudu;
				sudo[i][j] = sudu - '0';
				row[sudo[i][j]][i] = 1;
				column[sudo[i][j]][j] = 1;
				grid[sudo[i][j]][(i/3)*3 + j / 3] == 1;
			}
		}

		//�ʼ֮���ԵȲ����𰸣��������ԭ��

		/*����һ��Ϊʲô�ǣ�r+j/3��
			i    i/3    j   j/3   
			0     0     0    0     
			1     0     1    0     
			2     0     2    0     
			3     1     3    1     
			4     1     4    1     
			5     1     5    1    
			6     2     6    2     
			7     2     7    2     
			8     2     8    2     
			9     3     9    3       

		  ��a=i/3��b=j/3

		    a     b     gird
			0     0      0
			0     1      1
			0     2      2
			1     0      3
			1     1      4
			1     2      5
			2     0      6
			2     1      7
			2     2      8
			
			��֪gird=��i/3��*3+��j/3��
			*/

		//��1,1��ʼ
		DFS(1, 1);
		cout << endl;
		for (int i = 1;i < 10;i++) {
			for (int j = 1;j < 10;j++) {
				cout << sudo[i][j];
			}
			cout << endl;
		}
	}
	return 0;
}