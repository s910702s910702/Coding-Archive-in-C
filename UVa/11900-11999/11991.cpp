#include <iostream>
#include <vector>

#define SIZE 1000005

using namespace std;

vector<int> arr[SIZE];

void init() {
	for(int i = 0; i < SIZE; i++) 
		if(!arr[i].empty())
			arr[i].clear();
}

int main() {
	int n, m;

	ios::sync_with_stdio(false);
	cin.tie(0);

	while(cin >> n >> m) {
		init();

		for(int i = 0; i < n; i++) 	{
			int x;
			cin >> x;

			arr[x].push_back(i + 1);
		}

		for(int i = 0; i < m; i++) {
			int v, k;
			cin >> k >> v;

			if(k > arr[v].size()) cout << 0;
			else cout << arr[v][k - 1];
			cout << "\n";
		}
	}
	return 0;
}