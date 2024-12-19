// VMSS '15 #4 - Frank and Roads (DMOJ): https://dmoj.ca/problem/vmss15c1p4
// RAW CODE - https://dmoj.ca/src/6819953
#include <bits/stdc++.h>
using namespace std;
const int MM = 2003;
const int INF = 1e9+3;
typedef pair<int, int> pi;
int N, M, G, T, dis[MM]; bool vis[MM]; vector<pi> adj[MM]; vector<int> dest;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> T >> N >> M >> G;
    for(int i = 0, x; i < G; i++){
        cin >> x;
        dest.push_back(x);
    }
    for(int i = 0, u, v, w; i < M; i++){
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    priority_queue<pi, vector<pi>, greater<pi> > q;
    fill(dis, dis+MM, INF);
    q.push({0, 0}); dis[0] = 0;
    while(!q.empty()){
        int u = q.top().second; q.pop();
        if(vis[u]) continue;
        vis[u] = true;
        for(auto& [v, w] : adj[u]){
            if(dis[v] > dis[u] + w){
                dis[v] = dis[u] + w; q.push({dis[v], v});
            }
        }
    }
    int cnt = 0;
    for(int cur : dest){
        if(dis[cur] <= T) cnt++;
    }
    cout << cnt << endl;
}
