#include <iostream>
#include <stack>

using namespace std;

stack<int> route;

int main() {
	int a, b;
	cin >> a >> b;
	
	while(b > a) {
		if(b % 10 == 1) {
			route.push(b);
			b /= 10;
		}
		else if(b % 2 == 0) {
			route.push(b);
			b >>= 1;
		}
		else {
			break;
		}
	}
	
	if(b == a) {
		route.push(a);
		cout << "YES" << endl;
		cout << route.size() << endl;
		while(route.size() > 1) {
			cout << route.top() << " ";
			route.pop();
		}
		cout << route.top() << endl;
	}
	else cout << "NO" << endl;
	return 0;
}
