#include<iostream>
using namespace std;

class Color 
{
	friend int mColoring(int, int, int**);
private:
	bool ok(int k);
	void backtrack(int t);
	int n, m, **a, *x, sum;
};

bool Color::ok(int k) 
{
	for (int j = 1; j < k; j++) 
	{
		if ((a[k][j] == 1) && (x[j] == x[k]))
			return false;
	}
	return true;
}

void Color::backtrack(int t) 
{
	if (t > n) 
	{
		sum++;
		for (int i = 1; i <= n; i++) 
		{
			cout << x[i] << " ";
		}
		cout << endl;
	}
	else {
		for (int i = 1; i <= m; i++) 
		{
			x[t] = i;
			if (ok(t)) 
			{
				backtrack(t + 1);
			}
			x[t] = 0;
		}
	}
}

int mColoring(int n, int m, int **a) 
{
	Color C;
	C.n = n;
	C.m = m;
	C.a = a;
	C.sum = 0;
	int *x = new int[n + 1];
	for (int i = 0; i <= n; i++)
	{
		x[i] = 0;
	}
	C.x = x;
	C.backtrack(1);
	delete[]x;
	return C.sum;
}

int main()
{
	int e, m, n, u, v;
	int **a = new int *[100];
	for (int k = 0; k < 100; k++)
	{
		a[k] = new int[100];
	}
	while (1)
	{
		cin >> n >> e >> m;
		for (int i = 0; i < e; i++)
		{
			cin >> u >> v;
			a[u][v] = 1;
			a[v][u] = 1;
		}
		int sum = mColoring(n, m, a);
		cout << sum << endl;
	}
}
