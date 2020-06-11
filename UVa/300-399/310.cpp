#include <iostream>
#include <set>
#include <queue>

using namespace std;

int main() {
	string a, b, x, target;

	while(getline(cin, a) && getline(cin, b) && getline(cin, x) && getline(cin, target)) {
		if(target.length() == 0) {
			cout << "YES" << endl;
			continue;
		}
		queue<string> q;
		set<string> s;
		bool found = false;

		for(int i = 1; i <= target.length(); i++) {
			for(int j = 0; j < x.length(); j++) {
				string tmp = x.substr(j, i);
				
				if(s.find(tmp) == s.end()) {
					s.insert(tmp);
					q.push(tmp);
				}
			}
		}

		while(!q.empty()) {
			if(found) break;

			string cur = q.front();
			q.pop();

			int len = cur.length();

			if(cur == target) {
				found = true;
				break;
			}

			string new_str = "";
			for(int i = 0; i < len; i++) {
				if(cur[i] == 'a') new_str += a;
				if(cur[i] == 'b') new_str += b;
			}
			
			int new_len = new_str.length();

			for(int i = 1; i <= target.length(); i++) {
				for(int j = 0; j < new_len; j++) {
					string tmp = new_str.substr(j, i);

					if(s.find(tmp) == s.end()) {
						s.insert(tmp);
						q.push(tmp);
					}
				}
			}
			
		}

		if(found) cout << "YES" << endl;
		else cout << "NO" << endl;
		
	}

	return 0;
}