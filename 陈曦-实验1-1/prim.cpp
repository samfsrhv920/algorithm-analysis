#include<iostream>
using namespace std;
#define MAX 100  
#define MAXCOST 0x7fffffff  

int graph[MAX][MAX];

void prim(int graph[][MAX], int n)
{
	int lowcost[MAX];
	int mst[MAX];
	int u, v, min, minnum, sum = 0;
	for (u = 2; u <= n; u++)
	{
		lowcost[u] = graph[1][u];//lowcost��Ŷ���1�ɴ���·������ 
		mst[u] = 1 ;//��ʼ����1λ��ʼ�� 
	}
	mst[1] = 0;
	for (u = 2; u <= n; u++)
	{
		min = MAXCOST;
		minnum = 0;
		for (v = 2; v <= n; v++)
		{
			if (lowcost[v] < min && lowcost[v] != 0)
			{
				min = lowcost[v];//�ҳ�Ȩֵ��̵�·������ 
				minnum = v; //�ҳ���С��num 
			}
		}
		cout << "V" << mst[minnum] << "-V" << minnum << "=" << min << endl;
		sum += min;//��� 
		lowcost[minnum] = 0;//�ô����·����Ϊ0 
		for (v = 2; v <= n; v++)
		{
			if (graph[minnum][v] < lowcost[v])//����һ��ֱ��Ķ������·������ 
			{
				lowcost[v] = graph[minnum][v];
				mst[v] = minnum;
			}
		}
	}
	cout << "��СȨֵ֮��=" << sum << endl;
}
int main()
{
	int u, v, k, V, E;
	int w;
    cin >> V >> E;//V=����ĸ�����E=�ߵĸ���  

	for (u = 1; u <= V; u++)//��ʼ��ͼ 
	{
		for (v = 1; v <= V; v++)
		{
			graph[u][v] = MAXCOST;
		}
	}
	for (k = 1; k <= E; k++)
	{
		cin >> u >> v >> w;
		graph[u][v] = w;
		graph[v][u] = w;
	}

	prim(graph, V);
	return 0;
}
 