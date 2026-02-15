// Sleigh Ride (DMOJ): https://dmoj.ca/problem/sleigh
// RAW
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
            dis[v] = dis[u] + w;
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
    total -= mx; 
    cout << total << endl;
}
