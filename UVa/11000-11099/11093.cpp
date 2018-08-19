#include <iostream>
#define SIZE 100005

using namespace std;

int a[SIZE], c[SIZE];

int test(int n) {
	int start = 0, cur = 0, sum = 0;
	bool repeat = false;

	while(1) {
		if(cur == n - 1) repeat = true;
		
		sum += c[cur];
		
		if(sum < 0) {
			if(repeat) return -1;
			cur = start = (cur + 1) % n;
			sum = 0;
		}
		else {
			if((cur + 1) % n == start) return start + 1;
			cur = (cur + 1) % n;
		}
	}
}

int main() {
	int kase, cnt = 1;
	cin >> kase;

	while(kase--) {
		int n;
		cin >> n;

		for(int i = 0; i < n; i++) cin >> a[i];
		for(int i = 0; i < n; i++) {
			int tmp;
			cin >> tmp;
			c[i] = a[i] - tmp;
		}
		
		int ans = test(n);

		cout << "Case " << cnt++ << ": ";
		if(ans == -1) cout << "Not possible" << endl;
		else cout << "Possible from station " << ans << endl;
	}

	return 0;
}