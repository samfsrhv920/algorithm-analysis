#include<iostream>
using namespace std;

template<class Type>
void GreedySelector(int n, Type s[], Type f[], bool A[]);
const int N = 10;

int main() {
	int s[]= { 0,1,3,2,5,4,5,6,8,8,2};
	int f[]= { 0,4,5,6,7,9,9,10,11,12,13};
	bool A[N + 1];
	for (int i=1; i <= N; i++) {
		cout << "[" << i << "]:" << "(" << s[i] << "," << f[i] << ")" << endl;
    }
	GreedySelector(N, s, f, A);
	for (int i = 1; i <= N; i++) {
		if (A[i]) {
			cout << "[" << i << "]:"<<"(" << s[i] << "," << f[i] << ")" << endl;
		}
	}
	return 0;
}

template<class Type>
void GreedySelector(int n, Type s[], Type f[], bool A[]) {
	A[1] = 1;
	int j = 1;
	for (int i = 2; i <= n; i++) {
		if (s[i] >= f[j]) {
			A[i] = 1;
			j = i;
		}
		else {
			A[i] = 0;
		}
	}
}