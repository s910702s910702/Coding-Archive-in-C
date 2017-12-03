#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define SIZE 20000
#define MAX 1e9

using namespace std;

typedef struct {
	int next;
	int l;
} chain;

vector<chain> map[SIZE];
int dis[SIZE];
int n, m, s, t;

typedef struct {
	int id;
	int d;
} node;

bool operator < (node l, node r) { return l.d > r.d; }

void reset() {
	for(int i = 0; i < SIZE; i++) {
		dis[i] = MAX;
		map[i].clear();
	}
}

void dijkstra(int start) {
	bool visit[n];
	memset(visit, false, sizeof(visit));
	
	dis[start] = 0;
	priority_queue<node> pq;
	
	pq.push((node){start, dis[start]});
	
	while(!pq.empty() && !visit[pq.top().id]) {
		int cur = pq.top().id;
		visit[cur] = true;
		
		for(int i = 0; i < map[cur].size(); i++) {
			int next = map[cur][i].next;
			
			if(!visit[next] && dis[next] > dis[cur] + map[cur][i].l) {
				dis[next] = dis[cur] + map[cur][i].l;
				pq.push((node) {next, dis[next]});
			}
		}
		
		while(!pq.empty() && visit[pq.top().id]) pq.pop();
	}
}

int main() {
	int kase, count = 0;
	cin >> kase;
	
	while(kase--) {
		reset();
		
		cin >> n >> m >> s >> t;
		
		for(int i = 0; i < m; i++) {
			int a, b, l;
			cin >> a >> b >> l;
			
			map[a].push_back((chain) {b, l});
			map[b].push_back((chain) {a, l});
		}
		
		dijkstra(s);
		
		cout << "Case #" << ++count << ": ";
		if(t < n && dis[t] != MAX) cout << dis[t] << endl;
		else cout << "unreachable" << endl;
	}
	return 0;
} 
