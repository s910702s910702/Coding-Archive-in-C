#include <iostream>
#include <queue>

using namespace std;

int main() {
	int n;
	while(cin >> n && n) {
		bool flag = true;
		queue<int> q;
		
		for(int i = 1; i <= n; i++) q.push(i);
		
		cout << "Discarded cards:";
		
		while(q.size() > 1) {
			if(flag) {
				cout << " ";
				flag = false;
			}
			else cout << ", ";
			cout << q.front();
			q.pop();
			q.push(q.front
			());
			q.pop();	
		}
	
		cout << endl;
		cout << "Remaining card: " << q.front() << endl;
	}
	return 0;
}
