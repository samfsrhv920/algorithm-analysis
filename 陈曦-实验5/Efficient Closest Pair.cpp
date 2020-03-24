#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

struct Point
{
	double x;
	double y;
};

Point S[100000]; 

bool cmpX(Point a, Point b)
{
	return a.x > b.x;
}

bool cmpY(Point a, Point b)
{
	return a.y > b.y;
}

double ECP(Point *P, Point *Q, int l, int n)
{
	if (n <= 3)
	{
		double result;
		result = (P[l].x - P[l + 1].x)*(P[l].x - P[l + 1].x) + (P[l].y - P[l + 1].y) * (P[l].y - P[l + 1].y);
		if (n == 3)
		{
			double tmp = (P[l].x - P[l + 2].x)*(P[l].x - P[l + 2].x) + (P[l].y - P[l + 2].y) * (P[l].y - P[l + 2].y);
			if (tmp < result)
				result = tmp;
			tmp = (P[l + 1].x - P[l + 2].x)*(P[l + 1].x - P[l + 2].x) + (P[l + 1].y - P[l + 2].y) * (P[l + 1].y - P[l + 2].y);
			if (tmp < result)
				result = tmp;
		}
		return result;
	}
	else
	{
		int mid = n / 2;
		double dl = ECP(P, Q, l, mid);
		double dr = ECP(P, Q, l + mid, n - mid);
		double d = dl < dr ? dl : dr;
		double m = P[l + mid - 1].x;
		int num = 0;
		double tmp;
		for (int i = l; i < l + n; i++)
		{
			tmp = Q[i].x - m;
			if (tmp < 0)
				tmp = -tmp;
			if (tmp < d)
				num++;
		}
		double dminsq = d;
		if (num > 1)
		{
			for (int i = l, j = 0; i < l + n; i++)
			{
				tmp = Q[i].x - m;
				if (tmp < 0)
					tmp = -tmp;
				if (tmp < d)
				{
					S[j].x = Q[i].x;
					S[j].y = Q[i].y;
					j++;
				}
			}
			int k;
			for (int i = 0; i < num - 1; i++)
			{
				k = i + 1;
				while (k < num && (S[k].y - S[i].y)*(S[k].y - S[i].y) < dminsq)
				{
					dminsq = min((S[k].x - S[i].x)*(S[k].x - S[i].x) + (S[k].y - S[i].y)*(S[k].y - S[i].y), dminsq);
					k++;
				}
			}
		}
        return sqrt(dminsq);
	}
}

int main()
{
	int n;
	Point *P, *Q;
	P = new Point[100000];
	Q = new Point[100000];
	while (cin>>n)
	{
		if (n == 0)
			break;
		for (int i = 0; i < n; i++)
		{
			cin >> P[i].x >> P[i].y;
			Q[i].x = P[i].x;
			Q[i].y = P[i].y;
		}
		if (n <= 3)
		{
			cout << ECP(P, Q, 0, n)/ 2 << endl;
		}
		else
		{
			sort(P, P + n, cmpX); 
			sort(Q, Q + n, cmpY);
			cout << ECP(P, Q, 0, n) / 2 << endl;
		}
	}
	return 0;
}

 