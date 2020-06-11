#include <iostream>

using namespace std;

int cur = 0;

bool slump(string str) {
	if(str[cur] != 'D' && str[cur] != 'E') return false;

	cur++;
	if(str[cur] != 'F') return false;

	while(str[cur] == 'F') cur++;

	if(str[cur] == 'G') {
		cur++;
		return true;
	}

	return slump(str);
}

bool slimp(string str) {
	if(str[cur] == 'A') cur++;
	else return false;


	if(str[cur] == 'H') {
		cur++;
		return true;
	}
	else if(str[cur] == 'B') {
		cur++;
		if(slimp(str) && str[cur] == 'C') {
			cur++;
			return true;
		}
		else return false;
	}
	else {
		if(slump(str) && str[cur] == 'C') {
			cur++;
			return true;
		}
		else return false;
	}
}

bool Slurpy(string str) {
	if(slimp(str)) return slump(str);
	else return false;
}

int main() {
	int n;
	cin >> n;

	cout << "SLURPYS OUTPUT" << endl;

	while(n--) {
		// init
		cur = 0;

		string str;
		cin >> str;

		if(Slurpy(str) && cur == str.length()) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	cout << "END OF OUTPUT" << endl;

	return 0;
}