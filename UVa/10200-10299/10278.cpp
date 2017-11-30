#include <iostream>
#include <cstring>
#include <queue>
#include <sstream>

#define SIZE 501
#define MAX 1e9

using namespace std;

int f, ci;

typedef struct {
	bool firestation;
	int dis;
} cities;

typedef struct {
	int id;
	int dis;
} node;
bool operator < (node n1, node n2) { return n1.dis > n2.dis; }

int map[SIZE][SIZE];
bool visit[SIZE];
cities c[SIZE];

void reset() {
	for(int i = 0; i < SIZE; i++)
		for(int j = 0; j < SIZE; j++) 
			map[i][j] = MAX;
	
	for(int i = 0; i < SIZE; i++) {
		c[i].firestation = false;
		c[i].dis = 1e9;
	}
}

void dijkstra(int start) {
	memset(visit, false, sizeof(visit));
	priority_queue<node> pq;

	pq.push((node){start, c[start].dis});

	while(!pq.empty() && !visit[pq.top().id]) {
		int cur = pq.top().id;
		visit[cur] = true;
		pq.pop();

		for(int i = 1; i <= ci; i++)
			if(!visit[i] && map[cur][i] + c[cur].dis < c[i].dis) {
				c[i].dis = map[cur][i] + c[cur].dis;
				
				pq.push((node){i, c[i].dis});
			}

		while(!pq.empty() && visit[pq.top().id]) pq.pop();
	}
}

int main() {
	bool flag = true;
	int kase;
	cin >> kase;
	
	while(kase--) {
		reset();

		cin >> f >> ci;
		
		for(int i = 0; i < f; i++) {
			int tmp;
			cin >> tmp;

			c[tmp].firestation = true;
			c[tmp].dis = 0;
		}
		getchar();
		
		string str;
		while(getline(cin, str) && str.length() > 0) {
			stringstream ss;
			ss << str;
			
			int a, b, l;
			ss >> a >> b >> l;
			map[a][b] = map[b][a] = l;
		}
		
		for(int i = 1; i <= ci; i++) if(c[i].firestation) dijkstra(i);
		
		int minimum = 0;
		for(int i = 1; i <= ci; i++) if(c[i].dis > minimum) minimum = c[i].dis;
		
		int miniwho = 1;
		for(int i = 1; i <= ci; i++) {
			if(!c[i].firestation) {
				for(int j = 1; j <= ci; j++) 
					if(c[j].firestation) c[j].dis = 0;
					else c[j].dis = MAX;
				
				c[i].firestation = true;
				int ori = c[i].dis;
				c[i].dis = 0;

				for(int j = 1; j <= ci; j++) if(c[j].firestation) dijkstra(j);

				int maximum = 0;
				for(int j = 1; j <= ci; j++)
					if(c[j].dis > maximum) maximum = c[j].dis;
					
				if(maximum < minimum) {
					minimum = maximum;
					miniwho = i;
				}
				
				c[i].firestation = false;
				c[i].dis = ori;
			}
		}
		if(flag) flag = false;
		else cout << endl;
		cout << miniwho << endl;
	}
	return 0;
}
