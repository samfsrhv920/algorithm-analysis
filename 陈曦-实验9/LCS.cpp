#include<iostream>
#include<string>
#define NUM 20
using namespace std;
int c[NUM][NUM];
char b[NUM][NUM];
void LCS_LENGTH(string X, string Y) {
	int m = X.length();
	int n = Y.length();
	for (int i = 1; i <= m; i++)
		c[i][0] = 0;
	for (int j = 0; j <= n; j++)
		c[0][j] = 0;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (X[i - 1] == Y[j - 1]) {
				c[i][j] = c[i - 1][j - 1] + 1;
				b[i][j] = 'a';
			}
			else if (c[i - 1][j] >= c[i][j - 1]) {
				c[i][j] = c[i - 1][j];
				b[i][j] = 'b';
			}
			else {
				c[i][j] = c[i][j - 1];
				b[i][j] = 'c';
			}
		}
	}
}

void PRINT_LCS(string B, int i, int j)
{
	if (i == 0 || j == 0)
		return;
	if (b[i][j] == 'a') {
		PRINT_LCS(B, i - 1, j - 1);
		cout << B[i - 1];
	}
	else if (b[i][j] == 'b') {
		PRINT_LCS(B, i - 1, j);
	}
	else
		PRINT_LCS(B, i, j - 1);
}
int main()
{
	string X, Y;
	cin >> X >> Y;
	LCS_LENGTH(X, Y);
	PRINT_LCS(X, X.length(), Y.length());
}
