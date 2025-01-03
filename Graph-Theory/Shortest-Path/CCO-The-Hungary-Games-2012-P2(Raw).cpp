// CCO '12 P2 - The Hungary Games (DMOJ): https://dmoj.ca/problem/cco12p2
// RAW CODE
#include <bits/stdc++.h>
using namespace std;
const int MM = 2e4+3;
typedef pair<int, int> pi;
int N, M; long long ds[MM], de[MM]; vector<pi> adj[MM], rev[MM];
void dijk(int s, long long dis[], vector<pi> adj[]){
    priority_queue<pi, vector<pi>, greater<> > q;
    fill(dis, dis+MM, 1e9);
    dis[s] = 0; q.push({dis[s], s});
    while(!q.empty()){
        auto [d, u] = q.top(); q.pop();
        if(d > dis[u]) continue;
        for(auto [v, w] : adj[u]){
            if(dis[v] > dis[u] + w){
                dis[v] = dis[u] + w; q.push({dis[v], v});
            }
        }
    }
}
int main(){
    cin >> N >> M;
    for(int i = 0, a, b, l; i < M; i++){
        cin >> a >> b >> l;
        adj[a].emplace_back(b, l); rev[b].emplace_back(a, l);
    }
    dijk(1, ds, adj); dijk(N, de, rev);
    long long ans = 1e9;
    for(int u = 1; u <= N; u++){
        for(auto [v, w] : adj[u]){
            if(ds[u] + w + de[v] > ds[N] && ans > ds[u] + w + de[v]) ans = ds[u] + w + de[v];
        }
    }
    cout << (ans == 1e9 ? -1 : ans) << endl;
}
