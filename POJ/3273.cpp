#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

#define SIZE 100005
using namespace std;

int a[SIZE];
int n, m;

bool test(long long x) {
	int sum = 0;
	int cnt = 1;
	
	for(int i = 0; i < n; i++) {
		if(sum + a[i] > x) {
			cnt++;
			sum = a[i];
		}
		else sum += a[i];
	}
	
	if(cnt > m) return false;
	return true;
}

int main() {
	while(cin >> n >> m) {
		for(int i = 0; i < n; i++) cin >> a[i];
		
		int left = *max_element(a, a + n), right = accumulate(a, a + n, 0), mid;
		
		if(test(left)) right = left;
		while(left < right - 1) {
			mid = (left + right) / 2;
			
			
			if(test(mid)) right = mid;
			else left = mid;
		}
		
		cout << right << endl;
	}
	return 0;
}
