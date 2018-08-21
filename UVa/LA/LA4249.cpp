#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int kase;
	cin >> kase;

	while(kase--) {
		int score = 0;

		long double a, b, c, d, e, f, g;
		cin >> a >> b >> c >> d >> e >> f >> g;

		score += (9.23076 * pow(26.7 - a, 1.835));
		score += (1.84523 * pow(b - 75.0, 1.348));
		score += (56.0211 * pow(c - 1.5, 1.05));
		score += (4.99087 * pow(42.5 - d, 1.81));
		score += (0.188807 * pow(e - 210, 1.41));
		score += (15.9803 * pow(f - 3.8, 1.04));
		score += (0.11193 * pow(254 - g, 1.88));

		cout << score << endl;
	}

	return 0;
}