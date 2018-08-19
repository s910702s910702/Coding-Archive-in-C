#include <iostream>
#include <cstring>

using namespace std;

int main() {
	int kase;
	cin >> kase;

	while(kase--) {
		int n;
		cin >> n;

		int arr[2 * n + 1][2 * n + 1];
		memset(arr, 0, sizeof(arr));

		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				cin >> arr[i][j];

				arr[i + n][j] = arr[i][j];
				arr[i][j + n] = arr[i][j];
				arr[i + n][j + n] = arr[i][j];
			}
		}

		int sum[2 * n + 1][2 * n + 1];
		memset(sum, 0, sizeof(sum));

		for(int i = 1; i <= 2 * n; i++) sum[1][i] = sum[1][i - 1] + arr[1][i];
		for(int i = 2; i <= 2 * n; i++) sum[i][1] = sum[i - 1][1] + arr[i][1];

		for(int i = 2; i <= 2 * n; i++) {
			for(int j = 2; j <= 2 * n; j++) {
				sum[i][j] = arr[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
			}
		}

		int max = -1e9;
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				for(int k = 0; k < n; k++) {
					for(int l = 0; l < n; l++) {
						int s = sum[i + k][j + l] - sum[i - 1][j + l] - sum[i + k][j - 1] + sum[i - 1][j - 1];
						if(s > max) max = s;
					}
				}
			}
		}
		cout << max << endl;
	}

	return 0;
}