#include <iostream>
#include <vector>
#include <algorithm>

uisng namespace std;

int main() {
	int kase;
	cin >> kase;
	int cnt = 1;

	while(kase--) {
		cout << "Case " << cnt++ << ": ";
		vector<int> v(3);
		for(int i = 0; i < 3; i++) cin >> v[i];

		sort(v.begin(), v.end());

		cout << v[1] << endl;
	}


	return 0;
}