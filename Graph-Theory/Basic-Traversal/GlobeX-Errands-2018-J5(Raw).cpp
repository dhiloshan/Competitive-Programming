// GlobeX Cup '18 J5 Errands (DMOJ): https://dmoj.ca/problem/globexcup18j5
// RAW CODE - https://dmoj.ca/src/6779080
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+3;
int N, M, Q, C, dis[MM]; bool vis[MM]; vector<int> adj[MM]; queue<int> q;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M >> Q >> C;
    for(int i = 1, u, v; i <= M; i++){
        cin >> u >> v; 
        adj[u].push_back(v); adj[v].push_back(u); 
    }
    q.push(C); vis[C] = true; dis[C] = 0;
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(int nxt : adj[cur]){
            if(!vis[nxt]){
                q.push(nxt);
                vis[nxt] = true; dis[nxt] = dis[cur] + 1;
            }
        }
    }
    for(int i = 1, a, b; i <= Q; i++){
        cin >> a >> b;
        cout << ((vis[a] && vis[b])? to_string(dis[a]+dis[b]) : "This is a scam!") << endl;
    }
}
