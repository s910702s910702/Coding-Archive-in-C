//correct
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

typedef struct {
	int x, y;
} point;

vector<point> allp;
deque<point> convex;

void generate(point a, int w) {
	allp.push_back(a);
	a.x += w;
	allp.push_back(a);
	a.y += w;
	allp.push_back(a);
	a.x -= w;
	allp.push_back(a);
}

bool cmp(point l, point r) {
	if(l.x == r.x) return l.y < r.y;
	return l.x < r.x;
}

bool j_cross(point a, point b, point c) {
	return ((b.x - a.x) * (c.y - b.y) - (b.y - a.y) * (c.x - b.x)) <= 0;
}

int dis(point a, point b) {
	return (b.y - a.y) * (b.y - a.y) + (b.x - a.x) * (b.x - a.x);
}

int main() {
	ios_base::sync_with_stdio(false);
	int kase;
	cin >> kase;
	
	while(kase--) {
		allp.clear();
		convex.clear();
		int n;
		cin >> n;
		
		for(int i = 0; i < n; i++) {
			point tmp;
			int w;
			cin >> tmp.x >> tmp.y >> w;
			generate(tmp, w);
		}
		
		sort(allp.begin(), allp.end(), cmp);
		
		for(int i = 0; i < allp.size(); i++) {
			while(convex.size() >= 2 && j_cross(convex[convex.size() - 2], convex[convex.size() - 1], allp[i])) convex.pop_back();
			
			convex.push_back(allp[i]);
		}
		convex.pop_back();
		
		int downamount = convex.size(); 
		for(int i = allp.size() - 1; i >= 0; i--) {
			while(convex.size() >= downamount + 2 && j_cross(convex[convex.size() - 2], convex[convex.size() - 1], allp[i])) convex.pop_back();
			
			convex.push_back(allp[i]);
		}
		convex.pop_back();
		
		int d2 = 0;
		for(int i = 0; i < convex.size(); i++) {
			for(int j = i + 1; j < convex.size(); j++) {
				int l = dis(convex[i], convex[j]);
				if(l > d2) d2 = l;
			}
		}
		cout << d2 << '\n';
	}
	return 0;
}