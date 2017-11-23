//correct
#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

int main() {
	int n, m;
	int cnt = 0;
	while(cin >> n >> m && n && m) {
	 // cout << n << " " << m << endl;
		if(n > m) {
		  cout << "Loowater is doomed!" << endl;
		  for(int i = 0; i < n; i++) {
		    int tmp;
		    cin >> tmp;
		  }
		  for(int i = 0; i < m; i++) {
		    int tmp;
		    cin >> tmp;
		  }
		  
		}
		else {

			deque<int> a, b;
			for(int i = 0; i < n; i++) {
				int tmp;
				cin >> tmp;
				a.push_back(tmp);
			}
			sort(a.begin(), a.end());

			for(int i = 0; i < m; i++) {
				int tmp;
				cin >> tmp;
				b.push_back(tmp);
			}
			sort(b.begin(), b.end());

			int sum = 0;

			while(!a.empty() && !b.empty()) {
				if(b.front() >= a.front()) {
					sum += b.front();
					a.pop_front();
					b.pop_front();
				}
				else b.pop_front();
			}

			if(!a.empty()) cout << "Loowater is doomed!" << endl;
			else cout << sum << endl;
		}
	}
	return 0;
}