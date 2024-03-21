#include<iostream>
using namespace std;
#include<cstring>
#define ll long long

//num�洢���̣�toto�洢��
int num[1010], toto[1010];
//lim�洢�����ȣ�flag�ж��Ƿ���ڴ�
int lim, flag;


ll gcd(ll mol, ll den) { 
	return den == 0 ? mol : gcd(den, mol % den); 
}


//depΪ��ǰ��ȣ�molΪ���ӣ�denΪ��ĸ��preΪǰһ�������ķ�ĸ
void dfs(ll dep, ll mol, ll den, ll pre) {
	//�ж��Ƿ񵽴���ȵ�
	if (dep == lim + 1) {
		//�����Ƿ�Ϊ0�������м�����Ϊ����
		if (mol == 0) {
			//������һ��������֮ǰ�Ĵ𰸴�
			//�����޴洢��
			if (num[lim] < toto[lim]||toto[lim]==0) {
				for (ll i = 0;i < dep;i++) {
					toto[i] = num[i];
				}
			}
			//��Ǵ��ڴ�
			flag = true;
		}
		return;
	}
	//Ҫ�������м�������i>(pre-1)
	//den/mol�ó�����1/c>=mol/den����Сcֵ
	for (int i = max(pre, den / mol);;i++) {
		//ԭʽΪ(lim - dep + 1)/i<mol/den
		//������ȫΪ1/i��������С���������������㣬�ų�
		if (den * (lim - dep + 1) < i * mol) {
			break;
		}
		//��¼����
		num[dep] = i;
		//�������ġ�/��ֻ�����������������㷨���ų�������Ӱ�죬ֱ��������
		//�Ҳ�������㷨��ʲô����
		ll mol2 = mol * i - den;
		ll den2 = den * i;
		ll g = gcd(mol2, den2);
		dfs(dep + 1, mol2/g, den2/g, i+1);
	}
	return;
}


int main() {
	flag = false;
	int a, b;
	cin >> a >> b;
	memset(num, 0, sizeof(num));
	memset(toto, 0, sizeof(toto));
	//���迼�Ǽ������ٵ�����
	//��Ϊ�ó��Ĵ𰸼���һ�����٣������Ϊ1��ʼ���У�
	for (lim = 1;;lim++) {
		//��ʼ���Ϊ1��ǰ��ĸΪ1
		dfs(1, a, b, 1);
		if (flag) break;
	}
	for (int i = 1;i <= lim;i++) {
		cout << toto[i] << " ";
	}
	return 0;
}