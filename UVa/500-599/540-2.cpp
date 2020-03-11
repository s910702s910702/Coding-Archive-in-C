#include <iostream>
#include <queue>

using namespace std;


int main() {
    int cnt = 1;

    int n;
    while(cin >> n && n) {
        cout << "Scenario #" << cnt++ << endl;

        queue<int> q[n + 1];
        int ppl[1000005];

        for(int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            for(int j = 0; j < x; j++) {
                int v;
                cin >> v;
                ppl[v] = i;
            }
        }

        string cmd;
        while(cin >> cmd) {
            if(cmd == "STOP") break;

            
            if(cmd == "ENQUEUE") {
                int who;
                cin >> who;
                int team = ppl[who];
                if(!q[team].empty()) q[team].push(who);
                else {
                    q[0].push(team);
                    q[team].push(who);
                }
            }
            else if(cmd == "DEQUEUE") {
                int team = q[0].front();
                int who = q[team].front();
                cout << who << endl;
                q[team].pop();
                if(q[team].empty()) q[0].pop();
            }
        }
        cout << endl;
    }
    return 0;
}