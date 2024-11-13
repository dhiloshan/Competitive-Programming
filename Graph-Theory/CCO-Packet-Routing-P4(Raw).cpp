// CCO '00 P4 - Packet Routing (DMOJ): https://dmoj.ca/problem/cco00p4
// RAW CODE - https://dmoj.ca/src/6737364
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e3+2;
int N, M, Q, vis[MM]; vector<pair<int, int> > adj[MM];
int dfs(int src, int dst){
    if(src == dst) return 0;
    for(auto &[v, w] : adj[src]) {
        if (!vis[v]) {
            vis[v] = true;
            int cost = dfs(v, dst);
            if(cost != -1){
                return w + cost;
            }
        }
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M >> Q;
    for(int i = 1, u, v, w; i <= M; i++){
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w); adj[v].emplace_back(u, w);
    }
    for(int i = 0, u, v; i < Q; i++){
        cin >> u >> v;
        for(int i = 0; i < MM; i++) vis[i] = 0;
        vis[u] = true;
        cout << dfs(u, v) << endl;
    }
}
