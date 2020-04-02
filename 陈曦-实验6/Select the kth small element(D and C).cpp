#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
#define MAX 100

int comp(const void *a, const void *b)
{
	int *aa = (int *)a;
	int *bb = (int *)b;
	return *aa - *bb;
}

int Select(int *a, int len, int k)
{
	int cnt = len / 5;
	int m[MAX], num = 0;
	int s1[MAX], s2[MAX];
	int num_s1 = 0, num_s2 = 0;

	if (len <= 5)
	{   
		qsort(a, len, sizeof(int), comp);
		return a[k - 1];
	}
	for (int i = 0; i < cnt; i++)
	{
		 
		qsort(a + 5 * i, 5, sizeof(int), comp);
		m[num++] = a[5 * i + 2];
	}

	int m_s = Select(m, num, num / 2 + 1);  

	for (int i = 0; i < cnt; i++)
	{
		if (a[5 * i + 2] < m_s)
		{
			s1[num_s1++] = a[5 * i];
			s1[num_s1++] = a[5 * i + 1];
			s1[num_s1++] = a[5 * i + 2];

			if (a[5 * i + 3] < m_s)
				s1[num_s1++] = a[5 * i + 3];
			else
				s2[num_s2++] = a[5 * i + 3];

			if (a[5 * i + 4] < m_s)
				s1[num_s1++] = a[5 * i + 4];
			else
				s2[num_s2++] = a[5 * i + 4];
		}
		else if (a[5 * i + 2] == m_s)
		{
			s1[num_s1++] = a[5 * i];
			s1[num_s1++] = a[5 * i + 1];
			s2[num_s2++] = a[5 * i + 3];
			s2[num_s2++] = a[5 * i + 4];
		}
		else
		{
			s2[num_s2++] = a[5 * i + 3];
			s2[num_s2++] = a[5 * i + 4];
			s2[num_s2++] = a[5 * i + 2];

			if (a[5 * i] < m_s)
				s1[num_s1++] = a[5 * i];
			else
				s2[num_s2++] = a[5 * i];

			if (a[5 * i + 1] < m_s)
				s1[num_s1++] = a[5 * i + 1];
			else
				s2[num_s2++] = a[5 * i + 1];
		}
	}

	for (int i = 5 * cnt; i < len; i++)
	{
		if (a[i] < m_s)
			s1[num_s1++] = a[i];
		else
			s2[num_s2++] = a[i];
	}

	if (k == num_s1 + 1)
		return m_s;
	else if (k <= num_s1)
		return Select(s1, num_s1, k);
	else
		return Select(s2, num_s2, k - num_s1 - 1);
}

int main()
{
	int a[] = { 86,63,20,51,17,24,16,90,49,65 };
	cout<<Select(a, sizeof(a) / sizeof(int), 2);
}
 

 