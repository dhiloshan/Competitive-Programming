// Mock CCC '18 Contest 5 J5/S3 - Directed Graph Connectivity (DMOJ): https://dmoj.ca/problem/nccc5j5s3
// RAW CODE
#include <bits/stdc++.h>
using namespace std;
const int MM = 55;
typedef pair<int, int> pi;
int N, M; vector<int> adj[MM]; vector<pi> edges;
int main(){
    cin >> N >> M;
    for(int i = 0, u, v; i < M; i++){
        cin >> u >> v; adj[u].push_back(v); edges.emplace_back(u, v);
    }
    for(auto& [du, dv] : edges){
        bool vis[MM]; memset(vis, false, sizeof(vis));
        queue<int> q; q.push(1);
        while(!q.empty()){
            int cur = q.front(); q.pop();
            for(int nxt: adj[cur]){
                if(!(cur == du && nxt == dv)){
                    if(!vis[nxt]){
                        vis[nxt] = true; q.push(nxt);
                    }
                }
            }
        }
        cout << (vis[N]? "YES" : "NO") << endl;
    }
}
