// GFSSOC '15 Fall S4 - Mostly Talking (DMOJ): https://dmoj.ca/problem/gfssoc2s4
// RAW CODE - https://dmoj.ca/src/6850517
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pl;
const int MM = 5e5+3;
const ll INF = 1e18;
int N, M, D; long long ds[MM], de[MM]; vector<pl> adj[MM], rev[MM];
void dijkstra(int s, vector<pl> adj[], ll dis[]){
    priority_queue<pl, vector<pl>, greater<> > q;
    fill(dis, dis+MM, INF);
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
    for(int i = 0, u, v, w; i < M; i++){
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w); rev[v].emplace_back(u, w);
    }
    dijkstra(1, adj, ds); dijkstra(N, rev, de);
    cin >> D;
    ll mi = ds[N];
    for(int i = 0, u, v, w; i < D; i++){
        cin >> u >> v >> w;
        mi = min(mi, ds[u] + w + de[v]);
    }
    cout << (mi == INF ? -1 : mi) << endl;
}
