// CSES Tree Diameter (CSES): https://cses.fi/problemset/task/1131/
// RAW CODE
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
const int MM = 2e5+3;
int N; vector<int> adj[MM];
void dfs(int u, int dis[], bool vis[]) {
    vis[u] = true;
    for (int nxt : adj[u]) {
        if (!vis[nxt]) {
            dis[nxt] = dis[u] + 1;
            dfs(nxt, dis, vis);
        }
    }
}
int main() {
    cin >> N;
    for (int i = 0, u, v; i < N-1; i++) {
        cin >> u >> v; adj[u].push_back(v); adj[v].push_back(u);
    }
    int dis1[MM]; memset(dis1, 0, sizeof(dis1));
    bool vis1[MM]; memset(vis1, 0, sizeof(vis1));
    dfs(1, dis1, vis1);
    int mx = 0, node = 0;
    for (int i = 1; i <= N; i++) {
        if (mx < dis1[i]) {
            mx = dis1[i];
            node = i;
        }
    }
    int disFinal[MM]; memset(disFinal, 0, sizeof(disFinal));
    bool visFinal[MM]; memset(disFinal, 0, sizeof(visFinal));
    dfs(node, disFinal, visFinal);
    int diameter = 0;
    for (int i = 1; i <= N; i++) {
        diameter = max(diameter, disFinal[i]);
    }
    cout << diameter << endl;
}
