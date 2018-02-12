#include <iostream>
#include <queue>

using namespace std;

typedef struct {
	int x;
} new_int;
bool operator < (new_int l, new_int r) { return l.x > r.x; }

int main() {
	int n;
	while(cin >> n && n) {
		priority_queue<new_int> pq;
		
		for(int i = 0; i < n; i++) {
			new_int tmp;
			cin >> tmp.x;
			
			pq.push(tmp);
		}
		
		int cost = 0;
		while(pq.size() > 1) {
			int a = pq.top().x;
			pq.pop();
			
			a += pq.top().x;
			pq.pop();
			
			cost += a;
			
			pq.push((new_int){a});
		}
		cout << cost << endl;
	}
	return 0;
} 
