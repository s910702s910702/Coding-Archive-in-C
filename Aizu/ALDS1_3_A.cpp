#include <iostream>
#include <stack>

using namespace std;

int main() {
	string str;

	stack<double> st;

	while(cin >> str) {
		if(isdigit(str[0])) st.push((double)stoi(str));
		else {
			double a, b;
			b = st.top();
			st.pop();
			a = st.top();
			st.pop();

			if(str == "+") st.push(a + b);
			else if(str == "-") st.push(a - b);
			else if(str == "*") st.push(a * b);
			else st.push(a / b);
		}
	}

	cout << st.top() << endl; 

	return 0;
}