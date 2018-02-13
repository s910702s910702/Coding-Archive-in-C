#include <iostream>
#include <stack>
#include <sstream>

using namespace std;

int main() {
	int n;
	bool flag = true;
	
	while(cin >> n && n) {
		if(flag) flag = false;
		else cout << endl;
		
		string str;
		getchar();
		while(getline(cin, str)) {
			int cur = 1;
			stack<int> st;
			bool judge = true;
			
			st.push(cur++);
			
			if(str.length() == 1 && str[0] == '0') break; 
			
			stringstream ss;
			ss << str;
			
			int x;
			while(ss >> x) {
				if(st.size() == 0) st.push(cur++);
				while(st.top() != x && cur <= n) st.push(cur++);
				if(st.top() == x) st.pop();
				else judge = false;
			}
			
			if(judge) cout << "Yes" << endl;
			else cout << "No" << endl;
		}
	}
	cout << endl;
	return 0;
}
