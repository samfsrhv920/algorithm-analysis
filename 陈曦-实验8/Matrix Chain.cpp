#include<iostream>
using namespace std;
const int N = 100;
int p[N + 1], m[N][N], s[N][N];
int n;

void matrixChain() {
	for (int i = 1; i <= n; i++)
		m[i][i] = 0;
    for (int r = 2; r <=n; r++) {
		for (int i = 1; i <=n - r + 1;i++) {
			int j = i + r - 1;
			m[i][j] = m[i + 1][j] + p[i - 1] * p[i] * p[j];
			s[i][j] = i;
			for (int k = i + 1; k <= j-1; k++) {
				int t = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				if (t < m[i][j]) {
					m[i][j] = t;
					s[i][j] = k;
				}
				 
			}
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i <= n; i++)
		cin >> p[i];
	matrixChain();
	cout << m[1][n] << endl;
	cout << s[1][n] << endl;
	return 0;
}