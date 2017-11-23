//correct
#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(int l, int r) {
	return l > r;
}

int main() {

	int n, d, r;
	while(cin >> n >> d >> r && n && d && r) {
		int a[n], b[n];

		for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
		sort(a, a + n);
		sort(b, b + n, cmp);

		int sum = 0;
		for(int i = 0; i < n; i++) {
		  sum += ((a[i] + b[i] - d) >= 0 ? (a[i] + b[i] - d) : 0) * r;
		}

		cout << sum << endl;
	}
	return 0;
}