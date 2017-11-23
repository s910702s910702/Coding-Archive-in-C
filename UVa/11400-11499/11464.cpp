//correct
#include <iostream>

using namespace std;

int n, minimum = 1e9;
int sample[15][15], make[15][15];

void evaluate() {
	int cnt = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if(sample[i][j] < make[i][j]) cnt++;
			
	if(cnt < minimum) minimum = cnt;
}

void generate() {
	for(int i = 1; i < n; i++) {
		for(int j = 0; j < n; j++) {
			int sum = 0;
			if(i - 2 >= 0 && make[i - 2][j]) sum++;
			if(i - 1 >= 0 && j - 1 >= 0 && make[i - 1][j - 1]) sum++;
			if(i - 1 >= 0 && j + 1 < n && make[i - 1][j + 1]) sum++;
			
			make[i][j] = sum & 1;
			if(make[i][j] < sample[i][j]) return ;
		}
	}
	evaluate();
}

void bt(int cur) {
	if(sample[0][cur]) {
		make[0][cur] = 1;
		if(cur < n - 1) bt(cur + 1);
		else generate();
	}
	else {
		make[0][cur] = 0;
		if(cur < n - 1) bt(cur + 1);
		else generate();
		
		make[0][cur] = 1;
		if(cur < n - 1) bt(cur + 1);
		else generate();
	}
}

int main() {
	int t, cnt = 0;
	cin >> t;
	
	while(t--) {
		minimum = 1e9;
		cin >> n;
		
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				cin >> sample[i][j];
		
		bt(0);
		
		cout << "Case " << ++cnt << ": ";
		if(minimum != 1e9) cout << minimum << endl;
		else cout << -1 << endl;
	}
	return 0;
} 