#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

#define n 8           
#define m 2*n-1       
typedef struct {        
	double w;     
	int p, l, r; 
}HTNode;
typedef HTNode HuffmanTree[m]; 

typedef struct {        
	int id;            
	double w;    
}temp;

typedef struct {      
	char ch;           
	char bits[n + 1];    
}CodeNode;
typedef CodeNode HuffmanCode[n];

void InitHuffmanTree(HuffmanTree T) {
	 for (int i = 0; i < m; i++) {
		T[i].l = -1;
		T[i].r = -1;
		T[i].p = -1;
		T[i].w = 0;
	}
}

void InputWeight(HuffmanTree T) {
	for (int i = 0; i < n; i++) {
		double x;
		scanf("%lf", &x);
		T[i].w = x;
	}
}

bool cmp(temp a, temp b) {
	 return a.w < b.w;
}

void SelectMin(HuffmanTree T, int k, int *p1, int *p2) {
	temp x[m];               
	int i, j;
	for (i = 0, j = 0; i <= k; i++) {  
		if (T[i].p == -1) { 
			x[j].id = i;       
			x[j].w = T[i].w; 
			j++;            
		}
	}
	sort(x, x + j, cmp);         
	*p1 = x[0].id;
	*p2 = x[1].id;
}

void CreateHuffmanTree(HuffmanTree T) {
	int i, p1, p2;
	InitHuffmanTree(T);    
	InputWeight(T);        
	for (i = n; i < m; i++) {
		SelectMin(T, i - 1, &p1, &p2); 
		T[p1].p = T[p2].p = i; 
		T[i].l = p1;             
		T[i].r = p2;              
		T[i].w = T[p1].w + T[p2].w; 
	}
}

void CharSetHuffmanEncoding(HuffmanTree T, HuffmanCode H) {
	int c, p;
	char cd[n + 1];
	int start;
	cd[n] = '\0';
	getchar();
	for (int i = 0; i < n; i++) {
		H[i].ch = getchar();
		start = n;
		c = i;
		while ((p = T[c].p) >= 0) {
			if (T[p].l == c)
				cd[--start] = '0';
			else
				cd[--start] = '1';
			c = p;
		}
		strcpy(H[i].bits, &cd[start]);
	}
}

int main() {
	HuffmanTree T;
	HuffmanCode H;
	printf("%d\n", n);
	CreateHuffmanTree(T);
	printf("%d\n", n);
	CharSetHuffmanEncoding(T, H);
	cout << endl;
	cout << endl;
	for (int i = 0; i < m; i++) {
		cout << i << " "<<T[i].w<<" "<< T[i].p<<" "<< T[i].l <<" "<< T[i].r<< endl;
	}
	cout << endl;
	double wpl = 0.0;
	for (int i = 0; i < n; i++) {
		cout << i <<" "<< H[i].ch <<" "<< H[i].bits << endl;
		wpl += strlen(H[i].bits)*T[i].w;
	}
	cout << wpl << endl;
	return 0;
}
 

 