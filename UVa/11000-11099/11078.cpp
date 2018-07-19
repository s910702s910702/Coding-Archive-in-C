#include <iostream>

using namespace std;

int main() {
	int kase;
	cin >> kase;

	while(kase--) {
		int n;
		cin >> n;
		int max = -1e9;
		int maxdif = -1e9;

		for(int i = 0; i < n; i++) {
			int tmp;
			cin >> tmp;
			if(maxdif < (max - tmp) ) maxdif = (max - tmp);
			if(max < tmp) max = tmp;
		}
		
		cout << maxdif << endl;
	}

	return 0;
}