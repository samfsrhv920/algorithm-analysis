#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
#define m 1000000000
int E, V;
int sum = 0;
struct node {
	int v, u;
	int e;
}A[100];
node ans[100];
int vis[100];
bool cmp(node a, node b) {
	return a.e < b.e;
}
int Find(int a) {
	if (vis[a] == a)   return a;
	else            return Find(vis[a]);
}
void Union(int a, int b) {
	vis[Find(a)] = Find(b);
}
void init() {
	for (int i = 0; i < 100; i++)  vis[i] = i;
	cin >> V;
	cin >> E;
}//初始化A数组 读入点的个数和边的个数
void input(int n) {
	while (n--)
		cin >> A[n + 1].v >> A[n + 1].u >> A[n + 1].e;

}//读入所有数据
void cal(int n, int cnt) {
	if (n > E)  return;
	if (Find(A[n].v) == Find(A[n].u))
		cal(++n, cnt);
	else {
		ans[cnt].u = A[n].u;
		ans[cnt].v = A[n].v;
		ans[cnt].e = A[n].e;
		Union(A[n].v, A[n].u);
		sum += A[n].e;
		cal(++n, ++cnt);
	}
}
void output() {
	for (int i = 1; i < V; i++) {
		cout << "V" << ans[i].u << "-V" << ans[i].v << "=" << ans[i].e << endl;
	}
	cout << "最小权值之和=" << sum << endl;
}

int main() {
	memset(A, 0, sizeof(A));
	init();
	input(E);
	sort(A + 1, A + E + 1, cmp);
	cal(1, 1);
	output();
	return 0;
}