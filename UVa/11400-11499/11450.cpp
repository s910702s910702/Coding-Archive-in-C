#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(int l, int r) { return l > r; }

int main() {
	int kase;
	cin >> kase;

	while(kase--) {
		int m, c;
		cin >> m >> c;

		vector<int> v[c];
		for(int i = 0; i < c; i++) {
			int n;
			cin >> n;

			for(int j = 0; j < n; j++) {
				int tmp;
				cin >> tmp;

				v[i].push_back(tmp);
			}

			sort(v[i].begin(), v[i].end(), cmp);
		}

		bool dp[m + 10][c];
		memset(dp, false, sizeof(dp));

		for(auto i : v[0]) if(i <= m) dp[i][0] = true;
		for(int i = 1; i < c; i++)
			for(auto j : v[i])
				for(int M = m; M >= 0; M--)
					if(dp[M][i - 1] && M + j <= m) dp[M + j][i] = true;

		bool flag = false;
		for(int i = m; i >= 0; i--) {
			if(dp[i][c - 1]) {
				cout << i << endl;
				flag = true;
				break;
			}
		}
		if(!flag) cout << "no solution" << endl;
	}

	return 0;
}