#include<iostream>
using namespace std;

int binary_search(int arr[], int len, int key)
{
	int l = 0;
	int r = len;
	int m = 0;
	while (l <= r) {
		m = l + (r - l) / 2;
		if (key < arr[m]) {
			r = m - 1;
		}
		else if (key > arr[m]) {
			l = m + 1;
		}
		else {
			return m;
		}
	}
	return -1;
}

int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int len = size(arr);
	int a;
	cin >> a;
	int j = binary_search(arr, len - 1, a);
	if (j >= 0) {
		cout << "j=" << j << endl;
	}
	else {
		cout << "j=0" << endl;
	}

	return 0;
}