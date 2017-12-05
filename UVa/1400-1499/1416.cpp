// This is bad solution :P
// I'll repost a better solution latter

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define SIZE 101
#define INF 1e9

using namespace std;

int n, m, L;

typedef struct {
	int next;
	int lon;
} mapnode;
vector<mapnode> map[SIZE];

typedef struct {
	int s, t;
	int lon;
} route;

void reset() {
	for(int i = 0; i < SIZE; i++) {
		map[i].clear();
		map[i].push_back((mapnode){-1, -1});
	}
}

typedef struct {
	int id;
	int lon;
} node;
bool operator < (node l, node r) { return l.lon > r.lon; }

int dis[SIZE];
int parent[SIZE][SIZE];

void dijkstra(int start) {
	bool visit[n + 1];
	memset(visit, false, sizeof(visit));
	for(int i = 0; i < SIZE; i++) dis[i] = INF;

	priority_queue<node> pq;

	dis[start] = 0;
	parent[start][start] = start;
	pq.push((node){start, dis[start]});

	while(!pq.empty()) {
		int cur = pq.top().id;
		pq.pop();

		visit[cur] = true;
		
		for(int i = 1; i < map[cur].size(); i++) {
			int next = map[cur][i].next;
			if(!visit[next] && dis[next] > dis[cur] + map[cur][i].lon) {
				parent[start][next] = cur;
				dis[next] = dis[cur] + map[cur][i].lon;
				pq.push((node){next, dis[next]});
			}
		}
		while(!pq.empty() && visit[pq.top().id]) pq.pop();
	}
}

long long int calc() {
	long long int sum = 0;
	for(int i = 1; i <= n; i++) 
		if(dis[i] == INF) sum += L;
		else sum += dis[i];
	return sum;
}

bool need(int a, int b) {
	for(int i = 1; i <= n; i++) {
		if(parent[i][a] == b || parent[i][b] == a) return true;
	}
	return false;
}

int main() {
	while(cin >> n >> m >> L) {
		reset();

		route r[m];
		for(int i = 0; i < m; i++) {
			cin >> r[i].s >> r[i].t >> r[i].lon;			
			
			map[r[i].s].push_back((mapnode){r[i].t, r[i].lon});
			map[r[i].t].push_back((mapnode){r[i].s, r[i].lon});
		}

		int sum = 0;
		for(int i = 1; i <= n; i++) {
			dijkstra(i);
			sum += calc();
		}

		cout << sum << " ";
		
		sum = 0;
		for(int i = 0; i < m; i++) {
			int ta = r[i].s, tb = r[i].t, tl = r[i].lon;
			if(need(ta, tb)) {
				for(int j = 1; j < map[ta].size(); j++) 
					if(map[ta][j].next == tb && map[ta][j].lon == tl) {
						map[ta][j].lon = INF;
						break;
					}

				for(int j = 1; j < map[tb].size(); j++) 
					if(map[tb][j].next == ta && map[tb][j].lon == tl) {
						map[tb][j].lon = INF;
						break;
					}
	            
				int aftersum = 0;
				for(int i = 1; i <= n; i++) {
					dijkstra(i);
					aftersum += calc();
				}

				if(aftersum > sum) sum = aftersum;

				for(int j = 1; j < map[ta].size(); j++) 
					if(map[ta][j].next == tb && map[ta][j].lon == INF) {
						map[ta][j].lon = tl;
						break;
					}

				for(int j = 1; j < map[tb].size(); j++) 
					if(map[tb][j].next == ta && map[tb][j].lon == INF) {
						map[tb][j].lon = tl;
						break;
					}

				for(int i = 1; i <= n; i++) {
					dijkstra(i);
					aftersum += calc();
				}
			}
			
		}
		cout << sum << endl;

	}
	return 0;
}

