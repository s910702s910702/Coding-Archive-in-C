#include <iostream>
#include <cstring>
#define ALPHABET_SIZE 30
#define MOD 20071027
#define MAX_L 350000

using namespace std;

int dp[MAX_L];

struct TrieNode {
     struct TrieNode *children[ALPHABET_SIZE];
     bool word;
};

TrieNode * root;

TrieNode * get_node() {
	TrieNode * new_ptr = new TrieNode;

	for(int i = 0; i < ALPHABET_SIZE; i++) 
		new_ptr -> children[i] = NULL;
	new_ptr -> word = false;

	return new_ptr;
}

void add(string str) {
	TrieNode * cur = root;

	for(int i = 0; i < str.length(); i++) {
		int index = (int)(str[i] - 'a');
		if(!cur -> children[index]) 
			cur -> children[index] = get_node();

		cur = cur -> children[index];
	}

	cur -> word = true;
}

void solve(string str, int p) {
	TrieNode * cur = root;

	for(int i = 0; i < str.length(); i++) {
		int index = (int)(str[i] - 'a');

		if(!cur -> children[index]) return;
		cur = cur -> children[index];
		if(cur -> word) dp[p] = (dp[p] + dp[p + i + 1]) % MOD; 
	}
}

void release(TrieNode * node) {
	TrieNode * cur = node;

	for(int i = 0; i < ALPHABET_SIZE; i++) {
		if(cur -> children[i]) {
			release(cur -> children[i]);
		}
	}
	delete node;
}

int main() {
	ios_base::sync_with_stdio(false);

	string sample;
	int cnt = 1;

	while(cin >> sample) {
		root = get_node();
		int n;
		cin >> n;

		for(int i = 0; i < n; i++) {
			string str;
			cin >> str;
			add(str);
		}

		memset(dp, 0, sizeof(dp));

		dp[sample.length()] = 1;

		string target = "";

		for(int i = sample.length() - 1; i >= 0; i--) {
			target = sample[i] + target;

			solve(target, i);
		}

		cout << "Case " << cnt++ << ": " << dp[0] % MOD << "\n";

		release(root);
	}

	return 0;
}