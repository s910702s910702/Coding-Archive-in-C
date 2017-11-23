//correct
#include <iostream>

using namespace std;

int main() {
	int n;
	while(cin >> n && n) {
		int a[n];
		
		for(int i = 0; i < n; i++) cin >> a[i];
		long long int cur = 0;
		long long int sum = 0;

		for(int i = 0; i < n; i++) {
			sum += abs(cur);
			cur += a[i];
		}
		cout << sum << endl;
	}
	return 0;
}