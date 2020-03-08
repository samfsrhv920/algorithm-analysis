#include <iostream>
using namespace std;
int main()
{
	int e[10][10], dis[10], book[10], i, j, n, m, start, end, weight, u, v, min;
	int inf = 99999999; //��inf(infinity����д)�洢������ֵ
	//����n��m��n��ʾ���������m��ʾ�ߵ�����
	cin >> n >> m;
    //��ʼ��
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			if (i == j) e[i][j] = 0;
			else e[i][j] = inf;
    //�����
	for (i = 1; i <= m; i++)
	{
		cin >> start >> end >> weight;
		e[start][end] = weight;
	}
	//��ʼ��dis���飬������1�Ŷ��㵽�����������ĳ�ʼ·��
	for (i = 1; i <= n; i++)
		dis[i] = e[1][i];
	//book�����ʼ��
	for (i = 1; i <= n; i++)
		book[i] = 0;
	book[1] = 1;
    //Dijkstra�㷨�������
	for (i = 1; i <= n - 1; i++)
	{
		//�ҵ���1�Ŷ�������Ķ���
		min = inf;
		for (j = 1; j <= n; j++)
		{
			if (book[j] == 0 && dis[j] < min)
			{
				min = dis[j];
				u = j;
			}
		}
		book[u] = 1;
		for (v = 1; v <= n; v++)
		{
			if (e[u][v] < inf)
			{
				if (dis[v] > dis[u] + e[u][v])
					dis[v] = dis[u] + e[u][v];
			}
		}
	}
    //������յĽ��
	cout << dis[n];
	getchar();
	getchar();
	return 0;
}

 
 

 
 
 
 

 