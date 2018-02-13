#include <iostream>
#include <stack>

using namespace std;

int main() {
	int n;
	cin >> n;
	getchar();
	while(n--) {
		string str;
		getline(cin, str);
		
		stack<char> st;
		
		bool judge = true;
		for(int i = 0; i < str.length(); i++) {	
			if(str[i] == '(') st.push('(');
			else if(str[i] == '[') st.push('[');
			else if(str[i] == ')') {
				if(st.size() == 0) judge = false;
				else if(st.top() != '(') judge = false;
				else st.pop();
			}
			else if(str[i] == ']') {
				if(st.size() == 0) judge = false;
				else if(st.top() != '[') judge = false;
				else st.pop();
			}
		}
		if(st.size() != 0) judge = false;
		
		if(judge) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	
	return 0;
}
