// CCO '12 P2 - The Hungary Games (DMOJ): https://dmoj.ca/problem/cco12p2
// ANNOTATED CODE - https://dmoj.ca/src/6853873
#include <bits/stdc++.h>
using namespace std;
const int MM = 2e4+3;
typedef pair<int, int> pi; // Dijkstra trick - second shortest path
// if you think about it, there has to be at least one different edge compared to the shortest path
// just loop through all edges, and check the distance from 1 to u, u to v, and v to N, and see if that is the second longest
int N, M; long long ds[MM], de[MM]; vector<pi> adj[MM], rev[MM]; // perform dijkstra forwards, and then backwards from N by reversing the edges since they are unidrectional
void dijk(int s, long long dis[], vector<pi> adj[]){ // dijkstra function to avoid duplicating code
    priority_queue<pi, vector<pi>, greater<> > q;
    fill(dis, dis+MM, 1e9); // node s is the start node
    dis[s] = 0; q.push({dis[s], s});
    while(!q.empty()){
        auto [d, u] = q.top(); q.pop();
        if(d > dis[u]) continue; // use of dis array to check if we need to perform dijkstra on node u instead of using the vis array
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
        adj[a].emplace_back(b, l); rev[b].emplace_back(a, l); // reverse the edge
    }
    dijk(1, ds, adj); dijk(N, de, rev); // perform dijkstra twice, once from node one forwards using the dis_start array (ds) 
                                        // and then once backwards from N using the rev graph on the dis_end array (de)
    long long ans = 1e9; // max
    for(int u = 1; u <= N; u++){ // go through edge node to find the edges (could also store all the edges in a data structure but im too lazy)
        for(auto [v, w] : adj[u]){ // for each neighbouring edge
            if(ds[u] + w + de[v] > ds[N] && ans > ds[u] + w + de[v]) ans = ds[u] + w + de[v];
            // if the distance is longer than the fastest path and is shorter than ans, update ans
        }
    }
    cout << (ans == 1e9 ? -1 : ans) << endl; // if ans is reachable print it out otherwise print -1
}
