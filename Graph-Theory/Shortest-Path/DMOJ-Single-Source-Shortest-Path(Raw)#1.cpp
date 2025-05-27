// SOLUTION #1: Dijkstra implementation with priority queue O(ElogV)
// Single Source Shortest Path (DMOJ): https://dmoj.ca/problem/sssp
// RAW CODE - https://dmoj.ca/src/6804649
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
const int MM = 1003;
const int INF = 1e9+3;
int N, M, dis[MM]; bool vis[MM]; vector<pi> adj[MM];
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for(int i = 1, u, v, w; i <= M; i++){
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w); adj[v].emplace_back(u, w);
    }
    priority_queue<pi, vector<pi>, greater<pi> > q;
    fill(dis, dis+MM, INF);
    q.push({0, 1}); dis[1] = 0;
    while(!q.empty()){
        int u = q.top().second; q.pop();
        if(vis[u]) continue;
        vis[u] = true;
        for(auto& [v, w] : adj[u]){
            if(dis[v] > dis[u] + w){
                dis[v] = dis[u] + w; q.push({dis[v], v});
            }
        }
    }
    for(int i = 1; i <= N; i++){
        cout << (vis[i]? dis[i] : -1) << endl;
    }
}
