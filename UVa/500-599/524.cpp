//correct
#include <iostream>
#include <cstring>

using namespace std;

int n;
bool book[17], flag = true;
int circle[16];

void judge_flag() {
	if(flag) flag = false;
	else cout << endl;
}

void reset() {
	memset(book , false, sizeof(book));
	book[1] = true;
}

void print() {
	for(int i = 0; i < n - 1; i++) cout << circle[i] << " ";
	cout << circle[n - 1] << endl;
}

bool prime(int x) {
	int p[15] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41 , 43, 47};
	for(int i = 0 ; i < 15; i++) if(x == p[i]) return true;
	return false;
}

void bt(int cur) {
	if(cur == n - 1) {
		for(int i = 1; i <= n; i++) {
			if(book[i] == false && prime(i + circle[0]) && prime(i + circle[cur - 1])) {
			 	circle[cur] = i;
				print();
				return ;
			}
		}
	}
	
	for(int i = 1; i <= n; i++) {
		if(book[i] == false && prime(i + circle[cur - 1])) {
			circle[cur] = i;
			book[i] = true;
			bt(cur + 1);
			book[i] = false;
		}
	}
}

int main() {
  int cnt = 0;
	while(cin >> n) {
		judge_flag();
		cout << "Case " << ++cnt << ":"<< endl;
		reset();
		circle[0] = 1;

		bt(1);
	}
	return 0;
}