#include <iostream>
#include <cstring>

#define SIZE 51

using namespace std;

long long int dp[SIZE][SIZE][SIZE];

void predo() {
	memset(dp, 0, sizeof(dp));

	for(int i = 0; i < SIZE; i++) dp[0][0][i] = 1;

	for(int n = 1; n < SIZE; n++) {
		for(int k = 1; k < SIZE; k++) {
			for(int m = 1; m < SIZE; m++) {
				for(int i = 1; i <= m; i++) {
					if(n - i < 0) break;
					dp[n][k][m] += dp[n - i][k - 1][m];
				}
			}
		}
	}
}


int main() {
	predo();

	int n, k, m;

	while(cin >> n >> k >> m) cout << dp[n][k][m] << endl;

	return 0;
}