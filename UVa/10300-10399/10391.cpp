#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
	set<string> s;
	vector<string> v;

	string str;

	while(cin >> str) {
		v.push_back(str);
		s.insert(str);
	}

	for(string str : v) {
		int len = str.length();

		for(int i = 1; i < len; i++) {
			string str1 = str.substr(0, i);
			string str2 = str.substr(i, len);

			if(s.find(str1) != s.end() && s.find(str2) != s.end()) {
				cout << str << endl;
				break;
			}
		}
	}

	return 0;
}