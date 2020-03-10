#include<iostream>
using namespace std;

int sequential_search(int arr[], int len, int key) {
	for (int i = 0; i < len; i++) {
		if (arr[i] == key)
			return i;
	}
	return -1;
}

int main() {
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int a;
	cin >> a;
	int j = sequential_search(arr, sizeof(arr), a);
	if (j == -1)
		cout << "j=0" << endl;
	else
		cout << "j=" << j << endl;
	return 0;
}
