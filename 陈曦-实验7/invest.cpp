#include<iostream>
#include<vector>

using namespace std;

int main() {

	int m, n;//mԪǮ��n��Ͷ��
	int i, j;//ѭ����������
	int tmp_m, tmp_F = 0;//tmp_m�������i����ĿͶ���Ǯ��  0<=tmp<=j;tmp_F����һ��ѭ���е�Ǯ��
	cin >> m >> n;
	vector<vector<int>> f(n, vector<int>(m + 1));//f[i][x], 0<i<=n,0<=x<=m��
	vector<vector<int>> F(n, vector<int>(m + 1));//F[i][x]����xԪǮͶ�뵽ǰi����Ŀ����������

	for (i = 0; i < n; ++i) {
		f[i][0] = 0;//�ڵ�(i+1)����Ŀ��Ͷ��0Ԫ������Ϊ0��ע��i��0��ʼ
	}
	for (i = 0; i < n; ++i) {
		for (j = 1; j < m + 1; ++j) {//j��1��ʼ��Ҳ���Ǵ�f[0][1]��ʼ
			cin >> f[i][j];
		}
	}
	//��F[0][0-m]��ֵ
	for (j = 0; j < m + 1; ++j) {
		F[0][j] = f[0][j];//��һ����Ŀ��Ͷ��0-mԪǮ������������f[0][0-m]
	}
	for (i = 1; i < n; ++i) {//��Ŀѭ������1��ʼ,Ҳ���Ǵ�ǰ2����Ŀ��ʼ�㣬��Ϊ��һ����Ŀ�Ѿ���ֵ
		for (j = 0; j < m + 1; ++j) {//Ǯ��ѭ�� ��0��ʼ
			for (tmp_m = 0; tmp_m <= j; ++tmp_m) {
				tmp_F = F[i - 1][j - tmp_m] + f[i][tmp_m];
				if (tmp_F > F[i][j])
					F[i][j] = tmp_F;
			}
		}
	}
	cout << F[n - 1][m] << endl;
}

	 