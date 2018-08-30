#include <iostream>
#include <cstring>

using namespace std;

struct tree {
	int next[15];
	bool word;
};

tree t[100005];
int back = 1;

bool check(int cur) {
	for(int i = 0; i < 15; i++) 
		if(t[cur].next[i] != -1)
			if(t[cur].word || check(t[cur].next[i])) return true;
	return false;
}

void build(string str) {
	int cur = 0;

	for(int i = 0; i < str.length(); i++) {
		int curchar = (int)(str[i] - '0');

		if(t[cur].next[curchar] == -1) {
			t[cur].next[curchar] = back;
			cur = back;

			back++;
		}
		else cur = t[cur].next[curchar];
	}

	t[cur].word = true;
}

void init() {
	back = 1;
	for(int i = 0; i < 100005; i++) {
		memset(t[i].next, -1, sizeof(t[i].next));
		t[i].word = false;
	}
}

int main() {
	int kase;
	cin >> kase;

	while(kase--) {
		init();

		int n;
		cin >> n;

		for(int i = 0; i < n; i++) {
			string str;
			cin >> str;

			build(str);
		}

		if(check(0)) cout << "NO" << endl;
		else cout << "YES" << endl;
	}

	return 0;
}