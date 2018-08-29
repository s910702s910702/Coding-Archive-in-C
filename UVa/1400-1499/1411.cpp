#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>

#define SIZE 110
#define EPS 1e-9
using namespace std;

struct point {
	double x, y;
};
point a[SIZE], b[SIZE];

int n;
double adj[SIZE][SIZE];
int mx[SIZE], my[SIZE];
double lx[SIZE], ly[SIZE];
bool vx[SIZE], vy[SIZE];


double d(point a, point b) { 
	return -sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)); 
}
void make_dis() {
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			adj[i][j] = d(a[i], b[j]);
}

bool dfs(int x) {
	vx[x] = true;

	for(int y = 0; y < n; y++)
		if(!vy[y])
			if(fabs(lx[x] + ly[y] - adj[x][y]) < EPS) {
				vy[y] = true;
				if(my[y] == -1 || dfs(my[y])) {
					mx[x] = y;
					my[y] = x;

					return true;
				}
			}

	return false;
}

void hungarian() {
	for(int i = 0; i < n; i++) lx[i] = adj[i][0];
	memset(ly, 0, sizeof(ly));

	for(int x = 0; x < n; x++)
		for(int y = 0; y < n; y++)
			lx[x] = max(lx[x], adj[x][y]);

	memset(mx, -1, sizeof(mx));
	memset(my, -1, sizeof(my));

	for(int x = 0; x < n; x++) {
		while(1) {
			memset(vx, false, sizeof(vx));
			memset(vy, false, sizeof(vy));
			if(dfs(x)) break;

			double d = 1e9;
			for(int x = 0; x < n; x++) if(vx[x])
				for(int y = 0; y < n; y++) if(!vy[y])
					d = min(d, lx[x] + ly[y] - adj[x][y]);

			if(d == 1e9) return ;

			for(int x = 0; x < n; x++)
				if(vx[x]) lx[x] -= d;

			for(int y = 0; y < n; y++)
				if(vy[y]) ly[y] += d;
		}
	}
}

int main() {
	bool flag = true;
	while(cin >> n) {
		if(flag) flag = false;
		else cout << endl;

		for(int i = 0; i < n; i++) cin >> a[i].x >> a[i].y;
		for(int i = 0; i < n; i++) cin >> b[i].x >> b[i].y;
		make_dis();

		hungarian();

		for(int i = 0; i < n; i++) cout << mx[i] + 1 << endl;
	}

	return 0;
}