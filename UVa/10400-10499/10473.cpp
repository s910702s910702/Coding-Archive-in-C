#include <iostream>
#include <sstream>
#include <cstdio>

using namespace std;

int main() {
	string str;
	
	while(cin >> str) {
		if(str[0] == '-') break;
		
		stringstream ss;
		
//		ss.str(str);
		ss << str;
		
		
		if(str[1] == 'x') {
			int num;
			ss >> hex >> num;
			printf("%d\n", num);
		}
		else  {
			int num;
			ss >> dec >> num;
			printf("0x%X\n", num);
		}
	}
	
	return 0;
} 
