#include <iostream>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <queue>
#include <cstring>

#define INF 1e9
#define SIZE 101

using namespace std;

int n, k;
int speed[SIZE];
int dis[SIZE];
bool book[SIZE];
vector<int> stopat[SIZE];

typedef struct {
	int id;
	int line;
	int dis;
} node;
bool operator < (node l, node r) { return l.dis > r.dis; }

void dijkstra(int start) {
	dis[start] = 0;
	book[start] = true;
	
	priority_queue <node> pq;
	
	for(int i = 0; i < n; i++) {
		if(stopat[i][0] == 0) {
			for(int j = 0; j < stopat[i].size(); j++) {
				int next = stopat[i][j];
				
				if(dis[next] > dis[0] + (next - 0) * speed[i]) { 
					dis[next] = dis[0] + (next - 0) * speed[i];
					
					pq.push((node){	next, i, dis[next] });
				}
			}
		}
	}
	while(!pq.empty()) {
		int cur = pq.top().id;
		int cline = pq.top().line;
		int cdis = pq.top().dis;
		pq.pop();
		
		book[cur] = true;
		
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < stopat[i].size(); j++) {
				if(stopat[i][j] > cur) break;
				
				if(stopat[i][j] == cur) {
					if(i != cline) {
						for(int k = 0; k < stopat[i].size(); k++) {
							int next = stopat[i][k];
							if(dis[next] > dis[cur] + abs(next - cur) * speed[i] + 60) {
								dis[next] = dis[cur] + abs(next - cur) * speed[i] + 60;
								pq.push((node){ next, i, dis[next] });
							}
						}
					}
					
					else {
						for(int k = 0; k < stopat[i].size(); k++) {
							int next = stopat[i][k];
							if(dis[next] > dis[cur] + abs(next - cur) * speed[i]) {
								dis[next] = dis[cur] + abs(next - cur) * speed[i];
								pq.push((node){ next, i, dis[next] });
							}
						}
					}
				}
			}
		}
		while(!pq.empty() && book[pq.top().id]) pq.pop();
	}
}

void reset() {
	memset(speed, 0, sizeof(speed));
	memset(book, false, sizeof(book));
	for(int i = 0; i < SIZE; i++) {
		dis[i] = INF;
		stopat[i].clear();
	}
}

int main() {
	while(cin >> n >> k) {
		reset();
		for(int i = 0; i < n; i++) cin >> speed[i];
		
		getchar();
		for(int i = 0; i < n; i++) {
			string str;
			getline(cin, str);
			
			stringstream ss;
			ss << str;
			
			int tmp;
			while(ss >> tmp) stopat[i].push_back(tmp);
		}
		
		dijkstra(0);
		
		if(dis[k] == INF) cout << "IMPOSSIBLE" << endl;
		else cout << dis[k] << endl;
	}
	
	return 0;
} 
