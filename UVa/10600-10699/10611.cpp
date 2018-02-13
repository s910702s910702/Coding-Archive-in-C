#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	
	int a[n];
	for(int i = 0; i < n; i++) cin >> a[i];
	
	int kase;
	cin >> kase;
	
	while(kase--) {
		int key;
		cin >> key;
		
		int l = 0, r = n - 1, mid;
		while(l < r - 1) {
			mid = (l + r) / 2;
			if(a[mid] > key) r = mid;
			else if(a[mid] == key) break;
			else if(a[mid] < key) l = mid;
		}
		
		int left = mid, right = mid;
		while(a[left] <= key && left < n - 1) left++;
		while(a[left] >= key && left >= 0) left--;
		while(a[right] >= key && right > 0) right--;
		while(a[right] <= key && right < n) right++;
		
		if(left < 0) cout << "X ";
		else cout << a[left] << " ";
		
		if(right < n) cout << a[right] << endl;
		else cout << "X" << endl;
	}
	
	return 0;
}
