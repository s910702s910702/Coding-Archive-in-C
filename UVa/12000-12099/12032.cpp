#include <iostream>

using namespace std;

int main() {
	int kase, cnt = 1;
	cin >> kase;
	
	while(kase--) {
		int n;
		cin >> n;
		
		int a[n];
		for(int i = 0; i < n; i++) cin >> a[i];
		
		int dis[n];
		dis[0] = a[0];
		for(int i = 1; i < n; i++) dis[i] = a[i] - a[i - 1];
		
		
		int cur = dis[n - 1];
		for(int i = n - 2; i >= 0; i--) {
			if(dis[i] == cur) cur++;
			if(dis[i] > cur) cur = dis[i];
		}
		
		cout << "Case " << cnt++ << ": " << cur << endl;
	}
	
	return 0;
}
