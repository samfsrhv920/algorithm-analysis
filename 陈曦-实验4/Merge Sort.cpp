#include<iostream>
using namespace std;
#define MAX 1000
int a[MAX], temp[MAX];
void merge_sort(int l, int r)
{
	if (l == r) 
		return;							 
	int mid = (l + r) / 2;
	merge_sort(l, mid);
	merge_sort(mid + 1, r);
	int p = l, i = l, j = mid + 1;
	while (i <= mid && j <= r) {
		if (a[i] > a[j]) 
			temp[p++] = a[j++]; 
		else 
			temp[p++] = a[i++];					 
	}
	while (i <= mid) 
		temp[p++] = a[i++];			 
	while (j <= r) 
		temp[p++] = a[j++];
	for (int i = l; i <= r; i++)
		a[i] = temp[i];							 
}
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	merge_sort(1, n);
	for (int i = 1; i <= n; i++)
		cout << a[i] << " ";						 
	return 0;
}

 
 
 