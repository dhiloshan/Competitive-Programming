// GFSSOC '14 Winter J5 - Pursuit of Knowledge (DMOJ): https://dmoj.ca/problem/gfssoc1j5
// ANNOTATED CODE - https://dmoj.ca/src/6946318
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e4+3;
typedef long long ll;
int N, M, T, Q; vector<int> adj[MM]; // run bfs for each query, see if you can visit the node, if you can, do the dist times T since ALL edges are weight T
int main(){
    ios::sync_with_stdio(0); cin.tie(0), cout.tie(0);
    cin >> N >> M >> T;
    for(int i = 0, u, v; i < M; i++){
        cin >> u >> v;
        adj[u].emplace_back(v); // one way edges
    }
    cin >> Q;
    for(int i = 0, a, b; i < Q; i++){ // for each query do bfs
        cin >> a >> b;
        int dis[N+1]; bool vis[N+1];
        fill(dis, dis+N+1, 0); fill(vis, vis+N+1, false); // fill it up because it has garbage values if assigned in main function and not globally
        queue<int> q; q.push(a); vis[a] = true;
        while(!q.empty()){ // bfs classical algo
            int cur = q.front(); q.pop();
            for(int nxt : adj[cur]){
                if(!vis[nxt]){
                    vis[nxt] = true; dis[nxt] = dis[cur] + 1;
                    q.push(nxt);
                }
            }
        }
        if(!vis[b]) cout << "Not enough hallways!\n";
        else cout << dis[b] * T << endl; // make sure to times by T, ALL EDGES are weight T
    }
    // NOTE: it is much faster to run 2d bfs, and then access index for each query as Q goes up to 2e5, but this is a very easy problem and i want to spend more time on challenging problems
}
