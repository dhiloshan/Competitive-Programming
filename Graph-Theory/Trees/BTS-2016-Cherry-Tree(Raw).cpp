// Back To School '16: Cherry Tree (DMOJ): https://dmoj.ca/problem/bts16p5
// RAW CODE
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MM = 10008;
int N; ll C, K;
ll val[MM], dep[MM], subC[MM], subW[MM];
vector<pair<int,int>> adj[MM];
vector<tuple<int,int,int>> edges;
void dfs(int u, int p, int d){
    dep[u] = d;
    subC[u] = val[u];
    subW[u] = 0;
    for (auto [v,w] : adj[u]){
        if (v == p) continue;
        dfs(v, u, d+1);
        subC[u] += subC[v];
        subW[u] += (ll)w + subW[v];
    }
}
int main(){
    cin >> N >> C >> K;
    for (int i=1;i<=N;i++) cin >> val[i];
    for (int i=1;i<N;i++){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
        edges.push_back({u,v,w});
    }
    dfs(1, 0, 0);
    int ans = 0;
    for (auto [u,v,w] : edges){
        int child = (dep[u] > dep[v]) ? u : v;
        if (subC[child] >= C && (ll)w + subW[child] <= K) 
            ans++;
    }
    cout << ans << endl;
}
