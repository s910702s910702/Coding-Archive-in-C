#include <iostream>

using namespace std;

bool isAlphabet(char x) {
	return (x >= 'A' && x <= 'Z') || (x >= 'a' && x <= 'z');
}

int main() {
	
	string str;
	
	while(getline(cin, str)) {
		int cnt = 0;
		bool connect = false;
		for(auto i : str) {
			if(isAlphabet(i)) {
				if(!connect) {
					cnt++;
					connect = true;
				}
			}
			else {
				connect = false;
			}
		}
		cout << cnt << endl;
	}
	return 0;
} 
