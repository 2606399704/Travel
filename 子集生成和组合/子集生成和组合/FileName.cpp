#include<iostream>
using namespace std;


void print_subset(int n) {
	for (int i = 0;i < (1 << n);i++) {
		//��1<<n��������ж��������
		for (int j = 0;j < n;j++) {
			if (i & (1 << j)) {
				//&ֻ������Ϊ1��Ϊ1
				//iΪ�Ӽ��Ķ����ƣ��ɵ�λ����λ�ڼ�λΪ1���ʹ�ӡ��
				//������ȫΪ0��Ϊ�ռ�������ӡ
				cout << j << " ";
			}
		}
		cout << endl;
	}
}
int main() {
	int n;//������Ԫ�ص�����
	cin >> n;
	print_subset(n);
	return 0;
}