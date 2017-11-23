//correct
#include <iostream>
#include <algorithm>

using namespace std;

typedef struct {
	int b, j;
} p;

int main() {
	int n, cnt = 0;

	while(cin >> n && n) {
		p people[n];
		for(int i = 0; i < n; i++) cin >> people[i].b >> people[i].j;

		sort(people, people + n, [] (p l, p r) { return l.j > r.j; });
    
		int briefback = 0, maximum = -1;
    for(auto i : people) {
      briefback += i.b;
      maximum = max(maximum, briefback + i.j);
    }
    cout << "Case " << ++cnt << ": "<< maximum << endl;
	}	
	return 0;
}