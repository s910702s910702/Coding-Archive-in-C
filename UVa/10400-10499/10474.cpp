#include <iostream>
#include <algorithm>

using namespace std;

int cnt = 1;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, q;
	while(cin >> n >> q && (n | q)) {
		cout << "CASE# " << cnt++ << ":\n";

		int m[n];
		for(int i = 0; i < n; i++) cin >> m[i];

		sort(m, m + n);

		for(int i = 0; i < q; i++) {
			int x;
			cin >> x; 

			int position = lower_bound(m, m + n, x) - m;

			if(m[position] == x) cout << x << " found at " << position + 1 << "\n";
			else cout << x << " not found" << "\n";
		}
	}

	return 0;
}