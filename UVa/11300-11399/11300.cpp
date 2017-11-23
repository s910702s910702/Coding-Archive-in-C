//correct
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n;
	while(cin >> n) {
		long long int a[n];
		long long int c[n + 1];
		long long int avg = 0;
		
		for(int i = 0; i < n; i++) {
			cin >> a[i];
			avg += a[i];
		}
		avg /= n;
		
		c[0] = 0;
		for(int i = 1; i < n; i++) c[i] = c[i - 1] - (a[i - 1] - avg);
		
		sort(c, c + n);
		int med = c[n  / 2];
		
		long long int sum = 0;
		for(int i = 0; i < n; i++) sum += abs(med - c[i]);
		
		cout << sum << endl;
	}
	return 0;
}