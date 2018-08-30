#include <iostream>
#include <vector>
#include <cstring>

#define SIZE 10000
#define ny 10
using namespace std;

vector<int> adj[SIZE];
char name[SIZE];
int nx;

int mx[SIZE], my[ny];
bool vy[10];

void init() {
	nx = 0;
	for(int i = 0; i < SIZE; i++) adj[i].clear();
}

bool dfs(int x) {
	for(int i = 0; i < adj[x].size(); i++) {
		int y = adj[x][i];
		
		if(!vy[y]) {
			vy[y] = true;

			if(my[y] == -1 || dfs(my[y])) {
				mx[x] = y;
				my[y] = x;

				return true;
			}
		}
	}

	return false;
}

int matching() {
	memset(mx, -1, sizeof(mx));
	memset(my, -1, sizeof(my));

	int c = 0;
	for(int i = 0; i < nx; i++) {
		memset(vy, false, sizeof(vy));

		if(dfs(i)) c++;
	}

	return c;
}

void judge() {
	int ans = matching();

	if(ans != nx) cout << "!" << endl;
	else {
		for(int i = 0; i < ny; i++) 
			if(my[i] != -1) cout << name[my[i]];
			else cout << "_";
		cout << endl;
	}
}

int main() {
	string str;

	while(getline(cin, str)) {
		if(str.length() == 0) {
			judge();
			init();
		}
		else {
			int number = (int)(str[1] - '0');

			vector<int> path;
			for(int i = 3; i < str.length() - 1; i++) {
				int tmp = (int)(str[i] - '0');
				path.push_back(tmp);
			}

			for(int i = 0; i < number; i++) {
				name[nx + i] = str[0];
				for(auto j : path) adj[nx + i].push_back(j);
			}

			nx += number;
		}
	}
	judge();

	return 0;
}