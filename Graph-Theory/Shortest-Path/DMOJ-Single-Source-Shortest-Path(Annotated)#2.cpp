// SOLUTION #2: Dijkstra implementation without priority queue O(V^2), optimal for complete graphs
// Single Source Shortest Path (DMOJ): https://dmoj.ca/problem/sssp
// ANNOTATED CODE
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
const int MM = 1003;
const int INF = 1e9+3; // we manually go through all N nodes for each round, guaranteeing we visit all REACHABLE nodes from the source node (disconnected components will continue to have nodes with distance INF)
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
    for(int i = 1; i <= N; i++){ // N rounds
        int mi = INF, u = 0; // manually loops O(V) to find the current cheapest vertex that is unvisited
        for(int j = 1; j <= N; j++){
            if(mi > dis[j] && !vis[j]){ // if the node is NOT visited and is cheaper than mi (the current cheapest option)
                mi = dis[j]; u = j; 
            }
        }
        vis[u] = true; // we only perform dijkstra on a node ONCE
        for(auto& [v, w] : adj[u]){ // for each of its neighbours
            if(dis[v] > dis[u] + w){ // simply check if node u to node v is the cheaper option, if so, update
                dis[v] = dis[u] + w;
            }
        }
    }
    for(int i = 1; i <= N; i++){
        cout << (vis[i]? dis[i] : -1) << endl;
    }
}
