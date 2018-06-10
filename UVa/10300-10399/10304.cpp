#include <iostream>
#include <cstring>

using namespace std;

int main() {
	
	int n;
	
	while(cin >> n) {
		int a[n];
		for(int i = 0; i < n; i++) cin >> a[i];

		int w[n + 2][n + 2];
		memset(w, 0, sizeof(w));

		int e[n + 2][n + 2];
		memset(e, 0, sizeof(w));

		for(int i = 1; i <= n; i++)
			for(int j = i - 1; j <= n; j++)
				if(j == i - 1) w[i][j] = 0;
				else w[i][j] = w[i][j - 1] + a[j - 1];

		for(int a = 0; a < n; a++) {
			for(int i = 1; i <= n; i++) {

				int j = i + a;
				if(j > n) break;

				int mincost = 1e9;
				for(int r = i; r <= j; r++) mincost = min(mincost, e[i][r - 1] + e[r + 1][j] + w[i][r - 1] + w[r + 1][j	]);
				
				e[i][j] = mincost;
			}
		}
		cout << e[1][n] << endl;

	}
	return 0;
}
