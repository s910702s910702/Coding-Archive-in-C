#include <iostream>
#include <vector>
#include <cstring>

#define MAX 1e9
#define SIZE 12

using namespace std;

vector<int> p;
int M[SIZE][SIZE];
int c[SIZE][SIZE];
int n;

void init() {
	p.clear();

	for(int i = 0; i < SIZE; i++) 
		for(int j = 0; j < SIZE; j++)
			M[i][j] = MAX;
	memset(c, -1, sizeof(c));
}

void optimalize() {
	for(int i = 0; i <= n; i++) M[i][i] = 0;

	for(int d = 0; d < n; d++) {
		for(int i = 1; i <= n; i++) {
			
			int j = i + d;
			if(j > n) break;

			for(int k = i; k < j; k++) {
				int cur = M[i][k] + M[k + 1][j] + p[i - 1] * p[k] * p[j];
				if(cur <= M[i][j]) {
					M[i][j] = cur;
					c[i][j] = k;
				} 
			}
		}
	}
}

void printer(int l, int r) {
	
	if(l == r) cout << "A" << l;
	else {
		int cut = c[l][r];
		cout << "(";
		printer(l, cut);
		cout << " x ";
		printer(cut + 1, r);
		cout << ")";
	}

}

int main() {
	int cnt = 1;

	while(cin >> n && n) {
		init();

		for(int i = 0; i < n; i++) {
			int a, b;
			cin >> a >> b;

			if(i == 0) p.push_back(a);
			p.push_back(b);
		}
		
		optimalize();
		cout << "Case " << cnt++ << ": ";
		printer(1, n);
		cout << endl;
	}

	return 0;
}