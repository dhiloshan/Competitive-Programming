// RTE '16 S3 - School Traversal (DMOJ): https://dmoj.ca/problem/rte16s3
// RAW CODE (solution 2: lca)
#include <bits/stdc++.h>
using namespace std;
const int MM = 6000;
const int mod = (int)1e9+7;
typedef long long ll;
typedef pair<int, int> pi;
int N, Q, dep[MM], in[MM]; vector<pi> adj[MM]; vector<int> euler; ll dis[MM];
pi st[2*MM][15];
void dfs(int cur, int par) {
    in[cur] = euler.size(); euler.push_back(cur);
    for (auto [v, w] : adj[cur]) {
        if (v != par) {
            dep[v] = dep[cur] + 1; dis[v] = dis[cur] + w;
            dfs(v, cur);
            euler.push_back(cur);
        }
    }
}
int lca(int u, int v) {
    int lft = min(in[u], in[v]), rit = max(in[u], in[v]);
    int k = log2(rit - lft+1);
    return min(st[lft][k], st[rit - (1<<k) + 1][k]).second;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for (int i = 1, u, v, w; i < N; i++) {
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w); adj[v].emplace_back(u, w);
    }
    dfs(0, -1); int M = euler.size(), LOG = log2(M);
    for (int i = 0; i < M; i++) st[i][0] = {dep[euler[i]], euler[i]};
    for (int k = 1; k <= LOG; k++) {
        for (int i = 0; i + (1<<k) - 1 < M; i++) {
            st[i][k] = min(st[i][k-1],  st[i + (1<<k-1) ][k-1]);
        }
    }
    cin >> Q;
    for (int i = 1, u, v; i <= Q; i++) {
        cin >> u >> v;
        cout << dis[u] + dis[v] - 2 * dis[lca(u, v)] << endl;
    }
}
