#include <iostream>
#include <stack>

using namespace std;

int main() {
	string str;

	while(cin >> str) {
		int len = str.length();

		stack<string> st;
		bool judge = true;

		for(int i = len - 1; i >= 0; i--) {
			if(judge == false) break;

			char cur = str[i];
			if(cur >= 'p' && cur <= 'z') {
				string s(1, cur);
				st.push(s);
			}
			else if(cur == 'N') {
				if(st.size() < 1) {
					judge = false;
					continue;
				}
				string tmp = st.top();
				st.pop();

				st.push(cur + tmp);
			}
			else if(cur == 'C' || cur == 'D' || cur == 'E' || cur == 'I') {
				if(st.size() < 2) {
					judge = false;
					continue;
				}
				string tmp1 = st.top();
				st.pop();
				string tmp2 = st.top();
				st.pop();

				st.push(cur + tmp2 + tmp1);
			}
			else judge = false;
		}
		if(st.size() != 1) judge = false;


		if(judge) cout << "YES" << endl;
		else cout << "NO" << endl;
	}


	return 0;
}