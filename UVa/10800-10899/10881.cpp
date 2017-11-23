//correct
#include <iostream>
#include <algorithm>

using namespace std;

typedef struct {
	int id;
	int position;
	int dir;
} ant;

string sdir[3] = {"L", "Turning", "R"};

int main() {
	int kase, cnt = 0;
	bool flag = true;
	
	cin >> kase;
	while(kase--) {
		int l, t, n;
		cin >> l >> t >> n;
		
		ant a[n];
		for(int i = 0; i < n; i++) {
			a[i].id = i;
			cin >> a[i].position;
			char tmp;
			cin >> tmp;
			a[i].dir = (tmp == 'R' ? 1 : -1);
		}
		
		sort(a, a + n, [](ant l, ant r) { return l.position < r.position; });
		
		int order[n];
		for(int i = 0; i < n; i++) {
			order[i] = a[i].id;
			a[i].position += a[i].dir * t;
		}

		sort(a, a + n, [](ant l, ant r) { return l.position < r.position; });
		
		for(int i = 0; i < n; i++) {
			a[i].id = order[i];
			if(a[i].position == a[i + 1].position) a[i].dir = a[i + 1].dir = 0;
		}
		
		sort(a, a + n, [](ant l, ant r) { return l.id < r.id; });
		
		if(flag) flag = false;
		else cout << endl;
		
		cout << "Case #" << ++cnt << ":" << endl;
		for(auto i : a) {
			if(i.position >= 0 && i.position <= l) cout << i.position << " " << sdir[i.dir + 1] << endl;
			else cout << "Fell off"	<< endl;			
		}
	}
	cout << endl;
	return 0;
}