// SOLUTION #1: Dijkstra implementation with priority queue O((V+E) logV)
// Single Source Shortest Path (DMOJ): https://dmoj.ca/problem/sssp
// ANNOTATED CODE - https://dmoj.ca/src/6847116
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
const int MM = 1003;
const int INF = 1e9+3; // use of priority queue to find next unvisited vertex with min distance
int N, M, dis[MM]; bool vis[MM]; vector<pi> adj[MM];
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for(int i = 1, u, v, w; i <= M; i++){
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w); adj[v].emplace_back(u, w);
    }
    priority_queue<pi, vector<pi>, greater<pi> > q; // sorts it in non-decreasing order (priority queue by default sorts by decreasing order)
    fill(dis, dis+MM, INF); // initialize all nodes with INF as their distance
    q.push({0, 1}); // 0 is the distance for node 1, priority queue sorts by the first argument by default
    dis[1] = 0;
    // dijkstra algo
    while(!q.empty()){
        int u = q.top().second; q.pop(); // note we don't care about the distance to node u from the queue, we just want it in this case to create the ordering
        if(vis[u]) continue; // if we performed dijkstra for node u once before, don't do it again and move on to the next node by skipping this iteration
        vis[u] = true;
        for(auto& [v, w] : adj[u]){ // for each neighbour
            if(dis[v] > dis[u] + w){ // if the path from node u to node v through its edge costing w is CHEAPER than the path going to node v currently (some path that we don't know but frankly we don't care about)
                dis[v] = dis[u] + w; // update that minimum distance
                q.push({dis[v], v}); // push into the queue the new distance for node v
            }
        }
    }
    for(int i = 1; i <= N; i++){
        cout << (vis[i]? dis[i] : -1) << endl; 
    }
}
