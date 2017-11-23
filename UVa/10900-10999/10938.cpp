//correct
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<int> map[5005];
int path[5005];
bool used[5005], found;

void dfs(int len, int start, int end) {
	if(used[start] || found) return ;

	path[len] = start;

	if(start == end) {
		if(!(len % 2)) cout << "The fleas meet at " << path[len / 2] << "." << endl;
		else {
			if(path[len / 2] < path[len / 2 + 1]) cout << "The fleas jump forever between " << path[len / 2] << " and " << path[len / 2 + 1] << "." << endl;
			else cout << "The fleas jump forever between " << path[len / 2 + 1] << " and " << path[len / 2] << "." << endl;
		}
		found = true;
		return ;
	}
	
	used[start] = true;
	for(int i = 0; i < map[start].size(); i++) {
//		if(used[map[start][i]] == false) cout << start << " Found " << map[start][i] << endl;
		if(used[map[start][i]] == false) dfs(len + 1, map[start][i], end);
	}
	used[start] = false;
}

int main() {
	int n;
	while(cin >> n && n) {
		for(int i = 0; i < 5005; i++) map[i].clear();

		for(int i = 0; i < n - 1; i++) {
			int a, b;
			cin >> a >> b;
			map[a].push_back(b);
			map[b].push_back(a);
		}

		int q;
		cin >> q;
		
		while(q--) {
			memset(used, false, sizeof(used));
			found = false;
			
			int start, end;
			cin >> start >> end;
			dfs(0, start, end);
		}
	}
	return 0; 
}