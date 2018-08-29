// Same problem like LA6258
#include <iostream>
#include <map>

#define SIZE 200005
using namespace std;

long long int a[SIZE];
int l[SIZE], r[SIZE];
int n;

bool test(int ll, int rr) {
	if(ll >= rr) return true;

	for(int ul = ll, ur = rr; ul <= ur; ul++, ur--) {
		if(l[ul] < ll && r[ul] > rr) return test(ll, ul - 1) && test(ul + 1, rr);
		if(l[ur] < ll && r[ur] > rr) return test(ll, ur - 1) && test(ur + 1, rr);
	}

	return false;
}

int main() {
	ios::sync_with_stdio(false);
	int kase;
	cin >> kase;

	while(kase--) {
		cin >> n;

		map<long long int, int> m;
		for(int i = 0; i < n; i++) {
			cin >> a[i];

			if(m.count(a[i]) == 0) l[i] = -1;
			else l[i] = m[a[i]];
			m[a[i]] = i;
		}

		m.clear();

		for(int i = n - 1; i >= 0; i--) {
			if(m.count(a[i]) == 0) r[i] = n;
			else r[i] = m[a[i]];

			m[a[i]] = i;
		}

		if(test(0, n - 1)) cout << "non-boring" << "\n";
		else cout << "boring" << "\n";
	}

	return 0;
}
