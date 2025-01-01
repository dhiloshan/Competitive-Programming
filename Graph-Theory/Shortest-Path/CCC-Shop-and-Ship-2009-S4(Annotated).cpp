// CCC '09 S4 - Shop and Ship (DMOJ): https://dmoj.ca/problem/ccc09s4
// ANNOTATED CODE - https://dmoj.ca/src/6849187
#include <bits/stdc++.h>
using namespace std;
const int MM = 5002, INF = 0x3f3f3f3f;
typedef pair<int, int> pi; // Dijkstra algorithm runs from the destination node
int N, M, K, D, dis[MM], city[MM], cost[MM]; // dis[i] is the min dist from dest (or "source") node to node i
// city[i] denotes that city[i] has a pencil; cost[i] denotes that the ith city charges a pencil for x dollars
vector<pi> adj[MM]; bool vis[MM];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i=1, u, v, w; i<=M; i++){
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w); adj[v].emplace_back(u, w);
    }
    cin >> K; // K cities offer pencils
    for(int i=1; i<=K; i++) cin >> city[i] >> cost[i];
    cin >> D; // dest city (run dijkstra from here; too inefficient to run dijkstra from all possible source nodes)

    priority_queue<pi, vector<pi>, greater<> > q;
    memset(dis, 0x3f, sizeof(dis)); // initialize dis array to INF (max)
    dis[D] = 0; q.push({dis[D], D});
    // perform dijkstra
    while(!q.empty()){
        int u = q.top().second; q.pop();
        if(vis[u]) continue;
        vis[u] = true;
        for(auto& [v, w] : adj[u]){
            if(dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w ; q.push({dis[v], v});
            }
        }
    }
    int ans = INF;
    for(int i=1; i<=K; i++)
        ans = min(ans, dis[city[i]] + cost[i]); // uses the min distance by edges and also the cost of pencils to find the optimal cost
    cout << ans << endl;
}
