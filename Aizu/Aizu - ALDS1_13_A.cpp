#include <iostream>
#include <cstring>

using namespace std;

char map[8][8];
bool a1[8], a2[8], a3[15], a4[15];

void print() {
	for(int i = 0; i < 8; i++) {
		for(int j = 0; j < 7; j++)
			cout << map[i][j];
		cout << map[i][7] << endl;
	}
}

void bt(int x, int y, int n) {
	if(y == 8) {
		x++;
		y = 0;
	}
	
	if(x == 8) {
		if(n == 8) print();
		return ;
	}
	
	
	if(!a1[x] && !a2[y] && !a3[x + y] && !a4[x - y + 7]) {
		a1[x] = a2[y] = a3[x + y] = a4[x - y + 7] = true;
		map[x][y] = 'Q';
		
		bt(x, y + 1, n + 1);
	
		a1[x] = a2[y] = a3[x + y] = a4[x - y + 7] = false;
		map[x][y] = '.';
	}
	
	bt(x, y + 1, n);
	
}

int main() {
	
	memset(map, '.', sizeof(map));
	memset(a1, false, sizeof(a1));
	memset(a2, false, sizeof(a2));
	memset(a3, false, sizeof(a3));
	memset(a4, false, sizeof(a4));
	
	int n;
	cin >> n;
	
	for(int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		
		map[x][y] = 'Q';
		a1[x] = true;
		a2[y] = true;
		a3[x +  y] = true;
		a4[x - y + 7] = true;
	}
	bt(0, 0, n);
	
	return 0;
}
