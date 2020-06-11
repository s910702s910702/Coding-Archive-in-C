#include <iostream>
#include <map>

using namespace std;

int main() {
	int n, m;

	while(cin >> n >> m) {
		map<string, string> mp;

		for(int i = 0; i < n; i++) {
			string name, ip;

			cin >> name >> ip;

			mp.insert(pair<string, string>(ip + ";", name));
		}

		for(int i = 0; i < m; i++) {
			string cmd, ip;

			cin >> cmd >> ip;

			string name = mp[ip];

			cout << cmd << " " << ip << " #" << name << endl;
		}
	}

	return 0;
}