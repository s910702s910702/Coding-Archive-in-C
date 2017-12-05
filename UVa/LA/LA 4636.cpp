#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
	int a, b;
	while(cin >> a >> b && a && b) {
		deque<int> q1, q2;
		for(int i = 0; i < a; i++) {
			int tmp;
			cin >> tmp;
			
			q1.push_back(tmp);
		}
		
		for(int i = 0; i < b; i++) {
			int tmp;
			cin >> tmp;
			
			q2.push_back(tmp);
		}
		
		sort(q1.begin(), q1.end());
		sort(q2.begin(), q2.end());
		
		int sum = 0;
		
		while(!q1.empty() && !q2.empty()) {
			if(q1.front() == q2.front()) {
				sum += q1.front();
				q1.pop_front();
				q2.pop_front();
			}
			else if(q1.front() < q2.front()) {
				sum += q1.front();
				q1.pop_front();
			}
			else {
				sum += q2.front();
				q2.pop_front();
			}
		}
		
		while(!q1.empty()) {
			sum += q1.front();
			q1.pop_front();
		}
	
		while(!q2.empty()) {
			sum += q2.front();
			q2.pop_front();
		}
	
		cout << sum << endl;	
	}
	return 0;
}
