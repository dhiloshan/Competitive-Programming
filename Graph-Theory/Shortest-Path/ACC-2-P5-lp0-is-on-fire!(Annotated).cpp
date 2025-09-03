// Arcadia Computing Contest 2 P5 - lp0 is on fire! (DMOJ): https://dmoj.ca/problem/ahscc2p5
// ANNOTATED CODE
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
const int MM = 3e5;
int N, M, K; ll t; bool p[MM]; vector<pi> adj[MM]; vector<int> fire, reg;
int main(){
    cin >> N >> M >> K >> t;
    for(int i = 0, x; i < K; i++){
        cin >> x; p[x] = true; // 1-indexed
    }
    for(int i = 1; i <= N; i++){
        if(!p[i]) fire.push_back(i);
        else reg.push_back(i);
    }
    for(int i = 1, u, v, w; i <= M; i++){
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w); adj[v].emplace_back(u, w);
    }
    string ans(N, '0');
    ll dis[N+1]; priority_queue<pi, vector<pi>, greater<pi> > q;
    fill(dis, dis+N+1, 3e18);
    for(int f : fire){ // multi-source dijkstra
        dis[f] = 0; q.push({dis[f], f});
    }
    while(!q.empty()){
        auto [d, u] = q.top(); q.pop();
        if(d > dis[u]) continue;
        for(auto [v, w] : adj[u]){
            if(dis[u] + w < dis[v]){
                dis[v] = dis[u] + w; q.push({dis[v], v});
            }
        }
    }
    for(int u : reg){
        if(dis[u] != 3e18 && dis[u] <= t){ // for a source node, can it REACH (should be connected as well) another node that WON'T be extinguished BEFORE the water is turned on?
            ans[u-1] = '0';
        }
        else ans[u-1] = '1';
        // cout << u << " " << dis[u] << endl;
    }
    cout << ans << endl;
}
