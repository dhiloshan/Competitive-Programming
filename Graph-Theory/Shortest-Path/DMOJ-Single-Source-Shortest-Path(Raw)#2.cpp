// SOLUTION #2: Dijkstra implementation without priority queue O(V^2), optimal for complete graphs
// Single Source Shortest Path (DMOJ): https://dmoj.ca/problem/sssp
// RAW CODE - https://dmoj.ca/src/6847148
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
    fill(dis, dis+MM, INF);
    dis[1] = 0;
    for(int i = 1; i <= N; i++){
        int mi = INF, u = 0;
        for(int j = 1; j <= N; j++){
            if(mi > dis[j] && !vis[j]){
                mi = dis[j]; u = j;
            }
        }
        vis[u] = true;
        for(auto& [v, w] : adj[u]){
            if(dis[v] > dis[u] + w){
                dis[v] = dis[u] + w;
            }
        }
    }
    for(int i = 1; i <= N; i++){
        cout << (vis[i]? dis[i] : -1) << endl;
    }
}
