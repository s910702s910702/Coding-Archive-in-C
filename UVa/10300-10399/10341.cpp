#include <iostream>
#include <cstdio>
#include <iomanip>
#include <cmath>

using namespace std;

int p, q, r, s, t, u;
double f(double x) {
	return p * exp(-x) +  q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;
}

int main() {
	while(cin >> p >> q >> r >> s >> t >> u) {
		double left = 0, right = 1, x;
		if(f(left) * f(right) > 0.0) cout << "No solution" << endl;
		else {
			while(left + 0.0000001 < right) {
				x = (left + right) / 2;			
				if(f(x) * f(left) <= 0) right = x;
				else left = x;
			}
			
			cout << fixed << setprecision(4) << (left + right) / 2 << endl;
		}
	}
	return 0;
} 
