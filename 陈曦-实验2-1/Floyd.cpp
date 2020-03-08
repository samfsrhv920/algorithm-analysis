#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;
void InputGraph(vector<vector<int>> &graph)  //输入权值，否则为无穷大
{
	int count = 0;
	cin >> count;
	int size = graph.size();
	for (int i = 0; i < size; i++)
	{
		graph[i][i] = 0;
	}
	for (int i = 0; i < count; i++)
	{
		int start = -1, end = -1, weight = 0;
		cin >> start >> end >> weight;
		graph[start][end] = weight;
	}
}
void Floyd(vector<vector<int>> &graph)  //使用Floyd算法求最短路径长度
{
	int size = graph.size();
	for (int k = 0; k < size; k++)
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (graph[i][j] > graph[i][k] + graph[k][j])
				{
					graph[i][j] = graph[i][k] + graph[k][j];
				}
			}
		}
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << setw(6) << graph[i][j] << "  ";
		}
		cout << endl;
	}
}
int main()
{
	vector<vector<int>> graph = vector<vector<int>>(5, vector<int>(5, 999));
	InputGraph(graph);
	Floyd(graph);
	system("pause");
	return 0;
}


 

 