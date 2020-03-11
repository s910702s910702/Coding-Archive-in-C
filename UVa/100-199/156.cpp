#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
	char read;
	vector<char> v;
	map<string, string> ori;
	map<string, int> mp;

	while(cin >> noskipws >> read && read != '#') {
		if(isalpha(read)) v.push_back(read);
		else {
			if(v.size() == 0) continue;

			string o = "";
			for(auto i : v) o += i;

			for(int i = 0; i < v.size(); i++) v[i] = tolower(v[i]);
			sort(v.begin(), v.end());

			string str = "";
			for(auto i : v) str += i;

			v.clear();

			ori.insert(pair<string, string>(o, str));
			if(mp.find(str) == mp.end()) mp.insert(pair<string, int>(str, 1));
			else mp[str] += 1;
		}
	}

	for(auto i : ori) {
		string str = i.second;

		if(mp[str] == 1) cout << i.first << endl;
	}

	return 0;
}