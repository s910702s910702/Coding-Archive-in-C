#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <cstring>
#include <cstdio>

#define SIZE 101
#define INF 1e9

using namespace std;

typedef struct {
  int s, t;
  int loud;
} route;

int map[SIZE][SIZE];
int disjoint[SIZE];
int c, s, q;

bool cmp(route l, route r) { return l.loud < r.loud; }

int root(int x) {
  while(disjoint[x] > 0) x = disjoint[x];
  return x;
}

bool isConnected(int a, int b) {
  if(root(a) == root(b)) return true;
  else return false;
}

void connect(int a, int b) {
  int aroot = root(a);
  int broot = root(b);
  
  disjoint[aroot] += disjoint[broot];
  disjoint[broot] = aroot;
}

bool visit[SIZE];
void dfs(int start, int end) {
  stack<int> st;
  bool found = false;
  int record[c + 1];
  
  memset(visit, false, sizeof(visit));
  memset(record, 0, sizeof(record));
  
  st.push(start);
  
  while(!st.empty() && !found) {
    int cur = st.top();
    st.pop();
    
    if(cur == end) {
      found = true;
      break;
    }
    
    visit[cur] = true;
    for(int i = 0; i < SIZE; i++) {
      if(!visit[i] && map[cur][i] != INF) {
        record[i] = max(record[cur], map[cur][i]);
        st.push(i);
      }
    }
  }
  if(!found) cout << "no path" << endl;
  else cout << record[end] << endl;
}


void reset() {
  for(int i = 0; i < SIZE; i++) {
  	disjoint[i] = -1;
  	for(int j = 0; j < SIZE; j++)
      map[i][j] = INF;
  }
}

int main() {
  int count = 0;
  while(cin >> c >> s >> q && c && s && q) {
    if(count > 0) cout << endl;
    cout << "Case #" << ++count << endl;
    reset();
    route r[s];
    for(int i = 0; i < s; i++) cin >> r[i].s >> r[i].t >> r[i].loud;
  
    sort(r, r + s, cmp);
    
    for(int i = 0; i < s; i++) {
      if(!isConnected(r[i].s, r[i].t)) {
        connect(r[i].s, r[i].t);
        map[r[i].s][r[i].t] = map[r[i].t][r[i].s] = r[i].loud;
      }
    }
    
    for(int i = 0; i < q; i++) {
      int start, end;
      cin >> start >> end;
      dfs(start, end);
    }
  }
  
  return 0;
}
