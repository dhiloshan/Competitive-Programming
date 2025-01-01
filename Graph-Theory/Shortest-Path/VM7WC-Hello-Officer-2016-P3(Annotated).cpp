// VM7WC '16 #3 Gold - Hello, Officer. (DMOJ): https://dmoj.ca/problem/vmss7wc16c3p3
// ANNOATED CODE - https://dmoj.ca/src/6849238
#include <bits/stdc++.h>
using namespace std;
const int MM = 2002;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pi; // Dijkstra from the dest node
int N, M, B, Q, dis[MM]; bool vis[MM]; vector<pi> adj[MM];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> B >> Q;
    for(int i = 0, x, y, z; i < M; i++){
        cin >> x >> y >> z;
        adj[x].emplace_back(y, z); adj[y].emplace_back(x, z);
    }
    priority_queue<pi, vector<pi>, greater<> > q;
    memset(dis, 0x3f, sizeof(dis)); // set all nodes to INF
    dis[B] = 0; q.push({dis[B], B}); // push the dest node as the first node to traverse
    // begin dijkstra
    while(!q.empty()){
        int u = q.top().second; q.pop();
        if(vis[u]) continue;
        vis[u] = true;
        for(auto [v, w] : adj[u]){
            if(dis[v] > dis[u] + w){
                dis[v] = dis[u] + w; q.push({dis[v], v});
            }
        }
    }
    for(int i = 0, x; i < Q; i++){
        cin >> x;
        cout << (vis[x]? dis[x] : -1) << endl; // if visited print the node's distance. otherwise, print -1 like instructed
    }
}
