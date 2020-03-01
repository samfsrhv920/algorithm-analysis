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
		lowcost[u] = graph[1][u];//lowcost存放顶点1可达点的路径长度 
		mst[u] = 1 ;//初始化以1位起始点 
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
				min = lowcost[v];//找出权值最短的路径长度 
				minnum = v; //找出最小的num 
			}
		}
		cout << "V" << mst[minnum] << "-V" << minnum << "=" << min << endl;
		sum += min;//求和 
		lowcost[minnum] = 0;//该处最短路径置为0 
		for (v = 2; v <= n; v++)
		{
			if (graph[minnum][v] < lowcost[v])//对这一点直达的顶点进行路径更新 
			{
				lowcost[v] = graph[minnum][v];
				mst[v] = minnum;
			}
		}
	}
	cout << "最小权值之和=" << sum << endl;
}
int main()
{
	int u, v, k, V, E;
	int w;
    cin >> V >> E;//V=顶点的个数，E=边的个数  

	for (u = 1; u <= V; u++)//初始化图 
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
 