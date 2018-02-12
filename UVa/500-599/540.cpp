#include <iostream>
#include <queue>
#include <cstring>
#include <map>

using namespace std;

int main() {
	int t, cnt = 0;
	while(cin >> t && t) {
		cout << "Scenario #" << ++cnt << endl;
		
		int team_back[t];
		memset(team_back, -1, sizeof(team_back));
		
		map<int, int> m;
		for(int i = 0; i < t; i++) {
			int n;
			cin >> n;
			
			for(int j = 0; j < n; j++) {
				int tmp;
				cin >> tmp;
				m[tmp] = i;
			}
		}
		
		deque<int> dq;
		string cmd;
		while(cin >> cmd) {
			if(cmd == "ENQUEUE") {
				int x;
				cin >> x;
				
				int belong = m.find(x) -> second;
				
				if(team_back[belong] == -1) {
					dq.push_back(x);
					team_back[belong] = dq.size() - 1;
				}
				else {
					dq.insert(dq.begin() + team_back[belong] + 1, x);
					for(int i = 0; i < t; i++)
						if(team_back[i] >= team_back[belong]) team_back[i]++;
				}
			}
			else if(cmd == "DEQUEUE") {
				cout << dq.front() << endl;
				dq.pop_front();
				for(int i = 0; i < t; i++)
					if(team_back[i] >= 0) team_back[i]--;
			}
			else {
				cout << endl;
				break;
			}
		}
	}
	return 0;
}
