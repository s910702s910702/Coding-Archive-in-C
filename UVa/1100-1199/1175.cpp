#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int main() {
	int kase;
	bool flag = true;
	cin >> kase;

	while(kase--) {
		if(flag) flag = false;
		else cout << endl;

		int n;
		cin >> n;

		int male[n + 1][n];
		int f_rank[n + 1][n];

		for(int i = 1; i <= n; i++)
			for(int j = 0; j < n; j++)
				cin >> male[i][j];


		for(int i = 1; i <= n; i++) 
			for(int j = 0; j < n; j++) {
				int who;
				cin >> who;

				f_rank[i][who] = j;
			}

		queue<int> q;
		for(int i = 1; i <= n; i++) q.push(i);

		int f_select[n + 1];
		int m_select[n + 1];
		int m_it[n + 1];

		memset(f_select, 0, sizeof(f_select));
		memset(m_select, 0, sizeof(m_select));
		memset(m_it, 0, sizeof(m_it));

		while(!q.empty()) {
			int cur = q.front();
			q.pop();

			int cur_select = male[cur][m_it[cur]];

			if(!f_select[cur_select]) {
				f_select[cur_select] = cur;
				m_select[cur] = cur_select;
			}
			else {
				int om_rank = f_rank[cur_select][f_select[cur_select]];
				int nm_rank = f_rank[cur_select][cur];

				if(nm_rank < om_rank) {
					q.push(f_select[cur_select]);
					m_it[f_select[cur_select]]++;

					f_select[cur_select] = cur;
					m_select[cur] = cur_select;
				}
				else {
					q.push(cur);
					m_it[cur]++;
				}
			}
		}

		for(int i = 1; i <= n; i++) cout << m_select[i] << endl;
	}
		
	return 0;
}