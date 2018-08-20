#include <iostream>

using namespace std;

long long int power3(int x) {
	long long int ans = 1;
	for(int i = 0; i < x; i++) ans *= 3;
	return ans;
}

long long int find(int k, int end) {
	if(end < 1) return 0;
	if(k == 0) return 1;
	if(end == 1 << k) return power3(k);

	if(end >= (1 << (k - 1))) 
		return 2 * power3(k - 1) + find(k - 1, end - (1 << (k - 1)));
	else 
		return 2 * find(k - 1, end);
}

long long int count(int k, int a, int b) {
	return find(k, b) - find(k, a - 1);
}

int main() {
	int kase, cnt = 1;
	cin >> kase;

	while(kase--) {
		int k, a, b;
		cin >> k >> a >> b;

		cout << "Case " << cnt++ << ": " << count(k, a, b) << endl;
	}

	return 0;
}