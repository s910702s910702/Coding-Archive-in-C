#include <iostream>
#include <queue>
using namespace std;

typedef struct {
	int x, y;
} node;

int main() {
	int a, b;
	
	while(cin >> a >> b && a && b) {
		char m[a][b];
		bool book[a][b];
		for(int i = 0; i < a; i++)
			for(int j = 0;j < b; j++) {
				cin >> m[i][j];
				book[i][j] = false;
			}
				
		queue<node> q;
		
		int cnt = 0;
		for(int i = 0; i < a; i++) {
			for(int j = 0; j < b; j++) {
				if(m[i][j] == '@' && book[i][j] == false) {
					q.push((node){i, j});
					cnt++;
					while(!q.empty()) {
						int curx = q.front().x;
						int cury = q.front().y;
						
						q.pop();
						
						if(book[curx][cury] == false) book[curx][cury] = true;
						else continue;
						
						if(curx - 1 >= 0 && cury - 1 >= 0 && book[curx - 1][cury - 1] == false && m[curx - 1][cury - 1] == '@') q.push((node){curx - 1, cury - 1});
						if(curx - 1 >= 0 && book[curx - 1][cury] == false && m[curx - 1][cury] == '@') q.push((node){curx - 1, cury});
						if(curx - 1 >= 0 && cury + 1 < b && book[curx - 1][cury + 1] == false && m[curx - 1][cury + 1] == '@') q.push((node){curx - 1, cury + 1});
						if(cury - 1 >= 0 && book[curx][cury - 1] == false && m[curx][cury - 1] == '@') q.push((node){curx, cury - 1});
						if(cury + 1 < b && book[curx][cury + 1] == false && m[curx][cury + 1] == '@') q.push((node){curx, cury + 1});
						if(curx + 1 < a && cury - 1 >= 0 && book[curx + 1][cury - 1] == false && m[curx + 1][cury - 1] == '@') q.push((node){curx + 1, cury - 1});
						if(curx + 1 < a && book[curx + 1][cury] == false && m[curx + 1][cury] == '@') q.push((node){curx + 1, cury});
						if(curx + 1 < a && cury + 1 < b && book[curx + 1][cury + 1] == false && m[curx + 1][cury + 1] == '@') q.push((node){curx + 1, cury + 1});
					}
				}
			}
		}
		cout << cnt << endl;
	}
	return 0;
}
