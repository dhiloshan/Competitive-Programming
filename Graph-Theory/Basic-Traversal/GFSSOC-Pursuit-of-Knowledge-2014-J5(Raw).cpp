// GFSSOC '14 Winter J5 - Pursuit of Knowledge (DMOJ): https://dmoj.ca/problem/gfssoc1j5
// RAW CODE - https://dmoj.ca/src/6946299
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e4+3;
typedef long long ll;
int N, M, T, Q; vector<int> adj[MM];
int main(){
    cin >> N >> M >> T;
    for(int i = 0, u, v; i < M; i++){
        cin >> u >> v;
        adj[u].emplace_back(v);
    }
    cin >> Q;
    for(int i = 0, a, b; i < Q; i++){
        cin >> a >> b;
        int dis[N+1]; bool vis[N+1];
        fill(dis, dis+N+1, 0); fill(vis, vis+N+1, false);
        queue<int> q; q.push(a); vis[a] = true;
        while(!q.empty()){
            int cur = q.front(); q.pop();
            for(int nxt : adj[cur]){
                if(!vis[nxt]){
                    vis[nxt] = true; dis[nxt] = dis[cur] + 1;
                    q.push(nxt);
                }
            }
        }
        if(!vis[b]) cout << "Not enough hallways!\n";
        else cout << dis[b] * T << endl;
    }
}
