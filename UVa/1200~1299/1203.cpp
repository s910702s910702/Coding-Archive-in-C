#include <iostream>
#include <queue>

using namespace std;

typedef struct {
	int id;
	int time;
} node;
bool operator < (node l, node r) { 
  if(l.time == r.time) return l.id > r.id;
  return l.time > r.time;
}


int main() {
	string str;
	int order = 0;
	priority_queue<node> pq;
	
	while(cin >> str && str[0] != '#') {
		int a, b;
		cin >> a >> b;

		for(int i = 1; i <= 10000; i++) {
			pq.push((node){a, b * i});
		}
		
		order++;
	} 
	int c;
	cin >> c;

	for(int i = 0; i < c; i++) {
		cout << pq.top().id << endl;
		pq.pop();
	}

	return 0;
}