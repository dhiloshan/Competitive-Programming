// CCC '09 S4 - Shop and Ship (DMOJ): https://dmoj.ca/problem/ccc09s4
// RAW CODE - https://dmoj.ca/src/6849183
#include <bits/stdc++.h>
using namespace std;
const int MM = 5002, INF = 0x3f3f3f3f;
typedef pair<int, int> pi;
int N, M, K, D, dis[MM], city[MM], cost[MM];
vector<pi> adj[MM]; bool vis[MM];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i=1, u, v, w; i<=M; i++){
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w); adj[v].emplace_back(u, w);
    }
    cin >> K;
    for(int i=1; i<=K; i++) cin >> city[i] >> cost[i];
    cin >> D;

    priority_queue<pi, vector<pi>, greater<> > q;
    memset(dis, 0x3f, sizeof(dis));
    dis[D] = 0; q.push({dis[D], D});
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
        ans = min(ans, dis[city[i]] + cost[i]);
    cout << ans << endl;
}
