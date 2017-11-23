#include <iostream>

using namespace std;

int main() {
	int kase;
	cin >> kase;

	while(kase--) {
		int n;
		cin >> n;

		int a[n];
		for(int i = 0; i < n; i++) cin >> a[i];


		int left_large[n];
		int right_large[n];
		int left_less[n];
		int right_less[n];

		for(int i = 0; i < n; i++) {
			int great = 0;
			
			for(int j = 0; j < i; j++) if(a[j] > a[i]) great++;
			left_large[i] = great;
			left_less[i] = i - great;

			great = 0;

			for(int j = n - 1; j > i; j--) if(a[j] > a[i]) great++;
			right_large[i] = great;
			right_less[i] = (n - i - 1) - great;
		}
    
		long long int sum = 0;

		for(int i = 0; i < n; i++) sum += (left_less[i] * right_large[i] + left_large[i] * right_less[i]);

		cout << sum << endl;

	}
	return 0;
}