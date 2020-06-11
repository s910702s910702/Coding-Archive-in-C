#include <iostream>
#include <set>
#include <string>

using namespace std;

string to_lower(string str) {
	int len = str.length();

	for(int i = 0; i < len; i++)
		if(str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;

	return str;
}

int main() {
	char read;
	string str;
	set<string> s;

	while(cin >> noskipws >> read) {
		if(isalpha(read)) str += read;
		else {
			if(str.length() == 0) continue;
			s.insert(to_lower(str));
			str = "";
		}
	}

	for(auto str : s) cout << str << endl;

	return 0;
}