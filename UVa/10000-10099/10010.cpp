#include <iostream>
#include <cstring>

using namespace std;

int main() {
	int kase;
	bool flag = true;
	cin >> kase;
	
	while(kase--) {
		if(flag) flag = false;
		else cout << endl;
		
		int m, n;
		cin >> m >> n;
		
		char a[m][n];
		
		for(int i = 0; i < m; i++)
			for(int j = 0; j < n; j++) {
				cin >> a[i][j];
				a[i][j] = tolower(a[i][j]);
			}
				
				
		int k;
		cin >> k;
		for(int i = 0; i < k; i++) {
			string str;
			cin >> str;
			
			for(int i = 0; i < str.length(); i++) str[i] = tolower(str[i]);
			
			bool find = false;
			for(int i = 0; i < m; i++) {
				if(find) break;
				for(int j = 0; j < n; j++) {
					if(find) break;
					
					if(a[i][j] == str[0]) {
						
						
						find = true;
						for(int l = 0; l < str.length(); l++)
							if(a[i][j + l] != str[l] || j + l >= n) {
								find = false;
								break;
							}
						if(find) {
							i++;
							j++;
							cout << i << " " << j << endl;
//							find = false;
							break;
						}
						
						
						
						
						find = true;
						for(int l = 0; l < str.length(); l++){
//							cout << a[i + l][j] << " " << str[l] << endl;
							if(a[i + l][j] != str[l] || i + l >= m) {
//								cout << "out" << endl;
								find = false;
								break;
							}
						}
						if(find) {
							i++;
							j++;
							cout << i << " " << j << endl;
//							find = false;
							break;
						}
						
						
						
						
						find = true;
						for(int l = 0; l < str.length(); l++)
							if(a[i + l][j + l] != str[l] || i + l >= m || j + l >= n) {
								find = false;
								break;
							}
						if(find) {
							i++;
							j++;
							cout << i << " " << j << endl;
//							find = false;
							break;
						}
						
						
						
						
						find = true;
						for(int l = 0; l < str.length(); l++)
							if(a[i][j - l] != str[l] || j - l < 0) {
								find = false;
								break;
							}
						if(find) {
							i++;
							j++;
							cout << i << " " << j << endl;
//							find = false;
							break;
						}
						
						
						
						
						find = true;
						for(int l = 0; l < str.length(); l++)
							if(a[i - l][j] != str[l] || i - l < 0) {
								find = false;
								break;
							}
						if(find) {
							i++;
							j++;
							cout << i << " " << j << endl;
//							find = false;
							break;
						}
						
						
						
						find = true;
						for(int l = 0; l < str.length(); l++)
							if(a[i - l][j - l] != str[l] || i - l < 0 || j - l < 0) {
								find = false;
								break;
							}
						if(find) {
							i++;
							j++;
							cout << i << " " << j << endl;
//							find = false;
							break;
						}
						
						
						find = true;
						for(int l = 0; l < str.length(); l++)
							if(a[i - l][j + l] != str[l] || i - l < 0 || j + l >= n) {
								find = false;
								break;
							}
						if(find) {
							i++;
							j++;
							cout << i << " " << j << endl;
//							find = false;
							break;
						}
						
						
						find = true;
						for(int l = 0; l < str.length(); l++)
							if(a[i + l][j - l] != str[l] || i + l >= m || j - l < 0) {
								find = false;
								break;
							}
						if(find) {
							i++;
							j++;
							cout << i << " " << j << endl;
//							find = false;
							break;
						}
					}
				}
			}
			
			
		}
		
	}
	
	return 0;
}
