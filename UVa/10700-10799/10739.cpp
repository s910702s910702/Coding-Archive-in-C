#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int kase, count = 0;
	cin >> kase;
	
	while(kase--) {
		string str;
		cin >> str;
		
		int n = str.length();
		int dp[n][n];
		
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				dp[i][j] = 0;
				
		for(int i = 1; i < n; i++) {
			for(int j = 0; j < n; j++) {
				if(j + i < n && str[j] == str[j + i]) dp[j][j + i] = dp[j + 1][j + i - 1];
				else if(j + i < n && str[j] != str[j + i])dp[j][j + i] = min(min(dp[j][j + i - 1], dp[j + 1][j + i - 1]), dp[j + 1][j + i]) + 1;
			}
		}
		
		cout << "Case " << ++count << ": " << dp[0][n - 1] << endl;
	}
	return 0;
}
