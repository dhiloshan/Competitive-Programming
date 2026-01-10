// Graph Contest 2 P1 - Connected Components (DMOJ): https://dmoj.ca/problem/graph2p1
// RAW CODE
#include <bits/stdc++.h>
using namespace std;
const int MM = 2003;
int N; bool vis[MM];
vector<int> adj[MM]; int a[MM][MM];
vector<int> cur;
void dfs(int u) {
    if (vis[u]) return;
    vis[u] = true;
   cur.push_back(u);
    for (int nxt : adj[u]) {
        dfs(nxt);
    }
}
int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> a[i][j];
            if (a[i][j] == 1) {
                adj[i].push_back(j);
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        if (!vis[i]) {
            dfs(i);
        }
        sort(cur.begin(), cur.end());
        for (int x : cur) {
            cout << x << " ";
        } cout << endl;
        cur = {};
    }


}
