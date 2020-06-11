#include <iostream>
#include <queue>
#include <string>
#include <vector>

#define LL unsigned long long

using namespace std;


vector<LL> v;

bool in_vector(LL x) {
	if(v.size() == 0) return false;;
	for(int i = 0; i < v.size(); i++) {
		if(v[i] == x) return true;
	}
	return false;
}


int main() {
	priority_queue<LL, vector<LL>, greater<LL> > pq;

	pq.push(1);

	while(v.size() < 1500) {
		int cur = pq.top();
		if(in_vector(cur)) {
			pq.pop();
			continue;
		}

		v.push_back(cur);
		// cout << cur << " ";
		pq.pop();

		pq.push(cur * 2);
		pq.push(cur * 3);
		pq.push(cur * 5);
	}

	cout << "The 1500'th ugly number is " << v[1499] << "." << endl;

	return 0;
}