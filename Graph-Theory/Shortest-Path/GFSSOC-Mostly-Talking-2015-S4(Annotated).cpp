// GFSSOC '15 Fall S4 - Mostly Talking (DMOJ): https://dmoj.ca/problem/gfssoc2s4
// ANNOTATED CODE - https://dmoj.ca/src/6850545
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pl;
const int MM = 5e5+3;
const ll INF = 1e18; // Dijkstra Trick: shortest path via a specific edge <u, v>
// idea is the perform dijkstra once from source node, and then AGAIN from the dest node (but to make it the same you have to reverse the edges)
// to travel from node ONE to node N via edge <u, v>, it costs: 1 to u + <u, v>'s weight + v to N => ds[u] + w + de[v]
int N, M, D; long long ds[MM], de[MM]; vector<pl> adj[MM], rev[MM]; // ds is dis array for source, de is dis array for end, adj is original, rev is graph but reversed edges
void dijkstra(int s, vector<pl> adj[], ll dis[]){ // dijkstra in a function because we repeat it TWICE; note that the arrays are passed by REFERENCE (which we need for dis) by default
    priority_queue<pl, vector<pl>, greater<> > q; // use of long long since edge weights get large
    fill(dis, dis+MM, INF); // because we are using long long, only fill will work (not memset) for getting a large enough value
    dis[s] = 0; q.push({dis[s], s}); // s represents the start node
    // begin dijkstra
    while(!q.empty()){
        auto [d, u] = q.top(); q.pop();
        if(d > dis[u]) continue; // if this is true, that means we performed dijkstra on node u before, so just skip this iteration
        // notice how we didn't use vis and this is just a different way to check if we visited the node before
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
        adj[u].emplace_back(v, w); rev[v].emplace_back(u, w); // rev REVERSES the edge, if it was bi-directional it wouldn't matter
    }
    dijkstra(1, adj, ds); dijkstra(N, rev, de); // perform dijkstra twice
    cin >> D;
    ll mi = ds[N]; // consider the case where the extra edges are useless and there is a path without these special edges from 1 to N that is faster compared to a path with one of the special edges
    for(int i = 0, u, v, w; i < D; i++){
        cin >> u >> v >> w;
        mi = min(mi, ds[u] + w + de[v]); // formula for cost via an edge <u, v>, except we check it for all D edges
    }
    cout << (mi == INF ? -1 : mi) << endl; // print -1 if it is impossible to reach node N from node 1
}
