// Sleigh Ride (DMOJ): https://dmoj.ca/problem/sleigh
// ANNOTATED CODE
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
const int MM = 1e5+8;
int N; vector<pi> adj[MM]; ll total = 0, dis[MM]; bool vis[MM];
void dfs(int u) {
    vis[u] = true;
    for (auto [v, w] : adj[u]) {
        if (!vis[v]) {
            dis[v] = dis[u] + w; // only one possible path from any two nodes so this is fine
            dfs(v);
        }
    }
}
int main() {
    cin >> N;
    for (int i = 0, u, v, w; i < N; i++) {
        cin >> u >> v >> w;
        adj[u].push_back({v, w}); adj[v].push_back({u, w});
        total += w;
    }
    total *= 2;
    dfs(0);
    ll mx = 0;
    for (int i = 1; i <= N; i++) {
        if (mx < dis[i]) mx = dis[i];
    }
    total -= mx; // formula to visit all nodes in a weighted tree but not need to return back to root: 2 * summation of weights - longest path
    // (consider that there is one path that we do not have to go back up, best to not go up on the longest path to minimize cost)
    cout << total << endl;
}
