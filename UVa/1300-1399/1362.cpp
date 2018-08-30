#include <iostream>
#include <cstring>

#define SIZE 301
#define MOD 1000000000

using namespace std;

long long dp[SIZE][SIZE];

void init() {
	memset(dp, 0, sizeof(dp));
	for(int i = 0; i < SIZE; i++) dp[i][i] = 1;
}

int main() {
	string str;

	while(cin >> str) {
		init();
		int n = str.length();

		for(int d = 1; d < n; d++) {
			for(int i = 0; i + d < n; i++) {
				int j = i + d;

				if(str[i] == str[j]) {
					for(int k = i + 1; k <= j; k++) {
						if(str[i] == str[k]) {
							dp[i][j] += (dp[i + 1][k - 1] * dp[k][j]) % MOD;
							dp[i][j] %= MOD;
						}
					}
				}
			}
		}

		cout << dp[0][n - 1] << endl;
	}

	return 0;
}