#include <iostream>
#include <vector>
#include <cstring>


using namespace std;

int main() {
	int n;

	while(cin >> n) {
		bool diff[n + 1];
		int last;
		bool judge = true;

		memset(diff, false, sizeof(diff));

		for(int i = 0; i < n; i++) {
			int x;
			cin >> x;

			if(i > 0) {
				int tmp = abs(last - x);
				if(tmp >= n || diff[tmp]) judge = false;
				diff[tmp] = true;
			}
			last = x;
		}

		if(judge) cout << "Jolly" << endl;
		else cout << "Not jolly" << endl;
	}

	return 0;
}