#include <iostream>
#include <set>

using namespace std;

typedef pair<int, int> pi;

int main() {
	
	int kase;
	cin >> kase;
	while(kase--) {
		set<pi> s;
		int n;
		cin >> n;

		int left = 1e9, right = -1e9;

		for(int i = 0; i < n; i++) {
			pi tmp;
			cin >> tmp.first >> tmp.second;
			if(tmp.first < left) left = tmp.first;
			if(tmp.first > right) right = tmp.first;

			s.insert(tmp);
		}

		int mid = left + right;
		bool flag = true;

		for(auto ab : s) {
			if(s.count(pi(mid - ab.first, ab.second)) == 0) {
				flag = false;
				break;
			} 
		}

		if(flag) cout << "YES" << endl;
		else cout << "NO" << endl;

	}
	return 0;
}